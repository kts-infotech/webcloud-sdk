#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"
class TaskDetails
{
public:

	int TaskID;
	CString TaskTitle;
	CString TaskDescription;
};

class BugTaskDetails
{
public:

	CString BugTaskTitle;
	CString BugStatus;
	CString BugTaskDescription;
};
class  WebCloudUserInfo
{
public:
	bool IsAdmin;
	CString UserGroup;
};
class UserBugTaskDetailsResponse
{
public:
	bool Success;
	CString ErrorReason;
	WebCloudUserInfo UserInfo;
	CArray <BugTaskDetails, BugTaskDetails>BugTaskDetailsList;
	
     
};


class DefectDetails
{
public:
	int TopicID;
	CString Username;
	CString BugLanguage;
	CString BugAssignedTo;
	CString BugAssignedToValue;
	CString BugTaskDescription;
	CString FormType;
	CString FileAttachment;
	CString FilePath;
	CString BugTaskTitle;
};
class TopicDetails
{
public:
	int TopicID;
	CString TopicName;
	CString TopicDescription;
};
class TaskAssignedTo
{
public:
	CString EmailId;
	CString Name;
};