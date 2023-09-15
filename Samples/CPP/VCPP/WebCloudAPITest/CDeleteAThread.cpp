/*********************************************************************
   Workfile : CDeleteAThread.cpp
   Description : Implementation of  CDeleteAThread.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 5 August 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CDeleteAThread.h"
#include "afxdialogex.h"
#include "CGetAllThread.h"

// CDeleteAThread dialog

IMPLEMENT_DYNAMIC(CDeleteAThread, CDialogEx)

CDeleteAThread::CDeleteAThread(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETE_A_THREAD, pParent)
{
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
}

CDeleteAThread::~CDeleteAThread()
{
}

void CDeleteAThread::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteAThread, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteAThread::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_THREAD_ID, &CDeleteAThread::OnCbnSelchangeComboSelectThreadId)
	END_MESSAGE_MAP()


// CDeleteAThread message handlers

/***************************************************************
  Function Name : OnBnClickedButton1
  Return Type : void
  Remarks : Function to delete a selected thread 
 **************************************************************/
void CDeleteAThread::OnBnClickedButton1()
{
	try
	{
		// TODO: Add your control notification handler code here
		CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
		CString Thread_Name;
		Combodrop_down->GetWindowText(Thread_Name);
		if (Thread_Name == _T(""))
		{
			AfxMessageBox(_T("Select A Thread To Delete"));
		}
		else
		{
		#if TRUE
			m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
			int Combo_Sel = Combodrop_down->GetCurSel();
			CString InfoArray;
			m_ForumService->DeleteThread(m_Thread_Id[Combo_Sel], InfoArray);
		#else
			int Combo_Sel = Combodrop_down->GetCurSel();
			CString deleteAThread;
			deleteAThread.Format(_T("Api/Forum/DeleteThread?strThreadID=%s"), m_Thread_Id[Combo_Sel]);
			JSONValue* Jvalue = NetworkRequest::GetReqEx(deleteAThread);
			std::wstring res = Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(deleteAThread);
			AfxMessageBox(cstrRes);
		#endif
		}
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
		AfxMessageBox(_T("Unable to Delete the Thread"));
	}

}
/***************************************************************
  Function Name : DeleteAThreadAPI
  Return Type : void
  Remarks : Function to load all threads 
 **************************************************************/
void CDeleteAThread::DeleteAThreadAPI()
{
	// TODO: Add your implementation code here.
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
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
		CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strThreadID(jobj[L"ThreadID"]->AsString().c_str());
			m_Thread_Id.Add(strThreadID);
			Combodrop_down->AddString(strThreadID);
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
BOOL CDeleteAThread::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	DeleteAThreadAPI();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
	
}
/***************************************************************
  Function Name : OnCbnSelchangeComboSelectThreadId
  Return Type : void
  Remarks : Function to load all details of a thread 
 **************************************************************/
void CDeleteAThread::OnCbnSelchangeComboSelectThreadId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		CStringA Posted_Date = m_InfoArray[Combo_Sel].ftrDetails.PostedDate;
		ULONGLONG num = _atoi64(Posted_Date);
		COleDateTime date = CGetAllThread::GetDateFromTicks(num);
		CString strdate = date.Format(_T("%A, %B %d, %Y, %r "));
		GetDlgItem(IDC_STATIC_THREAD_NAME)->SetWindowText(m_InfoArray[Combo_Sel].ThreadName);
		GetDlgItem(IDC_STATIC_T1)->SetWindowText(_T("Bug Status : ") + m_InfoArray[Combo_Sel].ftrDetails.BugStatus);
		GetDlgItem(IDC_STATIC_T2)->SetWindowText(_T("Assigned Status : ") + m_InfoArray[Combo_Sel].ftrDetails.ThreadAssigned);
		GetDlgItem(IDC_STATIC_T3)->SetWindowText(_T("Posted On : ") + strdate);
		GetDlgItem(IDC_STATIC_T4)->SetWindowText(_T("Author ID : ") + m_InfoArray[Combo_Sel].ftrDetails.AuthorID);
		GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION)->SetWindowText(m_InfoArray[Combo_Sel].ThreadDesc);
	}
#else
	
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
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
		COleDateTime date = CGetAllThread::GetDateFromTicks(num);
		CString strdate = date.Format(_T("%A, %B %d, %Y, %r "));
		CString Author_ID(Jobj_Thread[L"AuthorID"]->AsString().c_str());
		CString Thread_Desc(Jobj[L"ThreadDesc"]->AsString().c_str()); 
	    CString Thread_Name(Jobj[L"ThreadName"]->AsString().c_str());
		GetDlgItem(IDC_STATIC_THREAD_NAME)->SetWindowText(Thread_Name);
		GetDlgItem(IDC_STATIC_T1)->SetWindowText(_T("Bug Status : ") + Bug_Status);
		GetDlgItem(IDC_STATIC_T2)->SetWindowText(_T("Assigned Status : ") + Thread_Assigned);
		GetDlgItem(IDC_STATIC_T3)->SetWindowText(_T("Posted On : ") + strdate);
		GetDlgItem(IDC_STATIC_T4)->SetWindowText(_T("Author ID : ") + Author_ID);
		GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION)->SetWindowText(Thread_Desc);
	}
#endif
}



