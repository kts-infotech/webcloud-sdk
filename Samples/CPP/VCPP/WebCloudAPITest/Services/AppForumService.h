/*********************************************************************
   Workfile : AppForumService.h
   Description : Implementation of  AppForumService.h
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 30 June 2022
 *********************************************************************/
#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"

class FormDetailsInfo
{
public:
    FormDetailsInfo()
    {
        FormID = _T("");
        FormName = _T("");
        FormDesc = _T("");
        GroupEmail = _T("");
        ForumType = _T("");
        IsPrivate = false;
        IsThreadAdminOnly = false;
        Success = false;
        ErrorDesc = _T("");
    }
    CString FormID;
    CString FormName;
    CString FormDesc;
    CString GroupEmail;
    CString ForumType;
    bool IsPrivate;
    bool IsThreadAdminOnly;
    bool Success;
    CString ErrorDesc;
};

class ItemInfo
{
public:
    ItemInfo()
    {
        Text = _T("");
        Value = 0;
    }

    CString Text;
    int Value;
};
class Topics
{
public:
    Topics()
    {
        TopicID = _T("");
        ForumID = _T("");
        GroupEmail = _T("");
        TopicName = _T("");
        TopicDesc = _T("");
        AdminApproval = false;
        Success = false;
        ErrorDesc = _T("");
    }

    CString TopicID;
    CString ForumID;
    CString GroupEmail;
    CString TopicName;
    CString TopicDesc;
    bool AdminApproval;
    bool Success;
    CString ErrorDesc;
};
class ForumThreadDetails
{
public:
    ForumThreadDetails()
    {

    }

    CString BugStatus;
    CString ThreadAssigned;
    CStringA PostedDate;
    CString AuthorID;
    CString ThreadImagePth;
};
class ThreadDetailsInfo
{
public:
    ThreadDetailsInfo()
    {
    }
    ForumThreadDetails ftrDetails;
    ItemInfo ForumInfo;
    ItemInfo TopicInfo;
    CString ThreadID;
    CString ThreadName;
    CString UserName;
    CString ThreadDesc;
    CString ThreadImage;
    CString ImageName;
    bool Success;
    CString ErrorDesc;
};
class UserCategotyInfo
{
public:
    UserCategotyInfo()
    {

    }
    CString CategoryID;
    CString CategoryName;
    bool Success;
    CString ErrorDesc;
};
class CommentsInfo
{
public:
    CommentsInfo()
    {

    }

    CString MsgID;
    CString ThreadID;
    CString Message;
    CString Author;
    CString User;
    CStringA PostedDate;
    CString Posteddate;
    bool Status;
    CString DeletedBy;
    bool Success;
    CString ErrorDesc;
};
