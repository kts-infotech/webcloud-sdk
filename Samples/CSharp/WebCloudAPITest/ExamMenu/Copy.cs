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
    public partial class Copy : Form
    {
        private ApiTestDataUtil objTestDataUtil;

        public Copy(List<object> examInfoList, ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;

            //Populate treeview
            Populate(trvSource.Nodes, examInfoList);
            Populate(trvDestination.Nodes, examInfoList);
           
            lblDefaultText.Text = "No Questions found.Please select any sub-category from source.";
            lblDefaultText.ForeColor = Color.Red;
          
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="nodes"></param>
        /// <param name="categorylists"></param>
        protected void Populate(TreeNodeCollection nodes, IList<object> examInfoList)
        {
            try
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
                            childNode.Tag = (string)subItem["MainCategoryID"] + "," + (string)subItem["SubCategoryID"];
                            childNode.ToolTipText = (string)subItem["SubCategoryDesc"];

                            string[] tagKeys = childNode.Tag.ToString().Split(',').ToArray();

                            if (tagKeys[0].ToString() == parentNode.Tag.ToString())
                            {
                                parentNode.Nodes.Add(childNode);

                            }
                        }

                        nodes.Add(parentNode);
                    }

                }
            }
            catch (Exception)
            {
            }

        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="questions"></param>
        public void LoadQuestions(string questions, bool isSelectAll)
        {
            int x = 0;
            int y = 0;
            int Qno = 1;

            try
            {
                if (!(string.IsNullOrEmpty(questions)))
                {
                    lblDefaultText.Visible = false;
                    chkSelectAll.Visible = true;
                    XDocument xmlDoc = XDocument.Parse(questions);
                    panelq.Controls.Clear();
                    foreach (var question in xmlDoc.Descendants("CM_OL_EXAM_QUESTION_MASTER_TB"))
                    {
                        // do whatever you want to do with those items of information now
                        var control = new UCCopyQuestions(question, Qno, isSelectAll);
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
                else
                {

                    lblDefaultText.Visible = true;
                    chkSelectAll.Visible = false;
                    lblDefaultText.Text = "No question(s) found for the selected category.";

                    if (!panelq.Visible)
                    {
                        panelq.Visible = true;
                    }

                }

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
        private async void btnCopy_Click(object sender, EventArgs e)
        {

            try
            {
                //Check if any destinaton is selected or not
                if (IsSelectAnyDestination(trvDestination.Nodes))
                {
                    int sourceCategoryId = FindQuestionCategoryId(trvSource.Nodes);
                    int destinationCategoryId = FindQuestionCategoryId(trvDestination.Nodes);

                    if (chkSelectAll.Checked)
                    {
                        //...Copy Entire questions 
                        await objTestDataUtil.InvokeCopyAllQuestionsAPI(sourceCategoryId, destinationCategoryId);
                    }
                    else
                    {                        
                        List<WebCloud.Api.DS.ExamQuestionMaster> lstexamQuestionMaster = new List<WebCloud.Api.DS.ExamQuestionMaster>();

                        foreach (Control usercontrol in this.panelq.Controls)
                        {

                            if (usercontrol is UCCopyQuestions)
                            {
                                var CheckBoxmatches = usercontrol.Controls.Find("chkSelect", true);
                                CheckBox chk = CheckBoxmatches.FirstOrDefault() as CheckBox;

                                if (chk.Checked)
                                {
                                    WebCloud.Api.DS.ExamQuestionMaster examQuestionMaster = new WebCloud.Api.DS.ExamQuestionMaster();

                                    //get qid,category id
                                    Label lblCategory = usercontrol.Controls.Find("lblHiddenId", true).FirstOrDefault() as Label;
                                    Label lblQuestionId = usercontrol.Controls.Find("lblHiddenQid", true).FirstOrDefault() as Label;

                                    examQuestionMaster.CategoryID = Convert.ToInt32(lblCategory.Text);
                                    examQuestionMaster.QuestionID = Convert.ToInt32(lblQuestionId.Text);

                                    lstexamQuestionMaster.Add(examQuestionMaster);
                                }
                            }
                        }
                       
                        //Copy selected questions
                        await objTestDataUtil.InvokeCopySelectedQuestionsAPI(lstexamQuestionMaster, destinationCategoryId);


                    }
                }
                else
                {
                    lblWarning.Text = "* Please select any Destinaton.";
                }
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
        private void trvSource_AfterCheck(object sender, TreeViewEventArgs e)
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
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void trvDestination_AfterCheck(object sender, TreeViewEventArgs e)
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
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnViewQuestion_Click(object sender, EventArgs e)
        {
            try
            {
                //Find tag (id) of node which  is selected.
                int mainCategoryID = FindQuestionCategoryId(trvSource.Nodes);
                var v = await objTestDataUtil.InvokeLoadQuestionPaperAPI(mainCategoryID);
                bool isSelectAll = false;

                if (chkSelectAll.Checked)
                {
                    isSelectAll = true;
                }

                LoadQuestions(v, isSelectAll);
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
        private async void chkSelectAll_CheckedChanged(object sender, EventArgs e)
        {
            //Find tag (id) of node which  is selected.
            int mainCategoryID = FindQuestionCategoryId(trvSource.Nodes);
            var v = await objTestDataUtil.InvokeLoadQuestionPaperAPI(mainCategoryID);
            bool isSelectAll = false;
            
            if (chkSelectAll.Checked)
            {
                isSelectAll = true;
            }
            LoadQuestions(v, isSelectAll);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="theNodes"></param>
        /// <returns></returns>
        private bool IsSelectAnyDestination(System.Windows.Forms.TreeNodeCollection theNodes)
        {
            bool isselected = false;

            if (theNodes != null)
            {
                foreach (System.Windows.Forms.TreeNode aNode in theNodes)
                {

                    foreach (TreeNode cur_sub_node in aNode.Nodes)
                    {
                        if (cur_sub_node.Checked)
                        {
                            isselected = true;
                            return isselected;
                        }
                        

                    }

                }
            }

            return isselected;
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
