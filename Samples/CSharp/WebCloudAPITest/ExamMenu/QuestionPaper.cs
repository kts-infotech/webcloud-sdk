using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Linq;

namespace WebCloudAPITest
{
    public partial class QuestionPaper : UserControl
    {
        public QuestionPaper()
        {
            InitializeComponent();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="questions"></param>
        public QuestionPaper(XElement question,int Qno) : this()
        {          

            try
            {              
                int slNo = Qno;
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
               
            }
            catch (Exception)
            {
            }
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="categoryId"></param>
        public Panel  LoadQuestions(string questions)
        {
            Panel panel = new Panel();
            
            try
            {
                XDocument xmlDoc = XDocument.Parse(questions);
                
                foreach (var question in xmlDoc.Descendants("CM_OL_EXAM_QUESTION_MASTER_TB"))
                {
                    QuestionPaper questionPaper = new QuestionPaper();
                    int slNo = 1;
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
                    slNo++;
                    panel.Controls.Add(questionPaper);
                }
                
            }
            catch (Exception)
            {
            }
            return panel;
        }

        public static explicit operator QuestionPaper(XElement v)
        {
            throw new NotImplementedException();
        }

        protected override void OnLoad(EventArgs e)
        {
            //Your code to run on load goes here 

            // Call the base class OnLoad to ensure any delegate event handlers are still callled
            base.OnLoad(e);
        }
    }
}
