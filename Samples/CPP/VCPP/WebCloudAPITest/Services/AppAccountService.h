#pragma once
/*---------------------------------------------------------------------------
	$Workfile: AppAccountervice.h $

	Description: Header file for various data structures.

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

   Author: Chandradurga S
	Last $Modtime: 4/07/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"
#include <vector>
class UserIn
{
public:
	CString Email;
	CString FirstName;
	CString LastName;
	CString Password;
	CString Phoneno;
	CString Address;
	CString Status;
	CString inActive;
};
class Addadmin
{
public:
	Addadmin()
	{

	}

	CString Email;
	CString FirstName;
	CString LastName;
	CString Password;
	CString Phoneno;
	CString Address;
	CString Status;
	CString inActive;
};
class Adduser
{
public:
	Adduser()
	{

	}

	CString Email;
	CString FirstName;
	CString LastName;
	CString Password;
	CString Phoneno;
	CString Address;
	CString Status;
	CString inActive;
};
class Deleteuser
{
public:
	Deleteuser()
	{

	}

	CString Email;
	
};
class Deleteadmin
{
public:
	Deleteadmin()
	{

	}

	CString Email;

};
//UserEmail, UserMessage
class InviteUserapi
{
public:
	InviteUserapi()
	{

	}

	CString UserEmail;
	CString UserMessage;


};
class BlockUserser
{
public:
	BlockUserser()
	{

	}

	CString Email;
	CString FirstName;
	CString LastName;
	CString Password;
	CString Phoneno;
	CString Address;
	CString Status;
	CString inActive;


};
