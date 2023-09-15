namespace WebCloudAPITest
{
    partial class ListAllDirFilesForm
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
            this.groupBoxTreeArea = new System.Windows.Forms.GroupBox();
            this.labelStatus = new System.Windows.Forms.Label();
            this.treeViewRemote = new System.Windows.Forms.TreeView();
            this.buttonOK = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxPath = new System.Windows.Forms.TextBox();
            this.menuStripDirOperations = new System.Windows.Forms.MenuStrip();
            this.toolStripMenuItemCreate = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItemRename = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItemDelete = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBoxTreeArea.SuspendLayout();
            this.menuStripDirOperations.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxTreeArea
            // 
            this.groupBoxTreeArea.Controls.Add(this.labelStatus);
            this.groupBoxTreeArea.Controls.Add(this.treeViewRemote);
            this.groupBoxTreeArea.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxTreeArea.Location = new System.Drawing.Point(34, 38);
            this.groupBoxTreeArea.Name = "groupBoxTreeArea";
            this.groupBoxTreeArea.Size = new System.Drawing.Size(685, 308);
            this.groupBoxTreeArea.TabIndex = 0;
            this.groupBoxTreeArea.TabStop = false;
            this.groupBoxTreeArea.Text = "Select the File | Folder";
            // 
            // labelStatus
            // 
            this.labelStatus.AutoSize = true;
            this.labelStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelStatus.ForeColor = System.Drawing.Color.Red;
            this.labelStatus.Location = new System.Drawing.Point(8, 285);
            this.labelStatus.Name = "labelStatus";
            this.labelStatus.Size = new System.Drawing.Size(54, 17);
            this.labelStatus.TabIndex = 4;
            this.labelStatus.Text = "Status";
            // 
            // treeViewRemote
            // 
            this.treeViewRemote.Location = new System.Drawing.Point(11, 21);
            this.treeViewRemote.Name = "treeViewRemote";
            this.treeViewRemote.Size = new System.Drawing.Size(664, 245);
            this.treeViewRemote.TabIndex = 0;
            this.treeViewRemote.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeViewRemote_AfterSelect);
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(433, 390);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(134, 35);
            this.buttonOK.TabIndex = 1;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(585, 390);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(134, 35);
            this.buttonCancel.TabIndex = 2;
            this.buttonCancel.Text = "Cancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.label1.Location = new System.Drawing.Point(34, 356);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(109, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Selected Path";
            // 
            // textBoxPath
            // 
            this.textBoxPath.Location = new System.Drawing.Point(149, 353);
            this.textBoxPath.Name = "textBoxPath";
            this.textBoxPath.Size = new System.Drawing.Size(570, 22);
            this.textBoxPath.TabIndex = 4;
            // 
            // menuStripDirOperations
            // 
            this.menuStripDirOperations.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.menuStripDirOperations.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStripDirOperations.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemCreate,
            this.toolStripMenuItemRename,
            this.toolStripMenuItemDelete});
            this.menuStripDirOperations.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.menuStripDirOperations.Location = new System.Drawing.Point(0, 0);
            this.menuStripDirOperations.Name = "menuStripDirOperations";
            this.menuStripDirOperations.Size = new System.Drawing.Size(759, 28);
            this.menuStripDirOperations.TabIndex = 5;
            this.menuStripDirOperations.Text = "menuStrip1";
            // 
            // toolStripMenuItemCreate
            // 
            this.toolStripMenuItemCreate.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.toolStripMenuItemCreate.Name = "toolStripMenuItemCreate";
            this.toolStripMenuItemCreate.Size = new System.Drawing.Size(66, 24);
            this.toolStripMenuItemCreate.Text = "Create";
            this.toolStripMenuItemCreate.Click += new System.EventHandler(this.toolStripMenuItemCreate_Click);
            // 
            // toolStripMenuItemRename
            // 
            this.toolStripMenuItemRename.Name = "toolStripMenuItemRename";
            this.toolStripMenuItemRename.Size = new System.Drawing.Size(78, 24);
            this.toolStripMenuItemRename.Text = "Rename";
            this.toolStripMenuItemRename.Click += new System.EventHandler(this.toolStripMenuItemRename_Click);
            // 
            // toolStripMenuItemDelete
            // 
            this.toolStripMenuItemDelete.ForeColor = System.Drawing.Color.Red;
            this.toolStripMenuItemDelete.Name = "toolStripMenuItemDelete";
            this.toolStripMenuItemDelete.Size = new System.Drawing.Size(66, 24);
            this.toolStripMenuItemDelete.Text = "Delete";
            this.toolStripMenuItemDelete.Click += new System.EventHandler(this.toolStripMenuItemDelete_Click);
            // 
            // ListAllDirFilesForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(759, 447);
            this.Controls.Add(this.textBoxPath);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.groupBoxTreeArea);
            this.Controls.Add(this.menuStripDirOperations);
            this.MainMenuStrip = this.menuStripDirOperations;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ListAllDirFilesForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Directory File Listing Form";
            this.Load += new System.EventHandler(this.ListAllDirFilesForm_Load);
            this.groupBoxTreeArea.ResumeLayout(false);
            this.groupBoxTreeArea.PerformLayout();
            this.menuStripDirOperations.ResumeLayout(false);
            this.menuStripDirOperations.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxTreeArea;
        private System.Windows.Forms.Button buttonOK;
        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxPath;
        private System.Windows.Forms.TreeView treeViewRemote;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.MenuStrip menuStripDirOperations;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemCreate;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemRename;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemDelete;
    }
}