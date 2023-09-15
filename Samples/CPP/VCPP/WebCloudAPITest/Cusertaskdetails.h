/*---------------------------------------------------------------------------
	$Workfile: Cusertaskdetails.h $

	Description: Header file for Cusertaskdetails class.

	Copyright (C) 2022 KTS Computers
	All rights reserved.

   Author: Tom,LAKSHMI V
	Last $Modtime: 09/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once


// Cusertaskdetails dialog

class Cusertaskdetails : public CDialogEx
{
	DECLARE_DYNAMIC(Cusertaskdetails)

public:
	Cusertaskdetails(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cusertaskdetails();
	
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_USERTASKDETAILS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGetInfoButton();
	afx_msg void OnCbnSelchangeComboBugTaskTitle();
	virtual BOOL OnInitDialog();
private:
	AppApiService* m_apiService;
	UserBugTaskDetailsResponse UserResponse;
	CArray <BugTaskDetails, BugTaskDetails> m_BugListArray;
	CComboBox* m_BugTaskTitle;
	
};
