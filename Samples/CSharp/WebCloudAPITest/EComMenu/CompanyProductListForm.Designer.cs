
namespace WebCloudAPITest
{
    partial class CompanyProductListForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.comCompanyList = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.comProductCategory = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.comProductSubcategory = new System.Windows.Forms.ComboBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.txtProductDetails = new System.Windows.Forms.TextBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(38, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Select Company";
            // 
            // comCompanyList
            // 
            this.comCompanyList.FormattingEnabled = true;
            this.comCompanyList.Location = new System.Drawing.Point(227, 32);
            this.comCompanyList.Name = "comCompanyList";
            this.comCompanyList.Size = new System.Drawing.Size(233, 21);
            this.comCompanyList.TabIndex = 2;
            this.comCompanyList.SelectedIndexChanged += new System.EventHandler(this.comCompanyList_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(38, 96);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(122, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Select Product Category";
            // 
            // comProductCategory
            // 
            this.comProductCategory.FormattingEnabled = true;
            this.comProductCategory.Location = new System.Drawing.Point(227, 93);
            this.comProductCategory.Name = "comProductCategory";
            this.comProductCategory.Size = new System.Drawing.Size(233, 21);
            this.comProductCategory.TabIndex = 4;
            this.comProductCategory.SelectedIndexChanged += new System.EventHandler(this.comProductCategory_SelectedIndexChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(38, 154);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(100, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Select Subcategory";
            // 
            // comProductSubcategory
            // 
            this.comProductSubcategory.FormattingEnabled = true;
            this.comProductSubcategory.Location = new System.Drawing.Point(227, 154);
            this.comProductSubcategory.Name = "comProductSubcategory";
            this.comProductSubcategory.Size = new System.Drawing.Size(233, 21);
            this.comProductSubcategory.TabIndex = 6;
            this.comProductSubcategory.SelectedIndexChanged += new System.EventHandler(this.comProductSubcategory_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtProductDetails);
            this.groupBox1.Location = new System.Drawing.Point(35, 208);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(701, 152);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Product Details";
            // 
            // txtProductDetails
            // 
            this.txtProductDetails.Location = new System.Drawing.Point(6, 16);
            this.txtProductDetails.Multiline = true;
            this.txtProductDetails.Name = "txtProductDetails";
            this.txtProductDetails.Size = new System.Drawing.Size(689, 130);
            this.txtProductDetails.TabIndex = 0;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(603, 385);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(117, 23);
            this.btnClose.TabIndex = 8;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // CompanyProductListForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(787, 450);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.comProductSubcategory);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.comProductCategory);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comCompanyList);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "CompanyProductListForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CompanyProductListForm";
            this.Load += new System.EventHandler(this.CompanyProductListForm_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comCompanyList;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comProductCategory;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comProductSubcategory;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtProductDetails;
        private System.Windows.Forms.Button btnClose;
    }
}