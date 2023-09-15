/*********************************************************************
   Workfile : CAddUpdateThread.h
   Description : Headerfile for CAddUpdateThread CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#pragma once
#include "NetworkRequest.h"

// CAddUpdateThread dialog

class CAddUpdateThread : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUpdateThread)

public:
	CAddUpdateThread(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddUpdateThread();
	CArray<CString> m_Forum_Id;
	CArray<int> m_Topic_Id;
	CArray<int> m_Thread_Id;
	JSONArray m_root;

	AppApiService* m_ForumService;
	CArray<FormDetailsInfo>m_InfoArray;
	CArray<ItemInfo>InfoArray;
	CArray<ItemInfo>infoArray;
	CArray<ThreadDetailsInfo>Infoarray;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_UPDATE_THREAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonSelectImage();
	BOOL OnFileOpen();
	void AddUpdateThreadAPI();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboExistingForumName();
	afx_msg void OnCbnSelchangeComboExistingTopicName();
	afx_msg void OnLbnSelchangeListExistingThreads();
	afx_msg void OnBnClickedButtonAddNew();
	afx_msg void OnPaint();
	IStream *m_pStream;
	CString m_imagepath, m_strImage, m_strName, m_strPostedDate;
	JSONObject m_Root;
	afx_msg void OnBnClickedCheck1();
	void ImageDecode(CString strBase64);
	int GetThreadId(CString strThreadName, JSONArray arr);
	CString GetTicksNow();
};
