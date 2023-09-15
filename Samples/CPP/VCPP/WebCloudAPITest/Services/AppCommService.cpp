/*---------------------------------------------------------------------------
	Workfile:AppCommService.cpp
	Description: . Services for Comm menu

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

	Author: Jayakrishnan P
	Last Modtime:  29/06/2022
	Last Revision:
---------------------------------------------------------------------------*/
#include "pch.h"
#include "AppApiService.h"


/*---------------------------------------------------------------------------
	Function Name: AppApiService::GetAllSiteUserInfo
	Return Value: void
	Parameters:CArray.
	Remarks:  Calls API to get all users list.
---------------------------------------------------------------------------*/
void AppApiService::GetAllSiteUserInfo(CArray<UserInfo, UserInfo>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("Api/Comm/GetAllActiveSiteUsersList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserInfo usrInfo;
			usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			usrInfo.CategryId = jsonObj[L"CategryId"]->AsString().c_str();
			usrInfo.CategryName = jsonObj[L"CategryName"]->AsString().c_str();
			usrInfo.ConnectionId = jsonObj[L"ConnectionId"]->AsString().c_str();
			usrInfo.EmailID = jsonObj[L"EmailID"]->AsString().c_str();
			usrInfo.ErrorInfo = jsonObj[L"ErrorInfo"]->AsString().c_str();
			usrInfo.Name = jsonObj[L"Name"]->AsString().c_str();
			usrInfo.PhoneNo = jsonObj[L"PhoneNo"]->AsString().c_str();
			usrInfo.UserType = jsonObj[L"UserType"]->AsString().c_str();

			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}

}

/*---------------------------------------------------------------------------
	Function Name: AppApiService::GetAllSiteAdminUserInfo
	Return Value: void
	Parameters:CArray.
	Remarks:  Calls API to get all admin users list.
---------------------------------------------------------------------------*/
void AppApiService::GetAllSiteAdminUserInfo(CArray<UserInfo, UserInfo>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("Api/Comm/GetAllSiteAdminUsersList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserInfo usrInfo;
			usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			usrInfo.CategryId = jsonObj[L"CategryId"]->AsString().c_str();
			usrInfo.CategryName = jsonObj[L"CategryName"]->AsString().c_str();
			usrInfo.ConnectionId = jsonObj[L"ConnectionId"]->AsString().c_str();
			usrInfo.EmailID = jsonObj[L"EmailID"]->AsString().c_str();
			usrInfo.ErrorInfo = jsonObj[L"ErrorInfo"]->AsString().c_str();
			usrInfo.Name = jsonObj[L"Name"]->AsString().c_str();
			usrInfo.PhoneNo = jsonObj[L"PhoneNo"]->AsString().c_str();
			usrInfo.UserType = jsonObj[L"UserType"]->AsString().c_str();

			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

/*---------------------------------------------------------------------------
	Function Name: AppApiService::GetAllOnlineUserInfo
	Return Value: void
	Parameters:CArray.
	Remarks:  Calls API to get all online users list.
---------------------------------------------------------------------------*/
void AppApiService::GetAllOnlineUserInfo(CArray<UserInfo, UserInfo>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("Api/Comm/GetAllOnlineUsersList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserInfo usrInfo;
			usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			usrInfo.CategryId = jsonObj[L"CategryId"]->AsString().c_str();
			usrInfo.CategryName = jsonObj[L"CategryName"]->AsString().c_str();
			usrInfo.ConnectionId = jsonObj[L"ConnectionId"]->AsString().c_str();
			usrInfo.EmailID = jsonObj[L"EmailID"]->AsString().c_str();
			usrInfo.ErrorInfo = jsonObj[L"ErrorInfo"]->AsString().c_str();
			usrInfo.Name = jsonObj[L"Name"]->AsString().c_str();
			usrInfo.PhoneNo = jsonObj[L"PhoneNo"]->AsString().c_str();
			usrInfo.UserType = jsonObj[L"UserType"]->AsString().c_str();

			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

/*---------------------------------------------------------------------------
	Function Name: AppApiService::GetAllOnlineNormalUserInfo
	Return Value: void
	Parameters:CArray.
	Remarks:  Calls API to get all online normal users list.
---------------------------------------------------------------------------*/
void AppApiService::GetAllOnlineNormalUserInfo(CArray<UserInfo, UserInfo>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("Api/Comm/GetAllOnlineNormalUsersList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserInfo usrInfo;
			usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			usrInfo.CategryId = jsonObj[L"CategryId"]->AsString().c_str();
			usrInfo.CategryName = jsonObj[L"CategryName"]->AsString().c_str();
			usrInfo.ConnectionId = jsonObj[L"ConnectionId"]->AsString().c_str();
			usrInfo.EmailID = jsonObj[L"EmailID"]->AsString().c_str();
			usrInfo.ErrorInfo = jsonObj[L"ErrorInfo"]->AsString().c_str();
			usrInfo.Name = jsonObj[L"Name"]->AsString().c_str();
			usrInfo.PhoneNo = jsonObj[L"PhoneNo"]->AsString().c_str();
			usrInfo.UserType = jsonObj[L"UserType"]->AsString().c_str();

			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

/*---------------------------------------------------------------------------
	Function Name: AppApiService::GetAllOnlineSupportUserInfo
	Return Value: void
	Parameters:CArray.
	Remarks:  Calls API to get all online support users list.
---------------------------------------------------------------------------*/
void AppApiService::GetAllOnlineSupportUserInfo(CArray<UserInfo, UserInfo>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("Api/Comm/GetAllOnlineSupportUsersList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserInfo usrInfo;
			usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			usrInfo.CategryId = jsonObj[L"CategryId"]->AsString().c_str();
			usrInfo.CategryName = jsonObj[L"CategryName"]->AsString().c_str();
			usrInfo.ConnectionId = jsonObj[L"ConnectionId"]->AsString().c_str();
			usrInfo.EmailID = jsonObj[L"EmailID"]->AsString().c_str();
			usrInfo.ErrorInfo = jsonObj[L"ErrorInfo"]->AsString().c_str();
			usrInfo.Name = jsonObj[L"Name"]->AsString().c_str();
			usrInfo.PhoneNo = jsonObj[L"PhoneNo"]->AsString().c_str();
			usrInfo.UserType = jsonObj[L"UserType"]->AsString().c_str();

			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

/*---------------------------------------------------------------------------
	Function Name: AppApiService::SendEmail
	Return Value: void
	Parameters:WCResult, MailInfo.
	Remarks:  Calls API to send email.
---------------------------------------------------------------------------*/
void AppApiService::SendEmail(WCResult& responce, MailInfo& mailInfo)
{
	CString url = _T("Api/Comm/SendMail");

	//Serializing mailInfo.
	CString dataString1 = _T("{\"To\":\"" + mailInfo.To + "\",\"CC\":\"" + mailInfo.CC + "\",\"BCC\":\"" + mailInfo.BCC + "\",\"Subject\":\"" + mailInfo.Subject + "\",\"HtmlMailContent\":\"" + mailInfo.HtmlMailContent + "\",\"AdditionalParams\":null,\"AttachmentArray\":[");
	CString temp = _T("");
	CString dataString2 = _T("");
	for (int i = 0; i < mailInfo.AttachmentArray.GetSize(); i++)
	{
		temp.Format(_T("{ \"AttachmentBase64\":\"%s\",\"AttachmentName\":\"%s\",\"AttachmentType\":\"%s\"}"), mailInfo.AttachmentArray.GetAt(i).AttachmentBase64, mailInfo.AttachmentArray.GetAt(i).AttachmentName, mailInfo.AttachmentArray.GetAt(i).AttachmentType);
		if (i != (mailInfo.AttachmentArray.GetSize() - 1))
		{
			temp += _T(",");
		}
		dataString2 += temp;
	}
	dataString2 += _T("] }");
	CString dataString = dataString1 + dataString2;

	//Call
	JSONValue* sendResponce = NetworkRequest::PostReq(url, dataString);
	JSONObject jsonObj = sendResponce->AsObject();
	responce.Code = jsonObj[L"Code"]->AsNumber();
	responce.Desc = jsonObj[L"Desc"]->AsString().c_str();
	responce.Status = jsonObj[L"Status"]->AsBool();
}
