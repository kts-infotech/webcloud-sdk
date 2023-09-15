/*********************************************************************
   Workfile : CGetAllThread.cpp
   Description : Implementation of Class  CGetAllThread.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 30 June 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CGetAllThread.h"
#include "afxdialogex.h"


// CGetAllThread dialog

IMPLEMENT_DYNAMIC(CGetAllThread, CDialogEx)

CGetAllThread::CGetAllThread(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GETALLTHREAD, pParent)
{
	m_Jvalue = nullptr;
}

CGetAllThread::~CGetAllThread()
{
}

void CGetAllThread::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetAllThread, CDialogEx)
	ON_BN_CLICKED(IDCANCEL2, &CGetAllThread::OnBnClickedCancel2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CGetAllThread::OnCbnSelchangeCombo1)
	END_MESSAGE_MAP()


// CGetAllThread message handlers

void CGetAllThread::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
	
}
/***************************************************************
  Function Name : GetAllThreadAPI
  Return Type : void
  Remarks : Function to load all threads 
 **************************************************************/
void CGetAllThread::GetAllThreadAPI()
{
	// TODO: Add your implementation code here.
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO1);
	Combodrop_down->ResetContent();
	m_ForumService->GetAllThreads(m_InfoArray);
	for (int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		Combodrop_down->AddString(m_InfoArray[i].ThreadID);
	}

#else
	CString getAllThreads = _T("Api/Forum/GetAllThreads");
	try
	{
		m_Jvalue = NetworkRequest::GetReqEx(getAllThreads);
		std::wstring res = m_Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllThreads);
		JSONArray root = m_Jvalue->AsArray();
		CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO1);
		Combodrop_down->ResetContent();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strThread_ID(jobj[L"ThreadID"]->AsString().c_str());
			Combodrop_down->AddString(strThread_ID);
		}

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
#endif

}
/***************************************************************
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Overriding OnInitDialog() for initialization 
 **************************************************************/
BOOL CGetAllThread::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetAllThreadAPI();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/***************************************************************
  Function Name : OnCbnSelchangeCombo1
  Return Type : void
  Remarks : Function to get all details of selected thread 
 **************************************************************/
void CGetAllThread::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		CStringA Posted_Date= m_InfoArray[Combo_Sel].ftrDetails.PostedDate;
		ULONGLONG num = _atoi64(Posted_Date);
		COleDateTime date = GetDateFromTicks(num);
		CString strdate = date.Format(_T("%A, %B %d, %Y, %r "));
		GetDlgItem(IDC_STATIC_THREAD_NAME)->SetWindowText(m_InfoArray[Combo_Sel].ThreadName);
		GetDlgItem(IDC_STATIC_THREAD_1)->SetWindowText(_T("Bug Status : ") + m_InfoArray[Combo_Sel].ftrDetails.BugStatus);
		GetDlgItem(IDC_STATIC_THREAD_2)->SetWindowText(_T("Assigned Status : ") + m_InfoArray[Combo_Sel].ftrDetails.ThreadAssigned);
		GetDlgItem(IDC_STATIC_THREAD_3)->SetWindowText(_T("Posted On : ") + strdate);
		GetDlgItem(IDC_STATIC_THREAD_4)->SetWindowText(_T("Author ID : ") + m_InfoArray[Combo_Sel].ftrDetails.AuthorID);
		GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION)->SetWindowText(m_InfoArray[Combo_Sel].ThreadDesc);
		
	}

#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		JSONArray root = m_Jvalue->AsArray();
		std::wstring res = m_Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		JSONObject Jobj = root[Combo_Sel]->AsObject();
		JSONObject Jobj_Thread = Jobj[L"ftrDetails"]->AsObject();

		CString Bug_Status(Jobj_Thread[L"BugStatus"]->AsString().c_str());
		CString Thread_Assigned(Jobj_Thread[L"ThreadAssigned"]->AsString().c_str());

		CStringA Posted_Date(Jobj_Thread[L"PostedDate"]->AsString().c_str());
		ULONGLONG num = _atoi64(Posted_Date); 
		COleDateTime date=GetDateFromTicks(num);
		CString strdate = date.Format(_T("%A, %B %d, %Y, %r "));
		CString Author_ID(Jobj_Thread[L"AuthorID"]->AsString().c_str());
		CString Thread_Desc(Jobj[L"ThreadDesc"]->AsString().c_str());
		CString Thread_Name(Jobj[L"ThreadName"]->AsString().c_str());
		GetDlgItem(IDC_STATIC_THREAD_NAME)->SetWindowText(Thread_Name);
		GetDlgItem(IDC_STATIC_THREAD_1)->SetWindowText(_T("Bug Status : ") + Bug_Status);
		GetDlgItem(IDC_STATIC_THREAD_2)->SetWindowText(_T("Assigned Status : ")+ Thread_Assigned);
		GetDlgItem(IDC_STATIC_THREAD_3)->SetWindowText(_T("Posted On : ")+ strdate);
		GetDlgItem(IDC_STATIC_THREAD_4)->SetWindowText(_T("Author ID : ")+ Author_ID);

		GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION)->SetWindowText(Thread_Desc);

	}
#endif
}
/******************************************************************************
  Function Name : GetDateFromTicks
  Return Type : COleDateTime
  Parameters : date 
  Remarks : Function to get the date and time corresponding to  specific ticks 
 *****************************************************************************/
COleDateTime CGetAllThread::GetDateFromTicks(ULONGLONG date)
{
	COleDateTime epoch(100, 1, 1, 00, 00, 00);
	LONG missingDays = 365 * 99 + 24;
	CTimeSpan centSpan(missingDays, 0, 0, 0);
	CTimeSpan cSpan(date / 10000000);
	CTimeSpan tot = cSpan - centSpan;
	COleDateTimeSpan timSpn((LONG)tot.GetDays(), (int)tot.GetHours(), (int)tot.GetMinutes(), (int)tot.GetSeconds());
	COleDateTime resDate = epoch + timSpn;
	return resDate;
}