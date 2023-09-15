using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;
using WstWebServiceImpl;

namespace WebCloudAPITest
{
    public partial class AddUser : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public AddUser(ApiTestDataUtil obj)
        {

            InitializeComponent();
            objTestDataUtil = obj;
        }

        private void AddUser_Load(object sender, EventArgs e)
        {

        }

        private void btnSubmit_Click(object sender, EventArgs e)
        {
            UserAccountInfo addUserDetails = new UserAccountInfo();

            addUserDetails.Email = tbUsername.Text;
            addUserDetails.FirstName = tbFirstName.Text;
            addUserDetails.LastName = tbLastName.Text;
            addUserDetails.Password = tbPass.Text;
            addUserDetails.Address = tbAddress.Text;
            addUserDetails.PhoneNo = tbPhNo.Text;

            InvokeAddUserAPI(addUserDetails);
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }


        private async void InvokeAddUserAPI(UserAccountInfo addUserDetails)
        {
            try
            {
                await objTestDataUtil.InvokeAddUserAPI(addUserDetails);
            }
            catch (Exception Ex)
            {
                objTestDataUtil.MainForm.SetResponseData(Ex.Message);
            }
        }

    }
}
