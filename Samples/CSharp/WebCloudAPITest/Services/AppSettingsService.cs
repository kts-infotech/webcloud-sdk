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
        public async Task<WCAppSettings> GetSettingsInfo()
        {
            WCAppSettings Settings = new WCAppSettings();
            try
            {

                var requestTask = await AppServiceClient.GetAsync("api/Settings/GetSettingsInfo");
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Settings = JsonConvert.DeserializeObject<WCAppSettings>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Settings;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<bool> UpdateSettingsInfo(WCAppSettings Settings)
        {
            bool bResult = false;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(Settings);
                string Paramters = "api/Settings/UpdateSettingsInfo";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    bResult = true;

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return bResult;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
    }
}
