/*********************************************************************
   Workfile : CDeleteAComment.h
   Description : Headerfile for CDeleteAComment CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CDeleteAComment dialog

class CDeleteAComment : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteAComment)

public:
	CDeleteAComment(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteAComment();
	CArray<int>m_Forum_Id;
	CArray<int> m_Topic_Id;
	CArray<int>m_Thread_Id;
	
	AppApiService* m_ForumService;
	CArray<CommentsInfo>m_InfoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_A_COMMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonUnselectAll();
	afx_msg void OnBnClickedButtonSelectAll();
	afx_msg void OnBnClickedButtonDeleteSelected();
	void DeleteACommentAPI();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboSelectForumId();
	afx_msg void OnCbnSelchangeComboSelectTopicId();
	afx_msg void OnCbnSelchangeComboSelectThreadId();
	CListCtrl m_listctrl;
	void AddCommentstoTable();
	void AddCommentTable(JSONArray arr);
	COleDateTime GetDateFromTicks(ULONGLONG date);
	
};
