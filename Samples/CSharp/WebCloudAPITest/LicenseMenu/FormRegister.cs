using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Management;
using System.Net.NetworkInformation;
using WebCloudAPITest.Properties;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;
using System.Resources;
using System.Collections;


namespace WebCloudAPITest.LicenseMenu
{
    public partial class FormRegister : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        LicenseType m_LType;
        public FormRegister(WebCloudAPIForm ObjMainForm)
        {
            InitializeComponent();
            m_ObjMainForm = ObjMainForm;
            textMacID.Text = GetUniqueHardwareId();
            textEmail.Text = ObjMainForm.GetUserID();
            textUrl.Text = ObjMainForm.GetMainURL();
            comboRegType.SelectedIndex = 0;
            comboRegType.Select();
            FetchResourceData();
        }

        private void FetchResourceData()
        {
            ResourceSet resources = Resources.ResourceManager.GetResourceSet(new System.Globalization.CultureInfo("en"), true, true);
            IDictionaryEnumerator resourceList = resources.GetEnumerator();
            while (resourceList.MoveNext())

            {
                if (resourceList.Value.GetType() == typeof(string))
                {
                    string key = (string)resourceList.Key;
                    string value = (string)resourceList.Value;
                    combPrdts.Items.Add(new ItemInfo { Text = key, Value = value });
                }

            }
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            
            this.Close();
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            if (combPrdts.SelectedIndex == -1)
                return;
            string selectPrdt = (combPrdts.SelectedItem as ItemInfo).Value.ToString();
            NewUserRegInfo Info = new NewUserRegInfo
            {
                CustomerName = textName.Text,
                ProductSubID = selectPrdt,
                HardwareID = textMacID.Text,
                PhoneNo = textPh.Text,
                EmailID = textEmail.Text,
                Address = textAddress.Text,
                RegKey = textRegKey.Text,
            };
            switch(comboRegType.SelectedIndex)
            {
                case 0:
                    RequestTrialVersion(Info);
                    break;
                case 1:
                    RequestOneTimeReg(Info);
                    break;
                case 2:
                    RequestSubscription(Info);
                    break;
            }
            
        }

        private async void RequestSubscription(NewUserRegInfo info)
        {
            
            try
            {
                string result = await m_ObjMainForm.ApiService.RequestSubscription(info);
                MessageBox.Show(result, "Info");
                ValidateActivation();
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.ToString(), "Info");
            }
        }

        private async void RequestOneTimeReg(NewUserRegInfo info)
        {
            
            try
            {
                string result = await m_ObjMainForm.ApiService.RequestOneTimeReg(info);
                MessageBox.Show(result, "Info");
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.ToString(), "Info");
            }
        }

        private async void RequestTrialVersion(NewUserRegInfo info)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.RegisterNewLicense(info);
                MessageBox.Show(result, "Info");
                ValidateActivation();
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.ToString(), "Info");
            }
        }

        public string GetUniqueHardwareId()
        {
            List<string> mac = new List<string>();
            foreach (NetworkInterface nic in NetworkInterface.GetAllNetworkInterfaces())
            {
                mac.Add(nic.GetPhysicalAddress().ToString());
            }
            return mac[0];
        }

        public string GenerateRegistrationKey(string ProductCode, string ProductName, string ProductVersion,
                                                string RegistrationName, LicenseType LType,
                                                string Reserved1, string Reserved2)
        {
            //Registration key generation logic to be created in app as well as webcloud backend registration key generator dll.
            //Currently  we are returning "123456XYZ" only
            //Below Sample Call to dll

            /*ProductLicense licenseData = new ProductLicense();
            return licenseData.GenerateRegistrationKey(ProductCode, ProductName, ProductVersion, RegistrationName, LType,Reserved1, Reserved2);
            */
            return "123456XYZ";
        }

        private void comboRegType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboRegType.SelectedItem.ToString() == "One Time")
            {
                m_LType = LicenseType.OneTime;
                textRegKey.Enabled = true;
            }
            else if (comboRegType.SelectedItem.ToString() == "Subscription")
            {
                m_LType = LicenseType.Subscription;
                textRegKey.Enabled = true;
            }
            else
            {
                textRegKey.Enabled = false;
                return;
            }
            //textRegKey.Text = GetRegistrationKey();
        }

        private string GetRegistrationKey()
        {
            string ProductCode = (combPrdts.SelectedItem as ItemInfo).Value.ToString();
            string ProductName = (combPrdts.SelectedItem as ItemInfo).Text;
            string ProductVersion = "1.0";
            string RegistrationName = textMacID.Text.Trim();
            string Reserved1 = "";
            string Reserved2 = "";
            return GenerateRegistrationKey(ProductCode, ProductName, ProductVersion,
                                    RegistrationName, m_LType, Reserved1, Reserved2);
        }

        private void btnValidate_Click(object sender, EventArgs e)
        {
            ValidateActivation();
        }

        private async void ValidateActivation()
        {
            if (combPrdts.SelectedIndex == -1)
            {
                MessageBox.Show("Please Select a Product", "Info");
                return;
            }
            if (comboRegType.SelectedIndex == 1)
            {
                if (textRegKey.Text == GetRegistrationKey())
                {
                    ActivateProduct("UNLIMITED");
                    MessageBox.Show("Product Activated Successfully", "Success");
                    return;
                }
                MessageBox.Show("Enter a valid Key", "Failed");
                return;
            }
            string strPdtSubscriptionId = (combPrdts.SelectedItem as ItemInfo).Value.ToString();
            try
            {

                LicenseInfo info = await m_ObjMainForm.ApiService.GetLicenseInfo(strPdtSubscriptionId, textMacID.Text);
                if (info != null)
                {
                    DateTime today = DateTime.Now;
                    DateTime dtExpiry = today.AddDays(Convert.ToInt32(info.RemainingDays));
                    ActivateProduct(dtExpiry.ToString());
                    MessageBox.Show(info.RemainingDays + "days balance", "Info");
                }
                else
                    MessageBox.Show("No Product License Found", "Info");
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.ToString(), "Info");
            }
        }
        private void ActivateProduct(string strExpiryDate)
        {
            PFCrypt.Key = "KTSProducts";
            Settings.Default.LicenseMode = comboRegType.SelectedItem.ToString();
            Settings.Default.RegistrationKey = textRegKey.Text;
            Settings.Default.RegistrationName = textMacID.Text;
            Settings.Default.UserName = textEmail.Text;
            Settings.Default.ExpirationDate = PFCrypt.Encrypt(strExpiryDate);
            Settings.Default.Save();
        }

        private void btnBuy_Click(object sender, EventArgs e)
        {
            if (combPrdts.SelectedIndex == -1)
            {
                MessageBox.Show("Please Select a Product", "Info");
                return;
            }

            string strweburl = textUrl.Text.Trim();
            string strBuyRenew = "buy-renew.aspx?productsubid=";
            string strName = "&HardwareID=";
            string strUserID = "&userid=";
            string strComputerName = "&ComputerName=";
            string strProductCode = (combPrdts.SelectedItem as ItemInfo).Value.ToString();
            string strRegistrtionName = textMacID.Text.Trim();
            string ComputerName = Environment.MachineName;
            string UserID = "";
            string strUrl;
            strUrl = strweburl + "//" + strBuyRenew + strProductCode + strName + strRegistrtionName + strUserID + UserID + strComputerName + ComputerName;
            System.Diagnostics.Process.Start(strUrl);
        }

    }
}
