using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest.TTMenu
{
    public partial class UploadWorkLog : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        WorkDairyDataReq m_WorkDairy;
        public UploadWorkLog(WebCloudAPIForm obj)
        {
            InitializeComponent();
            combCompletion.SelectedIndex = 0;
            m_ObjMainForm = obj;
            m_WorkDairy = new WorkDairyDataReq();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnUpload_Click(object sender, EventArgs e)
        {
            InvikeUplaodWorklogAPI();
        }
        private WorkDairyData CaptureWorkActivity()
        {
            WorkDairyData WdData = new WorkDairyData();
            //Get the Work Details Memo
            WdData.MemoDetails = new WorkMemoDetails();

            WdData.MemoDetails.MemoTitle = textMemo.Text;
            WdData.MemoDetails.MemoDesc = textMemoDesc.Text;
            WdData.MemoDetails.CompletionPercentage = combCompletion.SelectedItem.ToString();

            //Get Active Window Details
            WdData.CurrentActiveAppDetails = new CurrentApplicationDetails();
            WdData.CurrentActiveAppDetails.ApplicationExeName = textAppExeName.Text;
            WdData.CurrentActiveAppDetails.ApplicationExeName = WdData.CurrentActiveAppDetails.ApplicationExeName.Remove(0, WdData.CurrentActiveAppDetails.ApplicationExeName.LastIndexOf('\\') + 1);

            string strTopWindowText = textAppWinTitle.Text;
            strTopWindowText = strTopWindowText.Replace("'", "''");
            WdData.CurrentActiveAppDetails.ApplicationWindowTitle = strTopWindowText;

            WdData.CurrentActiveAppDetails.ActiveAppScreenShot = GetActiveApplicationScreenshot();

            //Get the current Time
            WdData.CaptureTime = GetCurrentSynchronizedTime();
            lbCaptureTime.Text = "Capture Time : " + WdData.CaptureTime;
            WdData.IsUploaded = false;
            //If the Capture screen shot option is checked
            //the Captre the screen 640 X 480 
            //Capture the Screen Title, Exe, Time ,Image Name with Date Time 
            //Memo details (Title, Desc, Percentage Completion)
            WdData.UserName = m_ObjMainForm.ApiService.UserID;

            return WdData;

        }
        private DateTime GetCurrentSynchronizedTime()
        {
            //For Now just return the Current Time
            //Later Get the Time Zone and the Time From the Webcloud Server and send  the 
            //Current Time Accordingly
            return DateTime.Now;
        }
        private string GetActiveApplicationScreenshot()
        {
            string strBase64 = "";
            using (Bitmap bitmap = new Bitmap(Screen.AllScreens[0].Bounds.Width, Screen.AllScreens[0].Bounds.Height))
            {
                
                using (Graphics g = Graphics.FromImage(bitmap))
                {
                    g.CopyFromScreen(Point.Empty, Point.Empty, Screen.AllScreens[0].Bounds.Size);
                }
                //bitmap.
                strBase64 = ConvertImageToBase64String(ResizeImage(bitmap, new Size(640, 480)));

            }

            return strBase64;
        }

        public static Bitmap ResizeImage(Bitmap imgToResize, Size size)
        {
            try
            {
                Bitmap b = new Bitmap(size.Width, size.Height);
                using (Graphics g = Graphics.FromImage((Image)b))
                {
                    g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;
                    g.DrawImage(imgToResize, 0, 0, size.Width, size.Height);
                }
                return b;
            }
            catch (Exception)
            {
                return null;
            }
        }

        public string ConvertImageToBase64String(Bitmap bitmap)
        {
            try
            {
                MemoryStream objMemoryStream = new MemoryStream();
                bitmap.Save(objMemoryStream, System.Drawing.Imaging.ImageFormat.Jpeg);
                pictureBox.Image = Image.FromStream(objMemoryStream);
                byte[] byteImage = objMemoryStream.ToArray();
                objMemoryStream.Close();
                objMemoryStream.Dispose();
                return Convert.ToBase64String(byteImage);
            }
            catch (Exception Ex)
            {
                throw new Exception(Ex.Message);
            }
        }
        public async void InvikeUplaodWorklogAPI()
        {
            try
            {
                WorkDairyDataResp Info = await m_ObjMainForm.ApiService.UploadWorkDairy(m_ObjMainForm.ApiService.UserID, m_WorkDairy);
                m_ObjMainForm.SetResponseData(Info);
                m_ObjMainForm.SetRequestURL(m_ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                m_ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        private void btnScrnShot_Click(object sender, EventArgs e)
        {
            m_WorkDairy.WorkDairyData = CaptureWorkActivity();
            
        }
    }
}
