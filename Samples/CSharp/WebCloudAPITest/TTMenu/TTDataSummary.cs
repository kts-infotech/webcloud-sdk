using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WebCloudAPITest.TTMenu
{
    public partial class TTDataSummary : Form
    {
        public TTDataSummary(int iTodayHrs, int iThisWeekHrs, int iThisMonthHrs)
        {
            InitializeComponent();
            ShowTodayHours(iTodayHrs);
            ShowThisWeekHours(iThisWeekHrs);
            ShowThisMonthHours(iThisMonthHrs);
        }

        private void ShowTodayHours(int ihrs)
        {
            TimeSpan spWorkMin = TimeSpan.FromMinutes(ihrs*10);
            string strDay = string.Format("{0:00}:{1:00}", (int)spWorkMin.TotalHours, spWorkMin.Minutes);
            textTdyHrs.Text = strDay;
        }
        private void ShowThisWeekHours(int ihrs)
        {
            TimeSpan spWorkMin = TimeSpan.FromMinutes(ihrs*10);
            string strWeek = string.Format("{0:00}:{1:00}", (int)spWorkMin.TotalHours, spWorkMin.Minutes);
            textWekHrs.Text = strWeek;
        }
        private void ShowThisMonthHours(int ihrs)
        {
            TimeSpan spWorkMin = TimeSpan.FromMinutes(ihrs*10);
            string strMonth = string.Format("{0:00}:{1:00}", (int)spWorkMin.TotalHours, spWorkMin.Minutes);
            textMthHrs.Text = strMonth;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
