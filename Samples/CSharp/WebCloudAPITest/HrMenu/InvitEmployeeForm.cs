using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloudAPITest.TestData;
using WebCloud.Api.DS;
using ProjectFrameworkAPITest;

namespace WebCloudAPITest
{
    public partial class InvitEmployeeForm : Form
    {
        WebCloudAPIForm m_ObjMainForm;

        public InvitEmployeeForm(EmplTypeCategory EmplTypeCat, WebCloudAPIForm obj)
        {
            InitializeComponent();
            m_ObjMainForm = obj;
            LoadComboBoxes(EmplTypeCat);
        }

        private void LoadComboBoxes(EmplTypeCategory emplTypeCat)
        {
            comEmplyType.Items.Clear();
            foreach(var item in emplTypeCat.EmployeeTypes)
            {
                comEmplyType.Items.Add(item);
            }
            comUsrCat.Items.Clear();
            foreach (var item in emplTypeCat.UserCategoryList)
            {
                comUsrCat.Items.Add(item);
            }
        }

        private  void btnInviteEmpl_Click(object sender, EventArgs e)
        {
            if(comUsrCat.SelectedIndex==-1)
            {
                MessageBox.Show("Please select User a Category","Warning!");
                return;
            }
            if (comEmplyType.SelectedIndex == -1)
            {
                MessageBox.Show("Please select an Employee type", "Warning!");
                return;
            }
            EmployeeInviteInfo invite = new EmployeeInviteInfo();
            invite.UserCategory = (comUsrCat.SelectedItem as ItemInfo).Value.ToString();
            invite.EmployeeType = (comEmplyType.SelectedItem as ItemInfo).Value.ToString();
            invite.UserEmailAddress = txtEmailList.Text;
            invite.UserMessage = txtMessage.Text;
            InvokeInviteEmployeeAPI(invite);
            
        }

        private async void InvokeInviteEmployeeAPI(EmployeeInviteInfo invite)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.InviteEmployee(invite);
                MessageBox.Show(result, "Result");
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
