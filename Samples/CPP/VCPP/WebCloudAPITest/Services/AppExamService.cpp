#include "pch.h"
#include "AppApiService.h"
#include "../NetworkRequest.h"
#include "../WebCloudAPITest.h"


CString AppApiService::AddExamMainCategory(ExamMainCategory examMainCategory)
{
	CString url = _T("api/Exam/AddExamMainCategory");
	OnStatusMessage(url);
	CString data;
	data.Format(_T("{  \"MainCategoryName\":\"%s\", \
						\"MainCategoryDesc\" : \"%s\", \ }"),
		examMainCategory.MainCategoryName, examMainCategory.MainCategoryDesc);
	try
	{
		OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
	}
	return CString();
}
