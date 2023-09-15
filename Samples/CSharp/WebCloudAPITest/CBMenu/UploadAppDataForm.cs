using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using WebCloud.Api.DS;
using WebCloudAPITest.TestData;

namespace WebCloudAPITest.CBMenu
{
    public partial class UploadAppDataForm : Form
    {
        ApiTestDataUtil m_ObjApiTestDataUtil;

        private FileCollection m_Files = null;
        private int m_iNoOfTry = 1;
        private Thread uploaderThread = null;
        #region Deligates and events
        public delegate void OnUploadProgress(object sender, FileUploadProgressEvntArgs e);
        public delegate void OnUploadStatusChanged(object sender, UploadStatusChangeEventArgs e);
        delegate void SetTextCallback(string text);
        public event OnUploadProgress OnUploadFileProgress;
        public event OnUploadStatusChanged OnUploadFileStatus;
        #endregion
        public UploadAppDataForm(ApiTestDataUtil apiTestDataUtil)
        {
            InitializeComponent();
            m_ObjApiTestDataUtil = apiTestDataUtil;
            OnUploadFileProgress = WCOnUploadProgress;
            OnUploadFileStatus = WCOnUploadFileStatus;
        }

        private void btnUploadFile_Click(object sender, EventArgs e)
        {
            if(combApps.SelectedIndex==-1)
            {
                MessageBox.Show("Please select an Application Name","App Name ?");
                return;
            }
            string strDesPath = combApps.SelectedItem.ToString();
            if (radioAppFileData.Checked)
            {
                buttonUplaodFile_Click(strDesPath);
            }
            else
            {
                UploadAplicationData(strDesPath);
            }
        }

        private void UploadAplicationData(string strAppName)
        {
            AplicationFileInfo info = new AplicationFileInfo
            {
                ApplicationFileName = Path.GetFileName(textFilePath.Text.Trim()),
                ApplicationName = strAppName  
            };
            if (info.IsSizeSmall(textFilePath.Text.Trim()))
            {
                info.ConverFileToBase64(textFilePath.Text.Trim());
                InvokeAppDataUploadApi(info);
            }
            else
            {
                MessageBox.Show("File is larger than 2MB Please use Application File Data Method", "Failed");
            }
        }

        private async void InvokeAppDataUploadApi(AplicationFileInfo info)
        {
            try
            {
                AplicationFileInfo result = await m_ObjApiTestDataUtil.MainForm.ApiService.UploadAppData(info);
                if(result.Success)
                {
                    progressBar1.Value = 100;
                    MessageBox.Show("Data Saved Succesfully","Success");
                    
                }
                else
                {
                    MessageBox.Show("Data not Saved :"+result.RespMessage, "Failed");
                }
            }
            catch (Exception Ex)
            {

                MessageBox.Show("Data not Saved :" + Ex.ToString(), "Failed");
            }
        }
        private void btnBrowse_Click(object sender, EventArgs e)
        {
            try
            {
                ListAllDirFilesForm LocalPath = new ListAllDirFilesForm(m_ObjApiTestDataUtil, false, true, textFilePath.Text);
                LocalPath.ShowDialog();
                textFilePath.Text = LocalPath.DestPath;
            }
            catch (Exception Ex)
            {
                MessageBox.Show(Ex.Message);
            }
        }

        private void buttonUplaodFile_Click(string strDestinationDir)
        {
            if(textFilePath.Text.Trim()=="")
            {
                MessageBox.Show("Please select a File to Upload", "No File");
                return;
            }
            m_Files = new FileCollection();
            CloudFile file = new CloudFile();
            string strFilePath = textFilePath.Text;

            FileInfo info = new FileInfo(strFilePath);
            file.FilePath = strFilePath;
            file.DestinationDirectory = strDestinationDir;

            m_Files.Add(file);
            if (btnUploadFile.Text == "Upload File")
            {
                uploaderThread = new Thread(new ThreadStart(UploadFiles));
                uploaderThread.Start();

                btnUploadFile.Text = "Abort";
            }
            else
            {
                AbortUploading();
                uploaderThread = null;
                btnUploadFile.Text = "Upload File";
            }

        }

        public void AbortUploading()
        {
            try
            {
                uploaderThread.Abort();
            }
            catch (Exception)
            {
            }
        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        public void WCOnUploadProgress(object sender, FileUploadProgressEvntArgs Progress)
        {
            string ProgressStatus = System.IO.Path.GetFileName(Progress.FileName) + "|" + Progress.ProgressPercentage + "% Completed";
            progressBar1.Value = Progress.ProgressPercentage;
            SetProgressText(ProgressStatus);
        }
        public void WCOnUploadFileStatus(object sender, UploadStatusChangeEventArgs Status)
        {
            string FileStatus = System.IO.Path.GetFileName(Status.File.FilePath) + "|" + Status.Status;
            SetStatusText(FileStatus);
            if (Status.Status == UploadStatus.SingleFileUploadFinishSuccesfuly)
            {
                uploaderThread = null;
                btnUploadFile.Text = "Upload File";
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
        private void UploadFiles()
        {

            CloudFile file = null;
            try
            {
                for (int iIndex = 0; iIndex < m_Files.Count; iIndex++)
                {
                    file = m_Files[iIndex];
                    file.FileStatus = TransferFileStatus.NotTransfer;
                    try
                    {
                        UploadFile(file);
                        file.FileStatus = TransferFileStatus.TransferSuccesfuly;
                    }
                    catch (Exception ex)
                    {
                        file.FileStatus = TransferFileStatus.TransferFailed;
                        OnUploadFileStatus(this, new UploadStatusChangeEventArgs(file, UploadStatus.SingleFileUploadFailed, ex));

                    }

                }

                //On_Upload_Progress(this, new AiopFileUploadProgressEvntArgs(AiopProgressTypes.TotalFileUploadProgress));
            }
            catch (Exception Ex)
            {
                file.FileStatus = TransferFileStatus.TransferFailed;
                OnUploadFileStatus(this, new UploadStatusChangeEventArgs(file, UploadStatus.SingleFileUploadFailed, Ex));
            }
        }

        private async void UploadFile(CloudFile file)
        {
            OnUploadFileStatus(this, new UploadStatusChangeEventArgs(file, UploadStatus.SingleFileUploadStarted));

            Stream fileContents = null;
            try
            {
                fileContents = (Stream)file.FileContent;

                int nBufferSize = 1024 * 512;
                bool bIsEndOfFile = false;
                bool bHasBlocks = true;
                float lLen = fileContents.Length;

                if (lLen < nBufferSize)
                {
                    bHasBlocks = false;
                    nBufferSize = (int)lLen;
                }

                float iBytesRead = 0;
                int iFileBlockNo = -1;
                fileContents.Position = nBufferSize * file.LastTransferedChunkNo;

                while (iBytesRead < lLen)
                {
                    byte[] filebuff = new byte[nBufferSize];
                    iBytesRead += fileContents.Read(filebuff, 0, nBufferSize);
                    iFileBlockNo++;

                    float lRemain = lLen - fileContents.Position;
                    if (lRemain < nBufferSize)
                    {
                        nBufferSize = (int)lRemain;
                    }
                    FileChunkReq fileChunkReq = new FileChunkReq();
                    fileChunkReq.FileName = file.FilePath;
                    fileChunkReq.Data = filebuff;
                    fileChunkReq.DestinationDirectory = file.DestinationDirectory;
                    fileChunkReq.EndOfData = bIsEndOfFile;
                    fileChunkReq.HasBlocks = bHasBlocks;
                    fileChunkReq.ChunkNumber = iFileBlockNo;
                    if (100 == (int)Math.Ceiling(((decimal)(iBytesRead / lLen) * 100)))
                    {
                        fileChunkReq.EndOfData = true;
                    }
                    // retry downloading
                    file.LastTransferedChunkNo = iFileBlockNo;
                    // webservice method
                    //webservice.SetWSTData(m_strUserName, m_strPassword, m_strUserType, REQUEST_TYPE, WstUtils.GetSerilizedXml(fileChunkReq));
                    FileChunkResp Resp = await m_ObjApiTestDataUtil.MainForm.ApiService.UploadAppDataFile(fileChunkReq);

                    float sendBytes = iBytesRead / lLen;
                    int iSendByteProgress = (int)Math.Ceiling(((decimal)sendBytes * 100));

                    TransferFileStatus Tstaus = TransferFileStatus.Transferring;
                    if (100 == iSendByteProgress)
                    {
                        Tstaus = TransferFileStatus.TransferSuccesfuly;

                    }



                    FileUploadProgressEvntArgs fileUploadEventArgs =
                        new FileUploadProgressEvntArgs(ProgressTypes.SingleFileUploadProgess,
                                                           Tstaus,
                                                           fileChunkReq.FileName,
                                                           iSendByteProgress,
                                                           (int)Math.Ceiling(iBytesRead));

                    OnUploadFileProgress(this, fileUploadEventArgs);

                    if (100 == iSendByteProgress)
                    {
                        OnUploadFileStatus(this, new UploadStatusChangeEventArgs(file, UploadStatus.SingleFileUploadFinishSuccesfuly));

                    }

                }
                fileContents.Close();
                fileContents.Dispose();
                file.FileStatus = TransferFileStatus.TransferSuccesfuly;

                //OnUploadFileStatus(this, new UploadStatusChangeEventArgs(file, UploadStatus.SingleFileUploadFinishSuccesfuly));
            }
            catch (Exception)
            {
                int ThreadSleep = 1000;
                while (m_iNoOfTry <= 4)
                {
                    Thread.Sleep(ThreadSleep);

                    if (null != fileContents)
                    {
                        fileContents.Close();
                        fileContents.Dispose();
                    }

                    m_iNoOfTry++;
                    ThreadSleep = ThreadSleep * m_iNoOfTry;
                    UploadFile(file);
                }

                file.FileStatus = TransferFileStatus.TransferFailed;
                //OnUploadFileStatus(this, new UploadStatusChangeEventArgs(file, UploadStatus.SingleFileUploadFailed));
                if (null != fileContents)
                {
                    fileContents.Close();
                    fileContents.Dispose();
                }

            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
