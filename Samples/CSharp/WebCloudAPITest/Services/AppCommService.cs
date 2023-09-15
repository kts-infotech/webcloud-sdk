using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloud.Services
{
    public partial class AppApiService
    {

        public async Task <List<UserInfo>> GetAllActiveSiteUsersList()
        {
            List<UserInfo> Info = new List<UserInfo>();
            try
            {
                string Paramters = "Api/Comm/GetAllActiveSiteUsersList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<UserInfo>>(ResponseData.Result);

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

        public async Task <List<UserInfo>> GetAllOnlineUsersList()
        {
            List<UserInfo> Info = new List<UserInfo>();
            try
            {
                string Paramters = "Api/Comm/GetAllOnlineUsersList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<UserInfo>>(ResponseData.Result);

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


        public async Task<List<UserInfo>> GetAllOnlineNormalUsersList()
        {
            List<UserInfo> Info = new List<UserInfo>();
            try
            {
                string Paramters = "Api/Comm/GetAllOnlineNormalUsersList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<UserInfo>>(ResponseData.Result);

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



        public async Task<List<UserInfo>> GetAllOnlineSupportUsersList()
        {
            List<UserInfo> Info = new List<UserInfo>();
            try
            {
                string Paramters = "Api/Comm/GetAllOnlineSupportUsersList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<UserInfo>>(ResponseData.Result);

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

        public async Task<List<UserInfo>> GetAllSiteAdminUsersList()
        {
            List<UserInfo> Info = new List<UserInfo>();
            try
            {
                string Paramters = "Api/Comm/GetAllSiteAdminUsersList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<UserInfo>>(ResponseData.Result);

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

        public async Task<WCResult> SendMail(MailInfo Info)
        {
            WCResult Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/Comm/SendMail";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<WCResult>(ResponseData.Result);

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



    }
}
