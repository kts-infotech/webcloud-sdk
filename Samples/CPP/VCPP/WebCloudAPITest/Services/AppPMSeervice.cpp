#include "pch.h"
#include "AppApiService.h"
#include <afxwin.h>
#include "../NetworkRequest.h"

CString AppApiService::AddNewTask(Task_Details info)
{
	CString url;
	url = _T("api/PM/UploadNewTaskDetails");
	//OnStatusMessage(url);
	CString data;
	data.Format(_T("{ \"TaskID\":\"%s\", \
					   \"TaskTitle\" : \"%s\", \
						\"TaskDescription\" : \"%s\"}"),
		info.TaskID, info.TaskTitle, info.TaskDescription);
	try
	{
		//OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		//OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
void AppApiService::TASKVIEWLIST(CArray<Task_Info>& InfoArray)
{


	try {
		CString getAllMessages;
		getAllMessages.Format(_T("api/PM/GetAllTaskList"));
		//OnStatusMessage(getAllMessages);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			Task_Info Info;

			Info.TaskTitle = Jobj[L"TaskTitle"]->AsString().c_str();
			Info.TaskDescription = Jobj[L"TaskDescription"]->AsString().c_str();
			//Info.TaskID = Jobj[L"TaskID"]->AsString().c_str();

			InfoArray.Add(Info);
		}
		std::wstring res = Jvalue->Stringify(true);
		//OnResponseData(CString(res.c_str()));
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}

}
CString AppApiService::AddNewSubTask(SubTaskDetails info)
{
	CString url;
	url = _T("api/PM/AddSubTask");
	//OnStatusMessage(url);
	CString data;
	data.Format(_T("{ \"SubTaskID\":\"%s\", \
					   \"SubTaskTitle\" : \"%s\", \
						\"SubTaskDescription\" : \"%s\"}"),
		info.SubTaskID, info.SubTaskTitle, info.SubTaskDescription);
	try
	{
		//OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		//OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
void AppApiService::SUBTASKVIEWLIST(CArray<SubTask_Info>& InfoArray)
{


	try {
		CString getAllMessages;
		getAllMessages.Format(_T("api/PM/GetAllSubTaskList"));
		//OnStatusMessage(getAllMessages);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			SubTask_Info Info;

			Info.SubTaskTitle = Jobj[L"SubTaskTitle"]->AsString().c_str();
			Info.SubTaskDescription = Jobj[L"SubTaskDescription"]->AsString().c_str();
			//Info.SubTaskID = Jobj[L"SubTaskID"]->AsString().c_str();

			InfoArray.Add(Info);
		}
		std::wstring res = Jvalue->Stringify(true);
		//OnResponseData(CString(res.c_str()));
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}

}