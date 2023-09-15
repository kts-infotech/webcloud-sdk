using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class CompanyForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<VenderInfo> objCompanyList;
        private string objCompanyId;
        public CompanyForm(ApiTestDataUtil apiTestDataUtil, List<VenderInfo> CompanyList)
        {
            objTestDataUtil = apiTestDataUtil;
            objCompanyList = CompanyList;
            InitializeComponent();
        }
        private async void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                string result = string.Empty;
                if (ValidateData())
                {
                    VenderInfo objVenderInfo = new VenderInfo();
                    objVenderInfo.VenderCompanyName = txtCompanyName.Text;
                    objVenderInfo.VenderWebsiteUrl = txtWebSiteUrl.Text;
                    objVenderInfo.GstinVatID = txtGstVat.Text;
                    objVenderInfo.VenderPhoneNumber = txtTelephoneNo.Text;
                    objVenderInfo.VenderMobileNumber = txtMobileNo.Text;
                    objVenderInfo.VenderEmailAddress = txtEmailAddress.Text;
                    objVenderInfo.ReEnterEmailAddress = txtReEnterEmail.Text;
                    objVenderInfo.InvoicePrefix = txtInvoicePrefix.Text;
                    objVenderInfo.VenderAddress1 = txtAddress1.Text;
                    objVenderInfo.VenderAddress2 = txtAddress2.Text;
                    objVenderInfo.VenderCity = txtCity.Text;
                    objVenderInfo.VenderState = txtState.Text;
                    objVenderInfo.VenderPinCode = txtPinCode.Text;
                    objVenderInfo.VenderCountry = txtCountry.Text;
                    objVenderInfo.VenderProfileDesc = txtDescription.Text;
                    if (btnSave.Text.Equals("Save"))
                    {
                        result = await objTestDataUtil.InvokeAddCompanyAPI(objVenderInfo);
                    }
                    if (btnSave.Text.Equals("Update"))
                    {
                        objVenderInfo.VenderUserId = objCompanyId;
                        result = await objTestDataUtil.InvokeUpadteCompanyAPI(objVenderInfo);
                    }

                    if (result.Contains("Data saved Successfully"))
                    {
                        objCompanyList = await this.objTestDataUtil.MainForm.ApiService.GetCompanyList();
                        BindCompanyList();
                        ClearData();
                        MessageBox.Show("Data saved Successfully");
                    }
                    if (result.Contains("User E Mail Already Exists"))
                    {
                        MessageBox.Show("Email Address Already Exists");
                    }
                }
            }
            catch (Exception)
            {
               
            }
        }
        public bool ValidateData()
        {
            if (String.IsNullOrEmpty(txtCompanyName.Text))
            {
                MessageBox.Show("Enter Company Name");
                return false;
            }
            else if (String.IsNullOrEmpty(txtEmailAddress.Text))
            {
                MessageBox.Show("Enter Email Address");
                return false;
            }
            else if (String.IsNullOrEmpty(txtReEnterEmail.Text))
            {
                MessageBox.Show("ReEnter Email Address");
                return false;
            }
            else if(!txtEmailAddress.Text.Equals(txtReEnterEmail.Text))
            {
                MessageBox.Show("Mismatch Email Address!");
                return false;
            }
            Regex regex = new Regex(@"^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$");
            bool isValid = regex.IsMatch(txtEmailAddress.Text.Trim());
            if (!isValid)
            {
                MessageBox.Show("Enter valid Email Address");
                return false;
            }
            return true;
        }
        public void ClearData()
        {
            txtCompanyName.Text = string.Empty;
            txtWebSiteUrl.Text = string.Empty;
            txtGstVat.Text = string.Empty;
            txtTelephoneNo.Text = string.Empty; 
            txtMobileNo.Text = string.Empty; 
            txtEmailAddress.Text = string.Empty; 
            txtReEnterEmail.Text = string.Empty; 
            txtInvoicePrefix.Text = string.Empty;
            txtAddress1.Text = string.Empty;
            txtAddress2.Text = string.Empty;
            txtCity.Text = string.Empty;
            txtState.Text = string.Empty;
            txtPinCode.Text = string.Empty;
            txtCountry.Text = string.Empty;
            txtDescription.Text = string.Empty;
            btnSave.Text = "Save";
        }
        private void CompanyForm_Load(object sender, EventArgs e)
        {
            try
            {
                BindCompanyList();
            }
            catch (Exception)
            {
                
            }
        }
        public void BindCompanyList()
        {
            int i = 0;
            int rowcount = dgvCompany.RowCount;
            if (rowcount > 0)
            {
                dgvCompany.Rows.Clear();
            }
            foreach (var item in objCompanyList)
            {
                dgvCompany.Rows.Add();
                dgvCompany[0, i].Value = i + 1;
                dgvCompany[1, i].Value = item.VenderUserId;
                dgvCompany[2, i].Value = item.VenderCompanyName;
                dgvCompany[3, i].Value = item.VenderEmailAddress;
                dgvCompany[4, i].Value = item.VenderCity;
                dgvCompany[5, i].Value = item.VenderState;
                dgvCompany[6, i].Value = item.VenderMobileNumber;
                i++;
            }
            dgvCompany.Update();
            dgvCompany.Refresh();
        }
        private async void dgvCompany_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                string CompanyId = "";
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvCompany.Rows[e.RowIndex];
                    CompanyId = row.Cells["CompanyId"].Value.ToString();
                }
                if (dgvCompany.Columns[e.ColumnIndex].Name=="Delete")
                {
                    
                    if (MessageBox.Show("Are you sure to delete this record ?","Message",MessageBoxButtons.YesNo,MessageBoxIcon.Question)==DialogResult.Yes)
                    {                        
                        await objTestDataUtil.InvokeDeleteCompanyAPI(CompanyId);
                        objCompanyList = await this.objTestDataUtil.MainForm.ApiService.GetCompanyList();
                        BindCompanyList();
                        ClearData();
                    }                    
                }
                if (dgvCompany.Columns[e.ColumnIndex].Name == "Edit")
                {
                    objCompanyId = CompanyId;
                    VenderInfo objVenderInfo= objCompanyList.Where(x => x.VenderUserId == CompanyId).FirstOrDefault();
                    txtCompanyName.Text = objVenderInfo.VenderCompanyName;
                    txtWebSiteUrl.Text = objVenderInfo.VenderWebsiteUrl;
                    txtGstVat.Text = objVenderInfo.GstinVatID;
                    txtTelephoneNo.Text = objVenderInfo.VenderPhoneNumber;
                    txtMobileNo.Text = objVenderInfo.VenderMobileNumber;
                    txtEmailAddress.Text = objVenderInfo.VenderEmailAddress;
                    txtReEnterEmail.Text = objVenderInfo.VenderEmailAddress;
                    txtInvoicePrefix.Text = objVenderInfo.InvoicePrefix;
                    txtAddress1.Text = objVenderInfo.VenderAddress1;
                    txtAddress2.Text = objVenderInfo.VenderAddress2;
                    txtCity.Text = objVenderInfo.VenderCity;
                    txtState.Text = objVenderInfo.VenderState;
                    txtPinCode.Text = objVenderInfo.VenderPinCode;
                    txtCountry.Text = objVenderInfo.VenderCountry;
                    txtDescription.Text = objVenderInfo.VenderProfileDesc;
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
    }
}
