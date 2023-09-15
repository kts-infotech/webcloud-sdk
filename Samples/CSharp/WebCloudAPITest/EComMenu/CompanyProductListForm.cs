using Newtonsoft.Json;
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
using WebCloud.Services;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class CompanyProductListForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<VenderInfo> objCompanyList;
        private List<VendorProducts> objProductCategoryList;
        public CompanyProductListForm(TestData.ApiTestDataUtil api, List<VenderInfo> CompanyList,List<VendorProducts> ProductCategoryList)
        {
            objTestDataUtil = api;
            objCompanyList = CompanyList;
            objProductCategoryList = ProductCategoryList;
            InitializeComponent();
        }
        public void SetComboBox(List<VenderInfo> venderInfos)
        {
            comCompanyList.DisplayMember = "Text";
            comCompanyList.ValueMember = "Value";
            comCompanyList.Items.Add(new { Text = "Select", Value = "0" });
            comCompanyList.SelectedIndex = 0;
            foreach (VenderInfo proj in venderInfos)
            {
                comCompanyList.Items.Add(new { Text = proj.VenderCompanyName, Value = proj.VenderUserId });
            }
        }
        public void SetProductCategoryComboBox(List<VendorProducts> productcat)
        {
            comProductCategory.Items.Clear();          
            comProductCategory.DisplayMember = "Text";
            comProductCategory.ValueMember = "Value";
            comProductCategory.Items.Add(new { Text = "Select", Value = "0" });
            comProductCategory.SelectedIndex = 0;
            foreach (VendorProducts cat in productcat)
            {
                comProductCategory.Items.Add(new { Text = cat.CategoryName, Value = cat.CategoryID });
            }
        }
        public void SetProductSubcategoryComboBox(List<VendorProducts> productsubcat)
        {
            comProductSubcategory.Items.Clear();
            comProductSubcategory.ResetText();
            comProductSubcategory.ResetText();
            comProductSubcategory.DisplayMember = "Text";
            comProductSubcategory.ValueMember = "Value";
            comProductSubcategory.Items.Add(new { Text = "Select", Value = "0" });
            comProductSubcategory.SelectedIndex = 0;
            foreach (VendorProducts cat in productsubcat)
            {
                comProductSubcategory.Items.Add(new { Text = cat.SubCategoryName, Value = cat.SubCategoryId });
            }
        }
        private void CompanyProductListForm_Load(object sender, EventArgs e)
        {
            try
            {
                SetComboBox(objCompanyList);
                SetProductCategoryComboBox(objProductCategoryList);
            }
            catch (Exception)
            {

            }
        }
        private async void comProductCategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string CategoryId = (comProductCategory.SelectedItem as dynamic).Value;
                List<VendorProducts> ProductSubcategory = await objTestDataUtil.MainForm.ApiService.GetAllProductSubCategory(CategoryId);
                SetProductSubcategoryComboBox(ProductSubcategory);
                BindProductDetails();
            }
            catch (Exception)
            {

            }
        }
        private void comProductSubcategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                BindProductDetails();
            }
            catch (Exception)
            {
               
            }
        }
        public async void BindProductDetails()
        {
            string CompanyId = "0";
            string CategoryId = "0";
            string SubcategoryId = "0";
            if (!string.IsNullOrEmpty(comCompanyList.Text))
            {
                CompanyId = (comCompanyList.SelectedItem as dynamic).Value;
            }
            if (!string.IsNullOrEmpty(comProductCategory.Text))
            {
                CategoryId = (comProductCategory.SelectedItem as dynamic).Value;
            }
            if (!string.IsNullOrEmpty(comProductSubcategory.Text))
            {
                SubcategoryId = (comProductSubcategory.SelectedItem as dynamic).Value;
            }
            if (!CompanyId.Equals("0") && !CategoryId.Equals("0") && !SubcategoryId.Equals("0"))
            {
                List<VendorProducts> ProductDetails = await objTestDataUtil.MainForm.ApiService.GetProductDetails(CompanyId, CategoryId, SubcategoryId);
                txtProductDetails.Text = JsonConvert.SerializeObject(ProductDetails);
            }
            else
            {
                txtProductDetails.Text = "";
            }
        }
        private void comCompanyList_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                BindProductDetails();
            }
            catch (Exception)
            {
               
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
