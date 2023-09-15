/*---------------------------------------------------------------------------
	$Workfile: Cpostdeffectform.h $

	Description: Header file for Cpostdeffectform class.

	Copyright (C) 2022 KTS Computers
	All rights reserved.

   Author: Tom,LAKSHMI V
	Last $Modtime: 09/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
#include"NetworkRequest.h"

// Cpostdeffectform dialog

class Cpostdeffectform : public CDialogEx
{
	DECLARE_DYNAMIC(Cpostdeffectform)

public:
	Cpostdeffectform(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cpostdeffectform();
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strFilePath, AttachmentBase64, AttachmentName, AttachmentType,MsgBox;
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POSTADEFFECTFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboSelectTopic();
	afx_msg void OnCbnSelchangeComboSelectLanguage();
	afx_msg void OnCbnSelchangeComboSelectAssigned();
	afx_msg void OnBnClickedBrowseButton();
	afx_msg void OnBnClickedPostButton();
	virtual BOOL OnInitDialog();
	void PostADefectForm();
	void selectAssigned();
	void selectLanguage();
	CComboBox m_ComboBox3;
	CComboBox m_AssignedTo;
	CEdit m_EditAttachFile;
	afx_msg void OnBnClickedCloseButton();
	AppApiService* m_apiService;
	CArray<TopicDetails, TopicDetails> TopicArray;
	CComboBox* m_TopicCombo;
	CArray<TaskAssignedTo, TaskAssignedTo> TopicAssignedArray;
	CComboBox* m_TaskAssigned;
	DefectDetails defectdetails;

};
