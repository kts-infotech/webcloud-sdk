using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using WebCloud.Api.DS;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        public async Task InvokeEmployeeAPI()
        {
            try
            {
                List<EmployeeInfo> EmployeeList = await this.ObjMainForm.ApiService.GetAllEmployeeInfo();
                List<EmployeeType> EmployeeTypeList = await this.ObjMainForm.ApiService.GetEmpoloyeeType();
                Array EmpStstus = Enum.GetValues(typeof(EmployeeStatus));
                new EmployeeForm(this, EmployeeList, EmployeeTypeList, EmpStstus).ShowDialog();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeDeleteEmployeeAPI(string EmployeeId)
        {
            string result = await this.ObjMainForm.ApiService.DeleteEmployee(EmployeeId);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }
        public async Task<string> InvokeUpadteEmployeeAPI(EmployeeInfo EmployeeInfo)
        {
            string result = await ObjMainForm.ApiService.UpadteEmployee(EmployeeInfo);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeAddEmployee(EmployeeInfo EmplDet)
        {
            string result = string.Empty;
            try
            {
                result = await ObjMainForm.ApiService.UploadNewEmployee(EmplDet);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                return result;
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            return result;
        }

        public async Task InvokeInviteEmployeeAPI()
        {
            try
            {
                EmplTypeCategory result = await ObjMainForm.ApiService.FetchEmplTypeCategory();
                InvitEmployeeForm form = new InvitEmployeeForm(result, ObjMainForm);
                form.Show();
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeHrManagerAsEmailAPI()
        {
            try
            {
                WCResult result = await ObjMainForm.ApiService.FetchCategoryManager();
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                if (result.Status)
                {
                    HrSendEmailForm form = new HrSendEmailForm(ObjMainForm, result.Desc);
                    form.Show();
                }
                else
                {
                    MessageBox.Show(result.Desc, "Error");
                }
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.ToString());
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
            
        }
        public void InvokeLeaveForm()
        {
            ApplyForLeaveForm form = new ApplyForLeaveForm(this, ObjMainForm);
            form.Show();
        }
        public async Task InvokeListAllLeaveApplicationsAPI()
        {
            try
            {
                List<LeaveRequestDetails> Info = await ObjMainForm.ApiService.GetAllLeaveApplicationsList();
                ListAllLeaveApplicationsForm form = new ListAllLeaveApplicationsForm(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeApproveRejectLeaveAPI()
        {
            try
            {
                List<LeaveRequestDetails> Info = await ObjMainForm.ApiService.GetAllLeaveApplicationsList();
                ApproveOrRejectLeaveForm form = new ApproveOrRejectLeaveForm(Info, ObjMainForm);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
    }
}