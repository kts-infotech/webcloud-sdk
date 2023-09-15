using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;


namespace WebCloudAPITest.ForumMenu
{
    public partial class AllForms : Form
    {
        List<FormDetailsInfo> listDetails;
        public AllForms(List<FormDetailsInfo> info)
        {
            InitializeComponent();
            listDetails = info;
            foreach (FormDetailsInfo det in listDetails)
            {
                comboFormID.Items.Add(det.FormID);
            }
        }

        private void comboFormID_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = comboFormID.SelectedItem.ToString();
            FormDetailsInfo info = listDetails.Find(x => x.FormID == selection);
            lbFormName.Text = info.FormName;
            lbForumDesc.Text = info.FormDesc;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
