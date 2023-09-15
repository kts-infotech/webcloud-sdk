#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"

class ExamMainCategory
{
public:

	CString MainCategoryDesc;
	int MainCategoryID;
	CString MainCategoryName;
};

class ExamSubCategory
{
public:
	int MainCategoryID;
	CString SubCategoryDesc;
	int SubCategoryID;
	CString SubCategoryName;
};

class ExamDefaultSettings
{
public:
	int DefaultNoOfQuestions;
};

class ImportData
{
public:
	CString Error;
	CString mainCatDesc;
	int mainCategoryId;
	CString mainCategoryName;
	int strPassword;
	CString strRequestType;
	CString strUserName;
	CString strUserType;
	CString subCatDesc;
	int subCategoryID;
	CString subCategoryName;
	CString url;
};

class ExamQuestionMaster
{
	CString Answer;
	int CategoryID;
	CString Option1;
	CString Option2;
	CString Option3;
	CString Option4;
	CString Question;
	int QuestionID;
	CString QuestionTitle;
};