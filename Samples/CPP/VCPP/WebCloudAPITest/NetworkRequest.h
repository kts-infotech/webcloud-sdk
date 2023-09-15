#pragma once
#include"Include/Httprequest.hpp" 
//https://github.com/elnormous/HTTPRequest
#include"Include/JSONvalue.h"
#include"Include/JSON.h"
class NetworkRequest
{
	static CString m_strAuthToken;
	static CString m_strCloudUrl;
public:
	static void SetCloudUrl(CString url);
	static void SetAuthToken(CString strToken);
	static JSONValue* GetReq(CString url);
	static JSONValue* GetReqEx(CString url, CString msg = _T(""));
	static JSONValue* PostReq(CString url,CString msg);
	static CString ConvertToBase64(CString filePath);
	static bool ConvertFromBase64(CString base64string, CString filePathtoSave);

};

