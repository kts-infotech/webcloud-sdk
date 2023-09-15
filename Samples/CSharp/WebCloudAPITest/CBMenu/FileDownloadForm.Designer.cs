namespace WebCloudAPITest
{
    partial class FileDownloadForm
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
            this.buttonClose = new System.Windows.Forms.Button();
            this.labelStatus = new System.Windows.Forms.Label();
            this.buttonDownloadFile = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.labelProgress = new System.Windows.Forms.Label();
            this.buttonDestinationPathBrowse = new System.Windows.Forms.Button();
            this.buttonRemotePathBrowse = new System.Windows.Forms.Button();
            this.textBoxDestinatinationDir = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxRemoteFilePath = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonClose
            // 
            this.buttonClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonClose.Location = new System.Drawing.Point(802, 256);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(133, 27);
            this.buttonClose.TabIndex = 14;
            this.buttonClose.Text = "Close";
            this.buttonClose.UseVisualStyleBackColor = true;
            this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
            // 
            // labelStatus
            // 
            this.labelStatus.AutoSize = true;
            this.labelStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelStatus.ForeColor = System.Drawing.Color.Red;
            this.labelStatus.Location = new System.Drawing.Point(13, 186);
            this.labelStatus.Name = "labelStatus";
            this.labelStatus.Size = new System.Drawing.Size(54, 17);
            this.labelStatus.TabIndex = 12;
            this.labelStatus.Text = "Status";
            // 
            // buttonDownloadFile
            // 
            this.buttonDownloadFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonDownloadFile.Location = new System.Drawing.Point(639, 256);
            this.buttonDownloadFile.Name = "buttonDownloadFile";
            this.buttonDownloadFile.Size = new System.Drawing.Size(153, 27);
            this.buttonDownloadFile.TabIndex = 13;
            this.buttonDownloadFile.Text = "Download File";
            this.buttonDownloadFile.UseVisualStyleBackColor = true;
            this.buttonDownloadFile.Click += new System.EventHandler(this.buttonDownloadFile_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.labelProgress);
            this.groupBox1.Controls.Add(this.labelStatus);
            this.groupBox1.Controls.Add(this.buttonDestinationPathBrowse);
            this.groupBox1.Controls.Add(this.buttonRemotePathBrowse);
            this.groupBox1.Controls.Add(this.textBoxDestinatinationDir);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textBoxRemoteFilePath);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(33, 24);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(905, 219);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select the Download Parameters";
            // 
            // labelProgress
            // 
            this.labelProgress.AutoSize = true;
            this.labelProgress.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelProgress.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.labelProgress.Location = new System.Drawing.Point(12, 146);
            this.labelProgress.Name = "labelProgress";
            this.labelProgress.Size = new System.Drawing.Size(73, 17);
            this.labelProgress.TabIndex = 9;
            this.labelProgress.Text = "Progress";
            // 
            // buttonDestinationPathBrowse
            // 
            this.buttonDestinationPathBrowse.Location = new System.Drawing.Point(848, 104);
            this.buttonDestinationPathBrowse.Name = "buttonDestinationPathBrowse";
            this.buttonDestinationPathBrowse.Size = new System.Drawing.Size(32, 23);
            this.buttonDestinationPathBrowse.TabIndex = 7;
            this.buttonDestinationPathBrowse.Text = "...";
            this.buttonDestinationPathBrowse.UseVisualStyleBackColor = true;
            this.buttonDestinationPathBrowse.Click += new System.EventHandler(this.buttonDestinationPathBrowse_Click);
            // 
            // buttonRemotePathBrowse
            // 
            this.buttonRemotePathBrowse.Location = new System.Drawing.Point(848, 49);
            this.buttonRemotePathBrowse.Name = "buttonRemotePathBrowse";
            this.buttonRemotePathBrowse.Size = new System.Drawing.Size(32, 23);
            this.buttonRemotePathBrowse.TabIndex = 6;
            this.buttonRemotePathBrowse.Text = "...";
            this.buttonRemotePathBrowse.UseVisualStyleBackColor = true;
            this.buttonRemotePathBrowse.Click += new System.EventHandler(this.buttonRemotePathBrowse_Click);
            // 
            // textBoxDestinatinationDir
            // 
            this.textBoxDestinatinationDir.Location = new System.Drawing.Point(281, 104);
            this.textBoxDestinatinationDir.Name = "textBoxDestinatinationDir";
            this.textBoxDestinatinationDir.Size = new System.Drawing.Size(541, 22);
            this.textBoxDestinatinationDir.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(12, 104);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(223, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "Select Local Download Folder";
            // 
            // textBoxRemoteFilePath
            // 
            this.textBoxRemoteFilePath.Location = new System.Drawing.Point(281, 49);
            this.textBoxRemoteFilePath.Name = "textBoxRemoteFilePath";
            this.textBoxRemoteFilePath.Size = new System.Drawing.Size(541, 22);
            this.textBoxRemoteFilePath.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(182, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Select Remote File Path";
            // 
            // FileDownloadForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(975, 309);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.buttonDownloadFile);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FileDownloadForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Download File From Cloud";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonClose;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.Button buttonDownloadFile;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label labelProgress;
        private System.Windows.Forms.Button buttonDestinationPathBrowse;
        private System.Windows.Forms.Button buttonRemotePathBrowse;
        private System.Windows.Forms.TextBox textBoxDestinatinationDir;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxRemoteFilePath;
        private System.Windows.Forms.Label label1;
    }
}