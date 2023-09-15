using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;
using WebCloudAPITest.CBMenu;
using System.IO;

namespace WebCloudAPITest
{
    public partial class ListAllDirFilesForm : Form
    {
        private ApiTestDataUtil objTestDataUtil;
        private TreeNode TreeRemote = null;
        bool m_bFolderType=false;
        bool m_bLocalPath = true;
        bool m_bEditDirFiles = false;
        bool m_bFileType;
        public string DestPath { get; set; }
        private FolderBrowserDialog LocalFolderPathDlg = new FolderBrowserDialog();
        private OpenFileDialog FileBrowser = new OpenFileDialog();
        public ListAllDirFilesForm(ApiTestDataUtil obj,bool bFolderType=false,bool bLocalPath=true,string DefaultPath="",bool bEditDirFiles=false)
        {
            InitializeComponent();
            m_bFileType = false;
            objTestDataUtil = obj;
            m_bFolderType = bFolderType;
            m_bLocalPath = bLocalPath;
            DestPath = DefaultPath;
            m_bEditDirFiles = bEditDirFiles; // if this option is enabled , then we can display content menu to delete/rename a file , directory etc.
        }

        private void ListAllDirFilesForm_Load(object sender, EventArgs e)
        {
            try
            {
                menuStripDirOperations.Visible = m_bEditDirFiles;
                textBoxPath.Text = DestPath;
                if (m_bLocalPath)
                {
                    if (m_bFolderType)
                    {
                        this.Text = "Select Local Folder";
                        LocalFolderPathDlg.ShowDialog();
                        textBoxPath.Text = LocalFolderPathDlg.SelectedPath+"\\";
                        
                    }
                    else
                    {
                        this.Text = "Select Local File";
                        FileBrowser.ShowDialog();
                        textBoxPath.Text = FileBrowser.FileName;
                    }
                    DestPath = textBoxPath.Text;
                    this.Close();
                }
                else
                {
                    if(objTestDataUtil.MainForm.ApiService==null)
                    {
                        throw new Exception("Please Login to the App First");
                    }
                    if (m_bFolderType)
                    {
                        this.Text = "Select Remote Folder";
                    }
                    else
                    {
                        this.Text = "Select Remote File";
                    }

                    TreeNode treeNode = new TreeNode(objTestDataUtil.MainForm.ApiService.UserID);
                    treeViewRemote.Nodes.Add(treeNode);

                }
                if(m_bEditDirFiles)
                {
                    this.Text = "Create | Delete | Rename Remote Files | Folders ..";
                }
            }
            catch(Exception Ex)
            {
                this.Close();
                MessageBox.Show(Ex.Message,"WebCloudAPITest");
            }

        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            DestPath = textBoxPath.Text ;
            this.Close();
        }
       
       
        public void SetStatusMessage(string Message)
        {
            labelStatus.Text = Message;
        }
        private void AddToTreeViewRemote(DirListingResp directoryListingResp,bool bFolder=true)
        {
            if (!directoryListingResp.IsSuccesfulResponse)
            {
                SetStatusMessage(directoryListingResp.Message);
                return;
            }
            try
            {
                if (null != TreeRemote.FirstNode && string.Compare(TreeRemote.FirstNode.Text, DefinedSettings.strNode) == 0)
                {
                    treeViewRemote.Nodes.Remove(TreeRemote.FirstNode);
                }

                //statusBarRemote.Text = string.Format("{0} Directories", Convert.ToString(directoryListingResp.DirecoryInfo.Directories.Length));
                foreach (Dir directory in directoryListingResp.DirecoryInfo.Directories)
                {
                    Dir directoryTrim = new Dir();
                    string strDirfullPath = directory.StrDirectoryName;
                    string strDirNameTrimmed = System.IO.Path.GetFileName(strDirfullPath);
                    directoryTrim.HasContents = directory.HasContents;
                    directoryTrim.StrDirectoryName = strDirNameTrimmed;

                    if (directoryTrim.HasContents)
                    {
                        TreeNode nodes = new TreeNode(directoryTrim.StrDirectoryName);
                        treeViewRemote.SelectedNode.Nodes.Add(nodes);
                        nodes.Tag = strDirfullPath;
                        nodes.ImageIndex = DefinedSettings.iImgIndxFolderClosed; ;
                        nodes.SelectedImageIndex = DefinedSettings.iImgIndxFolderOpen;
                        nodes.Nodes.Add(DefinedSettings.strNode);
                    }
                    else
                    {
                        TreeNode nodes = new TreeNode(directoryTrim.StrDirectoryName);
                        treeViewRemote.SelectedNode.Nodes.Add(nodes);
                        nodes.Tag = strDirfullPath;
                        nodes.ImageIndex = DefinedSettings.iImgIndxFolderClosed;
                        nodes.SelectedImageIndex = DefinedSettings.iImgIndxFolderOpen;
                        nodes.Text = directoryTrim.StrDirectoryName;
                    }
                }
                if (!bFolder)
                {
                    foreach (FileDetails FileInfo in directoryListingResp.DirecoryInfo.Filedetails)
                    {
                        TreeNode nodes = new TreeNode(FileInfo.FileName);
                        treeViewRemote.SelectedNode.Nodes.Add(nodes);
                        nodes.Tag = FileInfo.FileName;
                        nodes.ImageIndex = DefinedSettings.iImgIndxKeyFile;
                        nodes.SelectedImageIndex = DefinedSettings.iImgIndxKeyFile;
                        nodes.Text = System.IO.Path.GetFileName(FileInfo.FileName);
                    }
                }


            }
            catch (Exception ex)
            { throw ex; }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private async void treeViewRemote_AfterSelect(object sender, TreeViewEventArgs e)
        {
            try
            {
                treeViewRemote.SelectedNode.Nodes.Clear();
                await BrowseDirectory();
            }
            catch (Exception) { }

        }

        public async Task BrowseDirectory()
        {
            try
            {
                SetStatusMessage("Please Wait...");
                TreeNode CurrentNode = treeViewRemote.SelectedNode;
                if (CurrentNode != TreeRemote)
                {
                    TreeRemote = CurrentNode;
                }
                else
                {
                    SetStatusMessage("Clicked on the Same Node ..");
                    return;
                }

                List<string> ParentArray = new List<string>();
                TreeNode Parent = TreeRemote.Parent;
                while (Parent != null)
                {
                    ParentArray.Add(Parent.Text);
                    Parent = Parent.Parent;
                }
                DestPath = "";
                for (int i = ParentArray.Count - 1; i >= 0; i--)
                {
                    DestPath = DestPath + ParentArray[i] + "\\";
                }
                DestPath = DestPath + TreeRemote.Text + "\\";
                if (m_bFolderType)
                {
                    textBoxPath.Text = DestPath;
                }
                else
                {
                    if(TreeRemote.Tag!=null)
                    {
                        textBoxPath.Text = TreeRemote.Tag.ToString();
                    }
                    
                }
                
                DirListingResp Resp = await objTestDataUtil.InvokeListDirectoryAPI(objTestDataUtil.MainForm.ApiService.UserID, DestPath);
                m_bFileType = (Resp.DirecoryInfo == null);
                AddToTreeViewRemote(Resp, m_bFolderType);
                objTestDataUtil.MainForm.SetResponseData(Resp);
                SetStatusMessage("Done...");

            }
            catch (Exception Ex)
            {
                objTestDataUtil.MainForm.SetResponseData(Ex.Message);
            }
        }

        private void toolStripMenuItemCreate_Click(object sender, EventArgs e)
        {
            CreateDir();
        }

        private void toolStripMenuItemRename_Click(object sender, EventArgs e)
        {
            TreeNode node = treeViewRemote.SelectedNode;
            if(!m_bFileType)
            {
                RenameDir();
            }
            else
            {
                RenameFile();
            }
        }

        private void toolStripMenuItemDelete_Click(object sender, EventArgs e)
        {
            TreeNode node = treeViewRemote.SelectedNode;
            if (!m_bFileType)
            {
                DeleteDir();
            }
            else
            {
                string[] files = { textBoxPath.Text };
                DeleteFile(files);
            }
            
        }
        private async void RenameFile()
        {
            FileNameForm form = new FileNameForm(treeViewRemote.SelectedNode.Text);
            form.ShowDialog();
            if (form.DialogResult == DialogResult.Cancel)
                return;
            string fileName = form.GetFileName();
            RenameFileReq renameFile = new RenameFileReq
            {
                FullFilePath = textBoxPath.Text,
                FileName = fileName
            };
            try
            {
                RenameFileResp res = await objTestDataUtil.MainForm.ApiService.RenameFile(renameFile);
                if (res.IsSuccesfulResponse)
                {
                    MessageBox.Show(res.Message, "Success");
                    RefreshTreePart();
                }
                else
                {
                    MessageBox.Show(res.Message, "Failed");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.ToString(), "Error");
            }
        }

        private async void DeleteFile(string[] files)
        {
            DeleteFileReq deleteFile = new DeleteFileReq
            {
                FullFilePath = files
            };
            try
            {
                DialogResult dialogResult = MessageBox.Show("Are you sure want to delete this file ?", "Warning", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.No) return;
                DeleteFileResp res = await objTestDataUtil.MainForm.ApiService.DeleteFile(deleteFile);
                if (res.IsSuccesfulResponse)
                {
                    MessageBox.Show(res.Message, "Success");
                    RefreshTreePart();
                }
                else
                {
                    MessageBox.Show(res.Message, "Failed");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.ToString(), "Error");
            }
        }

        private async void DeleteDir()
        {
            DeleteDirectoryReq deleteDirectory = new DeleteDirectoryReq
            {
                strDirPath = textBoxPath.Text
            };
            try
            {
                DialogResult dialogResult = MessageBox.Show("Are you sure want to delete this folder ?", "Warning", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.No) return;
                DeleteDirectoryResp res = await objTestDataUtil.MainForm.ApiService.DeleteDirectory(deleteDirectory);
                if (res.IsSuccesfulResponse)
                {
                    MessageBox.Show(res.Message, "Success");
                    RefreshTreePart();
                }
                else
                {
                    MessageBox.Show(res.Message, "Failed");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.ToString(), "Error");
            }
        }

        private async void RenameDir()
        {
            FileNameForm form = new FileNameForm(treeViewRemote.SelectedNode.Text);
            form.ShowDialog();
            if (form.DialogResult == DialogResult.Cancel)
                return;
            string fileName = form.GetFileName();
            RenameDirectoryReq renameDirectory = new RenameDirectoryReq
            {
                Dirpath = textBoxPath.Text,
                DirectoryName = fileName
            };
            try
            {
                RenameDirectoryResp res = await objTestDataUtil.MainForm.ApiService.RenameDirectory(renameDirectory);
                if (res.IsSuccesfulResponse)
                {
                    MessageBox.Show(res.Message, "Success");
                    RefreshTreePart();
                }
                else
                {
                    MessageBox.Show(res.Message, "Failed");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.ToString(), "Error");
            }
        }

        private async void CreateDir()
        {
            FileNameForm form = new FileNameForm();
            form.ShowDialog();
            if (form.DialogResult == DialogResult.Cancel)
                return;
            string fileName = form.GetFileName();
            CreateDirectoryReq createDirectory = new CreateDirectoryReq
            {
                DirPath = textBoxPath.Text,
                StrDirName = fileName
            };
            try
            {
                CreateDirectoryResp res = await objTestDataUtil.MainForm.ApiService.CreateDirectory(createDirectory);
                if (res.IsSuccesfulResponse)
                {
                    MessageBox.Show(res.Message, "Success");
                    RefreshTreePart();
                }
                else
                {
                    MessageBox.Show(res.Message, "Failed");
                }
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.ToString(), "Error");
            }
        }

        private void RefreshTreePart()
        {
            TreeNode pareNode = treeViewRemote.SelectedNode.Parent;
            treeViewRemote.SelectedNode = pareNode;
        }
    }
}
