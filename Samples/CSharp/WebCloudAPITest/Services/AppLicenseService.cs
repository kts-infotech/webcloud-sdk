using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Http;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloud.Services
{
    public partial class AppApiService
    {

        public async Task<LicenseInfo> GetLicenseInfo(string strPdtSubscriptionId, string strUniqueRegistrationID)
        {
            LicenseInfo result = new LicenseInfo();

            try
            {
                string Paramters = string.Format("api/License/GetLicenseInfo?strPdtSubscriptionId={0}&&strUniqueRegistrationID={1}",
                                                    strPdtSubscriptionId, strUniqueRegistrationID);
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject <LicenseInfo> (ResponseData.Result) ;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<WebCloudLicenseRegistrationStatus> RegisterNewLicense(string strPdtSubscriptionId, string strUniqueRegistrationId,
                                                    string strCustomerName, string strCustomerEmailID)
        {
            WebCloudLicenseRegistrationStatus liceStat = new WebCloudLicenseRegistrationStatus();

            try
            {
                string Paramters = string.Format("api/License/RegisterNewLicense?strPdtSubscriptionId={0}&&" +
                                                    "strUniqueRegistrationID={1}" +
                                                    "&&strCustomerName={2}&&" +
                                                    "strCustomerEmailID={3}", strPdtSubscriptionId, strUniqueRegistrationId,
                                                     strCustomerName, strCustomerEmailID);
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    liceStat = JsonConvert.DeserializeObject<WebCloudLicenseRegistrationStatus>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return liceStat;
            }
            catch (Exception Ex)
            {
                return new WebCloudLicenseRegistrationStatus { Message = Ex.ToString(), Result = OperationResult.Failed };
            }
        }
        public async Task<string> RegisterNewLicense(NewUserRegInfo info)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(info);
                string Paramters = "api/License/RegisterNewLicense";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = ResponseData.Result;
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

        public async Task<string> RequestOneTimeReg(NewUserRegInfo info)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(info);
                string Paramters = "api/License/RequestOneTimeReg";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = ResponseData.Result;
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

        public async Task<string> RequestSubscription(NewUserRegInfo info)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(info);
                string Paramters = "api/License/RequestSubscription";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Response = ResponseData.Result;
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