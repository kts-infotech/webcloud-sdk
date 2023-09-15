using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;
using ProjectFrameworkAPITest;
using WebCloud.Api.DS;

namespace WebCloudAPITest
{
    public partial class SendEmailForm : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        MailInfo m_Emailinfo;
        List<AttachmentInfo> m_AttachmentArray;
        public SendEmailForm(WebCloudAPIForm form)
        {
            InitializeComponent();
            m_Emailinfo = new MailInfo();
            m_AttachmentArray = new List<AttachmentInfo>();
            m_ObjMainForm = form;
            textFromID.Text = m_ObjMainForm.GetUserID();

        }

        private void btnAttach_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                string strFilePath = dlg.FileName;
                AttachmentInfo attachment = new AttachmentInfo();
                attachment.AttachmentBase64 = ConvertFileToBase64String(strFilePath);
                attachment.AttachmentName = Path.GetFileName(strFilePath);
                attachment.AttachmentType = Path.GetExtension(strFilePath);
                m_AttachmentArray.Add(attachment);
                flowLayoutPanel.Controls.Add(CreateButton(attachment.AttachmentName));
            }
        }

        private async void btnSendMail_Click(object sender, EventArgs e)
        {
            if (textToID.Text == "")
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
            m_Emailinfo.To = textToID.Text;
            m_Emailinfo.BCC = textBcc.Text;
            m_Emailinfo.CC = textCc.Text;
            m_Emailinfo.Subject = textSubject.Text;
            m_Emailinfo.HtmlMailContent = textMessage.Text;
            m_Emailinfo.AttachmentArray = m_AttachmentArray;
            m_ObjMainForm.SetRequestData(m_Emailinfo);
            try
            {
                WCResult strResponse = await m_ObjMainForm.ApiService.SendMail(m_Emailinfo);
                m_ObjMainForm.SetResponseData(strResponse);
                m_ObjMainForm.SetRequestURL(m_ObjMainForm.ApiService.SubmitURL);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
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
            btn.Name = "button" + m_AttachmentArray.Count.ToString();
            btn.Size = new System.Drawing.Size(75, 23);
            btn.TabIndex = 0;
            btn.Text = strFileName;
            btn.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            btn.UseVisualStyleBackColor = true;
            return btn;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}

