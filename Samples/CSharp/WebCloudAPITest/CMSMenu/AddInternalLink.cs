using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WebCloud.Api.DS;
using ProjectFrameworkAPITest;

namespace WebCloudAPITest.CMSMenu
{
    public partial class AddInternalLink : Form
    {

        WebCloudAPIForm m_ObjMainForm;
        MenuNameByID m_MenuInfo;
        string m_strMenuID;
        LinkSettingsInfo m_Info;
        public AddInternalLink(WebCloudAPIForm ObjMainForm, MenuNameByID Info)
        {
            InitializeComponent();
            m_ObjMainForm = ObjMainForm;
            m_MenuInfo = Info;
            SetMenuDetailsInListBox(Info.itemList);
            GetExistingLinks();
        }

        private async void GetExistingLinks()
        {
            try
            {
                m_Info = await m_ObjMainForm.ApiService.GetInternalLinkInfo();
                textTitle.Text = m_Info.InternalLinkTitle;
                checkShowTitle.Checked = m_Info.ShowInternalLink;
                SetExistingLinksInListBox(m_Info.linkDetailList);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }

        }
        private void SetExistingLinksInListBox(List<LinkDetails> linkDetailList)
        {
            foreach (LinkDetails lnk in linkDetailList)
            {

                listBoxLinks.Items.Add(new ItemInfo { Text = lnk.LinkName,Value = lnk});
            }
        }

        private void SetMenuDetailsInListBox(List<ItemInfo> itemList)
        {
            foreach(ItemInfo item in itemList)
            {
                listBoxMenu.Items.Add(item);
            }
            
        }

        private void listBoxMenu_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_strMenuID = (listBoxMenu.SelectedItem as ItemInfo).Value.ToString();
        }

        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            if(listBoxMenu.SelectedIndex == -1)
            {
                
                return;
            }
            foreach (ItemInfo it in listBoxLinks.Items)
            {

                LinkDetails lnks = it.Value as LinkDetails;
                if(lnks.MenuID == m_strMenuID)
                {
                    ShowMessageBox("Error", "Item Already Added");
                    return;
                }
            }
            string strSelText = (listBoxMenu.SelectedItem as ItemInfo).Text;
            LinkDetails lnk = new LinkDetails();
            lnk.MenuID = m_strMenuID;
            lnk.LinkName = (textLinkText.Text == "") ? strSelText : textLinkText.Text;
            lnk.LinkID = "";
            lnk.MenuName = strSelText;
            listBoxLinks.Items.Add(new ItemInfo { Text = lnk.LinkName, Value = lnk });
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listBoxLinks.SelectedIndex == -1)
            {
                return;
            }
            listBoxLinks.Items.Remove(listBoxLinks.SelectedItem);
        }

        private void listBoxLinks_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private async void btnUpdateTitle_Click(object sender, EventArgs e)
        {
            try
            {
                string Response = await m_ObjMainForm.ApiService.UpdateInternalLinkTitle(textTitle.Text,checkShowTitle.Checked);
                ShowMessageBox("Information", Response);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private void checkShowTitle_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            List<LinkDetails> links = new List<LinkDetails>();
            foreach (ItemInfo item in listBoxLinks.Items)
            {
                LinkDetails link = item.Value as LinkDetails;
                links.Add(link);
            }
            SendToUpdateAPI(links);
            
        }

        private async void SendToUpdateAPI(List<LinkDetails> links)
        {
            try
            {
                string Response = await m_ObjMainForm.ApiService.UpdateInternalLink(links);
                ShowMessageBox("Information", Response);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }
    }
}
