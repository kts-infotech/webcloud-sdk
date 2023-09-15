using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class DeleteThread : Form
    {
        private WebCloudAPIForm ObjMainForm;
        List<ThreadDetailsInfo> m_threadDeails;
        ThreadDetailsInfo m_SelectedObj;
        public DeleteThread(List<ThreadDetailsInfo> info, WebCloudAPIForm formObject)
        {
            m_threadDeails = info;
            ObjMainForm = formObject;
            InitializeComponent();
            foreach (ThreadDetailsInfo thread in m_threadDeails)
            {
                combThreadID.Items.Add(thread.ThreadID);
            }
        }


        private void combThreadID_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = combThreadID.SelectedItem.ToString();
            m_SelectedObj = m_threadDeails.Find(x => x.ThreadID == selection);
            lbThreadName.Text = "Thread Name :" + m_SelectedObj.ThreadName;
            textTaskDesc.Text = "Thread Desc :" + m_SelectedObj.ThreadDesc;
            lbBugStatus.Text = "Bug Status :" + m_SelectedObj.ftrDetails.BugStatus;
            lbAssigned.Text = "Assigned Status :" + m_SelectedObj.ftrDetails.ThreadAssigned;
            lbAuthorId.Text = "Author ID :" + m_SelectedObj.ftrDetails.AuthorID;
            Int64 ticks = Convert.ToInt64(m_SelectedObj.ftrDetails.PostedDate);
            DateTime dt = new DateTime(ticks);
            lbPostedDate.Text = "Posted On :" + dt.ToString("MM/dd/yyyy hh: mm tt");
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            string message = "Are you sure want to delete this thread?";
            string title = "Delete Thread";
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.Yes)
            {
                DeleteThisThread(combThreadID.SelectedItem.ToString());
            }
        }

        private async void DeleteThisThread(string strThreadID)
        {
            try
            {
                string info = await ObjMainForm.ApiService.DeleteThread(strThreadID);
                string title = "Information";
                MessageBox.Show(info, title);
                if (info == "Deleted Successfully") DeleteFromList();
                ObjMainForm.SetResponseData(info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
                ObjMainForm.SetResponseData(Ex.Message);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
           
        }

        private void DeleteFromList()
        {
            m_threadDeails.Remove(m_SelectedObj);
            combThreadID.Items.RemoveAt(combThreadID.SelectedIndex);
            combThreadID.SelectedIndex = 0;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
