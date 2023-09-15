
namespace WebCloudAPITest
{
    partial class VoiceChatForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(VoiceChatForm));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.labelStatus = new System.Windows.Forms.Label();
            this.groupOnlineMem = new System.Windows.Forms.GroupBox();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.combOnlineMemb = new System.Windows.Forms.ComboBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.textPhone = new System.Windows.Forms.TextBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.textEmail = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.textNickName = new System.Windows.Forms.TextBox();
            this.callerGroup = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnDisconCall = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.lbPhoneGif = new System.Windows.Forms.Label();
            this.btnPhCall = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.lbCallerID = new System.Windows.Forms.Label();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox8.SuspendLayout();
            this.groupOnlineMem.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.callerGroup.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Controls.Add(this.groupBox8);
            this.groupBox1.Controls.Add(this.groupOnlineMem);
            this.groupBox1.Controls.Add(this.groupBox5);
            this.groupBox1.Controls.Add(this.groupBox4);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Location = new System.Drawing.Point(14, 5);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(537, 172);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Enter Your Details";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnConnect);
            this.groupBox2.Location = new System.Drawing.Point(369, 75);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(152, 46);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Enter Your Email";
            // 
            // btnConnect
            // 
            this.btnConnect.BackColor = System.Drawing.Color.LimeGreen;
            this.btnConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnect.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnConnect.Image = global::WebCloudAPITest.Properties.Resources.Globe_16x16;
            this.btnConnect.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnConnect.Location = new System.Drawing.Point(22, 15);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(100, 23);
            this.btnConnect.TabIndex = 4;
            this.btnConnect.Text = "Connect";
            this.btnConnect.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnConnect.UseVisualStyleBackColor = false;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // groupBox8
            // 
            this.groupBox8.Controls.Add(this.labelStatus);
            this.groupBox8.Location = new System.Drawing.Point(6, 127);
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
            this.groupOnlineMem.Location = new System.Drawing.Point(6, 75);
            this.groupOnlineMem.Name = "groupOnlineMem";
            this.groupOnlineMem.Size = new System.Drawing.Size(357, 46);
            this.groupOnlineMem.TabIndex = 3;
            this.groupOnlineMem.TabStop = false;
            this.groupOnlineMem.Text = "Select Available Online Member To Chat";
            // 
            // btnRefresh
            // 
            this.btnRefresh.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btnRefresh.Image = global::WebCloudAPITest.Properties.Resources.refresh;
            this.btnRefresh.Location = new System.Drawing.Point(308, 13);
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
            this.combOnlineMemb.Size = new System.Drawing.Size(293, 21);
            this.combOnlineMemb.TabIndex = 0;
            this.combOnlineMemb.SelectedIndexChanged += new System.EventHandler(this.combOnlineMemb_SelectedIndexChanged);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.textPhone);
            this.groupBox5.Location = new System.Drawing.Point(369, 23);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(152, 46);
            this.groupBox5.TabIndex = 3;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Enter Your Phone Number";
            // 
            // textPhone
            // 
            this.textPhone.Location = new System.Drawing.Point(7, 16);
            this.textPhone.MaxLength = 11;
            this.textPhone.Name = "textPhone";
            this.textPhone.Size = new System.Drawing.Size(130, 20);
            this.textPhone.TabIndex = 0;
            this.textPhone.Text = "7594985084";
            this.textPhone.WordWrap = false;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.textEmail);
            this.groupBox4.Location = new System.Drawing.Point(160, 23);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(203, 46);
            this.groupBox4.TabIndex = 2;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Enter Your Email";
            // 
            // textEmail
            // 
            this.textEmail.Location = new System.Drawing.Point(7, 16);
            this.textEmail.Name = "textEmail";
            this.textEmail.Size = new System.Drawing.Size(178, 20);
            this.textEmail.TabIndex = 0;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textNickName);
            this.groupBox3.Location = new System.Drawing.Point(7, 23);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(147, 46);
            this.groupBox3.TabIndex = 1;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Enter Nick Name";
            // 
            // textNickName
            // 
            this.textNickName.Location = new System.Drawing.Point(7, 16);
            this.textNickName.Name = "textNickName";
            this.textNickName.Size = new System.Drawing.Size(130, 20);
            this.textNickName.TabIndex = 0;
            this.textNickName.Text = "Kts";
            // 
            // callerGroup
            // 
            this.callerGroup.Controls.Add(this.label2);
            this.callerGroup.Controls.Add(this.btnDisconCall);
            this.callerGroup.Controls.Add(this.label1);
            this.callerGroup.Controls.Add(this.lbPhoneGif);
            this.callerGroup.Controls.Add(this.btnPhCall);
            this.callerGroup.Enabled = false;
            this.callerGroup.Location = new System.Drawing.Point(14, 184);
            this.callerGroup.Margin = new System.Windows.Forms.Padding(20);
            this.callerGroup.Name = "callerGroup";
            this.callerGroup.Size = new System.Drawing.Size(537, 106);
            this.callerGroup.TabIndex = 2;
            this.callerGroup.TabStop = false;
            this.callerGroup.Text = "Caller Function";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(227, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Stop Call";
            // 
            // btnDisconCall
            // 
            this.btnDisconCall.BackgroundImage = global::WebCloudAPITest.Properties.Resources.hang_up;
            this.btnDisconCall.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnDisconCall.Enabled = false;
            this.btnDisconCall.FlatAppearance.BorderSize = 0;
            this.btnDisconCall.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnDisconCall.Location = new System.Drawing.Point(229, 19);
            this.btnDisconCall.Name = "btnDisconCall";
            this.btnDisconCall.Size = new System.Drawing.Size(49, 49);
            this.btnDisconCall.TabIndex = 3;
            this.btnDisconCall.UseVisualStyleBackColor = true;
            this.btnDisconCall.Click += new System.EventHandler(this.btnDisconCall_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(113, 78);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Start Call";
            // 
            // lbPhoneGif
            // 
            this.lbPhoneGif.Image = ((System.Drawing.Image)(resources.GetObject("lbPhoneGif.Image")));
            this.lbPhoneGif.Location = new System.Drawing.Point(420, 15);
            this.lbPhoneGif.MinimumSize = new System.Drawing.Size(10, 0);
            this.lbPhoneGif.Name = "lbPhoneGif";
            this.lbPhoneGif.Size = new System.Drawing.Size(71, 68);
            this.lbPhoneGif.TabIndex = 1;
            this.lbPhoneGif.Visible = false;
            // 
            // btnPhCall
            // 
            this.btnPhCall.BackgroundImage = global::WebCloudAPITest.Properties.Resources.dial;
            this.btnPhCall.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnPhCall.FlatAppearance.BorderSize = 0;
            this.btnPhCall.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnPhCall.Location = new System.Drawing.Point(115, 19);
            this.btnPhCall.Name = "btnPhCall";
            this.btnPhCall.Size = new System.Drawing.Size(49, 49);
            this.btnPhCall.TabIndex = 0;
            this.btnPhCall.UseVisualStyleBackColor = true;
            this.btnPhCall.Click += new System.EventHandler(this.btnPhCall_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.lbCallerID);
            this.groupBox6.Location = new System.Drawing.Point(14, 305);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(537, 42);
            this.groupBox6.TabIndex = 3;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Caller Information";
            // 
            // lbCallerID
            // 
            this.lbCallerID.AutoSize = true;
            this.lbCallerID.Location = new System.Drawing.Point(12, 19);
            this.lbCallerID.Name = "lbCallerID";
            this.lbCallerID.Size = new System.Drawing.Size(27, 13);
            this.lbCallerID.TabIndex = 6;
            this.lbCallerID.Text = "info:";
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(460, 357);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 4;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // VoiceChatForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(573, 392);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.callerGroup);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "VoiceChatForm";
            this.Text = "VoiceChatForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox8.ResumeLayout(false);
            this.groupBox8.PerformLayout();
            this.groupOnlineMem.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.callerGroup.ResumeLayout(false);
            this.callerGroup.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.GroupBox groupBox8;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.GroupBox groupOnlineMem;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.ComboBox combOnlineMemb;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.TextBox textPhone;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox textEmail;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textNickName;
        private System.Windows.Forms.GroupBox callerGroup;
        private System.Windows.Forms.Button btnPhCall;
        private System.Windows.Forms.Label lbPhoneGif;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnDisconCall;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Label lbCallerID;
        private System.Windows.Forms.Button btnClose;
    }
}