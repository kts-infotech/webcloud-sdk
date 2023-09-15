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
        public async Task<TimeTrackerSettings> GetTimeTrackerSettings()
        {
            TimeTrackerSettings Info = new TimeTrackerSettings();
            try
            {
                string Paramters = "api/TT/GetTimeTrackerSettings";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<TimeTrackerSettings>(ResponseData.Result);

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

        public async Task<WorkDairyDataResp> UploadWorkDairy(string UserID, WorkDairyDataReq WorkDairyData)
        {
            WorkDairyDataResp Response = new WorkDairyDataResp(); ;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(WorkDairyData);
                string Paramters = "api/TT/UploadWorkDairy?UserID="+ UserID;
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<WorkDairyDataResp>(ResponseData.Result);

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

        public async Task<TimeTrackerSummaryResponse> TTDataSummaryInfo(string UserID, TimeTrackerSummaryInfo SummaryInfo)
        {
            TimeTrackerSummaryResponse Response = new TimeTrackerSummaryResponse();

            try
            {
                var serializedItem = JsonConvert.SerializeObject(SummaryInfo);
                string Paramters = "api/TT/TTDataSummaryInfo?UserID=" + UserID;
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<TimeTrackerSummaryResponse>(ResponseData.Result);

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
