using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using WebCloud.Api.DS;

namespace WebCloud.Services
{
    public partial class AppApiService
    {
        public async Task<IList<MenuInfo>> GetAllPageInfo()
        {

            IList<MenuInfo> result = null;
            try
            {
                string Paramters = "api/Cms/GetAllPageInfo";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<List<MenuInfo>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }



        public async Task<MenuSettingsInfo> GetPageSettingsInfo(string menuname)
        {

            MenuSettingsInfo result = new MenuSettingsInfo();
            try
            {
                string Paramters = "api/Cms/GetPageSettingsInfo?menuname=" + menuname;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<MenuSettingsInfo>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }


        public async Task<List<SEODPageDetails>> GetSeoSettings()
        {

            List<SEODPageDetails> result = null;
            try
            {
                string Paramters = "api/Cms/GetSeoSettings";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<List<SEODPageDetails>>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }
                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<string> SetSeoPageInfo(SEODPageDetails seodetails)
        {
            string result;
            try
            {
                var serializedItem = JsonConvert.SerializeObject(seodetails);
                string Paramters = "api/Cms/SetSeoInfo";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }




        public async Task<LinkSettingsInfo> GetExternalLinkInfo()
        {

            LinkSettingsInfo result = new LinkSettingsInfo();
            try
            {
                string Paramters = "api/Cms/GetExternalLinks";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<LinkSettingsInfo>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }



        public async Task<LinkSettingsInfo> GetInternalLinkInfo()
        {

            LinkSettingsInfo result = new LinkSettingsInfo();
            try
            {
                string Paramters = "api/Cms/GetInternalLinks";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<LinkSettingsInfo>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }




        public async Task<List<MenuInfo>> GetFooterInfo()
        {

            List<MenuInfo> result = null;
            try
            {
                string Paramters = "api/Cms/GetFooterInfo";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<List<MenuInfo>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }


        public async Task<List<MenuSettingsInfo>> GetDetailedPageInfo()
        {

            List<MenuSettingsInfo> result = null;
            try
            {
                string Paramters = "api/Cms/GetDetailedPageInfo";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<List<MenuSettingsInfo>>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }


        public async Task<string> UpdateInternalLink(List<LinkDetails> links)
        {
            string result = null;
            try
            {

                var serializedItem = JsonConvert.SerializeObject(links);

                string Paramters = "api/Cms/UpdateInternalLink";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);

                Task<string> ResponseData;

                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<string> AddExternalLink(LinkDetails lnk)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/AddExternalLink";

                var serializedItem = JsonConvert.SerializeObject(lnk);
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);


                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> UpdateExternalLink(LinkDetails lnk)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/UpdateExternalLink";

                var serializedItem = JsonConvert.SerializeObject(lnk);
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);


                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }


        public async Task<string> AddFooterLink(MenuInfo menuDetails)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/AddFooterLink";


                var serializedItem = JsonConvert.SerializeObject(menuDetails);



                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);


                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }


        public async Task<string> AddHeaderLink(MenuInfo menuDetails)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/AddHeaderLink";


                var serializedItem = JsonConvert.SerializeObject(menuDetails);



                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);

                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<string> UpdateFooterInfo(MenuInfo menuDetails)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/UpdateFooterInfo";

                var serializedItem = JsonConvert.SerializeObject(menuDetails);
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);

                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<PageDetailsInfo> GetPageDetailedInfo(string strMenuID)
        {

            PageDetailsInfo result = null;
            try
            {
                string Paramters = "api/Cms/GetPageDetailedInfo?strMenuID="+ strMenuID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<PageDetailsInfo>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<SEODPageDetails> GetDefaultSEOSettings()
        {

            SEODPageDetails result = null;
            try
            {
                string Paramters = "api/Cms/GetDefaultSEOSettings";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<SEODPageDetails>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<string> UpdateDefaultSEOSettings(SEODPageDetails Info)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/UpdateDefaultSEOSettings";

                var serializedItem = JsonConvert.SerializeObject(Info);
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);

                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<MenuNameByID> GetALLMenuNameByID()
        {

            MenuNameByID result = new MenuNameByID();
            try
            {
                string Paramters = "api/Cms/GetALLMenuNameByID";
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<MenuNameByID>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }

        public async Task<string> UpdateInternalLinkTitle(string strDefaultTitle, bool ShowInternalLink)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/UpdateInternalLinkTitle?strDefaultTitle="+strDefaultTitle+"&&ShowInternalLink="+ShowInternalLink;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<string> UpdateExternalLinkTitle(string strDefaultTitle, bool ShowExternalLink)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/UpdateExternalLinkTitle?strDefaultTitle=" + strDefaultTitle + "&&ShowExternalLink=" + ShowExternalLink;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }

        public async Task<string> DeleteExternalLink(string strLinkID)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/DeleteExternalLink?strLinkID="+ strLinkID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }

        public async Task<string> UpdateOrderExternalLink(List<LinkDetails> links)
        {
            string result = null;
            try
            {
                string Paramters = "api/Cms/UpdateOrderExternalLink";

                var serializedItem = JsonConvert.SerializeObject(links);
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent(serializedItem, Encoding.UTF8, "application/json"));
                var response = Task.Run(() => requestTask);


                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<HeaderInfoList> GetAllHeaders()
        {
            HeaderInfoList result = null;
            try
            {
                string Paramters = "api/Cms/GetAllHeaders";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent("application/json"));
                var response = Task.Run(() => requestTask);


                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<HeaderInfoList>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }
        public async Task<FooterInfoList> GetAllFooters()
        {
            FooterInfoList result = null;
            try
            {
                string Paramters = "api/Cms/GetAllFooters";
                var requestTask = await AppServiceClient.PostAsync(Paramters, new StringContent("application/json"));
                var response = Task.Run(() => requestTask);


                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<FooterInfoList>(ResponseData.Result);

                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);

                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }
        }

        public async Task<string> AddHeader(string strLinkName, string strMenuID)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/AddHeader?strLinkName=" + strLinkName + "&&strMenuID="+strMenuID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<string> AddFooter(string strLinkName, string strMenuID)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/AddFooter?strLinkName=" + strLinkName + "&&strMenuID=" + strMenuID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<string> DeleteHeader(string strLinkID)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/DeleteHeaderFooter?strLinkID=" + strLinkID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }
        public async Task<string> DeleteFooter(string strLinkID)
        {

            string result = null;
            try
            {
                string Paramters = "api/Cms/DeleteHeaderFooter?strLinkID=" + strLinkID;
                var requestTask = await AppServiceClient.GetAsync(Paramters);
                var response = Task.Run(() => requestTask);
                Task<string> ResponseData;
                if (response.Result.IsSuccessStatusCode)
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    result = JsonConvert.DeserializeObject<string>(ResponseData.Result);
                }
                else
                {
                    ResponseData = response.Result.Content.ReadAsStringAsync();
                    throw new Exception(ResponseData.Result);
                }

                return result;
            }
            catch (Exception Ex)
            {
                throw Ex;
            }

        }


    }
}
