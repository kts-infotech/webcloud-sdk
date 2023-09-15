using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloud.Services
{
    public partial class AppApiService
    {   
        public async Task<List<VenderInfo>> GetCompanyList()
        {
            List<VenderInfo> Info = new List<VenderInfo>();
            try
            {
                string Paramters = "api/Ecom/GetCompanyList";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<VenderInfo>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<List<VendorProducts>> GetAllProductCategory()
        {            
            List<VendorProducts> Info = new List<VendorProducts>();
            try
            {
                string Paramters = "api/Ecom/GetAllProductCategory";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<VendorProducts>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<List<VendorProducts>> GetAllProductSubCategory(string CategoryId)
        {            
            List<VendorProducts> Info = new List<VendorProducts>();
            try
            {
                string Paramters = "api/Ecom/GetAllProductSubCategory?CategoryId=" + CategoryId; 
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<VendorProducts>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<List<VendorProducts>> GetProductDetails(string CompanyId, string CategoryId, string SubcategoryId)
        {
            List<VendorProducts> Info = new List<VendorProducts>();
            try
            {               
                string Paramters = "api/Ecom/GetProductDetails?CompanyId="+CompanyId+"&CategoryId="+CategoryId+"&SubcategoryId="+SubcategoryId; 
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<List<VendorProducts>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> AddCompany(VenderInfo objVenderInfo)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(objVenderInfo);
                string Paramters = "api/Ecom/AddCompany";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> UpadteCompany(VenderInfo objVenderInfo)
        {
            string Response;

            try
            {
                var serializedItem = JsonConvert.SerializeObject(objVenderInfo);
                string Paramters = "api/Ecom/UpadteCompany";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> DeleteCompany(string CompanyId)
        {
            string Response;

            try
            {
                string Paramters = "api/Ecom/DeleteCompany?CompanyId="+CompanyId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> AddCompanyProduct(VendorProducts objVendorProducts)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(objVendorProducts);
                string Paramters = "api/Ecom/AddCompanyProduct";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> UpadteCompanyProduct(VendorProducts objVendorProducts)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(objVendorProducts);
                string Paramters = "api/Ecom/UpadteCompanyProduct";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> DeleteCompanyProduct(string ProductId)
        {
            string Response;

            try
            {
                string Paramters = "api/Ecom/DeleteCompanyProduct?ProductId=" + ProductId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<FileChunkResp> UploadImageFile(FileChunkReq fileChunkRequest)
        {
            FileChunkResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(fileChunkRequest);
                string Paramters = "api/Ecom/UploadImageFile";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<FileChunkResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<PayPalSettings> GetPayPalSettings(string VendorId)
        {
            PayPalSettings Info = new PayPalSettings();
            try
            {
                string Paramters = "api/Ecom/GetPayPalSettings?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<PayPalSettings>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<PayUMoneySettings> GetPayUMoneySettings(string VendorId)
        {
            PayUMoneySettings Info = new PayUMoneySettings();
            try
            {
                string Paramters = "api/Ecom/GetPayUMoneySettings?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<PayUMoneySettings>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<StripeSettings> GetStripeSettings(string VendorId)
        {
            StripeSettings Info = new StripeSettings();
            try
            {
                string Paramters = "api/Ecom/GetStripeSettings?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<StripeSettings>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<RazorpaySettings> GetRazorpaySettings(string VendorId)
        {
            RazorpaySettings Info = new RazorpaySettings();
            try
            {
                string Paramters = "api/Ecom/GetRazorpaySettings?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<RazorpaySettings>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<EmailSettings> GetEMailSettings(string VendorId)
        {
            EmailSettings Info = new EmailSettings();
            try
            {
                string Paramters = "api/Ecom/GetEMailSettings?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<EmailSettings>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }        
        public async Task<BusinessSettings> GetBusinessSettings(string VendorId)
        {
            BusinessSettings Info = new BusinessSettings();
            try
            {
                string Paramters = "api/Ecom/GetBusinessSettings?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<BusinessSettings>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<BankDetails> GetBankDetails(string VendorId)
        {
            BankDetails Info = new BankDetails();
            try
            {
                string Paramters = "api/Ecom/GetBankDetails?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<BankDetails>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<ShippingDetails> GetShippingDetails(string VendorId)
        {
            ShippingDetails Info = new ShippingDetails();
            try
            {
                string Paramters = "api/Ecom/GetShippingDetails?VendorId=" + VendorId;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    Info = JsonConvert.DeserializeObject<ShippingDetails>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Info;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> AddPayPalSettings(PayPalSettings payPalSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(payPalSettings);
                string Paramters = "api/Ecom/AddPayPalSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> UpdatePayPalSettings(PayPalSettings payPalSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(payPalSettings);
                string Paramters = "api/Ecom/UpdatePayPalSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }        
        public async Task<string> AddPayumoneySettings(PayUMoneySettings payUMoneySettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(payUMoneySettings);
                string Paramters = "api/Ecom/AddPayumoneySettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }        
        public async Task<string> UpdatePayumoneySettings(PayUMoneySettings payUMoneySettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(payUMoneySettings);
                string Paramters = "api/Ecom/UpdatePayumoneySettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> AddStripeSettings(StripeSettings stripeSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(stripeSettings);
                string Paramters = "api/Ecom/AddStripeSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }       
        public async Task<string> UpdateStripeSettings(StripeSettings stripeSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(stripeSettings);
                string Paramters = "api/Ecom/UpdateStripeSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> AddRazorpaySettings(RazorpaySettings razorpaySettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(razorpaySettings);
                string Paramters = "api/Ecom/AddRazorpaySettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }        
        public async Task<string> UpdateRazorpaySettings(RazorpaySettings razorpaySettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(razorpaySettings);
                string Paramters = "api/Ecom/UpdateRazorpaySettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> AddEmailSettings(EmailSettings emailSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(emailSettings);
                string Paramters = "api/Ecom/AddEmailSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }        
        public async Task<string> UpdateEmailSettings(EmailSettings emailSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(emailSettings);
                string Paramters = "api/Ecom/UpdateEmailSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> AddBusinessSettings(BusinessSettings businessSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(businessSettings);
                string Paramters = "api/Ecom/AddBusinessSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }        
        public async Task<string> UpdateBusinessSettings(BusinessSettings businessSettings)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(businessSettings);
                string Paramters = "api/Ecom/UpdateBusinessSettings";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }       
        public async Task<string> AddBankDetails(BankDetails bankDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(bankDetails);
                string Paramters = "api/Ecom/AddBankDetails";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> UpdateBankDetails(BankDetails bankDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(bankDetails);
                string Paramters = "api/Ecom/UpdateBankDetails";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> AddShippingDetails(ShippingDetails shippingDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(shippingDetails);
                string Paramters = "api/Ecom/AddShippingDetails";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
        public async Task<string> UpdateShippingDetails(ShippingDetails shippingDetails)
        {
            string Response;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(shippingDetails);
                string Paramters = "api/Ecom/UpdateShippingDetails";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    //Response = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                    Response = ResponseData.Result;
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                return Ex.ToString();
            }
        }
    }
}
