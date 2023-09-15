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
    
    public partial class GetDetailedPageInfo : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        
        public GetDetailedPageInfo(WebCloudAPIForm ObjMainForm, IList<MenuInfo> Info)
        {
            InitializeComponent();
            m_ObjMainForm = ObjMainForm;
            SetMenuNamesInListBox(Info);
        }

        private void SetMenuNamesInListBox(IList<MenuInfo> Info)
        {
            foreach(MenuInfo item in Info)
            {
                ItemInfo Item = new ItemInfo
                {
                    Text = item.MenuName + "(" + item.MenuID + ")",
                    Value = item.MenuID
                };

                listMenuWithID.Items.Add(Item);
            }
        }

        private void listMenuWithID_SelectedIndexChanged(object sender, EventArgs e)
        {
            string strSelMenuID = (listMenuWithID.SelectedItem as ItemInfo).Value.ToString();
            RequestMenuDetails(strSelMenuID);
        }

        private async void RequestMenuDetails(string strMenuID)
        {
            try 
            {
                PageDetailsInfo Info = await m_ObjMainForm.ApiService.GetPageDetailedInfo(strMenuID);
                textBoxInfo.Text = TextBoxContent(Info);
                webBrowser.DocumentText = Info.PageDescription;
            }
            catch(Exception Ex)
            {
                MessageBox.Show(Ex.Message,"Error");
            }
        }
        private string TextBoxContent(PageDetailsInfo info)
        {
           
            DateTime myDate = new DateTime(Convert.ToInt64(info.DateTime));
            string dt = myDate.ToString();
            string content = "MenuId : " + info.MenuID + Environment.NewLine +
                            "Menu Name :" + info.MenuName + Environment.NewLine +
                            "Menu Link :" + info.MenuLink + Environment.NewLine +
                            "MenuOrder :" + info.MenuOrder + Environment.NewLine +
                            "ShowMenu :" + info.ShowMenu + Environment.NewLine +
                            "ParentID :" + info.ParentID + Environment.NewLine +
                            "MenuAvailabilityntID :" + info.MenuAvailability + Environment.NewLine +
                             "TemplateID :" + info.TemplateID + Environment.NewLine +
                             "PageHeading :" + info.PageHeading + Environment.NewLine +
                             "UseFeedbackForm :" + info.UseFeedbackForm + Environment.NewLine +
                             "UseTellAFriend :" + info.UseTellAFriend + Environment.NewLine +
                             "MenuAliasURL :" + info.MenuAliasURL + Environment.NewLine +
                             "OpenInNewWindow :" + info.OpenInNewWindow + Environment.NewLine +
                             "DateTime :" + dt + Environment.NewLine;
            return content;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
