
#include "pch.h"
#include "AppApiService.h"

void AppApiService::GetAllDetailedInfo(CArray<MenuInfo, MenuInfo>& AllInfo)
{
	CString strSigninURL;

			strSigninURL=_T("api/Cms/GetAllPageInfo");
			JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);
			JSONArray arr = jval->AsArray();
			for (unsigned int i = 0; i < arr.size(); i++)
			{
				JSONObject obj = arr[i]->AsObject();
				MenuInfo infomenu;
				infomenu.MenuID = obj[L"MenuID"]->AsNumber();
				infomenu.MenuName = obj[L"MenuName"]->AsString().c_str();
				infomenu.MenuLink = obj[L"MenuLink"]->AsString().c_str();
				infomenu.ParentID = obj[L"ParentID"]->AsNumber();
				infomenu.PageHeading = obj[L"PageHeading"]->AsString().c_str();
				infomenu.ShowMenu = obj[L"ShowMenu"]->AsBool();
				infomenu.Success = obj[L"Success"]->AsBool();
				infomenu.ErrorDec = obj[L"ErrorDec"]->AsString().c_str();
				infomenu.AliasURLLink = obj[L"AliasURLLink"]->AsString().c_str();
				AllInfo.InsertAt(i, infomenu);
			}
}
void AppApiService::GetSeoSettings(CArray<SeoPageDetails, SeoPageDetails>& Info)
{
	CString strSigninURL;
	strSigninURL = ("api/Cms/GetSeoSettings");
		JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);
		JSONArray arr = jval->AsArray();
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			JSONObject obj = arr[i]->AsObject();
			JSONObject jobj = obj[L"SocialSharingSettings"]->AsObject();
			SeoPageDetails pageinfo;
			pageinfo.MenuID = obj[L"MenuID"]->AsNumber();
			pageinfo.DefaultPageTitle = obj[L"DefaultPageTitle"]->AsString().c_str();
			pageinfo.DefaultMetaDescription = obj[L"DefaultMetaDescription"]->AsString().c_str();
			pageinfo.DefaultMetaKeywords = obj[L"DefaultMetaKeywords"]->AsString().c_str();
			pageinfo.IsAliasingEnabled = obj[L"IsAliasingEnabled"]->AsBool();
			pageinfo.UseDefaultSeoDetails = obj[L"UseDefaultSeoDetails"]->AsBool();
			pageinfo.SocialSharingSettings.EnableSocialSharing = jobj[L"EnableSocialSharing"]->AsBool();
			pageinfo.SocialSharingSettings.EnableWhatsAppSharing = jobj[L"EnableWhatsAppSharing"]->AsBool();
			pageinfo.SocialSharingSettings.EnableFbSharing = jobj[L"EnableFbSharing"]->AsBool();
			pageinfo.SocialSharingSettings.EnableFTOSharing = jobj[L"EnableFTOSharing"]->AsBool();
			pageinfo.SocialSharingSettings.EnableGooglePlusSharing = jobj[L"EnableGooglePlusSharing"]->AsBool();
			pageinfo.SocialSharingSettings.EnableTwitterSharing = jobj[L"EnableTwitterSharing"]->AsBool();
			Info.InsertAt(i, pageinfo);
		}
	}
void AppApiService::GetDefaultSeoSettings(CArray<SeoPageDetails, SeoPageDetails>& info)
{
	CString strSigninURL;
	strSigninURL = ("api/Cms/GetDefaultSEOSettings");
	JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);
	JSONObject obj = jval->AsObject();
	
		SeoPageDetails pageInfo;
		pageInfo.DefaultPageTitle = obj[L"DefaultPageTitle"]->AsString().c_str();
		pageInfo.DefaultMetaDescription = obj[L"DefaultMetaDescription"]->AsString().c_str();
		pageInfo.DefaultMetaKeywords = obj[L"DefaultMetaKeywords"]->AsString().c_str();
		pageInfo.IsAliasingEnabled = obj[L"IsAliasingEnabled"]->AsBool();
		info.Add(pageInfo);
}

void AppApiService::GetInternalLinkInfo(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo)
{
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetInternalLinks");
	JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

	JSONObject root = jval->AsObject();
	JSONArray arr = root[L"linkDetailList"]->AsArray();
	LinkSettingsInfo linksetinfo;
	linksetinfo.InternalLinkTitle = root[L"InternalLinkTitle"]->AsString().c_str();
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		JSONObject obj = arr[i]->AsObject();
		
		linksetinfo.linkinfo.LinkID= obj[L"LinkID"]->AsString().c_str();
		linksetinfo.linkinfo.MenuID = obj[L"MenuID"]->AsString().c_str();
		linksetinfo.linkinfo.MenuName = obj[L"MenuName"]->AsString().c_str();
		linksetinfo.linkinfo.LinkName = obj[L"LinkName"]->AsString().c_str();
		LinkInfo.InsertAt(i, linksetinfo);
	}
}
void AppApiService::GetExternalLinkInfo(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo)
{
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetExternalLinks");
	JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

	JSONObject root = jval->AsObject();
	JSONArray arr = root[L"linkDetailList"]->AsArray();
	LinkSettingsInfo linksetinfo;
	linksetinfo.ExternalLinkTitle = root[L"ExternalLinkTitle"]->AsString().c_str();
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		JSONObject obj = arr[i]->AsObject();

		linksetinfo.linkinfo.LinkID = obj[L"LinkID"]->AsString().c_str();
		linksetinfo.linkinfo.LinkUrl = obj[L"LinkUrl"]->AsString().c_str();
		linksetinfo.linkinfo.LinkName = obj[L"LinkName"]->AsString().c_str();
		linksetinfo.linkinfo.OrderNo = obj[L"OrderNo"]->AsString().c_str();
		LinkInfo.InsertAt(i, linksetinfo);
	}
}
void AppApiService::GetAllFooters(CArray< FooterDetails, FooterDetails>& FtrInfo)
{
	CString strSigninURL, strLinkName;

	strSigninURL = ("api/Cms/GetAllFooters");
	
		JSONValue* jval = NetworkRequest::PostReq(strSigninURL, strLinkName);
		JSONObject root = jval->AsObject();
		JSONArray arr = root[L"FooterList"]->AsArray();
		FooterDetails footer;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			JSONObject jobj = arr[i]->AsObject();
			footer.LinkName = jobj[L"LinkName"]->AsString().c_str();
			footer.LinkID = jobj[L"LinkID"]->AsString().c_str();
			footer.MenuID = jobj[L"MenuID"]->AsString().c_str();
			FtrInfo.Add(footer);
		}
}
void AppApiService::InvokeAddFooter(CString strLinkName, CString MenuID)
{
	CString url;
	url.Format(_T("api/Cms/AddFooter?strLinkName=" + strLinkName + "&&strMenuID=" + MenuID));
	FooterDetails footer;
	OnStatusMessage(url);
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(url);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
		JSONObject root;
		root[L"MenuID"] = new JSONValue(footer.MenuID);
		root[L"LinkName"] = new JSONValue(std::wstring(footer.LinkName));
	
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
void AppApiService::DeleteHeaderFooter(CString strLinkID)
{
	try
	{
		CString strSigninURL, Link;
		strSigninURL.Format(_T("api/Cms/DeleteHeaderFooter?strLinkID=%s"), strLinkID); 

			JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);
			std::wstring res = jval->Stringify(true);
			CString cstrRes(res.c_str());
			//OnResponseData(cstrRes);
			AfxMessageBox(cstrRes);

		}
		catch (const std::exception& e)
		{
			OnResponseData(CString(e.what()));
			
		}
}
void AppApiService::GetAllHeaders(CArray< HeaderDetails, HeaderDetails>& headerinfo)
{
	CString strSigninURL, strLinkName;

	strSigninURL = ("api/Cms/GetAllHeaders");

	JSONValue* jval = NetworkRequest::PostReq(strSigninURL, strLinkName);
	JSONObject root = jval->AsObject();
	JSONArray arr = root[L"HeaderList"]->AsArray();
	HeaderDetails header;
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		JSONObject jobj = arr[i]->AsObject();
		 header.LinkName= jobj[L"LinkName"]->AsString().c_str();
		header.LinkID= jobj[L"LinkID"]->AsString().c_str();
		header.MenuID = jobj[L"MenuID"]->AsString().c_str();
		headerinfo.Add(header);
	}
}
void AppApiService::InvokeAddHeader(CString strLinkName, CString MenuID)
{
	CString url;
	url.Format(_T("api/Cms/AddHeader?strLinkName=" + strLinkName + "&&strMenuID=" + MenuID));
	HeaderDetails header;
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(url);
		std::wstring res = jval->Stringify(true);
		CString cstrRes1(res.c_str());
		AfxMessageBox(cstrRes1);
		JSONObject root;
		root[L"MenuID"] = new JSONValue(header.MenuID);
		root[L"LinkName"] = new JSONValue(std::wstring(header.LinkName));

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
void AppApiService::SetSeoSettings(CArray<SeoPageDetails, SeoPageDetails>& seoinfo)
{
	SeoPageDetails info;
	//CArray<SeoPageDetails, SeoPageDetails> m_seodetails;
	CString url = _T("api/Cms/SetSeoInfo");
	CString data;
	JSONObject obj;
	for (int i = 0; i < seoinfo.GetSize(); i++)
	{
		info = seoinfo[i];
		obj[L"MenuID"] = new JSONValue(info.MenuID);
		obj[L"DefaultPageTitle"] = new JSONValue(std::wstring(info.DefaultPageTitle));
		obj[L"DefaultMetaDescription"] = new JSONValue(std::wstring(info.DefaultMetaDescription));
		obj[L"DefaultMetaKeywords"] = new JSONValue(std::wstring(info.DefaultMetaKeywords));
		obj[L"UseDefaultSeoDetails"] = new JSONValue(info.UseDefaultSeoDetails);
		obj[L"EnableSocialSharing"] = new JSONValue(info.SocialSharingSettings.EnableSocialSharing);
		obj[L"EnableWhatsAppSharing"] = new JSONValue(info.SocialSharingSettings.EnableWhatsAppSharing);
		obj[L"EnableFbSharing"] = new JSONValue(info.SocialSharingSettings.EnableFbSharing);
		obj[L"EnableFTOSharing"] = new JSONValue(info.SocialSharingSettings.EnableFTOSharing);
		obj[L"EnableGooglePlusSharing"] = new JSONValue(info.SocialSharingSettings.EnableGooglePlusSharing);
		obj[L"EnableTwitterSharing"] = new JSONValue(info.SocialSharingSettings.EnableTwitterSharing);
	}
	
	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		JSONValue* Defaultjval = NetworkRequest::PostReq(url, data);
		std::wstring res = Defaultjval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}
void AppApiService::UpdateInternalLinkTitle(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo)
{
	CString strDefaultTitle,checkconvert;
	LinkSettingsInfo link;
	JSONObject obj;
	for (int i = 0; i < LinkInfo.GetSize(); i++)
	{
		link = LinkInfo[i];
	}
		CString showLink;
		showLink.Format(L"%d", link.ShowInternalLink);
		if (showLink == "1")
		{
			checkconvert = "true";
		}
		else
		{
			checkconvert = "false";
		}
	
		CString strSigninURL;
		strSigninURL.Format(_T("api/Cms/UpdateInternalLinkTitle?strDefaultTitle=" + link.InternalLinkTitle + "&&ShowInternalLink=" + checkconvert));
	
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}
void AppApiService::UpdateExternalLinkTitle(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo)
{
	CString strDefaultTitle, checkconvert;
	LinkSettingsInfo link;
	JSONObject obj;
	for (int i = 0; i < LinkInfo.GetSize(); i++)
	{
		link = LinkInfo[i];
	}
	CString showLink;
	showLink.Format(L"%d", link.ShowExternalLinks);
	if (showLink == "1")
	{
		checkconvert = "true";
	}
	else
	{
		checkconvert = "false";
	}

	CString strSigninURL;
	strSigninURL.Format(_T("api/Cms/UpdateExternalLinkTitle?strDefaultTitle=" + link.ExternalLinkTitle + "&&ShowExternalLink=" + checkconvert));

	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}
void AppApiService::AddExternalLink(LinkDetails linkinfo)
{
	CString url = _T("api/Cms/AddExternalLink");
	CString data;
	data.Format(_T("{ \"MenuID\" : \"%s\", \
                       \"MenuName\" : \"%s\", \
                         \"LinkID\" : \"%s\", \
                           \"LinkName\" : \"%s\", \
                             \"LinkUrl\" : \"%s\", \
                               \"OrderNo\" : \"%s\", \
                                 \"iOrderNo\" : \"%d\"}"),
		linkinfo.MenuID, linkinfo.MenuName, linkinfo.LinkID, linkinfo.LinkName, linkinfo.LinkUrl, linkinfo.OrderNo, linkinfo.iOrderNo);
	try
	{
		JSONValue* Defaultjval = NetworkRequest::PostReq(url, data);
		std::wstring res = Defaultjval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}
void AppApiService::UpdateExternalLink(LinkDetails linkinfo)
{
	CString url = _T("api/Cms/UpdateExternalLink");
	CString data;
	JSONObject obj;
	obj[L"LinkUrl"] = new JSONValue(std::wstring(linkinfo.LinkUrl));
	obj[L"LinkName"] = new JSONValue(std::wstring(linkinfo.LinkName));
	obj[L"OrderNo"] = new JSONValue(std::wstring(linkinfo.OrderNo));
	obj[L"LinkID"] = new JSONValue(std::wstring(linkinfo.LinkID));
	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		JSONValue* Defaultjval = NetworkRequest::PostReq(url, data);
		std::wstring res = Defaultjval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}
void AppApiService::DeleteExternalLink(LinkDetails linkinfo)
{

	try
	{
		CString strSigninURL;
		strSigninURL.Format(_T("api/Cms/DeleteExternalLink?strLinkID=%s"), linkinfo.LinkID);
		JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}
void AppApiService::UpdateOrderExternalLink(CArray<LinkSettingsInfo, LinkSettingsInfo>& linkin)
{
	CString strSignin;
	strSignin = ("api/Cms/UpdateOrderExternalLink");
	LinkSettingsInfo link;
	JSONArray reArray;
	JSONObject obj;
	for (int i = 0; i < linkin.GetSize(); i++)
	{
		link = linkin[i];

		obj[L"MenuID"] = new JSONValue(std::wstring(link.linkinfo.MenuID));
		obj[L"MenuName"] = new JSONValue(std::wstring(link.linkinfo.MenuName));
		obj[L"LinkID"] = new JSONValue(std::wstring(link.linkinfo.LinkID));
		obj[L"LinkName"] = new JSONValue(std::wstring(link.linkinfo.LinkName));
		obj[L"LinkUrl"] = new JSONValue(std::wstring(link.linkinfo.LinkUrl));

		obj[L"OrderNo"] = new JSONValue(std::wstring(link.linkinfo.OrderNo));
		obj[L"iOrderNo"] = new JSONValue(link.linkinfo.iOrderNo);
		reArray.push_back(new JSONValue(obj));
	}

try
{
	JSONValue* val = new JSONValue(reArray);
	std::wstring resul = val->Stringify(true);
	CString newdata = CString(resul.c_str());
	JSONValue* jval = NetworkRequest::PostReq(strSignin, newdata);
	std::wstring res = jval->Stringify(true);
	CString cstrRes(res.c_str());
	AfxMessageBox(cstrRes);
}
catch (const std::exception& e)
{
	CString errorStr(e.what());
	AfxMessageBox(errorStr);

}
}
void AppApiService::UpdateInternalLink(LinkDetails linkinfo)
{
	CString url = _T("api/Cms/UpdateInternalLink");
	CString data;
	JSONObject obj;
	obj[L"LinkUrl"] = new JSONValue(std::wstring(linkinfo.LinkUrl));
	obj[L"LinkName"] = new JSONValue(std::wstring(linkinfo.LinkName));
	obj[L"OrderNo"] = new JSONValue(std::wstring(linkinfo.OrderNo));
	obj[L"LinkID"] = new JSONValue(std::wstring(linkinfo.LinkID));
	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		JSONValue* Defaultjval = NetworkRequest::PostReq(url, data);
		std::wstring res = Defaultjval->Stringify(true);
		CString cstrRes(res.c_str());
		AfxMessageBox(cstrRes);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
}