/*---------------------------------------------------------------------------
	$Workfile: AppCommService.h $

	Description: Header file for various data structures.

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

   Author: Jayakrishnan P
	Last $Modtime: 29/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"
#include <vector>
class UserInfo
{
public:
	CString Address;
	CString CategryId;
	CString CategryName;
	CString ConnectionId;
	CString EmailID;
	CString ErrorInfo;
	CString Name;
	CString PhoneNo;
	CString UserType;
};

class AttachmentInfo
{
	
public:
	CString AttachmentBase64;
	CString AttachmentName;
	CString AttachmentType;
};

class MailInfo
{

public:
	CString To;
	CString CC;
	CString BCC;
	CString Subject;
	CString HtmlMailContent;
	CString AdditionalParams;
	CArray<AttachmentInfo, AttachmentInfo> AttachmentArray;
};



class WCResult
{
public:
	bool Status;
	CString Desc;
	int Code;
};