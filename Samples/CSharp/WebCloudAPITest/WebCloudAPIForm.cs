
using Newtonsoft.Json;
using System;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloud.Services;
using WebCloudAPITest;
using WebCloudAPITest.TestData;

namespace ProjectFrameworkAPITest
{
    public partial class WebCloudAPIForm : Form
    {
        public AppApiService ApiService = null;
        AuthInfo AuthInfo;
        private ApiTestDataUtil objTestDataUtil;
        public WebCloudAPIForm()
        {
            InitializeComponent();
            AuthInfo = new AuthInfo();
            objTestDataUtil = new ApiTestDataUtil(this);
            LoadDefaultValues();
        }
        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        public void SetResponseData(string Response)
        {
            textBoxResponseData.Text = Response;
        }
        public void SetResponseData(Object Response)
        {
            textBoxResponseData.Text = JsonConvert.SerializeObject(Response);
        }
        public void SetRequestData(string Response)
        {
            textBoxRequestData.Text = Response;
        }
        public void SetRequestData(Object Response)
        {
            textBoxRequestData.Text = JsonConvert.SerializeObject(Response);
        }
        public void SetRequestURL(string strRequestURL)
        {
            toolStripStatusLabelRequestURL.Text = strRequestURL;
        }
        public void SetStatusText(string status)
        {
            toolStripStatusLabelRequestURL.Text = status;
        }
        public string GetLoginButtonText()
        {
            return buttonLogin.Text;
        }
        public void SetLoginButtonText(string strName)
        {
            buttonLogin.Text = strName;
        }
        private async void buttonLogin_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvikeLoginValidationAPI();
        }
        public void SetAutheticationToken(string Token)
        {
            labelAuthTokenValue.Text = Token;
        }
        public string GetMainURL()
        {
            return textBoxURL.Text;
        }
        public string GetUserID()
        {
            return textBoxUserID.Text;
        }
        public string GetPassword()
        {
            return textBoxPassword.Text;
        }
        private async void getTimeTrackerSettingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvikeTimeTrackerSettingsAPI();
        }
        public void SaveDefaultValues()
        {
            try
            {
                Microsoft.Win32.RegistryKey ApiRegistryKey = Microsoft.Win32.Registry.CurrentUser.CreateSubKey("WebClpudApiTest");
                ApiRegistryKey.SetValue("URL", textBoxURL.Text);
                ApiRegistryKey.SetValue("UserID", textBoxUserID.Text);
                ApiRegistryKey.SetValue("Password", textBoxPassword.Text);
                ApiRegistryKey.Close();
            }
            catch (Exception Ex)
            {
                SetResponseData(Ex.Message);
            }
        }
        public void LoadDefaultValues()
        {
            try
            {
                Microsoft.Win32.RegistryKey ApiRegistryKey = Microsoft.Win32.Registry.CurrentUser.OpenSubKey("WebClpudApiTest");
                if (ApiRegistryKey != null)
                {
                    textBoxURL.Text = ApiRegistryKey.GetValue("URL").ToString();
                    textBoxUserID.Text = ApiRegistryKey.GetValue("UserID").ToString();
                    textBoxPassword.Text = ApiRegistryKey.GetValue("Password").ToString();
                }
            }
            catch (Exception Ex)
            {
                SetResponseData(Ex.Message);
            }
        }
        private void uploadWorklogToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvikeUplaodWorklogAPI();
        }
        private async void tTDataSummaryInfoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvikeDataSummarayInfoAPI();
        }
        private async void listAllPageInfoWithLinksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllPageInfoAPI();
        }
        private async void getDetailedPageInfoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetDetailedPageInfoAPI();
        }
        private async void getSEOInfoOfPageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetSEOInfoOfPageAPI();
        }
        private async void setSEOInfoOfPageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeSetSEOInfoOfPageAPI();
        }
        private async void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllInternalLinksAPI();
        }
        private async void getAllExternalLinksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllExternalLinksAPI();
        }
        private async void addInternalLinkToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddInternalLinkAPI();
        }
        private async void addExternalLinkToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddExternalLinkAPI();
        }
        private async void getFooterInfoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetFooterInfoAPI();
        }
        private void upadteFooterInfoToolStripMenuItem_Click(object sender, EventArgs e)
        {

            //UpdateFooterInfoForm form = new UpdateFooterInfoForm(objTestDataUtil);
            //form.Show();
        }
        private void addHeaderLinkToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //int iValue = 3;
            //await objTestDataUtil.InvokeGetDetailedPageInfoAPI(objTestDataUtil, iValue);

        }
        private void addFooterLinkToolStripMenuItem_Click(object sender, EventArgs e)
        {

            //int iValue = 4;
            //await objTestDataUtil.InvokeGetDetailedPageInfoAPI(objTestDataUtil, iValue);

        }
        private async void userListToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeUserListAPI();
        }
        private void accountAPIToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeAddUserAccountAPI();

        }
        private void inviteUserToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new InviteUser(objTestDataUtil).ShowDialog();
        }
        private async void deleteUserToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetUserListForDeletionAPI(objTestDataUtil);
        }
        private async void blockUserToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeBlockUserAPI();
        }
        private void addAdminToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new AddAdmin(objTestDataUtil).ShowDialog();
        }
        private async void deleteAdminToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAdminListForDeletionAPI(objTestDataUtil);
        }
        private async void getAllUsersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllActiveSiteUsersListAPI();
        }
        private async void getAllAdminUsersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllSiteAdminUsersListAPI();
        }
        private async void getAllOnlineUsersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllOnlineUsersListAPI();
        }
        private async void getAllOnlineNormalUsersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllOnlineNormalUsersListAPI();
        }
        private async void getAllOnlineSupportUsersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllOnlineSupportUsersListAPI();
        }
        private void sendEMailToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeSendEmailAPI();
        }
        private void launchTextChatDemoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeLaunchTextChatDemoAPI();
        }
        private void launchVoiceChatDemoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeLaunchVoiceChatDemoAPI();
        }
        private async void getAssignedTaskListToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAssignedTaskListAPI(textBoxUserID.Text);
        }
        private async void getBugTrackerTaskDetailsListToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetBugTrackerTaskDetailsListAPI(textBoxUserID.Text);
        }
        private void getUserTaskInfoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeGetWebCloudUserTaskDetailsAPI();
        }
        private async void getAllBugListToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllBugListAPI();
        }
        private async void listAllCompaniesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeListAllCompaniesAPI();
        }
        private async void listAllCompanyProductsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeListAllCompanyProductsAPI();
        }
        private async void getAllForumsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllForumsAPI();
        }
        private async void getAllTopicsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllTopicsAPI();
        }
        private async void getAllThreadsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllThreadsAPI();
        }
        private async void deleteAThreadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeDeleteThreadAPI();
        }       
        //private void addEmployeeToolStripMenuItem1_Click(object sender, EventArgs e)
        //{
        //    AddEmployee add = new AddEmployee(objTestDataUtil);
        //    add.Show();
        //}
        private async void inviteEmployeeToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeInviteEmployeeAPI();
        }
        private async void getAllProjectsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllProjectsAPI();
        }
        private async void getAllTasksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllTasksAPI(textBoxUserID.Text);
        }
        //private async void addAProjectToolStripMenuItem_Click(object sender, EventArgs e)
        //{

        //}
        //private async void updateAProjectToolStripMenuItem_Click(object sender, EventArgs e)
        //{

        //    await objTestDataUtil.InvokeUpdateProjectAPI(objTestDataUtil);
        //}
        //private async void deleteAProjectToolStripMenuItem_Click(object sender, EventArgs e)
        //{

        //}
       
        private void uploadFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeUploadFileAPI();
        }
        private void downloadFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeDownloadFileAPI();
        }
        private void listFilesInDirectoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeListFilesAndDirectoryAPI();
        }
        private void CRUDAFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeCRUDFileDirectoryAPI();
        }
        private async void generateTempSiteAccessTokenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGenerateTempSiteAccessTokenAPI();
        }
        private async void postADefectBugToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokePostADefectAPI();
        }
        private async void listAllExamCategoriesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeExamCategoriesListAPI();
        }
        private async void listAllExamSubCategoriesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeExamSubCategoriesListAPI();
        }
        private void addExamCategoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeAddExamMainAPI();
        }
        private async void addExamSubCategoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeListAllExamSubCategoriesAPI();
        }
        private async void listAllQuestionToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //await objTestDataUtil.InvokeListAllQuestionsAPI();
          await objTestDataUtil.InvokeExamQuestionPaperCategoryListAPI();
            
        }
        private async void addEditDeleteQuestionsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeEditDeleteQuestionsAPI();
        }
        private async void upadateExamDefaultSettingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllExamSettingsAPI();

        }
        private async void informHRManagerAsEMailToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeHrManagerAsEmailAPI();
        }
        private void applyForLeaveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeLeaveForm();
        }
        private async void listAllLeaveApplicationsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeListAllLeaveApplicationsAPI();
        }
        private async void approveRejectLeaveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeApproveRejectLeaveAPI();
        }
        private void registerLicenseUserToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeRegisterLicenceUserAPI();
        }
        private void getLicenseInfoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeGetLicenceInfoAPI();
        }
        private void validateLicenseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeValidateLicenseAPI();
        }
        private async void addForumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddFormAPI();
        }
        private async void addSubForumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddSubFormAPI();
        }
        private async void addThreadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddThreadAPI();
        }
        private async void deleteACommentToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeDeleteCommentAPI();
        }
        private async void addACommentToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddCommentAPI();
        }
        private async void CompanyDetailsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeCompanyAPI();
        }
        private async void CompanyProductDetails_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeCompanyProductAPI();
        }
        private async void PaymentGatewaySettingsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokePaymentGatewaySettingsAPI();
        }

        private async void addACommentToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAddCommentAPI();
        }

        private async void EmployeeDetailsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeEmployeeAPI();
        }

        private async void addDeleteHeaderToolStripMenuItem_ClickAsync(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllHeadersAPI();
        }

        private async void addDeleteFooterToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeGetAllFootersAPI();
        }

        private async void ProjectsToolStripMenuItem_Click(object sender, EventArgs e)
        {            
            await objTestDataUtil.InvokeProjectAPI(textBoxUserID.Text);
        }

        private async void TaskToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeTaskAPI();
        }

        private async void SubTaskToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeSubTaskAPI();
        }

        private async void assignTasksToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeAssignTaskAPI();
        }


        private async void copyQuestionsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            await objTestDataUtil.InvokeCopyQuestionAPI();
        }

        private void ImportDatatoolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeImportQuestionAPI();

        }



        private void downloadAppDataDownloadAppFileDataToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeApplicationDataDownloadForm();
        }

        private void uploadApplicationDataToolStripMenuItem_Click(object sender, EventArgs e)
        {
            objTestDataUtil.InvokeApplicationDataUploadForm();
        }

    }
}
