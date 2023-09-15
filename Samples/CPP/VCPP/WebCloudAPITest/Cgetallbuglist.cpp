// Cgetallbuglist.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:Cgetallbuglist.cpp
	Description: . Implementation of Class Cgetallbuglist

	Copyright (C) 2022 KTS Computers
	All rights reserved.

	Author: Tom,LAKSHMI V
	Last Modtime:  09/06/2022
	Last Revision:
---------------------------------------------------------------------------*/
#include "pch.h"
#include "WebCloudAPITest.h"
#include "Cgetallbuglist.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// Cgetallbuglist dialog

IMPLEMENT_DYNAMIC(Cgetallbuglist, CDialogEx)

Cgetallbuglist::Cgetallbuglist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GETALLBUGLIST, pParent)
{

}

Cgetallbuglist::~Cgetallbuglist()
{
}

void Cgetallbuglist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cgetallbuglist, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOBUGTITLE, &Cgetallbuglist::OnCbnSelchangeCombBugTitle)
END_MESSAGE_MAP()


// Cgetallbuglist message handlers

/*---------------------------------------------------------------------------
	Function Name: Cgetallbuglist::OnCbnSelchangeCombBugTitle
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of ComboBox.
---------------------------------------------------------------------------*/
void Cgetallbuglist::OnCbnSelchangeCombBugTitle()
{
	// TODO: Add your control notification handler code here

	int BugList = BugTaskTitle->GetCurSel();
	if (BugList != CB_ERR) {
		BugTaskDetails bugtaskdetails;
		bugtaskdetails = m_BugListArray.GetAt(BugList);
		GetDlgItem(IDC_BUGSTATUS)->SetWindowText(bugtaskdetails.BugStatus);
		GetDlgItem(IDC_BUGDESC)->SetWindowText(bugtaskdetails.BugTaskDescription);
	}

}

/*---------------------------------------------------------------------------
	Function Name: Cgetallbuglist::OnInitDialog
	Return Value: Boolean
	Parameters:No parameters.
	Remarks:  Dialog-box initialization
---------------------------------------------------------------------------*/
BOOL Cgetallbuglist::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetAllBugLists();//Function call
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/*---------------------------------------------------------------------------
	Function Name: Cgetallbuglist::GetAllBugLists
	Return Value: Void
	Parameters:
	Remarks:  Code for CCombobox,which is to be initialised when dialog is created and the function call is given in OnInitDialog().
---------------------------------------------------------------------------*/
void Cgetallbuglist::GetAllBugLists()
{
	CString GetBugList = _T("Api/DT/GetAllBugDetailsList");
	BugTaskTitle = (CComboBox*)GetDlgItem(IDC_COMBOBUGTITLE);
	try
	{
		m_apiService->AllbugLists(m_BugListArray);
		for (int i = 0; i < m_BugListArray.GetSize(); i++) {
		BugTaskTitle->AddString(m_BugListArray.GetAt(i).BugTaskTitle);
		}
		CWebCloudAPITestApp::SetRequestMSg(GetBugList);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}

}
