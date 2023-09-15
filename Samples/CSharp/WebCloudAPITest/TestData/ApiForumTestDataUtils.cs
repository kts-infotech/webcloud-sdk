using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using WebCloud.Api.DS;
using WebCloudAPITest.ForumMenu;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        public async Task InvokeGetAllForumsAPI()
        {
            try
            {
                List<FormDetailsInfo> Info = await ObjMainForm.ApiService.GetAllForums();
                AllForms form = new AllForms(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetAllTopicsAPI()
        {
            try
            {
                List<Topics> Info = await ObjMainForm.ApiService.GetAllTopics();
                AllTopicsForm form = new AllTopicsForm(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

        }

        public async Task InvokeGetAllThreadsAPI()
        {
            try
            {
                List<ThreadDetailsInfo> Info = await ObjMainForm.ApiService.GetAllThreads();
                GetAllThread form = new GetAllThread(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

        }

        public async Task InvokeDeleteThreadAPI()
        {
            try
            {
                List<ThreadDetailsInfo> Info = await ObjMainForm.ApiService.GetAllThreads();
                DeleteThread form = new DeleteThread(Info, ObjMainForm);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeAddFormAPI()
        {
            try
            {
                List<FormDetailsInfo> Info = await ObjMainForm.ApiService.GetAllForums();
                AddForum form = new AddForum(ObjMainForm, Info);
                form.Show();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeAddSubFormAPI()
        {
            try
            {
                List<Topics> infoTopics = await ObjMainForm.ApiService.GetAllTopics();
                //ObjMainForm.SetResponseData(infoTopics);
                List<FormDetailsInfo> infoForum = await ObjMainForm.ApiService.GetAllForums();
                AddTopic form = new AddTopic(ObjMainForm, infoForum, infoTopics);
                form.Show();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeAddThreadAPI()
        {
           
            try
            {
                List<ItemInfo> Info = await ObjMainForm.ApiService.GetAllForumIdWithNames();
                AddThread form = new AddThread(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

        }
        public async Task InvokeDeleteCommentAPI()
        {
            try 
            {
                List<ItemInfo> Info = await ObjMainForm.ApiService.GetAllForumIdWithNames();
                DelComment form = new DelComment(ObjMainForm, Info);
                form.Show();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            
        }
        public async Task InvokeAddCommentAPI()
        {
            try
            {
                List<ItemInfo> Info = await ObjMainForm.ApiService.GetAllForumIdWithNames();
                AddComment form = new AddComment(ObjMainForm, Info);
                form.Show();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

        }
    }
}
