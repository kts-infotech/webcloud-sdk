using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {

        public async Task InvokeGetAssignedTaskListAPI(string removeThis)
        {
            try
            {
                string strUsername = ObjMainForm.GetUserID(); 
                List<TaskDetails> Info = await ObjMainForm.ApiService.GetAssignedBugList(strUsername);
                DtGetAssigTaskListForm fom = new DtGetAssigTaskListForm(Info);
                fom.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetBugTrackerTaskDetailsListAPI(string removeThis)
        {
            try
            {
                string strUsername = ObjMainForm.GetUserID();
                List<BugTaskDetails> Info = await ObjMainForm.ApiService.GetBugTrackerTaskDetailsList(strUsername);
                DtGetBugTrackerDetailList form = new DtGetBugTrackerDetailList(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public UserBugTaskDetailsResponse InvokeGetWebCloudUserTaskDetailsAPI()
        {
            UserBugTaskDetailsResponse Info = new UserBugTaskDetailsResponse();
            string strUsername= ObjMainForm.GetUserID();
            try
            {
                UserTaskDetailsForm form = new UserTaskDetailsForm(ObjMainForm);
                form.Show();
                
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            return Info;
        }

        public async Task InvokeGetAllBugListAPI()
        {

            try
            {
                List<BugTaskDetails> Info = await ObjMainForm.ApiService.GetAllBugListAPI();
                GetAllBugList form = new GetAllBugList(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokePostADefectAPI()
        {
            try
            {
                List<TopicDetails> Info = new List<TopicDetails>();
                List<TaskAssignedTo> assignedToInfo = new List<TaskAssignedTo>();
                Info = await ObjMainForm.ApiService.GetAllTopicsNameFromFormType("DT");
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

                assignedToInfo = await ObjMainForm.ApiService.GetAssignedToList("DT");

                ObjMainForm.SetResponseData(assignedToInfo);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

                PostADefectForm form = new PostADefectForm(Info, assignedToInfo, ObjMainForm);
                form.Show();
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
           
        }

    }
}