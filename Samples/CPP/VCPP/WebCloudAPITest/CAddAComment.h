/*********************************************************************
   Workfile : CAddAComment.h
   Description : Headerfile for CAddAComment CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CAddAComment dialog

class CAddAComment : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAComment)

public:
	CAddAComment(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddAComment();
	CArray<int>m_Forum_Id;
	CArray<int> m_Topic_Id;
	int m_Thread_Id;
	JSONValue* m_Jvalue;

	AppApiService* m_ForumService;
	CArray<CommentsInfo>m_InfoArray;
	CArray<ItemInfo>m_infoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_A_COMMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAddComment();
	void AddACommentAPI();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboSelectForumId();
	afx_msg void OnCbnSelchangeComboSelectTopicId();
	CString GetTicksNow();
	afx_msg void OnCbnSelchangeComboSelectThreadId();
};
