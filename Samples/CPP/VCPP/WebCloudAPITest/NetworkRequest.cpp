#include "pch.h"
#include "NetworkRequest.h"
#include "Base64Util.h"

CString NetworkRequest::m_strAuthToken=_T("");
CString NetworkRequest::m_strCloudUrl = _T("");
void NetworkRequest::SetCloudUrl(CString url)
{
	m_strCloudUrl = url;
}
void NetworkRequest::SetAuthToken(CString strToken)
{
	m_strAuthToken = strToken;
}
/*Parameter details
			url ->url of api example "/api/Auth/ValidateUser?UserID=admin&Password=admin"
*/
JSONValue* NetworkRequest::GetReq(CString url)
{
	try
	{
		CString strURL = m_strCloudUrl + _T("/") + url;
		http::Request request{ std::string(CT2CA(strURL)) };
		const auto response = request.send("GET");

		if (response.description == "OK")
		{
			std::wstring widestr = std::wstring{ response.body.begin(), response.body.end() };
			const wchar_t* Res = widestr.c_str();
			return JSON::Parse(Res);
		}
		else
		{
			throw std::exception(response.description.c_str());
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
	
		
    
}
JSONValue* NetworkRequest::GetReqEx(CString url, CString msg)
{
	try
	{
		CString strURL = m_strCloudUrl + _T("/") + url;
		http::Request request{ std::string(CT2CA(strURL)) };
		JSONObject root;
		std::string msgBody = (CT2CA(msg));
		std::string  method = "GET";
		std::string  strToken = (CT2CA(m_strAuthToken));
		const std::vector<std::string> headers = { "Authorization:Bearer " + strToken ,"Content-Type:application/json" };
		const auto response = request.send(method, msgBody, headers);
		if (response.description == "OK")
		{
			std::wstring widestr = std::wstring{ response.body.begin(), response.body.end() };
			const wchar_t* Res = widestr.c_str();
			return JSON::Parse(Res);
		}
		else
		{
			throw std::exception(response.description.c_str());
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
/*Parameter details
			url ->url of api example "/api/Auth/ValidateUser?UserID=admin&Password=admin"
			msg ->should be in the form of json
			Example of a class Person
			class Person
			{
				string Name;
				string Age;
			};
			Create object
			Person person;
			person.Name="Myname";
			person.Age="45";

			This data to be pass like 
			CString data =_T(
			"{ \"Name\":\"" + person.Name + "\",\
			\"Age\" : \"" + person.Age + "\" }"
			);
			PostReq(url,data)

			 
*/
JSONValue* NetworkRequest::PostReq(CString url, CString msg)
{
	try
	{
		CString strURL = m_strCloudUrl + _T("/") + url;
		http::Request request{ std::string(CT2CA(strURL)) };
		JSONObject root;
		std::string msgBody = (CT2CA(msg));
		std::string  method = "POST";
		std::string  strToken = (CT2CA(m_strAuthToken));
		const std::vector<std::string> headers = { "Authorization:Bearer " + strToken ,"Content-Type:application/json" };
		const auto response = request.send(method, msgBody, headers);
		if (response.description == "OK")
		{
			std::wstring widestr = std::wstring{ response.body.begin(), response.body.end() };
			const wchar_t* Res = widestr.c_str();
			return JSON::Parse(Res);
		}
		else
		{
			throw std::exception(response.description.c_str());
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
	

}

CString NetworkRequest::ConvertToBase64(CString filePath)
{
	Base64Util util;
	std::string strPath=std::string(CT2CA(filePath));
	std::string base64=util.ConvertToBase64(strPath);
	return CString(base64.c_str());
}

bool NetworkRequest::ConvertFromBase64(CString base64string, CString filePathtoSave)
{
	Base64Util util;
	std::string strPath = std::string(CT2CA(filePathtoSave));
	std::string strBase64 = std::string(CT2CA(base64string));
	util.ConvertFromBase64(strBase64, strPath);
	return false;
}
