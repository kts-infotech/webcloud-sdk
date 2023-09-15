using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest
{
    public partial class HrSendEmailForm : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        HRMailInfo m_HREmailinfo;
        List<HRAttachmentInfo> m_HRAttachmentArray;
        const int MAX_FILE_SIZE = 2097152;
        long  m_LFileSize;

        public HrSendEmailForm(WebCloudAPIForm form, string strManagerID)
        {
            InitializeComponent();
            m_LFileSize = 0;
            m_HREmailinfo = new HRMailInfo();
            m_HRAttachmentArray = new List<HRAttachmentInfo>();
            m_ObjMainForm = form;
            textFromID.Text = m_ObjMainForm.GetUserID();
            textHRID.Text = strManagerID;


        }
        private void btnAttach_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                string strFilePath = dlg.FileName;
                FileInfo file = new FileInfo(strFilePath);
                if (file.Length <= MAX_FILE_SIZE)
                {
                    m_LFileSize += file.Length;
                    HRAttachmentInfo attachment = new HRAttachmentInfo();
                    attachment.AttachmentBase64 = ConvertFileToBase64String(strFilePath);
                    attachment.AttachmentName = Path.GetFileName(strFilePath);
                    attachment.AttachmentType = Path.GetExtension(strFilePath);
                    m_HRAttachmentArray.Add(attachment);
                    flowLayoutPanel.Controls.Add(CreateButton(attachment.AttachmentName));
                }
                else
                {
                    MessageBox.Show("Please select a file less than 2MB", "Error");
                }
            }
        }
        private async void btnSendHrMail_Click(object sender, EventArgs e)
        {
            if (textHRID.Text == "")
            {
                MessageBox.Show("To Address is Empty. You must provide a reciever address to proceed", "No Reciever");
                return;
            }
            if (textSubject.Text == "")
            {
                if (MessageBox.Show("Subject field Empty. Are you sure want to send this mail without subject?", "No Subject", MessageBoxButtons.YesNo) != DialogResult.Yes)
                {

                    return;
                }
            }

            if (textMessage.Text == "")
            {
                if (MessageBox.Show("Message field Empty. Are you sure want to send this mail without Message?", "No Message", MessageBoxButtons.YesNo) != DialogResult.Yes)
                {

                    return;
                }
            }

            if (m_LFileSize>MAX_FILE_SIZE)
            {
                MessageBox.Show("Total File Size is large to Send. Please remove some attachments","Error");
                return;
            }
            //LogCategoryy
            int dbValue = 24;
            LogCategory enumValue = (LogCategory)dbValue;
            string strTaskID = enumValue.ToString();
            long ticks = ConvertDateTimeToTicks(DateTime.Now);
            string userID = m_ObjMainForm.GetUserID();
            m_HREmailinfo.Username = userID;
            m_HREmailinfo.LogType = strTaskID;
            m_HREmailinfo.LogDate = ticks.ToString();
            m_HREmailinfo.To = textHRID.Text;
            m_HREmailinfo.BCC = textBcc.Text;
            m_HREmailinfo.CC = textCc.Text;
            m_HREmailinfo.Subject = textSubject.Text;
            m_HREmailinfo.HtmlMailContent = textMessage.Text;
            m_ObjMainForm.SetRequestData(m_HREmailinfo);
            m_HREmailinfo.HRAttachmentArray = m_HRAttachmentArray;          
            try
            {
                WCResult Response = await m_ObjMainForm.ApiService.SendHRMail(m_HREmailinfo);
                if(Response.Status)
                {
                    MessageBox.Show(Response.Desc,"Success");
                }
                else
                {
                    MessageBox.Show(Response.Desc, "Failed");
                }
                m_ObjMainForm.SetResponseData(Response);
            }
            catch (Exception ex)
            {
                m_ObjMainForm.SetResponseData(ex.Message);
                MessageBox.Show(ex.Message, "Error");
            }
           
            m_ObjMainForm.SetRequestURL(m_ObjMainForm.ApiService.SubmitURL);
        }
        public string ConvertFileToBase64String(string FilePath)
        {
            try
            {
                Byte[] bytes = File.ReadAllBytes(FilePath);
                String FileData = Convert.ToBase64String(bytes);
                return FileData;
            }
            catch (Exception)
            {
                return "";
            }
        }
        private Button CreateButton(string strFileName)
        {
            Button btn = new Button();
            btn.FlatAppearance.BorderSize = 0;
            btn.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            btn.Image = global::WebCloudAPITest.Properties.Resources.Attachment_Icon_16;
            btn.ImageAlign = System.Drawing.ContentAlignment.TopLeft;
            btn.Location = new System.Drawing.Point(3, 3);
            btn.Name = "button" + m_HRAttachmentArray.Count.ToString();
            btn.Size = new System.Drawing.Size(75, 23);
            btn.TabIndex = 0;
            btn.Text = strFileName;
            btn.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            btn.UseVisualStyleBackColor = true;
            return btn;
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        public static long ConvertDateTimeToTicks(DateTime dtInput)
        {
            long ticks = 0;
            ticks = dtInput.Ticks;
            return ticks;
        }
    }
}
