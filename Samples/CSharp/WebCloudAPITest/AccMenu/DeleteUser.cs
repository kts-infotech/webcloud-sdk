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
using WstWebServiceImpl;

namespace WebCloudAPITest
{
    public partial class DeleteUser : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        public DeleteUser(ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
        }

        public void SetComboBox(List<UserAccountInfo> result)
        {
            try
            {
                DataTable dtUserInfo = ConvertToDataTable(result);

                cbDelUser.DataSource = dtUserInfo;
                cbDelUser.DisplayMember = "Firstname";
                cbDelUser.ValueMember = "Email";
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
          
            return dataTable;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void button1_Click(object sender, EventArgs e)
        {
            string emailId = cbDelUser.SelectedValue.ToString();
            await objTestDataUtil.InvokeDeleteUserAPI(emailId);
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
