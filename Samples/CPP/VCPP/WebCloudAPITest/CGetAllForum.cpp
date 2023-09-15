/*********************************************************************
   Workfile : CGetAllForum.cpp
   Description : Implementation of Class  CGetAllForum.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 30 June 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CGetAllForum.h"
#include "afxdialogex.h"




// CGetAllForum dialog

IMPLEMENT_DYNAMIC(CGetAllForum, CDialogEx)

CGetAllForum::CGetAllForum(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GET_ALL_FORUM, pParent)
{
	// TODO: add construction code herem_ComBox
	m_Jvalue = nullptr;
	
}

CGetAllForum::~CGetAllForum()
{
}

void CGetAllForum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetAllForum, CDialogEx)
	ON_BN_CLICKED(IDCLOSE, &CGetAllForum::OnBnClickedClose)
	ON_CBN_SELCHANGE(IDC_COMBO_FORUM_ID, &CGetAllForum::OnCbnSelchangeComboForumId)
END_MESSAGE_MAP()


// CGetAllForum message handlers

void CGetAllForum::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
/***************************************************************
  Function Name : GetAllFormsAPI
  Return Type : void
  Remarks : Function to load all forums 
 **************************************************************/
void CGetAllForum::GetAllFormsAPI()
{
	// TODO: Add your implementation code here.
	
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_ID);
	Combodrop_down->ResetContent();
	m_ForumService->GetAllForums(m_InfoArray);
	for (int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		Combodrop_down->AddString(m_InfoArray[i].FormID);
	}

#else
	CString getAllForums = _T("Api/Forum/GetAllForums");
	try
	{
	    m_Jvalue = NetworkRequest::GetReqEx(getAllForums);
		std::wstring res = m_Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllForums);
		JSONArray root = m_Jvalue->AsArray();
		CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_ID);
		Combodrop_down->ResetContent();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj =root[i]->AsObject();
			CString strFormID(Jobj[L"FormID"]->AsString().c_str());
			Combodrop_down->AddString(strFormID);
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
BOOL CGetAllForum::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetAllFormsAPI();

	// TODO:  Add extra initialization here
   //  GetAllFormsAPI();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/***************************************************************
  Function Name : OnCbnSelchangeComboForumId
  Return Type : void
  Remarks : Function to get all details of a forum 
 **************************************************************/
void CGetAllForum::OnCbnSelchangeComboForumId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		GetDlgItem(IDC_STATIC_NAME)->SetWindowText(m_InfoArray[Combo_Sel].FormName);
		GetDlgItem(IDC_STATIC_DESCRIPTION)->SetWindowText(m_InfoArray[Combo_Sel].FormDesc);
	}

#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_ID);
	int Combo_Sel= Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		JSONArray root = m_Jvalue->AsArray();
		std::wstring res = m_Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		JSONObject Jobj = root[Combo_Sel]->AsObject();
		CString strForum_Name(Jobj[L"FormName"]->AsString().c_str());
		CString strForum_Desc(Jobj[L"FormDesc"]->AsString().c_str());
		GetDlgItem(IDC_STATIC_NAME)->SetWindowText(strForum_Name);
		GetDlgItem(IDC_STATIC_DESCRIPTION)->SetWindowText(strForum_Desc);
		
	}
#endif
}
