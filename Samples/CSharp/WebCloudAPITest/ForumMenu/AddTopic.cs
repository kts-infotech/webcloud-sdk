using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class AddTopic : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        private List<FormDetailsInfo> m_ExistForms;
        List<Topics> m_listDetails;
        string m_strTopicId;
        public AddTopic(WebCloudAPIForm objMainForm, List<FormDetailsInfo> listForum, List<Topics> listTopics)
        {
            InitializeComponent();
            m_ObjMainForm = objMainForm;
            m_ExistForms = listForum;
            m_listDetails = listTopics;
            AddForumNamesInCombo();
        }

        private void AddForumNamesInCombo()
        {
            foreach (FormDetailsInfo forum in m_ExistForms)
            {
                ItemInfo item = new ItemInfo { Text = forum.FormName, Value = forum.FormID };
                combForums.Items.Add(item);
            }
        }

        private void combForums_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = (combForums.SelectedItem as ItemInfo).Value.ToString();
            ShowGroupEmailsInCheckList(selection);
            listBoxTopics.Items.Clear();
            List<Topics> listTp = m_listDetails.FindAll(x => x.ForumID == selection);
            foreach (Topics tp in listTp)
            {
                ItemInfo item = new ItemInfo { Text = tp.TopicName, Value = tp.TopicID };
                listBoxTopics.Items.Add(item);
            }

        }

        private void ShowGroupEmailsInCheckList(string strForumID)
        {
            chkListEmails.Items.Clear();
            FormDetailsInfo fm = m_ExistForms.Find(x => x.FormID == strForumID);
            string strEmails = fm.GroupEmail.Trim();
            string[] emailIDs = strEmails.Split(',');
            foreach (var email in emailIDs)
            {
                if (email != "")
                    chkListEmails.Items.Add(email.Trim());
            }
        }

        private void btnSelectAll_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < chkListEmails.Items.Count; i++)
            {
                chkListEmails.SetItemChecked(i, true);
            }
        }

        private void btnUnselectAll_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < chkListEmails.Items.Count; i++)
            {
                chkListEmails.SetItemChecked(i, false);
            }
        }

        private void listBoxTopics_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxTopics.SelectedIndex == -1)
            {
                return;
            }
            btnAddNew.Visible = true;
            btnAdd.Text = "Update";
            string strTopicID = (listBoxTopics.SelectedItem as ItemInfo).Value.ToString();
            m_strTopicId = strTopicID;
            Topics tp = m_listDetails.Find(x => x.TopicID == strTopicID);
            textTopic.Text = tp.TopicName;
            textTopicDesc.Text = tp.TopicDesc;
            checkAdminApr.Checked = tp.AdminApproval;
            string[] emailIDs = tp.GroupEmail.Split(',');
            for (int i = 0; i < chkListEmails.Items.Count; i++)
            {
                string strEmailId = chkListEmails.Items[i].ToString();
                if (emailIDs.Contains(strEmailId))
                {
                    chkListEmails.SetItemChecked(i, true);
                }
                else
                {
                    chkListEmails.SetItemChecked(i, false);
                }
            }
        }

        private async void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (btnAdd.Text == "Add")
                {
                    string Info = await m_ObjMainForm.ApiService.AddTopics(GetDataFromForum());
                    ShowMessageBox("Information", Info);
                }
                else
                {
                    string Info = await m_ObjMainForm.ApiService.UpdateTopic(GetDataFromForum());
                    ShowMessageBox("Information", Info);
                }
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
            
        }

        private Topics GetDataFromForum()
        {
            Topics tp = new Topics();
            tp.TopicID = m_strTopicId;
            tp.ForumID = (combForums.SelectedItem as ItemInfo).Value.ToString();
            tp.TopicName = textTopic.Text;
            tp.TopicDesc = textTopicDesc.Text;
            tp.GroupEmail = GetGroupEmailAsString();
            tp.AdminApproval = checkAdminApr.Checked;
            return tp;

        }

        private string GetGroupEmailAsString()
        {
            string checkedItems = string.Empty;
            foreach (object Item in chkListEmails.CheckedItems)
            {
                checkedItems += Item.ToString() + ",";
            }
            return checkedItems;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnAddNew_Click(object sender, EventArgs e)
        {
            btnAdd.Text = "Add";
            btnAddNew.Visible = false;
            textTopic.Clear();
            textTopicDesc.Clear();
            checkAdminApr.Checked = false;
            for (int i = 0; i < chkListEmails.Items.Count; i++)
            {
                chkListEmails.SetItemChecked(i, false);
            }

        }

        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }

        private void delTopic_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(m_strTopicId))
            {
                MessageBox.Show("Please select a Topic");
                return;
            }
            DialogResult dialogResult = MessageBox.Show("Are Yoy sure Want to delete this Topic ?", "Confirm", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                InvokeTopicDeleteAPI(m_strTopicId);
            }
        }

        private async void InvokeTopicDeleteAPI(string m_strTopicID)
        {
            try
            {
                string response = await m_ObjMainForm.ApiService.DeleteTopic(m_strTopicID);
                if (response == "This Topic contains Threads")
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
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        private void ShowConfirmMsg(string response)
        {
            string strMsg = response + " Do you want to delete all details ?";
            DialogResult dialogResult = MessageBox.Show(strMsg, "Confirm", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                InvokeForceDeleteAPI(m_strTopicId);
            }
        }

        private async void InvokeForceDeleteAPI(string strTopicId)
        {
            try
            {
                string response = await m_ObjMainForm.ApiService.ForceDeleteTopic(strTopicId);
                MessageBox.Show(response);
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }

        }
    }
}
