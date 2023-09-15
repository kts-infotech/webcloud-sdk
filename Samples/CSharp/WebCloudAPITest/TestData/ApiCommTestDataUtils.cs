using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using WebCloud.Api.DS;
using NAudio.Wave;
using System.IO;
using WebCloudAPITest.CommMenu;

namespace WebCloudAPITest.TestData
{
    public class AudioRecorder
    {
        public static int m_BufferPer10Ms = 160;
        public static int m_SleepIntervalPer10Ms = 5;

        public static double m_humanVoiceAmplitude = 0.175;

        //FormChat chatControl;
        Thread m_chatSendThread;
        MultimediaChatSentEventArgs args = new MultimediaChatSentEventArgs();
        private SignalRChatManager manager;
        private string m_strWebcloudId;
        private string m_strCommunicationID;

        private static WaveIn sourceStream;
        private WaveFileWriter waveWriter;

        private String FilePath;
        private String FileName;
        private int InputDeviceIndex;
        private int i = 0;

        byte[] Remainingdatabuffer = new byte[0];

        List<byte> mahByteArray = new List<byte>();
        long pos = 0;
        public SignalRChatManager Manager
        {
            get
            {
                return manager;
            }

            set
            {
                manager = value;
            }
        }

        public string StrWebcloudId
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

        public string StrCommunicationID
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
        /*
        public FormChat ChatControl
        {
            get
            {
                return chatControl;
            }

            set
            {
                chatControl = value;
            }
        }
        */
        public AudioRecorder(int inputDeviceIndex, String filePath, String fileName)
        {
            int waveInDevices = WaveIn.DeviceCount;

            for (int waveInDevice = 0; waveInDevice < waveInDevices; waveInDevice++)
            {
                WaveInCapabilities deviceInfo = WaveIn.GetCapabilities(waveInDevice);
                i = WaveIn.GetCapabilities(waveInDevice).Channels;
            }
            InputDeviceIndex = inputDeviceIndex;
            FileName = fileName;
            FilePath = filePath;

        }

        public void StartVoiceRecording()
        {
            if (i == 0)
            {
                int waveInDevices = WaveIn.DeviceCount;
                for (int waveInDevice = 0; waveInDevice < waveInDevices; waveInDevice++)
                {
                    WaveInCapabilities deviceInfo = WaveIn.GetCapabilities(waveInDevice);
                    i = WaveIn.GetCapabilities(waveInDevice).Channels;
                }
                if (i == 0)
                {
                    Double[] data = { 0 };
                    // ChatControl.OnBufferValueChanged(data, 404);
                    return;
                }
            }
            sourceStream = new WaveIn
            {
                DeviceNumber = InputDeviceIndex,
                WaveFormat =
                    new WaveFormat(8000, 16, 1),
                BufferMilliseconds = m_SleepIntervalPer10Ms * 10,
            };

            sourceStream.DataAvailable += this.SourceStreamDataAvailable;

            if (!Directory.Exists(FilePath))
            {
                Directory.CreateDirectory(FilePath);
            }

            string strFilePath = Path.Combine(FilePath, FileName);
            waveWriter = new WaveFileWriter(strFilePath, sourceStream.WaveFormat);

            sourceStream.StartRecording();
        }
        public void StartRecording()
        {
            StartVoiceRecording();

        }

        public void SourceStreamDataAvailable(object sender, WaveInEventArgs e)
        {

            int Buffersize = m_BufferPer10Ms * m_SleepIntervalPer10Ms;
            int bytesread = 0;
            byte[] databuffer = new byte[Buffersize];

            if (waveWriter == null) return;

            if (!IsHumanVoice(e.Buffer, e.BytesRecorded))
            {
                waveWriter.Flush();
                return;
            }

            byte[] bytes = new byte[e.Buffer.Length];
            Array.Copy(e.Buffer, 0, bytes, 0, bytes.Length);
            //your local byte[]
            mahByteArray.AddRange(bytes);

            Stream stream = new MemoryStream(mahByteArray.ToArray());
            stream.Position = pos;

            bytesread = stream.Read(databuffer, 0, databuffer.Length);
            if (bytesread > 0)
            {
                pos += bytesread;
                //args.Message = databuffer;
                args.Message = G711.Encode_aLaw(databuffer, 0, bytesread);
                args.length = args.Message.Length;

                args.MsgType = "Voice";
                args.SenderUniqueID = StrCommunicationID;
                args.ReceiverWebCloudID = StrWebcloudId;
                m_chatSendThread = new Thread(Manager.SendMultimediaMessageEmail);
                m_chatSendThread.Start(args);

                waveWriter.Write(e.Buffer, 0, e.BytesRecorded);
                waveWriter.Flush();

            }

            waveWriter.Write(e.Buffer, 0, e.BytesRecorded);
            waveWriter.Flush();

        }


        private bool IsHumanVoice(byte[] buffer, int bytesRecorded)
        {
            Double[] data;
            data = new Double[(bytesRecorded - 44) / 4];//shifting the headers out of the PCM data;

            double voiceSample = 0;
            for (int i = 0; i < data.Length - i * 4; i++)
            {
                data[i] = (BitConverter.ToInt32(buffer, (1 + i) * 4)) / 65536.0;
                //65536.0.0=2^n,       n=bits per sample;
                if (Math.Abs(data[i]) > 25)
                {
                    voiceSample = voiceSample + 1;
                }
            }

            double rate = voiceSample / data.Length;
            //ChatControl.OnBufferValueChanged(data, rate);
            if (rate >= m_humanVoiceAmplitude)
            {

                return true;
            }
            else
            {
                return true;
            }


        }

        public void RecordEnd()
        {
            try
            {
                if (sourceStream != null)
                {
                    sourceStream.StopRecording();
                    sourceStream.Dispose();
                    sourceStream = null;
                }
                if (waveWriter == null)
                {
                    return;
                }
                waveWriter.Dispose();
                waveWriter = null;
                if (Directory.Exists(FilePath))
                {
                    Directory.Delete(FilePath, true);
                }
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
    }

    public partial class ApiTestDataUtil
    {


         
        public async Task InvokeGetAllActiveSiteUsersListAPI()
        {

            try
            {
                List<UserInfo> Info = await ObjMainForm.ApiService.GetAllActiveSiteUsersList();
                AllUserInfoForm form = new AllUserInfoForm(Info);
                form.Show();

                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            

        }

        public async Task InvokeGetAllSiteAdminUsersListAPI()
        {
            try
            {
                List<UserInfo> Info = await ObjMainForm.ApiService.GetAllSiteAdminUsersList();
                AllUserInfoForm form = new AllUserInfoForm(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

            
        }

        public async Task InvokeGetAllOnlineUsersListAPI()
        {
            try
            {
                List<UserInfo> Info = await ObjMainForm.ApiService.GetAllOnlineUsersList();
                AllOnlineUsers form = new AllOnlineUsers(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetAllOnlineNormalUsersListAPI()
        {

            try
            {
                List<UserInfo> Info = await ObjMainForm.ApiService.GetAllOnlineNormalUsersList();
                AllOnlineUsers form = new AllOnlineUsers(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetAllOnlineSupportUsersListAPI()
        {
            try
            {
                List<UserInfo> Info = await ObjMainForm.ApiService.GetAllOnlineSupportUsersList();
                AllOnlineUsers form = new AllOnlineUsers(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }


           
        }

        public void InvokeSendEmailAPI()
        {
            SendEmailForm form = new SendEmailForm(ObjMainForm);
            form.Show();
            
            
        }

        public void  InvokeLaunchTextChatDemoAPI()
        {
            TextChatForm form = new TextChatForm(ObjMainForm);
            form.Show();
        }

        public void InvokeLaunchVoiceChatDemoAPI()
        {

            VoiceChatForm form = new VoiceChatForm(ObjMainForm);
            form.Show();
        }
    }
}
