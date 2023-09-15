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
    public partial class QuestionCustomization : UserControl
    {
        private ApiTestDataUtil objTestDataUtil;
        public QuestionCustomization(ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnAdd_Click(object sender, EventArgs e)
        {
            ExamQuestionMaster examQuestionMaster = new ExamQuestionMaster();

            examQuestionMaster.CategoryID = 1;
            examQuestionMaster.Question = txtQuestion.Text.ToString();
            examQuestionMaster.Answer = txtAnswer.Text.ToString();
            examQuestionMaster.QuestionTitle = txtTitle.Text.ToString();
            examQuestionMaster.Option1 = txtOption1.Text.ToString();
            examQuestionMaster.Option2 = txtOption2.Text.ToString();
            examQuestionMaster.Option3 = txtOption3.Text.ToString();
            examQuestionMaster.Option4 = txtOption4.Text.ToString();

            await objTestDataUtil.InvokeAddQuestionAPI(examQuestionMaster);
        }

        private void txtOption2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
