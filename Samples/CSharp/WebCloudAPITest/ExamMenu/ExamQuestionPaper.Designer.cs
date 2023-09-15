
namespace WebCloudAPITest
{
    partial class ExamQuestionPaper
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
            this.panelq = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btnViewQuestion = new System.Windows.Forms.Button();
            this.trvCategories = new System.Windows.Forms.TreeView();
            this.btnCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // panelq
            // 
            this.panelq.AutoScroll = true;
            this.panelq.AutoScrollMargin = new System.Drawing.Size(100, 100);
            this.panelq.AutoScrollMinSize = new System.Drawing.Size(100, 100);
            this.panelq.Location = new System.Drawing.Point(204, 71);
            this.panelq.Name = "panelq";
            this.panelq.Size = new System.Drawing.Size(574, 360);
            this.panelq.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(184, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(180, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Category > Subcategory";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(188, 105);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 13);
            this.label2.TabIndex = 3;
            // 
            // btnViewQuestion
            // 
            this.btnViewQuestion.Location = new System.Drawing.Point(204, 42);
            this.btnViewQuestion.Name = "btnViewQuestion";
            this.btnViewQuestion.Size = new System.Drawing.Size(160, 23);
            this.btnViewQuestion.TabIndex = 0;
            this.btnViewQuestion.Text = "View Questions";
            this.btnViewQuestion.UseVisualStyleBackColor = true;
            this.btnViewQuestion.Click += new System.EventHandler(this.btnViewQuestion_Click);
            // 
            // trvCategories
            // 
            this.trvCategories.CheckBoxes = true;
            this.trvCategories.Location = new System.Drawing.Point(1, 46);
            this.trvCategories.Name = "trvCategories";
            this.trvCategories.Size = new System.Drawing.Size(197, 407);
            this.trvCategories.TabIndex = 2;
            this.trvCategories.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.trvCategories_AfterCheck);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(651, 437);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 13;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // ExamQuestionPaper
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 472);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnViewQuestion);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.trvCategories);
            this.Controls.Add(this.panelq);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ExamQuestionPaper";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ExamQuestionPaper";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Panel panelq;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnViewQuestion;
        private System.Windows.Forms.TreeView trvCategories;
        private System.Windows.Forms.Button btnCancel;
    }
}