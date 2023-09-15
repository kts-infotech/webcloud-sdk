
namespace WebCloudAPITest.ForumMenu
{
    partial class AddThread
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
            this.combTopName = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.listBoxExisTrds = new System.Windows.Forms.ListBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textTrdName = new System.Windows.Forms.TextBox();
            this.btnBrsImg = new System.Windows.Forms.Button();
            this.textTrdDesc = new System.Windows.Forms.TextBox();
            this.textImgPath = new System.Windows.Forms.TextBox();
            this.comboForName = new System.Windows.Forms.ComboBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.checkUpldImage = new System.Windows.Forms.CheckBox();
            this.btnAddNew = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // combTopName
            // 
            this.combTopName.FormattingEnabled = true;
            this.combTopName.Location = new System.Drawing.Point(124, 73);
            this.combTopName.Name = "combTopName";
            this.combTopName.Size = new System.Drawing.Size(230, 21);
            this.combTopName.TabIndex = 4;
            this.combTopName.SelectedIndexChanged += new System.EventHandler(this.combTopName_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(110, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Existing Topic Name :";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(112, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Existing Forum Name :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 25);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(78, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Thread Name :";
            // 
            // listBoxExisTrds
            // 
            this.listBoxExisTrds.FormattingEnabled = true;
            this.listBoxExisTrds.Location = new System.Drawing.Point(7, 20);
            this.listBoxExisTrds.Name = "listBoxExisTrds";
            this.listBoxExisTrds.Size = new System.Drawing.Size(360, 82);
            this.listBoxExisTrds.TabIndex = 0;
            this.listBoxExisTrds.SelectedIndexChanged += new System.EventHandler(this.listBoxExisTrds_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(18, 62);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(66, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "Description :";
            // 
            // textTrdName
            // 
            this.textTrdName.Location = new System.Drawing.Point(91, 23);
            this.textTrdName.Name = "textTrdName";
            this.textTrdName.Size = new System.Drawing.Size(263, 20);
            this.textTrdName.TabIndex = 3;
            // 
            // btnBrsImg
            // 
            this.btnBrsImg.Enabled = false;
            this.btnBrsImg.Location = new System.Drawing.Point(266, 40);
            this.btnBrsImg.Name = "btnBrsImg";
            this.btnBrsImg.Size = new System.Drawing.Size(88, 23);
            this.btnBrsImg.TabIndex = 2;
            this.btnBrsImg.Text = "Select Image";
            this.btnBrsImg.UseVisualStyleBackColor = true;
            this.btnBrsImg.Click += new System.EventHandler(this.btnBrsImg_Click);
            // 
            // textTrdDesc
            // 
            this.textTrdDesc.Location = new System.Drawing.Point(91, 59);
            this.textTrdDesc.Multiline = true;
            this.textTrdDesc.Name = "textTrdDesc";
            this.textTrdDesc.Size = new System.Drawing.Size(263, 177);
            this.textTrdDesc.TabIndex = 5;
            // 
            // textImgPath
            // 
            this.textImgPath.Location = new System.Drawing.Point(7, 43);
            this.textImgPath.Name = "textImgPath";
            this.textImgPath.ReadOnly = true;
            this.textImgPath.Size = new System.Drawing.Size(253, 20);
            this.textImgPath.TabIndex = 1;
            // 
            // comboForName
            // 
            this.comboForName.FormattingEnabled = true;
            this.comboForName.Location = new System.Drawing.Point(124, 26);
            this.comboForName.Name = "comboForName";
            this.comboForName.Size = new System.Drawing.Size(230, 21);
            this.comboForName.TabIndex = 2;
            this.comboForName.SelectedIndexChanged += new System.EventHandler(this.comboForName_SelectedIndexChanged);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(701, 414);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 18;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.pictureBox);
            this.groupBox4.Controls.Add(this.btnBrsImg);
            this.groupBox4.Controls.Add(this.textImgPath);
            this.groupBox4.Controls.Add(this.checkUpldImage);
            this.groupBox4.Location = new System.Drawing.Point(410, 139);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(373, 256);
            this.groupBox4.TabIndex = 17;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Upload Image";
            // 
            // pictureBox
            // 
            this.pictureBox.Location = new System.Drawing.Point(36, 90);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(294, 145);
            this.pictureBox.TabIndex = 3;
            this.pictureBox.TabStop = false;
            // 
            // checkUpldImage
            // 
            this.checkUpldImage.AutoSize = true;
            this.checkUpldImage.Location = new System.Drawing.Point(7, 19);
            this.checkUpldImage.Name = "checkUpldImage";
            this.checkUpldImage.Size = new System.Drawing.Size(92, 17);
            this.checkUpldImage.TabIndex = 0;
            this.checkUpldImage.Text = "Upload Image";
            this.checkUpldImage.UseVisualStyleBackColor = true;
            this.checkUpldImage.CheckedChanged += new System.EventHandler(this.checkUpldImage_CheckedChanged);
            // 
            // btnAddNew
            // 
            this.btnAddNew.Location = new System.Drawing.Point(410, 414);
            this.btnAddNew.Name = "btnAddNew";
            this.btnAddNew.Size = new System.Drawing.Size(75, 23);
            this.btnAddNew.TabIndex = 19;
            this.btnAddNew.Text = "Add New";
            this.btnAddNew.UseVisualStyleBackColor = true;
            this.btnAddNew.Visible = false;
            this.btnAddNew.Click += new System.EventHandler(this.btnAddNew_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.textTrdDesc);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.textTrdName);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Location = new System.Drawing.Point(18, 138);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(377, 257);
            this.groupBox2.TabIndex = 15;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Give a Thread Name and Description";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.listBoxExisTrds);
            this.groupBox3.Location = new System.Drawing.Point(410, 14);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(373, 118);
            this.groupBox3.TabIndex = 16;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Existing Threads";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.combTopName);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.comboForName);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(18, 14);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(377, 118);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Select Forum and Topic";
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(608, 414);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 20;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // AddThread
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.btnAddNew);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnCancel);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AddThread";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AddThread";
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox combTopName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListBox listBoxExisTrds;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textTrdName;
        private System.Windows.Forms.Button btnBrsImg;
        private System.Windows.Forms.TextBox textTrdDesc;
        private System.Windows.Forms.TextBox textImgPath;
        private System.Windows.Forms.ComboBox comboForName;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.CheckBox checkUpldImage;
        private System.Windows.Forms.Button btnAddNew;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.PictureBox pictureBox;
    }
}