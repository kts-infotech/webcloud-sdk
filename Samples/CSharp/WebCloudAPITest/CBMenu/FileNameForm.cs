using System;
using System.Windows.Forms;

namespace WebCloudAPITest.CBMenu
{
    public partial class FileNameForm : Form
    {
        public FileNameForm(string text="")
        {
            InitializeComponent();
            textFileName.Text = text;
        }

        private void btnFileName_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        public string GetFileName()
        {
            return textFileName.Text.Trim();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
