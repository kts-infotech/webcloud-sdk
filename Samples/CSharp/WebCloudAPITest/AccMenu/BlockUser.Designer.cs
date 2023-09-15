
namespace WebCloudAPITest
{
    partial class BlockUser
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
            this.grdUserList = new System.Windows.Forms.DataGridView();
            this.btnCancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.grdUserList)).BeginInit();
            this.SuspendLayout();
            // 
            // grdUserList
            // 
            this.grdUserList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.grdUserList.Location = new System.Drawing.Point(12, 23);
            this.grdUserList.Name = "grdUserList";
            this.grdUserList.Size = new System.Drawing.Size(776, 415);
            this.grdUserList.TabIndex = 0;
            this.grdUserList.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.grdUserList_CellClick_1);
            this.grdUserList.CellFormatting += new System.Windows.Forms.DataGridViewCellFormattingEventHandler(this.grdUserList_CellFormatting_1);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(657, 444);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(87, 26);
            this.btnCancel.TabIndex = 15;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // BlockUser
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 480);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.grdUserList);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "BlockUser";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "BlockUser";
            ((System.ComponentModel.ISupportInitialize)(this.grdUserList)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView grdUserList;
        private System.Windows.Forms.Button btnCancel;
    }
}