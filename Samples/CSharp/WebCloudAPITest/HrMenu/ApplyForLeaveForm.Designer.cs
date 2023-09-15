
namespace WebCloudAPITest
{
    partial class ApplyForLeaveForm
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
            this.textLeaveSubject = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.datePickerLeaveFrom = new System.Windows.Forms.DateTimePicker();
            this.datePickerLeaveTo = new System.Windows.Forms.DateTimePicker();
            this.textBoxLeaveDescription = new System.Windows.Forms.TextBox();
            this.comboBoxLeaveType = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lblReason = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnRequestLeave = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textLeaveSubject);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.groupBox2);
            this.groupBox1.Controls.Add(this.textBoxLeaveDescription);
            this.groupBox1.Controls.Add(this.comboBoxLeaveType);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.lblReason);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(391, 316);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Leave Application";
            // 
            // textLeaveSubject
            // 
            this.textLeaveSubject.Location = new System.Drawing.Point(116, 165);
            this.textLeaveSubject.Name = "textLeaveSubject";
            this.textLeaveSubject.ReadOnly = true;
            this.textLeaveSubject.Size = new System.Drawing.Size(208, 20);
            this.textLeaveSubject.TabIndex = 12;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(17, 165);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "Subject";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.datePickerLeaveFrom);
            this.groupBox2.Controls.Add(this.datePickerLeaveTo);
            this.groupBox2.Location = new System.Drawing.Point(20, 19);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(346, 80);
            this.groupBox2.TabIndex = 10;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Select Date";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 27);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(33, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "From ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 55);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(20, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "To";
            // 
            // datePickerLeaveFrom
            // 
            this.datePickerLeaveFrom.Location = new System.Drawing.Point(107, 21);
            this.datePickerLeaveFrom.Name = "datePickerLeaveFrom";
            this.datePickerLeaveFrom.Size = new System.Drawing.Size(200, 20);
            this.datePickerLeaveFrom.TabIndex = 4;
            this.datePickerLeaveFrom.ValueChanged += new System.EventHandler(this.datePickerLeaveFrom_ValueChanged);
            // 
            // datePickerLeaveTo
            // 
            this.datePickerLeaveTo.Location = new System.Drawing.Point(107, 49);
            this.datePickerLeaveTo.Name = "datePickerLeaveTo";
            this.datePickerLeaveTo.Size = new System.Drawing.Size(200, 20);
            this.datePickerLeaveTo.TabIndex = 5;
            this.datePickerLeaveTo.ValueChanged += new System.EventHandler(this.datePickerLeaveTo_ValueChanged);
            // 
            // textBoxLeaveDescription
            // 
            this.textBoxLeaveDescription.Location = new System.Drawing.Point(116, 210);
            this.textBoxLeaveDescription.Multiline = true;
            this.textBoxLeaveDescription.Name = "textBoxLeaveDescription";
            this.textBoxLeaveDescription.Size = new System.Drawing.Size(208, 70);
            this.textBoxLeaveDescription.TabIndex = 3;
            // 
            // comboBoxLeaveType
            // 
            this.comboBoxLeaveType.AccessibleDescription = "";
            this.comboBoxLeaveType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxLeaveType.FormattingEnabled = true;
            this.comboBoxLeaveType.Items.AddRange(new object[] {
            "Sick Leave",
            "Casual Leave",
            "Vacation Leave",
            "Other(Specify)"});
            this.comboBoxLeaveType.Location = new System.Drawing.Point(116, 120);
            this.comboBoxLeaveType.Name = "comboBoxLeaveType";
            this.comboBoxLeaveType.Size = new System.Drawing.Size(208, 21);
            this.comboBoxLeaveType.TabIndex = 2;
            this.comboBoxLeaveType.SelectedIndexChanged += new System.EventHandler(this.comboBoxLeaveType_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 123);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Type of Leave";
            // 
            // lblReason
            // 
            this.lblReason.AutoSize = true;
            this.lblReason.Location = new System.Drawing.Point(17, 213);
            this.lblReason.Name = "lblReason";
            this.lblReason.Size = new System.Drawing.Size(44, 13);
            this.lblReason.TabIndex = 0;
            this.lblReason.Text = "Reason";
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(303, 348);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 26);
            this.btnCancel.TabIndex = 9;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnRequestLeave
            // 
            this.btnRequestLeave.Location = new System.Drawing.Point(173, 348);
            this.btnRequestLeave.Name = "btnRequestLeave";
            this.btnRequestLeave.Size = new System.Drawing.Size(102, 26);
            this.btnRequestLeave.TabIndex = 8;
            this.btnRequestLeave.Text = "Request Leave";
            this.btnRequestLeave.UseVisualStyleBackColor = true;
            this.btnRequestLeave.Click += new System.EventHandler(this.btnRequestLeave_Click);
            // 
            // ApplyForLeaveForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(423, 386);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnRequestLeave);
            this.Controls.Add(this.btnCancel);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ApplyForLeaveForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Apply For Leave";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblReason;
        private System.Windows.Forms.ComboBox comboBoxLeaveType;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DateTimePicker datePickerLeaveFrom;
        private System.Windows.Forms.DateTimePicker datePickerLeaveTo;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.TextBox textBoxLeaveDescription;
        private System.Windows.Forms.Button btnRequestLeave;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textLeaveSubject;
    }
}