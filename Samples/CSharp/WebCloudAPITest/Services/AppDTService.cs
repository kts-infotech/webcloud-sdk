using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloud.Services
{
    public partial class AppApiService
    {
        public async Task <List<TaskDetails>> GetAssignedBugList(string strUsername)
        {
           List <TaskDetails> Info =null;
            try
            {
                string key = strUsername;
                string Paramters = "Api/DT/GetAssignedBugList?strUserName=" + key;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<TaskDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<List<BugTaskDetails>> GetBugTrackerTaskDetailsList(string strUsername)
        {
            List<BugTaskDetails> Info = null;
            try
            {
                string key = strUsername;
                string Paramters = "Api/DT/GetBugTrackerTaskDetailsList?strUserName=" + key;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<BugTaskDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<UserBugTaskDetailsResponse> GetWebCloudUserTaskDetails(string strUsername)
        {
            UserBugTaskDetailsResponse Info = new UserBugTaskDetailsResponse();
            try
            {
                string key = strUsername;
                string Paramters = "Api/DT/GetWebCloudUserTaskDetails?strUserName=" + key;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<UserBugTaskDetailsResponse>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<List<BugTaskDetails>> GetAllBugListAPI()
        {
            List<BugTaskDetails> Info = new List<BugTaskDetails>();
            try
            {
               // string key = strUsername;
                string Paramters = "Api/DT/GetAllBugDetailsList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<BugTaskDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<bool> PostADefect(DefectDetails deffectDetails)
        {
            bool Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(deffectDetails);
                string Paramters = "api/DT/PostADefect";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<bool>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task <List<TopicDetails>> GetAllTopicsNameFromFormType(string strFormType)
        {
            List<TopicDetails> Info = new List<TopicDetails>();
            try
            {
                string key = strFormType;
                string Paramters = "Api/DT/GetAllTopicsNameFromFormType?strFormType=" + key;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<TopicDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<List<TaskAssignedTo>> GetAssignedToList(string strFormType)
        {
            List<TaskAssignedTo> Info = new List<TaskAssignedTo>();
            try
            {
                string key = strFormType;
                string Paramters = "Api/DT/GetAssignedToList?strFormType=" + key;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<TaskAssignedTo>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

    }
}