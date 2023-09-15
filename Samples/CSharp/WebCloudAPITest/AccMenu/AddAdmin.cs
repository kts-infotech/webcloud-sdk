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

namespace WebCloudAPITest
{
    public partial class AddAdmin : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public AddAdmin(ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
        }

        private async void btnSubmit_Click(object sender, EventArgs e)
        {
            AdminAccInfo addAdminDetails = new AdminAccInfo();
            addAdminDetails.Email = tbUsername.Text;
            addAdminDetails.FirstName = tbFirstName.Text;
            addAdminDetails.LastName = tbLastName.Text;
            addAdminDetails.Password = tbPass.Text;
            addAdminDetails.Address = tbAddress.Text;
            addAdminDetails.PhoneNo = tbPhNo.Text;

            await objTestDataUtil.InvokeAddAdminAPI(addAdminDetails);
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
    }
}
