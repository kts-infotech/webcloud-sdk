using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using NAudio.Wave;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;
using WebCloudAPITest.CommMenu;

namespace WebCloudAPITest
{
    public partial class VoiceChatForm : Form
    {
        private int m_JitterBufferSize = 100;
        static int i = 0;
        private List<byte> m_BufferArray = new List<byte>();
        DirectSoundOut waveout = new DirectSoundOut();
        private IWaveProvider provider;
        System.Media.SoundPlayer m_player;
        private bool m_inComingCall;
        private SignalRChatManager m_chatManager;
        public delegate void OnAuthenticateUser(object sender, AuthenticateUserEventArgs e);
        private WebCloudAPIForm m_ObjMainForm;
        string m_strCommunicationID;
        string m_strWebcloudId;
        AudioRecorder rec;
        public string WebcloudId
        {
            get
            {
                return m_strWebcloudId;
            }

            set
            {
                m_strWebcloudId = value;
            }
        }
        public string CommunicationID
        {
            get
            {
                return m_strCommunicationID;
            }

            set
            {
                m_strCommunicationID = value;
            }
        }
        public SignalRChatManager ChatManager
        {
            get
            {
                return m_chatManager;
            }

            set
            {
                m_chatManager = value;
            }
        }
        public VoiceChatForm(WebCloudAPIForm obj)
        {
            m_JitterBufferSize = (AudioRecorder.m_BufferPer10Ms * AudioRecorder.m_SleepIntervalPer10Ms * 10) / 2;
            InitializeComponent();
            
            m_ObjMainForm = obj;
            m_strCommunicationID = string.Empty;
            m_strWebcloudId = string.Empty;
            textEmail.Text = obj.GetUserID();
            WriteAudioFile("sample.wav");
            m_player = new System.Media.SoundPlayer(Properties.Resources.ringing_snd);


        }
        private void WriteAudioFile(string strFilename)
        {
            string strExePath = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            strExePath = Path.Combine(strExePath, textEmail.Text);
            rec = new AudioRecorder(0, strExePath, strFilename);
        }
        public void StartCall()
        {
            rec.Manager = ChatManager;
            rec.StrCommunicationID = m_strCommunicationID;
            rec.StrWebcloudId = m_strWebcloudId;
            rec.StartRecording();
        }
        private AppSettings Settings()
        {
            AppSettings settings = new AppSettings();
            settings.EmailID = textEmail.Text;
            settings.NickName = textNickName.Text;
            settings.PhoneNo = textPhone.Text;
            settings.SupportServerName = "GodadyServer";
            settings.SupportServerUrl = m_ObjMainForm.GetMainURL();
            settings.UserName = m_ObjMainForm.GetUserID();
            settings.Password = m_ObjMainForm.GetPassword();
            return settings;
        }
        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (btnConnect.Text == "Connect")
            {
                m_chatManager = new SignalRChatManager(Settings(), ChatManagerMode.ClientMode);
                m_chatManager.SenderEmail = textEmail.Text;

                m_chatManager.On_NewChatContact += m_chatManager_On_NewChatContact;
                m_chatManager.On_ChatRecieved += m_chatManager_On_ChatRecieved;
                m_chatManager.On_ChatSent += M_chatManager_On_ChatSent;
                m_chatManager.On_SupportUserUniqueIDReceived += m_chatManager_On_SupportUserUniqueIDReceived;
                m_chatManager.On_CurrentUserUniqueIdReceived += m_chatManager_On_CommunicationUniqueIdReceived;
                m_chatManager.On_MultimediaChatSent += m_chatManager_On_MultimediaChatSent;
                m_chatManager.On_MultimediaChatRecieved += m_chatManager_On_MultimediaChatRecieved;
                m_chatManager.Start();
            }
            ConnectingToUser();
        }
        private void m_chatManager_On_NewChatContact(object sender, ChatNewContactEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnNewChatContact(m_chatManager_On_NewChatContact), sender, e);
                return;
            }

            ContactInfo info = new ContactInfo();
            info.chatmanager = (SignalRChatManager)sender;
            info.ContactDetails = e;
            m_strCommunicationID = info.ContactDetails.ContactUniqueID;
            m_strWebcloudId = info.ContactDetails.WebcloudUniqueID;
            combOnlineMemb.Items.Add(e.EmailID);

        }
        private void m_chatManager_On_ChatRecieved(object sender, ChatReceivedEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnChatReceived(m_chatManager_On_ChatRecieved)
                    , sender
                    , e);
                return;
            }
            
            if (e.Message==VoiceCommand.Initaiate.ToString())
            {
                
                RingBellOnInComingCall();
                lbCallerID.Text = e.SenderDisplayName + " is calling";
                SetSenderEmailIdInComboBox(e.CallerEmailID);
            }
            else if (e.Message == VoiceCommand.Accept.ToString())
            {
                StartCall();
            }
            else if (e.Message == VoiceCommand.Terminate.ToString())
            {

                StopBellOnReject();
            }
        }
        private void M_chatManager_On_ChatSent(object sender, ChatSentEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnChatSent(M_chatManager_On_ChatSent)
                    , sender
                    , e);
                return;
            }
        }
        private void m_chatManager_On_SupportUserUniqueIDReceived(object sender, communicaioUniqueIdReceivedEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnSupportUserUniqueIDReceived(m_chatManager_On_SupportUserUniqueIDReceived)
                    , sender
                    , e);
                return;
            }

            m_strCommunicationID = e.UniqueIDForCommunication;
            m_strWebcloudId = e.WebcloudID;


        }
        private void DiscntNrmltUser()
        {
            callerGroup.Enabled = false;
            m_chatManager.On_DisconnectNormalUser += m_chatManager_On_DisconnectNormalUser;
            m_chatManager.DisconnectNormlUser(textEmail.Text, Settings().SupportServerName);
           
        }
        private void m_chatManager_On_DisconnectNormalUser(object sender, DisconnectSupportUserInfoEventArgs e)
        {


            try
            {
                if (this.InvokeRequired)
                {
                    this.BeginInvoke((Action)delegate
                    {
                        if (e.Status == "success")
                        {
                            labelStatus.Text = "Disconnected Successfully";
                            btnConnect.BackColor = System.Drawing.Color.LimeGreen;
                            btnConnect.Text = "Connect";
                            groupOnlineMem.Enabled = false;
                            StopDataToOutputDevice();
                        }
                        else
                        {
                            labelStatus.Text = "Connection Error";
                        }
                    });
                }
                else
                {
                    if (e.Status == "success")
                    {
                       
                        labelStatus.Text = "Disconnected Successfully";
                        btnConnect.BackColor = System.Drawing.Color.LimeGreen;
                        btnConnect.Text = "Connect";
                        groupOnlineMem.Enabled = false;
                        StopDataToOutputDevice();
                    }
                    else
                    {
                        labelStatus.Text = "Connection Error";
                    }
                }


            }
            catch (Exception)
            {
                //MessageBox.Show(ex.Message);
            }
        }
        private void ConnectingToUser()
        {
            SignalRChatManager chatManager = (SignalRChatManager)m_chatManager;
            if (chatManager.Started)
            {
                if (MessageBox.Show("Connected. Do you want to Disconnect. Confirm?", "WebCloudSupport", MessageBoxButtons.YesNo) == DialogResult.Yes)
                {
                    DiscntNrmltUser();
                    return;
                }
                else
                {
                    return;
                }
            }
            labelStatus.Text = "Please wait..";
            chatManager.On_CheckConnection += ChatManager_On_CheckConnection;
            //chatManager.Start();

        }
        private void ChatManager_On_CheckConnection(object sender, ConnectionEventArgs e)
        {
            if (!e.Status)
            {
                if (this.InvokeRequired)
                {
                    this.Invoke(new SignalRChatManager.OnCheckConnection(ChatManager_On_CheckConnection), sender, e);
                    return;
                }
                labelStatus.Text = "Unable to connect to server.Please check settings and internet connection.";
                return;
            }
            SignalRChatManager chatManager = sender as SignalRChatManager;
            chatManager.On_AuthenticateUser += chatManager_On_AuthenticateUser;
            chatManager.AuthenticateUser(Settings().UserName
                                            , Settings().Password
                                            , Settings().SupportServerName
                                            , Settings().SupportServerUrl
                                            , Settings().NickName
                                            , Settings().PhoneNo, Settings().EmailID);
        }
        private void chatManager_On_AuthenticateUser(object sender, AuthenticateUserEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnAuthenticateUser(chatManager_On_AuthenticateUser), sender, e);
                return;
            }
            if (e.Status == Status.sucess.ToString())
            {
                labelStatus.Text = "Connected";
                btnConnect.Text = "Disconnect";
                btnConnect.BackColor = System.Drawing.Color.Tomato;
                groupOnlineMem.Enabled = true;
            }
            else
            {
                labelStatus.Text = "Failed to connect";
            }
        }
        private void m_chatManager_On_MultimediaChatRecieved(object sender, MultimediaChatReceivedEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnMultimediaChatReceived(m_chatManager_On_MultimediaChatRecieved)
                    , sender
                    , e);
                return;
            }
            //formchat.ChatManager_On_Multimedia_ChatRecieved(sender, e);
            if (e.MsgType == "Voice")
            {
                m_BufferArray.AddRange(e.Message);
                if (m_BufferArray.Count >= m_JitterBufferSize)
                {
                    SendDataToOutputDevice();

                }

                return;
            }
        }
        private void m_chatManager_On_MultimediaChatSent(object sender, MultimediaChatSentEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnMultimediaChatSent(m_chatManager_On_MultimediaChatSent)
                    , sender
                    , e);
                return;
            }
            //formchat.ChatManager_On_Multimedia_ChatSent(sender, e);
        }
        private void m_chatManager_On_CommunicationUniqueIdReceived(object sender, communicaioUniqueIdReceivedEventArgs e)
        {
            m_chatManager.GetSupportUserUniqueID();
        }
        public void SendDataToOutputDevice()
        {
            
            byte[] DataByte = m_BufferArray.ToArray();
            byte[] ConvertedBytes = null;
            ConvertedBytes = G711.Decode_aLaw(DataByte, 0, DataByte.Length);
            m_BufferArray.Clear();
            MemoryStream ms = new MemoryStream(ConvertedBytes);
            provider = new RawSourceWaveStream(ms, new WaveFormat(8000, 16, 1));
            waveout.Init(provider);
            waveout.Play();
            labelStatus.Text = "Voice Message Received | " + DateTime.Now.ToString() + " | TransportMode = " + SignalRChatManager.strTransportMode;
            i++;
            if(i%100 == 0)
            {
                GC.Collect();
            }
            this.Refresh();
        }
        public void StopDataToOutputDevice()
        {
            try
            {
                waveout.Stop();
                labelStatus.Text = "Voice Ended";
            }
            catch(Exception ex)
            {
                labelStatus.Text = ex.ToString();
            }
            
        }
        private async void GetAllOnlineUsersList()
        {
            try
            {
                List<UserInfo> onlineUserList = await m_ObjMainForm.ApiService.GetAllOnlineUsersList();
                combOnlineMemb.Items.Clear();
                foreach (UserInfo onlineUser in onlineUserList)
                {
                    string strEmaiId = onlineUser.EmailID;
                    if (strEmaiId != null && strEmaiId != textEmail.Text)
                    {
                        combOnlineMemb.Items.Add(strEmaiId);
                    }
                }
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.Message,"Error");
            }
            

        }
        private async Task<bool> IsUserIsOnline(string strEmail)
        {
            try
            {
                List<UserInfo> onlineUserList = await m_ObjMainForm.ApiService.GetAllOnlineUsersList();
                foreach (UserInfo onlineUser in onlineUserList)
                {
                    if (onlineUser.EmailID == strEmail)
                    {
                        return true;
                    }
                }
                return false;
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.Message, "Error");
                return false;
            }
            
        }
        private void btnRefresh_Click(object sender, EventArgs e)
        {
            GetAllOnlineUsersList();
        }
        private void combOnlineMemb_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_chatManager.SenderEmail = textEmail.Text;
            m_chatManager.RecieveEmail = combOnlineMemb.SelectedItem.ToString();
            int index = combOnlineMemb.SelectedIndex;
            if(index>=0)
            {
                callerGroup.Enabled = true;
            }
        }
        private async void btnPhCall_Click(object sender, EventArgs e)
        {
            string strReviverEmail = combOnlineMemb.SelectedItem.ToString();
            if (!await IsUserIsOnline(strReviverEmail))
            {
                labelStatus.Text = "User is offline";
                return;
            }
            btnDisconCall.Enabled = true;
            if (!m_inComingCall)
            {
                VoiceChat vChat = new VoiceChat();
                vChat.VCommand = VoiceCommand.Initaiate;
                byte[] Message = m_chatManager.ObjectToByteArray(vChat);
                m_chatManager.SendMultiMedMsgWithEmailID(Message, Message.Length, textEmail.Text, strReviverEmail);
            }
            else
            {
                VoiceChat vChat = new VoiceChat();
                vChat.VCommand = VoiceCommand.Accept;
                byte[] Message = m_chatManager.ObjectToByteArray(vChat);
                m_chatManager.SendMultiMedMsgWithEmailID(Message, Message.Length, textEmail.Text, strReviverEmail);
                StartCall();
                StopBellOnAccept();
            }

            
        }
        private void btnDisconCall_Click(object sender, EventArgs e)
        {
            m_chatManager.SendChatEx(VoiceCommand.Terminate.ToString(), textEmail.Text, combOnlineMemb.SelectedItem.ToString());
            StopBellOnReject();
        }
        private void RingBellOnInComingCall()
        {
            btnDisconCall.Enabled = true;
            callerGroup.Enabled = true;
            m_player.PlayLooping();
            lbPhoneGif.Show();
            m_inComingCall = true;
        }
        private void StopBellOnAccept()
        {
            btnDisconCall.Enabled = true;
            m_player.Stop();
            lbPhoneGif.Hide();
            m_inComingCall = false;
        }
        private void StopBellOnReject()
        {
            btnDisconCall.Enabled = false;
            m_player.Stop();
            lbPhoneGif.Hide();
            m_inComingCall = false;
            rec.RecordEnd();
            m_BufferArray.Clear();
            
        }
        private void SetSenderEmailIdInComboBox(string strEmaiId)
        {
            m_chatManager.RecieveEmail = strEmaiId;
            if (!combOnlineMemb.Items.Contains(strEmaiId))
            {
                combOnlineMemb.Items.Add(strEmaiId);
            }
            combOnlineMemb.SelectedIndex = combOnlineMemb.FindStringExact(strEmaiId);
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
