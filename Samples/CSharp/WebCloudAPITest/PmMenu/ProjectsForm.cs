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
    public partial class ProjectsForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<ProjectDetails> objprojectList;
        private int objProjectId;
        public ProjectsForm(ApiTestDataUtil apiTestDataUtil, List<ProjectDetails> projectList)
        {
            objTestDataUtil = apiTestDataUtil;
            objprojectList = projectList;
            InitializeComponent();
        }
        private async void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                string result = string.Empty;
                if (ValidateData())
                {
                    ProjectDetails projectDetails = new ProjectDetails();
                    projectDetails.ProjectName = txtProjectName.Text;
                    projectDetails.ProjectDescription = txtProjectDescription.Text;
                    if (cbActive.Checked)
                    {
                        projectDetails.iCheckActive = 1;
                    }
                    else
                    {
                        projectDetails.iCheckActive = 0;
                    }

                    if (btnSave.Text.Equals("Save"))
                    {
                        result = await objTestDataUtil.InvokeAddProjectAPI(projectDetails);
                    }
                    if (btnSave.Text.Equals("Update"))
                    {
                        projectDetails.ProjectID = objProjectId;
                        result = await objTestDataUtil.UpdateProjectInfo(projectDetails);
                    }

                    if (result.Contains("Data saved Successfully"))
                    {
                        objprojectList = await this.objTestDataUtil.MainForm.ApiService.GetAllProjectDetails();
                        BindProjectList();
                        ClearData();
                        MessageBox.Show("Data saved Successfully");
                    }
                    if (result.Contains("User E Mail Already Exists"))
                    {
                        MessageBox.Show("Email Address Already Exists");
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
            txtProjectName.Text = string.Empty;
            txtProjectDescription.Text = string.Empty;
            cbActive.Checked = false;
            btnSave.Text = "Save";
        }
        public bool ValidateData()
        {
            if (String.IsNullOrEmpty(txtProjectName.Text))
            {
                MessageBox.Show("Enter Project Name");
                return false;
            }            
            return true;
        }
        private void ProjectsForm_Load(object sender, EventArgs e)
        {
            try
            {
                BindProjectList();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
        }
        public void BindProjectList()
        {
            int i = 0;
            int rowcount = dgvProjects.RowCount;
            if (rowcount > 0)
            {
                dgvProjects.Rows.Clear();
            }
            foreach (var item in objprojectList)
            {
                dgvProjects.Rows.Add();
                dgvProjects[0, i].Value = i + 1;
                dgvProjects[1, i].Value = item.ProjectID;
                dgvProjects[2, i].Value = item.ProjectName;
                dgvProjects[3, i].Value = item.ProjectDescription;
                i++;
            }
            dgvProjects.Update();
            dgvProjects.Refresh();
        }
        private async void dgvProjects_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                int ProjectId = 0;
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvProjects.Rows[e.RowIndex];
                    ProjectId = Convert.ToInt32(row.Cells["ProjectId"].Value.ToString());
                }
                if (dgvProjects.Columns[e.ColumnIndex].Name == "Delete")
                {

                    if (MessageBox.Show("Are you sure to delete this record ?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        await objTestDataUtil.InvokeDeleteProjectAPI(ProjectId);
                        objprojectList = await this.objTestDataUtil.MainForm.ApiService.GetAllProjectDetails();
                        BindProjectList();                       
                    }
                }
                if (dgvProjects.Columns[e.ColumnIndex].Name == "Edit")
                {
                    objProjectId = ProjectId;
                    ProjectDetails projectDetails = objprojectList.Where(x => x.ProjectID == ProjectId).FirstOrDefault();
                    txtProjectName.Text = projectDetails.ProjectName;
                    txtProjectDescription.Text = projectDetails.ProjectDescription;
                    if(projectDetails.iCheckActive == 1)
                    {
                        cbActive.Checked = true;
                    }
                    else
                    {
                        cbActive.Checked = false;
                    }
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
