/*********************************************************************
   Workfile : CAddUpdateThread.cpp
   Description : Implementation of  CAddUpdateThread.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 8 August 2022
 *********************************************************************/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddUpdateThread.h"
#include "afxdialogex.h"
#include "base64.h"
// CAddUpdateThread dialog

IMPLEMENT_DYNAMIC(CAddUpdateThread, CDialogEx)

CAddUpdateThread::CAddUpdateThread(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_UPDATE_THREAD, pParent)
{
	m_pStream = 0;
	m_ForumService = CWebCloudAPITestApp::m_pAppApiService;
}

CAddUpdateThread::~CAddUpdateThread()
{
}

void CAddUpdateThread::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddUpdateThread, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddUpdateThread::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddUpdateThread::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_IMAGE, &CAddUpdateThread::OnBnClickedButtonSelectImage)
	ON_CBN_SELCHANGE(IDC_COMBO_EXISTING_FORUM_NAME, &CAddUpdateThread::OnCbnSelchangeComboExistingForumName)
	ON_CBN_SELCHANGE(IDC_COMBO_EXISTING_TOPIC_NAME, &CAddUpdateThread::OnCbnSelchangeComboExistingTopicName)
	ON_LBN_SELCHANGE(IDC_LIST_EXISTING_THREADS, &CAddUpdateThread::OnLbnSelchangeListExistingThreads)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW, &CAddUpdateThread::OnBnClickedButtonAddNew)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK1, &CAddUpdateThread::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CAddUpdateThread message handlers

/***************************************************************
  Function Name : OnBnClickedOk
  Return Type : void
  Remarks : Function to add and update thread
 **************************************************************/
void CAddUpdateThread::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();


	CString strImage,strImage1,strImg;
	CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
	bool check=CheckImage->GetState();
	bool uploadOrexisting=false;
		if (check)
		{
			CString imagepath;
			GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->GetWindowText(imagepath);
			if (imagepath == _T(""))
			{
				AfxMessageBox(_T("Please Select an Image"));
					return;
			}
			uploadOrexisting = true;

		}
		else
		{
			uploadOrexisting = false;
			if ((m_strImage == _T("")) && (m_strName == _T("")))
			{
					 strImage = _T("");
					 strImg = _T("");
			}
			else
			{
				 strImage = m_strImage;
				 strImg = m_strName;
			}
			
		}

	CString strButtonText, strTopicName, strThreadDesc,strThreadName, strForum, strImgup,strForumName,strTopic;
	GetDlgItem(IDOK)->GetWindowText(strButtonText);
	CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_TOPIC_NAME);
	Combodrop->GetWindowText(strTopic);
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_FORUM_NAME);
	Combodrop_down->GetWindowText(strForumName);
	if (strForumName ==_T("")|| strTopic==_T(""))
	{
		AfxMessageBox(_T("Please Select A Forum and Topic"));
		return;
	}
	int iselforum= Combodrop_down->GetCurSel();
	Combodrop_down->GetLBText(iselforum, strForum);
	int iseltopic = Combodrop->GetCurSel();
	Combodrop->GetLBText(iseltopic, strTopicName);
	GetDlgItem(IDC_EDIT_THREAD_NAME)->GetWindowText(strThreadName);

	GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION)->GetWindowText(strThreadDesc);
	GetDlgItem(IDOK)->GetWindowText(strButtonText);
	GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->GetWindowText(strImgup);
	CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_THREADS);
	CString FormID = m_Forum_Id[iselforum];
	int iThreadID = (int)List_box->GetItemData(List_box->GetCurSel());
	CString ThreadId;
	ThreadId.Format(_T("%d"), iThreadID);
	CString ErrorDesc = _T("");
	bool Success = false;
	CString User = CWebCloudAPITestApp::GetUsername();
	if (strThreadName != _T(""))
	{

		if (strButtonText == _T("Update"))
		{
#if TRUE

			ThreadDetailsInfo Info;
			Info.ftrDetails.BugStatus =_T("None");
			Info.ftrDetails.ThreadAssigned = _T("");
			Info.ftrDetails.PostedDate = _T("");
			Info.ftrDetails.AuthorID = _T("");
			Info.ftrDetails.ThreadImagePth = _T("");

			Info.ForumInfo.Text = strForum;
			int iForumID = _ttoi(FormID);
			Info.ForumInfo.Value = iForumID;
			Info.TopicInfo.Text = strTopicName;
			Info.TopicInfo.Value = m_Topic_Id[iseltopic];
			Info.ThreadID = ThreadId;
			Info.ThreadName = strThreadName;
			Info.UserName = User;
			Info.ThreadDesc = strThreadDesc;

			if (uploadOrexisting)
			{
				if (m_imagepath == _T(""))
					strImage1 = _T("");
				else
					strImage1 = NetworkRequest::ConvertToBase64(m_imagepath);
				Info.ThreadImage = strImage1;
				Info.ImageName = strImgup;
				
			}
			else
			{
				Info.ThreadImage = strImage;
				Info.ImageName = strImg;
			
			}

			Info.Success = Success;
			Info.ErrorDesc = ErrorDesc;

			m_ForumService->UpdateThread(Info);

#else
			CString updateThreads = _T("Api/Forum/UpdateThread");
			JSONObject ftrDetails;
			ftrDetails[L"BugStatus"] = new JSONValue(L"None");
			ftrDetails[L"ThreadAssigned"] = new JSONValue(L"");
			ftrDetails[L"PostedDate"] = new JSONValue(L"");
			ftrDetails[L"AuthorID"] = new JSONValue(L"");
			ftrDetails[L"ThreadImagePth"] = new JSONValue(L"");

			JSONObject ThreadDetailsInfo;
			int iForumID = _ttoi(FormID);
			ThreadDetailsInfo[L"ftrDetails"] = new JSONValue(ftrDetails);

			JSONObject ItemInfo;
			ItemInfo[L"Text"] = new JSONValue(std::wstring(strForum));
			ItemInfo[L"Value"] = new JSONValue(iForumID);
			ThreadDetailsInfo[L"ForumInfo"] = new JSONValue(ItemInfo);

			JSONObject ItemInfo1;
			ItemInfo1[L"Text"] = new JSONValue(std::wstring(strTopicName));
			ItemInfo1[L"Value"] = new JSONValue(m_Topic_Id[iseltopic]);

			ThreadDetailsInfo[L"TopicInfo"] = new JSONValue(ItemInfo1);
			ThreadDetailsInfo[L"ThreadID"] = new JSONValue(std::wstring(ThreadId));
			ThreadDetailsInfo[L"ThreadName"] = new JSONValue(std::wstring(strThreadName));
			ThreadDetailsInfo[L"UserName"] = new JSONValue(std::wstring(User));
			ThreadDetailsInfo[L"ThreadDesc"] = new JSONValue(std::wstring(strThreadDesc));

			if (uploadOrexisting)
			{
				if (m_imagepath == _T(""))
					 strImage1 = _T("");
				else
					 strImage1 = NetworkRequest::ConvertToBase64(m_imagepath);

				ThreadDetailsInfo[L"ThreadImage"] = new JSONValue(std::wstring(strImage1));
				ThreadDetailsInfo[L"ImageName"] = new JSONValue(std::wstring(strImgup));
			}
			else
			{
				ThreadDetailsInfo[L"ThreadImage"] = new JSONValue(std::wstring(strImage));
				ThreadDetailsInfo[L"ImageName"] = new JSONValue(std::wstring(strImg));

			}

			ThreadDetailsInfo[L"Success"] = new JSONValue(Success);
			ThreadDetailsInfo[L"ErrorDesc"] = new JSONValue(ErrorDesc);

			JSONValue* val = new JSONValue(ThreadDetailsInfo);
			std::wstring res = val->Stringify(false);
			CString dataUpdate = CString(res.c_str());

			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataUpdate);
				JSONValue* jval = NetworkRequest::PostReq(updateThreads, dataUpdate);
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
		ThreadDetailsInfo Info;
		Info.ftrDetails.BugStatus = _T("None");
		Info.ftrDetails.ThreadAssigned = _T("");
		CString PostedDate = GetTicksNow();
		Info.ftrDetails.PostedDate = PostedDate;
		Info.ftrDetails.AuthorID = _T("");
		Info.ftrDetails.ThreadImagePth = _T("");

		Info.ForumInfo.Text = strForum;
		int iForumID = _ttoi(FormID);
		Info.ForumInfo.Value = iForumID;
		Info.TopicInfo.Text = strTopicName;
		Info.TopicInfo.Value = m_Topic_Id[iseltopic];
		Info.ThreadID = _T("");
		Info.ThreadName = strThreadName;
		Info.UserName = User;
		Info.ThreadDesc = strThreadDesc;
		if (m_imagepath == _T(""))
			strImage1 = _T("");
		else
		    strImage1 = NetworkRequest::ConvertToBase64(m_imagepath);
		Info.ThreadImage = strImage1;
		Info.ImageName = strImgup;

		Info.Success = Success;
		Info.ErrorDesc = ErrorDesc;

		m_ForumService->AddThread(Info);
#else
			CString updateThreads = _T("Api/Forum/AddThread");
			JSONObject ftrDetails;
			ftrDetails[L"BugStatus"] = new JSONValue(L"None");
			ftrDetails[L"ThreadAssigned"] = new JSONValue(L"");
			CString PostedDate = GetTicksNow();
			ftrDetails[L"PostedDate"] = new JSONValue(std::wstring(PostedDate));
			ftrDetails[L"AuthorID"] = new JSONValue(L"");
			ftrDetails[L"ThreadImagePth"] = new JSONValue(L"");

			JSONObject ThreadDetailsInfo;
			int iForumID = _ttoi(FormID);
			ThreadDetailsInfo[L"ftrDetails"] = new JSONValue(ftrDetails);

			JSONObject ItemInfo;
			ItemInfo[L"Text"] = new JSONValue(std::wstring(strForum));
			ItemInfo[L"Value"] = new JSONValue(iForumID);
			ThreadDetailsInfo[L"ForumInfo"] = new JSONValue(ItemInfo);

			JSONObject ItemInfo1;
			ItemInfo1[L"Text"] = new JSONValue(std::wstring(strTopicName));
			ItemInfo1[L"Value"] = new JSONValue(m_Topic_Id[iseltopic]);

			ThreadDetailsInfo[L"TopicInfo"] = new JSONValue(ItemInfo1);
			ThreadDetailsInfo[L"ThreadID"] = new JSONValue(L"");
			ThreadDetailsInfo[L"ThreadName"] = new JSONValue(std::wstring(strThreadName));
			ThreadDetailsInfo[L"UserName"] = new JSONValue(std::wstring(User));
			ThreadDetailsInfo[L"ThreadDesc"] = new JSONValue(std::wstring(strThreadDesc));

			if (m_imagepath == _T(""))
				CString strImage = _T("");
			else
			    strImage = NetworkRequest::ConvertToBase64(m_imagepath);

			ThreadDetailsInfo[L"ThreadImage"] = new JSONValue(std::wstring(strImage));
			ThreadDetailsInfo[L"ImageName"] = new JSONValue(std::wstring(strImgup));
			
			ThreadDetailsInfo[L"Success"] = new JSONValue(Success);
			ThreadDetailsInfo[L"ErrorDesc"] = new JSONValue(ErrorDesc);

			JSONValue* val = new JSONValue(ThreadDetailsInfo);
			std::wstring res = val->Stringify(false);
			CString dataUpdate = CString(res.c_str());

			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataUpdate);
				JSONValue* jval = NetworkRequest::PostReq(updateThreads, dataUpdate);
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
	  AfxMessageBox(_T("Please enter Thread Name"));
	}
}

void CAddUpdateThread::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}
/***************************************************************
  Function Name : OnBnClickedButtonSelectImage
  Return Type : void
  Remarks :  Function to set the image path in dialogbox
 **************************************************************/
void CAddUpdateThread::OnBnClickedButtonSelectImage()
{
	// TODO: Add your control notification handler code here
	
	if (OnFileOpen())
	{
		m_pStream = NULL;
		GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->SetWindowText(m_imagepath);
		Invalidate();

	}
}
/***************************************************************
  Function Name : OnFileOpen
  Return Type : BOOL
  Remarks :  Function for file open to upload image
 **************************************************************/
BOOL CAddUpdateThread::OnFileOpen()
{
	// szFilters is a text string that includes two file name filters:
	// "*.my" for "MyType Files" and "*.*' for "All Files."
	TCHAR szFilters[] = _T("Image Files (*.BMP; *.JPG; *.GIF; *.JPEG; *.PNG)|*.png|All Files (*.*)|*.*||");

	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(TRUE, _T(""), _T("*.BMP; *.JPG; *.GIF; *.JPEG; *.PNG"),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		m_imagepath = fileDlg.GetPathName();

		// Implement opening and reading file in here.

		//Change the window's title to the opened file's title.
		CString fileName = fileDlg.GetFileTitle();
		return TRUE;
	}
	return FALSE;
}
/***************************************************************
  Function Name : AddUpdateThreadAPI
  Return Type : void
  Remarks : Function to load all forums 
 **************************************************************/
void CAddUpdateThread::AddUpdateThreadAPI()
{
	// TODO: Add your implementation code here.
#if TRUE
	m_ForumService->GetAllForums(m_InfoArray);
	CComboBox* Combo_dropdown = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_FORUM_NAME);
	Combo_dropdown->ResetContent();
	m_Forum_Id.RemoveAll();
	for (int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		Combo_dropdown->AddString(m_InfoArray[i].FormName);
		m_Forum_Id.Add(m_InfoArray[i].FormID);
	}
#else
	CString getAllForumId = _T("Api/Forum/GetAllForums");
	try
	{
		JSONValue* jvalue = NetworkRequest::GetReqEx(getAllForumId);
		std::wstring res = jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllForumId);
		JSONArray root = jvalue->AsArray();
		CComboBox *Combo_dropdown=(CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_FORUM_NAME);
		Combo_dropdown->ResetContent();
		m_Forum_Id.RemoveAll();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			CString strForumName(jobj[L"FormName"]->AsString().c_str());
			CString strForumID(jobj[L"FormID"]->AsString().c_str());
			m_Forum_Id.Add(strForumID);
			Combo_dropdown->AddString(strForumName);
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
BOOL CAddUpdateThread::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	AddUpdateThreadAPI();
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
/***************************************************************
  Function Name : OnCbnSelchangeComboExistingForumName
  Return Type : void
  Remarks : Function to load all topics of given forum
 **************************************************************/
void CAddUpdateThread::OnCbnSelchangeComboExistingForumName()
{
	// TODO: Add your control notification handler code here
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_FORUM_NAME);
	int Combo_Sel = Combodrop_down->GetCurSel();
	CListBox* List_box;
	List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_THREADS);
	List_box->ResetContent();
	CEdit* Edit_box;
	Edit_box = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_NAME);
	Edit_box->SetWindowText(_T(""));
	CEdit* Edit_box_desc;
	Edit_box_desc = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION);
	Edit_box_desc->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->SetWindowText(_T(""));
	CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
	CheckImage->SetCheck(0);
	m_pStream = 0;
	m_imagepath = _T("");
	Invalidate();
	if (Combo_Sel != CB_ERR)
	{
#if TRUE
		CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_TOPIC_NAME);
		Combodrop->ResetContent();
		infoArray.RemoveAll();
		m_ForumService->GetAllTopicsWithForumID(m_InfoArray[Combo_Sel].FormID, infoArray);
		for (int i = 0; i < infoArray.GetSize(); i++)
		{
			Combodrop->AddString(infoArray[i].Text);
			int iTopic_Id= infoArray[i].Value;
			m_Topic_Id.Add(iTopic_Id);
		}

#else
		CString getAllTopics;
		getAllTopics.Format(_T("Api/Forum/GetAllTopicsWithForumID?iForumId=%s"), m_Forum_Id[Combo_Sel]);
		try
		{
			JSONValue* jvalue = NetworkRequest::GetReqEx(getAllTopics);
			std::wstring res = jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllTopics);
			JSONArray root = jvalue->AsArray();
			CComboBox* Combodrop = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_TOPIC_NAME);
			Combodrop->ResetContent();
			m_Topic_Id.RemoveAll();
			for (unsigned int i = 0; i < root.size(); i++)
			{
				JSONObject Jobj = root[i]->AsObject();
				CString strTopic(Jobj[L"Text"]->AsString().c_str());
				Combodrop->AddString(strTopic);
				int iTopic_Id((int)Jobj[L"Value"]->AsNumber());
				m_Topic_Id.Add(iTopic_Id);
			}
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
  Function Name : OnCbnSelchangeComboExistingTopicName
  Return Type : void
  Remarks : Function to load all threads of given topic 
 **************************************************************/
void CAddUpdateThread::OnCbnSelchangeComboExistingTopicName()
{
	// TODO: Add your control notification handler code here
	
	CEdit* Edit_box;
	Edit_box = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_NAME);
	Edit_box->SetWindowText(_T(""));
	CEdit* Edit_box_desc;
	Edit_box_desc = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION);
	Edit_box_desc->SetWindowText(_T(""));
	CListBox* List_box;
	CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
	CheckImage->SetCheck(0);
	m_pStream = 0;
	m_imagepath = _T("");
	Invalidate();
	
	CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_EXISTING_TOPIC_NAME);
	int Combo_Sel = Combodrop_down->GetCurSel();
	if (Combo_Sel != CB_ERR)
	{
		List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_THREADS);
		int list_sel = List_box->GetCurSel();
		List_box->ResetContent();
#if TRUE
		infoArray.RemoveAll();
		CString TopicId;
		TopicId.Format(_T("%d"), m_Topic_Id[Combo_Sel]);
		m_ForumService->GetAllThreadsWithTopicID(TopicId, infoArray);
		m_Thread_Id.RemoveAll();
		for (int i = 0; i < infoArray.GetSize(); i++)
		{
			List_box->AddString(infoArray[i].Text);
			int iThread_Id = infoArray[i].Value;
			List_box->SetItemData(i, iThread_Id);
			m_Thread_Id.Add(iThread_Id);
		}
		CListBox* List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_THREADS);
		List_box->ModifyStyle(LBS_SORT, NULL);
#else
		try
		{
			CString getAllThreads;
			getAllThreads.Format(_T("Api/Forum/GetAllThreadsWithTopicID?strTopicID=%d"), m_Topic_Id[Combo_Sel]);
			JSONValue* jvalue = NetworkRequest::GetReqEx(getAllThreads);
			std::wstring res = jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllThreads);
			m_root = jvalue->AsArray();
			m_Thread_Id.RemoveAll();
			for (unsigned int i = 0; i < m_root.size(); i++)
			{
				JSONObject Jobj = m_root[i]->AsObject();
				CString strThread(Jobj[L"Text"]->AsString().c_str());
				JSONObject jobj = m_root[i]->AsObject();
				List_box->AddString(strThread);
				int iThread_Id((int)jobj[L"Value"]->AsNumber());
				List_box->SetItemData(i, iThread_Id);
				m_Thread_Id.Add(iThread_Id);

			}
			CListBox *List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_THREADS);
			List_box->ModifyStyle(LBS_SORT,NULL);
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
  Function Name : OnLbnSelchangeListExistingThreads
  Return Type : void
  Remarks : Function to load thread details 
 **************************************************************/
void CAddUpdateThread::OnLbnSelchangeListExistingThreads()
{
	// TODO: Add your control notification handler code here

	CListBox* List_box;
	List_box = (CListBox*)GetDlgItem(IDC_LIST_EXISTING_THREADS);
	int isel = List_box->GetCurSel();
	CString List_Curr_Sel_Data;
	List_box->GetText(isel, List_Curr_Sel_Data);

	CEdit* Edit_box;
	Edit_box = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_NAME);
	Edit_box->SetWindowText(List_Curr_Sel_Data);
	if (isel != CB_ERR)
	{
#if TRUE
		Infoarray.RemoveAll();
		CString ThreadId;
		ThreadId.Format(_T("%d"), m_Thread_Id[isel]);
		m_ForumService->GetThreadByID(ThreadId, Infoarray);
		CString str_Thread = Infoarray[0].ThreadDesc;
		m_strImage = Infoarray[0].ThreadImage;
		m_strName = Infoarray[0].ImageName;
		m_imagepath = _T("");
		ImageDecode(m_strImage);
		Invalidate();

		CEdit* Edit_box_desc;
		Edit_box_desc = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION);
		Edit_box_desc->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->SetWindowText(_T(""));
		Edit_box_desc->SetWindowText(str_Thread);
		CButton* Button_Add_New = (CButton*)GetDlgItem(IDC_BUTTON_ADD_NEW);
		Button_Add_New->ShowWindow(SW_SHOW);
		SetDlgItemText(IDOK, _T("Update"));
		CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
		SetDlgItemText(IDC_CHECK1, _T("Update Image"));
		
#else
		try
	{
		CString getAllThreads;
		getAllThreads.Format(_T("Api/Forum/GetThreadByID?strThreadID=%d"), m_Thread_Id[isel]);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllThreads);
		JSONObject root = Jvalue->AsObject();
		m_Root= Jvalue->AsObject();
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllThreads);
		CString str_Thread = root[L"ThreadDesc"]->AsString().c_str();
	    m_strImage = root[L"ThreadImage"]->AsString().c_str();
		m_strName = root[L"ImageName"]->AsString().c_str();
		m_imagepath =_T("");
		ImageDecode(m_strImage);
		Invalidate();
		
		CEdit* Edit_box_desc;
		Edit_box_desc = (CEdit*)GetDlgItem(IDC_EDIT_THREAD_DESCRIPTION);
		Edit_box_desc->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->SetWindowText(_T(""));
		Edit_box_desc->SetWindowText(str_Thread);
		CButton* Button_Add_New = (CButton*)GetDlgItem(IDC_BUTTON_ADD_NEW);
		Button_Add_New->ShowWindow(SW_SHOW);
		SetDlgItemText(IDOK, _T("Update"));
		CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
		SetDlgItemText(IDC_CHECK1,_T("Update Image"));
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
  Function Name : OnBnClickedButtonAddNew
  Return Type : void
  Remarks : Clearing the dialog box values to add new thread 
 **************************************************************/
void CAddUpdateThread::OnBnClickedButtonAddNew()
{
	// TODO: Add your control notification handler code here
	CButton* Button_Add_New = (CButton*)GetDlgItem(IDC_BUTTON_ADD_NEW);
	Button_Add_New->ShowWindow(SW_HIDE);
	SetDlgItemText(IDOK, _T("Add"));
	SetDlgItemText(IDC_EDIT_THREAD_NAME, _T(""));
	SetDlgItemText(IDC_EDIT_THREAD_DESCRIPTION, _T(""));
	GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->SetWindowText(_T(""));
	CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
	SetDlgItemText(IDC_CHECK1, _T("Upload Image"));
	CheckImage->SetCheck(0);
	m_pStream = 0;
	m_imagepath = _T("");
	Invalidate();
}
/***************************************************************
  Function Name : OnPaint
  Return Type : void
  Remarks : Function to draw the image in a thread 
 **************************************************************/
void CAddUpdateThread::OnPaint()
{
	
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialogEx::OnPaint() for painting messages
	
	CRect rect;
	CWnd* pWnd = this->GetDlgItem(IDC_STATIC_IMAGE);
	pWnd->GetWindowRect(&rect);
	this->ScreenToClient(&rect);
	CImage image;
	
	if (image.Load(m_imagepath) != E_FAIL || image.Load(m_pStream) != E_FAIL)
	{
		int height = image.GetHeight();
		int width = image.GetWidth();
		float ratio = (float)width / (float)height;
		int currHeight = rect.bottom - rect.top;
		int reqWidth =(int)(ratio * currHeight);
		int clrence = (rect.right - rect.left - reqWidth) / 2;
		rect.left += clrence;
		rect.right = rect.left + reqWidth;
		image.Draw(dc, rect);
	}

	

}
/***************************************************************
  Function Name : OnBnClickedCheck1
  Return Type : void
  Remarks : Function to set the state of image upload button 
 **************************************************************/
void CAddUpdateThread::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	CButton* CheckImage = (CButton*)GetDlgItem(IDC_CHECK1);
	bool state = CheckImage->GetState();
	CButton* Button_selectImage = (CButton*)GetDlgItem(IDC_BUTTON_SELECT_IMAGE);
	if (state)
	{
		Button_selectImage->EnableWindow(true);
	}
	else 
	{
		Button_selectImage->EnableWindow(false);
		GetDlgItem(IDC_EDIT_UPLOAD_IMAGE)->SetWindowText(_T(""));
		m_pStream = 0;
		m_imagepath = _T("");
		Invalidate();
	}
}
/***************************************************************
  Function Name : ImageDecode
  Return Type : void
  Parameters : strBase64 
  Remarks : Function to decode image from base64 format
 **************************************************************/
void CAddUpdateThread::ImageDecode(CString strBase64)
{
	std::string encodedImage = std::string(CT2CA (strBase64));

	std::string decodedImage = base64_decode(encodedImage);

	DWORD imageSize = (DWORD)decodedImage.length();
	HGLOBAL hMem = ::GlobalAlloc(GMEM_MOVEABLE, imageSize);
	LPVOID pImage = ::GlobalLock(hMem);
	memcpy(pImage, decodedImage.c_str(), imageSize);
	m_pStream = NULL;
	::CreateStreamOnHGlobal(hMem, FALSE, &m_pStream);

}
/***************************************************************
  Function Name : GetThreadId
  Return Type : int
  Parameters : strThreadName ,arr
  Remarks :  Function to get thread id for a particular thread
 **************************************************************/
int CAddUpdateThread::GetThreadId(CString strThreadName, JSONArray arr)
{
	int strThreadId;

	for (int i = 0; i < arr.size(); i++)
	{
		JSONObject obj = arr[i]->AsObject();
		CString strThread(obj[L"Text"]->AsString().c_str());
		if (strThread == strThreadName)
		{
			strThreadId = ((int)obj[L"Value"]->AsNumber());
			return strThreadId;
		}

	}

	return 0;

}
/*************************************************************************
  Function Name : GetTicksNow
  Return Type : CString
  Remarks : Function to get the tics corresponding to current date an time
 ************************************************************************/
CString CAddUpdateThread::GetTicksNow()
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