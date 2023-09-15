#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"
#include <vector>
class Employee_Details
{
public:
	Employee_Details()
	{
		EmployeeID = _T("");
		EmployeeName = _T("");
		EmployeeType = _T("");
		EmployeeAddr = _T("");
		EmployeeEmailOff = _T("");
		EmployeeEmailHom = _T("");
		EmployeePh = _T("");
		EmployeeJoinDate = _T("");
		EmployeeLeavingDate = _T("");
		EmployeeStatus = _T("");
		EmployeeFinalSal = _T("");
		EmployeeRemarks = _T("");


	}
	CString EmployeeID;
	CString EmployeeName, EmployeeType, EmployeeAddr, EmployeeEmailOff, EmployeeEmailHom, EmployeePh, EmployeeJoinDate, EmployeeLeavingDate, EmployeeStatus, EmployeeFinalSal, EmployeeRemarks;
};
class Employee_Info
{
public:
	Employee_Info()
	{

	}
	CString EmployeeID;
	CString EmployeeName, EmployeeType, EmployeeAddr, EmployeeEmailOff, EmployeeEmailHom, EmployeePh, EmployeeJoinDate, EmployeeLeavingDate, EmployeeStatus, EmployeeFinalSal, EmployeeRemarks;
};
class InviteEmployeeInfo
{
public:
	InviteEmployeeInfo()
	{

	}
	CString UserCategory, EmployeeType, UserEmailAddress, UserMessage;
};
class LeaveRequestDetails
{
public:
	LeaveRequestDetails()
	{

	}
	CString LogID, LeaveType, Username, LogType, LogDate, FromDate, ToDate, LeaveReason, LeaveRequestStatus, LeaveRequestRemarks, ErrorInfo;
};

class LeaveReqStatus
{
public:
	LeaveReqStatus()
	{

	}
	CString LogID, LeaveRequestStatus, LeaveRequestRemarks;
};

class WCResults
{
public:
	bool Status;
	CString Desc;
	int Code;
};

class ItemInfos
{
public:
	ItemInfos()
	{
		Text = _T("");
		Value = 0;
	}

	CString Text;
	int Value;
};