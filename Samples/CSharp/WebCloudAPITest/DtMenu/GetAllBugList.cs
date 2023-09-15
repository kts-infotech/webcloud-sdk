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
    public partial class GetAllBugList : Form
    {
        List<BugTaskDetails> allBugList;
        public GetAllBugList(List<BugTaskDetails> Info)
        {
            InitializeComponent();
            allBugList = Info;
            foreach (BugTaskDetails details in Info)
            {
                combBugTaskTitle.Items.Add(details.BugTaskTitle);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void combBugTaskTitle_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem = combBugTaskTitle.SelectedItem.ToString();
            foreach (BugTaskDetails details in allBugList)
            {
                if(selectedItem == details.BugTaskTitle)
                {
                    lbBugStatus.Text = details.BugStatus == null ? "No Details Available": details.BugStatus;
                    textBugDesc.Text = details.BugTaskDescription;
                }
            }
        }
    }
}
