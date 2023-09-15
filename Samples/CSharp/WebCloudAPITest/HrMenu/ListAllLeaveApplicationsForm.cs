using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;


namespace WebCloudAPITest
{
    public partial class ListAllLeaveApplicationsForm : Form
    {
        public ListAllLeaveApplicationsForm(List<LeaveRequestDetails> leaveInfoList)
        {
            InitializeComponent();
            DisplaySelectedLeaveApplication(leaveInfoList);

        }    

        private void DisplaySelectedLeaveApplication(List<LeaveRequestDetails> info)
        {
            //Leave Application Details 
            int i = 1;
            foreach (LeaveRequestDetails item in info)
            {
                dataGridView1.Rows.Add(i,item.Username,
                    ConvertTicksToDateTime(item.FromDate),
                    ConvertTicksToDateTime(item.ToDate),
                    item.LeaveType,item.LeaveReason,item.LeaveRequestStatus,item.LeaveRequestRemarks);
                i++;
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private string ConvertTicksToDateTime(string strDateTime)
        {
            Int64 dateTime = Convert.ToInt64(strDateTime);
            DateTime dt = new DateTime(dateTime);
            return dt.ToString("MMMM dd, yyyy");
        }

    }
}
