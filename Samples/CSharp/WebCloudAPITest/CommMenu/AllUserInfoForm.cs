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
    public partial class AllUserInfoForm : Form
    {
        List<UserInfo> m_userInfoList;
        public AllUserInfoForm(List<UserInfo> userInfolist)
        {
            InitializeComponent();
            m_userInfoList = userInfolist;
            foreach (UserInfo userInfo in userInfolist)
            {
                combNames.Items.Add(userInfo.Name);
            }
        }

        private void combNames_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = combNames.SelectedItem.ToString();
            foreach (UserInfo infos in m_userInfoList)
            {
                if (selection == infos.Name)
                {
                    DisplaySelectedUserInfo(infos);
                    break;
                }
            }
        }

        private void DisplaySelectedUserInfo(UserInfo userInfo)
        {
            lbCategoryName.Text = userInfo.Name;
            lbEmailId.Text = userInfo.EmailID;
            lbPhoneNumber.Text = userInfo.PhoneNo;
            lbAddress.Text = userInfo.Address;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
