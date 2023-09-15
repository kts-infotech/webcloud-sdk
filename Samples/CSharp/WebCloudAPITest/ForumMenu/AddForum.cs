using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class AddForum : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        private List<FormDetailsInfo> m_ExistForms;
        FormDetailsInfo m_Info;

        string m_strFormID;
        public AddForum(WebCloudAPIForm obj, List<FormDetailsInfo> forms)
        {
            InitializeComponent();
            m_ObjMainForm = obj;
            m_ExistForms = forms;
            m_Info = new FormDetailsInfo();
            foreach (FormDetailsInfo form in forms)
            {
                ItemInfo item = new ItemInfo();
                item.Text = form.FormName;
                item.Value = form.FormID;
                listBoxExistingForum.Items.Add(item);
            }
            SetGroupsInCombo();
            SetFormTypeCombo();
            combForumType.SelectedIndex = 0;
        }

        private void SetFormTypeCombo()
        {
            ItemInfo item1 = new ItemInfo();
            item1.Text = "Discussion Forum";
            item1.Value = "False";
            ItemInfo item2 = new ItemInfo();
            item2.Text = "Bug Tracking System";
            item2.Value = "True";
            ItemInfo item3 = new ItemInfo();
            item3.Text = "Blog";
            item3.Value = "Blog";

            combForumType.Items.Add(item1);
            combForumType.Items.Add(item2);
            combForumType.Items.Add(item3);
        }

        private async void SetGroupsInCombo()
        {
            try
            {
                List<UserCategotyInfo> InfoList = await m_ObjMainForm.ApiService.GetExistingGroups();
                foreach (UserCategotyInfo Info in InfoList)
                {
                    ItemInfo item = new ItemInfo();
                    item.Text = Info.CategoryName;
                    item.Value = Info.CategoryID;
                    combSelGroup.Items.Add(item);
                }
            }
            catch (Exception Ex)
            {

                ShowMessageBox("Error", Ex.Message);
            }
            

        }

        private async void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                string strResponse = "";
                if (textForumName.Text == "")
                {
                    ShowMessageBox("Error", "You must provide a Forum name");
                    return;
                }
                ExtractDataFromWinForm();
                if (btnAdd.Text == "Add")
                {
                    strResponse = await m_ObjMainForm.ApiService.AddForum(m_Info);
                    if ("Forum details saved successfully." == strResponse)
                    {
                        listBoxExistingForum.Items.Add(textForumName.Text);
                    }
                }
                else
                {
                    strResponse = await m_ObjMainForm.ApiService.UpdateForum(m_Info);

                }
                ShowMessageBox("Info", strResponse);
                m_ObjMainForm.SetResponseData(strResponse);
                m_ObjMainForm.SetRequestURL(m_ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {

                ShowMessageBox("Error", Ex.Message);
            }
            
        }

        private void ExtractDataFromWinForm()
        {
            m_Info.FormID = m_strFormID;
            m_Info.FormName = textForumName.Text;
            m_Info.ForumType = (combForumType.SelectedItem as ItemInfo).Value.ToString();
            m_Info.IsPrivate = checkIsPrivate.Checked;
            m_Info.IsThreadAdminOnly = checkIsOnlyAdmin.Checked;
            m_Info.FormDesc = textDesc.Text;
            m_Info.GroupEmail = textEmails.Text;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }

        private async void btnRtrvEmail_Click(object sender, EventArgs e)
        {
            if (combSelGroup.SelectedIndex == -1)
            {
                ShowMessageBox("Error", "Please select a group");
                return;
            }

            string strGroupId = (combSelGroup.SelectedItem as ItemInfo).Value.ToString();
            try
            {
                textEmails.Text = await m_ObjMainForm.ApiService.RetrieveEmail(strGroupId);
            }
            catch (Exception Ex)
            {

                ShowMessageBox("Error", Ex.Message);
            }
            
        }

        private void listBoxExistingForum_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxExistingForum.SelectedIndex < 0)
            {
                return;
            }
            m_strFormID = (listBoxExistingForum.SelectedItem as ItemInfo).Value.ToString();
            FormDetailsInfo info = m_ExistForms.Find(x => x.FormID == m_strFormID);
            textForumName.Text = info.FormName;
            string strForumType = info.ForumType;
            if (strForumType == "True")
            {
                combForumType.SelectedIndex = 1;//Bug Tracking System
            }
            else if (strForumType == "Blog")
            {
                combForumType.SelectedIndex = 2;//Discussion Blog
            }
            else
            {
                combForumType.SelectedIndex = 0;//Discussion Forum
            }
            checkIsPrivate.Checked = info.IsPrivate;
            checkIsOnlyAdmin.Checked = info.IsThreadAdminOnly;
            textDesc.Text = info.FormDesc;
            textEmails.Text = info.GroupEmail;
            btnAdd.Text = "Update";
            btnAddNew.Visible = true;

        }

        private void btnAddNew_Click(object sender, EventArgs e)
        {
            btnAddNew.Visible = false;
            btnAdd.Text = "Add";
            textForumName.Clear();
            textDesc.Clear();
            textEmails.Clear();
            combForumType.SelectedIndex = 0;
            combSelGroup.SelectedIndex = -1;
            listBoxExistingForum.ClearSelected();
            checkIsPrivate.Checked = false;
            checkIsOnlyAdmin.Checked = false;
        }

        private void delForum_Click(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(m_strFormID))
            {
                MessageBox.Show("Please select a Forum");
                return;
            }
            DialogResult dialogResult = MessageBox.Show("Are Yoy sure Want to delete this Forum ?", "Confirm", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                InvokeForumDeleteAPI(m_strFormID);
            }
        }

        private async void InvokeForumDeleteAPI(string m_strFormID)
        {
            try
            {
                string response = await m_ObjMainForm.ApiService.DeleteForum(m_strFormID);
                if(response == "This Forum Contains Topics")
                {
                    ShowConfirmMsg(response);
                }
                else
                {
                    MessageBox.Show(response);
                }
                
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message,"Error");
            }
        }

        private void ShowConfirmMsg(string response)
        {
            string strMsg = response + " Do you want to delete all details ?";
            DialogResult dialogResult = MessageBox.Show(strMsg, "Confirm", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                InvokeForceDeleteAPI(m_strFormID);
            }
        }

        private async void InvokeForceDeleteAPI(string strFormID)
        {
            try
            {
                string response = await m_ObjMainForm.ApiService.ForceDeleteForum(strFormID);
                MessageBox.Show(response);
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
            
        }
    }

}
