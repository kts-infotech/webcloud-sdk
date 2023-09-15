/*********************************************************************
   Workfile : CDeleteAThread.h
   Description : Headerfile for CDeleteAThread CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CDeleteAThread dialog

class CDeleteAThread : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteAThread)

public:
	CDeleteAThread(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteAThread();
	JSONValue* m_Jvalue;
	CArray<CString>m_Thread_Id;

	AppApiService* m_ForumService;
	CArray<ThreadDetailsInfo>m_InfoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_A_THREAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void DeleteAThreadAPI();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboSelectThreadId();
	
	
};
