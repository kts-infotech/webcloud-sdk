using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;
namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {       
        public async Task InvokeListAllCompaniesAPI()
        {            
            try
            {
                List<VenderInfo> CompanyList = await this.ObjMainForm.ApiService.GetCompanyList();  
                CompanyListForm m_objCompany = new CompanyListForm(this, CompanyList);
                m_objCompany.Show();                
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeListAllCompanyProductsAPI()
        {
            try
            {
                List<VenderInfo> CompanyList = await this.MainForm.ApiService.GetCompanyList();
                List<VendorProducts> ProductCategoryList = await this.MainForm.ApiService.GetAllProductCategory();
                CompanyProductListForm m_objCompanyProductList = new CompanyProductListForm(this, CompanyList, ProductCategoryList);
                m_objCompanyProductList.Show();  
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }        
        public async Task InvokeCompanyAPI()
        {
            try
            {
                List<VenderInfo> CompanyList = await this.ObjMainForm.ApiService.GetCompanyList();   
                new CompanyForm(this, CompanyList).ShowDialog();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task<string> InvokeAddCompanyAPI(VenderInfo objVenderInfo)
        {
            string result = await ObjMainForm.ApiService.AddCompany(objVenderInfo);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeUpadteCompanyAPI(VenderInfo objVenderInfo)
        {
            string result = await ObjMainForm.ApiService.UpadteCompany(objVenderInfo);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task InvokeDeleteCompanyAPI(string CompanyId)
        {
            string result = await this.ObjMainForm.ApiService.DeleteCompany(CompanyId);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);            
        }
        public async Task InvokeCompanyProductAPI()
        {
            try
            {

                List<VenderInfo> CompanyList = await this.MainForm.ApiService.GetCompanyList();
                List<VendorProducts> ProductCategoryList = await this.MainForm.ApiService.GetAllProductCategory(); 
                
                new CompanyProductForm(this, CompanyList, ProductCategoryList).Show();

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        //public async Task InvokeUpadteCompanyProductDetailsAPI()
        //{
        //    //Separate API call for Add and Update 
        //}
        public async Task<string> InvokeAddCompanyProductAPI(VendorProducts objVendorProducts)
        {
            string result = await ObjMainForm.ApiService.AddCompanyProduct(objVendorProducts);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeUpadteCompanyProductAPI(VendorProducts objVendorProducts)
        {
            string result = await ObjMainForm.ApiService.UpadteCompanyProduct(objVendorProducts);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task InvokeDeleteCompanyProductAPI(string ProductId)
        {
            string result = await this.ObjMainForm.ApiService.DeleteCompanyProduct(ProductId);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
        }

        public async Task<FileChunkResp> UploadImageFileAPI(FileChunkReq fileChunkRequest)
        {
            return await MainForm.ApiService.UploadImageFile(fileChunkRequest);
        }
        public async Task InvokePaymentGatewaySettingsAPI()
        {
            try
            {
                List<VenderInfo> CompanyList = await this.MainForm.ApiService.GetCompanyList();    
                new PaymentGatewaySettingsForm(this, CompanyList).Show();
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }       
        public async Task<string> InvokeAddPayPalSettingsAPI(PayPalSettings payPalSettings)
        {
            string result = await this.MainForm.ApiService.AddPayPalSettings(payPalSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeUpdatePayPalSettingsAPI(PayPalSettings payPalSettings)
        {
            string result = await this.MainForm.ApiService.UpdatePayPalSettings(payPalSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeAddPayumoneySettingsAPI(PayUMoneySettings payUMoneySettings)
        {
            string result = await this.MainForm.ApiService.AddPayumoneySettings(payUMoneySettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeUpdatePayumoneySettingsAPI(PayUMoneySettings payUMoneySettings)
        {
            string result = await this.MainForm.ApiService.UpdatePayumoneySettings(payUMoneySettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeAddStripeSettingsAPI(StripeSettings stripeSettings)
        {
            string result = await this.MainForm.ApiService.AddStripeSettings(stripeSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }      
        public async Task<string> InvokeUpdateStripeSettingsAPI(StripeSettings stripeSettings)
        {
            string result = await this.MainForm.ApiService.UpdateStripeSettings(stripeSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeAddRazorpaySettingsAPI(RazorpaySettings razorpaySettings)
        {
            string result = await this.MainForm.ApiService.AddRazorpaySettings(razorpaySettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }        
        public async Task<string> InvokeUpdateRazorpaySettingsAPI(RazorpaySettings razorpaySettings)
        {
            string result = await this.MainForm.ApiService.UpdateRazorpaySettings(razorpaySettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeAddEmailSettingsAPI(EmailSettings emailSettings)
        {
            string result = await this.MainForm.ApiService.AddEmailSettings(emailSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeUpdateEmailSettingsAPI(EmailSettings emailSettings)
        {
            string result = await this.MainForm.ApiService.UpdateEmailSettings(emailSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeAddBusinessSettingsAPI(BusinessSettings businessSettings)
        {
            string result = await this.MainForm.ApiService.AddBusinessSettings(businessSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }        
        public async Task<string> InvokeUpdateBusinessSettingsSettingsAPI(BusinessSettings businessSettings)
        {
            string result = await this.MainForm.ApiService.UpdateBusinessSettings(businessSettings);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }        
        public async Task<string> InvokeAddBankDetailsAPI(BankDetails bankDetails)
        {
            string result = await this.MainForm.ApiService.AddBankDetails(bankDetails);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
        public async Task<string> InvokeUpdateBankDetailsAPI(BankDetails bankDetails)
        {
            string result = await this.MainForm.ApiService.UpdateBankDetails(bankDetails);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }        
        public async Task<string> InvokeAddShippingDetailsAPI(ShippingDetails shippingDetails)
        {
            string result = await this.MainForm.ApiService.AddShippingDetails(shippingDetails);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }       
        public async Task<string> InvokeUpdateShippingDetailsAPI(ShippingDetails shippingDetails)
        {
            string result = await this.MainForm.ApiService.UpdateShippingDetails(shippingDetails);
            ObjMainForm.SetResponseData(result);
            ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            return result;
        }
    }
}
