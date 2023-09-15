
namespace WebCloudAPITest
{
    partial class TextChatForm
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
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.labelStatus = new System.Windows.Forms.Label();
            this.groupOnlineMem = new System.Windows.Forms.GroupBox();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.combOnlineMemb = new System.Windows.Forms.ComboBox();
            this.groupBoxChatMode = new System.Windows.Forms.GroupBox();
            this.radMemberChat = new System.Windows.Forms.RadioButton();
            this.radSupportUser = new System.Windows.Forms.RadioButton();
            this.btnConnect = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.textPhone = new System.Windows.Forms.TextBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.textEmail = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.textNickName = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.flowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.btnSentMsg = new System.Windows.Forms.Button();
            this.TextBoxChat = new System.Windows.Forms.RichTextBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox8.SuspendLayout();
            this.groupOnlineMem.SuspendLayout();
            this.groupBoxChatMode.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.groupBox8);
            this.groupBox1.Controls.Add(this.groupOnlineMem);
            this.groupBox1.Controls.Add(this.groupBoxChatMode);
            this.groupBox1.Controls.Add(this.btnConnect);
            this.groupBox1.Controls.Add(this.groupBox5);
            this.groupBox1.Controls.Add(this.groupBox4);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(542, 237);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Enter Your Details";
            // 
            // groupBox8
            // 
            this.groupBox8.Controls.Add(this.labelStatus);
            this.groupBox8.Location = new System.Drawing.Point(7, 180);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Size = new System.Drawing.Size(520, 37);
            this.groupBox8.TabIndex = 6;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "Connection Status";
            // 
            // labelStatus
            // 
            this.labelStatus.AutoSize = true;
            this.labelStatus.ForeColor = System.Drawing.Color.Red;
            this.labelStatus.Location = new System.Drawing.Point(6, 17);
            this.labelStatus.Name = "labelStatus";
            this.labelStatus.Size = new System.Drawing.Size(43, 13);
            this.labelStatus.TabIndex = 5;
            this.labelStatus.Text = "............";
            // 
            // groupOnlineMem
            // 
            this.groupOnlineMem.Controls.Add(this.btnRefresh);
            this.groupOnlineMem.Controls.Add(this.combOnlineMemb);
            this.groupOnlineMem.Enabled = false;
            this.groupOnlineMem.Location = new System.Drawing.Point(7, 127);
            this.groupOnlineMem.Name = "groupOnlineMem";
            this.groupOnlineMem.Size = new System.Drawing.Size(390, 46);
            this.groupOnlineMem.TabIndex = 3;
            this.groupOnlineMem.TabStop = false;
            this.groupOnlineMem.Text = "Select Available Online Member To Chat";
            // 
            // btnRefresh
            // 
            this.btnRefresh.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnRefresh.Image = global::WebCloudAPITest.Properties.Resources.refresh;
            this.btnRefresh.Location = new System.Drawing.Point(344, 15);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(31, 23);
            this.btnRefresh.TabIndex = 2;
            this.btnRefresh.UseVisualStyleBackColor = false;
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // combOnlineMemb
            // 
            this.combOnlineMemb.FormattingEnabled = true;
            this.combOnlineMemb.Location = new System.Drawing.Point(9, 15);
            this.combOnlineMemb.Name = "combOnlineMemb";
            this.combOnlineMemb.Size = new System.Drawing.Size(329, 21);
            this.combOnlineMemb.TabIndex = 0;
            this.combOnlineMemb.SelectedIndexChanged += new System.EventHandler(this.combOnlineMemb_SelectedIndexChanged);
            // 
            // groupBoxChatMode
            // 
            this.groupBoxChatMode.Controls.Add(this.radMemberChat);
            this.groupBoxChatMode.Controls.Add(this.radSupportUser);
            this.groupBoxChatMode.Location = new System.Drawing.Point(266, 75);
            this.groupBoxChatMode.Name = "groupBoxChatMode";
            this.groupBoxChatMode.Size = new System.Drawing.Size(261, 46);
            this.groupBoxChatMode.TabIndex = 4;
            this.groupBoxChatMode.TabStop = false;
            this.groupBoxChatMode.Text = "Select Chat Mode";
            // 
            // radMemberChat
            // 
            this.radMemberChat.AutoSize = true;
            this.radMemberChat.Location = new System.Drawing.Point(137, 19);
            this.radMemberChat.Name = "radMemberChat";
            this.radMemberChat.Size = new System.Drawing.Size(118, 17);
            this.radMemberChat.TabIndex = 1;
            this.radMemberChat.Text = "Member Chat Mode";
            this.radMemberChat.UseVisualStyleBackColor = true;
            this.radMemberChat.CheckedChanged += new System.EventHandler(this.radMemberChat_CheckedChanged);
            // 
            // radSupportUser
            // 
            this.radSupportUser.AutoSize = true;
            this.radSupportUser.Checked = true;
            this.radSupportUser.Location = new System.Drawing.Point(14, 20);
            this.radSupportUser.Name = "radSupportUser";
            this.radSupportUser.Size = new System.Drawing.Size(117, 17);
            this.radSupportUser.TabIndex = 0;
            this.radSupportUser.TabStop = true;
            this.radSupportUser.Text = "Support User Mode";
            this.radSupportUser.UseVisualStyleBackColor = true;
            // 
            // btnConnect
            // 
            this.btnConnect.BackColor = System.Drawing.Color.LimeGreen;
            this.btnConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnConnect.Image = global::WebCloudAPITest.Properties.Resources.Globe_16x16;
            this.btnConnect.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnConnect.Location = new System.Drawing.Point(411, 140);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(100, 23);
            this.btnConnect.TabIndex = 4;
            this.btnConnect.Text = "Connect";
            this.btnConnect.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnConnect.UseVisualStyleBackColor = false;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.textPhone);
            this.groupBox5.Location = new System.Drawing.Point(7, 75);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(253, 46);
            this.groupBox5.TabIndex = 3;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Enter Your Phone Number";
            // 
            // textPhone
            // 
            this.textPhone.Location = new System.Drawing.Point(7, 16);
            this.textPhone.MaxLength = 11;
            this.textPhone.Name = "textPhone";
            this.textPhone.Size = new System.Drawing.Size(233, 20);
            this.textPhone.TabIndex = 0;
            this.textPhone.Text = "7594985084";
            this.textPhone.WordWrap = false;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.textEmail);
            this.groupBox4.Location = new System.Drawing.Point(266, 23);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(261, 46);
            this.groupBox4.TabIndex = 2;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Enter Your Email";
            // 
            // textEmail
            // 
            this.textEmail.Location = new System.Drawing.Point(7, 16);
            this.textEmail.Name = "textEmail";
            this.textEmail.Size = new System.Drawing.Size(248, 20);
            this.textEmail.TabIndex = 0;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textNickName);
            this.groupBox3.Location = new System.Drawing.Point(7, 23);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(253, 46);
            this.groupBox3.TabIndex = 1;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Enter Nick Name";
            // 
            // textNickName
            // 
            this.textNickName.Location = new System.Drawing.Point(7, 16);
            this.textNickName.Name = "textNickName";
            this.textNickName.Size = new System.Drawing.Size(233, 20);
            this.textNickName.TabIndex = 0;
            this.textNickName.Text = "Kts";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.flowLayoutPanel);
            this.groupBox2.Controls.Add(this.btnSentMsg);
            this.groupBox2.Controls.Add(this.TextBoxChat);
            this.groupBox2.Location = new System.Drawing.Point(12, 256);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(542, 346);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Chat";
            // 
            // flowLayoutPanel
            // 
            this.flowLayoutPanel.AutoScroll = true;
            this.flowLayoutPanel.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.flowLayoutPanel.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel.Location = new System.Drawing.Point(7, 20);
            this.flowLayoutPanel.Margin = new System.Windows.Forms.Padding(9);
            this.flowLayoutPanel.Name = "flowLayoutPanel";
            this.flowLayoutPanel.Size = new System.Drawing.Size(520, 231);
            this.flowLayoutPanel.TabIndex = 0;
            this.flowLayoutPanel.WrapContents = false;
            // 
            // btnSentMsg
            // 
            this.btnSentMsg.Image = global::WebCloudAPITest.Properties.Resources.Telegram_64;
            this.btnSentMsg.Location = new System.Drawing.Point(446, 269);
            this.btnSentMsg.Name = "btnSentMsg";
            this.btnSentMsg.Size = new System.Drawing.Size(75, 71);
            this.btnSentMsg.TabIndex = 2;
            this.btnSentMsg.UseVisualStyleBackColor = true;
            this.btnSentMsg.Click += new System.EventHandler(this.btnSentMsg_Click);
            // 
            // TextBoxChat
            // 
            this.TextBoxChat.Location = new System.Drawing.Point(14, 263);
            this.TextBoxChat.Name = "TextBoxChat";
            this.TextBoxChat.Size = new System.Drawing.Size(416, 52);
            this.TextBoxChat.TabIndex = 1;
            this.TextBoxChat.Text = "";
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(464, 618);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 3;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // TextChatForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(576, 662);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TextChatForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TextChatForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox8.ResumeLayout(false);
            this.groupBox8.PerformLayout();
            this.groupOnlineMem.ResumeLayout(false);
            this.groupBoxChatMode.ResumeLayout(false);
            this.groupBoxChatMode.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.TextBox textPhone;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox textEmail;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textNickName;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnSentMsg;
        private System.Windows.Forms.RichTextBox TextBoxChat;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.GroupBox groupBox8;
        private System.Windows.Forms.GroupBox groupOnlineMem;
        private System.Windows.Forms.GroupBox groupBoxChatMode;
        private System.Windows.Forms.RadioButton radMemberChat;
        private System.Windows.Forms.RadioButton radSupportUser;
        private System.Windows.Forms.ComboBox combOnlineMemb;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Button btnClose;
    }
}