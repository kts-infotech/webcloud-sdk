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
    public partial class InviteUser : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public InviteUser(ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
        }

        private async void btnInviteUser_Click(object sender, EventArgs e)
        {
           

            UserInvitation invite = new UserInvitation();
            if (cbUserCategory.SelectedIndex ==0)
            {
                invite.UserCategory = "1000";
            }

            //invite.UserCategory = cbUserCategory.SelectedIndex.ToString();
            invite.UserEmail = txtEmailAddr.Text;
            invite.UserMessage = txtMsg.Text;
            await objTestDataUtil.InvokeInviteUserAPI(invite);
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
