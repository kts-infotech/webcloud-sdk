using System;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest.CBMenu
{
    
    public partial class DownloadAppDataForm : Form
    {
        CloudFile m_fileToDownload = null;
        private bool bDownFailed = false;
        private int m_iLoopIter;
        private Thread downloadThread = null;
        private FileCollection m_FilesToDownload;

        private ApiTestDataUtil objTestDataUtil;
        #region Deligates and events
        public delegate void OnDownloadProgress(object sender, FileDownloadProgressEvntArgs e);
        public delegate void OnDownloadStatusChanged(object sender, DownloadStatusChangeEventArgs e);
        delegate void SetTextCallback(string text);
        public event OnDownloadProgress OnDownloadFileProgress;
        public event OnDownloadStatusChanged OnDownloadFileStatus;
        #endregion
        public DownloadAppDataForm(ApiTestDataUtil apiTestDataUtil)
        {
            InitializeComponent();
            objTestDataUtil = apiTestDataUtil;
            OnDownloadFileProgress = WCOnDownloadProgress;
            OnDownloadFileStatus = WCOnDownloadFileStatus;
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnDownldFile_Click(object sender, EventArgs e)
        {
            if (combApps.SelectedIndex == -1)
            {
                MessageBox.Show("Please select an Application Name", "App Name ?");
                return;
            }

            if (textFilePath.Text.Trim() == "")
            {
                MessageBox.Show("Please select a Destination folder to Start Download", "No Destination Folder");
                return;
            }
            if (radioAppFileData.Checked)
            {
                StartDownloadAppFileData();
            }
            else
            {
                string strAppName = combApps.SelectedItem.ToString();
                RequestDownloadAppData(strAppName);
            }

        }

        private async void RequestDownloadAppData(string strAppName)
        {
            try
            {
                AplicationFileInfo info = await objTestDataUtil.MainForm.ApiService.DownloadAppData(strAppName);
                if (info.Success)
                {
                    string strOutPath = Path.Combine(textFilePath.Text.Trim(), info.ApplicationFileName);
                    info.ConverBase64ToFile(strOutPath);
                    progressBar1.Value = 100;
                    MessageBox.Show("File Downloaded Successfully", "Success");
                }
                else
                {
                    MessageBox.Show(info.RespMessage, "Failed");
                }
            }
            catch (Exception Ex)
            {

                MessageBox.Show(Ex.ToString(), "Error");
            }
            
        }

        private void StartDownloadAppFileData()
        {
            m_FilesToDownload = new FileCollection();
            CloudFile file = new CloudFile();
            file.FilePath = combApps.SelectedItem.ToString();
            file.DestinationDirectory = textFilePath.Text;
            m_FilesToDownload.Add(file);

            if (btnDownldFile.Text == "Download File")
            {
                downloadThread = new Thread(new ThreadStart(DownloadFiles));
                downloadThread.Start();

                btnDownldFile.Text = "Abort";
            }
            else
            {
                AbortDownloading();
                downloadThread = null;
                btnDownldFile.Text = "Download File";
            }
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            ListAllDirFilesForm LocalPath = new ListAllDirFilesForm(objTestDataUtil, true, true, textFilePath.Text);
            LocalPath.ShowDialog();
            textFilePath.Text = LocalPath.DestPath;
        }
        public void WCOnDownloadProgress(object sender, FileDownloadProgressEvntArgs Progress)
        {
            string ProgressStatus = System.IO.Path.GetFileName(Progress.FileName) + "|" + Progress.ProgressPercentage + "% Completed";
            progressBar1.Value = Progress.ProgressPercentage;
            SetProgressText(ProgressStatus);
        }
        public void WCOnDownloadFileStatus(object sender, DownloadStatusChangeEventArgs Status)
        {
            string FileStatus = System.IO.Path.GetFileName(Status.File.FilePath) + "|" + Status.Status;
            SetStatusText(FileStatus);
            if (Status.Status == DownloadStatus.SingleFileDownloadFinishSuccesfuly)
            {
                downloadThread = null;
                btnDownldFile.Text = "Download File";
            }

        }
        private void SetStatusText(string Status)
        {
            if (labelStatus.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetStatusText);
                this.Invoke(d, new object[] { Status });
            }
            else
            {
                labelStatus.Text = Status;
            }
        }
        private void SetProgressText(string Progress)
        {
            if (labelProgress.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetProgressText);
                this.Invoke(d, new object[] { Progress });
            }
            else
            {
                labelProgress.Text = Progress;
            }
        }

        private void DownloadFiles()
        {
            CloudFile fileToDownload = null;

            try
            {
                for (int position = 0; position < m_FilesToDownload.Count; position++)
                {
                    fileToDownload = m_FilesToDownload[position];
                    fileToDownload.FileStatus = TransferFileStatus.NotTransfer;

                    DownloadFile(fileToDownload);

                    fileToDownload.FileStatus = TransferFileStatus.TransferSuccesfuly;
                }
            }
            catch (Exception ex)
            {
                fileToDownload.FileStatus = TransferFileStatus.TransferFailed;
                OnDownloadFileStatus(this, new DownloadStatusChangeEventArgs(fileToDownload, DownloadStatus.SingleFileDownloadFailed, ex));
            }
        }

        public void AbortDownloading()
        {
            try
            {
                downloadThread.Abort();
            }
            catch (Exception)
            {
            }
        }

        private async void DownloadFile(CloudFile fileToDownload)
        {
            OnDownloadFileStatus(this, new DownloadStatusChangeEventArgs(fileToDownload, DownloadStatus.SingleFileDownloadStarted));

            int nBufferSize = 1024 * 512;

            int ChunkCount = 0;
            if (bDownFailed)
            {
                ChunkCount = fileToDownload.LastTransferedChunkNo;
            }

            double lDownloadedFileSize = 0;
            int iDownloaProgress = 0;
            double dDownloadbyte = 0;

            try
            {
                FileChunkDownloadResp fileChunkDownloadResp = null;

                do
                {
                    m_fileToDownload = fileToDownload;
                    int buff = ChunkCount * nBufferSize;

                    FileChunkDownloadReq fileChunkDownloadReq = new FileChunkDownloadReq(ChunkCount,
                                                                                                  fileToDownload.FilePath,
                                                                                                  fileToDownload.DestinationDirectory);
                    fileChunkDownloadResp = await DownloadChunk(fileChunkDownloadReq);
                    if(!fileChunkDownloadResp.IsSuccesfulResponse)
                    {
                        MessageBox.Show(fileChunkDownloadResp.Message, "Failed");
                        AbortDownloading();
                        downloadThread = null;
                        btnDownldFile.Text = "Download File";
                        return;
                    }
                    long lFileSize = fileChunkDownloadResp.FileLength;

                    lDownloadedFileSize = lDownloadedFileSize + fileChunkDownloadResp.CurrentBuffLength;
                    dDownloadbyte = (lDownloadedFileSize / (double)lFileSize);
                    iDownloaProgress = Convert.ToInt32(dDownloadbyte * 100);

                    FileMode openMode;
                    if (fileChunkDownloadResp.ChunkNumber == 0)
                    {
                        openMode = FileMode.Create;
                    }
                    else
                    {
                        openMode = FileMode.Append;
                    }

                    WriteToFile(fileChunkDownloadResp.FileContent,
                                 Path.Combine(fileChunkDownloadResp.DestinationDirectory,
                                 Path.GetFileName(fileChunkDownloadResp.FileName)),
                                 fileChunkDownloadResp.CurrentBuffLength,
                                 openMode);

                    ChunkCount += 1;
                    m_fileToDownload.LastTransferedChunkNo = ChunkCount;

                    TransferFileStatus Tstaus = TransferFileStatus.Transferring;
                    if (100 == iDownloaProgress)
                    {
                        Tstaus = TransferFileStatus.TransferSuccesfuly;
                    }


                    OnDownloadFileProgress(this, new FileDownloadProgressEvntArgs(DownloadProgressTypes.SingleFileDownloadProgess,
                                                                 Tstaus,
                                                                 fileToDownload.FilePath,
                                                                 iDownloaProgress,
                                                                 lDownloadedFileSize));

                    if (100 == iDownloaProgress)
                    {
                        OnDownloadFileStatus(this, new DownloadStatusChangeEventArgs(fileToDownload, DownloadStatus.SingleFileDownloadFinishSuccesfuly));
                    }

                }
                while (fileChunkDownloadResp.HasBlocks);
            }
            catch (Exception Ex)
            {
                bDownFailed = true;
                m_iLoopIter += 2;
                int iThreadSleep = 1000 * m_iLoopIter;
                while (m_iLoopIter < 5)
                {
                    Thread.Sleep(iThreadSleep);
                    DownloadFile(m_fileToDownload);
                }
                throw Ex;
            }
        }

        private async Task<FileChunkDownloadResp> DownloadChunk(FileChunkDownloadReq fileChunkDownloadReq)
        {

            FileChunkDownloadResp fileChunkDownloadResp = await objTestDataUtil.MainForm.ApiService.DownloadAppFileData(fileChunkDownloadReq);
            return fileChunkDownloadResp;

        }

        private static bool WriteToFile(byte[] buffer, string strFileName, int iCurrentBuffLength, FileMode openMode)
        {
            try
            {
                FileStream fs = File.Open(strFileName, openMode);
                if (fs != null)
                {
                    fs.Write(buffer, 0, iCurrentBuffLength);
                    fs.Close();
                    return true;
                }
                else
                {
                    return false;
                }
            }
            catch (Exception Ex)
            {
                throw new Exception(Ex.Message, Ex.InnerException);
            }
        }
    }
}
