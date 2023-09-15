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
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class AddExamCategory : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public AddExamCategory(ApiTestDataUtil obj)
        {
            objTestDataUtil = obj;
            InitializeComponent();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnAdd_Click(object sender, EventArgs e)
        {
            ExamMainCategory examMainCategory  = new ExamMainCategory();

            try
            {
                examMainCategory.MainCategoryName = txtCategoryName.Text;
                examMainCategory.MainCategoryDesc = txtDescription.Text;

                await objTestDataUtil.InvokeAddExamCategoriesAPI(examMainCategory);
            }
            catch (Exception)
            {
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
