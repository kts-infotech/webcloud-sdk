using System;
using System.Collections.Generic;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest.CMSMenu
{
    public partial class AddDelFooter : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        string m_strMenuID;
        string m_strMenuName;
        string m_strLinkID;
        public AddDelFooter(WebCloudAPIForm objMainForm, FooterInfoList info)
        {
            InitializeComponent();
            m_ObjMainForm = objMainForm;
            SetListBoxWithMenuItems(info.MenuList);
            SetListBoxWithFooterItems(info.FooterList);
        }

        private void SetListBoxWithFooterItems(List<FooterDetails> footerList)
        {
            listBoxExistingFtrs.Items.Clear();
            foreach (FooterDetails ftr in footerList)
            {
                ItemInfo item = new ItemInfo
                {
                    Text = ftr.LinkName,
                    Value = ftr
                };

                listBoxExistingFtrs.Items.Add(item);
            }
        }

        private void SetListBoxWithMenuItems(List<ItemInfo> menuList)
        {

            foreach (ItemInfo item in menuList)
            {
                listBoxMenus.Items.Add(item);
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            if (listBoxMenus.SelectedIndex == -1)
                return;
            string strLinkName = (textLinkName.Text.Trim() == "") ? m_strMenuName : textLinkName.Text.Trim();
            InvokeAddFooter(strLinkName, m_strMenuID);
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listBoxExistingFtrs.SelectedIndex == -1)
                return;
            InvokeDeleteFootersAPI(m_strLinkID);

        }

        private void listBoxMenus_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxMenus.SelectedIndex == -1)
                return;
            ItemInfo selectedItem = listBoxMenus.SelectedItem as ItemInfo;
            m_strMenuID = selectedItem.Value.ToString();
            m_strMenuName = selectedItem.Text;
        }
        private void listBoxExistingFtrs_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxExistingFtrs.SelectedIndex == -1)
                return;
            ItemInfo selectedItem = listBoxExistingFtrs.SelectedItem as ItemInfo;
            m_strLinkID = (selectedItem.Value as FooterDetails).LinkID;
        }

        #region API Interface

        private async void InvokeAddFooter(string strLinkName, string strMenuID)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.AddFooter(strLinkName, strMenuID);
                InvokeGetAllFootersAPI();
                textLinkName.Clear();
                MessageBox.Show(result, "Information");

            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        public async void InvokeGetAllFootersAPI()
        {
            try
            {
                FooterInfoList Info = await m_ObjMainForm.ApiService.GetAllFooters();
                SetListBoxWithFooterItems(Info.FooterList);

            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        public async void InvokeDeleteFootersAPI(string strLinkID)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.DeleteFooter(strLinkID);
                MessageBox.Show(result, "Information");
                InvokeGetAllFootersAPI();

            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        #endregion


    }
}
