/*------------------------------------------------------------------------
  Workfile : InviteUser.cpp
   Description : Implementation of Class  InviteUser.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chandradurga swaminathan
   Last Modified : 20 June 2022
-------------------------------------------------------------------------*/
// InviteUser.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "afxdialogex.h"
#include "InviteUser.h"

//Api/Account/InviteUser
// InviteUser dialog
//PostAsync

IMPLEMENT_DYNAMIC(InviteUser, CDialogEx)

InviteUser::InviteUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INVITE_USER, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;

}

InviteUser::~InviteUser()
{
}

void InviteUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InviteUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &InviteUser::OnBnClickedOk)
END_MESSAGE_MAP()


// InviteUser message handlers

/*---------------------------------------------------------------------------
	Function Name: InviteUser::OnBnClickedOk
	Return Value: Void
	Remarks: to send the user invitation to the corresponding email with message.
---------------------------------------------------------------------------*/

void InviteUser::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	NetworkRequest::SetCloudUrl(strUrl);
	//Api/Account/InviteUser
	//IDC_EDIT2
		//IDC_EDIT7
     InviteUserapi invite;
	
	GetDlgItem(IDC_EDIT7)->GetWindowText(invite.UserMessage);
	GetDlgItem(IDC_EDIT2)->GetWindowText(invite.UserEmail);
	m_apiService->Inviteusersercive(invite);
	/*data.Format(_T("{ \"usercategory\":\"1000\",\"UserEmail\":\"%s\",\"UserMessage\" : \"%s\"}"), UserEmail, UserMessage);
	CString strSigninURL = _T("Api/Account/InviteUser");

	try
	{
		CWebCloudAPITestApp::SetRequestMSg(data);
		JSONValue* jval = NetworkRequest::PostReq(strSigninURL, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);

	}*/
}


