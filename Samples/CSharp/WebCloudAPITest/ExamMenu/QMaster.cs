using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class QMaster : UserControl
    {
        private ApiTestDataUtil objTestDataUtil;

        //public QMaster(ApiTestDataUtil obj)
        //{
        //    InitializeComponent();
        //    objTestDataUtil = obj;
        //}
        /// <summary>
        /// 
        /// </summary>
        /// <param name="questions"></param>
        public QMaster(XElement question, int Qno, ApiTestDataUtil obj) /*: this()*/
        {
            InitializeComponent();
            objTestDataUtil = obj;

            objTestDataUtil = obj;
            try
            {
                int slNo = Qno;
                int Qid= Convert.ToInt32(question.Element("QuestionID").Value);
                int categoryid = Convert.ToInt32(question.Element("CategoryID").Value);
                string Question = question.Element("Question").Value;
                string Option1 = question.Element("Option1").Value;
                string Option2 = question.Element("Option2").Value;
                string Option3 = question.Element("Option3").Value;
                string Option4 = question.Element("Option4").Value;
                string Answer = question.Element("Answer").Value;
                string QuestionTitle = question.Element("QuestionTitle").Value;

                // do whatever you want to do with those items of information now
                txtQuestion.Text = Question;
                txtOption1.Text = Option1;
                txtOption2.Text = Option2;
                txtOption3.Text = Option3;
                txtOption4.Text = Option4;
                txtAnswer.Text = Answer;
                txtTitle.Text = QuestionTitle;


                lblHiddenId.Text = categoryid.ToString();
                lblHiddenQid.Text = Qid.ToString();

            }
            catch (Exception)
            {
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnEdit_Click(object sender, EventArgs e)
        {
            ExamQuestionMaster examQuestionMaster = new ExamQuestionMaster();

            int mainCategoryID = Convert.ToInt32(lblHiddenId.Text);
            int questionId = Convert.ToInt32(lblHiddenQid.Text);
            
            examQuestionMaster.CategoryID = mainCategoryID;
            examQuestionMaster.QuestionID = questionId;
            examQuestionMaster.Question = txtQuestion.Text.ToString();
            examQuestionMaster.Answer = txtAnswer.Text.ToString();
            examQuestionMaster.QuestionTitle = txtTitle.Text.ToString();
            examQuestionMaster.Option1 = txtOption1.Text.ToString();
            examQuestionMaster.Option2 = txtOption2.Text.ToString();
            examQuestionMaster.Option3 = txtOption3.Text.ToString();
            examQuestionMaster.Option4 = txtOption4.Text.ToString();
            await objTestDataUtil.InvokeUpdateQuestionAPI(examQuestionMaster);

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnRemove_Click(object sender, EventArgs e)
        {
           // QuestionMaster questionMaster = new QuestionMaster(null, null,null);
            int mainCategoryID =Convert.ToInt32(lblHiddenId.Text);
            int questionId= Convert.ToInt32(lblHiddenQid.Text);
            await objTestDataUtil.InvokeRemoveQuestionsAPI(mainCategoryID, questionId);
        }

        
    }
}
