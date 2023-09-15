using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest
{
    public partial class PostADefectForm : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        List<TopicDetails> m_ListTopicDetails;
        string m_strFilePath;
        int m_iTopicID=-1;
        string m_strAssigned = "";
        string m_strSelLanguage = "";
        List<TaskAssignedTo> m_ListAssignedTo;
        const int MAX_FILE_SIZE = 2097152;
        public PostADefectForm(List<TopicDetails> info, List<TaskAssignedTo> assignedList, WebCloudAPIForm objForm)
        {
            InitializeComponent();
            m_ListTopicDetails = info;
            m_ListAssignedTo = assignedList;
            m_ObjMainForm = objForm;
           
            foreach (TopicDetails topics in m_ListTopicDetails)
            {
                combBugTopics.Items.Add(topics.TopicName);
            }

            foreach (TaskAssignedTo assignedTo in m_ListAssignedTo)
            {
                comboAssignedTo.Items.Add(assignedTo.Name);
            }
            
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = "c:\\";
            openFileDialog.Filter = "All files (*.*)|*.*";
            openFileDialog.FilterIndex = 2;
            openFileDialog.RestoreDirectory = true;

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {

                m_strFilePath = openFileDialog.FileName;
                var file = new FileInfo(m_strFilePath);
                if (file.Length > 1024 * 1024)
                {
                    MessageBox.Show("File is larger than 2 MB");
                    return;
                }
                textFilePath.Text = m_strFilePath;
                
            }
        }

        private async void btnPostThread_Click(object sender, EventArgs e)
        {
            if (m_iTopicID < 0)
            {
                MessageBox.Show("Please Select a Topic");
                return;
            }
            
            if (m_strAssigned == "")
            {
                MessageBox.Show("Please Select an assigned person");
                return;
            }

            if (m_strSelLanguage == "")
            {
                MessageBox.Show("Please Select a language");
                return;
            }

            DefectDetails postDefectDetails = new DefectDetails();
            postDefectDetails.BugTaskTitle = textBugTitle.Text;
            postDefectDetails.BugLanguage = m_strSelLanguage;
            postDefectDetails.BugAssignedTo = comboAssignedTo.SelectedItem.ToString();
            postDefectDetails.BugAssignedToValue = m_strAssigned;
            postDefectDetails.BugTaskDescription = textThreadDesc.Text;
            postDefectDetails.FormType = "DT";
            postDefectDetails.Username = m_ObjMainForm.GetUserID();
            postDefectDetails.TopicID = m_iTopicID;
            postDefectDetails.FileAttachment = ConvertFileToBase64(m_strFilePath);
            postDefectDetails.FilePath = Path.GetFileName(m_strFilePath);

            bool Info = await m_ObjMainForm.ApiService.PostADefect(postDefectDetails);
            if (Info)
            {
                MessageBox.Show("Deffect posted successfully");
            }
            else
            {
                MessageBox.Show(".......Failed........");
            }
            
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void combBugTopics_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem = combBugTopics.SelectedItem.ToString();
            foreach (TopicDetails topics in m_ListTopicDetails)
            {
                if (selectedItem == topics.TopicName)
                {
                    lbTopicDesc.Text = topics.TopicDescription;
                    m_iTopicID = topics.TopicID;
                    break;
                }
            }
            
        }

        private void comboAssignedTo_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem = comboAssignedTo.SelectedItem.ToString();
            foreach (TaskAssignedTo assignedTo in m_ListAssignedTo)
            {
                if (selectedItem == assignedTo.Name)
                {
                    m_strAssigned = assignedTo.EmailId;
                    break;
                }
            }
        }

        private void comboLanguages_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_strSelLanguage = comboLanguages.SelectedItem.ToString();
        }

        private string ConvertFileToBase64(string filePath)
        {

            if (!File.Exists(filePath))
                return "";
            FileInfo fileinfo = new FileInfo(filePath);
            if (fileinfo.Length > MAX_FILE_SIZE)
                return "";
            Byte[] bytes = File.ReadAllBytes(filePath);
            String file = Convert.ToBase64String(bytes);
            return file;
        }
    }
}
