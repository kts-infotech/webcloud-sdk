/*********************************************************************
   Workfile : CGetAllForum.h
   Description : Headerfile for CGetAllForum CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CGetAllForum dialog

class CGetAllForum : public CDialogEx
{
	DECLARE_DYNAMIC(CGetAllForum)

public:
	CGetAllForum(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetAllForum();
	JSONValue* m_Jvalue;
	//JSONObject m_Jobj;

	AppApiService* m_ForumService;
	CArray<FormDetailsInfo>m_InfoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GET_ALL_FORUM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose();
	void GetAllFormsAPI();
	virtual BOOL OnInitDialog();
	//void SetResponseData(CString msg);
	//void SetRequestData(CString msg);
	afx_msg void OnCbnSelchangeComboForumId();
};
