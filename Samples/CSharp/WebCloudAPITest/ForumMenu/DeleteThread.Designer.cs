
namespace WebCloudAPITest.ForumMenu
{
    partial class DeleteThread
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
            this.textTaskDesc = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.lbBugStatus = new System.Windows.Forms.Label();
            this.lbAssigned = new System.Windows.Forms.Label();
            this.lbPostedDate = new System.Windows.Forms.Label();
            this.lbAuthorId = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lbThreadName = new System.Windows.Forms.Label();
            this.combThreadID = new System.Windows.Forms.ComboBox();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // textTaskDesc
            // 
            this.textTaskDesc.Location = new System.Drawing.Point(6, 19);
            this.textTaskDesc.Multiline = true;
            this.textTaskDesc.Name = "textTaskDesc";
            this.textTaskDesc.Size = new System.Drawing.Size(340, 127);
            this.textTaskDesc.TabIndex = 5;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.lbBugStatus);
            this.groupBox3.Controls.Add(this.lbAssigned);
            this.groupBox3.Controls.Add(this.lbPostedDate);
            this.groupBox3.Controls.Add(this.lbAuthorId);
            this.groupBox3.Location = new System.Drawing.Point(11, 89);
            this.groupBox3.MinimumSize = new System.Drawing.Size(20, 0);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(352, 125);
            this.groupBox3.TabIndex = 8;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Thread Details";
            // 
            // lbBugStatus
            // 
            this.lbBugStatus.AutoSize = true;
            this.lbBugStatus.Location = new System.Drawing.Point(7, 16);
            this.lbBugStatus.Name = "lbBugStatus";
            this.lbBugStatus.Size = new System.Drawing.Size(35, 13);
            this.lbBugStatus.TabIndex = 11;
            this.lbBugStatus.Text = "label4";
            // 
            // lbAssigned
            // 
            this.lbAssigned.AutoSize = true;
            this.lbAssigned.Location = new System.Drawing.Point(6, 42);
            this.lbAssigned.Name = "lbAssigned";
            this.lbAssigned.Size = new System.Drawing.Size(35, 13);
            this.lbAssigned.TabIndex = 10;
            this.lbAssigned.Text = "label3";
            // 
            // lbPostedDate
            // 
            this.lbPostedDate.AutoSize = true;
            this.lbPostedDate.Location = new System.Drawing.Point(6, 70);
            this.lbPostedDate.Name = "lbPostedDate";
            this.lbPostedDate.Size = new System.Drawing.Size(35, 13);
            this.lbPostedDate.TabIndex = 9;
            this.lbPostedDate.Text = "label2";
            // 
            // lbAuthorId
            // 
            this.lbAuthorId.AutoSize = true;
            this.lbAuthorId.Location = new System.Drawing.Point(7, 96);
            this.lbAuthorId.Name = "lbAuthorId";
            this.lbAuthorId.Size = new System.Drawing.Size(35, 13);
            this.lbAuthorId.TabIndex = 8;
            this.lbAuthorId.Text = "label1";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textTaskDesc);
            this.groupBox2.Location = new System.Drawing.Point(11, 220);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(352, 168);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Thread Description";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lbThreadName);
            this.groupBox1.Controls.Add(this.combThreadID);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(352, 71);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select Thread ID";
            // 
            // lbThreadName
            // 
            this.lbThreadName.AutoSize = true;
            this.lbThreadName.Location = new System.Drawing.Point(118, 31);
            this.lbThreadName.Name = "lbThreadName";
            this.lbThreadName.Size = new System.Drawing.Size(72, 13);
            this.lbThreadName.TabIndex = 1;
            this.lbThreadName.Text = "Thread Name";
            // 
            // combThreadID
            // 
            this.combThreadID.FormattingEnabled = true;
            this.combThreadID.Location = new System.Drawing.Point(19, 28);
            this.combThreadID.Name = "combThreadID";
            this.combThreadID.Size = new System.Drawing.Size(75, 21);
            this.combThreadID.TabIndex = 0;
            this.combThreadID.SelectedIndexChanged += new System.EventHandler(this.combThreadID_SelectedIndexChanged);
            // 
            // buttonDelete
            // 
            this.buttonDelete.Location = new System.Drawing.Point(122, 394);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(124, 23);
            this.buttonDelete.TabIndex = 9;
            this.buttonDelete.Text = "Delete This Thread";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(265, 394);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 10;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // DeleteThread
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(394, 450);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.buttonDelete);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "DeleteThread";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "DeleteThread";
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox textTaskDesc;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label lbBugStatus;
        private System.Windows.Forms.Label lbAssigned;
        private System.Windows.Forms.Label lbPostedDate;
        private System.Windows.Forms.Label lbAuthorId;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lbThreadName;
        private System.Windows.Forms.ComboBox combThreadID;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.Button btnClose;
    }
}