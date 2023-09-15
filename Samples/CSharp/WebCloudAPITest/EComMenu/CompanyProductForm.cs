using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class CompanyProductForm : Form
    {
        private List<VendorProducts> objProductList;
        private ApiTestDataUtil objTestDataUtil;
        private List<VenderInfo> objCompanyList;
        private List<VendorProducts> objProductCategoryList;
        private string objProductId;
        public CompanyProductForm(ApiTestDataUtil api, List<VenderInfo> companyList, List<VendorProducts> productCategoryList)
        {
            InitializeComponent();           
            this.objTestDataUtil = api;
            this.objCompanyList = companyList;
            this.objProductCategoryList = productCategoryList;
        }
        private void CompanyProductForm_Load(object sender, EventArgs e)
        {
            try
            {
                SetComboBox(objCompanyList);
                SetProductCategoryComboBox(objProductCategoryList);
                SetItemSpecComboBox();
                ptxtTaxName.Visible = false;
                ptxtTaxPercentage.Visible = false;
            }
            catch (Exception)
            {

            }
        }
        private async void Save_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateData())
                {
                    VendorProducts objVendorProducts = new VendorProducts();
                    string result = string.Empty;
                    objVendorProducts.VenderUserId = (comCompany.SelectedItem as dynamic).Value;
                    objVendorProducts.CategoryID = (comProductCategory.SelectedItem as dynamic).Value;
                    objVendorProducts.SubCategoryId = (comProductSubcategory.SelectedItem as dynamic).Value;
                    objVendorProducts.ProductTitle = txtProductName.Text;
                    objVendorProducts.ProductSubTitle = txtProductSubName.Text;
                    objVendorProducts.ProductSpecification = (comItemSpec.SelectedItem as dynamic).Text;
                    objVendorProducts.ProductPrice = txtPriceUSD.Text;
                    objVendorProducts.ProductQuantity = txtQuantity.Text;
                    objVendorProducts.ProductDescription = txtProductDesc.Text;
                    objVendorProducts.ProductMoreDetails = txtMoreDesc.Text;
                    objVendorProducts.ProductShippingDetails = txtShippingChargeUSD.Text;
                    objVendorProducts.ProductRealImagePath = "";
                    objVendorProducts.ProductType = 0; //Non-software products
                    objVendorProducts.ProductDisablePayPal = "No";
                    objVendorProducts.ProductPlimusLink = "";
                    objVendorProducts.ProductQuickDemoLink = "Nil";
                    objVendorProducts.productImages = GetProductImages();
                    objVendorProducts.ecomProductDetails = GetProductDetailsSettings();  
                    if (btnSave.Text.Equals("Save"))
                    {
                        result = await objTestDataUtil.InvokeAddCompanyProductAPI(objVendorProducts);
                    }
                    if (btnSave.Text.Equals("Update"))
                    {
                        objVendorProducts.ProductId = objProductId;
                        result = await objTestDataUtil.InvokeUpadteCompanyProductAPI(objVendorProducts);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        objCompanyList = await this.objTestDataUtil.MainForm.ApiService.GetCompanyList();
                        BindProductDetails();
                        ClearData();
                        MessageBox.Show("Data saved Successfully");
                    }
                    if (result.Contains("Product Title Already Exists"))
                    {
                        MessageBox.Show("Product Title Already Exists");
                    }
                }
            }
            catch (Exception)
            {

            }
        }
        private EcomProductDetailsSettings GetProductDetailsSettings()
        {
            EcomProductDetailsSettings objEcomProductDetailsSettings = new EcomProductDetailsSettings();
            objEcomProductDetailsSettings.ProductPriceInInr = txtPriceINR.Text;
            objEcomProductDetailsSettings.ShippingChargeInInr = txtShippingChargeINR.Text;
            objEcomProductDetailsSettings.YoutubeVideoLink = txtVideoURL.Text;
            objEcomProductDetailsSettings.ProductImageTwoUrl = "";
            objEcomProductDetailsSettings.ProductImageThreeUrl = "";
            objEcomProductDetailsSettings.ProductThmnailTwoUrl = "";
            objEcomProductDetailsSettings.ProductThmnailThreeUrl = "";
            objEcomProductDetailsSettings.TaxName = ptxtTaxName.Text;
            objEcomProductDetailsSettings.TaxPercentage = ptxtTaxPercentage.Text;
            objEcomProductDetailsSettings.IncludeTax = chkTax.Checked;
            objEcomProductDetailsSettings.ProductRegistrationCode = txtProductRegistrationCode.Text;
            return objEcomProductDetailsSettings;
        }
        private ProductImages GetProductImages()
        {
            ProductImages imgs = new ProductImages();
            DataConversion convrt = new DataConversion();   
            if(!string.IsNullOrEmpty(txtImage1Path.Text))
            {
                imgs.strImage1 = convrt.ConvertImageToBase64String(txtImage1Path.Text);
            }
            else
            {
                imgs.strImage1 = "NIL";
            }
            if (!string.IsNullOrEmpty(txtImage2Path.Text))
            {
                imgs.strImage2 = convrt.ConvertImageToBase64String(txtImage2Path.Text);
            }
            else
            {
                imgs.strImage2 = "NIL";
            }
            if (!string.IsNullOrEmpty(txtImage3Path.Text))
            {
                imgs.strImage3 = convrt.ConvertImageToBase64String(txtImage3Path.Text);
            }
            else
            {
                imgs.strImage3 = "NIL";
            }           
            return imgs;
        }
        private async void comProductCategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string CategoryId = (comProductCategory.SelectedItem as dynamic).Value;
                if (!CategoryId.Equals("0"))
                {
                    List<VendorProducts> ProductSubcategory = await objTestDataUtil.MainForm.ApiService.GetAllProductSubCategory(CategoryId);
                    SetProductSubcategoryComboBox(ProductSubcategory);
                    BindProductDetails();
                }
            }
            catch (Exception)
            {

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
        private async void dgvProductList_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                string ProductId = "";
                if (e.RowIndex >= 0)
                {
                    DataGridViewRow row = this.dgvProductList.Rows[e.RowIndex];
                    ProductId = row.Cells["ProductId"].Value.ToString();
                }
                if (dgvProductList.Columns[e.ColumnIndex].Name == "Delete")
                {
                    if (MessageBox.Show("Are you sure to delete this record ?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    {
                        await objTestDataUtil.InvokeDeleteCompanyProductAPI(ProductId);                        
                        BindProductDetails();
                        ClearData();
                    }
                }
                if (dgvProductList.Columns[e.ColumnIndex].Name == "Edit")
                {
                    objProductId = ProductId;
                    VendorProducts objVendorProductsInfo = objProductList.Where(x => x.ProductId == ProductId).FirstOrDefault();
                    EcomProductDetailsSettings objEcomProductDetailsSettings = new EcomProductDetailsSettings();
                    string strAdditionalInfoXml = objVendorProductsInfo.AdditionalInfoXml;
                    objEcomProductDetailsSettings = objEcomProductDetailsSettings.SetXMLDataToVariables(strAdditionalInfoXml);
                    txtProductName.Text = objVendorProductsInfo.ProductTitle;
                    txtProductSubName.Text = objVendorProductsInfo.ProductSubTitle;
                    comItemSpec.SelectedIndex = comItemSpec.FindString(objVendorProductsInfo.ProductSpecification);
                    txtPriceUSD.Text = objVendorProductsInfo.ProductPrice;
                    txtQuantity.Text = objVendorProductsInfo.ProductQuantity;
                    txtProductDesc.Text = objVendorProductsInfo.ProductDescription;
                    txtMoreDesc.Text = objVendorProductsInfo.ProductMoreDetails;
                    txtShippingChargeUSD.Text = objVendorProductsInfo.ProductShippingDetails;
                    pbImage1.Image = ConvertFromBase64(objVendorProductsInfo.productThumbs.strThumb1);
                    pbImage1.SizeMode = PictureBoxSizeMode.StretchImage;
                    pbImage2.Image = ConvertFromBase64(objVendorProductsInfo.productThumbs.strThumb2);
                    pbImage2.SizeMode = PictureBoxSizeMode.StretchImage;
                    pbImage3.Image = ConvertFromBase64(objVendorProductsInfo.productThumbs.strThumb3);
                    pbImage3.SizeMode = PictureBoxSizeMode.StretchImage;
                    txtVideoURL.Text = objEcomProductDetailsSettings.YoutubeVideoLink;
                    if (objEcomProductDetailsSettings.IncludeTax)
                    {
                        chkTax.Checked = objEcomProductDetailsSettings.IncludeTax;
                        ptxtTaxName.Text = objEcomProductDetailsSettings.TaxName;
                        ptxtTaxPercentage.Text = objEcomProductDetailsSettings.TaxPercentage;
                    }
                    txtPriceINR.Text = objEcomProductDetailsSettings.ProductPriceInInr;
                    txtProductRegistrationCode.Text = objEcomProductDetailsSettings.ProductRegistrationCode;
                    txtShippingChargeINR.Text = objEcomProductDetailsSettings.ShippingChargeInInr;  
                    int index1 = objVendorProductsInfo.ProductRealImagePath.LastIndexOf(@"/");
                    string filename1= objVendorProductsInfo.ProductRealImagePath.Substring(index1 + 1);                      
                    //FirstImg = objVendorProductsInfo.ProductRealImagePath;
                    int index2 = objEcomProductDetailsSettings.ProductImageTwoUrl.LastIndexOf(@"/");
                    string filename2 = objEcomProductDetailsSettings.ProductImageTwoUrl.Substring(index2 + 1);
                    //SecondImg = objEcomProductDetailsSettings.ProductImageTwoUrl;
                    int index3 = objEcomProductDetailsSettings.ProductImageThreeUrl.LastIndexOf(@"/");
                    string filename3 = objEcomProductDetailsSettings.ProductImageThreeUrl.Substring(index3 + 1);                   
                    //ThirdImg = objEcomProductDetailsSettings.ProductImageThreeUrl;
                    btnSave.Text = "Update";
                }
            }
            catch (Exception)
            {

            }
        }
        private Image ConvertFromBase64(string strImage)
        {
            byte[] imageByte = Convert.FromBase64String(strImage);
            MemoryStream ms = new MemoryStream(imageByte);
            return Image.FromStream(ms);
        }
        private void btnImage1_Click(object sender, EventArgs e)
        {
            try
            {
                ListAllDirFilesForm LocalPath = new ListAllDirFilesForm(objTestDataUtil, false, true, txtImage1Path.Text);
                LocalPath.ShowDialog();
                txtImage1Path.Text = LocalPath.DestPath;   
                Bitmap bitmap = null;    
                bitmap?.Dispose();
                pbImage1.Image?.Dispose();
                using (Bitmap tempImage = new Bitmap(LocalPath.DestPath, true))
                {
                    bitmap = new Bitmap(tempImage);
                    pbImage1.Image = bitmap;
                    pbImage1.SizeMode = PictureBoxSizeMode.StretchImage;
                }
            }
            catch (Exception)
            {
                
            }
        }
        private void btnImage2_Click(object sender, EventArgs e)
        {
            try
            {
                ListAllDirFilesForm LocalPath = new ListAllDirFilesForm(objTestDataUtil, false, true, txtImage2Path.Text);
                LocalPath.ShowDialog();
                txtImage2Path.Text = LocalPath.DestPath;
                Bitmap bitmap = null;
                bitmap?.Dispose();
                pbImage2.Image?.Dispose();
                using (Bitmap tempImage = new Bitmap(LocalPath.DestPath, true))
                {
                    bitmap = new Bitmap(tempImage);
                    pbImage2.Image = bitmap;
                    pbImage2.SizeMode = PictureBoxSizeMode.StretchImage;
                }
            }
            catch (Exception)
            {

            }
        }
        private void btnImage3_Click(object sender, EventArgs e)
        {
            ListAllDirFilesForm LocalPath = new ListAllDirFilesForm(objTestDataUtil, false, true, txtImage3Path.Text);
            LocalPath.ShowDialog();
            txtImage3Path.Text = LocalPath.DestPath;
            Bitmap bitmap = null;
            bitmap?.Dispose();
            pbImage3.Image?.Dispose();
            using (Bitmap tempImage = new Bitmap(LocalPath.DestPath, true))
            {
                bitmap = new Bitmap(tempImage);
                pbImage3.Image = bitmap;
                pbImage3.SizeMode = PictureBoxSizeMode.StretchImage;
            }
        }
        private void btnUpload_Click(object sender, EventArgs e)
        {

        }
        private void Cancel_Click(object sender, EventArgs e)
        {
            try
            {
                CancelData();
            }
            catch (Exception)
            {
               
            }
        }
        private void chkTax_CheckStateChanged(object sender, EventArgs e)
        {
            try
            {
                if (chkTax.Checked)
                {
                    ptxtTaxName.Visible = true;
                    ptxtTaxPercentage.Visible = true;
                }
                else
                {
                    ptxtTaxName.Visible = false;
                    ptxtTaxPercentage.Visible = false;
                }
            }
            catch (Exception)
            {

            }
        }
        public void ClearData()
        {
            txtProductName.Text = string.Empty;
            txtProductSubName.Text = string.Empty;
            comItemSpec.SelectedIndex = 0;
            txtImage1Path.Text = string.Empty;
            txtImage2Path.Text = string.Empty;
            txtImage3Path.Text = string.Empty;
            txtPriceUSD.Text = string.Empty;
            txtPriceINR.Text = string.Empty;
            txtQuantity.Text = string.Empty;
            ptxtTaxName.Text = string.Empty;
            ptxtTaxPercentage.Text = string.Empty;
            txtProductDesc.Text = string.Empty;
            txtMoreDesc.Text = string.Empty;
            txtVideoURL.Text = string.Empty;
            txtProductRegistrationCode.Text = string.Empty;
            txtShippingChargeUSD.Text = string.Empty;
            txtShippingChargeINR.Text = string.Empty;
            chkTax.Checked = false;
            pbImage1.Image = null;
            pbImage2.Image = null;
            pbImage3.Image = null;
            btnSave.Text = "Save";
        }
        public bool ValidateData()
        {
            if (String.IsNullOrEmpty(txtProductName.Text))
            {
                MessageBox.Show("Enter Product Name");
                return false;
            }
            else if(String.IsNullOrEmpty(txtQuantity.Text))
            {
                MessageBox.Show("Enter Quantity");
                return false;
            }
            else if (comCompany.SelectedIndex == 0)
            {
                MessageBox.Show("Select Company");
                return false;
            }
            else if (comProductCategory.SelectedIndex == 0)
            {
                MessageBox.Show("Select Product Category");
                return false;
            }
            else if (comProductSubcategory.SelectedIndex == 0)
            {
                MessageBox.Show("Select Product Sub Category");
                return false;
            }
            return true;
        }       
        public void SetItemSpecComboBox()
        {
            comItemSpec.DisplayMember = "Text";
            comItemSpec.ValueMember = "Value";
            comItemSpec.Items.Add(new { Text = "New", Value = "0" });
            comItemSpec.Items.Add(new { Text = "Used", Value = "1" });
            comItemSpec.Items.Add(new { Text = "Not Specified", Value = "2" });
            comItemSpec.SelectedIndex = 0;
        }
        public void SetComboBox(List<VenderInfo> venderInfos)
        {
            comCompany.DisplayMember = "Text";
            comCompany.ValueMember = "Value";
            comCompany.Items.Add(new { Text = "Select", Value = "0" });
            comCompany.SelectedIndex = 0;
            foreach (VenderInfo proj in venderInfos)
            {
                comCompany.Items.Add(new { Text = proj.VenderCompanyName, Value = proj.VenderUserId });
            }
        }
        public void CancelData()
        {
            comCompany.SelectedIndex = 0;
            comProductCategory.SelectedIndex = 0;
            if (comProductSubcategory.Items.Count > 0)
            {
                comProductSubcategory.SelectedIndex = 0;
            }
            txtProductName.Text = string.Empty;
            txtProductSubName.Text = string.Empty;
            comItemSpec.SelectedIndex = 0;
            txtImage1Path.Text = string.Empty;
            txtImage2Path.Text = string.Empty;
            txtImage3Path.Text = string.Empty;
            txtPriceUSD.Text = string.Empty;
            txtPriceINR.Text = string.Empty;
            txtQuantity.Text = string.Empty;
            ptxtTaxName.Text = string.Empty;
            ptxtTaxPercentage.Text = string.Empty;
            txtProductDesc.Text = string.Empty;
            txtMoreDesc.Text = string.Empty;
            txtVideoURL.Text = string.Empty;
            txtProductRegistrationCode.Text = string.Empty;
            txtShippingChargeUSD.Text = string.Empty;
            txtShippingChargeINR.Text = string.Empty;
            chkTax.Checked = false;
            pbImage1.Image = null;
            pbImage2.Image = null;
            pbImage3.Image = null;
            dgvProductList.DataSource = null;
            btnSave.Text = "Save";
        }
        public async void BindProductDetails()
        {
            string CompanyId = "0";
            string CategoryId = "0";
            string SubcategoryId = "0";
            if (!string.IsNullOrEmpty(comCompany.Text))
            {
                CompanyId = (comCompany.SelectedItem as dynamic).Value;
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
                objProductList = await objTestDataUtil.MainForm.ApiService.GetProductDetails(CompanyId, CategoryId, SubcategoryId);
                int i = 0;
                int rowcount = dgvProductList.RowCount;
                if (rowcount > 0)
                {
                    dgvProductList.Rows.Clear();
                }
                foreach (var item in objProductList)
                {
                    dgvProductList.Rows.Add();
                    dgvProductList[0, i].Value = i + 1;
                    dgvProductList[1, i].Value = item.ProductId;
                    dgvProductList[2, i].Value = item.VenderCompanyName;
                    dgvProductList[3, i].Value = item.CategoryName;
                    dgvProductList[4, i].Value = item.SubCategoryName;
                    dgvProductList[5, i].Value = item.ProductTitle;
                    dgvProductList[6, i].Value = item.ProductSpecification;
                    i++;
                }
                dgvProductList.Update();
                dgvProductList.Refresh();
            }
            else
            {
                dgvProductList.Rows.Clear();
            }
        }       
        public void SetProductSubcategoryComboBox(List<VendorProducts> productsubcat)
        {
            comProductSubcategory.Items.Clear();
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
    }
}
