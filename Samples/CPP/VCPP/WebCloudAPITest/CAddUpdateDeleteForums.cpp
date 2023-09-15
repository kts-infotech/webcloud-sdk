/*********************************************************************
   Workfile : CAddUpdateDeleteForums.cpp
   Description : Implementation of  CAddUpdateDeleteForums.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 7 August 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddUpdateDeleteForums.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CAddUpdateDeleteForums dialog

IMPLEMENT_DYNAMIC(CAddUpdateDeleteForums, CDialogEx)

CAddUpdateDeleteForums::CAddUpdateDeleteForums(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_UPDATE_DELETE_FORUMS, pParent)
{
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
}

CAddUpdateDeleteForums::~CAddUpdateDeleteForums()
{
}

void CAddUpdateDeleteForums::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddUpdateDeleteForums, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddUpdateDeleteForums::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CAddUpdateDeleteForums::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW, &CAddUpdateDeleteForums::OnBnClickedButtonAddNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CAddUpdateDeleteForums::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDOK, &CAddUpdateDeleteForums::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST_EXISTING_FORUM_NAMES, &CAddUpdateDeleteForums::OnLbnSelchangeListExistingForumNames)
END_MESSAGE_MAP()


// CAddUpdateDeleteForums message handlers

/***************************************************************
  Function Name : OnBnClickedButton1
  Return Type : void
  Remarks : Button click function to retrieve e-mail  
 **************************************************************/
void CAddUpdateDeleteForums::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
   //Retrieve Email
	CComboBox* combo_Box = (CComboBox*)GetDlgItem(IDC_COMBO_SELECTE_GROUP);
	int isel=combo_Box->GetCurSel();
	if (isel != CB_ERR)
	{
#if TRUE
		CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT_PARTICIPANT_EMAIL);
		Edit_Box3->SetWindowText(_T(""));
		CString Emails;
		m_ForumService->RetrieveEmail(InfoArray[isel].CategoryID, Emails);
		Edit_Box3->SetWindowText(Emails);
#else
		CString RetrieveEmail;
		RetrieveEmail.Format(_T("Api/Forum/RetrieveEmail?strGroupId=%s"), m_strGroupId[isel]);
		try
		{
			JSONValue* jval = NetworkRequest::GetReqEx(RetrieveEmail);
			std::wstring res = jval->AsString();
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(RetrieveEmail);
			CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT_PARTICIPANT_EMAIL);
			Edit_Box3->SetWindowText(_T(""));
			Edit_Box3->SetWindowText(cstrRes);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}
#endif

	}
	else
	{
		AfxMessageBox(_T("Please Select A Group"));
	}
}

/***************************************************************
  Function Name : OnBnClickedButtonUpdate
  Return Type : void
  Remarks : Function to add and update  forums
 **************************************************************/
void CAddUpdateDeleteForums::OnBnClickedButtonUpdate()
{
	// TODO: Add your control notification handler code here
	CString  strtext, strDesc, strEmail,Combo_Sel_Forum_type, Combo_Sel_Forum_type_new;
	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_NAME);
	Edit_Box1->GetWindowText(strtext);
	CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_SETTINGS_DESCRIPTION);
	Edit_Box2->GetWindowText(strDesc);
	CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT_PARTICIPANT_EMAIL);
	Edit_Box3->GetWindowText(strEmail);
	CComboBox* combo_Box_drop = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_TYPE);
	int isel=combo_Box_drop->GetCurSel();
	combo_Box_drop->GetWindowText(Combo_Sel_Forum_type);
	CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_FORUM_NAMES);
	int iListsel = List_box->GetCurSel();
	
	if (Combo_Sel_Forum_type == _T(""))
	{
		AfxMessageBox(_T("Please Enter Data "));
		return;
	}
	
	combo_Box_drop->GetLBText(isel, Combo_Sel_Forum_type);
	if (Combo_Sel_Forum_type == _T("Discussion Forum"))
	     Combo_Sel_Forum_type_new = _T("False");
	else if (Combo_Sel_Forum_type == _T("Bug Tracking System") )
		Combo_Sel_Forum_type_new =_T("True");
	else if (Combo_Sel_Forum_type == _T("Blog"))
		Combo_Sel_Forum_type_new=(_T("Blog"));

	CString strButtonText;
	bool IsPrivate=false;
	bool IsThreadAdminOnly=false;
	CButton* Check1 = (CButton*)GetDlgItem(IDC_CHECK_PRIVATE_FORUM);
	int check_box1 = Check1->GetCheck();
	if (check_box1 == BST_UNCHECKED)
		IsPrivate = false;
	else if (check_box1 == BST_CHECKED)
		IsPrivate = true;

	CButton* Check2 = (CButton*)GetDlgItem(IDC_CHECK_ALLOW_ONLY_ADMINS);
	int check_box2 = Check2->GetCheck();
	if (check_box2 == BST_UNCHECKED)
		IsThreadAdminOnly = false;
	else if (check_box2 == BST_CHECKED)
		IsThreadAdminOnly = true;
	
	if (strtext!=_T(""))
	{
		CString ErrorDesc = _T("");
		GetDlgItem(IDC_BUTTON_UPDATE)->GetWindowText(strButtonText);
		if (strButtonText == _T("Update"))
		{
			
#if TRUE
			FormDetailsInfo Info;
			Info.ErrorDesc = _T("");
			Info.FormID = m_InfoArray[iListsel].FormID;
			Info.FormName = strtext;
			Info.FormDesc = strDesc;
			Info.GroupEmail = strEmail;
			Info.ForumType = Combo_Sel_Forum_type_new;
			bool Success = false;
			m_ForumService->UpdateForum(Info);

#else
			
			CString ErrorDesc = _T("");
			CString FormID = m_strForumId[iListsel];
			CString FormName = strtext;
			CString FormDesc = strDesc;
			CString GroupEmail = strEmail;
			CString ForumType = Combo_Sel_Forum_type_new;
			bool Success = false;
			CString updateForums = _T("Api/Forum/UpdateForum");
			CString dataUpdate;
			JSONObject obj;
			obj[L"FormID"] = new JSONValue(std::wstring(FormID));
			obj[L"FormName"] = new JSONValue(std::wstring(FormName));
			obj[L"FormDesc"] = new JSONValue(std::wstring(FormDesc));
			obj[L"GroupEmail"] = new JSONValue(std::wstring(GroupEmail));
			obj[L"ForumType"] = new JSONValue(std::wstring(ForumType));
			obj[L"IsPrivate"] = new JSONValue(IsPrivate);
			obj[L"IsThreadAdminOnly"] = new JSONValue(IsThreadAdminOnly);
			obj[L"Success"] = new JSONValue(Success);
			obj[L"ErrorDesc"] = new JSONValue(std::wstring(ErrorDesc));

			JSONValue* val = new JSONValue(obj);
			std::wstring res = val->Stringify(false);
			dataUpdate= CString(res.c_str());

			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataUpdate);
				JSONValue* jval = NetworkRequest::PostReq(updateForums, dataUpdate);
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

			FormDetailsInfo Info;
			Info.ErrorDesc = _T("");
			Info.FormID = _T("");
			Info.FormName = strtext;
			Info.FormDesc = strDesc;
			Info.GroupEmail = strEmail;
			Info.ForumType = Combo_Sel_Forum_type_new;
			bool Success = false;
			m_ForumService->AddForum(Info);

#else
			CString addForums = _T("Api/Forum/AddForum");
			CString dataAdd;
			CString ErrorDesc = _T("");
			CString FormID = _T("");
			CString FormName = strtext;
			CString FormDesc = strDesc;
			CString GroupEmail = strEmail;
		    CString ForumType = Combo_Sel_Forum_type_new;
			bool Success = false;
			JSONObject obj;
			obj[L"FormID"] = new JSONValue(std::wstring(FormID));
			obj[L"FormName"] = new JSONValue(std::wstring(FormName));
			obj[L"FormDesc"] = new JSONValue(std::wstring(FormDesc));
			obj[L"GroupEmail"] = new JSONValue(std::wstring(GroupEmail));
			obj[L"ForumType"] = new JSONValue(std::wstring(ForumType));
			obj[L"IsPrivate"] = new JSONValue(IsPrivate);
			obj[L"IsThreadAdminOnly"] = new JSONValue(IsThreadAdminOnly);
			obj[L"Success"] = new JSONValue(Success);
			obj[L"ErrorDesc"] = new JSONValue(std::wstring(ErrorDesc));

			JSONValue* val = new JSONValue(obj);
			std::wstring res = val->Stringify(false);
			dataAdd = CString(res.c_str());

			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataAdd);
				JSONValue* jval = NetworkRequest::PostReq(addForums, dataAdd);
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
		AfxMessageBox(_T("Please enter Forum Name"));
}

/***************************************************************
  Function Name : OnBnClickedButtonAddNew
  Return Type : void
  Remarks : Clearing the dialog box values to add new forum 
 **************************************************************/
void CAddUpdateDeleteForums::OnBnClickedButtonAddNew()
{
	// TODO: Add your control notification handler code here

	CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT_PARTICIPANT_EMAIL);
	Edit_Box3->SetWindowText(_T(""));
	CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_SETTINGS_DESCRIPTION);
	Edit_Box2->SetWindowText(_T(""));
	CButton* Check1 = (CButton*)GetDlgItem(IDC_CHECK_PRIVATE_FORUM);
	Check1->SetCheck(BST_UNCHECKED);
	CButton* Check2 = (CButton*)GetDlgItem(IDC_CHECK_ALLOW_ONLY_ADMINS);
	Check2->SetCheck(BST_UNCHECKED);
	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_NAME);
	Edit_Box1->SetWindowText(_T(""));
	CComboBox* combo_Box_drop = (CComboBox*)GetDlgItem(IDC_COMBO_FORUM_TYPE);
	combo_Box_drop->ResetContent();
	combo_Box_drop->SetCurSel(0);
	combo_Box_drop->AddString(_T("Discussion Forum"));
	combo_Box_drop->AddString(_T("Bug Tracking"));
	combo_Box_drop->AddString(_T("Blog"));

	SetDlgItemText(IDC_BUTTON_UPDATE, _T("Add"));

}

/***************************************************************
  Function Name : OnBnClickedButtonDelete
  Return Type : void
  Remarks : Function to delete a forum 
 **************************************************************/
void CAddUpdateDeleteForums::OnBnClickedButtonDelete()
{
	// TODO: Add your control notification handler code here

	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_NAME);
	CString  strtext;
	Edit_Box1->GetWindowText(strtext);
	if (strtext == _T(""))
	{
		AfxMessageBox(_T("Please Select A Forum To Delete"));
		return;
	}
	int iAnswer = 0;
	iAnswer = AfxMessageBox(_T("Are You Sure?Do You want to Delete This Forum"), MB_OKCANCEL);
	if (iAnswer == IDCANCEL)
	{
		return;
	}
	CListBox* List_box;
	List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_FORUM_NAMES);
	int isel = List_box->GetCurSel();
#if TRUE
	CString msg;
	
	m_ForumService->DeleteForum(m_InfoArray[isel].FormID,msg);
	if (msg == _T("This Forum Contains Topics"))
	{

		AfxMessageBox((msg + _T("Do you want to delete all details ?")), MB_OKCANCEL);
		if (iAnswer == IDCANCEL)
		{
			return;
		}
		else
		{
			m_ForumService->ForceDeleteForum(m_InfoArray[isel].FormID);	
		}


	}
	else
	{
		AfxMessageBox(msg);
	}



#else
	CString DeleteForum;
	DeleteForum.Format( _T("Api/Forum/DeleteForum?strForumID=%s"), m_strForumId[isel]);
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(DeleteForum);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(DeleteForum);
		CString strCompare = Jvalue->AsString().c_str();
		if (strCompare ==_T("This Forum Contains Topics"))
		{

			AfxMessageBox((cstrRes + _T("Do you want to delete all details ?")), MB_OKCANCEL);
			if (iAnswer == IDCANCEL)
			{
				return;
			}
			else
			{

				CString ForceDeleteForum;
				ForceDeleteForum.Format(_T("Api/Forum/ForceDeleteForum?strForumId=%s"), m_strForumId[isel]);
				JSONValue* JvalueNew = NetworkRequest::GetReqEx(ForceDeleteForum);
				std::wstring resNew = JvalueNew->Stringify(true);
				CString cstrResNew(resNew.c_str());
				CWebCloudAPITestApp::SetResponseMsg(cstrResNew);
				CWebCloudAPITestApp::SetStatusBarMsg(ForceDeleteForum);
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
  Function Name : AddUpdateDeleteForumAPI
  Return Type : void
  Remarks : Loading all forums into combobox for selection 
 **************************************************************/
void CAddUpdateDeleteForums::AddUpdateDeleteForumAPI()
{

	// TODO: Add your implementation code here.
	CString getAllForums = _T("Api/Forum/GetAllForums");
	CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_FORUM_NAMES);
	CComboBox* combo_Box = (CComboBox*)GetDlgItem(IDC_COMBO_SELECTE_GROUP);
	combo_Box->ResetContent();
#if TRUE
	
	m_ForumService->GetAllForums(m_InfoArray);
	for (int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		List_box->AddString(m_InfoArray[i].FormName);
	}
	
	m_ForumService->GetExistingGroups(InfoArray);
	for (int i = 0; i < InfoArray.GetSize(); i++)
	{
		combo_Box->AddString(InfoArray[i].CategoryName);
	}
	
#else
	try
	{

		JSONValue* jval = NetworkRequest::GetReqEx(getAllForums);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllForums);
		JSONArray root = jval->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strForumName(jobj[L"FormName"]->AsString().c_str());
			List_box->AddString(strForumName);
			m_strForumId.Add(jobj[L"FormID"]->AsString().c_str());
			m_strForumType.Add(jobj[L"ForumType"]->AsString().c_str());
			if (m_strForumType[i] == _T("False"))
				m_strForumType_new.Add(_T("Discussion Forum"));
			else if(m_strForumType[i] ==_T("True"))
				m_strForumType_new.Add(_T("Bug Tracking System"));
			else if(m_strForumType[i] == _T("Blog"))
				m_strForumType_new.Add(_T("Blog"));

		}

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}

	try
	{
		CString getExistingGroups = _T("Api/Forum/GetExistingGroups");
		JSONValue* jvalue = NetworkRequest::GetReqEx(getExistingGroups);
		std::wstring res1 = jvalue->Stringify(true);
		CString cstrRes1(res1.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes1);
		CWebCloudAPITestApp::SetStatusBarMsg(getExistingGroups);
		JSONArray root2 = jvalue->AsArray();
		for (unsigned int i = 0; i < root2.size(); i++)
		{
			JSONObject jobj = root2[i]->AsObject();
			CString strExistingGroups(jobj[L"CategoryName"]->AsString().c_str());
			combo_Box->AddString(strExistingGroups);
		    m_strGroupId.Add(jobj[L"CategoryID"]->AsString().c_str());
			
		}

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
#endif
}


void CAddUpdateDeleteForums::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

/***************************************************************
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Overriding OnInitDialog() for initialization 
 **************************************************************/
BOOL CAddUpdateDeleteForums::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	AddUpdateDeleteForumAPI();
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************************************
  Function Name : OnLbnSelchangeListExistingForumNames
  Return Type : void
  Remarks : Function to load all forum details 
 **************************************************************/
void CAddUpdateDeleteForums::OnLbnSelchangeListExistingForumNames()
{
	// TODO: Add your control notification handler code here
	CButton* Button_delete = (CButton*)GetDlgItem(IDC_BUTTON_DELETE);
	Button_delete->EnableWindow(true);
	CListBox* List_box;
	List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_FORUM_NAMES);
	int isel = List_box->GetCurSel();
#if TRUE
	if (m_InfoArray[isel].ForumType == _T("False"))
		SetCurrentTextCombo(IDC_COMBO_FORUM_TYPE, _T("Discussion Forum"));
	else if (m_InfoArray[isel].ForumType == _T("True"))
		SetCurrentTextCombo(IDC_COMBO_FORUM_TYPE, _T("Bug Tracking System"));
	else if (m_InfoArray[isel].ForumType == _T("Blog"))
		SetCurrentTextCombo(IDC_COMBO_FORUM_TYPE, _T("Blog"));
#else
	if (m_strForumType[isel] == _T("False"))
		SetCurrentTextCombo(IDC_COMBO_FORUM_TYPE, _T("Discussion Forum"));
	else if (m_strForumType[isel] == _T("True"))
		SetCurrentTextCombo(IDC_COMBO_FORUM_TYPE, _T("Bug Tracking System"));
	else if (m_strForumType[isel] == _T("Blog"))
		SetCurrentTextCombo(IDC_COMBO_FORUM_TYPE, _T("Blog"));

#endif	
	CButton* Button_Add_New = (CButton*)GetDlgItem(IDC_BUTTON_ADD_NEW);
	Button_Add_New->ShowWindow(SW_SHOW);
	SetDlgItemText(IDC_BUTTON_UPDATE, _T("Update"));
	if (isel != LB_ERR)
	{
#if TRUE
		CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_NAME);
		Edit_Box1->SetWindowText(_T(""));
		CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_SETTINGS_DESCRIPTION);
		Edit_Box2->SetWindowText(_T(""));
		CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT_PARTICIPANT_EMAIL);
		Edit_Box3->SetWindowText(_T(""));
		CButton* Check1 = (CButton*)GetDlgItem(IDC_CHECK_PRIVATE_FORUM);
		CButton* Check2 = (CButton*)GetDlgItem(IDC_CHECK_ALLOW_ONLY_ADMINS);

		Edit_Box1->SetWindowText(m_InfoArray[isel].FormName);
		Edit_Box2->SetWindowText(m_InfoArray[isel].FormDesc);
		Edit_Box3->SetWindowText(m_InfoArray[isel].GroupEmail);

		if (m_InfoArray[isel].IsPrivate == true)
		{
			Check1->SetCheck(BST_CHECKED);
		}
		else
		{
			Check1->SetCheck(BST_UNCHECKED);
		}

		if (m_InfoArray[isel].IsThreadAdminOnly == true)
		{
			Check2->SetCheck(BST_CHECKED);
		}
		else
		{
			Check2->SetCheck(BST_UNCHECKED);
		}
#else
		CString getAllForums = _T("Api/Forum/GetAllForums");
		try
		{
			JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllForums);
			std::wstring res = Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllForums);
			JSONArray root = Jvalue->AsArray();

			CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_NAME);
			Edit_Box1->SetWindowText(_T(""));
			CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT_FORUM_SETTINGS_DESCRIPTION);
			Edit_Box2->SetWindowText(_T(""));
			CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT_PARTICIPANT_EMAIL);
			Edit_Box3->SetWindowText(_T(""));
			CButton* Check1 = (CButton*)GetDlgItem(IDC_CHECK_PRIVATE_FORUM);
			CButton* Check2 = (CButton*)GetDlgItem(IDC_CHECK_ALLOW_ONLY_ADMINS);

			JSONObject Jobj = root[isel]->AsObject();
			CString strFormName(Jobj[L"FormName"]->AsString().c_str());
			Edit_Box1->SetWindowText(strFormName);
			CString strFormDesc(Jobj[L"FormDesc"]->AsString().c_str());
			Edit_Box2->SetWindowText(strFormDesc);
			CString strEmail(Jobj[L"GroupEmail"]->AsString().c_str());
			Edit_Box3->SetWindowText(strEmail);
			bool check1(Jobj[L"IsPrivate"]->AsBool());
			if (check1 == true)
			{
				Check1->SetCheck(BST_CHECKED);
			}
			else
			{
				Check1->SetCheck(BST_UNCHECKED);
			}

			bool check2(Jobj[L"IsThreadAdminOnly"]->AsBool());

			if (check2 == true)
			{
				Check2->SetCheck(BST_CHECKED);
			}
			else
			{
				Check2->SetCheck(BST_UNCHECKED);
			}
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
  Function Name : SetCurrentTextCombo
  Return Type : void
  Parameters : ID,text 
  Remarks : Function to set forum type
 **************************************************************/
void CAddUpdateDeleteForums::SetCurrentTextCombo(int ID, CString text)
{
	CComboBox* comboBox = (CComboBox*)GetDlgItem(ID);
	comboBox->SetCurSel(comboBox->FindStringExact(0, text));
}
