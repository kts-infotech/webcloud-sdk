/*********************************************************************
   Workfile : CGetAllTopic.h
   Description : Headerfile for CGetAllTopic CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once


// CGetAllTopic dialog
#include "NetworkRequest.h"
class CGetAllTopic : public CDialogEx
{
	DECLARE_DYNAMIC(CGetAllTopic)

public:
	CGetAllTopic(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetAllTopic();
	JSONValue* m_Jvalue;

	AppApiService* m_ForumService;
	CArray<Topics>m_InfoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GET_ALL_TOPIC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void GetAllTopicAPI();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboSelectTopicId();
};
