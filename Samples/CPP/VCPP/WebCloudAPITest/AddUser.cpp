/*------------------------------------------------------------------------
  Workfile : AddUser.cpp
   Description : Implementation of Class  AddUser.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chandradurga swaminathan
   Last Modified : 20 June 2022
-------------------------------------------------------------------------*/
// AddUser.cpp : implementation file


#include "pch.h"
#include "WebCloudAPITest.h"
#include "AddUser.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// AddUser dialog

IMPLEMENT_DYNAMIC(AddUser, CDialogEx)

AddUser::AddUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_USER, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;

}

AddUser::~AddUser()
{
}

void AddUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddUser, CDialogEx)
	
	ON_BN_CLICKED(ID_ADD_USER_SUMBITBUTTON, &AddUser::OnBnClickedAddUserSumbitbutton)
END_MESSAGE_MAP()


/*---------------------------------------------------------------------------
	Function Name: AddAdmin::OnBnClickedAddUserSumbitbutton
	Return Value: Void
	Remarks:   Function to insert new user details.
---------------------------------------------------------------------------*/

void AddUser::OnBnClickedAddUserSumbitbutton()
{
	// TODO: Add your control notification handler code here
	Adduser add;



	GetDlgItem(IDC_EDIT_ADD_ACC_USERNAME_TEXTBOX)->GetWindowText(add.Email);
	GetDlgItem(IDC_EDIT_ADD_ACC_PASSWORD_TEXTBOX)->GetWindowText(add.Password);

	GetDlgItem(IDC_EDIT_ADD_ACC_FIRSTNAME_TEXTBOX2)->GetWindowText(add.FirstName);

	GetDlgItem(IDC_EDIT_ADD_ACC_LASTNAME_TEXTBOX3)->GetWindowText(add.LastName);

	GetDlgItem(IDC_EDIT_ADD_ACC_PHONENO_TEXTBOX)->GetWindowText(add.Phoneno);
	GetDlgItem(IDC_EDIT_ADD_ACC_ADDRESS_TEXTBOX)->GetWindowText(add.Address);

	m_apiService->Adduserdetail(add);
}


