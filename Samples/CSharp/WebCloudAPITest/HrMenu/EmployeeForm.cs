using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloudAPITest.TestData;
using WebCloud.Api.DS;
using System.Text.RegularExpressions;
using System.Web.UI.WebControls;

namespace WebCloudAPITest
{
    public partial class EmployeeForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<EmployeeInfo> objEmployeeList;
        private string objEmployeeId;
        private List<EmployeeType> objEmployeeTypeList;
        private Array objEmpStstus;

        public EmployeeForm(ApiTestDataUtil apiTestDataUtil, List<EmployeeInfo> EmployeeList, List<EmployeeType> employeeTypeList, Array empStstus)
        {
            objTestDataUtil = apiTestDataUtil;
            objEmployeeList = EmployeeList;
            objEmployeeTypeList = employeeTypeList;
            objEmpStstus = empStstus;
            InitializeComponent();
        }
        

        private async void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                string result = string.Empty;
                if (ValidateEmployee())
                {
                    EmployeeInfo EmplDet = new EmployeeInfo();
                    EmplDet.EmployeeName = textEmployeeName.Text;
                    EmplDet.EmployeeType = combEmployeeType.SelectedIndex.ToString();
                    EmplDet.EmployeeAddr = textEmployeeAddr.Text;
                    EmplDet.EmployeeEmailOff = txtEmailOffice.Text;
                    EmplDet.EmployeeEmailHom = txtEmailPersonal.Text;
                    EmplDet.EmployeePh = txtPhoneNumber.Text;
                    EmplDet.EmployeeJoinDate = dateJoin.Text;
                    EmplDet.EmployeeLeavingDate = dateJoin.Text;
                    EmplDet.EmployeeStatus = (combStatus.SelectedItem as dynamic).Text;
                    EmplDet.EmployeeFinalSal = txtLastSal.Text;
                    EmplDet.EmployeeRemarks = txtRemarks.Text;
                    if (btnSave.Text.Equals("Save"))
                    {
                        result = await objTestDataUtil.InvokeAddEmployee(EmplDet);
                    }
                    if (btnSave.Text.Equals("Update"))
                    {
                        EmplDet.EmployeeID = objEmployeeId;
                        result = await objTestDataUtil.InvokeUpadteEmployeeAPI(EmplDet);
                    }

                    if (result.Contains("Data saved Successfully"))
                    {
                        objEmployeeList = await this.objTestDataUtil.MainForm.ApiService.GetAllEmployeeInfo();
                        BindEmployeeList();
                        ClearData();
                        MessageBox.Show("Data saved Successfully");
                    }
                    if (result.Contains("This EmailID already exists."))
                    {
                        MessageBox.Show("This EmailID already exists.");
                    }
                }
            }
            catch (Exception)
            {
                
            }
        }
        public void BindEmployeeList()
        {
            int i = 0;
            int rowcount = dgvEmployee.RowCount;
            if (rowcount > 0)
            {
                dgvEmployee.Rows.Clear();
            }
            foreach (var item in objEmployeeList)
            {
                dgvEmployee.Rows.Add();
                dgvEmployee[0, i].Value = i + 1;
                dgvEmployee[1, i].Value = item.EmployeeID;
                dgvEmployee[2, i].Value = item.EmployeeName;
                dgvEmployee[3, i].Value = item.EmployeeEmailOff;
                dgvEmployee[4, i].Value = item.EmployeeEmailHom;
                dgvEmployee[5, i].Value = item.EmployeePh;              
                i++;
            }
            dgvEmployee.Update();
            dgvEmployee.Refresh();
        }       
        public bool ValidateEmployee()
        {
            if (String.IsNullOrEmpty(textEmployeeName.Text))
            {
                MessageBox.Show("Enter Employee Name");
                return false;
            }
            else if (String.IsNullOrEmpty(textEmployeeAddr.Text))
            {
                MessageBox.Show("Enter Employee Address");
                return false;
            }
            else if (String.IsNullOrEmpty(txtEmailOffice.Text))
            {
                MessageBox.Show("Enter Office Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtEmailPersonal.Text))
            {
                MessageBox.Show("Enter Personal Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtEmailPersonal.Text))
            {
                MessageBox.Show("Enter Personal Email");
                return false;
            }
            Regex regex = new Regex(@"^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$");            
            if (!regex.IsMatch(txtEmailOffice.Text.Trim()))
            {
                MessageBox.Show("Enter valid office Email");
                return false;
            }
            if (!regex.IsMatch(txtEmailPersonal.Text.Trim()))
            {
                MessageBox.Show("Enter valid personal Email");
                return false;
            }
            return true;
        }
        private void EmployeeForm_Load(object sender, EventArgs e)
        {
            try
            {
                SetEmployeeStatusComboBox(objEmpStstus);
                SetEmployeeTypeComboBox(objEmployeeTypeList);
                BindEmployeeList();
            }
            catch (Exception)
            {
               
            }
        }
        public void SetEmployeeStatusComboBox(Array objEmpStstus)
        {
            foreach (EmployeeStatus status in objEmpStstus)
            {
                combStatus.Items.Add(new ListItem(status.ToString(), ((int)status).ToString()));
            }
            combStatus.SelectedIndex = 0;
        }
        public void SetEmployeeTypeComboBox(List<EmployeeType> EmployeeTypeList)
        {
            combEmployeeType.DisplayMember = "Text";
            combEmployeeType.ValueMember = "Value";  
            foreach (EmployeeType type in EmployeeTypeList)
            {
                combEmployeeType.Items.Add(new { Text = type.EmployeeTypeName, Value = type.EmployeeTypeID });
            }
            combEmployeeType.SelectedIndex = 0;
        }        
        private async void dgvEmployee_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {               
                string EmployeeId = "";
                string EmployeeEmail = "";
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvEmployee.Rows[e.RowIndex];
                    EmployeeId = row.Cells["EmployeeId"].Value.ToString();
                    EmployeeEmail = row.Cells["EmailIDOffice"].Value.ToString();
                }
                if (dgvEmployee.Columns[e.ColumnIndex].Name == "Delete")
                {

                    if (MessageBox.Show("Are you sure to delete this record ?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        await objTestDataUtil.InvokeDeleteEmployeeAPI(EmployeeEmail);
                        objEmployeeList = await this.objTestDataUtil.MainForm.ApiService.GetAllEmployeeInfo();
                        BindEmployeeList();
                        ClearData();
                    }
                }
                if (dgvEmployee.Columns[e.ColumnIndex].Name == "Edit")
                {
                    objEmployeeId = EmployeeId;
                    EmployeeInfo EmployeeInfo = objEmployeeList.Where(x => x.EmployeeEmailOff == EmployeeEmail).FirstOrDefault();
                    textEmployeeName.Text = EmployeeInfo.EmployeeName;
                    combEmployeeType.SelectedIndex = Convert.ToInt32(EmployeeInfo.EmployeeType);
                    txtEmailOffice.Text = EmployeeInfo.EmployeeEmailOff;
                    txtEmailPersonal.Text = EmployeeInfo.EmployeeEmailHom;
                    txtPhoneNumber.Text = EmployeeInfo.EmployeePh;
                    combStatus.SelectedIndex = combStatus.FindString(EmployeeInfo.EmployeeStatus);
                    txtLastSal.Text = EmployeeInfo.EmployeeFinalSal;
                    textEmployeeAddr.Text = EmployeeInfo.EmployeeAddr;
                    dateJoin.Text = EmployeeInfo.EmployeeJoinDate;
                    dateLeave.Text = EmployeeInfo.EmployeeLeavingDate;                    
                    txtRemarks.Text = EmployeeInfo.EmployeeRemarks;                    
                    btnSave.Text = "Update";
                }
            }
            catch (Exception)
            {

            }
        }
        private void Cancel_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData();
            }
            catch (Exception)
            {

            }
        }
        public void ClearData()
        {
            textEmployeeName.Text = string.Empty;
            combEmployeeType.SelectedIndex = 0;
            txtEmailOffice.Text = string.Empty;
            txtEmailPersonal.Text = string.Empty;
            txtPhoneNumber.Text = string.Empty;
            combStatus.SelectedIndex = 0;
            txtLastSal.Text = string.Empty;
            textEmployeeAddr.Text = string.Empty;
            dateJoin.Text = string.Empty;
            dateLeave.Text = string.Empty;
            txtRemarks.Text = string.Empty;
            btnSave.Text = "Save";
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
