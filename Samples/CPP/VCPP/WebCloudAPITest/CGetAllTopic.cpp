/*********************************************************************
   Workfile : CGetAllTopic.cpp
   Description : Implementation of Class  CGetAllTopic.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 30 June 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CGetAllTopic.h"
#include "afxdialogex.h"



// CGetAllTopic dialog

IMPLEMENT_DYNAMIC(CGetAllTopic, CDialogEx)

CGetAllTopic::CGetAllTopic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GET_ALL_TOPIC, pParent)
{
	
	m_Jvalue = nullptr;
}

CGetAllTopic::~CGetAllTopic()
{
}

void CGetAllTopic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetAllTopic, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGetAllTopic::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_TOPIC_ID, &CGetAllTopic::OnCbnSelchangeComboSelectTopicId)
END_MESSAGE_MAP()


// CGetAllTopic message handlers

void CGetAllTopic::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
/***************************************************************
  Function Name : GetAllTopicAPI
  Return Type : void
  Remarks : Function to get all topics 
 **************************************************************/
void CGetAllTopic::GetAllTopicAPI()
{
	// TODO: Add your implementation code here.
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	Combodrop_down->ResetContent();
	m_ForumService->GetAllTopics(m_InfoArray);
	for (int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		Combodrop_down->AddString(m_InfoArray[i].TopicID);
	}

#else
	CString getAllTopics = _T("Api/Forum/GetAllTopics");
	try
	{
		m_Jvalue = NetworkRequest::GetReqEx(getAllTopics);
		std::wstring res = m_Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllTopics);
		JSONArray root = m_Jvalue->AsArray();
		CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
		Combodrop_down->ResetContent();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strTopicID(jobj[L"TopicID"]->AsString().c_str());
			Combodrop_down->AddString(strTopicID);
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
BOOL CGetAllTopic::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetAllTopicAPI();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/***************************************************************
  Function Name : OnCbnSelchangeComboSelectTopicId
  Return Type : void
  Remarks : Function to get all details of a topic 
 **************************************************************/
void CGetAllTopic::OnCbnSelchangeComboSelectTopicId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		GetDlgItem(IDC_STATIC_NAME_OF_SELECTED_TOPIC)->SetWindowText(m_InfoArray[Combo_Sel].TopicName);
		GetDlgItem(IDC_STATIC_DESCRIPTION_OF_SELECTED_TOPIC)->SetWindowText(m_InfoArray[Combo_Sel].TopicDesc);
	}

#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		JSONArray root = m_Jvalue->AsArray();
		std::wstring res = m_Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		JSONObject Jobj = root[Combo_Sel]->AsObject();
		CString strTopic_Name(Jobj[L"TopicName"]->AsString().c_str());
		CString strTopic_Desc(Jobj[L"TopicDesc"]->AsString().c_str());
		GetDlgItem(IDC_STATIC_NAME_OF_SELECTED_TOPIC)->SetWindowText(strTopic_Name);
		GetDlgItem(IDC_STATIC_DESCRIPTION_OF_SELECTED_TOPIC)->SetWindowText(strTopic_Desc);

	}
#endif
}
