#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"
class Task_Details
{
public:
	Task_Details()
	{
		TaskID = _T("");
		TaskTitle = _T("");
		TaskDescription = _T("");
	}
	CString TaskID;
	CString TaskTitle, TaskDescription;
};
class Task_Info
{
public:
	Task_Info()
	{

	}
	CString TaskID;
	CString TaskTitle, TaskDescription;
};
class SubTaskDetails
{
public:
	SubTaskDetails()
	{
		SubTaskID = _T("");
		SubTaskTitle = _T("");
		SubTaskDescription = _T("");
	}
	CString SubTaskID;
	CString SubTaskTitle, SubTaskDescription;
};
class SubTask_Info
{
public:
	SubTask_Info()
	{

	}
	CString SubTaskID;
	CString SubTaskTitle, SubTaskDescription;
};