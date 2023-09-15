namespace WebCloudAPITest
{
    partial class FileUploadForm
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
            this.labelProgress = new System.Windows.Forms.Label();
            this.buttonDestinationPathBrowse = new System.Windows.Forms.Button();
            this.buttonLocalPathBrowse = new System.Windows.Forms.Button();
            this.textBoxDestinatinationDir = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxLocalFilePath = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.labelStatus = new System.Windows.Forms.Label();
            this.buttonUplaodFile = new System.Windows.Forms.Button();
            this.buttonClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.labelProgress);
            this.groupBox1.Controls.Add(this.labelStatus);
            this.groupBox1.Controls.Add(this.buttonDestinationPathBrowse);
            this.groupBox1.Controls.Add(this.buttonLocalPathBrowse);
            this.groupBox1.Controls.Add(this.textBoxDestinatinationDir);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textBoxLocalFilePath);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(37, 29);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(905, 230);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select the Upload Parameters";
            // 
            // labelProgress
            // 
            this.labelProgress.AutoSize = true;
            this.labelProgress.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelProgress.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.labelProgress.Location = new System.Drawing.Point(12, 149);
            this.labelProgress.Name = "labelProgress";
            this.labelProgress.Size = new System.Drawing.Size(73, 17);
            this.labelProgress.TabIndex = 9;
            this.labelProgress.Text = "Progress";
            // 
            // buttonDestinationPathBrowse
            // 
            this.buttonDestinationPathBrowse.Location = new System.Drawing.Point(848, 102);
            this.buttonDestinationPathBrowse.Name = "buttonDestinationPathBrowse";
            this.buttonDestinationPathBrowse.Size = new System.Drawing.Size(32, 23);
            this.buttonDestinationPathBrowse.TabIndex = 7;
            this.buttonDestinationPathBrowse.Text = "...";
            this.buttonDestinationPathBrowse.UseVisualStyleBackColor = true;
            this.buttonDestinationPathBrowse.Click += new System.EventHandler(this.buttonDestinationPathBrowse_Click);
            // 
            // buttonLocalPathBrowse
            // 
            this.buttonLocalPathBrowse.Location = new System.Drawing.Point(848, 49);
            this.buttonLocalPathBrowse.Name = "buttonLocalPathBrowse";
            this.buttonLocalPathBrowse.Size = new System.Drawing.Size(32, 23);
            this.buttonLocalPathBrowse.TabIndex = 6;
            this.buttonLocalPathBrowse.Text = "...";
            this.buttonLocalPathBrowse.UseVisualStyleBackColor = true;
            this.buttonLocalPathBrowse.Click += new System.EventHandler(this.buttonLocalPathBrowse_Click);
            // 
            // textBoxDestinatinationDir
            // 
            this.textBoxDestinatinationDir.Location = new System.Drawing.Point(281, 102);
            this.textBoxDestinatinationDir.Name = "textBoxDestinatinationDir";
            this.textBoxDestinatinationDir.Size = new System.Drawing.Size(541, 22);
            this.textBoxDestinatinationDir.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(12, 102);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(239, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "Select the Destination Directory";
            // 
            // textBoxLocalFilePath
            // 
            this.textBoxLocalFilePath.Location = new System.Drawing.Point(281, 49);
            this.textBoxLocalFilePath.Name = "textBoxLocalFilePath";
            this.textBoxLocalFilePath.Size = new System.Drawing.Size(541, 22);
            this.textBoxLocalFilePath.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(168, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Select the Source File";
            // 
            // labelStatus
            // 
            this.labelStatus.AutoSize = true;
            this.labelStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelStatus.ForeColor = System.Drawing.Color.Red;
            this.labelStatus.Location = new System.Drawing.Point(12, 190);
            this.labelStatus.Name = "labelStatus";
            this.labelStatus.Size = new System.Drawing.Size(54, 17);
            this.labelStatus.TabIndex = 8;
            this.labelStatus.Text = "Status";
            // 
            // buttonUplaodFile
            // 
            this.buttonUplaodFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonUplaodFile.Location = new System.Drawing.Point(621, 278);
            this.buttonUplaodFile.Name = "buttonUplaodFile";
            this.buttonUplaodFile.Size = new System.Drawing.Size(153, 27);
            this.buttonUplaodFile.TabIndex = 9;
            this.buttonUplaodFile.Text = "Upload File";
            this.buttonUplaodFile.UseVisualStyleBackColor = true;
            this.buttonUplaodFile.Click += new System.EventHandler(this.buttonUplaodFile_Click);
            // 
            // buttonClose
            // 
            this.buttonClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonClose.Location = new System.Drawing.Point(784, 278);
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(133, 27);
            this.buttonClose.TabIndex = 10;
            this.buttonClose.Text = "Close";
            this.buttonClose.UseVisualStyleBackColor = true;
            this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
            // 
            // FileUploadForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(954, 331);
            this.Controls.Add(this.buttonClose);
            this.Controls.Add(this.buttonUplaodFile);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FileUploadForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Upload Files to Cloud ";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBoxLocalFilePath;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxDestinatinationDir;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonLocalPathBrowse;
        private System.Windows.Forms.Button buttonDestinationPathBrowse;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.Button buttonUplaodFile;
        private System.Windows.Forms.Button buttonClose;
        private System.Windows.Forms.Label labelProgress;
    }
}