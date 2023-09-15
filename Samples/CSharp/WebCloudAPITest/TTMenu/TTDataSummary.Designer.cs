
namespace WebCloudAPITest.TTMenu
{
    partial class TTDataSummary
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
            this.label1 = new System.Windows.Forms.Label();
            this.textTdyHrs = new System.Windows.Forms.TextBox();
            this.textWekHrs = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textMthHrs = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.btnClose = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textMthHrs);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textWekHrs);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textTdyHrs);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(230, 185);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Data Summary";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(29, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(74, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Today Hours :";
            // 
            // textTdyHrs
            // 
            this.textTdyHrs.Location = new System.Drawing.Point(108, 32);
            this.textTdyHrs.Name = "textTdyHrs";
            this.textTdyHrs.Size = new System.Drawing.Size(100, 20);
            this.textTdyHrs.TabIndex = 1;
            // 
            // textWekHrs
            // 
            this.textWekHrs.Location = new System.Drawing.Point(108, 75);
            this.textWekHrs.Name = "textWekHrs";
            this.textWekHrs.Size = new System.Drawing.Size(100, 20);
            this.textWekHrs.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(7, 75);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(96, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "This Week Hours :";
            // 
            // textMthHrs
            // 
            this.textMthHrs.Location = new System.Drawing.Point(108, 125);
            this.textMthHrs.Name = "textMthHrs";
            this.textMthHrs.Size = new System.Drawing.Size(100, 20);
            this.textMthHrs.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 125);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(97, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "This Month Hours :";
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(168, 204);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // TTDataSummary
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(264, 239);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TTDataSummary";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TTDataSummary";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textMthHrs;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textWekHrs;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textTdyHrs;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnClose;
    }
}