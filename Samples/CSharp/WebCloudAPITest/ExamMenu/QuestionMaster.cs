using Newtonsoft.Json;
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
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class QuestionMaster : Form
    {
        private ApiTestDataUtil objTestDataUtil;

        public QuestionMaster(List<object> examInfoList, string questions, ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;

            //Populate treeview
            Populate(trvCategories.Nodes, examInfoList);
            LoadQuestions(questions);
        }



        /// <summary>
        /// 
        /// </summary>
        /// <param name="nodes"></param>
        /// <param name="categorylists"></param>
        protected void Populate(TreeNodeCollection nodes, IList<object> examInfoList)
        {
            if (examInfoList != null)
            {
                TreeNode parentNode = null;

                //Retrieve Exam Main Category from response objects.
                Newtonsoft.Json.Linq.JArray jsonResponse1 = Newtonsoft.Json.Linq.JArray.Parse(JsonConvert.SerializeObject(examInfoList[0]));

                foreach (var mainItem in jsonResponse1)
                {
                    parentNode = new TreeNode();
                    parentNode.Text = (string)mainItem["MainCategoryName"];
                    parentNode.Tag = (string)mainItem["MainCategoryID"];
                    parentNode.ToolTipText = (string)mainItem["MainCategoryDesc"];

                    //Retrieve Exam Sub Category from response objects.
                    Newtonsoft.Json.Linq.JArray jsonResponse2 = Newtonsoft.Json.Linq.JArray.Parse(JsonConvert.SerializeObject(examInfoList[1]));

                    foreach (var subItem in jsonResponse2)
                    {
                        TreeNode childNode = new TreeNode();
                        childNode.Text = (string)subItem["SubCategoryName"];
                        childNode.Tag = (string)subItem["MainCategoryID"]+","+ (string)subItem["SubCategoryID"];
                        childNode.ToolTipText = (string)subItem["SubCategoryDesc"];

                        string[] tagKeys = childNode.Tag.ToString().Split(',').ToArray();

                        if (tagKeys[0].ToString() == parentNode.Tag.ToString())
                        {
                            parentNode.Nodes.Add(childNode);

                        }
                    }

                    nodes.Add(parentNode);
                }

                // set the first  nodes to the Checked state
                trvCategories.Nodes[0].Checked = true;

            }

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="questions"></param>
        public void LoadQuestions(string questions)
        {
            int x = 0;
            int y = 0;
            int Qno = 1;
            if (!(string.IsNullOrEmpty(questions)))
            {
                XDocument xmlDoc = XDocument.Parse(questions);
                panelq.Controls.Clear();
              

                foreach (var question in xmlDoc.Descendants("CM_OL_EXAM_QUESTION_MASTER_TB"))
                {
                    // do whatever you want to do with those items of information now
                    var control = new QMaster(question, Qno, objTestDataUtil);
                    control.Location = new Point(x, y);
                    if (!panelq.Visible)
                    {
                        panelq.Visible = true;
                    }
                    panelq.Controls.Add(control);
                    y += control.Height;
                    Qno++;
                }
            }
           

        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void trvCategories_AfterCheck(object sender, TreeViewEventArgs e)
        {
            // only do it if the node became checked:
            if (e.Node.Checked)
            {
                // for all the nodes in the tree...
                foreach (TreeNode cur_node in e.Node.TreeView.Nodes)
                {

                    if (cur_node != e.Node)
                    {
                        // ... uncheck them
                        cur_node.Checked = false;

                    }
                    foreach (TreeNode cur_sub_node in cur_node.Nodes)
                    {
                        if (cur_sub_node != e.Node)
                        {
                            // ... uncheck them
                            cur_sub_node.Checked = false;

                        }
                    }
                }


            }



        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="theNodes"></param>
        /// <returns></returns>
        private int FindCheckedNodeId(System.Windows.Forms.TreeNodeCollection theNodes)
        {
            int nodeId = 0;

            if (theNodes != null)
            {
                foreach (System.Windows.Forms.TreeNode aNode in theNodes)
                {
                    if (aNode.Checked)
                    {
                        nodeId = Convert.ToInt32(aNode.Tag);
                        return nodeId;
                    }



                }
            }

            return nodeId;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="theNodes"></param>
        /// <returns></returns>
        private int FindQuestionCategoryId(System.Windows.Forms.TreeNodeCollection theNodes)
        {
            int nodeId = 0;

            if (theNodes != null)
            {
                foreach (System.Windows.Forms.TreeNode aNode in theNodes)
                {

                    foreach (TreeNode cur_sub_node in aNode.Nodes)
                    {
                        if (cur_sub_node.Checked)
                        {
                            string[] tagKeys = cur_sub_node.Tag.ToString().Split(',').ToArray();
                            nodeId = Convert.ToInt32(tagKeys[1]);
                            return nodeId;
                        }

                    }

                }
            }

            return nodeId;
        }

        /// <summary>
        /// 
        /// </summary>
        public async void RemoveQuestions( int mainCategoryID,int questionId)
        {
            await objTestDataUtil.InvokeRemoveQuestionsAPI(mainCategoryID, questionId);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnAddQuestion_Click(object sender, EventArgs e)
        {
            int x = 0;
            int y = 0;
            var control = new QuestionCustomization(objTestDataUtil);
            control.Location = new Point(x, y);            
           
            
           
            if (!pnlQuestionCustom.Visible)
            {
                panelq.Visible = true;
            }
            
            pnlQuestionCustom.Controls.Add(control);
            y += control.Height;

            panelq.Visible = false;
            pnlQuestionCustom.Visible = true;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnViewQuestion_Click(object sender, EventArgs e)
        {
            

            //Find tag (id) of node which  is selected.
            int mainCategoryID = FindQuestionCategoryId(trvCategories.Nodes);
            var v = await objTestDataUtil.InvokeLoadQuestionPaperAPI(mainCategoryID);
            LoadQuestions(v);
            //pnlQuestionCustom.Visible = true;
            panelq.Visible = true;
            //panelq.BringToFront();
            //pnlQuestionCustom.SendToBack();


        }

        private void trvCategories_AfterCheck_1(object sender, TreeViewEventArgs e)
        {
            // only do it if the node became checked:
            if (e.Node.Checked)
            {
                // for all the nodes in the tree...
                foreach (TreeNode cur_node in e.Node.TreeView.Nodes)
                {

                    if (cur_node != e.Node)
                    {
                        // ... uncheck them
                        cur_node.Checked = false;

                    }
                    foreach (TreeNode cur_sub_node in cur_node.Nodes)
                    {
                        if (cur_sub_node != e.Node)
                        {
                            // ... uncheck them
                            cur_sub_node.Checked = false;

                        }
                    }
                }


            }


        }

        private void panelq_Scroll(object sender, ScrollEventArgs e)
        {

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
