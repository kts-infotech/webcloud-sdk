using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using WebCloud.Api.DS;


namespace WebCloud.Services
{
    public partial class AppApiService
    {
        public async Task<List<EmployeeInfo>> GetAllEmployeeInfo()
        {
            List<EmployeeInfo> EmployeeList = new List<EmployeeInfo>();
            EmployeeInfo list = new EmployeeInfo();
            try
            {
                string Paramters = "api/HR/GetAllEmployeeDetails";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    EmployeeList = JsonConvert.DeserializeObject<List<EmployeeInfo>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return EmployeeList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<WCResult> FetchCategoryManager()
        {
           
            WCResult result = new WCResult();
            try
            {
                string Paramters = "api/HR/FetchCategoryManager";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<WCResult>(ResponseData.Result);

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
        public async Task<List<EmployeeType>> GetEmpoloyeeType()
        {
            List<EmployeeType> employeeType = new List<EmployeeType>();
            EmployeeType list = new EmployeeType();
            try
            {
                string Paramters = "api/HR/GetEmpoloyeeType";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    employeeType = JsonConvert.DeserializeObject<List<EmployeeType>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return employeeType;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> UploadNewEmployee(EmployeeInfo objEmpDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(objEmpDetails);
                string Paramters = "api/HR/UploadNewEmployeeDetails";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> UpadteEmployee(EmployeeInfo EmployeeInfo)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(EmployeeInfo);
                string Paramters = "api/HR/UpadteEmployee";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> DeleteEmployee(string EmployeeId)
        {
            string Response;

            try
            {
                string Paramters = "api/HR/DeleteEmployee?EmployeeId=" + EmployeeId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
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
        public async Task<string> InviteEmployee(EmployeeInviteInfo objInvitation)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(objInvitation);
                string Paramters = "api/HR/InviteEmployee";
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

        public async Task<EmplTypeCategory> FetchEmplTypeCategory()
        {
            EmplTypeCategory Response = new EmplTypeCategory();

            try
            {
                string Paramters = "api/HR/FetchEmplTypeCategory";
                var requestTask = await AppServiceClient.PostAsync(Paramters,null);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<EmplTypeCategory>(ResponseData.Result);

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

        public async Task<WCResult> SendHRMail(HRMailInfo Info)
        {
            WCResult Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "Api/HR/SendHRMail";
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

        public async Task<WCResult> PostLeaveRequest(LeaveRequestDetails leaverequestDetails)
        {
            WCResult Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(leaverequestDetails);
                string Paramters = "api/HR/PostALeaveRequest";
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

        public async Task<List<LeaveTypeDetails>> GetAllLeaveTypeNameFromFormType(string strFormType)
        {
            List<LeaveTypeDetails> Info = new List<LeaveTypeDetails>();
            try
            {
                string key = strFormType;
                string Paramters = "Api/DT/GetAllLeaveTypeNameFromFormType?strFormType=" + key;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<LeaveTypeDetails>>(ResponseData.Result);

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

        public async Task<List<LeaveRequestDetails>> GetAllLeaveApplicationsList()
        {
            List<LeaveRequestDetails> Info = new List<LeaveRequestDetails>();
            try
            {
                string Paramters = "Api/HR/GetAllLeaveApplicationsList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<LeaveRequestDetails>>(ResponseData.Result);

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

        public async Task<WCResult> PostLeaveStatus(LeaveReqStatus LeaveRequestStatus)
        {
            WCResult Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(LeaveRequestStatus);
                string Paramters = "api/HR/PostALeaveStatus";
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