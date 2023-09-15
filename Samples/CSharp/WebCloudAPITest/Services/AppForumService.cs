using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;


namespace WebCloud.Services
{
    public partial class AppApiService
    {
        public async Task<List<FormDetailsInfo>> GetAllForums() //GetAllForumIdWithNames
        {
            List<FormDetailsInfo> Info = null;
            try
            {
                string Paramters = "Api/Forum/GetAllForums";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<FormDetailsInfo>>(ResponseData.Result);

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

        public async Task<List<ItemInfo>> GetAllForumIdWithNames()
        {
            List<ItemInfo> Info = null;
            try
            {
                string Paramters = "Api/Forum/GetAllForumIdWithNames";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<ItemInfo>>(ResponseData.Result);

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
        public async Task<List<ItemInfo>> GetAllTopicsWithForumID(string iForumId)
        {
            List<ItemInfo> Info = null;
            try
            {
                string Paramters = "Api/Forum/GetAllTopicsWithForumID?iForumId=" + iForumId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<ItemInfo>>(ResponseData.Result);

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
        public async Task<List<ItemInfo>> GetAllThreadsWithTopicID(string strTopicID)
        {
            List<ItemInfo> Info = null;
            try
            {
                string Paramters = "Api/Forum/GetAllThreadsWithTopicID?strTopicID=" + strTopicID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<ItemInfo>>(ResponseData.Result);

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
        public async Task<List<Topics>> GetAllTopics()
        {
            List<Topics> Info = null;
            try
            {
                string Paramters = "Api/Forum/GetAllTopics";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<Topics>>(ResponseData.Result);
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
        public async Task<List<ThreadDetailsInfo>> GetAllThreads()
        {
            List<ThreadDetailsInfo> Info = null;
            try
            {
                string Paramters = "Api/Forum/GetAllThreads";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<ThreadDetailsInfo>>(ResponseData.Result);
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
        public async Task<string> DeleteThread(string strThreadID)
        {
            string Info = "";
            try
            {
                string Paramters = "Api/Forum/DeleteThread?strThreadID=" + strThreadID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> DeleteForum(string strForumID)
        {
            string Info = "";
            try
            {
                string Paramters = "Api/Forum/DeleteForum?strForumID=" + strForumID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> DeleteTopic(string strTopicID)
        {
            string Info = "";
            try
            {
                string Paramters = "Api/Forum/DeleteTopic?strTopicID=" + strTopicID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> AddForum(FormDetailsInfo Info)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/Forum/AddForum";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> UpdateForum(FormDetailsInfo Info)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/Forum/UpdateForum";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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

        public async Task<List<UserCategotyInfo>> GetExistingGroups()
        {
            List<UserCategotyInfo> Info;
            try
            {
                string Paramters = "Api/Forum/GetExistingGroups";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<UserCategotyInfo>>(ResponseData.Result);
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
        public async Task<string> RetrieveEmail(string strGroupId)
        {
            string Info = "";
            try
            {
                string Paramters = "Api/Forum/RetrieveEmail?strGroupId=" + strGroupId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> AddTopics(Topics Info)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/Forum/AddTopics";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> UpdateTopic(Topics Info)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/Forum/UpdateTopic";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> AddThread(ThreadDetailsInfo trd)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(trd);
                string Paramters = "Api/Forum/AddThread";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> UpdateThread(ThreadDetailsInfo trd)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(trd);
                string Paramters = "Api/Forum/UpdateThread";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<ThreadDetailsInfo> GetThreadByID(string strThreadID)
        {
            ThreadDetailsInfo Response;

            try
            {
                string Paramters = "Api/Forum/GetThreadByID?strThreadID=" + strThreadID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<ThreadDetailsInfo>(ResponseData.Result);

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
        public async Task<List<CommentsInfo>> GetMsgsByTrdID(string strThreadID)
        {
            List<CommentsInfo> Response;

            try
            {
                string Paramters = "Api/Forum/GetMsgsByTrdID?strThreadID=" + strThreadID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<List<CommentsInfo>>(ResponseData.Result);

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
        public async Task<List<string>> DeleteComments(List<string> strMsgID)
        {
            List<string> Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(strMsgID);
                string Paramters = "Api/Forum/DeleteComments";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<List<string>>(ResponseData.Result);
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
        public async Task<string> AddComments(CommentsInfo Info)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/Forum/AddComments";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> ForceDeleteForum(string strForumId)
        {
            string Info = "";
            try
            {
                string Paramters = "Api/Forum/ForceDeleteForum?strForumId=" + strForumId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> ForceDeleteTopic(string strTopicId)
        {
            string Info = "";
            try
            {
                string Paramters = "Api/Forum/ForceDeleteTopic?strTopicId=" + strTopicId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
