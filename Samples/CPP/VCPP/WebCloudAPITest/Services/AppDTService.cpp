
#include "pch.h"
#include "AppApiService.h"
#include "../WebCloudAPITest.h"


void AppApiService::GetBugTrackerTaskDetailsList(CString strUsername, CArray<BugTaskDetails, BugTaskDetails>& TaskDetailsList)
{
	try
	{
		CString strUrl2;
		strUrl2.Format(_T("Api/DT/GetBugTrackerTaskDetailsList?strUserName=%s"), strUsername);
		JSONValue* jval = NetworkRequest::GetReqEx(strUrl2);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			BugTaskDetails DetailsList;
			DetailsList.BugTaskTitle = jsonObj[L"BugTaskTitle"]->AsString().c_str();
			DetailsList.BugStatus = jsonObj[L"BugStatus"]->AsString().c_str();
			DetailsList.BugTaskDescription = jsonObj[L"BugTaskDescription"]->AsString().c_str();
			TaskDetailsList.InsertAt(i, DetailsList);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
void AppApiService::AssignedTaskList(CString strUsername, CArray<TaskDetails, TaskDetails>& TaskDetailsList)
{
	try
	{
		CString strUrl2;
		strUrl2.Format(_T("Api/DT/GetAssignedBugList?strUserName=%s"), strUsername);
		JSONValue* jval = NetworkRequest::GetReqEx(strUrl2);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			TaskDetails DetailsList;
			DetailsList.TaskID = jsonObj[L"TaskID"]->AsNumber();
			/*CString strTaskID;
			strTaskID.Format(_T("%d"), DetailsList.TaskID);
			DetailsList.TaskID = jsonObj[L"TaskID"]->AsNumber();*/
			DetailsList.TaskTitle = jsonObj[L"TaskTitle"]->AsString().c_str();
			DetailsList.TaskDescription = jsonObj[L"TaskDescription"]->AsString().c_str();

			TaskDetailsList.InsertAt(i, DetailsList);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
void AppApiService::AllbugLists(CArray<BugTaskDetails, BugTaskDetails>& Allbugs)
{
	try
	{
		CString GetBugList = _T("Api/DT/GetAllBugDetailsList");
		JSONValue* jval = NetworkRequest::GetReqEx(GetBugList);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			BugTaskDetails DetailsList;
			CString BugStatus;
			if (!jsonObj[L"BugStatus"]->IsNull()) {
				DetailsList.BugStatus = jsonObj[L"BugStatus"]->AsString().c_str();
			}
			DetailsList.BugTaskTitle = jsonObj[L"BugTaskTitle"]->AsString().c_str();
			DetailsList.BugTaskDescription = jsonObj[L"BugTaskDescription"]->AsString().c_str();
			Allbugs.InsertAt(i, DetailsList);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
void AppApiService::UserTaskDetails(CString strUsername, UserBugTaskDetailsResponse& userResponse, CArray<BugTaskDetails, BugTaskDetails>& Allbugs)
{
	try
	{

		CString Url;
		Url.Format(_T("Api/DT/GetWebCloudUserTaskDetails?strUserName=%s"), strUsername);
		JSONValue* jval = NetworkRequest::GetReqEx(Url);
		JSONObject JObj = jval->AsObject();

		UserBugTaskDetailsResponse UserResponse;
		WebCloudUserInfo UserInfo;
		JSONObject Usr = JObj[L"UserInfo"]->AsObject();
		UserResponse.UserInfo.IsAdmin = Usr[L"IsAdmin"]->AsBool();
		UserResponse.Success = JObj[L"Success"]->AsBool();

		JSONArray Jarry = JObj[L"BugTaskDetailsList"]->AsArray();
		std::wstring res = jval->Stringify(true);
		CString resp(res.c_str());

		for (int i = 0; i < Jarry.size(); i++) {
			JSONObject jsonObj = Jarry[i]->AsObject();
			BugTaskDetails details;
			details.BugStatus = jsonObj[L"BugStatus"]->AsString().c_str();
			details.BugTaskTitle = jsonObj[L"BugTaskTitle"]->AsString().c_str();
			details.BugTaskDescription = jsonObj[L"BugTaskDescription"]->AsString().c_str();
			Allbugs.Add(details);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
void AppApiService::PostThread(DefectDetails& defectDetails)
{
	CString data;
	JSONObject Obj;
	Obj[L"BugTaskDescription"] = new JSONValue(defectDetails.BugTaskDescription);
	Obj[L"FileAttachment"] = new JSONValue(defectDetails.FileAttachment);
	Obj[L"FilePath"] = new JSONValue(defectDetails.FilePath);
	Obj[L"BugLanguage"] = new JSONValue(defectDetails.BugLanguage);
	Obj[L"Username"] = new JSONValue(defectDetails.Username);
	Obj[L"BugAssignedTo"] = new JSONValue(defectDetails.BugAssignedTo);
	Obj[L"BugAssignedToValue"] = new JSONValue(defectDetails.BugAssignedToValue);
	Obj[L"TopicID"] = new JSONValue(defectDetails.TopicID);
	Obj[L"FormType"] = new JSONValue(defectDetails.FormType);
	Obj[L"BugTaskTitle"] = new JSONValue(defectDetails.BugTaskTitle);
	JSONValue* val = new JSONValue(Obj);
	std::wstring res = val->Stringify(false);
	data = CString(res.c_str());

	try
	{
		CString Postdefect = _T("api/DT/PostADefect");
		CWebCloudAPITestApp::SetRequestMSg(data);
		JSONValue* jval = NetworkRequest::PostReq(Postdefect, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		AfxMessageBox(L"Posted Successfully");
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);

	}

}
void AppApiService::GetAllTopicsNameFromFormType(CArray<TopicDetails, TopicDetails>& Details)
{
	try
	{
		CString addtopic;
		//CString strFormType = (_T("DT"));
		addtopic.Format(_T("Api/DT/GetAllTopicsNameFromFormType?strFormType=DT"));

		JSONValue* jval = NetworkRequest::GetReqEx(addtopic);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			TopicDetails DetailsList;
			DetailsList.TopicName = jsonObj[L"TopicName"]->AsString().c_str();
			DetailsList.TopicDescription = jsonObj[L"TopicDescription"]->AsString().c_str();
			DetailsList.TopicID = jsonObj[L"TopicID"]->AsNumber();
			Details.InsertAt(i, DetailsList);

		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
void AppApiService::GetAssignedToList(CArray<TaskAssignedTo, TaskAssignedTo>& Assigned)
{
	try
	{
		CString Assigne;
		//CString strFormType = (_T("DT"));
		Assigne.Format(_T("Api/DT/GetAssignedToList?strFormType=DT"));

		JSONValue* jval = NetworkRequest::GetReqEx(Assigne);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();
			TaskAssignedTo Assign;
			Assign.EmailId = jsonObj[L"EmailId"]->AsString().c_str();
			Assign.Name = jsonObj[L"Name"]->AsString().c_str();
			Assigned.InsertAt(i, Assign);

		}

	}
	catch (const std::exception& e)
	{
		throw e;
	}

}