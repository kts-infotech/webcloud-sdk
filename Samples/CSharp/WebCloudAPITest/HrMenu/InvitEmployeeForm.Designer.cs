namespace WebCloudAPITest
{
    partial class InvitEmployeeForm
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
            this.comUsrCat = new System.Windows.Forms.ComboBox();
            this.comEmplyType = new System.Windows.Forms.ComboBox();
            this.txtEmailList = new System.Windows.Forms.TextBox();
            this.txtMessage = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnInviteEmpl = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // comUsrCat
            // 
            this.comUsrCat.FormattingEnabled = true;
            this.comUsrCat.Location = new System.Drawing.Point(182, 30);
            this.comUsrCat.Name = "comUsrCat";
            this.comUsrCat.Size = new System.Drawing.Size(232, 21);
            this.comUsrCat.TabIndex = 0;
            // 
            // comEmplyType
            // 
            this.comEmplyType.FormattingEnabled = true;
            this.comEmplyType.Location = new System.Drawing.Point(182, 57);
            this.comEmplyType.Name = "comEmplyType";
            this.comEmplyType.Size = new System.Drawing.Size(232, 21);
            this.comEmplyType.TabIndex = 1;
            // 
            // txtEmailList
            // 
            this.txtEmailList.Location = new System.Drawing.Point(182, 84);
            this.txtEmailList.Multiline = true;
            this.txtEmailList.Name = "txtEmailList";
            this.txtEmailList.Size = new System.Drawing.Size(232, 50);
            this.txtEmailList.TabIndex = 2;
            // 
            // txtMessage
            // 
            this.txtMessage.Location = new System.Drawing.Point(182, 140);
            this.txtMessage.Multiline = true;
            this.txtMessage.Name = "txtMessage";
            this.txtMessage.Size = new System.Drawing.Size(232, 62);
            this.txtMessage.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(117, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Select User Category(*)";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(123, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Select Employee Type(*)";
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(24, 84);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(137, 27);
            this.label3.TabIndex = 6;
            this.label3.Text = "Enter User Email Address(s) Seperated by comma(*)";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(24, 140);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(151, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Enter Email Message(Optional)";
            // 
            // btnInviteEmpl
            // 
            this.btnInviteEmpl.Location = new System.Drawing.Point(182, 227);
            this.btnInviteEmpl.Name = "btnInviteEmpl";
            this.btnInviteEmpl.Size = new System.Drawing.Size(232, 41);
            this.btnInviteEmpl.TabIndex = 8;
            this.btnInviteEmpl.Text = "Invite Employee";
            this.btnInviteEmpl.UseVisualStyleBackColor = true;
            this.btnInviteEmpl.Click += new System.EventHandler(this.btnInviteEmpl_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.btnInviteEmpl);
            this.groupBox1.Controls.Add(this.comUsrCat);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.comEmplyType);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.txtEmailList);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.txtMessage);
            this.groupBox1.Location = new System.Drawing.Point(12, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(445, 292);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Invite Employee";
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(369, 323);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 10;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // InvitEmployeeForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(479, 363);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "InvitEmployeeForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "InvitEmployeeForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox comUsrCat;
        private System.Windows.Forms.ComboBox comEmplyType;
        private System.Windows.Forms.TextBox txtEmailList;
        private System.Windows.Forms.TextBox txtMessage;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnInviteEmpl;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnClose;
    }
}