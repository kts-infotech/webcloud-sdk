
namespace WebCloudAPITest
{
    partial class AssignTaskForm
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
            this.gbAssignTask = new System.Windows.Forms.GroupBox();
            this.btnAssignTask = new System.Windows.Forms.Button();
            this.cbUserGroup = new System.Windows.Forms.ComboBox();
            this.cbTeamMember = new System.Windows.Forms.ComboBox();
            this.cbSubTask = new System.Windows.Forms.ComboBox();
            this.cbTask = new System.Windows.Forms.ComboBox();
            this.comProject = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.gbAssignedTask = new System.Windows.Forms.GroupBox();
            this.dgvAssignedTaskList = new System.Windows.Forms.DataGridView();
            this.SlNo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AssignTaskId = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AssignedTask = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Delete = new System.Windows.Forms.DataGridViewButtonColumn();
            this.gbAssignTask.SuspendLayout();
            this.gbAssignedTask.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvAssignedTaskList)).BeginInit();
            this.SuspendLayout();
            // 
            // gbAssignTask
            // 
            this.gbAssignTask.Controls.Add(this.btnAssignTask);
            this.gbAssignTask.Controls.Add(this.cbUserGroup);
            this.gbAssignTask.Controls.Add(this.cbTeamMember);
            this.gbAssignTask.Controls.Add(this.cbSubTask);
            this.gbAssignTask.Controls.Add(this.cbTask);
            this.gbAssignTask.Controls.Add(this.comProject);
            this.gbAssignTask.Controls.Add(this.label5);
            this.gbAssignTask.Controls.Add(this.label4);
            this.gbAssignTask.Controls.Add(this.label3);
            this.gbAssignTask.Controls.Add(this.label2);
            this.gbAssignTask.Controls.Add(this.label1);
            this.gbAssignTask.Location = new System.Drawing.Point(12, 24);
            this.gbAssignTask.Name = "gbAssignTask";
            this.gbAssignTask.Size = new System.Drawing.Size(706, 263);
            this.gbAssignTask.TabIndex = 0;
            this.gbAssignTask.TabStop = false;
            this.gbAssignTask.Text = "Assign Task";
            // 
            // btnAssignTask
            // 
            this.btnAssignTask.Location = new System.Drawing.Point(166, 226);
            this.btnAssignTask.Name = "btnAssignTask";
            this.btnAssignTask.Size = new System.Drawing.Size(115, 22);
            this.btnAssignTask.TabIndex = 40;
            this.btnAssignTask.Text = "Assign Task";
            this.btnAssignTask.UseVisualStyleBackColor = true;
            this.btnAssignTask.Click += new System.EventHandler(this.btnAssignTask_Click);
            // 
            // cbUserGroup
            // 
            this.cbUserGroup.FormattingEnabled = true;
            this.cbUserGroup.Location = new System.Drawing.Point(166, 144);
            this.cbUserGroup.Name = "cbUserGroup";
            this.cbUserGroup.Size = new System.Drawing.Size(233, 21);
            this.cbUserGroup.TabIndex = 36;
            this.cbUserGroup.SelectedIndexChanged += new System.EventHandler(this.cbUserGroup_SelectedIndexChanged);
            // 
            // cbTeamMember
            // 
            this.cbTeamMember.FormattingEnabled = true;
            this.cbTeamMember.Location = new System.Drawing.Point(166, 184);
            this.cbTeamMember.Name = "cbTeamMember";
            this.cbTeamMember.Size = new System.Drawing.Size(233, 21);
            this.cbTeamMember.TabIndex = 35;
            this.cbTeamMember.SelectedIndexChanged += new System.EventHandler(this.cbTeamMember_SelectedIndexChanged);
            // 
            // cbSubTask
            // 
            this.cbSubTask.FormattingEnabled = true;
            this.cbSubTask.Location = new System.Drawing.Point(166, 102);
            this.cbSubTask.Name = "cbSubTask";
            this.cbSubTask.Size = new System.Drawing.Size(233, 21);
            this.cbSubTask.TabIndex = 34;
            // 
            // cbTask
            // 
            this.cbTask.FormattingEnabled = true;
            this.cbTask.Location = new System.Drawing.Point(166, 68);
            this.cbTask.Name = "cbTask";
            this.cbTask.Size = new System.Drawing.Size(233, 21);
            this.cbTask.TabIndex = 33;
            // 
            // comProject
            // 
            this.comProject.FormattingEnabled = true;
            this.comProject.Location = new System.Drawing.Point(166, 31);
            this.comProject.Name = "comProject";
            this.comProject.Size = new System.Drawing.Size(233, 21);
            this.comProject.TabIndex = 32;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(24, 187);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(108, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Select Team Member";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(24, 147);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(94, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Select User Group";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 105);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Select SubTask";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Select Task";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Select Project";
            // 
            // gbAssignedTask
            // 
            this.gbAssignedTask.Controls.Add(this.dgvAssignedTaskList);
            this.gbAssignedTask.Location = new System.Drawing.Point(12, 316);
            this.gbAssignedTask.Name = "gbAssignedTask";
            this.gbAssignedTask.Size = new System.Drawing.Size(706, 176);
            this.gbAssignedTask.TabIndex = 41;
            this.gbAssignedTask.TabStop = false;
            this.gbAssignedTask.Text = "Assigned Task";
            // 
            // dgvAssignedTaskList
            // 
            this.dgvAssignedTaskList.AllowUserToAddRows = false;
            this.dgvAssignedTaskList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvAssignedTaskList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.SlNo,
            this.AssignTaskId,
            this.AssignedTask,
            this.Delete});
            this.dgvAssignedTaskList.Location = new System.Drawing.Point(6, 19);
            this.dgvAssignedTaskList.Name = "dgvAssignedTaskList";
            this.dgvAssignedTaskList.Size = new System.Drawing.Size(694, 151);
            this.dgvAssignedTaskList.TabIndex = 1;
            this.dgvAssignedTaskList.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvAssignedTaskList_CellContentClick);
            // 
            // SlNo
            // 
            this.SlNo.HeaderText = "Sl No";
            this.SlNo.Name = "SlNo";
            this.SlNo.Width = 40;
            // 
            // AssignTaskId
            // 
            this.AssignTaskId.HeaderText = "AssignTaskId";
            this.AssignTaskId.Name = "AssignTaskId";
            this.AssignTaskId.Visible = false;
            // 
            // AssignedTask
            // 
            this.AssignedTask.HeaderText = "Assigned Task";
            this.AssignedTask.Name = "AssignedTask";
            this.AssignedTask.Width = 546;
            // 
            // Delete
            // 
            this.Delete.HeaderText = "Delete";
            this.Delete.Name = "Delete";
            this.Delete.Text = "Delete";
            this.Delete.UseColumnTextForButtonValue = true;
            this.Delete.Width = 65;
            // 
            // AssignTaskForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(732, 504);
            this.Controls.Add(this.gbAssignedTask);
            this.Controls.Add(this.gbAssignTask);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AssignTaskForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AssignTaskForm";
            this.Load += new System.EventHandler(this.AssignTaskForm_Load);
            this.gbAssignTask.ResumeLayout(false);
            this.gbAssignTask.PerformLayout();
            this.gbAssignedTask.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvAssignedTaskList)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gbAssignTask;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbUserGroup;
        private System.Windows.Forms.ComboBox cbTeamMember;
        private System.Windows.Forms.ComboBox cbSubTask;
        private System.Windows.Forms.ComboBox cbTask;
        private System.Windows.Forms.ComboBox comProject;
        private System.Windows.Forms.Button btnAssignTask;
        private System.Windows.Forms.GroupBox gbAssignedTask;
        private System.Windows.Forms.DataGridView dgvAssignedTaskList;
        private System.Windows.Forms.DataGridViewTextBoxColumn SlNo;
        private System.Windows.Forms.DataGridViewTextBoxColumn AssignTaskId;
        private System.Windows.Forms.DataGridViewTextBoxColumn AssignedTask;
        private System.Windows.Forms.DataGridViewButtonColumn Delete;
    }
}