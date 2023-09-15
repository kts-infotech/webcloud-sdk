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
using ProjectFrameworkAPITest;

namespace WebCloudAPITest.CMSMenu
{
    public partial class SetSeoPageInfo : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        List<SEODPageDetails> m_PageDetailList;
        int m_iMenuID;
        public SetSeoPageInfo(WebCloudAPIForm ObjMainForm, IList<MenuInfo> Info)
        {
            InitializeComponent();
            m_ObjMainForm = ObjMainForm;
            m_iMenuID = 0;
            m_PageDetailList = new List<SEODPageDetails>();
            SetMenuNamesInListBox(Info);
            GetDefaultSEOSettings();
        }

        private async void GetDefaultSEOSettings()
        {
            try
            {
                SEODPageDetails Info = await m_ObjMainForm.ApiService.GetDefaultSEOSettings();
                txtDftDesc.Text = Info.DefaultMetaDescription;
                txtDftKeyWords.Text = Info.DefaultMetaKeywords;
                txtDftTitle.Text = Info.DefaultPageTitle;
                chckEnableAlias.Checked = Info.IsAliasingEnabled;
                GetSEOSettings();
            }
            catch(Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }
        private async void GetSEOSettings()
        {
            try
            {
                m_PageDetailList = await m_ObjMainForm.ApiService.GetSeoSettings();
                /*m_ObjMainForm.SetResponseData(m_PageDetailList);
                m_ObjMainForm.SetRequestURL(m_ObjMainForm.ApiService.SubmitURL);*/
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        
        private void SetMenuNamesInListBox(IList<MenuInfo> Info)
        {
            foreach (MenuInfo item in Info)
            {
                ItemInfo Item = new ItemInfo
                {
                    Text = item.MenuName + "(" + item.MenuID + ")",
                    Value = item.MenuID
                };

                listMenuWithID.Items.Add(Item);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private async void btnDfltUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                SEODPageDetails Info = new SEODPageDetails();
                Info.DefaultMetaDescription= txtDftDesc.Text;
                Info.DefaultMetaKeywords= txtDftKeyWords.Text;
                Info.DefaultPageTitle= txtDftTitle.Text;
                Info.IsAliasingEnabled=chckEnableAlias.Checked;

                string response = await m_ObjMainForm.ApiService.SetSeoPageInfo(Info);;
                ShowMessageBox("Information", response);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private void btnDfltReset_Click(object sender, EventArgs e)
        {
            txtDftDesc.Text = "";
            txtDftKeyWords.Text = "";
            txtDftTitle.Text = "";
        }

        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }

        private void listMenuWithID_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selection = (listMenuWithID.SelectedItem as ItemInfo).Text;
            string strMenuID = (listMenuWithID.SelectedItem as ItemInfo).Value.ToString();
            m_iMenuID = Convert.ToInt32(strMenuID);
            lbSelectedPage.Text = "Selected Page :" + selection;
            foreach (SEODPageDetails Info in m_PageDetailList)
            {
                if(Info.MenuID == m_iMenuID)
                {
                    txtTitle.Text = Info.DefaultPageTitle;
                    txtDesc.Text = Info.DefaultMetaDescription;
                    txtKeyWords.Text = Info.DefaultMetaKeywords;
                    chkEnableSocialSharing.Checked = Info.SocialSharingSettings.EnableSocialSharing;
                    chkFB.Checked = Info.SocialSharingSettings.EnableFbSharing;
                    chkLinkedIn.Checked = Info.SocialSharingSettings.EnableGooglePlusSharing;
                    chkWhatsUP.Checked = Info.SocialSharingSettings.EnableWhatsAppSharing;
                    chkFinTip.Checked = Info.SocialSharingSettings.EnableFTOSharing;
                    chkTwiter.Checked = Info.SocialSharingSettings.EnableTwitterSharing;
                }
            }
        }

        private async void btnSiUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                SEODPageDetails Info = new SEODPageDetails();

                Info.MenuID = m_iMenuID;
                Info.DefaultPageTitle= txtTitle.Text;
                Info.DefaultMetaDescription= txtDesc.Text;
                Info.DefaultMetaKeywords=txtKeyWords.Text;
                Info.UseDefaultSeoDetails = chkUseDfltSeoDetails.Checked;
                Info.SocialSharingSettings.EnableSocialSharing= chkEnableSocialSharing.Checked;
                Info.SocialSharingSettings.EnableFbSharing = chkFB.Checked;
                Info.SocialSharingSettings.EnableGooglePlusSharing = chkLinkedIn.Checked;
                Info.SocialSharingSettings.EnableWhatsAppSharing = chkWhatsUP.Checked;
                Info.SocialSharingSettings.EnableFTOSharing = chkFinTip.Checked;
                Info.SocialSharingSettings.EnableTwitterSharing = chkTwiter.Checked;

                string response = await m_ObjMainForm.ApiService.SetSeoPageInfo(Info);
                ShowMessageBox("Information", response);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private void btnSiReset_Click(object sender, EventArgs e)
        {
            txtTitle.Text = "";
            txtDesc.Text = "";
            txtKeyWords.Text = "";
            chkEnableSocialSharing.Checked = false;
            chkUseDfltSeoDetails.Checked = false;
        }
    }
}
