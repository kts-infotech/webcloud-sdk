using System;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.Properties;

namespace WebCloudAPITest.LicenseMenu
{
    public partial class LicenceTestApp : Form
    {
        
        public LicenceTestApp()
        {
            InitializeComponent();
            try
            {
                SetStatusLabel();
            }
            catch (Exception)
            {
                statusLabel.Text = "No valid key found . Please purchace a key to continue";
            }
            
            PFCrypt.Key = "KTSProducts";
        }

        private void SetStatusLabel()
        {
            if (Settings.Default.LicenseMode == "One Time")
            {
                statusLabel.Text = string.Empty;
                if(CheckRegKey(Settings.Default.RegistrationKey))
                {
                    btnClickMe.Enabled = true;
                    return;
                }
                statusLabel.Text = "No valid key found . Please purchace a key to continue";
                return;
            }
            DateTime today = DateTime.Now;
            DateTime yesterday = today.AddDays(-1);
            string strExpiryDate = yesterday.ToString();
            try
            {
                strExpiryDate = PFCrypt.Decrypt(Settings.Default.ExpirationDate);
            }
            catch (Exception)
            {

            }
            statusLabel.Text = strExpiryDate;
            
            DateTime dtExpiry = DateTime.Parse(strExpiryDate);
            int daysLeft = Convert.ToInt32((dtExpiry - today).TotalDays);
            if(daysLeft<=0)
            {
                statusLabel.Text = "Product Expired Please Purchace";
            }
            else 
            {
                statusLabel.Text = "This product will Expire in "+ daysLeft + " days";
                btnClickMe.Enabled = true;
            }
            
            //DateTime dt = DateTime.Parse(Settings.Default.ExpirationDate);

        }

        private bool CheckRegKey(string registrationKey)
        {
            string strRegGen = GenerateRegistrationKey("", "", "", "", LicenseType.OneTime, "", "");
            return registrationKey == strRegGen;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
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
    }
}
