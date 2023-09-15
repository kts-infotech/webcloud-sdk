using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class DelComment : Form
    {
        private WebCloudAPIForm m_ObjMainForm;

        public DelComment(WebCloudAPIForm obj, List<ItemInfo> info)
        {
            InitializeComponent();
            m_ObjMainForm = obj;
            foreach (ItemInfo item in info)
            {
                comboForumID.Items.Add(item);
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }



        private void btnDelete_Click(object sender, EventArgs e)
        {
            List<string> msgs = new List<string>();
            foreach (DataGridViewRow row in dataGridView.Rows)
            {
                if (Convert.ToBoolean(row.Cells["seleDel"].Value))
                {
                    msgs.Add(row.Cells["MsgID"].Value.ToString());
                }
            }

            RequestDeleteAPI(msgs);
        }

        private async void RequestDeleteAPI(List<string> msgs)
        {
            try
            {
                List<string> responses = await m_ObjMainForm.ApiService.DeleteComments(msgs);
                foreach (string res in responses)
                {
                    if (res == "Failed")
                    {
                        ShowMessageBox("Error", "Some Comments are not Deleted");
                        return;
                    }
                }
                ShowMessageBox("Sucess", "All Comments Deleted Successfully");
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

        private void btnSelectAll_Click(object sender, EventArgs e)
        {

            foreach (DataGridViewRow row in dataGridView.Rows)
            {
                row.Cells["seleDel"].Value = true;
            }

        }

        private void btnUnSelectAll_Click(object sender, EventArgs e)
        {
            foreach (DataGridViewRow row in dataGridView.Rows)
            {
                row.Cells["seleDel"].Value = false;
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

        private async void comboThreadID_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string strThreadID = (comboThreadID.SelectedItem as ItemInfo).Value.ToString();
                List<CommentsInfo> info = await m_ObjMainForm.ApiService.GetMsgsByTrdID(strThreadID);
                dataGridView.Rows.Clear();
                if (info.Count == 0)
                    return;
                foreach (CommentsInfo item in info)
                {
                    Int64 ticks = Convert.ToInt64(item.PostedDate);
                    DateTime dt = new DateTime(ticks);
                    string strDate = dt.ToString("MM/dd/yyyy hh: mm tt");
                    dataGridView.Rows.Add(item.MsgID, item.Message, item.Author, strDate, item.Status);
                }
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }
        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }
    }
}
