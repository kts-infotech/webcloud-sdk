using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        private string UserName;
        public async Task InvokeProjectAPI(string strUserName)
        {
            try
            {
                UserName = strUserName;
                List<ProjectDetails> ProjectList = await this.ObjMainForm.ApiService.GetAllProjectDetails();
                new ProjectsForm(this, ProjectList).ShowDialog();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeGetAllProjectsAPI()
        {
            try
            {
                List<ProjectDetails> TasklList = await ObjMainForm.ApiService.GetAllProjectDetails();
                ObjMainForm.SetResponseData(TasklList);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeGetAllTasksAPI(string strUserName)
        {
            try
            {
                List<TaskDetails> TasklList = await ObjMainForm.ApiService.GetAllTaskDetails(strUserName);
                ObjMainForm.SetResponseData(TasklList);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task<string> InvokeAddProjectAPI(ProjectDetails projectDetails)
        {
            try
            {
                projectDetails.UserID = UserName;
                string result = await ObjMainForm.ApiService.AddNewProject(projectDetails);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }
                 
        }
        public async Task<string> UpdateProjectInfo(ProjectDetails objPrjDetails)
        {
            try
            {
                string result = await ObjMainForm.ApiService.UpdateProject(objPrjDetails);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }         
            
        }
        public async Task InvokeDeleteProjectAPI(int ProjectId)
        {
            try
            {
                string result = await this.ObjMainForm.ApiService.DeleteProject(ProjectId);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                
                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }


        public async Task InvokeTaskAPI()
        {
            try
            {               
                List<TaskDetails> TaskList = await ObjMainForm.ApiService.GetAllTaskDetails();
                new TaskForm(this, TaskList).ShowDialog();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task<string> InvokeAddTaskAPI(TaskDetails objTask)
        {
            try
            {
                string result = await ObjMainForm.ApiService.AddNewTask(objTask);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }      
                    
        }      
        public async Task DeleteTask(int TaskId)
        {
            try
            {
                string result = await ObjMainForm.ApiService.DeleteTask(TaskId);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task<string> InvokeUpdateTaskAPI(TaskDetails taskDetails)
        {
            try
            {
                string result = await ObjMainForm.ApiService.UpdateTask(taskDetails);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }
            
        }
       

        public async Task InvokeSubTaskAPI()
        {
            try
            {
                List<SubTaskDetails> SubTaskList = await ObjMainForm.ApiService.GetAllSubTaskDetails();
                new SubTaskForm(this, SubTaskList).ShowDialog();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task<string> InvokeAddSubTaskAPI(SubTaskDetails objSubTask)
        {
            try
            {
                string result = await ObjMainForm.ApiService.AddNewSubTask(objSubTask);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }
           
        }       
        public async Task DeleteSubTask(int SubTaskId)
        {
            try
            {
                string result = await ObjMainForm.ApiService.DeleteSubTask(SubTaskId);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task<string> InvokeUpdateSubTaskAPI(SubTaskDetails taskDetails)
        {
            try
            {
                string result = await ObjMainForm.ApiService.UpdateSubTask(taskDetails);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }
            
        }


       public async Task InvokeAssignTaskAPI()
        {
            try
            {
                string strUsername = ObjMainForm.GetUserID();
                List<ProjectDetails> ProjectList = await this.MainForm.ApiService.GetAllProjectDetails();
                List<TaskDetails> TaskList = await this.MainForm.ApiService.GetAllTaskDetails();
                List<SubTaskDetails> SubTaskList = await this.MainForm.ApiService.GetAllSubTaskDetails();
                List<UserCategotyInfo> UserGroupList = await this.MainForm.ApiService.GetExistingGroups();               
                new AssignTaskForm(this, strUsername, ProjectList, TaskList, SubTaskList, UserGroupList).ShowDialog();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task<string> InvokeAssignTaskToEmpAPI(TaskAssignment taskAssignment)
        {
            try
            {
                string result = await ObjMainForm.ApiService.AssignTaskToEmp(taskAssignment);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {

                throw Ex;
            }
           
        }        
        public async Task <List<TaskAssignment>> GetAssignedTaskofEmp(string EmpId)
        {
            List<TaskAssignment> TaskAssignmentList = new List<TaskAssignment>();
            try
            {
                TaskAssignmentList = await ObjMainForm.ApiService.GetAssignedTaskofEmp(EmpId);                
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            return TaskAssignmentList;
        }
        public async Task DeleteAssignedTask(int TaskAssignmentId)
        {
            try
            {
                string result = await ObjMainForm.ApiService.DeleteAssignedTask(TaskAssignmentId);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
    }
}