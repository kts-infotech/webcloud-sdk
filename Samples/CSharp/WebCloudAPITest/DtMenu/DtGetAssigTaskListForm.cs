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
    public partial class DtGetAssigTaskListForm : Form
    {
        List<TaskDetails> assignedTaskList;
        public DtGetAssigTaskListForm(List<TaskDetails> Info)
        {
            assignedTaskList = Info;
            InitializeComponent();
            foreach (TaskDetails taskDetail in Info)
            {
                combTaskId.Items.Add(taskDetail.TaskID);
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }


        private void combTaskId_SelectedIndexChanged(object sender, EventArgs e)
        {
            int selTaskID = Convert.ToInt32(combTaskId.SelectedItem);
            foreach (TaskDetails taskDetail in assignedTaskList)
            {
                if (taskDetail.TaskID == selTaskID)
                {
                    textTaskTitle.Text = taskDetail.TaskTitle != null ? taskDetail.TaskTitle : "No Title available";
                    textTaskDesc.Text = taskDetail.TaskDescription != null ? taskDetail.TaskDescription : "No details available";
                }
            }
        }
    }
}
