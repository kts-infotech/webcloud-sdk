/*---------------------------------------------------------------------------
	$Workfile: CAllonlineuser.h $

	Description: Header file for CAllonlineuser class.

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

   Author: Jayakrishnan P
	Last $Modtime: 15/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
#include "NetworkRequest.h"
#include "Services/AppCommService.h"

// CAllonlineuser dialog

class CAllonlineuser : public CDialogEx
{
	DECLARE_DYNAMIC(CAllonlineuser)

public:
	CAllonlineuser(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAllonlineuser();
	CString strSigninURL;

private:
	CListBox* m_allOnlineUserList;
	AppApiService* m_apiService;
	CArray<UserInfo, UserInfo> m_infoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ALLONLINEUSERS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeListAllonlineusersonlineusers();
};
