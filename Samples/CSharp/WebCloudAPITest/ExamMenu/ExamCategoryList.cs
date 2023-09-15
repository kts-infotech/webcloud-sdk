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
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class ExamCategoryList : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public ExamCategoryList(List<object> examInfoList, ApiTestDataUtil obj)
        {
            InitializeComponent();
            
            objTestDataUtil = obj;

            //Populate treeview
            Populate(trvMainCategories.Nodes, examInfoList);
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
                   
                    nodes.Add(parentNode);
                }

                // set the first  nodes to the Checked state
                trvMainCategories.Nodes[0].Checked = true;

            }

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
