using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TTMenu;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        public async Task InvikeTimeTrackerSettingsAPI()
        {
            try
            {
                TimeTrackerSettings Info = await ObjMainForm.ApiService.GetTimeTrackerSettings();
                GetTTSettings form = new GetTTSettings(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        private WorkDairyData CaptureWorkActivity()
        {
            WorkDairyData WdData = new WorkDairyData();
            //Get the Work Details Memo
            WdData.MemoDetails = new WorkMemoDetails();

            WdData.MemoDetails.MemoTitle = "Memo Title" + DateTime.Now.Ticks.ToString();
            WdData.MemoDetails.MemoDesc = "Memo Desc" + DateTime.Now.Ticks.ToString();
            WdData.MemoDetails.CompletionPercentage = "60%";

            //Get Active Window Details
            WdData.CurrentActiveAppDetails = new CurrentApplicationDetails();
            WdData.CurrentActiveAppDetails.ApplicationExeName = "winword.exe";
            WdData.CurrentActiveAppDetails.ApplicationExeName = WdData.CurrentActiveAppDetails.ApplicationExeName.Remove(0, WdData.CurrentActiveAppDetails.ApplicationExeName.LastIndexOf('\\') + 1);

            string strTopWindowText = "Window Text" + DateTime.Now.Ticks.ToString();
            strTopWindowText = strTopWindowText.Replace("'", "''");
            WdData.CurrentActiveAppDetails.ApplicationWindowTitle = strTopWindowText;

            WdData.CurrentActiveAppDetails.ActiveAppScreenShot = GetActiveApplicationScreenshot();

            //Get the current Time
            WdData.CaptureTime = GetCurrentSynchronizedTime();
            WdData.IsUploaded = false;
            //If the Capture screen shot option is checked
            //the Captre the screen 640 X 480 
            //Capture the Screen Title, Exe, Time ,Image Name with Date Time 
            //Memo details (Title, Desc, Percentage Completion)
            WdData.UserName = ObjMainForm.ApiService.UserID;

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
        public void  InvikeUplaodWorklogAPI()
        {
            UploadWorkLog form = new UploadWorkLog(ObjMainForm);
            form.Show();
        }
        public async Task InvikeDataSummarayInfoAPI()
        {
            int iTodayHrs = 0;
            int iThisWeekHrs = 0;
            int iThisMonthHrs = 0;
            int iThrdSleepDelay = 100;
            try
            {
                TimeTrackerSummaryResponse Response = new TimeTrackerSummaryResponse();

                TimeTrackerSummaryInfo DailySummaryInfo = new TimeTrackerSummaryInfo();
                DailySummaryInfo.TrackSummaryType = "TODAY";
                DailySummaryInfo.DateTicks = DateTime.Now.Ticks;

                ObjMainForm.SetRequestData(DailySummaryInfo);
                Response = await ObjMainForm.ApiService.TTDataSummaryInfo(ObjMainForm.ApiService.UserID, DailySummaryInfo);
                iTodayHrs = GetTotalHoursInInteger(Response.NoOfHoursWorked,Response.NoOfOfflineHoursWorked);

                ObjMainForm.SetResponseData(Response);
                ObjMainForm.SetRequestURL("Todays Summary| "+ObjMainForm.ApiService.SubmitURL);

                System.Threading.Thread.Sleep(iThrdSleepDelay);

                TimeTrackerSummaryInfo WeeklySummaryInfo = new TimeTrackerSummaryInfo();
                WeeklySummaryInfo.TrackSummaryType = "THIS_WEEK";
                WeeklySummaryInfo.DateTicks = DateTime.Now.Ticks;
                ObjMainForm.SetRequestData(WeeklySummaryInfo);
                Response = await ObjMainForm.ApiService.TTDataSummaryInfo(ObjMainForm.ApiService.UserID, WeeklySummaryInfo);
                iThisWeekHrs = GetTotalHoursInInteger(Response.NoOfHoursWorked, Response.NoOfOfflineHoursWorked);

                ObjMainForm.SetResponseData(Response);

               ObjMainForm.SetRequestURL("Weekly Summary| " + ObjMainForm.ApiService.SubmitURL);

                System.Threading.Thread.Sleep(iThrdSleepDelay);

                TimeTrackerSummaryInfo MonthlySummaryInfo = new TimeTrackerSummaryInfo();
                MonthlySummaryInfo.TrackSummaryType = "THIS_MONTH";
                MonthlySummaryInfo.DateTicks = DateTime.Now.Ticks;
                ObjMainForm.SetRequestData(MonthlySummaryInfo);

                Response = await ObjMainForm.ApiService.TTDataSummaryInfo(ObjMainForm.ApiService.UserID, MonthlySummaryInfo);
                iThisMonthHrs = GetTotalHoursInInteger(Response.NoOfHoursWorked, Response.NoOfOfflineHoursWorked);
                ObjMainForm.SetResponseData(Response);
                ObjMainForm.SetRequestURL("Montly Summary| " + ObjMainForm.ApiService.SubmitURL);
                TTDataSummary form = new TTDataSummary(iTodayHrs, iThisWeekHrs, iThisMonthHrs);
                form.Show();

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

        }

        private int GetTotalHoursInInteger(string strOnline, string strOffline)
        {
            int iOnline = (strOnline == "") ? 0 : Convert.ToInt32(strOnline);
            int iOffline = (strOffline == "") ? 0 : Convert.ToInt32(strOffline);
            return iOnline + iOffline;
        }
    }
}
