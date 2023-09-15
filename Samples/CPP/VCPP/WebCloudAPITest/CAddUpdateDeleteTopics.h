/*********************************************************************
   Workfile : CAddUpdateDeleteTopics.h
   Description : Headerfile for CAddUpdateDeleteTopics CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CAddUpdateDeleteTopics dialog

class CAddUpdateDeleteTopics : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUpdateDeleteTopics)

public:
	CAddUpdateDeleteTopics(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddUpdateDeleteTopics();
	CArray<CString>m_ForumId;
	CArray<int>m_Topic_Id;
	CArray<CString>m_Group_Email;
	CArray<CString>m_Group_Email_Spilt;
	CArray<CString>m_strTopic_Name;
	JSONArray m_root;
	
	AppApiService* m_ForumService;
	CArray<FormDetailsInfo>m_InfoArray;
	CArray<ItemInfo>InfoArray;
	CArray<Topics>infoArray;
	
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_UPDATE_DELETE_TOPICS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSelectAll();
	afx_msg void OnBnClickedButtonUnselectAll();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonAdd();
	void AddUpdateDeleteTopicAPI();
	afx_msg void OnBnClickedOk3();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboForumName();
	void SplitCString(CString str);
	afx_msg void OnLbnSelchangeListExistingTopic();
	CString GetTopicDescription(CString strTopicName,JSONArray arr);
	afx_msg void OnBnClickedAddNew();
	int GetTopicId();
	CString GetListboxDataSelected();
	afx_msg void OnLbnSelchangeListEmails();
	bool GetadminApproval(CString strTopicName1, JSONArray arr1);
	CCheckListBox m_Listboxctrl;
	CString GetGroupEmail(JSONArray arr1);
};
