/*********************************************************************
   Workfile : CAddAComment.cpp
   Description : Implementation of Class  CAddAComment.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddAComment.h"
#include "afxdialogex.h"



// CAddAComment dialog

IMPLEMENT_DYNAMIC(CAddAComment, CDialogEx)

CAddAComment::CAddAComment(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_A_COMMENT, pParent)
{
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
}

CAddAComment::~CAddAComment()
{
}

void CAddAComment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddAComment, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD_COMMENT, &CAddAComment::OnBnClickedButtonAddComment)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_FORUM_ID, &CAddAComment::OnCbnSelchangeComboSelectForumId)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_TOPIC_ID, &CAddAComment::OnCbnSelchangeComboSelectTopicId)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_THREAD_ID, &CAddAComment::OnCbnSelchangeComboSelectThreadId)
END_MESSAGE_MAP()


/***************************************************************
  Function Name : OnBnClickedButtonAddComment
  Return Type : void
  Remarks : Comment is added and posted 
 **************************************************************/
void CAddAComment::OnBnClickedButtonAddComment()
{
	// TODO: Add your control notification handler code here
	
#if TRUE
	CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	int Combo_Sel_Thread = Combo->GetCurSel();
	CommentsInfo info;
	info.MsgID = _T("");
	CString ThreadID;
	ThreadID.Format(_T("%d"), int(Combo->GetItemData(Combo_Sel_Thread)));
	info.ThreadID = ThreadID;
	CString Message;
	GetDlgItem(IDC_EDIT_ADD_COMMENTS)->GetWindowText(Message);
	info.Message = Message;
	info.Author = CWebCloudAPITestApp::GetUsername();
	info.User = CWebCloudAPITestApp::GetUsername();
	
	info.Posteddate = GetTicksNow();
	CString DeletedBy = CWebCloudAPITestApp::GetUsername();
	info.DeletedBy = DeletedBy;
	info.ErrorDesc= _T("");
	m_ForumService->AddComments(info);
#else	
	CString url = _T("Api/Forum/AddComments");
	CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	int Combo_Sel_Thread = Combo->GetCount();

	CString MsgID = _T("");
	CString ThreadID;
	ThreadID.Format(_T("%d"), m_Thread_Id);
	CString Message;
	GetDlgItem(IDC_EDIT_ADD_COMMENTS)->GetWindowText(Message);
	CString Author = CWebCloudAPITestApp::GetUsername();
	CString User = CWebCloudAPITestApp::GetUsername();
	CString PostedDate = GetTicksNow();
	CString DeletedBy = CWebCloudAPITestApp::GetUsername();
	CString ErrorDesc = _T("");
	CString data;
	data.Format(_T("{ \"MsgID\":\"%s\", \
					   \"ThreadID\" : \"%s\", \
						\"Message\" : \"%s\", \
						 \"Author\" : \"%s\", \
						  \"User\" : \"%s\", \
						   \"PostedDate\" : \"%s\", \
						    \"Status\" : false, \
						     \"DeletedBy\" :\"%s\",\
                              \"Success\" : false, \
						       \"ErrorDesc\" : \"%s\"}"),
		MsgID, ThreadID, Message, Author, User, PostedDate,DeletedBy,ErrorDesc);

	try
	{
		CWebCloudAPITestApp::SetRequestMSg(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
#endif
}
/***************************************************************
  Function Name : AddACommentAPI
  Return Type : void
  Remarks : Loading all forums into combobox for selection 
 **************************************************************/

void CAddAComment::AddACommentAPI()
{
	// TODO: Add your implementation code here.
#if TRUE
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_FORUM_ID);
	Combodrop_down->ResetContent();
	CArray<ItemInfo>InfoArray;
	m_ForumService->GetAllForumIdWithNames(InfoArray);
	for (int i = 0; i < InfoArray.GetSize(); i++)
	{
		Combodrop_down->AddString(InfoArray[i].Text);
		Combodrop_down->SetItemData(i, (int)InfoArray[i].Value);
	}
#else
	CString getAllForumId = _T("Api/Forum/GetAllForumIdWithNames");
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllForumId);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllForumId);
		CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_FORUM_ID);
		Combodrop_down->ResetContent();
		JSONArray root = Jvalue->AsArray();
		m_Forum_Id.RemoveAll();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strForumName = jobj[L"Text"]->AsString().c_str();
			Combodrop_down->AddString(strForumName);
			m_Forum_Id.Add((int)jobj[L"Value"]->AsNumber());

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
BOOL CAddAComment::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	AddACommentAPI();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************************************
  Function Name : OnCbnSelchangeComboSelectForumId
  Return Type : void
  Remarks : Loading all topics in to combo box for selection 
 **************************************************************/
void CAddAComment::OnCbnSelchangeComboSelectForumId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_FORUM_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		CArray<ItemInfo>InfoArray;
		CString strForumId;
		strForumId.Format(_T("%u"), (Combodrop_down->GetItemData(Combo_Sel)));
		m_ForumService->GetAllTopicsWithForumID(strForumId, InfoArray);
		CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
		int Combo_Sel1 = Combodrop->GetCurSel();
		Combodrop->ResetContent();
		CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
		Combo->ResetContent();
		for (unsigned int i = 0; i < InfoArray.GetSize(); i++)
		{
			Combodrop->AddString(InfoArray[i].Text);
			Combodrop->SetItemData(i, (int)InfoArray[i].Value);
		}
	}
#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_FORUM_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		try
		{
			CString getAllForumId;
			getAllForumId.Format(_T("Api/Forum/GetAllTopicsWithForumID?iForumId=%d"), m_Forum_Id[Combo_Sel]);
			JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllForumId);
			JSONArray root = Jvalue->AsArray();
			CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
			int Combo_Sel1 = Combodrop->GetCurSel();
			Combodrop->ResetContent();
			CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
			Combo->ResetContent();
			m_Topic_Id.RemoveAll();
			for (unsigned int i = 0; i < root.size(); i++)
			{
				JSONObject Jobj = root[i]->AsObject();
				CString strTopicID_data(Jobj[L"Text"]->AsString().c_str());

				m_Topic_Id.Add((int)Jobj[L"Value"]->AsNumber());
				Combodrop->AddString(strTopicID_data);

			}

			std::wstring res = Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllForumId);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}
	}
#endif
}

/***************************************************************
  Function Name : OnCbnSelchangeComboSelectTopicId
  Return Type : void
  Remarks : Loading all threads in to combo box for selection 
 **************************************************************/
void CAddAComment::OnCbnSelchangeComboSelectTopicId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		CString strTopicID;
		strTopicID.Format(_T("%u"), (Combodrop_down->GetItemData(Combo_Sel)));
		m_infoArray.RemoveAll();
		m_ForumService->GetAllThreadsWithTopicID(strTopicID, m_infoArray);
		CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
		Combodrop->ResetContent();
		for (unsigned int i = 0; i < m_infoArray.GetSize(); i++)
		{
			Combodrop->AddString(m_infoArray[i].Text);
			Combodrop->SetItemData(i, (int)m_infoArray[i].Value);
		}
	}
#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		try
		{
			CString getAllThreads;
			getAllThreads.Format(_T("Api/Forum/GetAllThreadsWithTopicID?strTopicID=%d"), m_Topic_Id[Combo_Sel]);
			m_Jvalue = NetworkRequest::GetReqEx(getAllThreads);
			JSONArray root = m_Jvalue->AsArray();
			CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
			Combodrop->ResetContent();
			
			for (unsigned int i = 0; i < root.size(); i++)
			{
				JSONObject Jobj = root[i]->AsObject();
				CString strThreadID(Jobj[L"Text"]->AsString().c_str());
				Combodrop->AddString(strThreadID);
				
			}

			std::wstring res = m_Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllThreads);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}

	}
#endif
}
/***************************************************************
  Function Name : GetTicksNow
  Return Type : CString
  Remarks :  Returns the current date and time  in tics
 **************************************************************/
CString CAddAComment::GetTicksNow()
{
	COleDateTime epoch(100, 1, 1, 00, 00, 00);
	COleDateTime currTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = currTime - epoch;
	CTimeSpan cSpan(span.GetDays(), span.GetHours(), span.GetMinutes(), span.GetSeconds());
	ULONGLONG diff = cSpan.GetTotalSeconds();
	LONG missingDays = 365 * 99 + 24;
	CTimeSpan centSpan(missingDays, 0, 0, 0);
	ULONGLONG centSeconds = centSpan.GetTotalSeconds();// *1000000000;//
	ULONGLONG totSec = (diff + centSeconds) * 10000000;
	CString strDiff;
	strDiff.Format(_T("%I64u"), totSec);
	return strDiff;
}
/***************************************************************
  Function Name : OnCbnSelchangeComboSelectThreadId
  Return Type : void
  Remarks :  
 **************************************************************/
void CAddAComment::OnCbnSelchangeComboSelectThreadId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	
#else
	CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	int isel= Combodrop->GetCurSel();
		if (isel != CB_ERR)
	{
			JSONArray root = m_Jvalue->AsArray();
			JSONObject Jobj = root[isel]->AsObject();
			m_Thread_Id = ((int)Jobj[L"Value"]->AsNumber());
	}
#endif
}
