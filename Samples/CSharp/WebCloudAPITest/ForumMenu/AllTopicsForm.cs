using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class AllTopicsForm : Form
    {
        List<Topics> listDetails;
        public AllTopicsForm(List<Topics> info)
        {
            InitializeComponent();
            listDetails = info;
            foreach (Topics det in listDetails)
            {
                comboFormID.Items.Add(det.TopicID);
            }
        }

        private void comboFormID_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = comboFormID.SelectedItem.ToString();
            Topics info = listDetails.Find(x => x.TopicID == selection);
            lbFormName.Text = info.TopicName;
            lbForumDesc.Text = info.TopicDesc;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
