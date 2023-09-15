using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using ProjectFrameworkAPITest;
using WebCloudAPITest.Properties;
using Newtonsoft.Json;
using System.Collections;
using System.Globalization;
using System.Resources;

namespace WebCloudAPITest.LicenseMenu
{
    public partial class GetLicenseInfo : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        public GetLicenseInfo(WebCloudAPIForm objMainForm)
        {
            InitializeComponent();
            textMacID.Text = GetUniqueHardwareId();
            m_ObjMainForm = objMainForm;
            combPrdts.Items.Clear();
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
                    combPrdts.Items.Add(new ItemInfo { Text = key,Value= value });
                }

            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private async void btnLicenceInfo_Click(object sender, EventArgs e)
        {
            if (combPrdts.SelectedIndex == -1)
                return;
            string selectPrdt = (combPrdts.SelectedItem as ItemInfo).Value.ToString();
            LicenseInfo res = await m_ObjMainForm.ApiService.GetLicenseInfo(selectPrdt, textMacID.Text.Trim());
            if (res == null)
            {
                textResponse.Text = "Product not Found";
                return;
            }
            string strContent = "LicenseStatus : " + res.LicenseStatus + Environment.NewLine +
                                "Machine Name : " + res.MachineName + Environment.NewLine +
                                "Product Name : " + res.ProductName + Environment.NewLine +
                                "Product ID : " + res.ProductID + Environment.NewLine +
                                "EmailID : " + res.EmailID + Environment.NewLine +
                                "Is Unlimited License : " + res.IsUnlimitedLicense.ToString() + Environment.NewLine +
                                "License Name : " + res.LicenseName + Environment.NewLine +
                                "No Of Days : " + res.NoOfDays + Environment.NewLine +
                                "Date of Entry : " + res.EntryDate.ToString() + Environment.NewLine +
                                "Reg Key : " + res.RegKey + Environment.NewLine +
                                "Email Status : " + res.EmailStatus + Environment.NewLine +
                                "Person Name : " + res.PersonName + Environment.NewLine +
                                "License Password : " + res.LicensePassword + Environment.NewLine +
                                "Hardware ID : " + res.HardwareID + Environment.NewLine +
                                "License ID : " + res.LicenseID + Environment.NewLine +
                                "Remaining Days : " + res.RemainingDays + Environment.NewLine +
                                "Allowed Features : " + res.AdditionalSubscriptionInfo.AllowedFeatures + Environment.NewLine +
                                "Disabled Features : " + res.AdditionalSubscriptionInfo.DisabledFeatures + Environment.NewLine +
                                "Initial License : " + res.AdditionalSubscriptionInfo.InitialLicense + Environment.NewLine +
                                "Product Subscription Id : " + res.AdditionalSubscriptionInfo.ProductSubscriptionId + Environment.NewLine;

            textResponse.Text = strContent;
            //textResponse.Text =  JsonConvert.SerializeObject(res);
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
    }
}
