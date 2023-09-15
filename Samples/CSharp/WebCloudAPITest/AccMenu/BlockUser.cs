using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest
{
    public partial class BlockUser : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private string status = string.Empty;
        /// <summary>
        /// 
        /// </summary>
        /// <param name="allUserLists"></param>
        /// <param name="obj"></param>
        public BlockUser(List<UserAccountInfo> allUserLists, ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
            
            //Bind Gridview 
            DataTable dtUserList = new DataTable();
            dtUserList = ConvertToDataTable(allUserLists);            
            grdUserList.DataSource = dtUserList;

            //Gridview Button Column Initialization
            ButtonColumnInitialization();

        }

        /// <summary>
        /// 
        /// </summary>
        public void ButtonColumnInitialization()
        {
            try
            {
                ////Button column Initialization
                var buttonCol = new DataGridViewButtonColumn();
                buttonCol.Name = "btnStatus";
                buttonCol.HeaderText = "Click";                
                grdUserList.Columns.Add(buttonCol);

            }
            catch (Exception)
            {

            }
            
        }

        
        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="models"></param>
        /// <returns></returns>
        public DataTable ConvertToDataTable<T>(List<T> models)
        {
            DataTable dataTable = new DataTable(typeof(T).Name);
            
            //Get all the properties of that model  
            PropertyInfo[] Props = typeof(T).GetProperties(BindingFlags.Public | BindingFlags.Instance);

            // Loop through all the properties              
            // Adding Column name to our datatable  
            foreach (PropertyInfo prop in Props)
            {
                // if(prop.Name!= "Password" || prop.Name != "LastName")
                //Setting column names as Property names    
                dataTable.Columns.Add(prop.Name);
            }
            // Adding Row and its value to our dataTable  
            foreach (T item in models)
            {
                var values = new object[Props.Length];
                for (int i = 0; i < Props.Length; i++)
                {
                    //inserting property values to datatable rows    
                    values[i] = Props[i].GetValue(item, null);
                }
                // Finally add value to datatable    
                dataTable.Rows.Add(values);


            }
            dataTable.Columns.Remove("Password");
            dataTable.Columns.Remove("LastName");
            
            return dataTable;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void grdUserList_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 0)
            {
                MessageBox.Show((e.RowIndex + 1) + "  Row  " + (e.ColumnIndex + 1) +
                "  Column button clicked ");
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void grdUserList_CellFormatting_1(object sender, DataGridViewCellFormattingEventArgs e)
        {
           
            //If this is header row or new row, do nothing
            if (e.RowIndex < 0 || e.RowIndex == this.grdUserList.NewRowIndex)
                return;

            if (e.ColumnIndex == this.grdUserList.Columns["Status"].Index)
            {
                //Get the 'Status' column value
                status = e.Value.ToString();
            }

            //If formatting your desired column, set the value
            if (e.ColumnIndex == this.grdUserList.Columns["btnStatus"].Index)
            {

               //Set 'Text' of the button dynamically based on the status value.
                if (status.ToLower() == "blocked")
                {
                    e.Value = "UnBlock";

                }
                if (status.ToLower() == "unblocked")
                {
                    e.Value = "Block";

                }
                
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void grdUserList_CellClick_1(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                UserAccountInfo blockOrUnblockUser = new UserAccountInfo();

                if (e.ColumnIndex == 0)
                {
                    DataGridViewCell emailCell = (DataGridViewCell)grdUserList.Rows[e.RowIndex].Cells["Email"];
                    DataGridViewButtonCell buttonCell = (DataGridViewButtonCell)grdUserList.Rows[e.RowIndex].Cells["btnStatus"];
                   
                    if(buttonCell.FormattedValue!=null)
                    {
                        if (emailCell != null)
                        {
                            var emailID = emailCell.Value.ToString();
                            blockOrUnblockUser.Email = emailID;
                           
                            if (buttonCell.FormattedValue.ToString().ToLower() == "block")
                            {
                                //Here the code for update IsActive=false in user table 
                                blockOrUnblockUser.IsActive = false;
                                
                                await objTestDataUtil.InvokeBlockOrUnBlockUserAPI(blockOrUnblockUser);
                                MessageBox.Show("Successfully blocked this user.");
                            }
                            if (buttonCell.FormattedValue.ToString().ToLower() == "unblock")
                            {
                                //Here the code for update IsActive=true in user table 
                                blockOrUnblockUser.IsActive = true;
                               
                                await objTestDataUtil.InvokeBlockOrUnBlockUserAPI(blockOrUnblockUser);
                                MessageBox.Show("Successfully unblock this user.");
                            }

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
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
