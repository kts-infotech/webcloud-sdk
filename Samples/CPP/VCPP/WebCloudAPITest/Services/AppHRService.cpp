#include "pch.h"
#include "AppApiService.h"
#include <afxwin.h>
#include "../NetworkRequest.h"
#include "../WebCloudAPITest.h"

CString AppApiService::AddNewEmployee(Employee_Details info)
{
	CString url;
	url = _T("api/HR/UploadNewEmployeeDetails");
	//OnStatusMessage(url);
	CString data;
	data.Format(_T("{ \"EmployeeID\":\"%s\", \
					   \"EmployeeName\" : \"%s\", \
                        \"EmployeeType\" : \"%s\", \
                         \"EmployeeAddr\" : \"%s\", \
                          \"EmployeeEmailOff\" : \"%s\", \
                           \"EmployeeEmailHom\" : \"%s\", \
                            \"EmployeePh\" : \"%s\", \
                             \"EmployeeJoinDate\" : \"%s\", \
                              \"EmployeeLeavingDate\" : \"%s\", \
                               \"EmployeeStatus\" : \"%s\", \
                                \"EmployeeFinalSal\" : \"%s\", \
                                 \"EmployeeRemarks\" : \"%s\"}"),
		info.EmployeeID, info.EmployeeName, info.EmployeeType, info.EmployeeAddr, info.EmployeeEmailOff, info.EmployeeEmailHom,
		info.EmployeePh, info.EmployeeJoinDate, info.EmployeeLeavingDate, info.EmployeeStatus, info.EmployeeFinalSal, info.EmployeeRemarks);
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
void AppApiService::EMPLOYEEVIEWLIST(CArray<Employee_Info>& InfoArray)
{


	try {
		CString getAllMessages;
		getAllMessages.Format(_T("api/HR/GetAllEmployeeDetails"));
		//OnStatusMessage(getAllMessages);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			Employee_Info Info;

			Info.EmployeeID = Jobj[L"EmployeeID"]->AsString().c_str();
			Info.EmployeeName = Jobj[L"EmployeeName"]->AsString().c_str();
			Info.EmployeeType = Jobj[L"EmployeeType"]->AsString().c_str();
			Info.EmployeeAddr = Jobj[L"EmployeeAddr"]->AsString().c_str();
			Info.EmployeeEmailOff = Jobj[L"EmployeeEmailOff"]->AsString().c_str();
			Info.EmployeeEmailHom = Jobj[L"EmployeeEmailHom"]->AsString().c_str();
			Info.EmployeePh = Jobj[L"EmployeePh"]->AsString().c_str();
			Info.EmployeeJoinDate = Jobj[L"EmployeeJoinDate"]->AsString().c_str();
			Info.EmployeeLeavingDate = Jobj[L"EmployeeLeavingDate"]->AsString().c_str();
			Info.EmployeeStatus = Jobj[L"EmployeeStatus"]->AsString().c_str();
			Info.EmployeeFinalSal = Jobj[L"EmployeeFinalSal"]->AsString().c_str();
			Info.EmployeeRemarks = Jobj[L"EmployeeRemarks"]->AsString().c_str();


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
CString AppApiService::InviteEmployee(InviteEmployeeInfo invite)

{

	CString data;


	data.Format(_T("{ \"UserCategory\":\"%s\",\"EmployeeType\":\"%s\",\"UserEmailAddress\":\"%s\",\"UserMessage\" : \"%s\"}"), invite.UserCategory, invite.EmployeeType, invite.UserEmailAddress, invite.UserMessage);
	CString strSigninURL = _T("api/HR/InviteEmployee");

	try
	{
		CWebCloudAPITestApp::SetRequestMSg(data);
		JSONValue* jval = NetworkRequest::PostReq(strSigninURL, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		//GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
		AfxMessageBox(errorStr);
	}
	return CString();

}

CString AppApiService::DeleteEmployee(CString EmployeeID)
{



	CString DeleteEmployee;
	CString ResponseMessage;
	DeleteEmployee.Format(_T("api/HR/DeleteEmployee?EmployeeId=%s"), EmployeeID);
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(DeleteEmployee);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		OnStatusMessage(DeleteEmployee);
		ResponseMessage = Jvalue->AsString().c_str();
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		OnResponseData(errorStr);
		AfxMessageBox(errorStr);
	}
	return ResponseMessage;
}





CString AppApiService::UpdateEmployee(Employee_Details Info)
{
	CString updateEmployee = _T("api/HR/UpadteEmployee");
	CString dataUpdate;
	JSONObject obj;
	//int empID = _wtoi(Info.EmployeeID);
	//empID += 1002;
	//Info.EmployeeID = std::to_wstring(empID).c_str();
	obj[L"EmployeeID"] = new JSONValue(Info.EmployeeID);
	obj[L"EmployeeName"] = new JSONValue(Info.EmployeeName);
	obj[L"EmployeeType"] = new JSONValue(Info.EmployeeType);
	obj[L"EmployeeAddr"] = new JSONValue(Info.EmployeeAddr);
	obj[L"EmployeeEmailOff"] = new JSONValue(Info.EmployeeEmailOff);
	obj[L"EmployeeEmailHom"] = new JSONValue(Info.EmployeeEmailHom);
	obj[L"EmployeePh"] = new JSONValue(Info.EmployeePh);
	obj[L"EmployeeJoinDate"] = new JSONValue(Info.EmployeeJoinDate);
	obj[L"EmployeeLeavingDate"] = new JSONValue(Info.EmployeeLeavingDate);
	obj[L"EmployeeStatus"] = new JSONValue(Info.EmployeeStatus);
	obj[L"EmployeeFinalSal"] = new JSONValue(Info.EmployeeFinalSal);
	obj[L"EmployeeRemarks"] = new JSONValue(Info.EmployeeRemarks);

	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	dataUpdate = CString(res.c_str());


	try
	{
		CString UpadteEmployee = _T("api/HR/UpadteEmployee");
		OnStatusMessage(UpadteEmployee);
		OnRequestData(dataUpdate);
		JSONValue* jval = NetworkRequest::PostReq(UpadteEmployee, dataUpdate);
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
CString AppApiService::PostLeaveRequest(WCResults& response, LeaveRequestDetails& LeaveRequestDetail)
{
	CString urls = _T("api/HR/PostALeaveRequest");
	//OnStatusMessage(urls);
	CString requestLeave;
	JSONObject obj;
	obj[L"LogID"] = new JSONValue(LeaveRequestDetail.LogID);
	obj[L"LeaveType"] = new JSONValue(LeaveRequestDetail.LeaveType);
	obj[L"UserName"] = new JSONValue(LeaveRequestDetail.Username);
	obj[L"LogType"] = new JSONValue(LeaveRequestDetail.LogType);
	obj[L"LogDate"] = new JSONValue(LeaveRequestDetail.LogDate);
	obj[L"FromDate"] = new JSONValue(LeaveRequestDetail.FromDate);
	obj[L"ToDate"] = new JSONValue(LeaveRequestDetail.ToDate);
	obj[L"LeaveReason"] = new JSONValue(LeaveRequestDetail.LeaveReason);
	obj[L"LeaveRequestStatus"] = new JSONValue(LeaveRequestDetail.LeaveRequestStatus);
	obj[L"LeaveRequestRemarks"] = new JSONValue(LeaveRequestDetail.LeaveRequestRemarks);
	obj[L"ErrorInfo"] = new JSONValue(LeaveRequestDetail.ErrorInfo);

	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	requestLeave = CString(res.c_str());


	try
	{
		JSONValue* sendResponce = NetworkRequest::PostReq(urls, requestLeave);
		JSONObject jsonObj = sendResponce->AsObject();
		response.Code = jsonObj[L"Code"]->AsNumber();
		response.Desc = jsonObj[L"Desc"]->AsString().c_str();
		response.Status = jsonObj[L"Status"]->AsBool();
		std::wstring res = sendResponce->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
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
CString AppApiService::PostLeaveStatus(WCResults& response, LeaveReqStatus& leaveRequestStatus)
{
	CString urls = _T("api/HR/PostALeaveStatus");
	//OnStatusMessage(urls);
	CString requestStatus;
	JSONObject obj;
	obj[L"LogID"] = new JSONValue(leaveRequestStatus.LogID);
	obj[L"LeaveRequestStatus"] = new JSONValue(leaveRequestStatus.LeaveRequestStatus);
	obj[L"LeaveRequestRemarks"] = new JSONValue(leaveRequestStatus.LeaveRequestRemarks);


	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	requestStatus = CString(res.c_str());


	try
	{
		JSONValue* sendResponce = NetworkRequest::PostReq(urls, requestStatus);
		JSONObject jsonObj = sendResponce->AsObject();
		response.Code = jsonObj[L"Code"]->AsNumber();
		response.Desc = jsonObj[L"Desc"]->AsString().c_str();
		response.Status = jsonObj[L"Status"]->AsBool();
		std::wstring res = sendResponce->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
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

void AppApiService::GetAllLeaveApplicationsList(CArray<LeaveRequestDetails, LeaveRequestDetails>& InfoArray)
{
	try
	{
		CString strSignInUrl = _T("Api/HR/GetAllLeaveApplicationsList");
		JSONValue* jval = NetworkRequest::GetReqEx(strSignInUrl);
		JSONArray JArray = jval->AsArray();

		for (int i = 0; i < JArray.size(); i++) {
			JSONObject jsonObj = JArray[i]->AsObject();

			LeaveRequestDetails leaveRequestInfo;
			leaveRequestInfo.Username = jsonObj[L"Username"]->AsString().c_str();



			if (!jsonObj[L"Username"]->IsNull())
			{

				leaveRequestInfo.Username = jsonObj[L"Username"]->AsString().c_str();

			}

			if (!jsonObj[L"LeaveRequestStatus"]->IsNull())
			{

				leaveRequestInfo.LeaveRequestStatus = jsonObj[L"LeaveRequestStatus"]->AsString().c_str();
			}

			if (!jsonObj[L"LeaveRequestRemarks"]->IsNull())
			{
				leaveRequestInfo.LeaveRequestRemarks = jsonObj[L"LeaveRequestRemarks"]->AsString().c_str();
			}

			if (!jsonObj[L"FromDate"]->IsNull())
			{
				leaveRequestInfo.FromDate = jsonObj[L"FromDate"]->AsString().c_str();

			}


			if (!jsonObj[L"ToDate"]->IsNull())
			{


				leaveRequestInfo.ToDate = jsonObj[L"ToDate"]->AsString().c_str();

			}



			if (!jsonObj[L"LeaveType"]->IsNull())
			{


				leaveRequestInfo.LeaveType = jsonObj[L"LeaveType"]->AsString().c_str();

			}
			if (!jsonObj[L"LeaveReason"]->IsNull())
			{


				leaveRequestInfo.LeaveReason = jsonObj[L"LeaveReason"]->AsString().c_str();

			}


			InfoArray.InsertAt(i, leaveRequestInfo);
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

void AppApiService::LEAVEVIEWLIST(CArray<LeaveRequestDetails>& InfoArray)
{

	try {
		CString getAllMessages;
		getAllMessages.Format(_T("Api/HR/GetAllLeaveApplicationsList"));
		//OnStatusMessage(getAllMessages);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			LeaveRequestDetails Info;

			Info.LogID = Jobj[L"LogID"]->AsString().c_str();
			Info.Username = Jobj[L"Username"]->AsString().c_str();
			Info.FromDate = Jobj[L"FromDate"]->AsString().c_str();
			Info.ToDate = Jobj[L"ToDate"]->AsString().c_str();
			Info.LeaveType = Jobj[L"LeaveType"]->AsString().c_str();
			Info.LeaveReason = Jobj[L"LeaveReason"]->AsString().c_str();
			Info.LeaveRequestStatus = Jobj[L"LeaveRequestStatus"]->AsString().c_str();
			Info.LeaveRequestRemarks = Jobj[L"LeaveRequestRemarks"]->AsString().c_str();

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

void AppApiService::GETLOGID(CArray<LeaveRequestDetails>& InfoArray, int index)
{

	try {
		CString getAllMessages;
		getAllMessages.Format(_T("Api/HR/GetAllLeaveApplicationsList"));
		//OnStatusMessage(getAllMessages);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			if (i == index) {
				JSONObject Jobj = root[i]->AsObject();
				LeaveRequestDetails InfoDetails;

				InfoDetails.LogID = Jobj[L"LogID"]->AsString().c_str();
				InfoDetails.Username = Jobj[L"Username"]->AsString().c_str();

				InfoArray.Add(InfoDetails);
			}
		}
		std::wstring res = Jvalue->Stringify(true);
		//OnResponseData(CString(res.c_str()));
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}

}