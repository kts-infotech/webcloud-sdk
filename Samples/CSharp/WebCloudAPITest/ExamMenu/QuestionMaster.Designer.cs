
namespace WebCloudAPITest
{
    partial class QuestionMaster
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
            this.trvCategories = new System.Windows.Forms.TreeView();
            this.panelq = new System.Windows.Forms.Panel();
            this.btnAddQuestion = new System.Windows.Forms.Button();
            this.pnlQuestionCustom = new System.Windows.Forms.Panel();
            this.btnViewQuestion = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.pnlQuestionCustom.SuspendLayout();
            this.SuspendLayout();
            // 
            // trvCategories
            // 
            this.trvCategories.CheckBoxes = true;
            this.trvCategories.Location = new System.Drawing.Point(3, 31);
            this.trvCategories.Name = "trvCategories";
            this.trvCategories.Size = new System.Drawing.Size(197, 407);
            this.trvCategories.TabIndex = 3;
            this.trvCategories.AfterCheck += new System.Windows.Forms.TreeViewEventHandler(this.trvCategories_AfterCheck_1);
            // 
            // panelq
            // 
            this.panelq.AutoScroll = true;
            this.panelq.AutoScrollMargin = new System.Drawing.Size(100, 100);
            this.panelq.AutoScrollMinSize = new System.Drawing.Size(100, 100);
            this.panelq.Location = new System.Drawing.Point(21, 19);
            this.panelq.Name = "panelq";
            this.panelq.Size = new System.Drawing.Size(600, 350);
            this.panelq.TabIndex = 4;
            this.panelq.Scroll += new System.Windows.Forms.ScrollEventHandler(this.panelq_Scroll);
            // 
            // btnAddQuestion
            // 
            this.btnAddQuestion.Location = new System.Drawing.Point(313, 31);
            this.btnAddQuestion.Name = "btnAddQuestion";
            this.btnAddQuestion.Size = new System.Drawing.Size(97, 30);
            this.btnAddQuestion.TabIndex = 5;
            this.btnAddQuestion.Text = "Add Questions";
            this.btnAddQuestion.UseVisualStyleBackColor = true;
            this.btnAddQuestion.Click += new System.EventHandler(this.btnAddQuestion_Click);
            // 
            // pnlQuestionCustom
            // 
            this.pnlQuestionCustom.AutoScroll = true;
            this.pnlQuestionCustom.AutoScrollMargin = new System.Drawing.Size(100, 100);
            this.pnlQuestionCustom.AutoScrollMinSize = new System.Drawing.Size(100, 100);
            this.pnlQuestionCustom.Controls.Add(this.panelq);
            this.pnlQuestionCustom.Location = new System.Drawing.Point(206, 67);
            this.pnlQuestionCustom.Name = "pnlQuestionCustom";
            this.pnlQuestionCustom.Size = new System.Drawing.Size(600, 350);
            this.pnlQuestionCustom.TabIndex = 6;
            // 
            // btnViewQuestion
            // 
            this.btnViewQuestion.Location = new System.Drawing.Point(206, 31);
            this.btnViewQuestion.Name = "btnViewQuestion";
            this.btnViewQuestion.Size = new System.Drawing.Size(101, 30);
            this.btnViewQuestion.TabIndex = 6;
            this.btnViewQuestion.Text = "View Questions";
            this.btnViewQuestion.UseVisualStyleBackColor = true;
            this.btnViewQuestion.Click += new System.EventHandler(this.btnViewQuestion_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(700, 433);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 13;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // QuestionMaster
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(838, 467);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.pnlQuestionCustom);
            this.Controls.Add(this.btnViewQuestion);
            this.Controls.Add(this.btnAddQuestion);
            this.Controls.Add(this.trvCategories);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "QuestionMaster";
            this.Text = "QuestionMaster";
            this.pnlQuestionCustom.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView trvCategories;
        private System.Windows.Forms.Panel panelq;
        private System.Windows.Forms.Button btnAddQuestion;
        private System.Windows.Forms.Panel pnlQuestionCustom;
        private System.Windows.Forms.Button btnViewQuestion;
        private System.Windows.Forms.Button btnCancel;
    }
}