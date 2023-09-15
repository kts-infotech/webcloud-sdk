
namespace WebCloudAPITest
{
    partial class SubTaskForm
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
            this.gbManageProjects = new System.Windows.Forms.GroupBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.txtSubTaskDescription = new System.Windows.Forms.TextBox();
            this.txtSubTaskName = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.dgvSubTasks = new System.Windows.Forms.DataGridView();
            this.SlNo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SubTaskId = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SubTaskName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SubTaskDescription = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Edit = new System.Windows.Forms.DataGridViewButtonColumn();
            this.Delete = new System.Windows.Forms.DataGridViewButtonColumn();
            this.gbProjectList = new System.Windows.Forms.GroupBox();
            this.gbManageProjects.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvSubTasks)).BeginInit();
            this.gbProjectList.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbManageProjects
            // 
            this.gbManageProjects.Controls.Add(this.btnCancel);
            this.gbManageProjects.Controls.Add(this.btnSave);
            this.gbManageProjects.Controls.Add(this.txtSubTaskDescription);
            this.gbManageProjects.Controls.Add(this.txtSubTaskName);
            this.gbManageProjects.Controls.Add(this.label2);
            this.gbManageProjects.Controls.Add(this.label1);
            this.gbManageProjects.Location = new System.Drawing.Point(65, 15);
            this.gbManageProjects.Name = "gbManageProjects";
            this.gbManageProjects.Size = new System.Drawing.Size(671, 231);
            this.gbManageProjects.TabIndex = 36;
            this.gbManageProjects.TabStop = false;
            this.gbManageProjects.Text = "Manage Sub Task";
            // 
            // btnCancel
            // 
            this.btnCancel.BackColor = System.Drawing.SystemColors.Control;
            this.btnCancel.Location = new System.Drawing.Point(327, 185);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(115, 22);
            this.btnCancel.TabIndex = 35;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = false;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnSave
            // 
            this.btnSave.BackColor = System.Drawing.SystemColors.Control;
            this.btnSave.Location = new System.Drawing.Point(174, 185);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(115, 22);
            this.btnSave.TabIndex = 34;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = false;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // txtSubTaskDescription
            // 
            this.txtSubTaskDescription.Location = new System.Drawing.Point(174, 80);
            this.txtSubTaskDescription.Multiline = true;
            this.txtSubTaskDescription.Name = "txtSubTaskDescription";
            this.txtSubTaskDescription.Size = new System.Drawing.Size(233, 76);
            this.txtSubTaskDescription.TabIndex = 11;
            // 
            // txtSubTaskName
            // 
            this.txtSubTaskName.Location = new System.Drawing.Point(174, 35);
            this.txtSubTaskName.Name = "txtSubTaskName";
            this.txtSubTaskName.Size = new System.Drawing.Size(233, 20);
            this.txtSubTaskName.TabIndex = 10;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(25, 83);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(109, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Sub Task Description";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(81, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "SubTask Name";
            // 
            // dgvSubTasks
            // 
            this.dgvSubTasks.AllowUserToAddRows = false;
            this.dgvSubTasks.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvSubTasks.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.SlNo,
            this.SubTaskId,
            this.SubTaskName,
            this.SubTaskDescription,
            this.Edit,
            this.Delete});
            this.dgvSubTasks.Location = new System.Drawing.Point(12, 19);
            this.dgvSubTasks.Name = "dgvSubTasks";
            this.dgvSubTasks.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvSubTasks.Size = new System.Drawing.Size(642, 181);
            this.dgvSubTasks.TabIndex = 32;
            this.dgvSubTasks.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvSubTasks_CellContentClick);
            // 
            // SlNo
            // 
            this.SlNo.HeaderText = "Sl No";
            this.SlNo.Name = "SlNo";
            this.SlNo.Width = 40;
            // 
            // SubTaskId
            // 
            this.SubTaskId.HeaderText = "TaskId";
            this.SubTaskId.Name = "SubTaskId";
            this.SubTaskId.Visible = false;
            // 
            // SubTaskName
            // 
            this.SubTaskName.HeaderText = "Sub Task Name";
            this.SubTaskName.Name = "SubTaskName";
            this.SubTaskName.Width = 198;
            // 
            // SubTaskDescription
            // 
            this.SubTaskDescription.HeaderText = "Sub Task Description";
            this.SubTaskDescription.Name = "SubTaskDescription";
            this.SubTaskDescription.Width = 230;
            // 
            // Edit
            // 
            this.Edit.HeaderText = "Edit";
            this.Edit.Name = "Edit";
            this.Edit.Text = "Edit";
            this.Edit.UseColumnTextForButtonValue = true;
            this.Edit.Width = 65;
            // 
            // Delete
            // 
            this.Delete.HeaderText = "Delete";
            this.Delete.Name = "Delete";
            this.Delete.Text = "Delete";
            this.Delete.UseColumnTextForButtonValue = true;
            this.Delete.Width = 65;
            // 
            // gbProjectList
            // 
            this.gbProjectList.Controls.Add(this.dgvSubTasks);
            this.gbProjectList.Location = new System.Drawing.Point(65, 280);
            this.gbProjectList.Name = "gbProjectList";
            this.gbProjectList.Size = new System.Drawing.Size(671, 206);
            this.gbProjectList.TabIndex = 37;
            this.gbProjectList.TabStop = false;
            this.gbProjectList.Text = "Task List";
            // 
            // SubTaskForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 532);
            this.Controls.Add(this.gbManageProjects);
            this.Controls.Add(this.gbProjectList);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SubTaskForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "SubTaskForm";
            this.Load += new System.EventHandler(this.SubTaskForm_Load);
            this.gbManageProjects.ResumeLayout(false);
            this.gbManageProjects.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvSubTasks)).EndInit();
            this.gbProjectList.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbManageProjects;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.TextBox txtSubTaskDescription;
        private System.Windows.Forms.TextBox txtSubTaskName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dgvSubTasks;
        private System.Windows.Forms.GroupBox gbProjectList;
        private System.Windows.Forms.DataGridViewTextBoxColumn SlNo;
        private System.Windows.Forms.DataGridViewTextBoxColumn SubTaskId;
        private System.Windows.Forms.DataGridViewTextBoxColumn SubTaskName;
        private System.Windows.Forms.DataGridViewTextBoxColumn SubTaskDescription;
        private System.Windows.Forms.DataGridViewButtonColumn Edit;
        private System.Windows.Forms.DataGridViewButtonColumn Delete;
    }
}