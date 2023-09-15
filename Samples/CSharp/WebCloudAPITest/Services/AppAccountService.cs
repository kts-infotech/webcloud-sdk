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
		 public async Task<string> GenerateTempSiteAccessToken()
        {
            string Token = "";
            try
            {
                string Paramters = "api/Account/GenerateTempSiteAccessToken";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Token = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return Token;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<List<UserAccountInfo>> GetUserList()
        {
            List<UserAccountInfo> Info = new List<UserAccountInfo>();
            try
            {
                string Paramters = "api/Account/GetUserList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<UserAccountInfo>>(ResponseData.Result);

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

        public async Task<string> DeleteUser(string email)
        {
            string Response = string.Empty;
            
            try
            {
                string Paramters = "api/Account/DeleteUser?email=" + email;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    // Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    var responseMessage = responseValues["Desc"];
                    
                    return responseMessage;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
            
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<List<AdminAccInfo>> GetAdminList()
        {
            List<AdminAccInfo> Info = new List<AdminAccInfo>();
            try
            {
                string Paramters = "api/Account/GetAdminList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<AdminAccInfo>>(ResponseData.Result);

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
        public async Task<string> DeleteAdmin(string email)
        {
            

            try
            {
                string Paramters = "api/Account/DeleteAdmin?email=" + email;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    var responseMessage = responseValues["Desc"];

                    return responseMessage;

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
              
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }




        public async Task<string> AddUser(UserAccountInfo objAddUser)
        {
           
            try
            {
                var serializedItem = JsonConvert.SerializeObject(objAddUser);
                string Paramters = "api/Account/AddUser";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    var responseMessage = responseValues["Desc"];

                    return responseMessage;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
               
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }

        public async Task<string> AddAdmin(AdminAccInfo objAccInfo)
        {
           

            try
            {
                var serializedItem = JsonConvert.SerializeObject(objAccInfo);
                string Paramters = "api/Account/AddAdmin";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    var responseMessage = responseValues["Desc"];

                    return responseMessage;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }


        public async Task<string> InviteUser(UserInvitation objInvitation)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(objInvitation);
                string Paramters = "Api/Account/InviteUser";
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
                return Ex.ToString();
            }
        }


        public async Task<string> BlockORUnBlockUser(UserAccountInfo blockOrUnblockUser)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(blockOrUnblockUser);
                string Paramters = "api/Account/BlockORUnBlockUser";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    var responseMessage = responseValues["Desc"];

                    return responseMessage;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }

    }
}