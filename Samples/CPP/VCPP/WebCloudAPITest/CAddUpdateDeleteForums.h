/*********************************************************************
   Workfile : CAddUpdateDeleteForums.h
   Description : Headerfile for CAddUpdateDeleteForums CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once


// CAddUpdateDeleteForums dialog

class CAddUpdateDeleteForums : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUpdateDeleteForums)

public:
	CAddUpdateDeleteForums(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddUpdateDeleteForums();
	CArray<CString>m_strGroupId;
	CArray<CString>m_strForumId;
	CArray<CString>m_strForumType;
	CArray<CString>m_strForumType_new;

	AppApiService* m_ForumService;
	CArray<FormDetailsInfo>m_InfoArray;
	CArray<UserCategotyInfo>InfoArray;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_UPDATE_DELETE_FORUMS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonAddNew();
	afx_msg void OnBnClickedButtonDelete();
	void AddUpdateDeleteForumAPI();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeListExistingForumNames();
	void SetCurrentTextCombo(int ID, CString text);
};
