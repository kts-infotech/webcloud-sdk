
namespace WebCloudAPITest
{
    partial class EmployeeForm
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
            this.btnSave = new System.Windows.Forms.Button();
            this.dateLeave = new System.Windows.Forms.DateTimePicker();
            this.dateJoin = new System.Windows.Forms.DateTimePicker();
            this.combStatus = new System.Windows.Forms.ComboBox();
            this.combEmployeeType = new System.Windows.Forms.ComboBox();
            this.txtRemarks = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.txtLastSal = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.txtPhoneNumber = new System.Windows.Forms.TextBox();
            this.label55 = new System.Windows.Forms.Label();
            this.txtEmailPersonal = new System.Windows.Forms.TextBox();
            this.label555 = new System.Windows.Forms.Label();
            this.txtEmailOffice = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textEmployeeAddr = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textEmployeeName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.gbEmployeeDetails = new System.Windows.Forms.GroupBox();
            this.gbEmployeeList = new System.Windows.Forms.GroupBox();
            this.dgvEmployee = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.EmployeeId = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.EmployeeName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.EmailIDOffice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.EmailIDPersonal = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.PhoneNumber = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Edit = new System.Windows.Forms.DataGridViewButtonColumn();
            this.Delete = new System.Windows.Forms.DataGridViewButtonColumn();
            this.Cancel = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.gbEmployeeDetails.SuspendLayout();
            this.gbEmployeeList.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvEmployee)).BeginInit();
            this.SuspendLayout();
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(512, 678);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(115, 22);
            this.btnSave.TabIndex = 50;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // dateLeave
            // 
            this.dateLeave.Location = new System.Drawing.Point(582, 165);
            this.dateLeave.Name = "dateLeave";
            this.dateLeave.Size = new System.Drawing.Size(233, 20);
            this.dateLeave.TabIndex = 49;
            // 
            // dateJoin
            // 
            this.dateJoin.Location = new System.Drawing.Point(582, 126);
            this.dateJoin.Name = "dateJoin";
            this.dateJoin.Size = new System.Drawing.Size(233, 20);
            this.dateJoin.TabIndex = 48;
            // 
            // combStatus
            // 
            this.combStatus.FormattingEnabled = true;
            this.combStatus.Location = new System.Drawing.Point(174, 252);
            this.combStatus.Name = "combStatus";
            this.combStatus.Size = new System.Drawing.Size(233, 21);
            this.combStatus.TabIndex = 47;
            // 
            // combEmployeeType
            // 
            this.combEmployeeType.FormattingEnabled = true;
            this.combEmployeeType.Location = new System.Drawing.Point(174, 81);
            this.combEmployeeType.Name = "combEmployeeType";
            this.combEmployeeType.Size = new System.Drawing.Size(233, 21);
            this.combEmployeeType.TabIndex = 46;
            // 
            // txtRemarks
            // 
            this.txtRemarks.Location = new System.Drawing.Point(582, 208);
            this.txtRemarks.Multiline = true;
            this.txtRemarks.Name = "txtRemarks";
            this.txtRemarks.Size = new System.Drawing.Size(233, 110);
            this.txtRemarks.TabIndex = 45;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(466, 211);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(89, 13);
            this.label11.TabIndex = 44;
            this.label11.Text = "General Remarks";
            // 
            // txtLastSal
            // 
            this.txtLastSal.Location = new System.Drawing.Point(174, 295);
            this.txtLastSal.Name = "txtLastSal";
            this.txtLastSal.Size = new System.Drawing.Size(233, 20);
            this.txtLastSal.TabIndex = 43;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(42, 298);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(93, 13);
            this.label10.TabIndex = 42;
            this.label10.Text = "Last Salary Drawn";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(41, 249);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(86, 13);
            this.label9.TabIndex = 41;
            this.label9.Text = "Employee Status";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(466, 171);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(71, 13);
            this.label8.TabIndex = 40;
            this.label8.Text = "Leaving Date";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(466, 132);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(70, 13);
            this.label7.TabIndex = 39;
            this.label7.Text = "Joining Date*";
            // 
            // txtPhoneNumber
            // 
            this.txtPhoneNumber.Location = new System.Drawing.Point(174, 205);
            this.txtPhoneNumber.Name = "txtPhoneNumber";
            this.txtPhoneNumber.Size = new System.Drawing.Size(233, 20);
            this.txtPhoneNumber.TabIndex = 38;
            // 
            // label55
            // 
            this.label55.AutoSize = true;
            this.label55.Location = new System.Drawing.Point(41, 208);
            this.label55.Name = "label55";
            this.label55.Size = new System.Drawing.Size(78, 13);
            this.label55.TabIndex = 37;
            this.label55.Text = "Phone Number";
            // 
            // txtEmailPersonal
            // 
            this.txtEmailPersonal.Location = new System.Drawing.Point(174, 165);
            this.txtEmailPersonal.Name = "txtEmailPersonal";
            this.txtEmailPersonal.Size = new System.Drawing.Size(233, 20);
            this.txtEmailPersonal.TabIndex = 36;
            // 
            // label555
            // 
            this.label555.AutoSize = true;
            this.label555.Location = new System.Drawing.Point(41, 168);
            this.label555.Name = "label555";
            this.label555.Size = new System.Drawing.Size(94, 13);
            this.label555.TabIndex = 35;
            this.label555.Text = "Email-ID Personal*";
            // 
            // txtEmailOffice
            // 
            this.txtEmailOffice.Location = new System.Drawing.Point(174, 126);
            this.txtEmailOffice.Name = "txtEmailOffice";
            this.txtEmailOffice.Size = new System.Drawing.Size(233, 20);
            this.txtEmailOffice.TabIndex = 34;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(41, 129);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(81, 13);
            this.label4.TabIndex = 33;
            this.label4.Text = "Email-ID Office*";
            // 
            // textEmployeeAddr
            // 
            this.textEmployeeAddr.Location = new System.Drawing.Point(582, 42);
            this.textEmployeeAddr.Multiline = true;
            this.textEmployeeAddr.Name = "textEmployeeAddr";
            this.textEmployeeAddr.Size = new System.Drawing.Size(233, 59);
            this.textEmployeeAddr.TabIndex = 32;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(465, 48);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 13);
            this.label3.TabIndex = 31;
            this.label3.Text = "Address*";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(41, 81);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(80, 13);
            this.label2.TabIndex = 30;
            this.label2.Text = "Employee Type";
            // 
            // textEmployeeName
            // 
            this.textEmployeeName.Location = new System.Drawing.Point(174, 42);
            this.textEmployeeName.Name = "textEmployeeName";
            this.textEmployeeName.Size = new System.Drawing.Size(233, 20);
            this.textEmployeeName.TabIndex = 29;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(85, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 13);
            this.label1.TabIndex = 28;
            this.label1.Text = "Employee Name*";
            // 
            // gbEmployeeDetails
            // 
            this.gbEmployeeDetails.Controls.Add(this.textEmployeeAddr);
            this.gbEmployeeDetails.Controls.Add(this.txtRemarks);
            this.gbEmployeeDetails.Controls.Add(this.combStatus);
            this.gbEmployeeDetails.Controls.Add(this.label11);
            this.gbEmployeeDetails.Controls.Add(this.dateLeave);
            this.gbEmployeeDetails.Controls.Add(this.txtLastSal);
            this.gbEmployeeDetails.Controls.Add(this.label2);
            this.gbEmployeeDetails.Controls.Add(this.label10);
            this.gbEmployeeDetails.Controls.Add(this.dateJoin);
            this.gbEmployeeDetails.Controls.Add(this.combEmployeeType);
            this.gbEmployeeDetails.Controls.Add(this.textEmployeeName);
            this.gbEmployeeDetails.Controls.Add(this.label9);
            this.gbEmployeeDetails.Controls.Add(this.label3);
            this.gbEmployeeDetails.Controls.Add(this.label4);
            this.gbEmployeeDetails.Controls.Add(this.txtEmailOffice);
            this.gbEmployeeDetails.Controls.Add(this.label8);
            this.gbEmployeeDetails.Controls.Add(this.label555);
            this.gbEmployeeDetails.Controls.Add(this.txtEmailPersonal);
            this.gbEmployeeDetails.Controls.Add(this.label55);
            this.gbEmployeeDetails.Controls.Add(this.label7);
            this.gbEmployeeDetails.Controls.Add(this.txtPhoneNumber);
            this.gbEmployeeDetails.Location = new System.Drawing.Point(44, 12);
            this.gbEmployeeDetails.Name = "gbEmployeeDetails";
            this.gbEmployeeDetails.Size = new System.Drawing.Size(853, 344);
            this.gbEmployeeDetails.TabIndex = 51;
            this.gbEmployeeDetails.TabStop = false;
            this.gbEmployeeDetails.Text = "Employee Details";
            // 
            // gbEmployeeList
            // 
            this.gbEmployeeList.Controls.Add(this.dgvEmployee);
            this.gbEmployeeList.Location = new System.Drawing.Point(44, 362);
            this.gbEmployeeList.Name = "gbEmployeeList";
            this.gbEmployeeList.Size = new System.Drawing.Size(853, 295);
            this.gbEmployeeList.TabIndex = 52;
            this.gbEmployeeList.TabStop = false;
            this.gbEmployeeList.Text = "Employee List";
            // 
            // dgvEmployee
            // 
            this.dgvEmployee.AllowUserToAddRows = false;
            this.dgvEmployee.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvEmployee.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.EmployeeId,
            this.EmployeeName,
            this.EmailIDOffice,
            this.EmailIDPersonal,
            this.PhoneNumber,
            this.Edit,
            this.Delete});
            this.dgvEmployee.Location = new System.Drawing.Point(17, 31);
            this.dgvEmployee.Name = "dgvEmployee";
            this.dgvEmployee.Size = new System.Drawing.Size(820, 247);
            this.dgvEmployee.TabIndex = 0;
            this.dgvEmployee.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvEmployee_CellContentClick);
            // 
            // Column1
            // 
            this.Column1.HeaderText = "Sl No";
            this.Column1.Name = "Column1";
            this.Column1.Width = 40;
            // 
            // EmployeeId
            // 
            this.EmployeeId.HeaderText = "EmployeeId";
            this.EmployeeId.Name = "EmployeeId";
            this.EmployeeId.Visible = false;
            // 
            // EmployeeName
            // 
            this.EmployeeName.HeaderText = "Employee Name";
            this.EmployeeName.Name = "EmployeeName";
            this.EmployeeName.Width = 150;
            // 
            // EmailIDOffice
            // 
            this.EmailIDOffice.HeaderText = "Email-ID Office";
            this.EmailIDOffice.Name = "EmailIDOffice";
            this.EmailIDOffice.Width = 150;
            // 
            // EmailIDPersonal
            // 
            this.EmailIDPersonal.HeaderText = "Email-ID Personal";
            this.EmailIDPersonal.Name = "EmailIDPersonal";
            this.EmailIDPersonal.Width = 150;
            // 
            // PhoneNumber
            // 
            this.PhoneNumber.HeaderText = "Phone Number";
            this.PhoneNumber.Name = "PhoneNumber";
            // 
            // Edit
            // 
            this.Edit.HeaderText = "Edit";
            this.Edit.Name = "Edit";
            this.Edit.Text = "Edit";
            this.Edit.UseColumnTextForButtonValue = true;
            // 
            // Delete
            // 
            this.Delete.HeaderText = "Delete";
            this.Delete.Name = "Delete";
            this.Delete.Text = "Delete";
            this.Delete.UseColumnTextForButtonValue = true;
            // 
            // Cancel
            // 
            this.Cancel.BackColor = System.Drawing.SystemColors.Control;
            this.Cancel.Location = new System.Drawing.Point(653, 678);
            this.Cancel.Name = "Cancel";
            this.Cancel.Size = new System.Drawing.Size(110, 22);
            this.Cancel.TabIndex = 53;
            this.Cancel.Text = "Clear All";
            this.Cancel.UseVisualStyleBackColor = false;
            this.Cancel.Click += new System.EventHandler(this.Cancel_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(784, 677);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(113, 23);
            this.btnClose.TabIndex = 54;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // EmployeeForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(933, 727);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.Cancel);
            this.Controls.Add(this.gbEmployeeList);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.gbEmployeeDetails);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "EmployeeForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "EmployeeForm";
            this.Load += new System.EventHandler(this.EmployeeForm_Load);
            this.gbEmployeeDetails.ResumeLayout(false);
            this.gbEmployeeDetails.PerformLayout();
            this.gbEmployeeList.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvEmployee)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.DateTimePicker dateLeave;
        private System.Windows.Forms.DateTimePicker dateJoin;
        private System.Windows.Forms.ComboBox combStatus;
        private System.Windows.Forms.ComboBox combEmployeeType;
        private System.Windows.Forms.TextBox txtRemarks;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox txtLastSal;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtPhoneNumber;
        private System.Windows.Forms.Label label55;
        private System.Windows.Forms.TextBox txtEmailPersonal;
        private System.Windows.Forms.Label label555;
        private System.Windows.Forms.TextBox txtEmailOffice;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textEmployeeAddr;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textEmployeeName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox gbEmployeeDetails;
        private System.Windows.Forms.GroupBox gbEmployeeList;
        private System.Windows.Forms.DataGridView dgvEmployee;
        private System.Windows.Forms.Button Cancel;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn EmployeeId;
        private System.Windows.Forms.DataGridViewTextBoxColumn EmployeeName;
        private System.Windows.Forms.DataGridViewTextBoxColumn EmailIDOffice;
        private System.Windows.Forms.DataGridViewTextBoxColumn EmailIDPersonal;
        private System.Windows.Forms.DataGridViewTextBoxColumn PhoneNumber;
        private System.Windows.Forms.DataGridViewButtonColumn Edit;
        private System.Windows.Forms.DataGridViewButtonColumn Delete;
        private System.Windows.Forms.Button btnClose;
    }
}