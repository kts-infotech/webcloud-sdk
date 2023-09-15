
namespace WebCloudAPITest.CMSMenu
{
    partial class GetDetailedPageInfo
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBoxMenus = new System.Windows.Forms.GroupBox();
            this.listMenuWithID = new System.Windows.Forms.ListBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.webBrowser = new System.Windows.Forms.WebBrowser();
            this.textBoxInfo = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBoxMenus.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxMenus
            // 
            this.groupBoxMenus.Controls.Add(this.listMenuWithID);
            this.groupBoxMenus.Location = new System.Drawing.Point(12, 12);
            this.groupBoxMenus.Name = "groupBoxMenus";
            this.groupBoxMenus.Size = new System.Drawing.Size(263, 413);
            this.groupBoxMenus.TabIndex = 0;
            this.groupBoxMenus.TabStop = false;
            this.groupBoxMenus.Text = "Select Menu Name(Menu ID)";
            // 
            // listMenuWithID
            // 
            this.listMenuWithID.FormattingEnabled = true;
            this.listMenuWithID.Location = new System.Drawing.Point(10, 19);
            this.listMenuWithID.Name = "listMenuWithID";
            this.listMenuWithID.Size = new System.Drawing.Size(239, 381);
            this.listMenuWithID.TabIndex = 0;
            this.listMenuWithID.SelectedIndexChanged += new System.EventHandler(this.listMenuWithID_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.webBrowser);
            this.groupBox1.Controls.Add(this.textBoxInfo);
            this.groupBox1.Location = new System.Drawing.Point(282, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(506, 413);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Details of Selected Item";
            // 
            // webBrowser
            // 
            this.webBrowser.Location = new System.Drawing.Point(7, 244);
            this.webBrowser.MinimumSize = new System.Drawing.Size(20, 20);
            this.webBrowser.Name = "webBrowser";
            this.webBrowser.ScriptErrorsSuppressed = true;
            this.webBrowser.Size = new System.Drawing.Size(493, 156);
            this.webBrowser.TabIndex = 1;
            // 
            // textBoxInfo
            // 
            this.textBoxInfo.Location = new System.Drawing.Point(7, 20);
            this.textBoxInfo.Multiline = true;
            this.textBoxInfo.Name = "textBoxInfo";
            this.textBoxInfo.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxInfo.Size = new System.Drawing.Size(493, 208);
            this.textBoxInfo.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(680, 443);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(102, 28);
            this.button1.TabIndex = 2;
            this.button1.Text = "Close";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // GetDetailedPageInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 483);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBoxMenus);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "GetDetailedPageInfo";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "GetDetailedPageInfo";
            this.groupBoxMenus.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxMenus;
        private System.Windows.Forms.ListBox listMenuWithID;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.WebBrowser webBrowser;
        private System.Windows.Forms.TextBox textBoxInfo;
    }
}