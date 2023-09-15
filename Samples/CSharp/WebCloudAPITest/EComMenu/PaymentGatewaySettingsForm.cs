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
    public partial class PaymentGatewaySettingsForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private List<VenderInfo> objCompanyList;  
        public PaymentGatewaySettingsForm(ApiTestDataUtil apiTestDataUtil, List<VenderInfo> companyList)
        {
            InitializeComponent();
            this.objTestDataUtil = apiTestDataUtil;
            this.objCompanyList = companyList;
        }
        public PaymentGatewaySettingsForm()
        {
        }
        private void PaymentGatewaySettingsForm_Load(object sender, EventArgs e)
        {
            try
            {
                SetComboBox(objCompanyList);
                panelBankDetails.Visible = false;
                panelBusinessSettings.Visible = false;
                panelEmailSettings.Visible = false;
                panelPayPalSettings.Visible = false;
                panelPayUMoneySettings.Visible = false;
                panelRazorpaySettings.Visible = false;
                panelShippingDetails.Visible = false;
                panelStripeSettings.Visible = false;
                panelBankDetails.Location = panelPayPalSettings.Location;
                panelBusinessSettings.Location = panelPayPalSettings.Location;
                panelEmailSettings.Location = panelPayPalSettings.Location;
                panelPayUMoneySettings.Location = panelPayPalSettings.Location;
                panelRazorpaySettings.Location = panelPayPalSettings.Location;
                panelShippingDetails.Location = panelPayPalSettings.Location;
                panelStripeSettings.Location = panelPayPalSettings.Location;
                //PaymentGatewaySettingsForm form = new PaymentGatewaySettingsForm();
                //form.Size = new Size(250, 200);
            }
            catch (Exception)
            {
               
            }
        }             
        private void comCompany_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //PayPalSettings
                    if (rbPayPalSettings.Checked)
                    {
                        panelPayPalSettings.Visible = true;
                        LoadPaypalSettings(VendorId);
                    }
                    else
                    {
                        panelPayPalSettings.Visible = false;
                    }
                    //PayUMoneySettings
                    if (rbPayUMoneySettings.Checked)
                    {
                        panelPayUMoneySettings.Visible = true;
                        LoadPayUMoneySettings(VendorId);
                    }
                    else
                    {
                        panelPayUMoneySettings.Visible = false;
                    }
                    //StripeSettings
                    if (rbStripe.Checked)
                    {
                        panelStripeSettings.Visible = true;
                        LoadStripeSettings(VendorId);
                    }
                    else
                    {
                        panelStripeSettings.Visible = false;
                    }
                    //RazorpaySettings
                    if (rbRazorpay.Checked)
                    {
                        panelRazorpaySettings.Visible = true;
                        LoadRazorpaySettings(VendorId);
                    }
                    else
                    {
                        panelRazorpaySettings.Visible = false;
                    }
                    //EmailSettings
                    if (rbEMailSettings.Checked)
                    {
                        panelEmailSettings.Visible = true;
                        LoadEMailSettings(VendorId);
                    }
                    else
                    {
                        panelEmailSettings.Visible = false;
                    }
                    //BusinessSettings
                    if (rbBusinessSettings.Checked)
                    {
                        panelBusinessSettings.Visible = true;
                        LoadBusinessSettings(VendorId);
                    }
                    else
                    {
                        panelBusinessSettings.Visible = false;
                    }
                    //BankDetails
                    if (rbBankDetails.Checked)
                    {
                        panelBankDetails.Visible = true;
                        LoadBankDetails(VendorId);
                    }
                    else
                    {
                        panelBankDetails.Visible = false;
                    }
                    //ShippingDetails
                    if (rbShippingDetails.Checked)
                    {
                        panelShippingDetails.Visible = true;
                        LoadShippingDetails(VendorId);
                    }
                    else
                    {
                        panelShippingDetails.Visible = false;
                    }
                }
                else
                {
                    //Visible false all panels.
                    panelBankDetails.Visible = false;
                    panelBusinessSettings.Visible = false;
                    panelEmailSettings.Visible = false;
                    panelPayPalSettings.Visible = false;
                    panelPayUMoneySettings.Visible = false;
                    panelRazorpaySettings.Visible = false;
                    panelShippingDetails.Visible = false;
                    panelStripeSettings.Visible = false;
                }
            }
            catch (Exception)
            {
               
            }
        }
        public async void LoadPaypalSettings(string VendorId)
        {
            PayPalSettings payPalSettings = await objTestDataUtil.MainForm.ApiService.GetPayPalSettings(VendorId);            
            if (payPalSettings.PaypalClientID != null)
            {
                txtClientId.Text = payPalSettings.PaypalClientID;
                txtClientSecretKey.Text = payPalSettings.PaypalClientSecretKey;
                if (payPalSettings.EnablePaypal)
                {
                    cbEnablePaypal.Checked = true;
                }
                else
                {
                    cbEnablePaypal.Checked = false;
                }
                btnSavePayPalSettings.Text = "Update Settings";
            }
            else
            {
                txtClientId.Text = string.Empty;
                txtClientSecretKey.Text = string.Empty;
                cbEnablePaypal.Checked = false;
                btnSavePayPalSettings.Text = "Save Settings";
            }
        }       
        public async void LoadPayUMoneySettings(string VendorId)
        {
            PayUMoneySettings payUMoneySettings = await objTestDataUtil.MainForm.ApiService.GetPayUMoneySettings(VendorId);
            if (payUMoneySettings.MerchantID != null)
            {
                txtMerchantId.Text = payUMoneySettings.MerchantID;
                txtMerchantKey.Text = payUMoneySettings.MerchantKey;
                txtSalt.Text = payUMoneySettings.Salt;
                if (payUMoneySettings.EnablePayumoney)
                {
                    cbEnablePayumoney.Checked = true;
                }
                else
                {
                    cbEnablePayumoney.Checked = false;
                }
                btnSavePayumoney.Text = "Update Settings";
            }
            else
            {
                txtMerchantId.Text = string.Empty;
                txtMerchantKey.Text = string.Empty;
                txtSalt.Text = string.Empty;
                cbEnablePayumoney.Checked = false;
                btnSavePayumoney.Text = "Save Settings";
            }
        }        
        public async void LoadStripeSettings(string VendorId)
        {
            StripeSettings stripeSettings = await objTestDataUtil.MainForm.ApiService.GetStripeSettings(VendorId);
            if (stripeSettings.SecretKey != null)
            {
                txtStripeSecretKey.Text = stripeSettings.SecretKey;
                txtPublishableKey.Text = stripeSettings.PublishableKey;
                if (stripeSettings.EnableStripeSettings)
                {
                    cbEnableStripe.Checked = true;
                }
                else
                {
                    cbEnableStripe.Checked = false;
                }
                btnSaveStripeSettings.Text = "Update Settings";
            }
            else
            {
                txtStripeSecretKey.Text = string.Empty;
                txtPublishableKey.Text = string.Empty;
                cbEnableStripe.Checked = false;
                btnSaveStripeSettings.Text = "Save Settings";
            }
        }       
        public async void LoadRazorpaySettings(string VendorId)
        {
            RazorpaySettings razorpaySettings = await objTestDataUtil.MainForm.ApiService.GetRazorpaySettings(VendorId);
            if (razorpaySettings.RazorpayKeyID != null)
            {
                txtKeyID.Text = razorpaySettings.RazorpayKeyID;
                txtKeySecret.Text = razorpaySettings.RazorpayKeySecret;
                if (razorpaySettings.EnableRazorpaySettings)
                {
                    cbEnableRazorpay.Checked = true;
                }
                else
                {
                    cbEnableRazorpay.Checked = false;
                }
                btnSaveRazorpaySettings.Text = "Update Settings";
            }
            else
            {
                txtKeyID.Text = string.Empty;
                txtKeySecret.Text = string.Empty;
                cbEnableRazorpay.Checked = false;
                btnSaveRazorpaySettings.Text = "Save Settings";
            }
        }
        public async void LoadEMailSettings(string VendorId)
        {           
            EmailSettings emailSettings = await objTestDataUtil.MainForm.ApiService.GetEMailSettings(VendorId);
            if (emailSettings.AdminEmail != null)
            {
                txtAdminEmail.Text = emailSettings.AdminEmail;
                txtSupportEmail.Text = emailSettings.SupportEmail;
                txtBusinessEmail.Text = emailSettings.BusinessEmail;
                txtDefaultEmail.Text = emailSettings.DefaultEmail;               
                btnSaveEmailSettings.Text = "Update Settings";
            }
            else
            {
                txtAdminEmail.Text = string.Empty;
                txtSupportEmail.Text = string.Empty;
                txtBusinessEmail.Text = string.Empty;
                txtDefaultEmail.Text = string.Empty;
                btnSaveEmailSettings.Text = "Save Settings";
            }
        }        
        public async void LoadBusinessSettings(string VendorId)
        {
            BusinessSettings businessSettings = await objTestDataUtil.MainForm.ApiService.GetBusinessSettings(VendorId);
            if (businessSettings.OrganizationName != null)
            {
                txtOrganizationName.Text = businessSettings.OrganizationName;
                txtAddress.Text = businessSettings.Address;
                txtPinCode.Text = businessSettings.PinCode;
                txtPhoneNo1.Text = businessSettings.PhoneNo1;
                txtPhoneNo2.Text = businessSettings.PhoneNo2;
                txtFaxNo.Text = businessSettings.FaxNo;
                txtWebSiteURL.Text = businessSettings.WebSiteURL;                
                btnSaveBusinessSettings.Text = "Update Settings";
            }
            else
            {
                txtOrganizationName.Text = string.Empty;
                txtAddress.Text = string.Empty;
                txtPinCode.Text = string.Empty;
                txtPhoneNo1.Text = string.Empty;
                txtPhoneNo2.Text = string.Empty;
                txtFaxNo.Text = string.Empty;
                txtWebSiteURL.Text = string.Empty;
                btnSaveBusinessSettings.Text = "Save Settings";
            }
        }       
        public async void LoadBankDetails(string VendorId)
        {
            BankDetails bankDetails = await objTestDataUtil.MainForm.ApiService.GetBankDetails(VendorId);
            if (bankDetails.BankName != null)
            {
                txtBankName.Text = bankDetails.BankName;
                txtAccountNo.Text = bankDetails.AccountNo;
                txtSWIFTIFSCCode.Text = bankDetails.SWIFTIFSCCodeBankAddress;
                txtOrderRequestEmail.Text = bankDetails.OrderRequestEmail;
                if (bankDetails.EnableBankTransfer)
                {
                    cbEnableBankTransfer.Checked = true;
                }
                else
                {
                    cbEnableBankTransfer.Checked = false;
                }                
                btnSaveBankDetails.Text = "Update Settings";
            }
            else
            {
                txtBankName.Text = string.Empty;
                txtAccountNo.Text = string.Empty;
                txtSWIFTIFSCCode.Text = string.Empty;
                txtOrderRequestEmail.Text = string.Empty;
                cbEnableBankTransfer.Checked = false;
                btnSaveBankDetails.Text = "Save Settings";
            }
        }
        public async void LoadShippingDetails(string VendorId)
        {
            ShippingDetails shippingDetails = await objTestDataUtil.MainForm.ApiService.GetShippingDetails(VendorId);
            if (shippingDetails.ShippingAddress != null)
            {
                txtShippingAddress.Text = shippingDetails.ShippingAddress;
                txtEmailAddress.Text = shippingDetails.EmailAddress;
                txtPhoneNumber.Text = shippingDetails.PhoneNumber;               
                btnSaveShippingDetails.Text = "Update Settings";
            }
            else
            {
                txtShippingAddress.Text = string.Empty;
                txtEmailAddress.Text = string.Empty;
                txtPhoneNumber.Text = string.Empty;               
                btnSaveShippingDetails.Text = "Save Settings";            
            }
        }
        public bool ValidateData()
        {
            if (comCompany.SelectedIndex == 0)
            {
                MessageBox.Show("Select Company");
                return false;
            }
            return true;
        }
        public bool ValidatePayPalSettings()
        {
            if (String.IsNullOrEmpty(txtClientId.Text))
            {
                MessageBox.Show("Enter Client Id");
                return false;
            }
            else if (String.IsNullOrEmpty(txtClientSecretKey.Text))
            {
                MessageBox.Show("Enter Client SecretKey");
                return false;
            }
            return true;
        }
        public bool ValidatePayumoneySettings()
        {
            if (String.IsNullOrEmpty(txtMerchantId.Text))
            {
                MessageBox.Show("Enter Merchant Id");
                return false;
            }
            else if (String.IsNullOrEmpty(txtMerchantKey.Text))
            {
                MessageBox.Show("Enter Merchant Key");
                return false;
            }
            //else if (String.IsNullOrEmpty(txtSalt.Text))
            //{
            //    MessageBox.Show("Enter Salt");
            //    return false;
            //}
            return true;
        }
        public bool ValidateStripeSettings()
        {
            if (String.IsNullOrEmpty(txtStripeSecretKey.Text))
            {
                MessageBox.Show("Enter Stripe Secret Key");
                return false;
            }
            else if (String.IsNullOrEmpty(txtPublishableKey.Text))
            {
                MessageBox.Show("Enter Publishable Key");
                return false;
            }
            return true;
        }
        public bool ValidateRazorpaySettings()
        {
            if (String.IsNullOrEmpty(txtAdminEmail.Text))
            {
                MessageBox.Show("Enter Admin Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtSupportEmail.Text))
            {
                MessageBox.Show("Enter Support Email");
                return false;
            }
            else if(String.IsNullOrEmpty(txtBusinessEmail.Text))
            {
                MessageBox.Show("Enter Business Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtDefaultEmail.Text))
            {
                MessageBox.Show("Enter Default Email");
                return false;
            }
            return true;
        }        
        public bool ValidateEmailSettings()
        {
            if (String.IsNullOrEmpty(txtAdminEmail.Text))
            {
                MessageBox.Show("Enter Admin Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtSupportEmail.Text))
            {
                MessageBox.Show("Enter Support Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtBusinessEmail.Text))
            {
                MessageBox.Show("Enter Business Email");
                return false;
            }
            else if (String.IsNullOrEmpty(txtDefaultEmail.Text))
            {
                MessageBox.Show("Enter Default Email");
                return false;
            }
            return true;
        }
        public bool ValidateBusinessSettings()
        {
            if (String.IsNullOrEmpty(txtOrganizationName.Text))
            {
                MessageBox.Show("Enter Organization Name");
                return false;
            }
            else if (String.IsNullOrEmpty(txtAddress.Text))
            {
                MessageBox.Show("Enter Address");
                return false;
            }
            else if (String.IsNullOrEmpty(txtPinCode.Text))
            {
                MessageBox.Show("Enter PinCode");
                return false;
            }
            else if (String.IsNullOrEmpty(txtPhoneNo1.Text))
            {
                MessageBox.Show("Enter PhoneNo1");
                return false;
            }
            return true;
        }       
        public bool ValidateBankDetails()
        {
            if (String.IsNullOrEmpty(txtBankName.Text))
            {
                MessageBox.Show("Enter Bank Name");
                return false;
            }
            else if (String.IsNullOrEmpty(txtAccountNo.Text))
            {
                MessageBox.Show("Enter Account No");
                return false;
            }
            else if (String.IsNullOrEmpty(txtSWIFTIFSCCode.Text))
            {
                MessageBox.Show("Enter SWIFT | IFSC | Code & Bank Address");
                return false;
            }
            else if (String.IsNullOrEmpty(txtOrderRequestEmail.Text))
            {
                MessageBox.Show("Enter Order Request Email");
                return false;
            }
            return true;
        }        
        public bool ValidateShippingDetails()
        {
            if (String.IsNullOrEmpty(txtShippingAddress.Text))
            {
                MessageBox.Show("Enter Shipping Address");
                return false;
            }
            else if (String.IsNullOrEmpty(txtEmailAddress.Text))
            {
                MessageBox.Show("Enter Email Address");
                return false;
            }
            else if (String.IsNullOrEmpty(txtPhoneNumber.Text))
            {
                MessageBox.Show("Enter txtPhone Number");
                return false;
            }            
            return true;
        }
        private async void btnSavePayPalSettings_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidatePayPalSettings())
                {
                    string result = string.Empty;
                    PayPalSettings payPalSettings = new PayPalSettings();
                    payPalSettings.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    payPalSettings.PaypalClientID = txtClientId.Text;
                    payPalSettings.PaypalClientSecretKey = txtClientSecretKey.Text;
                    if (cbEnablePaypal.Checked)
                    {
                        payPalSettings.EnablePaypal = true;
                    }
                    else
                    {
                        payPalSettings.EnablePaypal = false;
                    }
                    if (btnSavePayPalSettings.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddPayPalSettingsAPI(payPalSettings);
                    }
                    if (btnSavePayPalSettings.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdatePayPalSettingsAPI(payPalSettings);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadPaypalSettings(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception)
            {
               
            }
        }             
        private async void btnSavePayumoney_Click(object sender, EventArgs e)
        {
            try
            {
                if(ValidatePayumoneySettings())
                {
                    string result = string.Empty;
                    PayUMoneySettings payUMoneySettings = new PayUMoneySettings();
                    payUMoneySettings.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    payUMoneySettings.MerchantID = txtMerchantId.Text;
                    payUMoneySettings.MerchantKey = txtMerchantKey.Text;
                    payUMoneySettings.Salt = txtSalt.Text;
                    if (cbEnablePayumoney.Checked)
                    {
                        payUMoneySettings.EnablePayumoney = true;
                    }
                    else
                    {
                        payUMoneySettings.EnablePayumoney = false;
                    }                    
                    if (btnSavePayumoney.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddPayumoneySettingsAPI(payUMoneySettings);
                    }
                    if (btnSavePayumoney.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdatePayumoneySettingsAPI(payUMoneySettings);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadPayUMoneySettings(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {
               
            }
        }       
        private async void btnSaveStripeSettings_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateStripeSettings())
                {
                    string result = string.Empty;
                    StripeSettings stripeSettings = new StripeSettings();
                    stripeSettings.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    stripeSettings.SecretKey = txtStripeSecretKey.Text;
                    stripeSettings.PublishableKey = txtPublishableKey.Text;
                    if (cbEnableStripe.Checked)
                    {
                        stripeSettings.EnableStripeSettings = true;
                    }
                    else
                    {
                        stripeSettings.EnableStripeSettings = false;
                    }                    
                    if (btnSaveStripeSettings.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddStripeSettingsAPI(stripeSettings);
                    }
                    if (btnSaveStripeSettings.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdateStripeSettingsAPI(stripeSettings);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadStripeSettings(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {

            }
        }
        private async void btnSaveRazorpaySettings_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateRazorpaySettings())
                {
                    string result = string.Empty;
                    RazorpaySettings razorpaySettings = new RazorpaySettings();
                    razorpaySettings.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    razorpaySettings.RazorpayKeyID = txtKeyID.Text;
                    razorpaySettings.RazorpayKeySecret = txtKeySecret.Text;
                    if (cbEnableRazorpay.Checked)
                    {
                        razorpaySettings.EnableRazorpaySettings = true;
                    }
                    else
                    {
                        razorpaySettings.EnableRazorpaySettings = false;
                    }
                    if (btnSavePayPalSettings.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddRazorpaySettingsAPI(razorpaySettings);
                    }
                    if (btnSavePayPalSettings.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdateRazorpaySettingsAPI(razorpaySettings);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadRazorpaySettings(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {

            }
        }       
        private async void btnSaveEmailSettings_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateEmailSettings())
                {
                    string result = string.Empty;
                    EmailSettings emailSettings = new EmailSettings();
                    emailSettings.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    emailSettings.AdminEmail = txtAdminEmail.Text;
                    emailSettings.BusinessEmail = txtBusinessEmail.Text;
                    emailSettings.DefaultEmail = txtDefaultEmail.Text;
                    emailSettings.SupportEmail = txtSupportEmail.Text;
                    
                    if (btnSaveEmailSettings.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddEmailSettingsAPI(emailSettings);
                    }
                    if (btnSaveEmailSettings.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdateEmailSettingsAPI(emailSettings);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadEMailSettings(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {

            }
        }
        private async void btnSaveBusinessSettings_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateBusinessSettings())
                {
                    string result = string.Empty;
                    BusinessSettings businessSettings = new BusinessSettings();
                    businessSettings.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    businessSettings.OrganizationName = txtOrganizationName.Text;
                    businessSettings.Address = txtAddress.Text;
                    businessSettings.PinCode = txtPinCode.Text;
                    businessSettings.PhoneNo1 = txtPhoneNo1.Text;
                    businessSettings.PhoneNo2 = txtPhoneNo2.Text;
                    businessSettings.FaxNo = txtFaxNo.Text;
                    businessSettings.WebSiteURL = txtWebSiteURL.Text;
                    if (btnSaveBusinessSettings.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddBusinessSettingsAPI(businessSettings);
                    }
                    if (btnSaveBusinessSettings.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdateBusinessSettingsSettingsAPI(businessSettings);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadBusinessSettings(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {

            }
        }
        private async void btnSaveBankDetails_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateBankDetails())
                {
                    string result = string.Empty;
                    BankDetails bankDetails = new BankDetails();
                    bankDetails.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    bankDetails.BankName = txtBankName.Text;
                    bankDetails.AccountNo = txtAccountNo.Text;
                    bankDetails.SWIFTIFSCCodeBankAddress = txtSWIFTIFSCCode.Text;
                    bankDetails.OrderRequestEmail = txtOrderRequestEmail.Text;
                    if (cbEnableBankTransfer.Checked)
                    {
                        bankDetails.EnableBankTransfer = true;
                    }
                    else
                    {
                        bankDetails.EnableBankTransfer = false;
                    }
                    if (btnSaveBankDetails.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddBankDetailsAPI(bankDetails);
                    }
                    if (btnSaveBankDetails.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdateBankDetailsAPI(bankDetails);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadBankDetails(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {

            }
        }
        private async void btnSaveShippingDetails_Click(object sender, EventArgs e)
        {
            try
            {
                if (ValidateShippingDetails())
                {
                    string result = string.Empty;
                    ShippingDetails shippingDetails = new ShippingDetails();
                    shippingDetails.VendorId = (comCompany.SelectedItem as dynamic).Value;
                    shippingDetails.ShippingAddress = txtShippingAddress.Text;
                    shippingDetails.EmailAddress = txtEmailAddress.Text;
                    shippingDetails.PhoneNumber = txtPhoneNumber.Text;   
                    if (btnSaveShippingDetails.Text.Equals("Save Settings"))
                    {
                        //Insert Data
                        result = await objTestDataUtil.InvokeAddShippingDetailsAPI(shippingDetails);
                    }
                    if (btnSaveShippingDetails.Text.Equals("Update Settings"))
                    {
                        //Update Data
                        result = await objTestDataUtil.InvokeUpdateShippingDetailsAPI(shippingDetails);
                    }
                    if (result.Contains("Data saved Successfully"))
                    {
                        string VendorId = (comCompany.SelectedItem as dynamic).Value;
                        LoadShippingDetails(VendorId);
                        MessageBox.Show("Data saved Successfully");
                    }
                }
            }
            catch (Exception )
            {

            }
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
        private void rbPayPalSettings_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                { 
                    //PayPalSettings
                    if (rbPayPalSettings.Checked)
                    {
                        panelPayPalSettings.Visible = true;
                        LoadPaypalSettings(VendorId);
                    }
                    else
                    {
                        panelPayPalSettings.Visible = false;
                    }
                }
                else
                { 
                    panelPayPalSettings.Visible = false;                   
                }
            }
            catch (Exception )
            {

            }
        }
        private void rbPayUMoneySettings_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //PayUMoneySettings
                    if (rbPayUMoneySettings.Checked)
                    {
                        panelPayUMoneySettings.Visible = true;
                        LoadPayUMoneySettings(VendorId);
                    }
                    else
                    {
                        panelPayUMoneySettings.Visible = false;
                    }
                }
                else
                {
                    panelPayUMoneySettings.Visible = false;
                }
            }
            catch (Exception )
            {
                
            }
        }
        private void rbStripe_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //StripeSettings
                    if (rbStripe.Checked)
                    {
                        panelStripeSettings.Visible = true;
                        LoadStripeSettings(VendorId);
                    }
                    else
                    {
                        panelStripeSettings.Visible = false;
                    }
                }
                else
                {
                    panelStripeSettings.Visible = false;
                }
            }
            catch (Exception )
            {
               
            }
        }
        private void rbRazorpay_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //RazorpaySettings
                    if (rbRazorpay.Checked)
                    {
                        panelRazorpaySettings.Visible = true;
                        LoadRazorpaySettings(VendorId);
                    }
                    else
                    {
                        panelRazorpaySettings.Visible = false;
                    }
                }
                else
                {
                    panelRazorpaySettings.Visible = false;
                }
            }
            catch (Exception )
            {

                
            }
        }
        private void rbEMailSettings_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //EmailSettings
                    if (rbEMailSettings.Checked)
                    {
                        panelEmailSettings.Visible = true;
                        LoadEMailSettings(VendorId);
                    }
                    else
                    {
                        panelEmailSettings.Visible = false;
                    }
                }
                else
                {
                    panelEmailSettings.Visible = false;
                }

            }
            catch (Exception )
            {
                
            }
        }
        private void rbBusinessSettings_CheckedChanged(object sender, EventArgs e)
        {
            try
            {           
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //BusinessSettings
                    if (rbBusinessSettings.Checked)
                    {
                        panelBusinessSettings.Visible = true;
                        LoadBusinessSettings(VendorId);
                    }
                    else
                    {
                        panelBusinessSettings.Visible = false;
                    }
                }
                else
                {
                    panelBusinessSettings.Visible = false;
                }
            }
            catch (Exception )
            {
               
            }
        }
        private void rbBankDetails_CheckedChanged(object sender, EventArgs e)
        {
            try
            {           
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //BankDetails
                    if (rbBankDetails.Checked)
                    {
                        panelBankDetails.Visible = true;
                        LoadBankDetails(VendorId);
                    }
                    else
                    {
                        panelBankDetails.Visible = false;
                    }
                }
                else
                {
                    panelBankDetails.Visible = false;
                }
            }
            catch (Exception )
            {

            }
        }
        private void rbShippingDetails_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorId = (comCompany.SelectedItem as dynamic).Value;
                if (!VendorId.Equals("0"))
                {
                    //ShippingDetails
                    if (rbShippingDetails.Checked)
                    {
                        panelShippingDetails.Visible = true;
                        LoadShippingDetails(VendorId);
                    }
                    else
                    {
                        panelShippingDetails.Visible = false;
                    }
                }
                else
                {
                    panelShippingDetails.Visible = false;
                }
            }
            catch (Exception )
            {

            }
        }        
    }
}
