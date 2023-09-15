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
using ProjectFrameworkAPITest;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class UserTaskDetailsForm : Form
    {
        List<BugTaskDetails> BugTaskDetailsList;
        private WebCloudAPIForm ObjMainForm;
        public UserTaskDetailsForm(WebCloudAPIForm obj)
        {
            InitializeComponent();
            ObjMainForm = obj;
        }

        private async void buttonGetInfo_Click_1(object sender, EventArgs e)
        {
            UserBugTaskDetailsResponse Info;
            try
            {
                Info = await ObjMainForm.ApiService.GetWebCloudUserTaskDetails(textBoxUserName.Text);
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception ex)
            {
                ObjMainForm.SetResponseData(ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                MessageBox.Show(ex.Message, "Error");
                return;
            }
            
            bool Success = Info.Success;
            string strBugErrorReason = Info.ErrorReason;
            WebCloudUserInfo UserInfo = Info.UserInfo;

            bool IsAdmin = UserInfo.IsAdmin;
            lbUserType.Text = IsAdmin? "Admin User" : "Normal User";
            string UserGroup = UserInfo.UserGroup;
            lbUserGroup.Text = UserGroup==null ? "No Groups Found" : UserGroup;

            BugTaskDetailsList = Info.BugTaskDetailsList;
            comboTaskList.Items.Clear();
            foreach (BugTaskDetails BugTaskDetail in BugTaskDetailsList)
            {
                comboTaskList.Items.Add(BugTaskDetail.BugTaskTitle);
            }

            ObjMainForm.SetResponseData(Info);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);


        }

        private void comboTaskList_SelectedIndexChanged(object sender, EventArgs e)
        {
            foreach (BugTaskDetails BugTaskDetail in BugTaskDetailsList)
            {
                string selectedItem = comboTaskList.SelectedItem.ToString();
                if(selectedItem == BugTaskDetail.BugTaskTitle)
                {
                    lbBugStatus.Text = BugTaskDetail.BugStatus;
                    webBugDesc.DocumentText = BugTaskDetail.BugTaskDescription;
                }
            }


        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
