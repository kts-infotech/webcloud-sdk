/*---------------------------------------------------------------------------
	Workfile:AccountService.cpp
	Description: . Services for Account menu

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

	Author: Chandradurga S
	Last Modtime:  4-7-2022
	Last Revision:
---------------------------------------------------------------------------*/
#include "pch.h"
#include "AppApiService.h"
#include "../NetworkRequest.h"
#include "../WebCloudAPITest.h"

/*---------------------------------------------------------------------------
	Function Name: AppApiService::GetAllUserInfo
	Return Value: void
	Parameters:CArray.
	Remarks:  Calls API to get all users list.
---------------------------------------------------------------------------*/
void AppApiService::GetUserdetais(CArray<UserIn, UserIn>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("api/Account/GetUserList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserIn usrInfo;
			usrInfo.Email = jsonObj[L"Email"]->AsString().c_str();

			if (!jsonObj[L"Email"]->IsNull())
			{

				usrInfo.Email = jsonObj[L"Email"]->AsString().c_str();

			}
			if (!jsonObj[L"FirstName"]->IsNull())
			{


				usrInfo.FirstName = jsonObj[L"FirstName"]->AsString().c_str();
			}
			if (!jsonObj[L"LastName"]->IsNull())
			{


				usrInfo.LastName = jsonObj[L"LastName"]->AsString().c_str();
			}
			if (!jsonObj[L"Address"]->IsNull())
			{


				usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			}
			if (!jsonObj[L"PhoneNo"]->IsNull())
			{


				usrInfo.Phoneno = jsonObj[L"PhoneNo"]->AsString().c_str();

			}

			if (!jsonObj[L"Status"]->IsNull())
			{


				usrInfo.Status = jsonObj[L"Status"]->AsString().c_str();

			}
			//if (!jsonObj[L"isActive"]->IsNull())
			////{


			//	usrInfo.inActive = jsonObj[L"isActive"]->AsString().c_str();

			//}


			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

void AppApiService::GetAdmindetais(CArray<UserIn, UserIn>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("api/Account/GetAdminList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			UserIn usrInfo;
			usrInfo.Email = jsonObj[L"Email"]->AsString().c_str();

			if (!jsonObj[L"Email"]->IsNull())
			{

				usrInfo.Email = jsonObj[L"Email"]->AsString().c_str();

			}
			if (!jsonObj[L"FirstName"]->IsNull())
			{


				usrInfo.FirstName = jsonObj[L"FirstName"]->AsString().c_str();
			}
			if (!jsonObj[L"LastName"]->IsNull())
			{


				usrInfo.LastName = jsonObj[L"LastName"]->AsString().c_str();
			}
			if (!jsonObj[L"Address"]->IsNull())
			{


				usrInfo.Address = jsonObj[L"Address"]->AsString().c_str();
			}
			if (!jsonObj[L"PhoneNo"]->IsNull())
			{


				usrInfo.Phoneno = jsonObj[L"PhoneNo"]->AsString().c_str();

			}



			InfoArray.InsertAt(i, usrInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
CString AppApiService::Addadmindetail(Addadmin addadmin)
{
	CString url = _T("api/Account/AddAdmin");
	OnStatusMessage(url);
	CString data;
	data.Format(_T("{ \"Email\":\"%s\", \
						\"Password\" : \"%s\", \
						\"FirstName\" : \"%s\", \
						\"LastName\" : \"%s\", \
						 \"Address\" : \"%s\", \
						\"PhoneNo\" : \"%s\", \
						\"IsActive\" : true, \
						\"Status\" : null}"),
		addadmin.Email, addadmin.Password, addadmin.FirstName, addadmin.LastName, addadmin.Address, addadmin.Phoneno, addadmin.inActive);
	try
	{
		OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
	  AfxMessageBox(errorStr);
	}
	return CString();
}
CString AppApiService::Adduserdetail(Adduser adduser)
{
	CString url = _T("api/Account/AddAdmin");
	OnStatusMessage(url);
	CString data;
	data.Format(_T("{ \"Email\":\"%s\", \
						\"Password\" : \"%s\", \
						\"FirstName\" : \"%s\", \
						\"LastName\" : \"%s\", \
						 \"Address\" : \"%s\", \
						\"PhoneNo\" : \"%s\", \
						\"IsActive\" : true, \
						\"Status\" : null}"),
		adduser.Email, adduser.Password, adduser.FirstName, adduser.LastName, adduser.Address, adduser.Phoneno, adduser.inActive);
	try
	{
		OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
CString AppApiService::Deleteuserdetail(int list)

{

	 CString strSigninURL= _T("api/Account/GetUserList");
	JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

	JSONArray arr = jval->AsArray();

	JSONObject obj = arr[list]->AsObject();
	Deleteuser del;
	del.Email = "";

	if (!obj[L"Email"]->IsNull())
	{

		del.Email = obj[L"Email"]->AsString().c_str();

	}
	CString data;
		data.Format(_T("api/Account/DeleteUser?email=%s"), del.Email);

	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(data);

		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
CString AppApiService::Deleteadmindetail(int list)

{

	CString strSigninURL = _T("api/Account/GetAdminList");
	JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

	JSONArray arr = jval->AsArray();

	JSONObject obj = arr[list]->AsObject();
	Deleteuser del;
	del.Email = "";

	if (!obj[L"Email"]->IsNull())
	{

		del.Email = obj[L"Email"]->AsString().c_str();

	}
	CString data;
	data.Format(_T("api/Account/DeleteUser?email=%s"), del.Email);

	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(data);

		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
CString AppApiService::Inviteusersercive(InviteUserapi invite)

{

	CString data;
	

	data.Format(_T("{ \"usercategory\":\"1000\",\"UserEmail\":\"%s\",\"UserMessage\" : \"%s\"}"), invite.UserEmail, invite.UserMessage);
	CString strSigninURL = _T("Api/Account/InviteUser");

	try
	{
		CWebCloudAPITestApp::SetRequestMSg(data);
		JSONValue* jval = NetworkRequest::PostReq(strSigninURL, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		//GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);

	}
	return CString();

}
CString AppApiService::Blockusersercive(CString buttontxt)
{
	BlockUserser blk;
	CString data,btn;
	CString strSign = _T("api/Account/BlockORUnBlockUser");

	data.Format(_T("{ \"Email\":\"%s\", \
						\"Password\" : \"%s\", \
						\"FirstName\" : \"%s\", \
						\"LastName\" : \"%s\", \
						 \"Address\" : \"%s\", \
						\"PhoneNo\" : \"%s\", \
						\"IsActive\" : true, \
						\"Status\" : null}"),
		blk.Email, blk.Password, blk.FirstName, blk.LastName, blk.Address, blk.Phoneno, blk.inActive);
	if (buttontxt == _T("blocked"))
	{
		try
		{
			CWebCloudAPITestApp::SetRequestMSg(data);
			JSONValue* jval = NetworkRequest::PostReq(strSign, data);
			std::wstring res = jval->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			//GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->GetWindowText(Status);

			//GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->SetWindowText(_T("UnBlocked"));
			btn = _T("UnBlocked");
			return btn;
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
		}
	}

	else if (buttontxt == _T("unblocked"))

	{
		data.Format(_T("{ \"Email\":\"%s\", \
						\"Password\" : \"%s\", \
						\"FirstName\" : \"%s\", \
						\"LastName\" : \"%s\", \
						 \"Address\" : \"%s\", \
						\"PhoneNo\" : \"%s\", \
						\"IsActive\" : false, \
						\"Status\" : null}"),
			blk.Email, blk.Password, blk.FirstName, blk.LastName, blk.Address, blk.Phoneno, blk.inActive);
		try
		{
			CWebCloudAPITestApp::SetRequestMSg(data);
			JSONValue* jval = NetworkRequest::PostReq(strSign, data);
			std::wstring res = jval->Stringify(true);
			CString cstrRes(res.c_str());

			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			//GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->SetWindowText(_T("Blocked"));
			btn = _T("Blocked");
			return btn;

		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
		}

	}
	//return CString();
}

void  AppApiService::tempaccess() {
	CString url = _T("api/Account/GenerateTempSiteAccessToken");
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(url);
		std::wstring res = jval->AsString();
		CString strAuth(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(strAuth);
	}
	catch (const std::exception& e)
	{
		CWebCloudAPITestApp::SetResponseMsg(CString(e.what()));
	}

}
