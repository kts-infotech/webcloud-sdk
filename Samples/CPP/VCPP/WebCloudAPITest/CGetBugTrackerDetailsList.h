/*---------------------------------------------------------------------------
	$Workfile: CGetBugTrackerDetailsList.h $

	Description: Header file for CGetBugTrackerDetailsList class.

	Copyright (C) 2022 KTS Computers
	All rights reserved.

   Author: Tom,LAKSHMI V
	Last $Modtime: 09/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once


// CGetBugTrackerDetailsList dialog

class CGetBugTrackerDetailsList : public CDialogEx
{
	DECLARE_DYNAMIC(CGetBugTrackerDetailsList)

public:
	CGetBugTrackerDetailsList(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetBugTrackerDetailsList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BugTrackerDetailsList };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboBugTaskTitle();
	virtual BOOL OnInitDialog();
	void GetBugTrackerList();
private:
	AppApiService* m_apiService;
	CArray<BugTaskDetails, BugTaskDetails> m_infoArray;
	CComboBox* m_BugTrackerCombo;
};
