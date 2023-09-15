// Calluserinfo.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:Calluserinfo.cpp
	Description: . Implementation of Class Calluserinfo

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

	Author: Jayakrishnan P
	Last Modtime:  29/06/2022
	Last Revision:
---------------------------------------------------------------------------*/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "Calluserinfo.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// Calluserinfo dialog

IMPLEMENT_DYNAMIC(Calluserinfo, CDialogEx)

Calluserinfo::Calluserinfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ALLUSERINFO, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

Calluserinfo::~Calluserinfo()
{
}


void Calluserinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

/*---------------------------------------------------------------------------
	Function Name: Calluserinfo::OnInitDialog
	Return Value: BOOL
	Parameters:None.
	Remarks:  Initialized ComboBox when dialog is created.
---------------------------------------------------------------------------*/
BOOL Calluserinfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_allUserCombo = (CComboBox*)GetDlgItem(IDC_COMBO_AllUserInfo_slctName);

	try
	{
		//Get request.
		if (strSigninURL == _T("Api/Comm/GetAllActiveSiteUsersList"))
		{
			m_apiService->GetAllSiteUserInfo(m_infoArray);
			SetWindowText(_T("USER INFO"));
		}
		

		//Initializing combobox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			m_allUserCombo->AddString(m_infoArray.GetAt(i).Name);
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


BEGIN_MESSAGE_MAP(Calluserinfo, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_AllUserInfo_slctName, &Calluserinfo::OnCbnSelchangeComboAlluserinfoslctname)
END_MESSAGE_MAP()


// Calluserinfo message handlers

/*---------------------------------------------------------------------------
	Function Name: Calluserinfo::OnCbnSelchangeComboAlluserinfoslctname
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of ComboBox.
---------------------------------------------------------------------------*/
void Calluserinfo::OnCbnSelchangeComboAlluserinfoslctname()
{
	//Getting current selection of combobox.
	int allUserComboSeltItem = m_allUserCombo->GetCurSel();

	//Data is taken from JSONArray and fed to labels
	if (allUserComboSeltItem != CB_ERR) {
		
		UserInfo userInfo;
		userInfo = m_infoArray.GetAt(allUserComboSeltItem);

		//Feeding data to labels.
		GetDlgItem(IDC_STATIC_AllUserInfo_name)->SetWindowText(userInfo.CategryName);
		GetDlgItem(IDC_STATIC_AllUserInfo_emailId)->SetWindowText(userInfo.EmailID);
		GetDlgItem(IDC_STATIC_AllUserInfo_phoneNumber)->SetWindowText(userInfo.PhoneNo);
		GetDlgItem(IDC_STATIC_AllUserInfo_address)->SetWindowText(userInfo.Address);

	}
}




