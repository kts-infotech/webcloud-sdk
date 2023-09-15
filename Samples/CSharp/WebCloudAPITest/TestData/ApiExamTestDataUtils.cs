using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeListAllExamCategoriesAPI()
        {           
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();
            ObjMainForm.SetResponseData(result);
            new AddExamSubCategory(result, this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

         
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeExamCategoriesListAPI()
        {
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();
            ObjMainForm.SetResponseData(result);
            new ExamCategoryList(result, this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);


        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeExamSubCategoriesListAPI()
        {
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();
            ObjMainForm.SetResponseData(result);
            new ExamSubCategoryList(result, this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);


        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public void InvokeAddExamMainAPI()
        {
            new AddExamCategory(this).ShowDialog();
        }
       
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeListAllExamSubCategoriesAPI()
        {
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();
            ObjMainForm.SetResponseData(result);
            new AddExamSubCategory(result, this).ShowDialog();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examMainCategory"></param>
        /// <returns></returns>
        public async Task InvokeAddExamCategoriesAPI(ExamMainCategory examMainCategory)
        {
            string result = await ObjMainForm.ApiService.AddExamMainCategory(examMainCategory);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
           
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examMainCategory"></param>
        /// <returns></returns>
        public async Task InvokeAddExamSubCategoriesAPI(ExamSubCategory examSubCategory)
        {
            string result = await ObjMainForm.ApiService.AddExamSubCategory(examSubCategory);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

      
        public async Task InvokeEditDeleteQuestionsAPI()
        {
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();

            //Retrieve Exam subcategory Category from response objects.
            Newtonsoft.Json.Linq.JArray jsonResponse = Newtonsoft.Json.Linq.JArray.Parse(JsonConvert.SerializeObject(result[1]));
            string categoryId = (string)jsonResponse[0]["MainCategoryID"];
            string questions = await ObjMainForm.ApiService.GetAllQuestions(categoryId.ToString());

            ObjMainForm.SetResponseData(questions);

            new QuestionMaster(result, questions, this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }
 
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeExamQuestionPaperCategoryListAPI()
        {
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();
            
            //Retrieve Exam subcategory Category from response objects.
            Newtonsoft.Json.Linq.JArray jsonResponse = Newtonsoft.Json.Linq.JArray.Parse(JsonConvert.SerializeObject(result[1]));            
            string  categoryId= (string)jsonResponse[0]["MainCategoryID"];
            string questions = await ObjMainForm.ApiService.GetAllQuestions(categoryId.ToString());

            ObjMainForm.SetResponseData(questions);          

            new ExamQuestionPaper(result, questions, this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);


        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<string> InvokeLoadQuestionPaperAPI(int categoryId)
        {
            string  result =await ObjMainForm.ApiService.GetAllQuestions(categoryId.ToString());            
            ObjMainForm.SetResponseData(result);         
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<string> InvokeLoadQuestionMasterAPI(int categoryId)
        {
            string result = await ObjMainForm.ApiService.GetAllQuestions(categoryId.ToString());
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeUpdateExamSettings(WebCloud.Api.DS.ExamDefaultSettings examDefaultSettings)
        {
            string result = await ObjMainForm.ApiService.UpdateExamSettings(examDefaultSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeGetAllExamSettingsAPI()
        {
            List<WebCloud.Api.DS.ExamDefaultSettings> result = await ObjMainForm.ApiService.GetAllExamSettings();
            ObjMainForm.SetResponseData(result);
            new WebCloudAPITest.ExamDefaultSettings(result, this).ShowDialog();
            // ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="categoryId"></param>
        /// <returns></returns>
        public async Task InvokeRemoveQuestionsAPI(int categoryId,int Qid)
        {
            string result = await ObjMainForm.ApiService.DeleteQuestion(categoryId,Qid);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examQuestionMaster"></param>
        /// <returns></returns>
        public async Task InvokeAddQuestionAPI(ExamQuestionMaster examQuestionMaster)
        {
            string result = await ObjMainForm.ApiService.AddQuestion(examQuestionMaster);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examQuestionMaster"></param>
        /// <returns></returns>
        public async Task InvokeUpdateQuestionAPI(ExamQuestionMaster examQuestionMaster)
        {
            string result = await ObjMainForm.ApiService.UpdateQuestion(examQuestionMaster);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }
        public async Task InvokeCopyQuestionAPI()
        {
            List<object> result = await ObjMainForm.ApiService.GetExamInfoList();

            //Retrieve Exam subcategory Category from response objects.
            Newtonsoft.Json.Linq.JArray jsonResponse = Newtonsoft.Json.Linq.JArray.Parse(JsonConvert.SerializeObject(result[1]));
            string categoryId = (string)jsonResponse[0]["MainCategoryID"];
            string questions = await ObjMainForm.ApiService.GetAllQuestions(categoryId.ToString());

            ObjMainForm.SetResponseData(questions);

            new WebCloudAPITest.Copy(result, this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="examQuestionMaster"></param>
        /// <returns></returns>
        public async Task InvokeCopyAllQuestionsAPI(int sourceCategoryID, int destinationCategoryID)
        {
            string result = await ObjMainForm.ApiService.CopyAllQuestions(sourceCategoryID, destinationCategoryID);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name=""></param>
        /// <returns></returns>
        public async Task InvokeCopySelectedQuestionsAPI(List<ExamQuestionMaster> lstQuestionId, int destinationCategoryID)
        {
            string result = await ObjMainForm.ApiService.CopySelectedQuestions(lstQuestionId, destinationCategoryID);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

      
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public void InvokeImportQuestionAPI()
        {
            new WebCloudAPITest.ImportQuestions(this).ShowDialog();
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task<List<object>> InvokeGetWSDataAPI(string strUserName, string strPassword, string url)
        {
            List<object> result = await ObjMainForm.ApiService.GetWSData(strUserName, strPassword,url);
            ObjMainForm.SetResponseData(result);            
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name=""></param>
        /// <returns></returns>
        public async Task<string> InvokeImportWSQuestionAPI(ImportData importParameters)
        {
            string result = await ObjMainForm.ApiService.ImportWSQuestion(importParameters);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
    }
}
