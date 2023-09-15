using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class GetAllThread : Form
    {
        List<ThreadDetailsInfo> m_threadDeails;
        public GetAllThread(List<ThreadDetailsInfo> info)
        {
            m_threadDeails = info;
            InitializeComponent();
            foreach (ThreadDetailsInfo thread in m_threadDeails)
            {
                combThreadID.Items.Add(thread.ThreadID);
            }
        }

        private void combThreadID_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = combThreadID.SelectedItem.ToString();
            ThreadDetailsInfo info = m_threadDeails.Find(x => x.ThreadID == selection);
            lbThreadName.Text = "Thread Name :" + info.ThreadName;
            textTaskDesc.Text = "Thread Desc :" + info.ThreadDesc;
            lbBugStatus.Text = "Bug Status :" + info.ftrDetails.BugStatus;
            lbAssigned.Text = "Assigned Status :" + info.ftrDetails.ThreadAssigned;
            lbAuthorId.Text = "Author ID :" + info.ftrDetails.AuthorID;
            try
            {
                Int64 ticks = Convert.ToInt64(info.ftrDetails.PostedDate);
                DateTime dt = new DateTime(ticks);
                lbPostedDate.Text = "Posted On :" + dt.ToString("MM/dd/yyyy hh: mm tt");
            }
            catch (Exception)
            {

                lbPostedDate.Text = "Posted On : Date not available";
            }
            
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
