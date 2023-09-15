#include "pch.h"
#include "AppApiService.h"
#include <afxwin.h>
#include "../NetworkRequest.h"
#include "../WebCloudAPITest.h"



CString AppApiService::RegisterNewLicense(NewUserRegInfo Info)
{
	CString registerNewLicense = _T("api/License/RegisterNewLicense");
	CString data;
	JSONObject obj;
	obj[L"CustomerName"] = new JSONValue(Info.CustomerName);
	obj[L"ProductSubID"] = new JSONValue(Info.ProductSubID);
	obj[L"HardwareID"] = new JSONValue(Info.HardwareID);
	obj[L"PhoneNo"] = new JSONValue(Info.PhoneNo);
	obj[L"EmailID"] = new JSONValue(Info.EmailID);
	obj[L"Address"] = new JSONValue(Info.Address);
	obj[L"RegKey"] = new JSONValue(Info.RegKey);
	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		if (!registerNewLicense)
		{
			OnStatusMessage(registerNewLicense);
		}
		if (!data)
		{
			OnRequestData(data);
		}
		JSONValue* jval = NetworkRequest::PostReq(registerNewLicense, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		if (!cstrRes)
		{
			OnResponseData(cstrRes);
		}

		// Check if the response contains "Already registered for trial" message
		if (res.find(L"Already registered for trial") != std::wstring::npos)
		{
			AfxMessageBox(cstrRes);
			
		}
		else
		{
			AfxMessageBox(_T("Already registered for trial"));
		}
			

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	CWebCloudAPITestApp::SetResponseMsg(data);
	return CString();
}


CString AppApiService::RequestOneTimeReg(NewUserRegInfo Info)
{
	CString requestonetimereg = _T("api/License/RequestOneTimeReg");
	CString data;
	JSONObject obj;
	obj[L"CustomerName"] = new JSONValue(Info.CustomerName);
	obj[L"ProductSubID"] = new JSONValue(Info.ProductSubID);
	obj[L"HardwareID"] = new JSONValue(Info.HardwareID);
	obj[L"PhoneNo"] = new JSONValue(Info.PhoneNo);
	obj[L"EmailID"] = new JSONValue(Info.EmailID);
	obj[L"Address"] = new JSONValue(Info.Address);
	obj[L"RegKey"] = new JSONValue(Info.RegKey);
	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		if (!requestonetimereg) {
			OnStatusMessage(requestonetimereg);
		}
		if (!data)
			OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(requestonetimereg, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		if (!cstrRes)
			OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	CWebCloudAPITestApp::SetResponseMsg(data);

	return CString();
}

CString AppApiService::RequestSubscription(NewUserRegInfo Info)
{
	CString registerNewLicense = _T("api/License/RegisterNewLicense");
	CString data;
	JSONObject obj;
	obj[L"CustomerName"] = new JSONValue(Info.CustomerName);
	obj[L"ProductSubID"] = new JSONValue(Info.ProductSubID);
	obj[L"HardwareID"] = new JSONValue(Info.HardwareID);
	obj[L"PhoneNo"] = new JSONValue(Info.PhoneNo);
	obj[L"EmailID"] = new JSONValue(Info.EmailID);
	obj[L"Address"] = new JSONValue(Info.Address);
	obj[L"RegKey"] = new JSONValue(Info.RegKey);
	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		if (!registerNewLicense)
		{
			OnStatusMessage(registerNewLicense);
		}
		if (!data)
		{
			OnRequestData(data);
		}
		JSONValue* jval = NetworkRequest::PostReq(registerNewLicense, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		if (!cstrRes)
		{
			OnResponseData(cstrRes);
		}

		// Check if the response contains "Already registered for trial" message
		if (res.find(L"Already registered for trial") != std::wstring::npos)
		{
			AfxMessageBox(cstrRes);

		}
		else
		{
			AfxMessageBox(_T("Already registered for trial"));
		}
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
	CWebCloudAPITestApp::SetResponseMsg(data);

}
CString AppApiService::GetLicenseInfo(CString selectPrdt, CString Macid)
{
	return CString();

}

