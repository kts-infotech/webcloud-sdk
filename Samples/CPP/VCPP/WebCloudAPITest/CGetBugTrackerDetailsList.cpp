// CGetBugTrackerDetailsList.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:CGetBugTrackerDetailsList.cpp
	Description: . Implementation of Class CGetBugTrackerDetailsList

	Copyright (C) 2022 KTS Computers
	All rights reserved.

	Author: Tom,LAKSHMI V
	Last Modtime:  09/06/2022
	Last Revision:
---------------------------------------------------------------------------*/
#include "pch.h"
#include "WebCloudAPITest.h"
#include "CGetBugTrackerDetailsList.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CGetBugTrackerDetailsList dialog

IMPLEMENT_DYNAMIC(CGetBugTrackerDetailsList, CDialogEx)

CGetBugTrackerDetailsList::CGetBugTrackerDetailsList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BugTrackerDetailsList, pParent)
{

}

CGetBugTrackerDetailsList::~CGetBugTrackerDetailsList()
{
}

void CGetBugTrackerDetailsList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(CGetBugTrackerDetailsList, CDialogEx)
	ON_CBN_SELCHANGE(IDC_BUGTASKTITLE, &CGetBugTrackerDetailsList::OnCbnSelchangeComboBugTaskTitle)
END_MESSAGE_MAP()


// CGetBugTrackerDetailsList message handlers
/*---------------------------------------------------------------------------
	Function Name: CGetBugTrackerDetailsList::OnCbnSelchangeComboBugTaskTitle
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of ComboBox.
---------------------------------------------------------------------------*/
void CGetBugTrackerDetailsList::OnCbnSelchangeComboBugTaskTitle()
{
	// TODO: Add your control notification handler code here
	int BugTracker = m_BugTrackerCombo->GetCurSel();
	if (BugTracker != CB_ERR) {

		BugTaskDetails bugtaskdetails;
		bugtaskdetails = m_infoArray.GetAt(BugTracker);
		GetDlgItem(IDC_BUGSTATUS)->SetWindowText(bugtaskdetails.BugStatus);
		GetDlgItem(IDC_TASKDESC)->SetWindowText(bugtaskdetails.BugTaskDescription);
	}
}
/*---------------------------------------------------------------------------
	Function Name:CGetBugTrackerDetailsList::OnInitDialog
	Return Value: Boolean
	Parameters:
	Remarks:  Dialog-box initialization
---------------------------------------------------------------------------*/
BOOL CGetBugTrackerDetailsList::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetBugTrackerList();//Function call
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/*---------------------------------------------------------------------------
	Function Name: GetBugTrackerDetailsList::GetBugTrackerList
	Return Value: Void
	Parameters:
	Remarks:  Code for CCombobox,which is to be initialised when dialog is created and the function call is given in OnInitDialog().
---------------------------------------------------------------------------*/
void CGetBugTrackerDetailsList::GetBugTrackerList()
{
	CString strBugTracker;
	CString strUsername = CWebCloudAPITestApp::GetUsername();
	strBugTracker.Format(_T("Api/DT/GetBugTrackerTaskDetailsList?strUserName=%s"), strUsername);
	m_BugTrackerCombo = (CComboBox*)GetDlgItem(IDC_BUGTASKTITLE);
	try
	{
		m_apiService->GetBugTrackerTaskDetailsList(strUsername, m_infoArray);

		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			m_BugTrackerCombo->AddString(m_infoArray.GetAt(i).BugTaskTitle);
		}

		CWebCloudAPITestApp::SetRequestMSg(strBugTracker);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}
}
