// CDtgetassigntasklist.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:CDtgetassigntasklist.cpp
	Description: . Implementation of Class CDtgetassigntasklist

	Copyright (C) 2022 KTS Computers
	All rights reserved.

	Author: Tom,LAKSHMI V
	Last Modtime:  09/06/2022
	Last Revision:
---------------------------------------------------------------------------*/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CDtgetassigntasklist.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CDtgetassigntasklist dialog

IMPLEMENT_DYNAMIC(CDtgetassigntasklist, CDialogEx)

CDtgetassigntasklist::CDtgetassigntasklist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DTGETASSIGTASKLIST, pParent)
{

}

CDtgetassigntasklist::~CDtgetassigntasklist()
{
}

/*---------------------------------------------------------------------------
	Function Name: CDtgetassigntasklist::DoDataExchange
	Return Value: Void
	Parameters:Pointer to CDataExchange class.
	Remarks:  Initialized CCombobox when dialog is created.
---------------------------------------------------------------------------*/
void CDtgetassigntasklist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	CString strUrl2;
	//int TaskID;
	CString strUsername= CWebCloudAPITestApp::GetUsername();
	strUrl2.Format(_T("Api/DT/GetAssignedBugList?strUserName=%s"), strUsername);
	//NetworkRequest::SetCloudUrl(strUrl);
	m_TaskID = (CComboBox*)GetDlgItem(IDC_COMBOTASKID);
	//int TaskID=0;
	try
	{
		//Get request.
		
			m_apiService->AssignedTaskList(strUsername,m_TaskDetailsList);
		
		
			CString strTaskID;
			for (int i = 0; i < m_TaskDetailsList.GetSize(); i++) {
				TaskDetails DetailsList;

				DetailsList = m_TaskDetailsList[i];
				CString strTaskID;
				strTaskID.Format(_T("%d"), DetailsList.TaskID);
				m_TaskID->AddString(strTaskID);

			}

			
			CWebCloudAPITestApp::SetRequestMSg(strUrl2);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}
	
}



BEGIN_MESSAGE_MAP(CDtgetassigntasklist, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOTASKID, &CDtgetassigntasklist::OnCbnSelchangeComboTaskID)
END_MESSAGE_MAP()


// CDtgetassigntasklist message handlers

/*---------------------------------------------------------------------------
	Function Name: CDtgetassigntasklist::OnCbnSelchangeComboTaskID
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of ComboBox.
---------------------------------------------------------------------------*/
void CDtgetassigntasklist::OnCbnSelchangeComboTaskID()
{
	// TODO: Add your control notification handler code here
	
	int assignedtasklistItem = m_TaskID->GetCurSel();
	if (assignedtasklistItem != CB_ERR) {
		
		

			TaskDetails taskdetails;
			taskdetails = m_TaskDetailsList.GetAt(assignedtasklistItem);
				
			GetDlgItem(IDC_TASKTITLE)->SetWindowText(taskdetails.TaskTitle);
			GetDlgItem(IDC_TASKDESC)->SetWindowText(taskdetails.TaskDescription);
		
		
	}
}

//void CDtgetassigntasklist::getassignedtasklist()
//{
//}

