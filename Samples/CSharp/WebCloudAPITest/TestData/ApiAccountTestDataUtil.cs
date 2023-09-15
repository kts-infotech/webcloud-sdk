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
        private ApiTestDataUtil objTestDataUtil;

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeUserListAPI()
        {
            try
            {
                List<UserAccountInfo> result = await ObjMainForm.ApiService.GetUserList();
                ObjMainForm.SetResponseData(result);
                new UserList(result, this).ShowDialog();
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
            }
            
           // ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        public async Task InvokeGetUserListForDeletionAPI(ApiTestDataUtil obj)
        {
            try
            {
                objTestDataUtil = obj;
                
                List<UserAccountInfo> result = await ObjMainForm.ApiService.GetUserList();
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
               
                DeleteUser user = new DeleteUser(objTestDataUtil);
                user.SetComboBox(result);
                user.ShowDialog();
            }
            catch (Exception ex)
            {
                ObjMainForm.SetResponseData(ex);
            }
           
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        public async Task InvokeGetAdminListForDeletionAPI(ApiTestDataUtil obj)
        {
            try
            {
                objTestDataUtil = obj;
                
                List<AdminAccInfo> result = await ObjMainForm.ApiService.GetAdminList();
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
               
                DeleteAdmin admin = new DeleteAdmin(objTestDataUtil);
                
                admin.SetComboBox(result);              
                admin.ShowDialog();
            }
            catch (Exception ex)
            {
                ObjMainForm.SetResponseData(ex);
            }

        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="addUserDetails"></param>
        /// <returns></returns>
        public async Task InvokeAddUserAPI(UserAccountInfo addUserDetails)
        {
            try
            {
                string result = await ObjMainForm.ApiService.AddUser(addUserDetails);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
           
        }
        public async Task InvokeInviteUserAPI(UserInvitation invite)
        {
            try
            {
                string result = await ObjMainForm.ApiService.InviteUser(invite);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="email"></param>
        /// <returns></returns>
        public async Task InvokeDeleteUserAPI(string email)
        {
            try
            {
                string result = await ObjMainForm.ApiService.DeleteUser(email);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeBlockUserAPI()
        {
            try
            {
                List<UserAccountInfo> result = await ObjMainForm.ApiService.GetUserList();
                ObjMainForm.SetResponseData(result);
                new BlockUser(result, this).ShowDialog();
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="addAdminDetails"></param>
        /// <returns></returns>
        public async Task InvokeAddAdminAPI(AdminAccInfo addAdminDetails)
        {
            try
            {
                string result = await ObjMainForm.ApiService.AddAdmin(addAdminDetails);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="email"></param>
        /// <returns></returns>
        public async Task InvokeDeleteAdminAPI(string email)
        {
            try
            {
                string result = await ObjMainForm.ApiService.DeleteAdmin(email);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public async Task InvokeGenerateTempSiteAccessTokenAPI()
        {
            try
            {
                string Info = await ObjMainForm.ApiService.GenerateTempSiteAccessToken();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }


        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public void InvokeAddUserAccountAPI()
        {
            new AddUser(this).ShowDialog();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="addAdminDetails"></param>
        /// <returns></returns>
        public async Task InvokeBlockOrUnBlockUserAPI(UserAccountInfo blockOrUnblockUser)
        {
            try
            {
                string result = await ObjMainForm.ApiService.BlockORUnBlockUser(blockOrUnblockUser);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {

                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            
        }

    }
}
