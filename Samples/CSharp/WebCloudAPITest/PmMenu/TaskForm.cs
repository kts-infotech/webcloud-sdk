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
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class TaskForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<TaskDetails> objtaskList;
        private int objTaskId;
        public TaskForm(ApiTestDataUtil apiTestDataUtil, List<TaskDetails> taskList)
        {
            objTestDataUtil = apiTestDataUtil;
            objtaskList = taskList;
            InitializeComponent();
        }
        private async void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                string result = string.Empty;
                if (ValidateData())
                {
                    TaskDetails taskDetails = new TaskDetails();
                    taskDetails.TaskTitle = txtTaskName.Text;
                    taskDetails.TaskDescription = txtTaskDescription.Text;
                    if (btnSave.Text.Equals("Save"))
                    {
                        result = await objTestDataUtil.InvokeAddTaskAPI(taskDetails);
                    }
                    if (btnSave.Text.Equals("Update"))
                    {
                        taskDetails.TaskID = objTaskId;
                        result = await objTestDataUtil.InvokeUpdateTaskAPI(taskDetails);
                    }

                    if (result.Contains("Data saved Successfully"))
                    {
                        objtaskList = await this.objTestDataUtil.MainForm.ApiService.GetAllTaskDetails();
                        BindTaskList();
                        ClearData();
                        MessageBox.Show("Data saved Successfully");
                    }                    
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        public void ClearData()
        {
            txtTaskName.Text = string.Empty;
            txtTaskDescription.Text = string.Empty;
            btnSave.Text = "Save";
        }
        public bool ValidateData()
        {
            if (String.IsNullOrEmpty(txtTaskName.Text))
            {
                MessageBox.Show("Enter Task Name");
                return false;
            }
            return true;
        }
        public void BindTaskList()
        {
            int i = 0;
            int rowcount = dgvTasks.RowCount;
            if (rowcount > 0)
            {
                dgvTasks.Rows.Clear();
            }
            foreach (var item in objtaskList)
            {
                dgvTasks.Rows.Add();
                dgvTasks[0, i].Value = i + 1;
                dgvTasks[1, i].Value = item.TaskID;
                dgvTasks[2, i].Value = item.TaskTitle;
                dgvTasks[3, i].Value = item.TaskDescription;
                i++;
            }
            dgvTasks.Update();
            dgvTasks.Refresh();
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        private void TaskForm_Load(object sender, EventArgs e)
        {
            try
            {
                BindTaskList();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        private async void dgvTasks_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                int TaskId = 0;
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvTasks.Rows[e.RowIndex];
                    TaskId = Convert.ToInt32(row.Cells["TaskId"].Value.ToString());
                }
                if (dgvTasks.Columns[e.ColumnIndex].Name == "Delete")
                {

                    if (MessageBox.Show("Are you sure to delete this record ?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        await objTestDataUtil.DeleteTask(TaskId);
                        objtaskList = await this.objTestDataUtil.MainForm.ApiService.GetAllTaskDetails();
                        BindTaskList();
                    }
                }
                if (dgvTasks.Columns[e.ColumnIndex].Name == "Edit")
                {
                    objTaskId = TaskId;
                    TaskDetails taskDetails = objtaskList.Where(x => x.TaskID == TaskId).FirstOrDefault();
                    txtTaskName.Text = taskDetails.TaskTitle;
                    txtTaskDescription.Text = taskDetails.TaskDescription;
                    btnSave.Text = "Update";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
    }
}
