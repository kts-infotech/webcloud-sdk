using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.CMSMenu
{
    public partial class GetALLExternalLinks : Form
    {
        public GetALLExternalLinks(LinkSettingsInfo info)
        {
            InitializeComponent();
            PopulateForm(info);
        }
        private void PopulateForm(LinkSettingsInfo info)
        {
            if (info.Success)
            {
                lbTitle.Text = "Link Title :" + info.ExternalLinkTitle;
                checkShowTitle.Checked = info.ShowExternalLinks;
                PopulateDataGrid(info.linkDetailList);
            }
        }

        private void PopulateDataGrid(List<LinkDetails> linkDetailList)
        {
            foreach (LinkDetails lnk in linkDetailList)
            {
                
                dataGridView.Rows.Add(lnk.LinkID, lnk.LinkUrl, lnk.LinkName, lnk.OrderNo);
            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
