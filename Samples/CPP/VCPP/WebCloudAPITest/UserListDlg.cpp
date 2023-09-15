/*------------------------------------------------------------------------
  Workfile : UserListDlg.cpp
   Description : Implementation of Class  UserListDlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chandradurga swaminathan
   Last Modified : 20 June 2022

-------------------------------------------------------------------------*/
// UserListDlg.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "UserListDlg.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// UserListDlg dialog

IMPLEMENT_DYNAMIC(UserListDlg, CDialogEx)

UserListDlg::UserListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER_LIST, pParent)
{
	jval = nullptr;
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;


}

UserListDlg::~UserListDlg()
{
}

void UserListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}
/*---------------------------------------------------------------------------
	Function Name: UserListDlg::GetAllUserLIist
	Return Value: Void
	Remarks:   Function to get the all userinformation.
---------------------------------------------------------------------------*/

void UserListDlg::GetAllUserLIist()
{

}
BOOL UserListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_UL_COMBO);

	try
	{
		//Get request.
		if (strSigninURL == _T("api/Account/GetUserList"))
		{
			m_apiService->GetUserdetais(m_infoArray);
			SetWindowText(_T("ALL USER INFO"));
		}
	

		//Initializing combobox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			comboid->AddString(m_infoArray.GetAt(i).Email);
		}

		//Showing Resquest data and Response data.
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}

	return true;
}



BEGIN_MESSAGE_MAP(UserListDlg, CDialogEx)
	//ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &UserListDlg::OnLvnItemchangedList3)
	ON_CBN_SELCHANGE(IDC_UL_COMBO, &UserListDlg::OnCbnSelchangeUlCombo)
	//ON_BN_CLICKED(IDC_USERLIST_GROUP2, &UserListDlg::OnBnClickedUserlistGroup2)
END_MESSAGE_MAP()


// UserListDlg message handlers


void UserListDlg::OnNMThemeChangedScrollbar2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// This feature requires Windows XP or greater.
	// The symbol _WIN32_WINNT must be >= 0x0501.
	// TODO: Add your control notification handler code here
	*pResult = 0;
}





void UserListDlg::OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
/*---------------------------------------------------------------------------
	Function Name: UserListDlg::OnCbnSelchangeUlCombo
	Return Value: Void
	Remarks:   Function to display  user details for the selected 
---------------------------------------------------------------------------*/



void UserListDlg::OnCbnSelchangeUlCombo()
{
	//NetworkRequest::SetCloudUrl(strUrl);
	// TODO: Add your control notification handler code here
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_UL_COMBO);
	int list = comboid->GetCurSel();
	if (list != CB_ERR)
	{
		
		UserIn userDetail;
		userDetail = m_infoArray.GetAt(list);
		

		GetDlgItem(IDC_UL_NAME_LABEL)->SetWindowText(userDetail.FirstName);
		GetDlgItem(IDC_UL_LNAME_LABEL)->SetWindowText(userDetail.LastName);
		GetDlgItem(IDC_UL_PHONENO_LABEL)->SetWindowText(userDetail.Phoneno);
		GetDlgItem(IDC_UL_ADDRESS__LABEL)->SetWindowText(userDetail.Address);
		

	}

}


