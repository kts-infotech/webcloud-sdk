using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;
using Microsoft.AspNet.SignalR.Client;
using Newtonsoft.Json.Linq;
using System.Threading;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace WebCloudAPITest.CommMenu
{
    public class G711
    {
        #region byte[] ALawCompressTable

        private static readonly byte[] ALawCompressTable = new byte[]{
        1,1,2,2,3,3,3,3,
        4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,
        5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,
        6,6,6,6,6,6,6,6,
        6,6,6,6,6,6,6,6,
        6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7
    };

        #endregion

        #region short[] ALawDecompressTable

        private static readonly short[] ALawDecompressTable = new short[]{
        -5504, -5248, -6016, -5760, -4480, -4224, -4992, -4736,
        -7552, -7296, -8064, -7808, -6528, -6272, -7040, -6784,
        -2752, -2624, -3008, -2880, -2240, -2112, -2496, -2368,
        -3776, -3648, -4032, -3904, -3264, -3136, -3520, -3392,
        -22016,-20992,-24064,-23040,-17920,-16896,-19968,-18944,
        -30208,-29184,-32256,-31232,-26112,-25088,-28160,-27136,
        -11008,-10496,-12032,-11520,-8960, -8448, -9984, -9472,
        -15104,-14592,-16128,-15616,-13056,-12544,-14080,-13568,
        -344,  -328,  -376,  -360,  -280,  -264,  -312,  -296,
        -472,  -456,  -504,  -488,  -408,  -392,  -440,  -424,
        -88,   -72,   -120,  -104,  -24,   -8,    -56,   -40,
        -216,  -200,  -248,  -232,  -152,  -136,  -184,  -168,
        -1376, -1312, -1504, -1440, -1120, -1056, -1248, -1184,
        -1888, -1824, -2016, -1952, -1632, -1568, -1760, -1696,
        -688,  -656,  -752,  -720,  -560,  -528,  -624,  -592,
        -944,  -912,  -1008, -976,  -816,  -784,  -880,  -848,
        5504,  5248,  6016,  5760,  4480,  4224,  4992,  4736,
        7552,  7296,  8064,  7808,  6528,  6272,  7040,  6784,
        2752,  2624,  3008,  2880,  2240,  2112,  2496,  2368,
        3776,  3648,  4032,  3904,  3264,  3136,  3520,  3392,
        22016, 20992, 24064, 23040, 17920, 16896, 19968, 18944,
        30208, 29184, 32256, 31232, 26112, 25088, 28160, 27136,
        11008, 10496, 12032, 11520, 8960,  8448,  9984,  9472,
        15104, 14592, 16128, 15616, 13056, 12544, 14080, 13568,
        344,   328,   376,   360,   280,   264,   312,   296,
        472,   456,   504,   488,   408,   392,   440,   424,
        88,    72,   120,   104,    24,     8,    56,    40,
        216,   200,   248,   232,   152,   136,   184,   168,
        1376,  1312,  1504,  1440,  1120,  1056,  1248,  1184,
        1888,  1824,  2016,  1952,  1632,  1568,  1760,  1696,
        688,   656,   752,   720,   560,   528,   624,   592,
        944,   912,  1008,   976,   816,   784,   880,   848
    };

        #endregion

        #region byte[] MuLawCompressTable

        private static readonly byte[] MuLawCompressTable = new byte[]{
        0,0,1,1,2,2,2,2,3,3,3,3,3,3,3,3,
        4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
        7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
    };

        #endregion

        #region short[] MuLawDecompressTable

        private static readonly short[] MuLawDecompressTable = new short[]{
        -32124,-31100,-30076,-29052,-28028,-27004,-25980,-24956,
        -23932,-22908,-21884,-20860,-19836,-18812,-17788,-16764,
        -15996,-15484,-14972,-14460,-13948,-13436,-12924,-12412,
        -11900,-11388,-10876,-10364, -9852, -9340, -8828, -8316,
        -7932, -7676, -7420, -7164, -6908, -6652, -6396, -6140,
        -5884, -5628, -5372, -5116, -4860, -4604, -4348, -4092,
        -3900, -3772, -3644, -3516, -3388, -3260, -3132, -3004,
        -2876, -2748, -2620, -2492, -2364, -2236, -2108, -1980,
        -1884, -1820, -1756, -1692, -1628, -1564, -1500, -1436,
        -1372, -1308, -1244, -1180, -1116, -1052,  -988,  -924,
        -876,  -844,  -812,  -780,  -748,  -716,  -684,  -652,
        -620,  -588,  -556,  -524,  -492,  -460,  -428,  -396,
        -372,  -356,  -340,  -324,  -308,  -292,  -276,  -260,
        -244,  -228,  -212,  -196,  -180,  -164,  -148,  -132,
        -120,  -112,  -104,   -96,   -88,   -80,   -72,   -64,
        -56,   -48,   -40,   -32,   -24,   -16,    -8,     0,
        32124, 31100, 30076, 29052, 28028, 27004, 25980, 24956,
        23932, 22908, 21884, 20860, 19836, 18812, 17788, 16764,
        15996, 15484, 14972, 14460, 13948, 13436, 12924, 12412,
        11900, 11388, 10876, 10364,  9852,  9340,  8828,  8316,
        7932,  7676,  7420,  7164,  6908,  6652,  6396,  6140,
        5884,  5628,  5372,  5116,  4860,  4604,  4348,  4092,
        3900,  3772,  3644,  3516,  3388,  3260,  3132,  3004,
        2876,  2748,  2620,  2492,  2364,  2236,  2108,  1980,
        1884,  1820,  1756,  1692,  1628,  1564,  1500,  1436,
        1372,  1308,  1244,  1180,  1116,  1052,   988,   924,
        876,   844,   812,   780,   748,   716,   684,   652,
        620,   588,   556,   524,   492,   460,   428,   396,
        372,   356,   340,   324,   308,   292,   276,   260,
        244,   228,   212,   196,   180,   164,   148,   132,
        120,   112,   104,    96,    88,    80,    72,    64,
        56,    48,    40,    32,    24,    16,     8,     0
    };

        #endregion


        /// <summary>
        /// Default constructor.
        /// </summary>
        public G711()
        {
        }

        #region static method Encode_aLaw

        /// <summary>
        /// Encodes linear 16-bit linear PCM to 8-bit a-law.
        /// </summary>
        /// <param name="buffer">Data which to convert. Data must be in Little-Endian format.</param>
        /// <param name="offset">Offset in the buffer.</param>
        /// <param name="count">Number of bytes to encode.</param>
        /// <returns>Returns encoded data.</returns>
        /// <exception cref="ArgumentNullException">Is raised when when <b>buffer</b> is null.</exception>
        /// <exception cref="ArgumentException">Is raised when any of the arguments has invalid value.</exception>
        public static byte[] Encode_aLaw(byte[] buffer, int offset, int count)
        {
            if (buffer == null)
            {
                throw new ArgumentNullException("buffer");
            }
            if (offset < 0 || offset > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }
            if (count < 1 || (count + offset) > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }
            if ((buffer.Length % 2) != 0)
            {
                throw new ArgumentException("Invalid buufer value, it doesn't contain 16-bit boundaries.");
            }

            int offsetInRetVal = 0;
            byte[] retVal = new byte[count / 2];
            while (offsetInRetVal < retVal.Length)
            {
                // Little-Endian - lower byte,higer byte.
                short pcm = (short)(buffer[offset + 1] << 8 | buffer[offset]);
                offset += 2;

                retVal[offsetInRetVal++] = LinearToALawSample(pcm);
            }

            return retVal;
        }

        #endregion

        #region static method Decode_aLaw

        /// <summary>
        /// Decodes 8-bit a-law to 16-bit linear 16-bit PCM.
        /// </summary>
        /// <param name="buffer">Data to decode. Data must be in Little-Endian format.</param>
        /// <param name="offset">Offset in the buffer.</param>
        /// <param name="count">Number of bytes to decode.</param>
        /// <returns>Return decoded data.</returns>
        /// <exception cref="ArgumentNullException">Is raised when when <b>buffer</b> is null.</exception>
        /// <exception cref="ArgumentException">Is raised when any of the arguments has invalid value.</exception>
        public static byte[] Decode_aLaw(byte[] buffer, int offset, int count)
        {
            if (buffer == null)
            {
                throw new ArgumentNullException("buffer");
            }
            if (offset < 0 || offset > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }
            if (count < 1 || (count + offset) > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }

            int offsetInRetVal = 0;
            byte[] retVal = new byte[count * 2];
            for (int i = offset; i < buffer.Length; i++)
            {
                short pcm = ALawDecompressTable[buffer[i]];
                retVal[offsetInRetVal++] = (byte)(pcm & 0xFF);
                retVal[offsetInRetVal++] = (byte)(pcm >> 8 & 0xFF);
            }

            return retVal;
        }

        #endregion

        #region static method Encode_uLaw

        /// <summary>
        /// Encodes linear 16-bit linear PCM to 8-bit u-law.
        /// </summary>
        /// <param name="buffer">Data which to convert. Data must be in Little-Endian format.</param>
        /// <param name="offset">Offset in the buffer.</param>
        /// <param name="count">Number of bytes to encode.</param>
        /// <returns>Returns encoded data.</returns>
        public static byte[] Encode_uLaw(byte[] buffer, int offset, int count)
        {
            if (buffer == null)
            {
                throw new ArgumentNullException("buffer");
            }
            if (offset < 0 || offset > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }
            if (count < 1 || (count + offset) > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }
            if ((buffer.Length % 2) != 0)
            {
                throw new ArgumentException("Invalid buufer value, it doesn't contain 16-bit boundaries.");
            }

            int offsetInRetVal = 0;
            byte[] retVal = new byte[count / 2];
            while (offsetInRetVal < retVal.Length)
            {
                // Little-Endian - lower byte,higer byte.
                short pcm = (short)(buffer[offset + 1] << 8 | buffer[offset]);
                offset += 2;

                retVal[offsetInRetVal++] = LinearToMuLawSample(pcm);
            }

            return retVal;
        }

        #endregion

        #region static method Decode_uLaw

        /// <summary>
        /// Decodes 8-bit u-law to 16-bit linear 16-bit PCM.
        /// </summary>
        /// <param name="buffer">Data to decode. Data must be in Little-Endian format.</param>
        /// <param name="offset">Offset in the buffer.</param>
        /// <param name="count">Number of bytes to decode.</param>
        /// <returns>Return decoded data.</returns>
        /// <exception cref="ArgumentNullException">Is raised when when <b>buffer</b> is null.</exception>
        /// <exception cref="ArgumentException">Is raised when any of the arguments has invalid value.</exception>
        public static byte[] Decode_uLaw(byte[] buffer, int offset, int count)
        {
            if (buffer == null)
            {
                throw new ArgumentNullException("buffer");
            }
            if (offset < 0 || offset > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }
            if (count < 1 || (count + offset) > buffer.Length)
            {
                throw new ArgumentException("Argument offset is out of range.");
            }

            int offsetInRetVal = 0;
            byte[] retVal = new byte[count * 2];
            for (int i = offset; i < buffer.Length; i++)
            {
                short pcm = MuLawDecompressTable[buffer[i]];
                retVal[offsetInRetVal++] = (byte)(pcm & 0xFF);
                retVal[offsetInRetVal++] = (byte)(pcm >> 8 & 0xFF);
            }

            return retVal;
        }

        #endregion


        #region static method LinearToALawSample

        private static byte LinearToALawSample(short sample)
        {
            int sign = 0;
            int exponent = 0;
            int mantissa = 0;
            byte compressedByte = 0;

            sign = ((~sample) >> 8) & 0x80;
            if (sign == 0)
            {
                sample = (short)-sample;
            }
            if (sample > 32635)
            {
                sample = 32635;
            }
            if (sample >= 256)
            {
                exponent = (int)ALawCompressTable[(sample >> 8) & 0x7F];
                mantissa = (sample >> (exponent + 3)) & 0x0F;
                compressedByte = (byte)((exponent << 4) | mantissa);
            }
            else
            {
                compressedByte = (byte)(sample >> 4);
            }

            compressedByte ^= (byte)(sign ^ 0x55);

            return compressedByte;
        }

        #endregion

        #region static method LinearToMuLawSample

        private static byte LinearToMuLawSample(short sample)
        {
            int cBias = 0x84;
            int cClip = 32635;

            int sign = (sample >> 8) & 0x80;
            if (sign != 0)
            {
                sample = (short)-sample;
            }
            if (sample > cClip)
            {
                sample = (short)cClip;
            }
            sample = (short)(sample + cBias);
            int exponent = (int)MuLawCompressTable[(sample >> 7) & 0xFF];
            int mantissa = (sample >> (exponent + 3)) & 0x0F;
            int compressedByte = ~(sign | (exponent << 4) | mantissa);

            return (byte)compressedByte;
        }

        #endregion

    }

    public class SignalRChatManager
    {
        private IHubProxy m_hub;

        public delegate void OnMultimediaChatSent(object sender, MultimediaChatSentEventArgs e);
        public event OnMultimediaChatSent On_MultimediaChatSent;
        public delegate void OnMultimediaChatReceived(object sender, MultimediaChatReceivedEventArgs e);
        public event OnMultimediaChatReceived On_MultimediaChatRecieved;

        public delegate void OnChatSent(object sender, ChatSentEventArgs e);
        public event OnChatSent On_ChatSent;
        public delegate void OnChatReceived(object sender, ChatReceivedEventArgs e);
        public event OnChatReceived On_ChatRecieved;
        public delegate void OnNewChatContact(object sender, ChatNewContactEventArgs e);
        public event OnNewChatContact On_NewChatContact;
        public delegate void OnCheckConnection(object sender, ConnectionEventArgs e);
        public event OnCheckConnection On_CheckConnection;
        public delegate void OnSiteUserUniqueIdReceived(object sender, communicaioUniqueIdReceivedEventArgs e);
        public event OnSiteUserUniqueIdReceived On_CurrentUserUniqueIdReceived;
        public delegate void OnSupportUserUniqueIDReceived(object sender, communicaioUniqueIdReceivedEventArgs e);
        public event OnSupportUserUniqueIDReceived On_SupportUserUniqueIDReceived;
        public delegate void OnAuthenticateUser(object sender, AuthenticateUserEventArgs e);
        public event OnAuthenticateUser On_AuthenticateUser;
        public delegate void OnDisconnectSupportUser(object sender, DisconnectSupportUserInfoEventArgs e);
        public event OnDisconnectSupportUser On_DisconnectSupportUser;
        public delegate void OnDisconnectNormalUser(object sender, DisconnectSupportUserInfoEventArgs e);
        public event OnDisconnectNormalUser On_DisconnectNormalUser;

        private const string API_SET_SUPPORT_USER_INFO = "SetSupportUserInfo";
        private const string API_SET_SITE_USER_INFO = "SetSiteUsernfo";
        private const string API_SET_SEND_CHAT = "SendChat";
        private const string API_SET_SEND_CHAT_WITH_EMAIL = "SendChatEx";
        private const string API_SET_SEND_VOICE_CHAT_WITH_EMAIL = "SendMultiMedMsgWithEmailId";

        private const string API_SET_SEND_MULTIMEDIA_CHAT = "SendMultimediaMessage";

        private const string API_GET_UNIQUE_ID_FOR_CURRENT_USER = "GetUniqueIDForCurrentUser";
        private const string API_GET_UNIQUE_ID_OF_SUPPORT_USER = "GetUniqueIDOfSupportUser";
        private const string API_AUTHENTICATE_USER = "AuthenticateUser";
        private const string API_DISCONNECT_SUPPORT_USER = "DisconnectSupportUser";
        private const string API_DISCONNECT_NORMAL_USER = "DisconnectNormalUser";



        private const string CALL_BACK_NEW_USER_VISITED = "NewUserVisited";
        private const string CALL_BACK_CHAT_RECIEVED = "ChatReceived";

        private const string CALL_BACK_MULTIMEDIA_CHAT_RECIEVED = "MultimediaChatReceived";

        private const string CALL_BACK_CURRENT_USER_UNIQUE_ID_RECIEVED = "CurrentUserUniqueIDRecieved";
        private const string CALL_BACK_SUPPORT_USER_UNIQUE_ID_RECIEVED = "SupportUserUniqueIDReceived";
        private const string CALL_BACK_AUTHENTICATION_RESPONSE_RECIEVED = "AuthenticationResponseRecieved";
        private const string CALL_BACK_DISCONNECT_SUPPORT_USER_RESPONSE_RECIEVED = "DisconnectSupportUserResponseRecieved";
        private const string CALL_BACK_DISCONNECT_NORMAL_USER_RESPONSE_RECIEVED = "DisconnectNormalUserResponseRecieved";


        public static string strTransportMode;
        private string m_strCurrentUserUniqueID;

        private ChatManagerMode m_chatMode;
        private AppSettings m_appsettings;
        private int m_EventFiredCount = 0;
        private string m_strSenderEmail;
        private string m_strRecieverEmail;
        public string SenderEmail
        {
            get
            {
                return m_strSenderEmail;
            }

            set
            {
                m_strSenderEmail = value;
            }
        }

        public string RecieveEmail
        {
            get
            {
                return m_strRecieverEmail;
            }

            set
            {
                m_strRecieverEmail = value;
            }
        }
        public int EventFiredCount
        {
            get
            {
                return m_EventFiredCount;
            }

            set
            {
                m_EventFiredCount = value;
            }
        }
        public string CurrentUserUniqueID
        {
            get
            {
                return m_strCurrentUserUniqueID;
            }

            set
            {
                m_strCurrentUserUniqueID = value;
            }
        }

        public AppSettings Appsettings
        {
            get
            {
                return m_appsettings;
            }
        }

        private bool m_bStarted;

        public bool Started
        {
            get { return m_bStarted; }
        }
        public SignalRChatManager()
        {

        }
        public SignalRChatManager(AppSettings settings, ChatManagerMode chatMode = ChatManagerMode.ServerMode)
        {
            m_appsettings = settings;
            m_chatMode = chatMode;
            m_hub = null;
            m_strCurrentUserUniqueID = string.Empty;
            m_bStarted = false;
        }
        public void Start()
        {
            if (m_bStarted)
            {
                return;
            }
            Thread thread = new Thread(new ParameterizedThreadStart(ChatMonitorThread));
            thread.Start(m_appsettings);
        }
        private void ChatMonitorThread(object param)
        {
            m_bStarted = false;
            AppSettings settings = param as AppSettings;
            var connection = new WebCloudHubConnection(settings.SupportServerUrl);
            ConnectionEventArgs e = new ConnectionEventArgs();

            try
            {
                m_hub = connection.CreateHubProxy("WebCloud");
                connection.Start().Wait();
                switch (m_chatMode)
                {
                    case ChatManagerMode.ServerMode:
                        m_hub.Invoke(API_SET_SUPPORT_USER_INFO, settings.NickName, settings.EmailID, settings.EmailID, settings.PhoneNo, settings.SupportServerUrl);
                        break;
                    case ChatManagerMode.ClientMode:
                        m_hub.Invoke(API_SET_SITE_USER_INFO, settings.NickName, settings.EmailID, settings.EmailID, "", settings.PhoneNo, settings.SupportServerUrl);
                        break;

                }

                m_hub.On(CALL_BACK_NEW_USER_VISITED, x => ProcessNewChatContact(x));
                m_hub.On(CALL_BACK_CHAT_RECIEVED, x => ProcessNewChat(x));

                m_hub.On(CALL_BACK_MULTIMEDIA_CHAT_RECIEVED, x => ProcessNewMultiMediaChat(x));

                m_hub.On(CALL_BACK_CURRENT_USER_UNIQUE_ID_RECIEVED, x => ProcessCurrentSiteUserUniqueID(x));
                m_hub.On(CALL_BACK_SUPPORT_USER_UNIQUE_ID_RECIEVED, x => ProcessNewSupportUserUniqueID(x));
                m_hub.On(CALL_BACK_AUTHENTICATION_RESPONSE_RECIEVED, x => ProcessAuthenitactionResponse(x));
                m_hub.On(CALL_BACK_DISCONNECT_SUPPORT_USER_RESPONSE_RECIEVED, x => ProcessDisconectSuprtUserResponse(x));
                m_hub.On(CALL_BACK_DISCONNECT_NORMAL_USER_RESPONSE_RECIEVED, x => ProcessDisconectNormalUserResponse(x));

                m_hub.Invoke(API_GET_UNIQUE_ID_FOR_CURRENT_USER);

                strTransportMode = connection.Transport.Name;
                e.Status = true;
            }
            catch (Exception ex)
            {
                e.Status = false;
                if (null != ex.InnerException && null != ex.InnerException.InnerException)
                {
                    e.Message = ex.InnerException.InnerException.Message;
                }
                else if (null != ex.InnerException)
                {
                    e.Message = ex.InnerException.Message;
                }
                else
                {
                    e.Message = ex.Message;
                }
            }
            if (null == On_CheckConnection)
            {
                return;
            }
            On_CheckConnection(this, e);

        }

        private void ProcessNewChatContact(JObject chatContactInfo)
        {
            if (null == On_NewChatContact)
            {
                return;
            }

            ChatNewContactEventArgs e = new ChatNewContactEventArgs();
            e.ContactUniqueID = chatContactInfo["UniqueID"].ToString();
            e.Name = chatContactInfo["Name"].ToString();
            e.EmailID = chatContactInfo["EmailID"].ToString();
            e.PhoneNo = chatContactInfo["PhoneNo"].ToString();
            //e.WebSite = chatContactInfo["WebSite"].ToString();
            e.WebcloudUniqueID = chatContactInfo["WebcloudUniqueID"].ToString();
            On_NewChatContact(this, e);

        }

        private void ProcessNewMultiMediaChat(JObject jchatInfo)
        {
            if (null == On_MultimediaChatRecieved)
            {
                return;
            }
            byte[] arrayMsg = (byte[])jchatInfo["Message"].ToObject(typeof(byte[]));
            VoiceChat vChat = (VoiceChat)ByteArrayToObject(arrayMsg);

            byte[] arrayMessage = vChat.Message;
            //byte[] arrayMessage = (byte[])jchatInfo["Message"].ToObject(typeof(byte[]));
            int length = Convert.ToInt32(jchatInfo["length"].ToString());
            string strMsgType = jchatInfo["MsgType"].ToString();
            string strSenderUniqueID = jchatInfo["SenderUniqueID"].ToString();
            string strReceiverUniqueID = jchatInfo["ReceiverUniqueID"].ToString();
            string strSenderDisplayName = jchatInfo["SenderDisplayName"].ToString();
            string strReceiverDisplayName = jchatInfo["ReceiverDisplayName"].ToString();
            string strSenderWebcloudID = jchatInfo["SenderWebcloudID"].ToString();
            string strReceiverWebCloudID = jchatInfo["ReceiverWebCloudID"].ToString();
            string strCallerEmailId = jchatInfo["CallerEmailID"].ToString();
            if (vChat.VCommand == VoiceCommand.Data)
            {
                MultimediaChatReceivedEventArgs e = new MultimediaChatReceivedEventArgs();
                e.SenderUniqueID = strSenderUniqueID;
                e.ReceiverUniqueID = strReceiverUniqueID;
                e.SenderDisplayName = strSenderDisplayName;
                e.ReceiverDisplayName = strReceiverDisplayName;
                e.SenderWebcloudID = strSenderWebcloudID;
                e.ReceiverWebCloudID = strReceiverWebCloudID;
                e.Message = arrayMessage;
                e.length = length;
                e.MsgType = strMsgType;
                e.CallerEmailID = strCallerEmailId;
                On_MultimediaChatRecieved(this, e);
            }

            else
            {
                ChatReceivedEventArgs e = new ChatReceivedEventArgs();
                e.SenderUniqueID = strSenderUniqueID;
                e.ReceiverUniqueID = strReceiverUniqueID;
                e.SenderDisplayName = strSenderDisplayName;
                e.ReceiverDisplayName = strReceiverDisplayName;
                e.SenderWebcloudID = strSenderWebcloudID;
                e.ReceiverWebCloudID = strReceiverWebCloudID;
                e.CallerEmailID = strCallerEmailId;
                if (vChat.VCommand == VoiceCommand.Initaiate)
                {
                    e.Message = VoiceCommand.Initaiate.ToString();
                }
                else if (vChat.VCommand == VoiceCommand.Accept)
                {
                    e.Message = VoiceCommand.Accept.ToString();
                }
                else if (vChat.VCommand == VoiceCommand.Reject)
                {
                    e.Message = VoiceCommand.Reject.ToString();
                }
                else if (vChat.VCommand == VoiceCommand.Terminate)
                {
                    e.Message = VoiceCommand.Terminate.ToString();
                }
                On_ChatRecieved(this, e);
            }

        }

        private void ProcessNewChat(JObject jchatInfo)
        {
            if (null == On_ChatRecieved) { return; }

            string strMessage = jchatInfo["Message"].ToString();
            string strSenderUniqueID = jchatInfo["SenderUniqueID"].ToString();
            string strReceiverUniqueID = jchatInfo["ReceiverUniqueID"].ToString();
            string strSenderDisplayName = jchatInfo["SenderDisplayName"].ToString();
            string strReceiverDisplayName = jchatInfo["ReceiverDisplayName"].ToString();
            string strSenderWebcloudID = jchatInfo["SenderWebcloudID"].ToString();
            string strReceiverWebCloudID = jchatInfo["ReceiverWebCloudID"].ToString();

            ChatReceivedEventArgs e = new ChatReceivedEventArgs();
            e.SenderUniqueID = strSenderUniqueID;
            e.ReceiverUniqueID = strReceiverUniqueID;
            e.SenderDisplayName = strSenderDisplayName;
            e.ReceiverDisplayName = strReceiverDisplayName;
            e.SenderWebcloudID = strSenderWebcloudID;
            e.ReceiverWebCloudID = strReceiverWebCloudID;
            e.Message = strMessage;
            On_ChatRecieved(this, e);
        }

        public void SendMultimediaChatEx(object param)
        {
            try
            {
                if (null == m_hub)
                {
                    return;
                }
                MultimediaChatSentEventArgs args = (MultimediaChatSentEventArgs)param;
                if (args.MsgType == "Voice")
                {
                    m_hub.Invoke(API_SET_SEND_MULTIMEDIA_CHAT, args.Message, args.length, args.SenderUniqueID, args.ReceiverWebCloudID, args.MsgType);
                    return;
                }

                return;
            }
            catch (Exception)
            {
                return;
            }
        }

        public void SendMultimediaMessageEmail(object param)
        {
            try
            {
                MultimediaChatSentEventArgs args = (MultimediaChatSentEventArgs)param;
                if (args.MsgType == "Voice")
                {
                    VoiceChat vChat = new VoiceChat();
                    vChat.Message = args.Message;
                    vChat.VCommand = VoiceCommand.Data;
                    byte[] data = ObjectToByteArray(vChat);
                    SendMultiMedMsgWithEmailID(data, data.Length, m_strSenderEmail, m_strRecieverEmail);
                    return;
                }

                return;
            }
            catch (Exception)
            {
                return;
            }
        }

        public void SendMultiMedMsgWithEmailID(byte[] Message, int length, string m_strSenderEmail, string m_strRecieverEmail)
        {
            try
            {
                if (null == m_hub)
                {
                    return;
                }

                m_hub.Invoke(API_SET_SEND_VOICE_CHAT_WITH_EMAIL, Message, length, m_strSenderEmail, m_strRecieverEmail, "Voice");
                return;
            }
            catch (Exception)
            {
                return;
            }
        }

        public byte[] ObjectToByteArray(Object obj)
        {
            if (obj == null)
                return null;

            BinaryFormatter bf = new BinaryFormatter();
            MemoryStream ms = new MemoryStream();
            bf.Serialize(ms, obj);

            return ms.ToArray();
        }

        public Object ByteArrayToObject(byte[] arrBytes)
        {
            MemoryStream memStream = new MemoryStream();
            BinaryFormatter binForm = new BinaryFormatter();
            memStream.Write(arrBytes, 0, arrBytes.Length);
            memStream.Seek(0, SeekOrigin.Begin);
            Object obj = (Object)binForm.Deserialize(memStream);

            return obj;
        }
        public bool SendMultimediaChat(byte[] strMessage, int length, string strSenderUniqueID, string strReceiverUniqueID, string strReceiverWebCloudID, string strMsgType)
        {
            try
            {
                if (null == m_hub)
                {
                    return false;
                }
                if (strMsgType == "Voice")
                {
                    m_hub.Invoke(API_SET_SEND_MULTIMEDIA_CHAT, strMessage, length, strSenderUniqueID, strReceiverUniqueID, strMsgType);
                    return true;
                }
                if (strMsgType == "Text")
                {
                    m_hub.Invoke(API_SET_SEND_MULTIMEDIA_CHAT, strMessage, length, strSenderUniqueID, strReceiverUniqueID, strMsgType).Wait();
                    if (null != On_MultimediaChatSent)
                    {
                        MultimediaChatSentEventArgs e = new MultimediaChatSentEventArgs();
                        e.SenderUniqueID = CurrentUserUniqueID;
                        e.ReceiverWebCloudID = strReceiverWebCloudID;
                        e.Message = strMessage;
                        e.length = e.Message.Length;
                        e.MsgType = strMsgType;
                        On_MultimediaChatSent(this, e);
                    }
                    return true;
                }
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        public bool SendChat(string strMessage, string strSenderUniqueID, string strReceiverUniqueID, string strReceiverWebCloudID)
        {
            try
            {
                if (null == m_hub)
                {
                    return false;
                }
                m_hub.Invoke(API_SET_SEND_CHAT, strMessage, strSenderUniqueID, strReceiverUniqueID).Wait();
                if (null != On_ChatSent)
                {
                    ChatSentEventArgs e = new ChatSentEventArgs();
                    e.SenderUniqueID = CurrentUserUniqueID;
                    e.ReceiverWebCloudID = strReceiverWebCloudID;
                    e.Message = strMessage;
                    On_ChatSent(this, e);
                }
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
        public void GetSupportUserUniqueID()
        {
            m_hub.Invoke(API_GET_UNIQUE_ID_OF_SUPPORT_USER);
        }

        private void ProcessCurrentSiteUserUniqueID(JObject userInfo)
        {
            m_strCurrentUserUniqueID = userInfo["ConnectionId"].ToString();
            if (null != On_CurrentUserUniqueIdReceived)
            {
                communicaioUniqueIdReceivedEventArgs e = new communicaioUniqueIdReceivedEventArgs();
                e.UniqueIDForCommunication = m_strCurrentUserUniqueID;
                e.WebcloudID = userInfo["WebcloudUniqueID"].ToString();
                On_CurrentUserUniqueIdReceived(this, e);
            }

        }
        private void ProcessNewSupportUserUniqueID(JObject userInfo)
        {
            if (null != On_SupportUserUniqueIDReceived)
            {
                communicaioUniqueIdReceivedEventArgs e = new communicaioUniqueIdReceivedEventArgs();
                e.UniqueIDForCommunication = userInfo["ConnectionId"].ToString();
                e.WebcloudID = userInfo["WebcloudUniqueID"].ToString();
                On_SupportUserUniqueIDReceived(this, e);
            }
        }

        public void AuthenticateUser(string strUserName, string strPassword, string strServerName, string strServerUrl, string strNickName, string strPhoneNo, string strEmail)
        {

            if (null == m_hub)
            {
                return;
            }

            m_hub.Invoke(API_AUTHENTICATE_USER, strUserName, strPassword, strServerName, strServerUrl, strNickName, strPhoneNo, strEmail).Wait();

        }
        public void DisconnectSupportUser(string strSupportUserUniqID, string strSupportServerName)
        {

            if (null == m_hub)
            {
                return;
            }

            m_hub.Invoke(API_DISCONNECT_SUPPORT_USER, strSupportUserUniqID, strSupportServerName).Wait();
        }

        public void DisconnectNormlUser(string strNrmlUserEmailId, string strSupportServerName)
        {

            if (null == m_hub)
            {
                return;
            }

            m_hub.Invoke(API_DISCONNECT_NORMAL_USER, strNrmlUserEmailId, strSupportServerName).Wait();
        }
        private void ProcessAuthenitactionResponse(JObject jAuthenticationResponse)
        {
            if (null != On_AuthenticateUser)
            {
                AuthenticateUserEventArgs e = new AuthenticateUserEventArgs();
                e.UserName = jAuthenticationResponse["UserName"].ToString();
                e.Password = jAuthenticationResponse["Password"].ToString();
                e.ServerName = jAuthenticationResponse["ServerName"].ToString();

                e.ServerUrl = jAuthenticationResponse["ServerUrl"].ToString();
                e.NickName = jAuthenticationResponse["NickName"].ToString();
                e.PhoneNo = jAuthenticationResponse["PhoneNo"].ToString();
                e.Email = jAuthenticationResponse["Email"].ToString();

                e.Status = jAuthenticationResponse["Status"].ToString();
                if (e.Status == "sucess")
                {
                    m_bStarted = true;
                }
                else
                {
                    m_bStarted = false;
                }
                //e.AppSettings = m_appsettings;
                On_AuthenticateUser(this, e);
            }
        }
        private void ProcessDisconectSuprtUserResponse(JObject DisconectResponse)
        {
            if (null != On_DisconnectSupportUser)
            {
                DisconnectSupportUserInfoEventArgs e = new DisconnectSupportUserInfoEventArgs();
                e.supportUserId = DisconectResponse["supportUserId"].ToString();
                e.ServerName = DisconectResponse["ServerName"].ToString();
                e.Status = DisconectResponse["Status"].ToString();
                m_bStarted = false;
                On_DisconnectSupportUser(this, e);
            }
        }

        private void ProcessDisconectNormalUserResponse(JObject DisconectResponse)
        {
            if (null != On_DisconnectNormalUser)
            {
                DisconnectSupportUserInfoEventArgs e = new DisconnectSupportUserInfoEventArgs();
                e.supportUserId = DisconectResponse["supportUserId"].ToString();
                e.ServerName = DisconectResponse["ServerName"].ToString();
                e.Status = DisconectResponse["Status"].ToString();
                m_bStarted = false;
                On_DisconnectNormalUser(this, e);
            }
        }

        private void ChatHistoryReceived(JObject chatHistory)
        {
            if (null == m_hub)
            {
                return;
            }

        }

        public override string ToString()
        {
            return m_appsettings.ToString();
        }

        public void SendChatEx(string strMessage, string strSenderEmailID, string strReceiverEmailID)
        {
            try
            {
                m_hub.Invoke(API_SET_SEND_CHAT_WITH_EMAIL, strMessage, strSenderEmailID, strReceiverEmailID);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
    }

    public class WebCloudHubConnection : HubConnection
    {
        public WebCloudHubConnection(string strUrl) : base(strUrl)
        { }
        protected override void OnMessageReceived(JToken message)
        {
            base.OnMessageReceived(message);

        }
        protected override void OnClosed()
        {
            base.OnClosed();
        }
        public override Task Send(string data)
        {
            return base.Send(data);
        }
        protected override string OnSending()
        {
            return base.OnSending();
        }
    }

    public class ContactInfo
    {
        public SignalRChatManager chatmanager { get; set; }
        public ChatNewContactEventArgs ContactDetails { get; set; }

        public List<ChatInfo> ListchatInfo { get; set; }

        public bool MuteChatWindow { get; set; }
        public ContactInfo()
        {
            ListchatInfo = new List<ChatInfo>();
            MuteChatWindow = false;
        }
    }
}
