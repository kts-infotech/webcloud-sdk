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

namespace WebCloudAPITest
{
   
    public partial class ApproveOrRejectLeaveForm : Form
    {
        List<LeaveRequestDetails> m_LeaveInfoList;
        
        private string strLeaveRemarks;
        
        private WebCloudAPIForm m_ObjMainForm;
        public string m_strSelectedItem;
        public ApproveOrRejectLeaveForm(List<LeaveRequestDetails> leaveInfoList, WebCloudAPIForm objMainForm)
        {
            InitializeComponent();
            m_ObjMainForm = objMainForm;
            m_LeaveInfoList = leaveInfoList;
            foreach (LeaveRequestDetails LeaveRequestDetails in leaveInfoList)
            {
                comboBoxLeaveRequestList.Items.Add(new ItemInfo { Text= LeaveRequestDetails.Username,Value= LeaveRequestDetails.LogID});
            }
        }

        private void comboBoxLeaveRequestList_SelectedIndexChanged(object sender, EventArgs e)
        {
            // strLeaveRequestList = comboBoxLeaveRequestList.SelectedItem.ToString();
            m_strSelectedItem = (comboBoxLeaveRequestList.SelectedItem as ItemInfo).Value.ToString();
            LeaveRequestDetails postLeaveRequest = m_LeaveInfoList.Find(item => item.LogID == m_strSelectedItem);
            DisplaySelectedLeaveApplication(postLeaveRequest);
        }

        private void DisplaySelectedLeaveApplication(LeaveRequestDetails Selectedleavedetails)
        {
            labelFromDate.Text = ConvertTicksToDateTime(Selectedleavedetails.FromDate);
            labelToDate.Text = ConvertTicksToDateTime(Selectedleavedetails.ToDate);
            labelTypeOfLeave.Text = Selectedleavedetails.LeaveType;          
            labelLeaveDescription.Text = Selectedleavedetails.LeaveReason;
            //HR review Status Of each Applications
            labelLeaveStatus.Text = Selectedleavedetails.LeaveRequestStatus;
            textBoxRemarks.Text = Selectedleavedetails.LeaveRequestRemarks;
        }

        private void textBoxRemarks_TextChanged(object sender, EventArgs e)
        {
            strLeaveRemarks = textBoxRemarks.Text.ToString();
        }

        private async void btnApproveLeave_Click(object sender, EventArgs e)
        {
            
            String status = "Approved";
            LeaveReqStatus leaveRequestStatus = new LeaveReqStatus();         
            leaveRequestStatus.LogID = m_strSelectedItem;
            leaveRequestStatus.LeaveRequestStatus = status;
            leaveRequestStatus.LeaveRequestRemarks = strLeaveRemarks;
            try
            {
                WCResult result = await m_ObjMainForm.ApiService.PostLeaveStatus(leaveRequestStatus);
                if (result.Status)
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
        private async void btnRejectLeave_Click(object sender, EventArgs e)
        {
            String status = "Rejected";
            LeaveReqStatus leaveRequestStatus = new LeaveReqStatus();
            leaveRequestStatus.LogID = m_strSelectedItem;
            leaveRequestStatus.LeaveRequestStatus = status;
            leaveRequestStatus.LeaveRequestRemarks = strLeaveRemarks;
            try
            {
                WCResult result = await m_ObjMainForm.ApiService.PostLeaveStatus(leaveRequestStatus);
                if (result.Status)
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
