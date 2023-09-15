
namespace WebCloudAPITest.CMSMenu
{
    partial class AddExternalLink
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
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnUpdateTitle = new System.Windows.Forms.Button();
            this.textTitle = new System.Windows.Forms.TextBox();
            this.checkShowTitle = new System.Windows.Forms.CheckBox();
            this.lbTitle = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnDown = new System.Windows.Forms.Button();
            this.btnUp = new System.Windows.Forms.Button();
            this.btnApplyOrder = new System.Windows.Forms.Button();
            this.btnRemove = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.textUrlName = new System.Windows.Forms.TextBox();
            this.textUrl = new System.Windows.Forms.TextBox();
            this.lbUrlName = new System.Windows.Forms.Label();
            this.lbURL = new System.Windows.Forms.Label();
            this.listBoxExistLinks = new System.Windows.Forms.ListBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnUpdateTitle);
            this.groupBox2.Controls.Add(this.textTitle);
            this.groupBox2.Controls.Add(this.checkShowTitle);
            this.groupBox2.Controls.Add(this.lbTitle);
            this.groupBox2.Location = new System.Drawing.Point(12, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(547, 117);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Link Title Settings";
            // 
            // btnUpdateTitle
            // 
            this.btnUpdateTitle.Location = new System.Drawing.Point(352, 68);
            this.btnUpdateTitle.Name = "btnUpdateTitle";
            this.btnUpdateTitle.Size = new System.Drawing.Size(119, 31);
            this.btnUpdateTitle.TabIndex = 3;
            this.btnUpdateTitle.Text = "Update Title";
            this.btnUpdateTitle.UseVisualStyleBackColor = true;
            this.btnUpdateTitle.Click += new System.EventHandler(this.btnUpdateTitle_Click);
            // 
            // textTitle
            // 
            this.textTitle.Location = new System.Drawing.Point(60, 23);
            this.textTitle.Name = "textTitle";
            this.textTitle.Size = new System.Drawing.Size(226, 20);
            this.textTitle.TabIndex = 2;
            // 
            // checkShowTitle
            // 
            this.checkShowTitle.AutoSize = true;
            this.checkShowTitle.Location = new System.Drawing.Point(352, 26);
            this.checkShowTitle.Name = "checkShowTitle";
            this.checkShowTitle.Size = new System.Drawing.Size(122, 17);
            this.checkShowTitle.TabIndex = 1;
            this.checkShowTitle.Text = "Show External Links";
            this.checkShowTitle.UseVisualStyleBackColor = true;
            // 
            // lbTitle
            // 
            this.lbTitle.AutoSize = true;
            this.lbTitle.Location = new System.Drawing.Point(20, 26);
            this.lbTitle.Name = "lbTitle";
            this.lbTitle.Size = new System.Drawing.Size(33, 13);
            this.lbTitle.TabIndex = 0;
            this.lbTitle.Text = "Title :";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnDown);
            this.groupBox1.Controls.Add(this.btnUp);
            this.groupBox1.Controls.Add(this.btnApplyOrder);
            this.groupBox1.Controls.Add(this.btnRemove);
            this.groupBox1.Controls.Add(this.btnUpdate);
            this.groupBox1.Controls.Add(this.btnAdd);
            this.groupBox1.Controls.Add(this.textUrlName);
            this.groupBox1.Controls.Add(this.textUrl);
            this.groupBox1.Controls.Add(this.lbUrlName);
            this.groupBox1.Controls.Add(this.lbURL);
            this.groupBox1.Controls.Add(this.listBoxExistLinks);
            this.groupBox1.Location = new System.Drawing.Point(13, 136);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(550, 270);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Other Settings";
            // 
            // btnDown
            // 
            this.btnDown.Image = global::WebCloudAPITest.Properties.Resources.arrow_down;
            this.btnDown.Location = new System.Drawing.Point(166, 127);
            this.btnDown.Name = "btnDown";
            this.btnDown.Size = new System.Drawing.Size(30, 23);
            this.btnDown.TabIndex = 10;
            this.btnDown.UseVisualStyleBackColor = true;
            this.btnDown.Click += new System.EventHandler(this.btnDown_Click);
            // 
            // btnUp
            // 
            this.btnUp.Image = global::WebCloudAPITest.Properties.Resources.arrow_up;
            this.btnUp.Location = new System.Drawing.Point(166, 81);
            this.btnUp.Name = "btnUp";
            this.btnUp.Size = new System.Drawing.Size(30, 23);
            this.btnUp.TabIndex = 9;
            this.btnUp.UseVisualStyleBackColor = true;
            this.btnUp.Click += new System.EventHandler(this.btnUp_Click);
            // 
            // btnApplyOrder
            // 
            this.btnApplyOrder.Location = new System.Drawing.Point(7, 225);
            this.btnApplyOrder.Name = "btnApplyOrder";
            this.btnApplyOrder.Size = new System.Drawing.Size(152, 23);
            this.btnApplyOrder.TabIndex = 8;
            this.btnApplyOrder.Text = "Apply Order";
            this.btnApplyOrder.UseVisualStyleBackColor = true;
            this.btnApplyOrder.Click += new System.EventHandler(this.btnApplyOrder_ClickAsync);
            // 
            // btnRemove
            // 
            this.btnRemove.Location = new System.Drawing.Point(430, 176);
            this.btnRemove.Name = "btnRemove";
            this.btnRemove.Size = new System.Drawing.Size(91, 40);
            this.btnRemove.TabIndex = 7;
            this.btnRemove.Text = "Remove";
            this.btnRemove.UseVisualStyleBackColor = true;
            this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(308, 176);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(91, 40);
            this.btnUpdate.TabIndex = 6;
            this.btnUpdate.Text = "Update";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(192, 176);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(91, 40);
            this.btnAdd.TabIndex = 5;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // textUrlName
            // 
            this.textUrlName.Location = new System.Drawing.Point(281, 55);
            this.textUrlName.Name = "textUrlName";
            this.textUrlName.Size = new System.Drawing.Size(249, 20);
            this.textUrlName.TabIndex = 4;
            // 
            // textUrl
            // 
            this.textUrl.Location = new System.Drawing.Point(281, 20);
            this.textUrl.Name = "textUrl";
            this.textUrl.Size = new System.Drawing.Size(249, 20);
            this.textUrl.TabIndex = 3;
            // 
            // lbUrlName
            // 
            this.lbUrlName.AutoSize = true;
            this.lbUrlName.Location = new System.Drawing.Point(180, 55);
            this.lbUrlName.Name = "lbUrlName";
            this.lbUrlName.Size = new System.Drawing.Size(94, 13);
            this.lbUrlName.TabIndex = 2;
            this.lbUrlName.Text = "Enter URL Name :";
            // 
            // lbURL
            // 
            this.lbURL.AutoSize = true;
            this.lbURL.Location = new System.Drawing.Point(211, 20);
            this.lbURL.Name = "lbURL";
            this.lbURL.Size = new System.Drawing.Size(63, 13);
            this.lbURL.TabIndex = 1;
            this.lbURL.Text = "Enter URL :";
            // 
            // listBoxExistLinks
            // 
            this.listBoxExistLinks.FormattingEnabled = true;
            this.listBoxExistLinks.Location = new System.Drawing.Point(7, 20);
            this.listBoxExistLinks.Name = "listBoxExistLinks";
            this.listBoxExistLinks.Size = new System.Drawing.Size(152, 199);
            this.listBoxExistLinks.TabIndex = 0;
            this.listBoxExistLinks.Click += new System.EventHandler(this.listBoxExistLinks_On_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(468, 415);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 4;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // AddExternalLink
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(575, 450);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox2);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddExternalLink";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AddExternalLink";
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnUpdateTitle;
        private System.Windows.Forms.TextBox textTitle;
        private System.Windows.Forms.CheckBox checkShowTitle;
        private System.Windows.Forms.Label lbTitle;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnApplyOrder;
        private System.Windows.Forms.Button btnRemove;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.TextBox textUrlName;
        private System.Windows.Forms.TextBox textUrl;
        private System.Windows.Forms.Label lbUrlName;
        private System.Windows.Forms.Label lbURL;
        private System.Windows.Forms.ListBox listBoxExistLinks;
        private System.Windows.Forms.Button btnDown;
        private System.Windows.Forms.Button btnUp;
        private System.Windows.Forms.Button btnClose;
    }
}