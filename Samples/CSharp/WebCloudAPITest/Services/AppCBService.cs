using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloud.Services
{
    public partial class AppApiService
    {
        public async Task<DirListingResp> ListDirectory(string UserName, string DestinationPath)
        {

            DirListingResp Response=null;
            try
            {
                DirListingReq ListingReq = new DirListingReq();
                ListingReq.CurrentDirectotyPath = DestinationPath;
                ListingReq.UserID = UserName;
                var serializedItem = JsonConvert.SerializeObject(ListingReq);
                string Paramters = "api/CB/ListDirectory";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<DirListingResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<FileChunkResp> UploadFileChunk(FileChunkReq fileChunkRequest)
        {
            FileChunkResp Response = null;
            try
            {
               var serializedItem = JsonConvert.SerializeObject(fileChunkRequest);
                string Paramters = "api/CB/UploadFileChunk";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<FileChunkResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<FileChunkResp> UploadAppDataFile(FileChunkReq fileChunkRequest)
        {
            FileChunkResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(fileChunkRequest);
                string Paramters = "api/CB/UploadAppDataFile";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<FileChunkResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<AplicationFileInfo> UploadAppData(AplicationFileInfo Info)
        {
            AplicationFileInfo Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(Info);
                string Paramters = "api/CB/UploadAppData";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<AplicationFileInfo>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<AplicationFileInfo> DownloadAppData(string strAppName)
        {
            AplicationFileInfo Response = null;
            try
            {
                string Paramters = "api/CB/DownloadAppData?strAppName="+ strAppName;
                var requestTask = await AppServiceClient.PostAsync(Paramters,null);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<AplicationFileInfo>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<FileChunkDownloadResp> DownloadFileChunk(FileChunkDownloadReq fileChunkDownloadReq)
        {
            FileChunkDownloadResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(fileChunkDownloadReq);
                string Paramters = "api/CB/DownloadFileChunk";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<FileChunkDownloadResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<FileChunkDownloadResp> DownloadAppFileData(FileChunkDownloadReq fileChunkDownloadReq)
        {
            FileChunkDownloadResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(fileChunkDownloadReq);
                string Paramters = "api/CB/DownloadAppFileData";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<FileChunkDownloadResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<CreateDirectoryResp> CreateDirectory(CreateDirectoryReq CreateDirectoryReq)
        {
            CreateDirectoryResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(CreateDirectoryReq);
                string Paramters = "api/CB/CreateDirectory";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<CreateDirectoryResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<RenameDirectoryResp> RenameDirectory(RenameDirectoryReq renameDirectoryReq)
        {
            RenameDirectoryResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(renameDirectoryReq);
                string Paramters = "api/CB/RenameDirectory";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<RenameDirectoryResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<RenameFileResp> RenameFile(RenameFileReq RenameFileReq)
        {
            RenameFileResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(RenameFileReq);
                string Paramters = "api/CB/RenameFile";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<RenameFileResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<DeleteDirectoryResp> DeleteDirectory(DeleteDirectoryReq DeleteDirectoryReq)
        {
            DeleteDirectoryResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(DeleteDirectoryReq);
                string Paramters = "api/CB/DeleteDirectory";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<DeleteDirectoryResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<DeleteFileResp> DeleteFile(DeleteFileReq DeleteFileReq)
        {
            DeleteFileResp Response = null;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(DeleteFileReq);
                string Paramters = "api/CB/DeleteFile";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();

                    Response = JsonConvert.DeserializeObject<DeleteFileResp>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return Response;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
    }
}
