using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;
using WebCloud.Api.BLL;
using WebCloud.Api.DS;
using Newtonsoft.Json;
using System.Net.Http;


namespace WebCloud.Services
{
    public partial class AppApiService
    {
        public async Task <List<ProjectDetails>> GetAllProjectDetails()
        {
            List<ProjectDetails> TasklList = new List<ProjectDetails>();
            ProjectDetails list = new ProjectDetails();

            try
            {
                string Paramters = "api/PM/GetProjectList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    TasklList = JsonConvert.DeserializeObject<List<ProjectDetails>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return TasklList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<List<TaskDetails>> GetAllTaskDetails(string strUserName)
        {
            List<TaskDetails> TasklList = new List<TaskDetails>();
            TaskDetails list = new TaskDetails();

            try
            {
                string Paramters = "api/PM/GetTaskDetailsList?strUserName="+strUserName;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    TasklList = JsonConvert.DeserializeObject<List<TaskDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return TasklList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> AddNewProject(ProjectDetails pjDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(pjDetails);
                string Paramters = "api/PM/UploadNewProjectDetails";
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
        public async Task<string> UpdateProject(ProjectDetails pjDetails)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(pjDetails);
                string Paramters = "api/PM/UpdateProjectInfo";
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
        public async Task<string> DeleteProject(int ProjectId)
        {
            string Response;

            try
            {
                string Paramters = "api/PM/DeleteProject?ProjectId=" + ProjectId;
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
        public async Task<string> AddNewTask(TaskDetails objTaskDetail)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(objTaskDetail);
                string Paramters = "api/PM/UploadNewTaskDetails";
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
        public async Task<List<TaskDetails>> GetAllTaskDetails()
        {
            List<TaskDetails> TasklList = new List<TaskDetails>();
            TaskDetails list = new TaskDetails();

            try
            {
                string Paramters = "api/PM/GetAllTaskList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    TasklList = JsonConvert.DeserializeObject<List<TaskDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return TasklList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> DeleteTask(int TaskId)
        {
            string Response;

            try
            {
                string Paramters = "api/PM/DeleteTask?TaskId=" + TaskId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
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
        public async Task<string> UpdateTask(TaskDetails taskDetails)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(taskDetails);
                string Paramters = "api/PM/UpdateTask";
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

        public async Task<string> AddNewSubTask(SubTaskDetails subTaskDetails)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(subTaskDetails);
                string Paramters = "api/PM/AddSubTask";
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
        public async Task<List<SubTaskDetails>> GetAllSubTaskDetails()
        {
            List<SubTaskDetails> SubTasklList = new List<SubTaskDetails>();
            TaskDetails list = new TaskDetails();
            try
            {
                string Paramters = "api/PM/GetAllSubTaskList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    SubTasklList = JsonConvert.DeserializeObject<List<SubTaskDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }
                return SubTasklList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> DeleteSubTask(int SubTaskId)
        {
            string Response;

            try
            {
                string Paramters = "api/PM/DeleteSubTask?SubTaskId=" + SubTaskId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
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
        public async Task<string> UpdateSubTask(SubTaskDetails subTaskDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(subTaskDetails);
                string Paramters = "api/PM/UpdateSubTask";
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
        public async Task<List<UserAccountInfo>> GetTeamMemberByGroup(string GroupId)
        {
            List<UserAccountInfo> UserAccountList = new List<UserAccountInfo>();
            try
            {
                string Paramters = "Api/PM/GetTeamMemberByGroup?GroupId=" + GroupId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    UserAccountList = JsonConvert.DeserializeObject<List<UserAccountInfo>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return UserAccountList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
     
        public async Task<string> AssignTaskToEmp(TaskAssignment taskAssignment)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(taskAssignment);
                string Paramters = "api/PM/AssignTaskToEmp";
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
        
        public async Task<List<TaskAssignment>> GetAssignedTaskofEmp(string EmpId)
        {
            List<TaskAssignment> TaskAssignmentList = new List<TaskAssignment>();
            TaskAssignment taskAssignment = new TaskAssignment();
            try
            {
                string Paramters = "api/PM/GetAssignedTaskofEmp?EmpId=" + EmpId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    TaskAssignmentList = JsonConvert.DeserializeObject<List<TaskAssignment>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return TaskAssignmentList;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        
        public async Task<string> DeleteAssignedTask(int TaskAssignmentId)
        {
            string Response;
            try
            {
                string Paramters = "api/PM/DeleteAssignedTask?TaskAssignmentId=" + TaskAssignmentId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
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

    }
}
