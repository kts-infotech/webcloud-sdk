
namespace WebCloudAPITest.TTMenu
{
    partial class UploadWorkLog
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
            this.combCompletion = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textMemoDesc = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textMemo = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textAppWinTitle = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textAppExeName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.lbCaptureTime = new System.Windows.Forms.Label();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnUpload = new System.Windows.Forms.Button();
            this.btnScrnShot = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnScrnShot);
            this.groupBox1.Controls.Add(this.combCompletion);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.textMemoDesc);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.textMemo);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textAppWinTitle);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textAppExeName);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(455, 288);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Upload Details";
            // 
            // combCompletion
            // 
            this.combCompletion.FormattingEnabled = true;
            this.combCompletion.Items.AddRange(new object[] {
            "Ongoing Task",
            "5%",
            "10%",
            "15%",
            "30%",
            "45%",
            "60%",
            "75%",
            "90%",
            "100%"});
            this.combCompletion.Location = new System.Drawing.Point(147, 215);
            this.combCompletion.Name = "combCompletion";
            this.combCompletion.Size = new System.Drawing.Size(106, 21);
            this.combCompletion.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(7, 215);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(123, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Completion Percentage :";
            // 
            // textMemoDesc
            // 
            this.textMemoDesc.Location = new System.Drawing.Point(147, 168);
            this.textMemoDesc.Name = "textMemoDesc";
            this.textMemoDesc.Size = new System.Drawing.Size(263, 20);
            this.textMemoDesc.TabIndex = 7;
            this.textMemoDesc.Text = "Sample Description";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(7, 168);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(98, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Memo Description :";
            // 
            // textMemo
            // 
            this.textMemo.Location = new System.Drawing.Point(147, 125);
            this.textMemo.Name = "textMemo";
            this.textMemo.Size = new System.Drawing.Size(263, 20);
            this.textMemo.TabIndex = 5;
            this.textMemo.Text = "Sample Memo";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 125);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Memo Title :";
            // 
            // textAppWinTitle
            // 
            this.textAppWinTitle.Location = new System.Drawing.Point(147, 78);
            this.textAppWinTitle.Name = "textAppWinTitle";
            this.textAppWinTitle.Size = new System.Drawing.Size(263, 20);
            this.textAppWinTitle.TabIndex = 3;
            this.textAppWinTitle.Text = "SampleTitle";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(130, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Application Window Title :";
            // 
            // textAppExeName
            // 
            this.textAppExeName.Location = new System.Drawing.Point(147, 33);
            this.textAppExeName.Name = "textAppExeName";
            this.textAppExeName.Size = new System.Drawing.Size(263, 20);
            this.textAppExeName.TabIndex = 1;
            this.textAppExeName.Text = "SampleApplication.exe";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(123, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Application EXE  Name :";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.lbCaptureTime);
            this.groupBox2.Controls.Add(this.pictureBox);
            this.groupBox2.Location = new System.Drawing.Point(475, 14);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(330, 287);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Screen Shot Details";
            // 
            // lbCaptureTime
            // 
            this.lbCaptureTime.AutoSize = true;
            this.lbCaptureTime.Location = new System.Drawing.Point(6, 259);
            this.lbCaptureTime.Name = "lbCaptureTime";
            this.lbCaptureTime.Size = new System.Drawing.Size(76, 13);
            this.lbCaptureTime.TabIndex = 7;
            this.lbCaptureTime.Text = "Capture Time :";
            // 
            // pictureBox
            // 
            this.pictureBox.Location = new System.Drawing.Point(25, 19);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(266, 224);
            this.pictureBox.TabIndex = 0;
            this.pictureBox.TabStop = false;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(690, 325);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(115, 23);
            this.btnClose.TabIndex = 2;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnUpload
            // 
            this.btnUpload.Location = new System.Drawing.Point(548, 325);
            this.btnUpload.Name = "btnUpload";
            this.btnUpload.Size = new System.Drawing.Size(110, 23);
            this.btnUpload.TabIndex = 3;
            this.btnUpload.Text = "Upload";
            this.btnUpload.UseVisualStyleBackColor = true;
            this.btnUpload.Click += new System.EventHandler(this.btnUpload_Click);
            // 
            // btnScrnShot
            // 
            this.btnScrnShot.Location = new System.Drawing.Point(280, 249);
            this.btnScrnShot.Name = "btnScrnShot";
            this.btnScrnShot.Size = new System.Drawing.Size(130, 23);
            this.btnScrnShot.TabIndex = 10;
            this.btnScrnShot.Text = "Take Screen Shot";
            this.btnScrnShot.UseVisualStyleBackColor = true;
            this.btnScrnShot.Click += new System.EventHandler(this.btnScrnShot_Click);
            // 
            // UploadWorkLog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(840, 363);
            this.Controls.Add(this.btnUpload);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "UploadWorkLog";
            this.Text = "UploadWorkLog";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textAppExeName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textAppWinTitle;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textMemoDesc;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textMemo;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox combCompletion;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label lbCaptureTime;
        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnUpload;
        private System.Windows.Forms.Button btnScrnShot;
    }
}