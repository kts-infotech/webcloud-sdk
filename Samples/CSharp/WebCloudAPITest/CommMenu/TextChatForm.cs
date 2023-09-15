using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;
using WebCloudAPITest.CommMenu;


namespace WebCloudAPITest
{
    public partial class TextChatForm : Form
    {
        private SignalRChatManager m_chatManager;
        public delegate void OnAuthenticateUser(object sender, AuthenticateUserEventArgs e);

        private WebCloudAPIForm m_ObjMainForm;
        int iMessageCount;
        string m_strCommunicationID;
        string m_strWebcloudId;
        public TextChatForm(WebCloudAPIForm obj)
        {
            InitializeComponent();
            m_ObjMainForm = obj;
            iMessageCount = 0;
            m_strCommunicationID = string.Empty;
            m_strWebcloudId = string.Empty;
            textEmail.Text = obj.GetUserID();
        }

        private void btnSentMsg_Click(object sender, EventArgs e)
        {
            AddChatToChatWindow(TextBoxChat.Text.Trim(),"Arun","Send");
            TextBoxChat.Focus();
            if (radSupportUser.Checked)
                SendMessage();
            else
                SendMessageByEmail();
        }
        
        private void SendMessage()
        {
            if (!string.IsNullOrEmpty(TextBoxChat.Text.Trim()) && radSupportUser.Checked)
            {

                if (!m_chatManager.SendChat(TextBoxChat.Text.Trim()
                    , m_chatManager.CurrentUserUniqueID
                    , m_strCommunicationID
                    , m_strWebcloudId))
                {
                    MessageBox.Show("User went offline", "WebCloud Support");
                }
                TextBoxChat.Text = string.Empty;
            }
        }

        private void SendMessageByEmail()
        {
            if (!string.IsNullOrEmpty(TextBoxChat.Text.Trim()))
            {

                m_chatManager.SendChatEx(TextBoxChat.Text.Trim(),textEmail.Text,combOnlineMemb.SelectedItem.ToString());
                TextBoxChat.Text = string.Empty;
            }
        }


        public void AddChatToChatWindow(string strMessage, string strName, string strMessageType)
        {
            Label label;
            if (strMessageType == "Send")
            {
                label = SendMessage(strMessage, strName);
            }
            else
            {
                label = RecieveMessage(strMessage, strName);
            }

            flowLayoutPanel.Controls.Add(label);
            flowLayoutPanel.AutoScrollPosition = new Point(label.Left, label.Top);
        }

        public Label SendMessage(string strMessage, string strName)
        {
            
            Label labelSend = new Label();
            labelSend.AutoSize = true;
            labelSend.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            labelSend.Location = new System.Drawing.Point(3, 3);
            labelSend.Margin = new System.Windows.Forms.Padding(3);
            labelSend.MinimumSize = new System.Drawing.Size(350, 0);
            labelSend.Name = "labelSend"+ iMessageCount.ToString();
            labelSend.Size = new System.Drawing.Size(350, 13);
            labelSend.TabIndex = 0;
            labelSend.Text = strName + ": " + strMessage;
            iMessageCount++;
            return labelSend;
            
        }

        public Label RecieveMessage(string strMessage, string strName)
        {
            Label labelRecieve = new Label();
            labelRecieve.AutoSize = true;
            labelRecieve.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            labelRecieve.Location = new System.Drawing.Point(3, 3);
            labelRecieve.Margin = new System.Windows.Forms.Padding(3);
            labelRecieve.MinimumSize = new System.Drawing.Size(350, 0);
            labelRecieve.Name = "labelRecieve"+ iMessageCount.ToString();
            labelRecieve.Size = new System.Drawing.Size(350, 13);
            labelRecieve.TabIndex = 0;
            labelRecieve.Text = strName+": "+strMessage;
            labelRecieve.TextAlign=System.Drawing.ContentAlignment.MiddleRight;
            iMessageCount++;
            return labelRecieve;
        }
        
        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (btnConnect.Text == "Connect")
            {
                groupBoxChatMode.Enabled = false;
                if (radSupportUser.Checked)
                {
                    m_chatManager = new SignalRChatManager(Settings(), ChatManagerMode.ServerMode);
                }
                else if(radMemberChat.Checked)
                {
                    m_chatManager = new SignalRChatManager(Settings(), ChatManagerMode.ClientMode);
                    GetAllOnlineUsersList();
                }

                m_chatManager.On_NewChatContact += m_chatManager_On_NewChatContact;
                m_chatManager.On_ChatRecieved += m_chatManager_On_ChatRecieved;
                m_chatManager.On_ChatSent += M_chatManager_On_ChatSent;
                m_chatManager.On_CurrentUserUniqueIdReceived += m_chatManager_On_CommunicationUniqueIdReceived;
                m_chatManager.On_SupportUserUniqueIDReceived += m_chatManager_On_SupportUserUniqueIDReceived;
                //m_chatManager.On_MultimediaChatSent += m_chatManager_On_MultimediaChatSent;
                //m_chatManager.On_MultimediaChatRecieved += m_chatManager_On_MultimediaChatRecieved;
                m_chatManager.Start();
            }
            else if (btnConnect.Text != "Connect" && radMemberChat.Checked)
            {
                labelStatus.Text = "Disconnected Successfully";
                btnConnect.BackColor = System.Drawing.Color.LimeGreen;
                btnConnect.Text = "Connect";
                groupBoxChatMode.Enabled = true;
                return;
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
            //GetProductsTabControlByServerName(info.chatmanager.Appsettings.SupportServerName);
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

        private void m_chatManager_On_ChatRecieved(object sender, ChatReceivedEventArgs e)
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnChatReceived(m_chatManager_On_ChatRecieved)
                    , sender
                    , e);
                return;
            }
            AddChatToChatWindow(e.Message, e.SenderDisplayName, "Recieved");
        }

        public void ChatManager_On_ChatRecieved(object sender, ChatReceivedEventArgs e)
        {

            if (this.InvokeRequired)
            {
                this.Invoke(new SignalRChatManager.OnChatReceived(ChatManager_On_ChatRecieved)
                            , sender
                            , e);
                return;
            }

            //creating chat details object to keep track chat detials
            ChatInfo chatInfo = new ChatInfo();
            chatInfo.Message = e.Message;
            chatInfo.CommunicationId = e.SenderUniqueID;
            chatInfo.Type = MessageType.Received;
            chatInfo.Name = e.SenderDisplayName;
            chatInfo.UnreadMessage = chatInfo.UnreadMessage + 1;
            
            //add message to message window
            
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


        private void m_chatManager_On_CommunicationUniqueIdReceived(object sender, communicaioUniqueIdReceivedEventArgs e)
        {
            m_chatManager.GetSupportUserUniqueID();
            m_strCommunicationID = e.UniqueIDForCommunication;
            m_strWebcloudId = e.WebcloudID;
        }

        private void ConnectingToUser()
        {
            SignalRChatManager chatManager = (SignalRChatManager)m_chatManager;
            if (chatManager.Started)
            {
                if (MessageBox.Show("Connected. Do you want to Disconnect. Confirm?", "WebCloudSupport", MessageBoxButtons.YesNo) == DialogResult.Yes)
                {
                    DiscntSupportUser(m_chatManager);
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

        private void DiscntSupportUser(object tag)
        {
            SignalRChatManager chatManager = (SignalRChatManager)tag;
            chatManager.On_DisconnectSupportUser += ChatManager_On_DisconnectSupportUser;
            chatManager.DisconnectSupportUser(chatManager.CurrentUserUniqueID, chatManager.Appsettings.SupportServerName);
        }

        public void ChatManager_On_DisconnectSupportUser(object sender, DisconnectSupportUserInfoEventArgs e)
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
                            groupBoxChatMode.Enabled = true;
                        }
                        else
                        {
                            labelStatus.Text = "Connection  Error";
                            groupBoxChatMode.Enabled = true;
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
                        groupBoxChatMode.Enabled = true;
                    }
                    else
                    {
                        labelStatus.Text = "Connection  Error";
                        groupBoxChatMode.Enabled = true;
                    }
                }


            }
            catch (Exception)
            {
                throw new NotImplementedException();
            }
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
            }
            else
            {
                labelStatus.Text = "Failed to connect";
                groupBoxChatMode.Enabled = true;
            }
        }

        private void radMemberChat_CheckedChanged(object sender, EventArgs e)
        {
            if (radMemberChat.Checked)
            {
                groupOnlineMem.Enabled = true;
            }
            else
            {
                groupOnlineMem.Enabled = false;
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
                    if (strEmaiId != null)
                    {
                        combOnlineMemb.Items.Add(strEmaiId);
                    }
                }
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.Message, "Error");
            }


        }

        private void combOnlineMemb_SelectedIndexChanged(object sender, EventArgs e)
        {
            UserInfo selsctedUser = (UserInfo)combOnlineMemb.SelectedValue;
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            GetAllOnlineUsersList();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
