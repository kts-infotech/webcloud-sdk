/*********************************************************************
   Workfile : CGetAllThread.h
   Description : Headerfile for CGetAllThread CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CGetAllThread dialog

class CGetAllThread : public CDialogEx
{
	DECLARE_DYNAMIC(CGetAllThread)

public:
	CGetAllThread(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetAllThread();
	JSONValue* m_Jvalue;

	AppApiService* m_ForumService;
	CArray<ThreadDetailsInfo>m_InfoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETALLTHREAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel2();
	void GetAllThreadAPI();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();

	static COleDateTime GetDateFromTicks(ULONGLONG date);
	
};
