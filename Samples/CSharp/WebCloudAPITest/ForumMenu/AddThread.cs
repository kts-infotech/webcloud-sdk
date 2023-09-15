using ProjectFrameworkAPITest;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using WebCloud.Api.DS;

namespace WebCloudAPITest.ForumMenu
{
    public partial class AddThread : Form
    {
        private WebCloudAPIForm m_ObjMainForm;
        ThreadDetailsInfo m_Thread;
        public AddThread(WebCloudAPIForm obj, List<ItemInfo> info)
        {
            InitializeComponent();
            m_ObjMainForm = obj;
            m_Thread = new ThreadDetailsInfo();
            SetForumCombo(info);
        }

        private void SetForumCombo(List<ItemInfo> info)
        {
            comboForName.Items.Clear();
            foreach (ItemInfo item in info)
            {
                comboForName.Items.Add(item);
            }
        }

        private void SetTopicCombo(List<ItemInfo> info)
        {
            combTopName.Items.Clear();
            foreach (ItemInfo item in info)
            {
                combTopName.Items.Add(item);
            }
            combTopName.SelectedIndex = 0;
        }

        private void SetListBoxItems(List<ItemInfo> info)
        {
            listBoxExisTrds.Items.Clear();
            foreach (ItemInfo item in info)
            {
                listBoxExisTrds.Items.Add(item);
            }
        }

        private async void comboForName_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string strForumID = (comboForName.SelectedItem as ItemInfo).Value.ToString();
                List<ItemInfo> info = await m_ObjMainForm.ApiService.GetAllTopicsWithForumID(strForumID);
                SetTopicCombo(info);
            }
            catch (Exception Ex)
            {

                ShowMessageBox("Error", Ex.Message);
            }
        }

        private async void combTopName_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string strTopicID = (combTopName.SelectedItem as ItemInfo).Value.ToString();
                List<ItemInfo> info = await m_ObjMainForm.ApiService.GetAllThreadsWithTopicID(strTopicID);
                SetListBoxItems(info);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private async void listBoxExisTrds_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBoxExisTrds.SelectedIndex == -1)
                return;
            try
            {
                string strThreadID = (listBoxExisTrds.SelectedItem as ItemInfo).Value.ToString();
                ThreadDetailsInfo info = await m_ObjMainForm.ApiService.GetThreadByID(strThreadID);
                //m_ObjMainForm.SetResponseData(info);
                SetThreadDetailsInForm(info);
                btnAdd.Text = "Update";
                btnAddNew.Visible = true;
                checkUpldImage.Text = "Update Image";
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private void SetThreadDetailsInForm(ThreadDetailsInfo info)
        {
            textTrdName.Text = info.ThreadName;
            textTrdDesc.Text = info.ThreadDesc;
            pictureBox.Image = null;
            if (info.ThreadImage != "")
            {
                Image img = info.ConvertFromBase64();
                pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                pictureBox.Image = img;
            }

        }

        private void checkUpldImage_CheckedChanged(object sender, EventArgs e)
        {
            btnBrsImg.Enabled = checkUpldImage.Checked;
        }

        private void btnBrsImg_Click(object sender, EventArgs e)
        {
            OpenFileDialog opDLg = new OpenFileDialog();
            opDLg.RestoreDirectory = true;
            opDLg.Filter = "Image Files(*.BMP; *.JPG; *.GIF; *.JPEG; *.PNG)| *.BMP; *.JPG; *.GIF; *.JPEG; *.PNG";
            opDLg.ShowDialog();
            textImgPath.Text = opDLg.FileName;
            Image img = Image.FromFile(textImgPath.Text);
            pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox.Image = img;
        }

        private async void btnAdd_Click(object sender, EventArgs e)
        {
            string Info = "";
            try
            {
                m_Thread.ThreadName = textTrdName.Text;
                m_Thread.ForumInfo = comboForName.SelectedItem as ItemInfo;
                m_Thread.TopicInfo = combTopName.SelectedItem as ItemInfo;
                m_Thread.UserName = m_ObjMainForm.GetUserID();
                m_Thread.ThreadDesc = textTrdDesc.Text;
                if (textImgPath.Text != "" && File.Exists(textImgPath.Text) && checkUpldImage.Checked)
                {
                    m_Thread.ImageName = textImgPath.Text;
                    m_Thread.ConvertImageToBase64String(textImgPath.Text);
                }
                if (btnAdd.Text == "Add")
                {
                    Info = await m_ObjMainForm.ApiService.AddThread(m_Thread);
                }
                else
                {
                    m_Thread.ThreadID = (listBoxExisTrds.SelectedItem as ItemInfo).Value.ToString();
                    Info = await m_ObjMainForm.ApiService.UpdateThread(m_Thread);
                }
                ShowMessageBox("Information", Info);
            }
            catch (Exception Ex)
            {
                ShowMessageBox("Error", Ex.Message);
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnAddNew_Click(object sender, EventArgs e)
        {
            btnAdd.Text = "Add";
            btnAddNew.Visible = false;
            checkUpldImage.Text = "Upload Image";
            textTrdName.Text = "";
            textTrdDesc.Text = "";
            pictureBox.Image = null;

        }
        private void ShowMessageBox(string strtitle, string strMsg)
        {
            MessageBox.Show(strMsg, strtitle);
        }
    }
}
