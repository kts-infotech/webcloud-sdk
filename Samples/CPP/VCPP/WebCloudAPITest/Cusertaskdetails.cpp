// Cusertaskdetails.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:Cusertaskdetails.cpp
	Description: . Implementation of Class Cusertaskdetails

	Copyright (C) 2022 KTS Computers
	All rights reserved.

	Author: Tom,LAKSHMI V
	Last Modtime:  09/06/2022
	Last Revision:
---------------------------------------------------------------------------*/
#include "pch.h"
#include "WebCloudAPITest.h"
#include "Cusertaskdetails.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// Cusertaskdetails dialog

IMPLEMENT_DYNAMIC(Cusertaskdetails, CDialogEx)

Cusertaskdetails::Cusertaskdetails(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_USERTASKDETAILS, pParent)
{

}

Cusertaskdetails::~Cusertaskdetails()
{
}

void Cusertaskdetails::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cusertaskdetails, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cusertaskdetails::OnBnClickedGetInfoButton)
	ON_CBN_SELCHANGE(IDC_BUGTASKTITLE, &Cusertaskdetails::OnCbnSelchangeComboBugTaskTitle)
END_MESSAGE_MAP()


// Cusertaskdetails message handlers

/*---------------------------------------------------------------------------
	Function Name: Cusertaskdetails::OnBnClickedGetInfoButton
	Return Value:void
	Parameters:No parameters.
	Remarks:  ButtonClick Event
---------------------------------------------------------------------------*/
void Cusertaskdetails::OnBnClickedGetInfoButton()
{
	// TODO: Add your control notification handler code here
//#if TRUE
	CString Url;
	CString strUsername = CWebCloudAPITestApp::GetUsername();
	CString strAdmin;
	Url.Format(_T("Api/DT/GetWebCloudUserTaskDetails?strUserName=%s"), strUsername);
	m_BugTaskTitle = (CComboBox*)GetDlgItem(IDC_BUGTASKTITLE);
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
	
	m_apiService->UserTaskDetails(strUsername, UserResponse, m_BugListArray);

	for (int i = 0; i < m_BugListArray.GetSize(); i++) {

		m_BugTaskTitle->AddString(m_BugListArray.GetAt(i).BugTaskTitle);
	}
	JSONValue* jval = NetworkRequest::GetReqEx(Url);
	JSONObject JObj = jval->AsObject();
	
	UserBugTaskDetailsResponse UserResponse;
	WebCloudUserInfo UserInfo;
	JSONObject Usr = JObj[L"UserInfo"]->AsObject();
	
	if (!Usr[L"UserGroup"]->IsNull()) {
		UserResponse.UserInfo.UserGroup = Usr[L"UserGroup"]->AsString().c_str();
	}
	else {
		UserResponse.UserInfo.UserGroup = _T("No Groups Found");
	}
	
	if (strUsername == "admin")
	{
	strAdmin = _T("Admin User");

	}
	else
	{
		 strAdmin = _T("Normal User");
	}
	GetDlgItem(IDC_USERGROUP)->SetWindowText(UserResponse.UserInfo.UserGroup);
	GetDlgItem(IDC_USERTYPE)->SetWindowText(strAdmin);
}

/*---------------------------------------------------------------------------
	Function Name: Cusertaskdetails::OnCbnSelchangeComboBugTaskTitle
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of ComboBox.
---------------------------------------------------------------------------*/
void Cusertaskdetails::OnCbnSelchangeComboBugTaskTitle()
{
	//#if TRUE
		//// TODO: Add your control notification handler code here
	CString Url;
	CString strFormat;
	Url.Format(_T("Api/DT/GetWebCloudUserTaskDetails?strUserName=%s"), CWebCloudAPITestApp::GetUsername());
	CComboBox* BugTaskTitle = (CComboBox*)GetDlgItem(IDC_BUGTASKTITLE);
	int BugTracker = m_BugTaskTitle->GetCurSel();
	if (BugTracker != CB_ERR) {
		//UserBugTaskDetailsResponse UserResponse;
		BugTaskDetails bugtaskdetails;
		bugtaskdetails = m_BugListArray.GetAt(BugTracker);

		GetDlgItem(IDC_BUGSTATUS)->SetWindowText(bugtaskdetails.BugStatus);
		GetDlgItem(IDC_BUGDESC)->SetWindowText(bugtaskdetails.BugTaskDescription);
		

	}


}

/*---------------------------------------------------------------------------
	Function Name:Cusertaskdetails::OnInitDialog
	Return Value: Boolean
	Parameters:No parameters.
	Remarks:  Dialog-box initialization
---------------------------------------------------------------------------*/
BOOL Cusertaskdetails::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

