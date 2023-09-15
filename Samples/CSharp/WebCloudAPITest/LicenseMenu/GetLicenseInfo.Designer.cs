
namespace WebCloudAPITest.LicenseMenu
{
    partial class GetLicenseInfo
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnLicenceInfo = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.combPrdts = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textMacID = new System.Windows.Forms.TextBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.textResponse = new System.Windows.Forms.TextBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnLicenceInfo);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(627, 100);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Your Deatails";
            // 
            // btnLicenceInfo
            // 
            this.btnLicenceInfo.Location = new System.Drawing.Point(534, 25);
            this.btnLicenceInfo.Name = "btnLicenceInfo";
            this.btnLicenceInfo.Size = new System.Drawing.Size(75, 53);
            this.btnLicenceInfo.TabIndex = 2;
            this.btnLicenceInfo.Text = "Get Info";
            this.btnLicenceInfo.UseVisualStyleBackColor = true;
            this.btnLicenceInfo.Click += new System.EventHandler(this.btnLicenceInfo_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.combPrdts);
            this.groupBox3.Location = new System.Drawing.Point(267, 19);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(246, 59);
            this.groupBox3.TabIndex = 1;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Select Product";
            // 
            // combPrdts
            // 
            this.combPrdts.FormattingEnabled = true;
            this.combPrdts.Location = new System.Drawing.Point(7, 18);
            this.combPrdts.Name = "combPrdts";
            this.combPrdts.Size = new System.Drawing.Size(233, 21);
            this.combPrdts.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textMacID);
            this.groupBox2.Location = new System.Drawing.Point(6, 19);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(246, 59);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Machine ID";
            // 
            // textMacID
            // 
            this.textMacID.Location = new System.Drawing.Point(7, 20);
            this.textMacID.Name = "textMacID";
            this.textMacID.ReadOnly = true;
            this.textMacID.Size = new System.Drawing.Size(226, 20);
            this.textMacID.TabIndex = 0;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.textResponse);
            this.groupBox4.Location = new System.Drawing.Point(13, 120);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(627, 318);
            this.groupBox4.TabIndex = 1;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "License Details";
            // 
            // textResponse
            // 
            this.textResponse.Location = new System.Drawing.Point(13, 20);
            this.textResponse.Multiline = true;
            this.textResponse.Name = "textResponse";
            this.textResponse.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textResponse.Size = new System.Drawing.Size(595, 278);
            this.textResponse.TabIndex = 0;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(546, 454);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 2;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // GetLicenseInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(656, 495);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "GetLicenseInfo";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "GetLicenseInfo";
            this.groupBox1.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnLicenceInfo;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.ComboBox combPrdts;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textMacID;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.TextBox textResponse;
    }
}