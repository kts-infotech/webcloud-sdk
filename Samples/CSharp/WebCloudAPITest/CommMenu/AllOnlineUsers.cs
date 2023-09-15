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

namespace WebCloudAPITest
{
    public partial class AllOnlineUsers : Form
    {
        List<UserInfo> m_userInfoList;
        public AllOnlineUsers(List<UserInfo> info)
        {
            m_userInfoList = info;
            InitializeComponent();
            if (info != null)
            {
                foreach (UserInfo user in info)
                {
                    lsBoxUsers.Items.Add(user.EmailID);
                }
            }
        }

        private void lsBoxUsers_SelectedIndexChanged(object sender, EventArgs e)
        {
            string userEmailid = lsBoxUsers.SelectedItem.ToString();
            foreach(UserInfo userInfo in m_userInfoList)
            {
                if(userInfo.EmailID== userEmailid)
                {
                    DisplaySelectedDetails(userInfo);
                }
            }

        }

        private void DisplaySelectedDetails(UserInfo info)
        {
            lbConnID.Text = info.ConnectionId;
            lbName.Text = info.Name;
            lbPhoneNum.Text = info.PhoneNo;
            lbUserType.Text = info.UserType;
            lbAddress.Text = info.Address;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
