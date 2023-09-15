
namespace WebCloudAPITest
{
    partial class Copy
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
            this.btnCopy = new System.Windows.Forms.Button();
            this.trvSource = new System.Windows.Forms.TreeView();
            this.trvDestination = new System.Windows.Forms.TreeView();
            this.label3 = new System.Windows.Forms.Label();
            this.panelq = new System.Windows.Forms.Panel();
            this.lblDefaultText = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.chkSelectAll = new System.Windows.Forms.CheckBox();
            this.btnViewQuestion = new System.Windows.Forms.Button();
            this.lblWarning = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.panelq.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(74, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Select Source\r\n";
            // 
            // btnCopy
            // 
            this.btnCopy.Location = new System.Drawing.Point(366, 471);
            this.btnCopy.Name = "btnCopy";
            this.btnCopy.Size = new System.Drawing.Size(75, 23);
            this.btnCopy.TabIndex = 5;
            this.btnCopy.Text = "Copy";
            this.btnCopy.UseVisualStyleBackColor = true;
            this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
            // 
            // trvSource
            // 
            this.trvSource.CheckBoxes = true;
            this.trvSource.Location = new System.Drawing.Point(12, 40);
            this.trvSource.Name = "trvSource";
            this.trvSource.Size = new System.Drawing.Size(181, 425);
            this.trvSource.TabIndex = 6;
            this.trvSource.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.trvSource_AfterCheck);
            // 
            // trvDestination
            // 
            this.trvDestination.CheckBoxes = true;
            this.trvDestination.Location = new System.Drawing.Point(727, 40);
            this.trvDestination.Name = "trvDestination";
            this.trvDestination.Size = new System.Drawing.Size(181, 425);
            this.trvDestination.TabIndex = 7;
            this.trvDestination.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.trvDestination_AfterCheck);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(724, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(93, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Select Destination\r\n";
            // 
            // panelq
            // 
            this.panelq.AutoScroll = true;
            this.panelq.AutoScrollMargin = new System.Drawing.Size(100, 100);
            this.panelq.AutoScrollMinSize = new System.Drawing.Size(100, 100);
            this.panelq.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.panelq.Controls.Add(this.lblDefaultText);
            this.panelq.Location = new System.Drawing.Point(19, 31);
            this.panelq.Name = "panelq";
            this.panelq.Size = new System.Drawing.Size(467, 385);
            this.panelq.TabIndex = 9;
            // 
            // lblDefaultText
            // 
            this.lblDefaultText.AutoSize = true;
            this.lblDefaultText.Location = new System.Drawing.Point(145, 193);
            this.lblDefaultText.Name = "lblDefaultText";
            this.lblDefaultText.Size = new System.Drawing.Size(0, 13);
            this.lblDefaultText.TabIndex = 0;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.chkSelectAll);
            this.groupBox1.Controls.Add(this.panelq);
            this.groupBox1.Location = new System.Drawing.Point(199, 43);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(492, 422);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Questions";
            // 
            // chkSelectAll
            // 
            this.chkSelectAll.AutoSize = true;
            this.chkSelectAll.Location = new System.Drawing.Point(19, 19);
            this.chkSelectAll.Name = "chkSelectAll";
            this.chkSelectAll.Size = new System.Drawing.Size(70, 17);
            this.chkSelectAll.TabIndex = 10;
            this.chkSelectAll.Text = "Select All";
            this.chkSelectAll.UseVisualStyleBackColor = true;
            this.chkSelectAll.Visible = false;
            this.chkSelectAll.CheckedChanged += new System.EventHandler(this.chkSelectAll_CheckedChanged);
            // 
            // btnViewQuestion
            // 
            this.btnViewQuestion.Location = new System.Drawing.Point(318, 14);
            this.btnViewQuestion.Name = "btnViewQuestion";
            this.btnViewQuestion.Size = new System.Drawing.Size(160, 23);
            this.btnViewQuestion.TabIndex = 10;
            this.btnViewQuestion.Text = "View Questions";
            this.btnViewQuestion.UseVisualStyleBackColor = true;
            this.btnViewQuestion.Click += new System.EventHandler(this.btnViewQuestion_Click);
            // 
            // lblWarning
            // 
            this.lblWarning.AutoSize = true;
            this.lblWarning.ForeColor = System.Drawing.Color.Red;
            this.lblWarning.Location = new System.Drawing.Point(734, 11);
            this.lblWarning.Name = "lblWarning";
            this.lblWarning.Size = new System.Drawing.Size(0, 13);
            this.lblWarning.TabIndex = 11;
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(508, 471);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 12;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // Copy
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(920, 529);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.lblWarning);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnViewQuestion);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.trvDestination);
            this.Controls.Add(this.trvSource);
            this.Controls.Add(this.btnCopy);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Copy";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Copy";
            this.panelq.ResumeLayout(false);
            this.panelq.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCopy;
        private System.Windows.Forms.TreeView trvSource;
        private System.Windows.Forms.TreeView trvDestination;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel panelq;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnViewQuestion;
        private System.Windows.Forms.Label lblDefaultText;
        private System.Windows.Forms.CheckBox chkSelectAll;
        private System.Windows.Forms.Label lblWarning;
        private System.Windows.Forms.Button btnCancel;
    }
}