
namespace WebCloudAPITest
{
    partial class PostADefectForm
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
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnPostThread = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.btnBrowse = new System.Windows.Forms.Button();
            this.textFilePath = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textThreadDesc = new System.Windows.Forms.RichTextBox();
            this.comboAssignedTo = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.comboLanguages = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBugTitle = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.lbTopicDesc = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.combBugTopics = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnCancel);
            this.groupBox1.Controls.Add(this.btnPostThread);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Controls.Add(this.comboAssignedTo);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.comboLanguages);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textBugTitle);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 109);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(776, 414);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Add a New Thread";
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(619, 363);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(117, 23);
            this.btnCancel.TabIndex = 9;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnPostThread
            // 
            this.btnPostThread.Location = new System.Drawing.Point(480, 363);
            this.btnPostThread.Name = "btnPostThread";
            this.btnPostThread.Size = new System.Drawing.Size(117, 23);
            this.btnPostThread.TabIndex = 8;
            this.btnPostThread.Text = "Post Thread";
            this.btnPostThread.UseVisualStyleBackColor = true;
            this.btnPostThread.Click += new System.EventHandler(this.btnPostThread_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.btnBrowse);
            this.groupBox3.Controls.Add(this.textFilePath);
            this.groupBox3.Location = new System.Drawing.Point(10, 295);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(745, 102);
            this.groupBox3.TabIndex = 7;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Attach a file(Max 2MB)";
            // 
            // btnBrowse
            // 
            this.btnBrowse.Location = new System.Drawing.Point(609, 19);
            this.btnBrowse.Name = "btnBrowse";
            this.btnBrowse.Size = new System.Drawing.Size(117, 23);
            this.btnBrowse.TabIndex = 1;
            this.btnBrowse.Text = "Browse";
            this.btnBrowse.UseVisualStyleBackColor = true;
            this.btnBrowse.Click += new System.EventHandler(this.btnBrowse_Click);
            // 
            // textFilePath
            // 
            this.textFilePath.Location = new System.Drawing.Point(6, 23);
            this.textFilePath.Name = "textFilePath";
            this.textFilePath.Size = new System.Drawing.Size(581, 20);
            this.textFilePath.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textThreadDesc);
            this.groupBox2.Location = new System.Drawing.Point(10, 126);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(745, 163);
            this.groupBox2.TabIndex = 6;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Thread Description";
            // 
            // textThreadDesc
            // 
            this.textThreadDesc.Location = new System.Drawing.Point(6, 19);
            this.textThreadDesc.Name = "textThreadDesc";
            this.textThreadDesc.Size = new System.Drawing.Size(733, 138);
            this.textThreadDesc.TabIndex = 6;
            this.textThreadDesc.Text = "";
            // 
            // comboAssignedTo
            // 
            this.comboAssignedTo.FormattingEnabled = true;
            this.comboAssignedTo.Location = new System.Drawing.Point(276, 93);
            this.comboAssignedTo.Name = "comboAssignedTo";
            this.comboAssignedTo.Size = new System.Drawing.Size(238, 21);
            this.comboAssignedTo.TabIndex = 5;
            this.comboAssignedTo.SelectedIndexChanged += new System.EventHandler(this.comboAssignedTo_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 102);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Assigned To";
            // 
            // comboLanguages
            // 
            this.comboLanguages.FormattingEnabled = true;
            this.comboLanguages.Items.AddRange(new object[] {
            "English",
            "Other Language"});
            this.comboLanguages.Location = new System.Drawing.Point(276, 55);
            this.comboLanguages.Name = "comboLanguages";
            this.comboLanguages.Size = new System.Drawing.Size(238, 21);
            this.comboLanguages.TabIndex = 3;
            this.comboLanguages.SelectedIndexChanged += new System.EventHandler(this.comboLanguages_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(88, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Select Language";
            // 
            // textBugTitle
            // 
            this.textBugTitle.Location = new System.Drawing.Point(276, 20);
            this.textBugTitle.Name = "textBugTitle";
            this.textBugTitle.Size = new System.Drawing.Size(479, 20);
            this.textBugTitle.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(177, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Subject / Title (Max 100 characters)";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.lbTopicDesc);
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Controls.Add(this.combBugTopics);
            this.groupBox4.Controls.Add(this.label4);
            this.groupBox4.Location = new System.Drawing.Point(12, 12);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(776, 91);
            this.groupBox4.TabIndex = 1;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Select Topics";
            // 
            // lbTopicDesc
            // 
            this.lbTopicDesc.AutoSize = true;
            this.lbTopicDesc.Location = new System.Drawing.Point(133, 53);
            this.lbTopicDesc.Name = "lbTopicDesc";
            this.lbTopicDesc.Size = new System.Drawing.Size(100, 13);
            this.lbTopicDesc.TabIndex = 7;
            this.lbTopicDesc.Text = "..............Text..........";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(16, 53);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(96, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "Topic Description :";
            // 
            // combBugTopics
            // 
            this.combBugTopics.FormattingEnabled = true;
            this.combBugTopics.Location = new System.Drawing.Point(136, 19);
            this.combBugTopics.Name = "combBugTopics";
            this.combBugTopics.Size = new System.Drawing.Size(613, 21);
            this.combBugTopics.TabIndex = 5;
            this.combBugTopics.SelectedIndexChanged += new System.EventHandler(this.combBugTopics_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 23);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(117, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "Please Select a Topic :";
            // 
            // PostADefectForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 543);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox1);
            this.Name = "PostADefectForm";
            this.Text = "PostADefectForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnPostThread;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button btnBrowse;
        private System.Windows.Forms.TextBox textFilePath;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RichTextBox textThreadDesc;
        private System.Windows.Forms.ComboBox comboAssignedTo;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboLanguages;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBugTitle;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ComboBox combBugTopics;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lbTopicDesc;
        private System.Windows.Forms.Label label5;
    }
}