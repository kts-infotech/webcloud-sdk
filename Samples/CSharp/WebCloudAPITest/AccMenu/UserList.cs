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
    public partial class UserList : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Info"></param>
         public UserList(List<UserAccountInfo> allUserLists, ApiTestDataUtil obj)
        {
            try
            {
                InitializeComponent();
                objTestDataUtil = obj;
                DataTable dtUserList = new DataTable();
                dtUserList = ConvertToDataTable(allUserLists);
                grdUserList.DataSource = dtUserList;
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
            dataTable.Columns.Remove("IsActive");
            return dataTable;
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
