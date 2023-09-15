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
        /// <summary>
        /// 
        /// </summary>
        /// <param name="examMainCategory"></param>
        /// <returns></returns>
        public async Task<string> AddExamMainCategory(ExamMainCategory examMainCategory)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(examMainCategory);
                string Paramters = "api/Exam/AddExamMainCategory";
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

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<List<object>> GetExamInfoList()
        {
            List<object> Info = new List<object>();
            try
            {
                string Paramters = "api/Exam/GetExamInfoList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<object>>(ResponseData.Result);

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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examSubCategory"></param>
        /// <returns></returns>
        public async Task<string> AddExamSubCategory(ExamSubCategory examSubCategory)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(examSubCategory);
                string Paramters = "api/Exam/AddExamSubCategory";
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

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<string> GetAllQuestions(string categoryId)
        {
            string Response = string.Empty;

            try
            {
                string Paramters = "api/Exam/GetAllQuestions?categoryId=" + categoryId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                     Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    //var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    //var responseMessage = responseValues["Desc"];

                    return Response;
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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examDefaultSettings"></param>
        /// <returns></returns>
        public async Task<string> UpdateExamSettings(ExamDefaultSettings examDefault)
        {
            List<ExamDefaultSettings> Info = new List<ExamDefaultSettings>();
            try
            {
                var serializedItem = JsonConvert.SerializeObject(examDefault);
                string Paramters = "api/Exam/UpdateExamSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
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
                return Ex.ToString();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<List<ExamDefaultSettings>> GetAllExamSettings()
        {
            List<ExamDefaultSettings> Info = new List<ExamDefaultSettings>();
            try
            {
                string Paramters = "api/Exam/GetAllExamSettings";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<ExamDefaultSettings>>(ResponseData.Result);

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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="categoryId"></param>
        /// <returns></returns>
        public async Task<string> DeleteQuestion(int categoryId, int Qid)
        {
            string Response = string.Empty;

            try
            {
                string Paramters = "api/Exam/DeleteQuestion?categoryId=" + categoryId + "&&Qid=" + Qid;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    // Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    Response = responseValues["Desc"];


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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examQuestionMaster"></param>
        /// <returns></returns>
        public async Task<string> AddQuestion(ExamQuestionMaster examQuestionMaster)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(examQuestionMaster);
                string Paramters = "api/Exam/AddQuestions";
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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examQuestionMaster"></param>
        /// <returns></returns>
        public async Task<string> UpdateQuestion(ExamQuestionMaster examQuestionMaster)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(examQuestionMaster);
                string Paramters = "api/Exam/UpdateQuestions";
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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sourceCategoryID"></param>
        /// <param name="destinationCategoryID"></param>
        /// <returns></returns>
        public async Task<string> CopyAllQuestions(int sourceCategoryID, int destinationCategoryID)
        {
            string Response = string.Empty;
            try
            {
                string Paramters = "api/Exam/CopyAllQuestions?sourceCategoryID=" + sourceCategoryID + "&&destinationCategoryID=" + destinationCategoryID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    // Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    var responseValues = JsonConvert.DeserializeObject<Dictionary<string, string>>(ResponseData.Result);
                    Response = responseValues["Desc"];


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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="lstQuestionId"></param>
        /// <param name="destinationCategoryID"></param>
        /// <returns></returns>
        public async Task<string> CopySelectedQuestions(List<ExamQuestionMaster> lstQuestionId, int destinationCategoryID)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(lstQuestionId);
                string Paramters = "api/Exam/CopySelectedQuestions?destinationCategoryID=" + destinationCategoryID + "";
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

       
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<List<object>> GetWSData(string strUserName, string strPassword,string url)
        {
            List<object> Info = new List<object>();
            try
            {
                string Paramters = "api/Exam/GetWSData?strUserName=" + strUserName + "&&strPassword=" + strPassword+ "&&url="+url;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Info = JsonConvert.DeserializeObject<List<object>>(ResponseData.Result);

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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="lstQuestionId"></param>
        /// <param name="destinationCategoryID"></param>
        /// <returns></returns>
        public async Task<string> ImportWSQuestion(ImportData importParameters)
        {

            try
            {
                var serializedItem = JsonConvert.SerializeObject(importParameters);
                string Paramters = "api/Exam/ImportWSQuestion";
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
