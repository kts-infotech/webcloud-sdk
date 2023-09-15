/*---------------------------------------------------------------------------
	$Workfile: CDtgetassigntasklist.h $

	Description: Header file for CDtgetassigntasklist class.

	Copyright (C) 2022 KTS Computers
	All rights reserved.

   Author: Tom,LAKSHMI V
	Last $Modtime: 09/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
#include "NetworkRequest.h"

// CDtgetassigntasklist dialog

class CDtgetassigntasklist : public CDialogEx
{
	DECLARE_DYNAMIC(CDtgetassigntasklist)

public:
	CDtgetassigntasklist(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDtgetassigntasklist();
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strUrl1;
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DTGETASSIGTASKLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboTaskID();
	//void getassignedtasklist();
	//int TaskID;
private:
	AppApiService* m_apiService;
	CArray<TaskDetails, TaskDetails> m_TaskDetailsList;
	CComboBox* m_TaskID;
};
