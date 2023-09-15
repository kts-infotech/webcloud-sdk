using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;


namespace WebCloudAPITest
{
    public partial class SubTaskForm : Form
    {        
        private ApiTestDataUtil objTestDataUtil;
        private List<SubTaskDetails> objtaskList;
        private int objSubTaskId;
        public SubTaskForm(ApiTestDataUtil apiTestDataUtil, List<SubTaskDetails> taskList)
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
                    SubTaskDetails subTaskDetails = new SubTaskDetails();
                    subTaskDetails.SubTaskTitle = txtSubTaskName.Text;
                    subTaskDetails.SubTaskDescription = txtSubTaskDescription.Text;
                    if (btnSave.Text.Equals("Save"))
                    {
                        result = await objTestDataUtil.InvokeAddSubTaskAPI(subTaskDetails);
                    }
                    if (btnSave.Text.Equals("Update"))
                    {
                        subTaskDetails.SubTaskID = objSubTaskId;
                        result = await objTestDataUtil.InvokeUpdateSubTaskAPI(subTaskDetails);
                    }

                    if (result.Contains("Data saved Successfully"))
                    {
                        objtaskList = await this.objTestDataUtil.MainForm.ApiService.GetAllSubTaskDetails();
                        BindSubTaskList();
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
            txtSubTaskName.Text = string.Empty;
            txtSubTaskDescription.Text = string.Empty;
            btnSave.Text = "Save";
        }
        public bool ValidateData()
        {
            if (String.IsNullOrEmpty(txtSubTaskName.Text))
            {
                MessageBox.Show("Enter SubTask Name");
                return false;
            }
            return true;
        }
        public void BindSubTaskList()
        {
            int i = 0;
            int rowcount = dgvSubTasks.RowCount;
            if (rowcount > 0)
            {
                dgvSubTasks.Rows.Clear();
            }
            foreach (var item in objtaskList)
            {
                dgvSubTasks.Rows.Add();
                dgvSubTasks[0, i].Value = i + 1;
                dgvSubTasks[1, i].Value = item.SubTaskID;
                dgvSubTasks[2, i].Value = item.SubTaskTitle;
                dgvSubTasks[3, i].Value = item.SubTaskDescription;
                i++;
            }
            dgvSubTasks.Update();
            dgvSubTasks.Refresh();
        }       
        private void SubTaskForm_Load(object sender, EventArgs e)
        {
            try
            {
                BindSubTaskList();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        private async void dgvSubTasks_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                int SubTaskId = 0;
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvSubTasks.Rows[e.RowIndex];
                    SubTaskId = Convert.ToInt32(row.Cells["SubTaskId"].Value.ToString());
                }
                if (dgvSubTasks.Columns[e.ColumnIndex].Name == "Delete")
                {

                    if (MessageBox.Show("Are you sure to delete this record ?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        await objTestDataUtil.DeleteSubTask(SubTaskId);
                        objtaskList = await this.objTestDataUtil.MainForm.ApiService.GetAllSubTaskDetails();
                        BindSubTaskList();
                    }
                }
                if (dgvSubTasks.Columns[e.ColumnIndex].Name == "Edit")
                {
                    objSubTaskId = SubTaskId;
                    SubTaskDetails taskDetails = objtaskList.Where(x => x.SubTaskID == SubTaskId).FirstOrDefault();
                    txtSubTaskName.Text = taskDetails.SubTaskTitle;
                    txtSubTaskDescription.Text = taskDetails.SubTaskDescription;
                    btnSave.Text = "Update";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
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
    }
}
