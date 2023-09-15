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
    public partial class AssignTaskForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<ProjectDetails> objprojectList;
        private List<TaskDetails> objtaskList;
        private List<SubTaskDetails> objsubTaskList;
        private List<UserCategotyInfo> objuserGroupList;
        private List<UserAccountInfo> objteamMemberList;
        private List<TaskAssignment> objTaskAssignmentList;
        private string objUsername;
        public AssignTaskForm( ApiTestDataUtil apiTestDataUtil, string Username, List<ProjectDetails> projectList, List<TaskDetails> taskList, List<SubTaskDetails> subTaskList, List<UserCategotyInfo> userGroupList)
        {
            objUsername = Username;
            objTestDataUtil = apiTestDataUtil;
            objprojectList = projectList;
            objtaskList = taskList;
            objsubTaskList = subTaskList;
            objuserGroupList = userGroupList;
            InitializeComponent();
        }
        private async void btnAssignTask_Click(object sender, EventArgs e)
        {
            try
            {
                string result = string.Empty;
                TaskAssignment taskAssignment = new TaskAssignment();
                taskAssignment.ProjectID = (comProject.SelectedItem as dynamic).Value;
                taskAssignment.TaskID = (cbTask.SelectedItem as dynamic).Value;
                taskAssignment.SubTaskID = (cbSubTask.SelectedItem as dynamic).Value;
                taskAssignment.UserID = (cbUserGroup.SelectedItem as dynamic).Text;
                taskAssignment.EmployeeID= (cbTeamMember.SelectedItem as dynamic).Value;
                taskAssignment.TaskAssignedBy = objUsername;
                taskAssignment.TaskTitle= (comProject.SelectedItem as dynamic).Text + "|" + (cbTask.SelectedItem as dynamic).Text + "|" + (cbSubTask.SelectedItem as dynamic).Text;
                result = await objTestDataUtil.InvokeAssignTaskToEmpAPI(taskAssignment);
                if (result.Contains("The Selected user does not belong to an Employee Group"))
                {
                    MessageBox.Show("The Selected user does not belong to an Employee Group");
                }
                if (result.Contains("Task Already Assigned for the Selected Employee"))
                {
                    MessageBox.Show("Task Already Assigned for the Selected Employee");
                }
                if (result.Contains("Data saved Successfully"))
                {
                    objtaskList = await this.objTestDataUtil.MainForm.ApiService.GetAllTaskDetails();
                    //BindTaskList();
                    //ClearData();
                    MessageBox.Show("Task Assigned Sucessfully..");
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        private async void dgvAssignedTaskList_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                int TaskAssignmentId = 0;
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvAssignedTaskList.Rows[e.RowIndex];
                    TaskAssignmentId = Convert.ToInt32(row.Cells["AssignTaskId"].Value.ToString());
                }
                if (dgvAssignedTaskList.Columns[e.ColumnIndex].Name == "Delete")
                {

                    if (MessageBox.Show("Are you sure to delete this record ?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        await objTestDataUtil.DeleteAssignedTask(TaskAssignmentId);
                        objTaskAssignmentList = await objTestDataUtil.GetAssignedTaskofEmp((cbTeamMember.SelectedItem as dynamic).Value);
                        BindAssignedTaskofEmp();
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        private void AssignTaskForm_Load(object sender, EventArgs e)
        {
            SetProjectComboBox();
            SetTaskComboBox();
            SetSubTaskComboBox();
            SetUserGroupComboBox();
        }
        public void SetProjectComboBox()
        {
            comProject.DisplayMember = "Text";
            comProject.ValueMember = "Value";            
            foreach (ProjectDetails proj in objprojectList)
            {
                comProject.Items.Add(new { Text = proj.ProjectName, Value = proj.ProjectID });
            }
            comProject.SelectedIndex = 0;
        }
        public void SetTaskComboBox()
        {
            cbTask.DisplayMember = "Text";
            cbTask.ValueMember = "Value";
            foreach (TaskDetails proj in objtaskList)
            {
                cbTask.Items.Add(new { Text = proj.TaskTitle, Value = proj.TaskID });
            }
            cbTask.SelectedIndex = 0;
        }
        public void SetSubTaskComboBox()
        {
            cbSubTask.DisplayMember = "Text";
            cbSubTask.ValueMember = "Value";
            foreach (SubTaskDetails proj in objsubTaskList)
            {
                cbSubTask.Items.Add(new { Text = proj.SubTaskTitle, Value = proj.SubTaskID });
            }
            cbSubTask.SelectedIndex = 0;
        }
        public void SetUserGroupComboBox()
        {
            cbUserGroup.DisplayMember = "Text";
            cbUserGroup.ValueMember = "Value";
            foreach (UserCategotyInfo proj in objuserGroupList)
            {
                cbUserGroup.Items.Add(new { Text = proj.CategoryName, Value = proj.CategoryID });
            }
            cbUserGroup.SelectedIndex = 0;
        }
        public void SetTeamMemberComboBox()
        {
            cbTeamMember.Items.Clear();
            cbTeamMember.ResetText();
            cbTeamMember.DisplayMember = "Text";
            cbTeamMember.ValueMember = "Value";            
            foreach (UserAccountInfo proj in objteamMemberList)
            {
                cbTeamMember.Items.Add(new { Text = proj.FirstName, Value = proj.Email });
            }
            cbTeamMember.SelectedIndex = 0;            
        }
        public  void BindAssignedTaskofEmp()
        {            
            int i = 0;
            int rowcount = dgvAssignedTaskList.RowCount;
            if (rowcount > 0)
            {
                dgvAssignedTaskList.Rows.Clear();
            }
            foreach (var item in objTaskAssignmentList)
            {
                dgvAssignedTaskList.Rows.Add();
                dgvAssignedTaskList[0, i].Value = i + 1;
                dgvAssignedTaskList[1, i].Value = item.TaskAssignmentId;
                dgvAssignedTaskList[2, i].Value = item.AssignmentDesc;               
                i++;
            }
            dgvAssignedTaskList.Update();
            dgvAssignedTaskList.Refresh();
        }
        private async void cbUserGroup_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string UserGroupId = (cbUserGroup.SelectedItem as dynamic).Value;
                if (!UserGroupId.Equals("0"))
                {
                    objteamMemberList = await objTestDataUtil.MainForm.ApiService.GetTeamMemberByGroup(UserGroupId);
                   
                    SetTeamMemberComboBox();
                   
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }

        private async void cbTeamMember_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {                
                objTaskAssignmentList = await objTestDataUtil.GetAssignedTaskofEmp((cbTeamMember.SelectedItem as dynamic).Value);
                BindAssignedTaskofEmp();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
    }
}
