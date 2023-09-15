#include "pch.h"
#include "AppApiService.h"

void AppApiService::ValidateUser(CString strUserName, CString strPassword, AuthInfo& Info)
{
	CString strSigninURL = _T("api/Auth/ValidateUser?UserID=" + strUserName + "&Password=" + strPassword);
	OnRequestData(m_strBaseAPIURL + strSigninURL);
	OnStatusMessage(strSigninURL);
	m_NetworkRequest.SetCloudUrl(m_strBaseAPIURL);

	try
	{
		JSONValue* jval = NetworkRequest::GetReq(strSigninURL);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		JSONObject root = jval->AsObject();
		CString strAuthToken(root[L"AuthenticationToken"]->AsString().c_str());
		Info.AuthenticationToken = strAuthToken;
		NetworkRequest::SetAuthToken(strAuthToken);
		Info.UserID = strUserName;

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}

}
