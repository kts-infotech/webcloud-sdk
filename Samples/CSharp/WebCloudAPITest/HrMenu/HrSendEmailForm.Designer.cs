
namespace WebCloudAPITest
{
    partial class HrSendEmailForm
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
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnSendHrMail = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.flowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.btnAttach = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.textSubject = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textMessage = new System.Windows.Forms.RichTextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.textBcc = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textCc = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textHRID = new System.Windows.Forms.TextBox();
            this.textFromID = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btnSendHrMail);
            this.groupBox5.Location = new System.Drawing.Point(462, 225);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(168, 116);
            this.groupBox5.TabIndex = 25;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Send Mail";
            // 
            // btnSendHrMail
            // 
            this.btnSendHrMail.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnSendHrMail.BackgroundImage = global::WebCloudAPITest.Properties.Resources.Send_256x256;
            this.btnSendHrMail.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnSendHrMail.FlatAppearance.BorderSize = 0;
            this.btnSendHrMail.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSendHrMail.Location = new System.Drawing.Point(35, 19);
            this.btnSendHrMail.Name = "btnSendHrMail";
            this.btnSendHrMail.Size = new System.Drawing.Size(100, 75);
            this.btnSendHrMail.TabIndex = 7;
            this.btnSendHrMail.UseVisualStyleBackColor = false;
            this.btnSendHrMail.Click += new System.EventHandler(this.btnSendHrMail_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.flowLayoutPanel);
            this.groupBox4.Controls.Add(this.btnAttach);
            this.groupBox4.Location = new System.Drawing.Point(17, 259);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(439, 68);
            this.groupBox4.TabIndex = 24;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Attachments";
            // 
            // flowLayoutPanel
            // 
            this.flowLayoutPanel.AutoSize = true;
            this.flowLayoutPanel.Location = new System.Drawing.Point(114, 19);
            this.flowLayoutPanel.Name = "flowLayoutPanel";
            this.flowLayoutPanel.Size = new System.Drawing.Size(306, 35);
            this.flowLayoutPanel.TabIndex = 17;
            // 
            // btnAttach
            // 
            this.btnAttach.Image = global::WebCloudAPITest.Properties.Resources.Add_16x16;
            this.btnAttach.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAttach.Location = new System.Drawing.Point(19, 19);
            this.btnAttach.Name = "btnAttach";
            this.btnAttach.Size = new System.Drawing.Size(52, 32);
            this.btnAttach.TabIndex = 16;
            this.btnAttach.Text = "Add";
            this.btnAttach.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnAttach.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.btnAttach.UseVisualStyleBackColor = true;
            this.btnAttach.Click += new System.EventHandler(this.btnAttach_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textSubject);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Location = new System.Drawing.Point(17, 175);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(439, 50);
            this.groupBox3.TabIndex = 23;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Subject Line";
            // 
            // textSubject
            // 
            this.textSubject.Location = new System.Drawing.Point(75, 19);
            this.textSubject.Name = "textSubject";
            this.textSubject.Size = new System.Drawing.Size(345, 20);
            this.textSubject.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 22);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Subject :";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textMessage);
            this.groupBox1.Location = new System.Drawing.Point(17, 347);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(610, 198);
            this.groupBox1.TabIndex = 21;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Message";
            // 
            // textMessage
            // 
            this.textMessage.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textMessage.Location = new System.Drawing.Point(19, 19);
            this.textMessage.Name = "textMessage";
            this.textMessage.Size = new System.Drawing.Size(567, 161);
            this.textMessage.TabIndex = 8;
            this.textMessage.Text = "";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textBcc);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.textCc);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.textHRID);
            this.groupBox2.Controls.Add(this.textFromID);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Location = new System.Drawing.Point(26, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(430, 139);
            this.groupBox2.TabIndex = 26;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Address";
            // 
            // textBcc
            // 
            this.textBcc.Location = new System.Drawing.Point(49, 107);
            this.textBcc.Name = "textBcc";
            this.textBcc.Size = new System.Drawing.Size(362, 20);
            this.textBcc.TabIndex = 22;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(10, 107);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(32, 13);
            this.label6.TabIndex = 21;
            this.label6.Text = "Bcc :";
            // 
            // textCc
            // 
            this.textCc.Location = new System.Drawing.Point(49, 76);
            this.textCc.Name = "textCc";
            this.textCc.Size = new System.Drawing.Size(362, 20);
            this.textCc.TabIndex = 20;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(16, 79);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(26, 13);
            this.label5.TabIndex = 19;
            this.label5.Text = "Cc :";
            // 
            // textHRID
            // 
            this.textHRID.Location = new System.Drawing.Point(49, 48);
            this.textHRID.Name = "textHRID";
            this.textHRID.Size = new System.Drawing.Size(362, 20);
            this.textHRID.TabIndex = 18;
            // 
            // textFromID
            // 
            this.textFromID.Location = new System.Drawing.Point(49, 20);
            this.textFromID.Name = "textFromID";
            this.textFromID.ReadOnly = true;
            this.textFromID.Size = new System.Drawing.Size(362, 20);
            this.textFromID.TabIndex = 17;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 16;
            this.label2.Text = "To :";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 13);
            this.label1.TabIndex = 15;
            this.label1.Text = "From :";
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(552, 551);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 27;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // HrSendEmailForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(655, 583);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "HrSendEmailForm";
            this.ShowIcon = false;
            this.Text = "Send Email";
            this.groupBox5.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button btnSendHrMail;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel;
        private System.Windows.Forms.Button btnAttach;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textSubject;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox textMessage;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textBcc;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textCc;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textHRID;
        private System.Windows.Forms.TextBox textFromID;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCancel;
    }
}