// CAllonlineuser.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:CAllonlineuser.cpp
	Description: . Implementation of Class CAllonlineuser

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

	Author: Jayakrishnan P
	Last Modtime:  15/06/2022
	Last Revision:
---------------------------------------------------------------------------*/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAllonlineuser.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CAllonlineuser dialog

IMPLEMENT_DYNAMIC(CAllonlineuser, CDialogEx)

CAllonlineuser::CAllonlineuser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ALLONLINEUSERS, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CAllonlineuser::~CAllonlineuser()
{
}

/*---------------------------------------------------------------------------
	Function Name: CAllonlineuser::DoDataExchange
	Return Value: Void
	Parameters:Pointer to CDataExchange class.
	Remarks:  Initialized CListBox when dialog is created.
---------------------------------------------------------------------------*/
void CAllonlineuser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CAllonlineuser::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_allOnlineUserList = (CListBox*)GetDlgItem(IDC_LIST_AllOnlineUsers_onlineUsers);

	try
	{
		//Get request.
		JSONValue* jval = NULL;
		if (strSigninURL == _T("Api/Comm/GetAllOnlineUsersList"))
		{
			m_apiService->GetAllOnlineUserInfo(m_infoArray);
			SetWindowText(_T("ALL ONLINE USER INFO"));
		}
		else if (strSigninURL == _T("Api/Comm/GetAllOnlineSupportUsersList"))
		{
			m_apiService->GetAllOnlineSupportUserInfo(m_infoArray);
			SetWindowText(_T("ALL ONLINE SUPPORT USER INFO"));
		}
		else if (strSigninURL == _T("Api/Comm/GetAllOnlineNormalUsersList"))
		{
			m_apiService->GetAllOnlineNormalUserInfo(m_infoArray);
			SetWindowText(_T("ALL ONLINE NORMAL USER INFO"));
		}

		//Showing Resquest data.
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);
		
		//Initializing ListBox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			m_allOnlineUserList->AddString(m_infoArray.GetAt(i).Name);
		}
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}

	return true;
}


BEGIN_MESSAGE_MAP(CAllonlineuser, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_AllOnlineUsers_onlineUsers, &CAllonlineuser::OnLbnSelchangeListAllonlineusersonlineusers)
END_MESSAGE_MAP()


// CAllonlineuser message handlers


/*---------------------------------------------------------------------------
	Function Name: CAllonlineuser::OnLbnSelchangeListAllonlineusersonlineusers
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of CListBox.
---------------------------------------------------------------------------*/
void CAllonlineuser::OnLbnSelchangeListAllonlineusersonlineusers()
{
	//Getting current selection of ListBox.
	int allOnUserListSeltItem = m_allOnlineUserList->GetCurSel();

	//Data is taken from JSONArray and fed to labels
	if (allOnUserListSeltItem != LB_ERR) {
		
		UserInfo userInfo;
		userInfo = m_infoArray.GetAt(allOnUserListSeltItem);

		//Feeding data to labels.
		GetDlgItem(IDC_STATIC_AllOnlineUsers_connectionId)->SetWindowText(userInfo.CategryId);
		GetDlgItem(IDC_STATIC_AllOnlineUsers_userType)->SetWindowText(userInfo.UserType);
		GetDlgItem(IDC_STATIC_AllOnlineUsers_name)->SetWindowText(userInfo.Name);
		GetDlgItem(IDC_STATIC_AllOnlineUsers_phone)->SetWindowText(userInfo.PhoneNo);
		GetDlgItem(IDC_STATIC_AllOnlineUsers_address)->SetWindowText(userInfo.Address);
	}
}
