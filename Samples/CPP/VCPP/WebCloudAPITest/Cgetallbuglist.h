/*---------------------------------------------------------------------------
	$Workfile: Cgetallbuglist.h $

	Description: Header file for Cgetallbuglist class.

	Copyright (C) 2022 KTS Computers
	All rights reserved.

   Author: Tom,LAKSHMI V
	Last $Modtime: 09/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once

#include"NetworkRequest.h"
// Cgetallbuglist dialog

class Cgetallbuglist : public CDialogEx
{
	DECLARE_DYNAMIC(Cgetallbuglist)

public:
	Cgetallbuglist(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cgetallbuglist();
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETALLBUGLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombBugTitle();
	virtual BOOL OnInitDialog();
	void GetAllBugLists();
private:
	AppApiService* m_apiService;
	CArray<BugTaskDetails, BugTaskDetails> m_BugListArray;
	CComboBox* BugTaskTitle;
};
