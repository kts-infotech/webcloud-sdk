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
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class CompanyListForm : Form
    {
        private List<VenderInfo> m_objCompanyDetails;
        private ApiTestDataUtil objTestDataUtil;
        public CompanyListForm(TestData.ApiTestDataUtil api, List<VenderInfo> CompanyList)
        {
            m_objCompanyDetails = CompanyList;
            objTestDataUtil = api;
            InitializeComponent();
        }

        public void SetComboBox(List<VenderInfo> CompanyList)
        {
            comCompanyList.DisplayMember = "Text";
            comCompanyList.ValueMember = "Value";
            comCompanyList.Items.Add(new { Text = "Select", Value = "0" });
            comCompanyList.SelectedIndex = 0;
            foreach (VenderInfo Company in CompanyList)
            {
                comCompanyList.Items.Add(new { Text = Company.VenderCompanyName, Value = Company.VenderUserId });
            }
        }

        private void comCompanyList_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string VendorCompanyId = (comCompanyList.SelectedItem as dynamic).Value;
                if (!VendorCompanyId.Equals("0"))
                {
                    txtCompanyDetails.Text = JsonConvert.SerializeObject(m_objCompanyDetails.Where(x => x.VenderUserId == VendorCompanyId));
                }
                else
                {
                    txtCompanyDetails.Text = "";
                }
            }
            catch (Exception)
            {

            }
        } 

        private void CompanyListForm_Load(object sender, EventArgs e)
        {
            try
            {
                SetComboBox(m_objCompanyDetails);
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
