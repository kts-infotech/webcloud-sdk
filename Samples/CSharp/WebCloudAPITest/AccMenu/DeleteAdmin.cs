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
    public partial class DeleteAdmin : Form
    {
        private ApiTestDataUtil objTestDataUtil;
      

        /// <summary>
        /// 
        /// </summary>
        /// <param name="obj"></param>
        public DeleteAdmin(ApiTestDataUtil obj)
        {
            InitializeComponent();
            objTestDataUtil = obj;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private async void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string emailId = cbDelAdmin.SelectedValue.ToString();
                await objTestDataUtil.InvokeDeleteAdminAPI(emailId);
            }
            catch (Exception)
            {

            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="result"></param>
        public void SetComboBox(List<AdminAccInfo> result)
        {
            try
            {
                DataTable dtUserInfo = ConvertToDataTable(result);

                cbDelAdmin.DataSource = dtUserInfo;
                cbDelAdmin.DisplayMember = "Firstname";
                cbDelAdmin.ValueMember = "Email";
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
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
