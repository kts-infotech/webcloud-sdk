/*------------------------------------------------------------------------
  Workfile : AddAdmin.cpp
   Description : Implementation of Class  AddAdmin.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chandradurga swaminathan
   Last Modified : 20 June 2022
-------------------------------------------------------------------------*/
// AddAdmin.cpp : implementation file



#include "pch.h"
#include "WebCloudAPITest.h"
#include "afxdialogex.h"
#include "AddAdmin.h"
#include "NetworkRequest.h"


// AddAdmin dialog

IMPLEMENT_DYNAMIC(AddAdmin, CDialogEx)

AddAdmin::AddAdmin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDADMIN, pParent)
{
	//jval = nullptr;
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;

}

AddAdmin::~AddAdmin()
{
}

void AddAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddAdmin, CDialogEx)
	ON_BN_CLICKED(ID_ADD_ADMIN_ACC_SUMBIT_ADMIN, &AddAdmin::OnBnClickedAddAdminAccSumbitAdmin)
END_MESSAGE_MAP()


// AddAdmin message handlers
/*---------------------------------------------------------------------------
	Function Name: AddAdmin::OnBnClickedAddAdminAccSumbitAdmin
	Return Value: Void
	Remarks:   Function to insert new admin details.
---------------------------------------------------------------------------*/

void AddAdmin::OnBnClickedAddAdminAccSumbitAdmin()
{
	// TODO: Add your control notification handler code here
	
	Addadmin add;

	//CString url = _T("api/Account/AddAdmin");

	GetDlgItem(IDC_EDIT_ADMIN_ACC_USERNAME_TEXTBOX)->GetWindowText(add.Email);
	GetDlgItem(IDC_EDIT_ADMIN_ACC_PASSWORD_TEXTBOX)->GetWindowText(add.Password);

	GetDlgItem(IDC_EDIT_ADMIN_ACC_FIRSTNAME_TEXTBOX2)->GetWindowText(add.FirstName);

	GetDlgItem(IDC_EDIT_ADMIN_ACC_LASTNAME_TEXTBOX3)->GetWindowText(add.LastName);

	GetDlgItem(IDC_EDIT_ADMIN_ACC_PHONENO_TEXTBOX)->GetWindowText(add.Phoneno);
	GetDlgItem(IDC_EDIT_ADMIN_ACC_ADDRESS_TEXTBOX)->GetWindowText(add.Address);
	m_apiService->Addadmindetail(add);

}



