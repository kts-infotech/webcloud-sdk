using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest.CMSMenu
{
    public partial class AddExternalLink : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        public AddExternalLink(WebCloudAPIForm objMainForm, LinkSettingsInfo info)
        {
            InitializeComponent();
            m_ObjMainForm = objMainForm;
            textTitle.Text = info.ExternalLinkTitle;
            checkShowTitle.Checked = info.ShowExternalLinks;
            SetListBoxWithExixtingLinks(info.linkDetailList);
        }

        private void SetListBoxWithExixtingLinks(List<LinkDetails> linkDetailList)
        {
            listBoxExistLinks.Items.Clear();
            List<LinkDetails> sortedList = linkDetailList.OrderBy(o => o.iOrderNo).ToList();
            foreach (LinkDetails lnk in sortedList)
            {
                listBoxExistLinks.Items.Add(new ItemInfo { Text = lnk.LinkName, Value = lnk });
            }
        }

        private void btnUpdateTitle_Click(object sender, EventArgs e)
        {
            InvokeUpdateExternalLinkTitleApi(textTitle.Text, checkShowTitle.Checked);
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {

            LinkDetails link = new LinkDetails();
            link.LinkName = textUrlName.Text;
            link.LinkUrl = textUrl.Text;
            List<int> orderNumber = new List<int>();
            foreach (ItemInfo item in listBoxExistLinks.Items)
            {
                LinkDetails lnk = item.Value as LinkDetails;
                orderNumber.Add(Convert.ToInt32(lnk.OrderNo));
            }
            link.OrderNo = (orderNumber.Max() + 1).ToString();
            InvokeAddExternalLinkApi(link);
        }



        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (listBoxExistLinks.SelectedIndex == -1)
                return;
            LinkDetails link = (LinkDetails)(listBoxExistLinks.SelectedItem as ItemInfo).Value;
            link.LinkName = textUrlName.Text;
            link.LinkUrl = textUrl.Text;
            InvokeUpdateExternalLinkApi(link);
        }


        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listBoxExistLinks.SelectedIndex == -1)
                return;
            LinkDetails link = (LinkDetails)(listBoxExistLinks.SelectedItem as ItemInfo).Value;
            InvokeDeleteExternalLink(link.LinkID);
        }

        private void btnApplyOrder_ClickAsync(object sender, EventArgs e)
        {
            List<LinkDetails> links = new List<LinkDetails>();
            for(int i=0;i<listBoxExistLinks.Items.Count;i++)
            {
                LinkDetails lnk = new LinkDetails();
                lnk = (listBoxExistLinks.Items[i] as ItemInfo).Value as LinkDetails;
                lnk.OrderNo = i.ToString();
                links.Add(lnk);
            }

            InvokeUpdateOrderExternalLinkAPI(links);
        }
        public void MoveItem(int direction)
        {
            // Checking selected item
            if (listBoxExistLinks.SelectedItem == null || listBoxExistLinks.SelectedIndex < 0)
                return; // No selected item - nothing to do

            // Calculate new index using move direction
            int newIndex = listBoxExistLinks.SelectedIndex + direction;

            // Checking bounds of the range
            if (newIndex < 0 || newIndex >= listBoxExistLinks.Items.Count)
                return; // Index out of range - nothing to do

            object selected = listBoxExistLinks.SelectedItem;

            // Removing removable element
            listBoxExistLinks.Items.Remove(selected);
            // Insert it in new position
            listBoxExistLinks.Items.Insert(newIndex, selected);
            // Restore selection
            listBoxExistLinks.SetSelected(newIndex, true);
        }
        private void btnUp_Click(object sender, EventArgs e)
        {
            MoveItem(-1);
        }

        private void btnDown_Click(object sender, EventArgs e)
        {
            MoveItem(1);
        }
        private void listBoxExistLinks_On_Click(object sender, EventArgs e)
        {
            if (listBoxExistLinks.SelectedIndex == -1)
                return;
            ItemInfo itm = listBoxExistLinks.SelectedItem as ItemInfo;
            textUrlName.Text = itm.Text;
            textUrl.Text = (itm.Value as LinkDetails).LinkUrl;
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        #region API Interface

        private async void InvokeDeleteExternalLink(string strLinkID)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.DeleteExternalLink(strLinkID);
                MessageBox.Show(result, "Information");
                InvokeAddExternalLinkAPI();
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }
        private async void InvokeUpdateExternalLinkApi(LinkDetails link)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.UpdateExternalLink(link);
                MessageBox.Show(result, "Information");
                InvokeAddExternalLinkAPI();
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }
        private async void InvokeAddExternalLinkApi(LinkDetails link)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.AddExternalLink(link);
                MessageBox.Show(result, "Information");
                InvokeAddExternalLinkAPI();
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }
        private async void InvokeUpdateExternalLinkTitleApi(string strDefaultTitle, bool ShowExternalLink)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.UpdateExternalLinkTitle(strDefaultTitle, ShowExternalLink);
                MessageBox.Show(result, "Information");
                InvokeAddExternalLinkAPI();
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }
        }
        public async void InvokeAddExternalLinkAPI()
        {
            try
            {
                LinkSettingsInfo Info = await m_ObjMainForm.ApiService.GetExternalLinkInfo();
                SetListBoxWithExixtingLinks(Info.linkDetailList);
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }

        }

        public async void InvokeUpdateOrderExternalLinkAPI(List<LinkDetails> links)
        {
            try
            {
                string result = await m_ObjMainForm.ApiService.UpdateOrderExternalLink(links);
                m_ObjMainForm.SetRequestData(links);
                MessageBox.Show(result, "Information");
                
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message, "Error");
            }

        }

        #endregion

       
    }
}
