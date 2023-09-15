using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class AddComment : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        private string m_strThreadID;
        public AddComment(WebCloudAPIForm obj, List<ItemInfo> info)
        {
            InitializeComponent();
            m_ObjMainForm = obj;
            m_strThreadID = "";
            foreach (ItemInfo item in info)
            {
                comboForumID.Items.Add(item);
            }
        }

        private async void comboForumID_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string strForumID = (comboForumID.SelectedItem as ItemInfo).Value.ToString();
                List<ItemInfo> info = await m_ObjMainForm.ApiService.GetAllTopicsWithForumID(strForumID);
                comboTopicID.Items.Clear();
                foreach (ItemInfo item in info)
                {
                    comboTopicID.Items.Add(item);
                }
                comboTopicID.SelectedIndex = 0;
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private async void comboTopicID_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string strTopicID = (comboTopicID.SelectedItem as ItemInfo).Value.ToString();
                List<ItemInfo> info = await m_ObjMainForm.ApiService.GetAllThreadsWithTopicID(strTopicID);
                comboThreadID.Items.Clear();
                foreach (ItemInfo item in info)
                {
                    comboThreadID.Items.Add(item);
                }
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private void comboThreadID_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_strThreadID = (comboThreadID.SelectedItem as ItemInfo).Value.ToString();
        }

        private void btnAddCmts_Click(object sender, EventArgs e)
        {
            CommentsInfo info = new CommentsInfo();
            info.ThreadID = m_strThreadID;
            info.Message = textBoxCmts.Text;
            info.User = m_ObjMainForm.GetUserID();
            info.Author = m_ObjMainForm.GetUserID();
            info.PostedDate = DateTime.Now.Date.Ticks.ToString();
            RequestAddCommentsAPI(info);
        }
        private async void RequestAddCommentsAPI(CommentsInfo info)
        {
            try
            {
                string responses = await m_ObjMainForm.ApiService.AddComments(info);
                ShowMessageBox("Sucess", responses);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }
    }
}
