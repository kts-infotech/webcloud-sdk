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
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class ImportQuestions : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public ImportQuestions(ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
            txtImportDataType.Text = "Online Exam Data";
            txtImportDataType.Enabled = false;
        }

        private async void btnViewList_Click(object sender, EventArgs e)
        {

            try
            {     
                string userName = txtUserName.Text.ToString();
                string password = txtPassword.Text.ToString();
                string url = txtWebsiteUrl.Text.ToString();

                if (string.IsNullOrEmpty(userName))
                {
                    lblValidateusernameMsg.Visible = true;
                    lblValidateusernameMsg.Text = "Enter a valid username.";
                    lblValidateusernameMsg.ForeColor = Color.Red;
                }

                if (string.IsNullOrEmpty(password))
                {
                    lblValidatePassMsg.Visible = true;
                    lblValidatePassMsg.Text = "Enter a valid password.";
                    lblValidatePassMsg.ForeColor = Color.Red;
                }

                if (string.IsNullOrEmpty(url))
                {
                    lblValidateurlMsg.Visible = true;
                    lblValidateurlMsg.Text = "Enter a website url.";
                    lblValidateurlMsg.ForeColor = Color.Red;
                }
                if (!string.IsNullOrEmpty(userName) && !string.IsNullOrEmpty(password) && !string.IsNullOrEmpty(url))
                {
                    pnlImportDat.Visible = true;
                    //pass userid,password,website Url as parameter in webservice named
                    //fetch exam data from the  entered website url.

                    List<object> importDataList = await objTestDataUtil.InvokeGetWSDataAPI(userName, password, url);

                    //Exam :=>
                    //List count : Main category info+Sub category info ie,2
                    if (importDataList.Count == 2)
                    {
                        trvImportData.Visible = true;
                        Populate(trvImportData.Nodes, importDataList);

                        lblValidateusernameMsg.Text = "";
                        lblValidatePassMsg.Text = "";
                        lblValidateurlMsg.Text = "";
                    }
                    else
                    {
                        //Retrieve Import data error from response objects.
                        Newtonsoft.Json.Linq.JArray jsonResponse = Newtonsoft.Json.Linq.JArray.Parse(JsonConvert.SerializeObject(importDataList[0]));
                        lblStatus.Visible = true;

                        foreach (var errorItem in jsonResponse)
                        {
                            lblStatus.Text = (string)errorItem["Error"];
                            lblStatus.ForeColor = Color.Red;

                            return;
                        }


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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void btnImport_Click(object sender, EventArgs e)
        {
            ImportData importParameters = new ImportData();
            lblStatus.Visible = true;
            try
            {
                //Fetch the import params info
                string userName = txtUserName.Text.ToString();
                string password = txtPassword.Text.ToString();
                string url = txtWebsiteUrl.Text.ToString();
               
                importParameters.strUserName = userName;
                importParameters.strPassword = password;
                importParameters.url = url;                
                importParameters = FindTreeNodeInfo(trvImportData.Nodes, importParameters);

                string importResult = await objTestDataUtil.InvokeImportWSQuestionAPI(importParameters);
                lblStatus.Text = importResult;
            }
            catch (Exception) 
            {
            }
        }

        private void trvImportData_AfterCheck(object sender, TreeViewEventArgs e)
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
        private ImportData FindTreeNodeInfo(System.Windows.Forms.TreeNodeCollection theNodes, ImportData importParameters)
        {
            int nodeId = 0;
           
            if (theNodes != null)
            {
                foreach (System.Windows.Forms.TreeNode aNode in theNodes)
                {
                    if(!(aNode.Checked))
                    {
                        foreach (TreeNode cur_sub_node in aNode.Nodes)
                        {
                            if (cur_sub_node.Checked)
                            {

                                string[] tagKeys = cur_sub_node.Tag.ToString().Split(',').ToArray();
                                nodeId = Convert.ToInt32(tagKeys[1]);
                                importParameters.mainCategoryId = Convert.ToInt32(tagKeys[0]);
                                importParameters.mainCategoryName = aNode.Text;
                                importParameters.mainCatDesc = aNode.ToolTipText;

                                importParameters.subCategoryID = nodeId;
                                importParameters.subCategoryName = cur_sub_node.Text;
                                importParameters.subCatDesc = cur_sub_node.ToolTipText;
                                return importParameters;
                            }

                        }
                    }
                    else
                    {
                        importParameters.mainCategoryId = Convert.ToInt32(aNode.Tag);
                        importParameters.mainCategoryName = aNode.Text;
                        importParameters.mainCatDesc = aNode.ToolTipText;
                       
                        return importParameters;
                    }
            

                }
            }

            return importParameters;
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
