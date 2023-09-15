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
    public partial class DtGetBugTrackerDetailList : Form
    {
        List<BugTaskDetails> bugTaskListDetails;
        public DtGetBugTrackerDetailList(List<BugTaskDetails> Info)
        {
            InitializeComponent();
            bugTaskListDetails = Info;
            foreach (BugTaskDetails list in Info)
            {
                combBugTaskTitle.Items.Add(list.BugTaskTitle);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void combBugTaskTitle_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedBug = combBugTaskTitle.SelectedItem.ToString();
            foreach (BugTaskDetails list in bugTaskListDetails)
            {
                if (list.BugTaskTitle == selectedBug)
                {
                    textBugStatus.Text = list.BugStatus;
                    webBrowser.DocumentText= list.BugTaskDescription;
                }
            }
        }
    }
}
