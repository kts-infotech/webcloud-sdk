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
    public partial class GetSeoPageInfo : Form
    {
        WebCloudAPIForm m_ObjMainForm;
        public GetSeoPageInfo(WebCloudAPIForm ObjMainForm, List<SEODPageDetails> Info)
        {
            InitializeComponent();
            m_ObjMainForm = ObjMainForm;
            SetMenuIDsInComboBox(Info);
        }

        private void SetMenuIDsInComboBox(List<SEODPageDetails> listInfo)
        {
            foreach(SEODPageDetails Info in listInfo)
            {
                ItemInfo item = new ItemInfo
                {
                    Text = Info.MenuID.ToString(),
                    Value = Info
                };
                comboMenuIDs.Items.Add(item);
            }
        }
        private void comboMenuIDs_SelectedIndexChanged(object sender, EventArgs e)
        {
            SEODPageDetails info = ((comboMenuIDs.SelectedItem as ItemInfo).Value as SEODPageDetails);
            textBoxInfo.Text = TextBoxContent(info);
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private string TextBoxContent(SEODPageDetails info)
        {

            string content = "MenuId : " + info.MenuID.ToString() + Environment.NewLine +
                            "DefaultPageTitle :" + info.DefaultPageTitle + Environment.NewLine +
                            "DefaultMetaDescription :" + info.DefaultMetaDescription + Environment.NewLine +
                            "DefaultMetaKeywords :" + info.DefaultMetaKeywords + Environment.NewLine +
                            "IsAliasingEnabled :" + info.IsAliasingEnabled + Environment.NewLine;
                            
            return content;

        }


    }
}
