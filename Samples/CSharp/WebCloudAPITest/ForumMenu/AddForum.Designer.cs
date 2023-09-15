
namespace WebCloudAPITest.ForumMenu
{
    partial class AddForum
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
            this.btnRtrvEmail = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.listBoxExistingForum = new System.Windows.Forms.ListBox();
            this.textEmails = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.combSelGroup = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textDesc = new System.Windows.Forms.TextBox();
            this.lableDesc = new System.Windows.Forms.Label();
            this.checkIsOnlyAdmin = new System.Windows.Forms.CheckBox();
            this.checkIsPrivate = new System.Windows.Forms.CheckBox();
            this.combForumType = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textForumName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnAddNew = new System.Windows.Forms.Button();
            this.delForum = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnRtrvEmail);
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Controls.Add(this.textEmails);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.combSelGroup);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textDesc);
            this.groupBox1.Controls.Add(this.lableDesc);
            this.groupBox1.Controls.Add(this.checkIsOnlyAdmin);
            this.groupBox1.Controls.Add(this.checkIsPrivate);
            this.groupBox1.Controls.Add(this.combForumType);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textForumName);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(548, 497);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Forum Settings";
            // 
            // btnRtrvEmail
            // 
            this.btnRtrvEmail.Location = new System.Drawing.Point(422, 211);
            this.btnRtrvEmail.Name = "btnRtrvEmail";
            this.btnRtrvEmail.Size = new System.Drawing.Size(102, 23);
            this.btnRtrvEmail.TabIndex = 13;
            this.btnRtrvEmail.Text = "Retrieve Email";
            this.btnRtrvEmail.UseVisualStyleBackColor = true;
            this.btnRtrvEmail.Click += new System.EventHandler(this.btnRtrvEmail_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.listBoxExistingForum);
            this.groupBox2.Location = new System.Drawing.Point(23, 351);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(395, 127);
            this.groupBox2.TabIndex = 12;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Exixting Forum Names";
            // 
            // listBoxExistingForum
            // 
            this.listBoxExistingForum.FormattingEnabled = true;
            this.listBoxExistingForum.Location = new System.Drawing.Point(17, 19);
            this.listBoxExistingForum.Name = "listBoxExistingForum";
            this.listBoxExistingForum.Size = new System.Drawing.Size(362, 95);
            this.listBoxExistingForum.TabIndex = 0;
            this.listBoxExistingForum.SelectedIndexChanged += new System.EventHandler(this.listBoxExistingForum_SelectedIndexChanged);
            // 
            // textEmails
            // 
            this.textEmails.Location = new System.Drawing.Point(107, 258);
            this.textEmails.Multiline = true;
            this.textEmails.Name = "textEmails";
            this.textEmails.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textEmails.Size = new System.Drawing.Size(295, 75);
            this.textEmails.TabIndex = 11;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 261);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(92, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Participant EMail :";
            // 
            // combSelGroup
            // 
            this.combSelGroup.FormattingEnabled = true;
            this.combSelGroup.Location = new System.Drawing.Point(107, 211);
            this.combSelGroup.Name = "combSelGroup";
            this.combSelGroup.Size = new System.Drawing.Size(295, 21);
            this.combSelGroup.TabIndex = 9;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(20, 214);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(78, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Select Group  :";
            // 
            // textDesc
            // 
            this.textDesc.Location = new System.Drawing.Point(107, 142);
            this.textDesc.Multiline = true;
            this.textDesc.Name = "textDesc";
            this.textDesc.Size = new System.Drawing.Size(295, 47);
            this.textDesc.TabIndex = 7;
            // 
            // lableDesc
            // 
            this.lableDesc.AutoSize = true;
            this.lableDesc.Location = new System.Drawing.Point(20, 145);
            this.lableDesc.Name = "lableDesc";
            this.lableDesc.Size = new System.Drawing.Size(66, 13);
            this.lableDesc.TabIndex = 6;
            this.lableDesc.Text = "Description :";
            // 
            // checkIsOnlyAdmin
            // 
            this.checkIsOnlyAdmin.AutoSize = true;
            this.checkIsOnlyAdmin.Location = new System.Drawing.Point(107, 110);
            this.checkIsOnlyAdmin.Name = "checkIsOnlyAdmin";
            this.checkIsOnlyAdmin.Size = new System.Drawing.Size(238, 17);
            this.checkIsOnlyAdmin.TabIndex = 5;
            this.checkIsOnlyAdmin.Text = "Allow only admins to start a new forum thread";
            this.checkIsOnlyAdmin.UseVisualStyleBackColor = true;
            // 
            // checkIsPrivate
            // 
            this.checkIsPrivate.AutoSize = true;
            this.checkIsPrivate.Location = new System.Drawing.Point(107, 87);
            this.checkIsPrivate.Name = "checkIsPrivate";
            this.checkIsPrivate.Size = new System.Drawing.Size(91, 17);
            this.checkIsPrivate.TabIndex = 4;
            this.checkIsPrivate.Text = "Private Forum";
            this.checkIsPrivate.UseVisualStyleBackColor = true;
            // 
            // combForumType
            // 
            this.combForumType.FormattingEnabled = true;
            this.combForumType.Location = new System.Drawing.Point(107, 50);
            this.combForumType.MaxDropDownItems = 5;
            this.combForumType.Name = "combForumType";
            this.combForumType.Size = new System.Drawing.Size(295, 21);
            this.combForumType.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(20, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(81, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Forum Type     :";
            // 
            // textForumName
            // 
            this.textForumName.Location = new System.Drawing.Point(107, 17);
            this.textForumName.Name = "textForumName";
            this.textForumName.Size = new System.Drawing.Size(295, 20);
            this.textForumName.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(20, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Forum Name * :";
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(486, 516);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 1;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(393, 516);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 2;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnAddNew
            // 
            this.btnAddNew.Location = new System.Drawing.Point(291, 517);
            this.btnAddNew.Name = "btnAddNew";
            this.btnAddNew.Size = new System.Drawing.Size(75, 23);
            this.btnAddNew.TabIndex = 3;
            this.btnAddNew.Text = "Add New";
            this.btnAddNew.UseVisualStyleBackColor = true;
            this.btnAddNew.Visible = false;
            this.btnAddNew.Click += new System.EventHandler(this.btnAddNew_Click);
            // 
            // delForum
            // 
            this.delForum.Location = new System.Drawing.Point(193, 517);
            this.delForum.Name = "delForum";
            this.delForum.Size = new System.Drawing.Size(75, 23);
            this.delForum.TabIndex = 4;
            this.delForum.Text = "Delete";
            this.delForum.UseVisualStyleBackColor = true;
            this.delForum.Click += new System.EventHandler(this.delForum_Click);
            // 
            // AddForum
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(593, 563);
            this.Controls.Add(this.delForum);
            this.Controls.Add(this.btnAddNew);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddForum";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AddForum";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ListBox listBoxExistingForum;
        private System.Windows.Forms.TextBox textEmails;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox combSelGroup;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textDesc;
        private System.Windows.Forms.Label lableDesc;
        private System.Windows.Forms.CheckBox checkIsOnlyAdmin;
        private System.Windows.Forms.CheckBox checkIsPrivate;
        private System.Windows.Forms.ComboBox combForumType;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textForumName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnRtrvEmail;
        private System.Windows.Forms.Button btnAddNew;
        private System.Windows.Forms.Button delForum;
    }
}