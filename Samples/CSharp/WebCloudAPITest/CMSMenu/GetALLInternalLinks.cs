using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.CMSMenu
{
    public partial class GetALLInternalLinks : Form
    {
        public GetALLInternalLinks(LinkSettingsInfo info)
        {
            InitializeComponent();
            PopulateForm(info);
        }

        private void PopulateForm(LinkSettingsInfo info)
        {
            if(info.Success)
            {
                lbTitle.Text = "Link Title :" + info.InternalLinkTitle;
                checkShowTitle.Checked = info.ShowInternalLink;
                PopulateDataGrid(info.linkDetailList);
            }
        }

        private void PopulateDataGrid(List<LinkDetails> linkDetailList)
        {
            foreach(LinkDetails lnk in linkDetailList)
            {
                dataGridView.Rows.Add(lnk.LinkID, lnk.MenuID, lnk.MenuName, lnk.LinkName);
            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
