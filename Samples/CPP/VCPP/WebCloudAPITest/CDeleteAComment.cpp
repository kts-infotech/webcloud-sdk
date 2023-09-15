/*********************************************************************
   Workfile : CDeleteAComment.cpp
   Description : Implementation of  CDeleteAComment.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 1 July 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CDeleteAComment.h"
#include "afxdialogex.h"



// CDeleteAComment dialog

IMPLEMENT_DYNAMIC(CDeleteAComment, CDialogEx)

CDeleteAComment::CDeleteAComment(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETE_A_COMMENT, pParent)
{
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
}

CDeleteAComment::~CDeleteAComment()
{
}

void CDeleteAComment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SELECT_MESSAGE_TO_DELETE, m_listctrl);
}


BEGIN_MESSAGE_MAP(CDeleteAComment, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_UNSELECT_ALL, &CDeleteAComment::OnBnClickedButtonUnselectAll)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_ALL, &CDeleteAComment::OnBnClickedButtonSelectAll)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_SELECTED, &CDeleteAComment::OnBnClickedButtonDeleteSelected)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_FORUM_ID, &CDeleteAComment::OnCbnSelchangeComboSelectForumId)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_TOPIC_ID, &CDeleteAComment::OnCbnSelchangeComboSelectTopicId)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_THREAD_ID, &CDeleteAComment::OnCbnSelchangeComboSelectThreadId)
END_MESSAGE_MAP()


// CDeleteAComment message handlers

/***************************************************************
  Function Name : OnBnClickedButtonUnselectAll
  Return Type : void
  Remarks : Function to select all comments from list control 
 **************************************************************/
void CDeleteAComment::OnBnClickedButtonUnselectAll()
{
	// TODO: Add your control notification handler code here
	int nCount = m_listctrl.GetItemCount();

	for (int i = 0; i < nCount; i++)
	{
		m_listctrl.SetCheck(i, FALSE);

	}
}
/***************************************************************
  Function Name : OnBnClickedButtonSelectAll
  Return Type : void
  Remarks :  Function to unselect all comments from list control 
 **************************************************************/
void CDeleteAComment::OnBnClickedButtonSelectAll()
{
	// TODO: Add your control notification handler code here
	int nCount = m_listctrl.GetItemCount();
	
	for (int i = 0; i < nCount; i++)
	{
		m_listctrl.SetCheck(i, TRUE);
		
	}
	
}
/***************************************************************
  Function Name : OnBnClickedButtonDeleteSelected
  Return Type : void
  Remarks : Function to delete a selected message 
 **************************************************************/
void CDeleteAComment::OnBnClickedButtonDeleteSelected()
{
	// TODO: Add your control notification handler code here
	CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	CString Thread_Name;
	Combodrop->GetWindowText(Thread_Name);
	if (Thread_Name==_T(""))
	{
		AfxMessageBox(_T("Please Select A Message To Delete"));
	}
	else if(Thread_Name==_T("No data available"))
	{
		AfxMessageBox(_T("No Message To Delete"));
	}
	else 
	{
		CArray<CString>MsgId;
		int nCount = m_listctrl.GetItemCount();
		for (int i = 0; i < nCount; i++)
		{
			if (m_listctrl.GetCheck(i))
			{
				MsgId.Add(m_listctrl.GetItemText(i, 1));

			}

		}
#if TRUE
		CArray<CString>InfoArray;
		m_ForumService->DeleteComments(MsgId, InfoArray);
#else
		CString DeleteAComment = _T("Api/Forum/DeleteComments");
		JSONArray arr;
		for (int i = 0; i < MsgId.GetSize(); i++)
		{
			arr.push_back(new JSONValue(std::wstring(MsgId[i])));
		}
		JSONValue* val = new JSONValue(arr);
		std::wstring res = val->Stringify(true);
		CString dataUpdate = CString(res.c_str());
		CWebCloudAPITestApp::SetRequestMSg(dataUpdate);

		try
		{
			JSONValue* jval = NetworkRequest::PostReq(DeleteAComment, dataUpdate);
			std::wstring res = jval->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(DeleteAComment);
			AfxMessageBox(cstrRes);

		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			AfxMessageBox(errorStr);
		}
#endif
	}
}
/***************************************************************
  Function Name : DeleteACommentAPI
  Return Type : void
  Remarks : Function to load all forums  
 **************************************************************/
void CDeleteAComment::DeleteACommentAPI()
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
		Combodrop_down->SetItemData(i,(int)InfoArray[i].Value);
	}

#else
	CString getAllForums = _T("Api/Forum/GetAllForumIdWithNames");
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(getAllForums);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllForums);
		CComboBox* Combo_drop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_FORUM_ID);
		JSONArray root = jval->AsArray();
		Combo_drop->ResetContent();
		m_Forum_Id.RemoveAll();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strForumName(jobj[L"Text"]->AsString().c_str());
			m_Forum_Id.Add((int)jobj[L"Value"]->AsNumber());
			Combo_drop->AddString(strForumName);
		}

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
#endif
}
/******************************************************************
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Function to initialize the list control header values 
 *****************************************************************/
BOOL CDeleteAComment::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_listctrl.InsertColumn(1, L"MsgID", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(2, L"Message", LVCFMT_CENTER, 300);
	m_listctrl.InsertColumn(3, L"Author", LVCFMT_CENTER, 150);
	m_listctrl.InsertColumn(4, L"Posted Date", LVCFMT_CENTER, 150);
	m_listctrl.InsertColumn(5, L"Approval", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(0, L"Select", LVCFMT_CENTER, 100);

	DeleteACommentAPI();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/***************************************************************
  Function Name : OnCbnSelchangeComboSelectForumId
  Return Type : void
  Remarks : Function to load all topics for a specific forum 
 **************************************************************/
void CDeleteAComment::OnCbnSelchangeComboSelectForumId()
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
/************************************************************************
  Function Name : OnCbnSelchangeComboSelectTopicId
  Return Type : void
  Remarks : Function to load all threads corresponding to topic selection 
 ***********************************************************************/
void CDeleteAComment::OnCbnSelchangeComboSelectTopicId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		CArray<ItemInfo>InfoArray;
		CString strTopicID;
		strTopicID.Format(_T("%u"), (Combodrop_down->GetItemData(Combo_Sel)));
		m_ForumService->GetAllThreadsWithTopicID(strTopicID, InfoArray);
		CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
		Combodrop->ResetContent();
		for (unsigned int i = 0; i < InfoArray.GetSize(); i++)
		{
			Combodrop->AddString(InfoArray[i].Text);
			Combodrop->SetItemData(i, (int)InfoArray[i].Value);
		}
	}
#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_TOPIC_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		try {
			CString getAllThreads;
			getAllThreads.Format(_T("Api/Forum/GetAllThreadsWithTopicID?strTopicID=%d"), m_Topic_Id[Combo_Sel]);
			JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllThreads);
			JSONArray root = Jvalue->AsArray();
			CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
			Combodrop->ResetContent();
			m_Thread_Id.RemoveAll();
			for (unsigned int i = 0; i < root.size(); i++)
			{
				JSONObject Jobj = root[i]->AsObject();
				CString strThreadID(Jobj[L"Text"]->AsString().c_str());
				m_Thread_Id.Add((int)Jobj[L"Value"]->AsNumber());
				Combodrop->AddString(strThreadID);
			}

			std::wstring res = Jvalue->Stringify(true);
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
  Function Name : OnCbnSelchangeComboSelectThreadId
  Return Type : void
  Remarks : Function to load all messages corresponding to thread selection  
 **************************************************************/
void CDeleteAComment::OnCbnSelchangeComboSelectThreadId()
{
	// TODO: Add your control notification handler code here
#if TRUE
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	m_InfoArray.RemoveAll();
	if (Combo_Sel != CB_ERR)
	{
		CString strThreadID;
		strThreadID.Format(_T("%u"), (Combodrop_down->GetItemData(Combo_Sel)));
		m_ForumService->GetMsgsByTrdID(strThreadID, m_InfoArray);
		AddCommentstoTable();
	}
#else
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_THREAD_ID);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		try {
			CString getAllMessages;
			getAllMessages.Format(_T("Api/Forum/GetMsgsByTrdID?strThreadID=%d"), m_Thread_Id[Combo_Sel]);
			JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
			JSONArray root = Jvalue->AsArray();
			
			AddCommentTable(root);

			std::wstring res = Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllMessages);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}
	}
#endif
}
/******************************************************************
  Function Name : AddCommentTable
  Return Type : void
  Parameters : arr 
  Remarks : Function to load all messages in to list control table
 *****************************************************************/
#if TRUE
void CDeleteAComment::AddCommentstoTable()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_CHECKBOXES);
	m_listctrl.DeleteAllItems();
	UpdateData();

	for (unsigned int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		CStringA strPostedDate = m_InfoArray[i].PostedDate;
		ULONGLONG num = _atoi64(strPostedDate);
		COleDateTime date = GetDateFromTicks(num);
		CString strdate = date.Format(_T("%A, %B %d, %Y"));
		CString strApproval = m_InfoArray[i].Status ? _T("true") : _T("false");

		int nItem;
		nItem = m_listctrl.InsertItem(i, _T(""));
		m_listctrl.SetItemText(nItem, 1, m_InfoArray[i].MsgID);
		m_listctrl.SetItemText(nItem, 2, m_InfoArray[i].Message);
		m_listctrl.SetItemText(nItem, 3, m_InfoArray[i].Author);
		m_listctrl.SetItemText(nItem, 4, strdate);
		m_listctrl.SetItemText(nItem, 5, strApproval);
	}

}
#else
void CDeleteAComment::AddCommentTable(JSONArray arr)
{
	    m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_CHECKBOXES);
		m_listctrl.DeleteAllItems();
		UpdateData();
		
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			JSONObject Jobj = arr[i]->AsObject();
			CString strMsgID(Jobj[L"MsgID"]->AsString().c_str());
			CString strMessage(Jobj[L"Message"]->AsString().c_str());
			CString strAuthor(Jobj[L"Author"]->AsString().c_str());
			CStringA strPostedDate(Jobj[L"PostedDate"]->AsString().c_str());
			ULONGLONG num = _atoi64(strPostedDate);
			COleDateTime date = GetDateFromTicks(num);
			CString strdate = date.Format(_T("%A, %B %d, %Y"));
			bool Approval(Jobj[L"Status"]->AsBool());
			CString strApproval = Approval ? _T("true") : _T("false");

			
			int nItem;
			nItem = m_listctrl.InsertItem(i, _T(""));
			m_listctrl.SetItemText(nItem, 1, strMsgID);
			m_listctrl.SetItemText(nItem, 2, strMessage);
			m_listctrl.SetItemText(nItem, 3, strAuthor);
			m_listctrl.SetItemText(nItem, 4, strdate);
			m_listctrl.SetItemText(nItem, 5, strApproval);
		}

}
#endif
/******************************************************************
  Function Name : GetDateFromTicks
  Return Type : COleDateTime
  Parameters : date 
  Remarks : Function to retrieve the date and time from given ticks 
 *****************************************************************/
COleDateTime CDeleteAComment::GetDateFromTicks(ULONGLONG date)
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
