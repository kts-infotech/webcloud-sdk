using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using WebCloud.Api.DS;
using WebCloudAPITest.CMSMenu;
namespace WebCloudAPITest.TestData
{
    public partial class ApiTestDataUtil
    {
        public async Task InvokeGetAllPageInfoAPI()
        {
            try
            {
                IList<MenuInfo> Info = await ObjMainForm.ApiService.GetAllPageInfo();
                ListAllPageInfoWithLinks form = new ListAllPageInfoWithLinks(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetDetailedPageInfoAPI()
        {

            try
            {
                IList<MenuInfo> Info = await ObjMainForm.ApiService.GetAllPageInfo();
                GetDetailedPageInfo form = new GetDetailedPageInfo(ObjMainForm,Info);
                form.Show();

                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }


        public async Task<MenuSettingsInfo> GetOnePageInfo(string strProjName)
        {
            MenuSettingsInfo result = null;
            try
            {
                result = await ObjMainForm.ApiService.GetPageSettingsInfo(strProjName);
                ObjMainForm.SetResponseData(result);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
            return result;
        }

        public async Task InvokeGetSEOInfoOfPageAPI()
        {
            try
            {
                List<SEODPageDetails> Info = await ObjMainForm.ApiService.GetSeoSettings();
                GetSeoPageInfo form = new GetSeoPageInfo(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }

        }

        public async Task InvokeSetSEOInfoOfPageAPI()
        {
            try
            {
                IList<MenuInfo> Info = await ObjMainForm.ApiService.GetAllPageInfo();
                SetSeoPageInfo form = new SetSeoPageInfo(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }


        public async Task InvokeGetAllInternalLinksAPI()
        {
            try
            {
                LinkSettingsInfo Info = await ObjMainForm.ApiService.GetInternalLinkInfo();
                GetALLInternalLinks form = new GetALLInternalLinks(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
        public async Task InvokeGetAllExternalLinksAPI()
        {
            try
            {
                LinkSettingsInfo Info = await ObjMainForm.ApiService.GetExternalLinkInfo();
                GetALLExternalLinks form = new GetALLExternalLinks(Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeAddInternalLinkAPI()
        {
            try
            {
                //MenuInfo details = new MenuInfo();
                //string Info = await ObjMainForm.ApiService.AddInternalLink(details);
                MenuNameByID Info = await ObjMainForm.ApiService.GetALLMenuNameByID();
                AddInternalLink form = new AddInternalLink(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }



        public async Task InvokeAddExternalLinkAPI()
        {
            try
            {
                LinkSettingsInfo Info = await ObjMainForm.ApiService.GetExternalLinkInfo();
                AddExternalLink form = new AddExternalLink(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetFooterInfoAPI()
        {
            try
            {
                List<MenuInfo> Info = await ObjMainForm.ApiService.GetFooterInfo();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);
            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }


        }
        public async Task InvokeUpdateFooterInfoAPI(MenuInfo details)
        {
            try
            {
                string Info = await ObjMainForm.ApiService.UpdateFooterInfo(details);
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeAddHeaderLinkAPI(MenuInfo details)
        {
            try
            {
                string Info = await ObjMainForm.ApiService.AddHeaderLink(details);
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeAddFooterLinkAPI(MenuInfo details)
        {
            try
            {
                string Info = await ObjMainForm.ApiService.AddFooterLink(details);
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetAllHeadersAPI()
        {
            try
            {
                HeaderInfoList Info = await ObjMainForm.ApiService.GetAllHeaders();
                AddDelHeader form = new AddDelHeader(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }

        public async Task InvokeGetAllFootersAPI()
        {
            try
            {
                FooterInfoList Info = await ObjMainForm.ApiService.GetAllFooters();
                AddDelFooter form = new AddDelFooter(ObjMainForm, Info);
                form.Show();
                ObjMainForm.SetResponseData(Info);
                ObjMainForm.SetRequestURL(ObjMainForm.ApiService.SubmitURL);

            }
            catch (Exception Ex)
            {
                ObjMainForm.SetResponseData(Ex.Message);
            }
        }
    }
}
