using System;
using System.Collections.Generic;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest.CMSMenu
{
    public partial class AddDelHeader : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        string m_strMenuID;
        string m_strMenuName;
        string m_strLinkID;
        public AddDelHeader(WebCloudAPIForm objMainForm, HeaderInfoList info)
        {
            InitializeComponent();
            m_ObjMainForm = objMainForm;
            SetListBoxWithMenuItems(info.MenuList);
            SetListBoxWithHeaderItems(info.HeaderList);
        }

        private void SetListBoxWithHeaderItems(List<HeaderDetails> headerList)
        {
            listBoxExistingHdrs.Items.Clear();
            foreach (HeaderDetails hdr in headerList)
            {
                ItemInfo item = new ItemInfo
                {
                    Text = hdr.LinkName,
                    Value= hdr
                };

                listBoxExistingHdrs.Items.Add(item);
            }
        }

        private void SetListBoxWithMenuItems(List<ItemInfo> menuList)
        {
            
            foreach(ItemInfo item in menuList)
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
            InvokeAddHeader(strLinkName, m_strMenuID);
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listBoxExistingHdrs.SelectedIndex == -1)
                return;
            InvokeDeleteHeadersAPI(m_strLinkID);

        }

        private void listBoxMenus_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxMenus.SelectedIndex == -1)
                return;
            ItemInfo selectedItem = listBoxMenus.SelectedItem as ItemInfo;
            m_strMenuID = selectedItem.Value.ToString(); 
            m_strMenuName = selectedItem.Text;
        }
        private void listBoxExistingHdrs_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxExistingHdrs.SelectedIndex == -1)
                return;
            ItemInfo selectedItem = listBoxExistingHdrs.SelectedItem as ItemInfo;
            m_strLinkID = (selectedItem.Value as HeaderDetails).LinkID;
        }

        #region API Interface

        private async void InvokeAddHeader(string strLinkName, string strMenuID)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.AddHeader(strLinkName, strMenuID);
                InvokeGetAllHeadersAPI();
                textLinkName.Clear();
                MessageBox.Show(result, "Information");
                
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        public async void InvokeGetAllHeadersAPI()
        {
            try
            {
                HeaderInfoList Info = await m_ObjMainForm.ApiService.GetAllHeaders();
                SetListBoxWithHeaderItems(Info.HeaderList);

            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        public async void InvokeDeleteHeadersAPI(string strLinkID)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.DeleteHeader(strLinkID);
                MessageBox.Show(result, "Information");
                InvokeGetAllHeadersAPI();

            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }

        #endregion


    }
}
