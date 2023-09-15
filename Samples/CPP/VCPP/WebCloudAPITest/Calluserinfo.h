/*---------------------------------------------------------------------------
	$Workfile: Calluserinfo.h $

	Description: Header file for Calluserinfo class.

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

    Author: Jayakrishnan P
	Last $Modtime: 29/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
#include "NetworkRequest.h"
#include "Services/AppCommService.h"

// Calluserinfo dialog

class Calluserinfo : public CDialogEx
{
	DECLARE_DYNAMIC(Calluserinfo)

public:
	Calluserinfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Calluserinfo();

	CString strSigninURL;

private:
	AppApiService* m_apiService;
	CArray<UserInfo, UserInfo> m_infoArray;
	CComboBox* m_allUserCombo;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ALLUSERINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV support
	virtual BOOL Calluserinfo::OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboAlluserinfoslctname();
};