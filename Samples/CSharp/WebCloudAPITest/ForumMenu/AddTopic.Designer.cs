
namespace WebCloudAPITest.ForumMenu
{
    partial class AddTopic
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
            this.btnUnselectAll = new System.Windows.Forms.Button();
            this.btnSelectAll = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.listBoxTopics = new System.Windows.Forms.ListBox();
            this.checkAdminApr = new System.Windows.Forms.CheckBox();
            this.chkListEmails = new System.Windows.Forms.CheckedListBox();
            this.textTopicDesc = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textTopic = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.combForums = new System.Windows.Forms.ComboBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnAddNew = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.delTopic = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnUnselectAll);
            this.groupBox1.Controls.Add(this.btnSelectAll);
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Controls.Add(this.checkAdminApr);
            this.groupBox1.Controls.Add(this.chkListEmails);
            this.groupBox1.Controls.Add(this.textTopicDesc);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textTopic);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.combForums);
            this.groupBox1.Location = new System.Drawing.Point(27, 25);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(492, 505);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Forum Topic Settings";
            // 
            // btnUnselectAll
            // 
            this.btnUnselectAll.Location = new System.Drawing.Point(395, 257);
            this.btnUnselectAll.Name = "btnUnselectAll";
            this.btnUnselectAll.Size = new System.Drawing.Size(75, 23);
            this.btnUnselectAll.TabIndex = 10;
            this.btnUnselectAll.Text = "UnSelect All";
            this.btnUnselectAll.UseVisualStyleBackColor = true;
            this.btnUnselectAll.Click += new System.EventHandler(this.btnUnselectAll_Click);
            // 
            // btnSelectAll
            // 
            this.btnSelectAll.Location = new System.Drawing.Point(395, 186);
            this.btnSelectAll.Name = "btnSelectAll";
            this.btnSelectAll.Size = new System.Drawing.Size(75, 23);
            this.btnSelectAll.TabIndex = 9;
            this.btnSelectAll.Text = "Select all";
            this.btnSelectAll.UseVisualStyleBackColor = true;
            this.btnSelectAll.Click += new System.EventHandler(this.btnSelectAll_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.listBoxTopics);
            this.groupBox2.Location = new System.Drawing.Point(116, 325);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(272, 147);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Existing Topics";
            // 
            // listBoxTopics
            // 
            this.listBoxTopics.FormattingEnabled = true;
            this.listBoxTopics.Location = new System.Drawing.Point(20, 19);
            this.listBoxTopics.Name = "listBoxTopics";
            this.listBoxTopics.Size = new System.Drawing.Size(239, 108);
            this.listBoxTopics.TabIndex = 0;
            this.listBoxTopics.SelectedIndexChanged += new System.EventHandler(this.listBoxTopics_SelectedIndexChanged);
            // 
            // checkAdminApr
            // 
            this.checkAdminApr.AutoSize = true;
            this.checkAdminApr.Location = new System.Drawing.Point(137, 287);
            this.checkAdminApr.Name = "checkAdminApr";
            this.checkAdminApr.Size = new System.Drawing.Size(160, 17);
            this.checkAdminApr.TabIndex = 7;
            this.checkAdminApr.Text = "Need Administrator Approval";
            this.checkAdminApr.UseVisualStyleBackColor = true;
            // 
            // chkListEmails
            // 
            this.chkListEmails.FormattingEnabled = true;
            this.chkListEmails.Location = new System.Drawing.Point(137, 186);
            this.chkListEmails.Name = "chkListEmails";
            this.chkListEmails.Size = new System.Drawing.Size(251, 94);
            this.chkListEmails.TabIndex = 6;
            // 
            // textTopicDesc
            // 
            this.textTopicDesc.Location = new System.Drawing.Point(136, 119);
            this.textTopicDesc.Multiline = true;
            this.textTopicDesc.Name = "textTopicDesc";
            this.textTopicDesc.Size = new System.Drawing.Size(252, 60);
            this.textTopicDesc.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(27, 119);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(99, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Topic Description  :";
            // 
            // textTopic
            // 
            this.textTopic.Location = new System.Drawing.Point(137, 77);
            this.textTopic.Name = "textTopic";
            this.textTopic.Size = new System.Drawing.Size(252, 20);
            this.textTopic.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(52, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Topic Name  :*";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(112, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Existing Forum Name :";
            // 
            // combForums
            // 
            this.combForums.FormattingEnabled = true;
            this.combForums.Location = new System.Drawing.Point(136, 35);
            this.combForums.Name = "combForums";
            this.combForums.Size = new System.Drawing.Size(253, 21);
            this.combForums.TabIndex = 0;
            this.combForums.SelectedIndexChanged += new System.EventHandler(this.combForums_SelectedIndexChanged);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(340, 546);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 1;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnAddNew
            // 
            this.btnAddNew.Location = new System.Drawing.Point(249, 546);
            this.btnAddNew.Name = "btnAddNew";
            this.btnAddNew.Size = new System.Drawing.Size(75, 23);
            this.btnAddNew.TabIndex = 2;
            this.btnAddNew.Text = "Add New";
            this.btnAddNew.UseVisualStyleBackColor = true;
            this.btnAddNew.Visible = false;
            this.btnAddNew.Click += new System.EventHandler(this.btnAddNew_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(444, 546);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 3;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // delTopic
            // 
            this.delTopic.Location = new System.Drawing.Point(163, 546);
            this.delTopic.Name = "delTopic";
            this.delTopic.Size = new System.Drawing.Size(75, 23);
            this.delTopic.TabIndex = 5;
            this.delTopic.Text = "Delete";
            this.delTopic.UseVisualStyleBackColor = true;
            this.delTopic.Click += new System.EventHandler(this.delTopic_Click);
            // 
            // AddTopic
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(561, 591);
            this.Controls.Add(this.delTopic);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAddNew);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddTopic";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AddTopic";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox checkAdminApr;
        private System.Windows.Forms.CheckedListBox chkListEmails;
        private System.Windows.Forms.TextBox textTopicDesc;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textTopic;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox combForums;
        private System.Windows.Forms.ListBox listBoxTopics;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnAddNew;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnUnselectAll;
        private System.Windows.Forms.Button btnSelectAll;
        private System.Windows.Forms.Button delTopic;
    }
}