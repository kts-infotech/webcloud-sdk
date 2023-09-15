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

namespace WebCloudAPITest
{
    public partial class UCCopyQuestions : UserControl
    {
        public UCCopyQuestions()
        {
            InitializeComponent();
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="questions"></param>
        public UCCopyQuestions(XElement question, int Qno,bool isSelect) : this()
        {

            try
            {
                chkSelect.Checked = isSelect;
                int slNo = Qno;
                int Qid = Convert.ToInt32(question.Element("QuestionID").Value);
                int categoryid = Convert.ToInt32(question.Element("CategoryID").Value);
                string Question = question.Element("Question").Value;
                string Option1 = question.Element("Option1").Value;
                string Option2 = question.Element("Option2").Value;
                string Option3 = question.Element("Option3").Value;
                string Option4 = question.Element("Option4").Value;

                // do whatever you want to do with those items of information now
                lblQuestion.Text = slNo + "." + Question;
                rbOption1.Text = Option1;
                rbOption2.Text = Option2;
                rbOption3.Text = Option3;
                rbOption4.Text = Option4;
                lblHiddenId.Text = categoryid.ToString();
                lblHiddenQid.Text = Qid.ToString();

            }
            catch (Exception)
            {
            }
        }
       
    }
}
