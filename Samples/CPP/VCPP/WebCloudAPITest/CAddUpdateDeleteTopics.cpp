/*********************************************************************
   Workfile : CAddUpdateDeleteTopics.cpp
   Description : Implementation of  CAddUpdateDeleteTopics.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 8 August 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddUpdateDeleteTopics.h"
#include "afxdialogex.h"


// CAddUpdateDeleteTopics dialog

IMPLEMENT_DYNAMIC(CAddUpdateDeleteTopics, CDialogEx)

CAddUpdateDeleteTopics::CAddUpdateDeleteTopics(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_UPDATE_DELETE_TOPICS, pParent)
{
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
}

CAddUpdateDeleteTopics::~CAddUpdateDeleteTopics()
{
}

void CAddUpdateDeleteTopics::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_EMAILS, m_Listboxctrl);
}


BEGIN_MESSAGE_MAP(CAddUpdateDeleteTopics, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_ALL, &CAddUpdateDeleteTopics::OnBnClickedButtonSelectAll)
	ON_BN_CLICKED(IDC_BUTTON_UNSELECT_ALL, &CAddUpdateDeleteTopics::OnBnClickedButtonUnselectAll)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CAddUpdateDeleteTopics::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CAddUpdateDeleteTopics::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDOK3, &CAddUpdateDeleteTopics::OnBnClickedOk3)
	ON_CBN_SELCHANGE(IDC_COMBO_FORUM_NAME, &CAddUpdateDeleteTopics::OnCbnSelchangeComboForumName)
	ON_LBN_SELCHANGE(IDC_LIST_EXISTING_TOPIC, &CAddUpdateDeleteTopics::OnLbnSelchangeListExistingTopic)
	ON_BN_CLICKED(IDC_ADD_NEW, &CAddUpdateDeleteTopics::OnBnClickedAddNew)
	ON_LBN_SELCHANGE(IDC_LIST_EMAILS, &CAddUpdateDeleteTopics::OnLbnSelchangeListEmails)
END_MESSAGE_MAP()


// CAddUpdateDeleteTopics message handlers

/***************************************************************
  Function Name : OnBnClickedButtonSelectAll
  Return Type : void
  Remarks : Function to select all e-mails 
 **************************************************************/
void CAddUpdateDeleteTopics::OnBnClickedButtonSelectAll()
{
	// TODO: Add your control notification handler code here

	
	
	int nCount = m_Listboxctrl.GetCount();

	for (int i = 0; i < nCount; i++)
	{
		m_Listboxctrl.SetCheck(i, TRUE);

	}

}

/***************************************************************
  Function Name : OnBnClickedButtonUnselectAll
  Return Type : void
  Remarks : Function to unselect all e-mails 
 **************************************************************/
void CAddUpdateDeleteTopics::OnBnClickedButtonUnselectAll()
{
	// TODO: Add your control notification handler code here

	int nCount = m_Listboxctrl.GetCount();

	for (int i = 0; i < nCount; i++)
	{
		m_Listboxctrl.SetCheck(i, FALSE);

	}

}

/***************************************************************
  Function Name : OnBnClickedButtonDelete
  Return Type : void
  Remarks : Function to delete a topic 
 **************************************************************/
void CAddUpdateDeleteTopics::OnBnClickedButtonDelete()
{
	// TODO: Add your control notification handler code here
	CEdit* Edit_Box = (CEdit*)GetDlgItem(IDC_EDIT_TOPIC_NAME);
	CString strText;
	Edit_Box->GetWindowText(strText);
	if (strText == _T(""))
	{
		AfxMessageBox(_T("Please Select A Topic To Delete"));
		return;
	}
	int iAns = 0;
	iAns = AfxMessageBox(_T("Are You Sure?Do You want to Delete This Topic"), MB_OKCANCEL);
	if (iAns == IDCANCEL)
	{
		return;
	}
	CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC); 
	int isel = List_box->GetCurSel();
	int Topic_Id =(int)List_box->GetItemData(isel);
#if TRUE
	CString strCompare;
	m_ForumService->DeleteTopic(Topic_Id, strCompare);
	if (strCompare == _T("This Topic contains Threads"))
	{

		AfxMessageBox((strCompare + _T("Do you want to delete all details ?")), MB_OKCANCEL);
		if (iAns == IDCANCEL)
		{
			return;
		}
		else
		{
			CString strCompare;
			m_ForumService->ForceDeleteTopic(Topic_Id);
		}


	}
	else
	{
		AfxMessageBox(strCompare);
	}



#else
	CString DeleteTopic;
	DeleteTopic.Format(_T("Api/Forum/DeleteTopic?strTopicID=%d"), Topic_Id);
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(DeleteTopic);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(DeleteTopic);
		CString strCompare = Jvalue->AsString().c_str();
		if (strCompare == _T("This Topic contains Threads"))
		{

			AfxMessageBox((cstrRes + _T("Do you want to delete all details ?")), MB_OKCANCEL);
			if (iAns == IDCANCEL)
			{
				return;
			}
			else
			{

				CString ForceDeleteTopic;
				ForceDeleteTopic.Format(_T("Api/Forum/ForceDeleteTopic?strTopicId=%d"), Topic_Id);
				JSONValue* JvalueNew = NetworkRequest::GetReqEx(ForceDeleteTopic);
				std::wstring resNew = JvalueNew->Stringify(true);
				CString cstrResNew(resNew.c_str());
				CWebCloudAPITestApp::SetResponseMsg(cstrResNew);
				CWebCloudAPITestApp::SetStatusBarMsg(ForceDeleteTopic);
				AfxMessageBox(cstrResNew);
			}


		}
		else
		{
			AfxMessageBox(cstrRes);
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
  Function Name : OnBnClickedButtonAdd
  Return Type : void
  Remarks : Function to add and update topic 
 **************************************************************/
void CAddUpdateDeleteTopics::OnBnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	CString strButtonText, strTopicName, strComboDesc, strEmail;
	bool AdminApproval;
	GetDlgItem(IDC_BUTTON_ADD)->GetWindowText(strButtonText);
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_NAME);
	GetDlgItem(IDC_EDIT_TOPIC_NAME)->GetWindowText(strTopicName);
	GetDlgItem(IDC_EDIT_FORUM_TOPIC_DESCRIPTION)->GetWindowText(strComboDesc);

	CButton* Check1 = (CButton*)GetDlgItem(IDC_CHECK_NEED_ADMIN_APPROVAL);
	int check_box = Check1->GetCheck();
	if (check_box == BST_UNCHECKED)
		AdminApproval = false;
	else if (check_box == BST_CHECKED)
		AdminApproval = true;
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (strTopicName != _T(""))
	{
		if (strButtonText == _T("Update"))
		{
#if TRUE
			CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC);
			int isel = List_box->GetCurSel();
			Topics Info;
			int itopicID = GetTopicId();
			CString TopicID;
			TopicID.Format(_T("%d"), itopicID);
			Info.TopicID = TopicID;
			Info.ErrorDesc= _T("");
			Info.ForumID = m_InfoArray[Combo_Sel].FormID;
			Info.TopicName= strTopicName;
			Info.TopicDesc = strComboDesc;
			Info.GroupEmail = GetListboxDataSelected();
			bool Success = false;
			m_ForumService->UpdateTopic(Info);
#else
			int itopicID = GetTopicId();
			CString TopicID;
			TopicID.Format(_T("%d"), itopicID);
			CString ErrorDesc = _T("");
			CString FormID = m_ForumId[Combo_Sel];
			CString TopicName = strTopicName;
			CString TopicDesc = strComboDesc;
			CString GroupEmail = GetListboxDataSelected();
			CString updateTopic = _T("Api/Forum/UpdateTopic");
			CString dataUpdate;
			bool Success = false;

			JSONObject obj;
			obj[L"TopicID"] = new JSONValue(std::wstring(TopicID));
			obj[L"ForumID"] = new JSONValue(std::wstring(FormID));
			obj[L"GroupEmail"] = new JSONValue(std::wstring(GroupEmail));
			obj[L"TopicName"] = new JSONValue(std::wstring(TopicName));
			obj[L"TopicDesc"] = new JSONValue(std::wstring(TopicDesc));
			obj[L"AdminApproval"] = new JSONValue(AdminApproval);
			obj[L"Success"] = new JSONValue(Success);
			obj[L"ErrorDesc"] = new JSONValue(std::wstring(ErrorDesc));

			JSONValue* val = new JSONValue(obj);
			std::wstring res = val->Stringify(false);
			dataUpdate = CString(res.c_str());

			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataUpdate);
				JSONValue* jval = NetworkRequest::PostReq(updateTopic, dataUpdate);
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
		else if (strButtonText == _T("Add"))
		{
#if TRUE
			
			Topics Info;
			Info.TopicID = _T("");
			Info.ErrorDesc = _T("");
			Info.ForumID = m_InfoArray[Combo_Sel].FormID;
			Info.TopicName = strTopicName;
			Info.TopicDesc = strComboDesc;
			Info.GroupEmail = GetListboxDataSelected();
			bool Success = false;
			m_ForumService->AddTopics(Info);
#else
			CString TopicID = _T("");
			CString ErrorDesc = _T("");
			CString FormID = m_ForumId[Combo_Sel];
			CString TopicName = strTopicName;
			CString TopicDesc = strComboDesc;
			CString GroupEmail = GetListboxDataSelected();
			CString addTopics = _T("Api/Forum/AddTopics");
			CString dataAdd;
			bool Success = false;
			JSONObject obj1;
			obj1[L"TopicID"] = new JSONValue(std::wstring(TopicID));
			obj1[L"ForumID"] = new JSONValue(std::wstring(FormID));
			obj1[L"GroupEmail"] = new JSONValue(std::wstring(GroupEmail));
			obj1[L"TopicName"] = new JSONValue(std::wstring(TopicName));
			obj1[L"TopicDesc"] = new JSONValue(std::wstring(TopicDesc));
			obj1[L"AdminApproval"] = new JSONValue(AdminApproval);
			obj1[L"Success"] = new JSONValue(Success);
			obj1[L"ErrorDesc"] = new JSONValue(std::wstring(ErrorDesc));

			JSONValue* val = new JSONValue(obj1);
			std::wstring res = val->Stringify(false);
			dataAdd = CString(res.c_str());

			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataAdd);
				JSONValue* jval = NetworkRequest::PostReq(addTopics, dataAdd);
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
	}
	else
	{
		AfxMessageBox(_T("Please enter Topic Name"));
	}

}
/***************************************************************
  Function Name : AddUpdateDeleteTopicAPI
  Return Type : void
  Remarks : Function to load all forums 
 **************************************************************/
void CAddUpdateDeleteTopics::AddUpdateDeleteTopicAPI()
{
	// TODO: Add your implementation code here.
	CComboBox* combo_Box = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_NAME);
	combo_Box->ResetContent();
#if TRUE
	m_ForumService->GetAllForums(m_InfoArray);
	for (int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		combo_Box->AddString(m_InfoArray[i].FormName);
	}


#else
	CString getAllForums = _T("Api/Forum/GetAllForums");
	try
	{

		JSONValue* jval = NetworkRequest::GetReqEx(getAllForums);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllForums);

		JSONArray root = jval->AsArray();
		m_ForumId.RemoveAll();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strForumName(jobj[L"FormName"]->AsString().c_str());
			combo_Box->AddString(strForumName);
			m_ForumId.Add(jobj[L"FormID"]->AsString().c_str());
			m_Group_Email.Add(jobj[L"GroupEmail"]->AsString().c_str());
			
		}
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
#endif
}


void CAddUpdateDeleteTopics::OnBnClickedOk3()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}

/***************************************************************
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Overriding OnInitDialog() for initialization 
 **************************************************************/
BOOL CAddUpdateDeleteTopics::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	AddUpdateDeleteTopicAPI();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************************************
  Function Name : OnCbnSelchangeComboForumName
  Return Type : void
  Remarks : Function to load all topics 
 **************************************************************/
void CAddUpdateDeleteTopics::OnCbnSelchangeComboForumName()
{
	// TODO: Add your control notification handler code here
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_NAME);
	int Combo_Sel = Combodrop_down->GetCurSel();
	CListBox* Listbox = (CListBox*)GetDlgItem(IDC_LIST_EMAILS);
	GetDlgItem(IDC_EDIT_TOPIC_NAME)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_FORUM_TOPIC_DESCRIPTION)->SetWindowText(_T(""));
	CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC);
	List_box->ResetContent();
	if (Combo_Sel != CB_ERR)
	{
		
#if TRUE
		InfoArray.RemoveAll();
		m_ForumService->GetAllTopicsWithForumID(m_InfoArray[Combo_Sel].FormID,InfoArray);
		SplitCString(m_InfoArray[Combo_Sel].GroupEmail);
		int size = (int)m_Group_Email_Spilt.GetSize();
		m_Listboxctrl.ResetContent();
		for (int j = 0; j < size; j++)
		{
			m_Listboxctrl.SetCheckStyle(BS_AUTOCHECKBOX);
			m_Listboxctrl.AddString(m_Group_Email_Spilt[j]);
		}
		
		for (unsigned int i = 0; i <InfoArray.GetSize(); i++)
		{
			
			List_box->AddString(InfoArray[i].Text);
			List_box->SetItemData(i, InfoArray[i].Value);

		}

#else
		try
		{
			CString getAllTopics;
			getAllTopics.Format(_T("Api/Forum/GetAllTopicsWithForumID?iForumId=%s"), m_ForumId[Combo_Sel]);
			JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllTopics);
			m_root = Jvalue->AsArray();
			CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC);
			List_box->ResetContent();
			m_Listboxctrl.ResetContent();
			SplitCString(m_Group_Email[Combo_Sel]);
			int size =(int)m_Group_Email_Spilt.GetSize();
			for ( int j = 0;j <size; j++)
			{
				m_Listboxctrl.SetCheckStyle(BS_AUTOCHECKBOX);
				m_Listboxctrl.AddString(m_Group_Email_Spilt[j]);
			}

			for (unsigned int i = 0; i < m_root.size(); i++)
			{
				JSONObject Jobj = m_root[i]->AsObject();
				CString strTopicID_data(Jobj[L"Text"]->AsString().c_str());
				int iTopicId = (int)Jobj[L"Value"]->AsNumber();
				m_Topic_Id.Add((int)Jobj[L"Value"]->AsNumber());
				List_box->AddString(strTopicID_data);
				List_box->SetItemData(i, iTopicId);
				
			}
			std::wstring res = Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllTopics);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}
#endif
	}
}
/***************************************************************
  Function Name : SplitCString
  Return Type : void
  Parameters : str 
  Remarks : function to split group e-mail 
 **************************************************************/
 void CAddUpdateDeleteTopics::SplitCString(CString str)
{
	 m_Group_Email_Spilt.RemoveAll();
	int nTokenPos = 0;
	CString strToken = str.Tokenize(_T(","), nTokenPos);

	while (!strToken.IsEmpty())
	{
		m_Group_Email_Spilt.Add(strToken);
		strToken = str.Tokenize(_T(","), nTokenPos);
		
	}
}
/***************************************************************
  Function Name : OnLbnSelchangeListExistingTopic
  Return Type : void
  Remarks : Function to load  all topic details to dialog box
 **************************************************************/
 void CAddUpdateDeleteTopics::OnLbnSelchangeListExistingTopic()
 {
	 // TODO: Add your control notification handler code here
	 CButton* Button_Add_New = (CButton*)GetDlgItem(IDC_ADD_NEW);
	 Button_Add_New->ShowWindow(SW_SHOW);
	 SetDlgItemText(IDC_BUTTON_ADD, _T("Update"));
	 CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_NAME);
	 int Combo_Sel = Combodrop_down->GetCurSel();
	 CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC);
	 int isel = List_box->GetCurSel();
	 CButton* Check_Admin = (CButton*)GetDlgItem(IDC_CHECK_NEED_ADMIN_APPROVAL);
	 CEdit* Edit_Box = (CEdit*)GetDlgItem(IDC_EDIT_TOPIC_NAME);
	 Edit_Box->SetWindowText(_T(""));
	 GetDlgItem(IDC_EDIT_FORUM_TOPIC_DESCRIPTION)->SetWindowText(_T(""));
	 CString Topic_Name, Topic_Desc;
	 List_box->GetText(isel, Topic_Name);
	 if (isel != LB_ERR)
	 {
#if TRUE
		 CButton* Button_delete = (CButton*)GetDlgItem(IDC_BUTTON_DELETE);
		 Button_delete->EnableWindow(true);
		 int Topic_Id = (int)List_box->GetItemData(isel);
		 m_ForumService->GetAllTopics(infoArray);
		 Topics selectedTopic;
		 for (int i = 0; i < infoArray.GetSize(); i++)
		 {
			 if (_wtoi(infoArray[i].TopicID) == Topic_Id)
			 {
				 selectedTopic=infoArray[i];
			 }
		 }
		 CString EmailCheck = selectedTopic.GroupEmail;
		 CArray<CString>Group_Email_Spilt;
		 Group_Email_Spilt.RemoveAll();
		 int nTokenPos = 0;
		 CString strToken = EmailCheck.Tokenize(_T(","), nTokenPos);
		 while (!strToken.IsEmpty())
		 {
			 Group_Email_Spilt.Add(strToken);
			 strToken = EmailCheck.Tokenize(_T(","), nTokenPos);

		 }
		 for (int i = 0; i < m_Listboxctrl.GetCount(); i++)
		 {
			 m_Listboxctrl.SetCheck(i, BST_UNCHECKED);
		 }
		 for (int i = 0; i < Group_Email_Spilt.GetSize(); i++)
		 {
			 int index = m_Listboxctrl.FindString(0, Group_Email_Spilt[i]);
			 if (index >= 0)
			 {
				 m_Listboxctrl.SetCheck(index, BST_CHECKED);
			 }
		 }

		 bool AdminApproval = selectedTopic.AdminApproval;
		 if (AdminApproval == true)
		 {
			 Check_Admin->SetCheck(BST_CHECKED);
		 }
		 else
		 {
			 Check_Admin->SetCheck(BST_UNCHECKED);
		 }
		 Topic_Desc = selectedTopic.TopicDesc;
		 GetDlgItem(IDC_EDIT_TOPIC_NAME)->SetWindowText(Topic_Name);
		 GetDlgItem(IDC_EDIT_FORUM_TOPIC_DESCRIPTION)->SetWindowText(Topic_Desc);

#else
		 CButton* Button_delete = (CButton*)GetDlgItem(IDC_BUTTON_DELETE);
		 Button_delete->EnableWindow(true);
		 CString getAllTopics = _T("Api/Forum/GetAllTopics");
		 try
		 {
			 JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllTopics);
			 std::wstring res = Jvalue->Stringify(true);
			 CString cstrRes(res.c_str());
			 CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			 CWebCloudAPITestApp::SetStatusBarMsg(getAllTopics);
			 JSONArray root = Jvalue->AsArray();
			 CString EmailCheck = GetGroupEmail(root);

			CArray<CString>Group_Email_Spilt;
			Group_Email_Spilt.RemoveAll();
			int nTokenPos = 0;
			CString strToken = EmailCheck.Tokenize(_T(","), nTokenPos);
			while (!strToken.IsEmpty())
			{
				Group_Email_Spilt.Add(strToken);
				strToken = EmailCheck.Tokenize(_T(","), nTokenPos);
					
			}
			for (int i = 0; i < m_Listboxctrl.GetCount();i++)
			{
				m_Listboxctrl.SetCheck(i, BST_UNCHECKED);
			}
			for (int i = 0; i < Group_Email_Spilt.GetSize(); i++)
			{
				int index = m_Listboxctrl.FindString(0, Group_Email_Spilt[i]);
				if (index >= 0)
				{
					m_Listboxctrl.SetCheck(index, BST_CHECKED);
				}
			}
				
			 bool AdminApproval=GetadminApproval(Topic_Name,root);
			 if (AdminApproval == true)
			 {
				 Check_Admin->SetCheck(BST_CHECKED);
			 }
			 else
			 {
				 Check_Admin->SetCheck(BST_UNCHECKED);
			 }
			 Topic_Desc = GetTopicDescription(Topic_Name, root);
			 GetDlgItem(IDC_EDIT_TOPIC_NAME)->SetWindowText(Topic_Name);
			 GetDlgItem(IDC_EDIT_FORUM_TOPIC_DESCRIPTION)->SetWindowText(Topic_Desc);
		 }
		 catch(const std::exception& e)
		 {
			 CString errorStr(e.what());
			 CWebCloudAPITestApp::SetResponseMsg(errorStr);
		 }
#endif

	 }
 }
/***************************************************************
  Function Name : GetTopicDescription
  Return Type : CString
  Parameters : strTopicName ,arr
  Remarks : Function to  get topic description based on topic name
 **************************************************************/
 CString CAddUpdateDeleteTopics::GetTopicDescription(CString strTopicName, JSONArray arr)
 {
	 CString strTopicDesc;
	 for (int i = 0; i < arr.size(); i++)
	 {
		 JSONObject obj = arr[i]->AsObject();
		 CString strTopic(obj[L"TopicName"]->AsString().c_str());
		 if (strTopic == strTopicName)
		 {
			 strTopicDesc = obj[L"TopicDesc"]->AsString().c_str();
			 return strTopicDesc;
		 }
	 }
	 return CString();
 }
/***************************************************************
  Function Name : OnBnClickedAddNew
  Return Type : void
  Remarks : Clearing the dialog box values to add new topic 
 **************************************************************/
 void CAddUpdateDeleteTopics::OnBnClickedAddNew()
 {
	 // TODO: Add your control notification handler code here
	 CButton* Button_Add_New = (CButton*)GetDlgItem(IDC_ADD_NEW);
	 Button_Add_New->ShowWindow(SW_HIDE);
	 for (int i = 0; i < m_Listboxctrl.GetCount(); i++)
	 {
		 m_Listboxctrl.SetCheck(i, BST_UNCHECKED);
	 }
	 SetDlgItemText(IDC_BUTTON_ADD, _T("Add"));
	 CEdit* Edit_Box = (CEdit*)GetDlgItem(IDC_EDIT_TOPIC_NAME);
	 Edit_Box->SetWindowText(_T(""));
	 GetDlgItem(IDC_EDIT_FORUM_TOPIC_DESCRIPTION)->SetWindowText(_T(""));
 }
 /***************************************************************
   Function Name : GetTopicId
   Return Type : int
   Remarks : Function to get topic id based on current selection 
  **************************************************************/
 int CAddUpdateDeleteTopics::GetTopicId()
 {
	 CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC);
	 int isel = List_box->GetCurSel();
	 int Topic_Id=(int)List_box->GetItemData(isel);
	 return Topic_Id;
 }
 /***********************************************************************
   Function Name : GetListboxDataSelected
   Return Type : CString
   Remarks : Function to get the selected e-mails from the group e-mails  
  ***********************************************************************/
 CString CAddUpdateDeleteTopics::GetListboxDataSelected()
 {

	 int nCount = m_Listboxctrl.GetCount();
	 CString str = _T("");
	 for (int i = 0; i < nCount; i++)
	 {
		 if (m_Listboxctrl.GetCheck(i) == BST_CHECKED)
		 {
			 CString strEach;
			 m_Listboxctrl.GetText(i, strEach);
			 str += strEach + _T(",");
		 }
		 
	 }
	 return str;
 }

 void CAddUpdateDeleteTopics::OnLbnSelchangeListEmails()
 {
	
	 
 }
/*************************************************************************
  Function Name : GetadminApproval
  Return Type : bool
  Parameters : strTopicName1 ,arr1
  Remarks : Function to get the admin approval details for a given topic
 ***********************************************************************/
 bool CAddUpdateDeleteTopics::GetadminApproval(CString strTopicName1, JSONArray arr1)
 {
	 bool AdminApproval;

	 for (int i = 0; i < arr1.size(); i++)
	 {
		 JSONObject obj = arr1[i]->AsObject();
		 CString strTopic(obj[L"TopicName"]->AsString().c_str());
		 if (strTopic == strTopicName1)
		 {
			 AdminApproval = (obj[L"AdminApproval"]->AsBool());
			 return AdminApproval;
		 }

	 }

	 return 0;

 }
 /***************************************************************
   Function Name : GetGroupEmail
   Return Type : CString
   Parameters : arr 
   Remarks : Function to get the group e-mail of a specific topic 
  **************************************************************/
 CString CAddUpdateDeleteTopics::GetGroupEmail(JSONArray arr)
 {
	 CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_TOPIC);
	 int isel = List_box->GetCurSel();
	 int Topic_Id = (int)List_box->GetItemData(isel);
	 CString strTopicId;
	 strTopicId.Format(_T("%d"), Topic_Id);
	 for (int i = 0; i < arr.size(); i++)
	 {
		 JSONObject Jobj = arr[i]->AsObject();
		 CString strTpicIds=Jobj[L"TopicID"]->AsString().c_str();
		 if (strTopicId == strTpicIds)
		 {
			 CString strGroupEmail(Jobj[L"GroupEmail"]->AsString().c_str());
			 return strGroupEmail;
		 }
	 }
	 return CString();
 }
