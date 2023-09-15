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

namespace WebCloudAPITest.CMSMenu
{
    public partial class ListAllPageInfoWithLinks : Form
    {
        public ListAllPageInfoWithLinks(IList<MenuInfo> Info)
        {
            InitializeComponent();
            AddDataToGridView(Info);
        }

        private void AddDataToGridView(IList<MenuInfo> Info)
        {
            foreach(MenuInfo info in Info)
            {
                gridViewAllPageInfo.Rows.Add(info.MenuID,info.ParentID, info.MenuName,info.ShowMenu,info.MenuLink,info.AliasURLLink,info.PageHeading);
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
