
namespace WebCloudAPITest.CMSMenu
{
    partial class ListAllPageInfoWithLinks
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
            this.gridViewAllPageInfo = new System.Windows.Forms.DataGridView();
            this.btnClose = new System.Windows.Forms.Button();
            this.MenuID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ParentID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MenuName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ShowMenu = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.MenuLink = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AliasURLLink = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.PageHeading = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewAllPageInfo)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.gridViewAllPageInfo);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(1041, 365);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "All Page Information";
            // 
            // gridViewAllPageInfo
            // 
            this.gridViewAllPageInfo.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.gridViewAllPageInfo.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewAllPageInfo.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.MenuID,
            this.ParentID,
            this.MenuName,
            this.ShowMenu,
            this.MenuLink,
            this.AliasURLLink,
            this.PageHeading});
            this.gridViewAllPageInfo.Location = new System.Drawing.Point(6, 19);
            this.gridViewAllPageInfo.Name = "gridViewAllPageInfo";
            this.gridViewAllPageInfo.Size = new System.Drawing.Size(1014, 327);
            this.gridViewAllPageInfo.TabIndex = 0;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(947, 384);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(78, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // MenuID
            // 
            this.MenuID.HeaderText = "MenuID";
            this.MenuID.Name = "MenuID";
            this.MenuID.Width = 70;
            // 
            // ParentID
            // 
            this.ParentID.HeaderText = "ParentID";
            this.ParentID.Name = "ParentID";
            this.ParentID.Width = 74;
            // 
            // MenuName
            // 
            this.MenuName.HeaderText = "Menu Name";
            this.MenuName.Name = "MenuName";
            this.MenuName.Width = 90;
            // 
            // ShowMenu
            // 
            this.ShowMenu.HeaderText = "Show Menu";
            this.ShowMenu.Name = "ShowMenu";
            this.ShowMenu.Width = 89;
            // 
            // MenuLink
            // 
            this.MenuLink.HeaderText = "Menu Link";
            this.MenuLink.Name = "MenuLink";
            this.MenuLink.Width = 82;
            // 
            // AliasURLLink
            // 
            this.AliasURLLink.HeaderText = "Alias URL Link";
            this.AliasURLLink.Name = "AliasURLLink";
            this.AliasURLLink.Width = 102;
            // 
            // PageHeading
            // 
            this.PageHeading.HeaderText = "Page Heading";
            this.PageHeading.Name = "PageHeading";
            // 
            // ListAllPageInfoWithLinks
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1074, 450);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ListAllPageInfoWithLinks";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ListAllPageInfoWithLinks";
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewAllPageInfo)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DataGridView gridViewAllPageInfo;
        private System.Windows.Forms.DataGridViewTextBoxColumn MenuID;
        private System.Windows.Forms.DataGridViewTextBoxColumn ParentID;
        private System.Windows.Forms.DataGridViewTextBoxColumn MenuName;
        private System.Windows.Forms.DataGridViewTextBoxColumn ShowMenu;
        private System.Windows.Forms.DataGridViewTextBoxColumn MenuLink;
        private System.Windows.Forms.DataGridViewTextBoxColumn AliasURLLink;
        private System.Windows.Forms.DataGridViewTextBoxColumn PageHeading;
        private System.Windows.Forms.Button btnClose;
    }
}