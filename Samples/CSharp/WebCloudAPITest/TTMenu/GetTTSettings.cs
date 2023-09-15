using System;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.TTMenu
{
    public partial class GetTTSettings : Form
    {
        public GetTTSettings(TimeTrackerSettings info)
        {
            InitializeComponent();
            ShowTimeTrackerSettings(info);
        }

        private void ShowTimeTrackerSettings(TimeTrackerSettings info)
        {
            textTimeZone.Text = info.TimeZone;
            textTZCode.Text = info.TimeZoneCode;
            textCaptInterval.Text = info.ActivityCaptureInterval.ToString();
            textIdleTime.Text = info.IdleTimeDuration.ToString();
            textReslution.Text = info.ScreenCaptureResolution;
            checkScrnShot.Checked = info.CaptureScreenShots;
            checkTrackIdle.Checked = info.DoNotTrackIfIdle;

        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
