namespace WebCloudAPITest
{
    partial class InviteUser
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
            this.btnInviteUser = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txtMsg = new System.Windows.Forms.TextBox();
            this.txtEmailAddr = new System.Windows.Forms.TextBox();
            this.cbUserCategory = new System.Windows.Forms.ComboBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnInviteUser
            // 
            this.btnInviteUser.Location = new System.Drawing.Point(178, 221);
            this.btnInviteUser.Name = "btnInviteUser";
            this.btnInviteUser.Size = new System.Drawing.Size(133, 41);
            this.btnInviteUser.TabIndex = 17;
            this.btnInviteUser.Text = "Invite User";
            this.btnInviteUser.UseVisualStyleBackColor = true;
            this.btnInviteUser.Click += new System.EventHandler(this.btnInviteUser_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(20, 134);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(151, 13);
            this.label4.TabIndex = 16;
            this.label4.Text = "Enter Email Message(Optional)";
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(20, 78);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(137, 27);
            this.label3.TabIndex = 15;
            this.label3.Text = "Enter User Email Address(s) Seperated by comma(*)";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(20, 47);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(117, 13);
            this.label1.TabIndex = 13;
            this.label1.Text = "Select User Category(*)";
            // 
            // txtMsg
            // 
            this.txtMsg.Location = new System.Drawing.Point(178, 134);
            this.txtMsg.Multiline = true;
            this.txtMsg.Name = "txtMsg";
            this.txtMsg.Size = new System.Drawing.Size(232, 62);
            this.txtMsg.TabIndex = 12;
            // 
            // txtEmailAddr
            // 
            this.txtEmailAddr.Location = new System.Drawing.Point(178, 78);
            this.txtEmailAddr.Multiline = true;
            this.txtEmailAddr.Name = "txtEmailAddr";
            this.txtEmailAddr.Size = new System.Drawing.Size(232, 50);
            this.txtEmailAddr.TabIndex = 11;
            // 
            // cbUserCategory
            // 
            this.cbUserCategory.FormattingEnabled = true;
            this.cbUserCategory.Items.AddRange(new object[] {
            "Default"});
            this.cbUserCategory.Location = new System.Drawing.Point(178, 47);
            this.cbUserCategory.Name = "cbUserCategory";
            this.cbUserCategory.Size = new System.Drawing.Size(232, 21);
            this.cbUserCategory.TabIndex = 18;
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(323, 221);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(109, 41);
            this.btnCancel.TabIndex = 19;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // InviteUser
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(458, 307);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.cbUserCategory);
            this.Controls.Add(this.btnInviteUser);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtMsg);
            this.Controls.Add(this.txtEmailAddr);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "InviteUser";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "InviteUser";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnInviteUser;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtMsg;
        private System.Windows.Forms.TextBox txtEmailAddr;
        private System.Windows.Forms.ComboBox cbUserCategory;
        private System.Windows.Forms.Button btnCancel;
    }
}