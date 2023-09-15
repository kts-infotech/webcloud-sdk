using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;
using WstWebServiceImpl;

namespace WebCloudAPITest
{
    public partial class ApplyForLeaveForm : Form
    {
       
        private ApiTestDataUtil objTestDataUtil;      
        private string strFromDate;
        private string strTodate;
        private string strLeaveReason;

        private WebCloudAPIForm m_ObjMainForm;
        public ApplyForLeaveForm(ApiTestDataUtil obj, WebCloudAPIForm mainobj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
            m_ObjMainForm = mainobj;
        }


        private void datePickerLeaveFrom_ValueChanged(object sender, EventArgs e)
        {
            DateTime dt = datePickerLeaveFrom.Value;
            strFromDate = dt.Ticks.ToString();
        }

        private void datePickerLeaveTo_ValueChanged(object sender, EventArgs e)
        {
            DateTime dt = datePickerLeaveTo.Value;
            strTodate = dt.Ticks.ToString();
        }

        private void comboBoxLeaveType_SelectedIndexChanged(object sender, EventArgs e)
        {
            string strSelection = comboBoxLeaveType.SelectedItem.ToString();
            if(strSelection== "Other(Specify)")
            {
                textLeaveSubject.ReadOnly = false;
                textLeaveSubject.Clear();
            }
            else
            {

                textLeaveSubject.Text = strSelection;
                textLeaveSubject.ReadOnly = true;
            }
        }
        private void textBoxLeaveDescription_TextChanged(object sender, EventArgs e)
        {
            strLeaveReason = textBoxLeaveDescription.Text.ToString();
        }
       
        private async void btnRequestLeave_Click(object sender, EventArgs e)
        {         
            //LogCategoryy
            int dbValue = 23;
            LogCategory enumValue = (LogCategory)dbValue;
            string strTaskID = enumValue.ToString(); 
            //LogDate
            long ticks = ConvertDateTimeToTicks(DateTime.Now);
            //Status And Remarks          
            string status = "Not Yet Reviewed";
            string remarks = "Not Yet Reviewed";

            string userID = m_ObjMainForm.GetUserID();
            LeaveRequestDetails leaveRequestDetails = new LeaveRequestDetails();
            leaveRequestDetails.Username = userID;
            leaveRequestDetails.LogType = strTaskID;
            leaveRequestDetails.FromDate = strFromDate;
            leaveRequestDetails.ToDate = strTodate;
            leaveRequestDetails.LeaveType = textLeaveSubject.Text.Trim();
            leaveRequestDetails.LeaveReason = textBoxLeaveDescription.Text.Trim();
            leaveRequestDetails.LogDate = ticks.ToString();
            leaveRequestDetails.LeaveRequestStatus = status;
            leaveRequestDetails.LeaveRequestRemarks = remarks;
            try
            {
                WCResult result =await objTestDataUtil.MainForm.ApiService.PostLeaveRequest(leaveRequestDetails);
                if(result.Status)
                {
                    MessageBox.Show(result.Desc, "Success");
                }
                else
                {
                    MessageBox.Show(result.Desc, "Error");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        
        public static long ConvertDateTimeToTicks(DateTime dtInput)
        {
            long ticks = 0;
            ticks = dtInput.Ticks;
            return ticks;
        }
    }
}
