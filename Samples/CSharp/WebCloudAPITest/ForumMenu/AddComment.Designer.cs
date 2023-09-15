
namespace WebCloudAPITest.ForumMenu
{
    partial class AddComment
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
            this.label3 = new System.Windows.Forms.Label();
            this.comboThreadID = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.comboTopicID = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.comboForumID = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBoxCmts = new System.Windows.Forms.TextBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnAddCmts = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.comboThreadID);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.comboTopicID);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.comboForumID);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(308, 149);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select ForumID,TopicID and ThreadID";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 109);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(94, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Select Thread ID :";
            // 
            // comboThreadID
            // 
            this.comboThreadID.FormattingEnabled = true;
            this.comboThreadID.Location = new System.Drawing.Point(102, 106);
            this.comboThreadID.Name = "comboThreadID";
            this.comboThreadID.Size = new System.Drawing.Size(162, 21);
            this.comboThreadID.TabIndex = 4;
            this.comboThreadID.SelectedIndexChanged += new System.EventHandler(this.comboThreadID_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(87, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Select Topic ID :";
            // 
            // comboTopicID
            // 
            this.comboTopicID.FormattingEnabled = true;
            this.comboTopicID.Location = new System.Drawing.Point(102, 65);
            this.comboTopicID.Name = "comboTopicID";
            this.comboTopicID.Size = new System.Drawing.Size(162, 21);
            this.comboTopicID.TabIndex = 2;
            this.comboTopicID.SelectedIndexChanged += new System.EventHandler(this.comboTopicID_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Select Forum ID :";
            // 
            // comboForumID
            // 
            this.comboForumID.FormattingEnabled = true;
            this.comboForumID.Location = new System.Drawing.Point(102, 26);
            this.comboForumID.Name = "comboForumID";
            this.comboForumID.Size = new System.Drawing.Size(162, 21);
            this.comboForumID.TabIndex = 0;
            this.comboForumID.SelectedIndexChanged += new System.EventHandler(this.comboForumID_SelectedIndexChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textBoxCmts);
            this.groupBox2.Location = new System.Drawing.Point(13, 168);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(307, 94);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Add Comments";
            // 
            // textBoxCmts
            // 
            this.textBoxCmts.Location = new System.Drawing.Point(9, 22);
            this.textBoxCmts.Multiline = true;
            this.textBoxCmts.Name = "textBoxCmts";
            this.textBoxCmts.Size = new System.Drawing.Size(292, 59);
            this.textBoxCmts.TabIndex = 0;
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(34, 290);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(123, 23);
            this.btnCancel.TabIndex = 5;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnAddCmts
            // 
            this.btnAddCmts.Location = new System.Drawing.Point(186, 290);
            this.btnAddCmts.Name = "btnAddCmts";
            this.btnAddCmts.Size = new System.Drawing.Size(123, 23);
            this.btnAddCmts.TabIndex = 4;
            this.btnAddCmts.Text = "Add Comments";
            this.btnAddCmts.UseVisualStyleBackColor = true;
            this.btnAddCmts.Click += new System.EventHandler(this.btnAddCmts_Click);
            // 
            // AddComment
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(342, 337);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnAddCmts);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddComment";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AddComment";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboThreadID;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboTopicID;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboForumID;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textBoxCmts;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnAddCmts;
    }
}