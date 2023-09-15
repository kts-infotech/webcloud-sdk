using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;
using WebCloud.Services;

namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        private WebCloudAPIForm ObjMainForm;
        public WebCloudAPIForm MainForm { get { return ObjMainForm; } }
        

        public ApiTestDataUtil(WebCloudAPIForm MainForm)
        {
            ObjMainForm = MainForm;
        }

        public async Task InvikeLoginValidationAPI()
        {
            try
            {
                ObjMainForm.SetStatusText("Please Wait..");
                string LoginButtonText = ObjMainForm.GetLoginButtonText();
                if (LoginButtonText == "Login")
                {
                    ObjMainForm.ApiService = new AppApiService(ObjMainForm.GetMainURL());
                    AuthInfo Info = await ObjMainForm.ApiService.ValidateUser(ObjMainForm.GetUserID(), ObjMainForm.GetPassword());
                    ObjMainForm.ApiService.SetUserCredentials(Info.UserID, Info.AuthenticationToken);
                    ObjMainForm.SetAutheticationToken(Info.AuthenticationToken);
                    ObjMainForm.SetResponseData(Info);
                    ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
                    ObjMainForm.SetLoginButtonText("Logout");
                    ObjMainForm.SaveDefaultValues();
                }
                else
                {
                    ObjMainForm.ApiService.SetUserCredentials("", "");
                    ObjMainForm.SetAutheticationToken("");
                    ObjMainForm.SetResponseData("");
                    ObjMainForm.SetLoginButtonText("Login");
                    ObjMainForm.SetStatusText("Logout..");

                }
            }
            catch(Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            
        }
    }
}
