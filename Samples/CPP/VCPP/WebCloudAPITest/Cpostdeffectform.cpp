// Cpostdeffectform.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:Cpostdeffectform.cpp
	Description: . Implementation of Class Cpostdeffectform

	Copyright (C) 2022 KTS Computers
	All rights reserved.

	Author: Tom,LAKSHMI V
	Last Modtime:  09/06/2022
	Last Revision:
---------------------------------------------------------------------------*///

#include "pch.h"
#include "WebCloudAPITest.h"
#include "Cpostdeffectform.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// Cpostdeffectform dialog

IMPLEMENT_DYNAMIC(Cpostdeffectform, CDialogEx)

Cpostdeffectform::Cpostdeffectform(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_POSTADEFFECTFORM, pParent)
{

}

Cpostdeffectform::~Cpostdeffectform()
{
}

void Cpostdeffectform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SELECTLANGUAGE, m_ComboBox3);
	DDX_Control(pDX, IDC_SELECTASSIGNED, m_AssignedTo);
	DDX_Control(pDX, IDC_EDIT_ATTACHFILE, m_EditAttachFile);
}


BEGIN_MESSAGE_MAP(Cpostdeffectform, CDialogEx)
	ON_CBN_SELCHANGE(IDC_SELECTTOPIC, &Cpostdeffectform::OnCbnSelchangeComboSelectTopic)
	ON_CBN_SELCHANGE(IDC_SELECTLANGUAGE, &Cpostdeffectform::OnCbnSelchangeComboSelectLanguage)
	ON_CBN_SELCHANGE(IDC_SELECTASSIGNED, &Cpostdeffectform::OnCbnSelchangeComboSelectAssigned)
	ON_BN_CLICKED(IDC_BROWSEBUTTON, &Cpostdeffectform::OnBnClickedBrowseButton)
	ON_BN_CLICKED(IDC_POSTBUTTON, &Cpostdeffectform::OnBnClickedPostButton)
	ON_BN_CLICKED(IDC_CLOSEBUTTON, &Cpostdeffectform::OnBnClickedCloseButton)
END_MESSAGE_MAP()


// Cpostdeffectform message handlers

/*---------------------------------------------------------------------------
	Function Name: Cpostdeffectform::OnCbnSelchangeComboSelectTopic
	Return Value: Void
	Parameters:No parameters.
	Remarks:  Selection change event of ComboBox.
---------------------------------------------------------------------------*/
void Cpostdeffectform::OnCbnSelchangeComboSelectTopic()
{
	// TODO: Add your control notification handler code here
	//To select BugTopic
	/*CString addtopic;
	CString strFormType = (_T("DT"));
	addtopic.Format(_T("Api/DT/GetAllTopicsNameFromFormType?strFormType=%s"), strFormType);
	CComboBox* topiclist = (CComboBox*)GetDlgItem(IDC_SELECTTOPIC);*/
	int topic = m_TopicCombo->GetCurSel();
	if (topic != CB_ERR) {

		/*JSONValue* jval = NetworkRequest::GetReqEx(addtopic);
		JSONArray JArray = jval->AsArray();
		std::wstring res = jval->Stringify(true);
		CString resp(res.c_str());*/
		/*JSONObject jObjSelt = JArray[topic]->AsObject();*/
		TopicDetails Topic;
		Topic = TopicArray.GetAt(topic);

		//CString TopicDescription(jObjSelt[L"TopicDescription"]->AsString().c_str());
		GetDlgItem(IDC_TOPICDESCRIPTION)->SetWindowText(Topic.TopicDescription);

	}

}


void Cpostdeffectform::OnCbnSelchangeComboSelectLanguage()
{
	// TODO: Add your control notification handler code here
	//To Select Language

}


void Cpostdeffectform::OnCbnSelchangeComboSelectAssigned()
{

}

/*---------------------------------------------------------------------------
	Function Name: Cpostdeffectform::OnBnClickedBrowseButton
	Return Value:void
	Parameters:No parameters.
	Remarks:  ButtonClick Event for Browse button to select file.
---------------------------------------------------------------------------*/
void Cpostdeffectform::OnBnClickedBrowseButton()
{

	IFileOpenDialog* fileOpen;
	PWSTR pszFilePath;
	HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
		IID_IFileOpenDialog, reinterpret_cast<void**>(&fileOpen));

	if (SUCCEEDED(hr))
	{
		// Show the Open dialog box.
		hr = fileOpen->Show(NULL);

		// Get the file name from the dialog box.
		if (SUCCEEDED(hr))
		{
			IShellItem* pItem;
			hr = fileOpen->GetResult(&pItem);
			if (SUCCEEDED(hr))
			{
				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
				strFilePath = pszFilePath;
				pItem->Release();
			}
		}
	}
	DefectDetails defect;
	//defect.FileAttachment = NetworkRequest::ConvertToBase64(strFilePath);
	//defect.FilePath = PathFindFileName(strFilePath);
	//defect.FormType = defect.FileAttachment.Right(defect.FileAttachment.GetLength() - defect.FileAttachment.Find('.'));

	//m_attchmentList.Add(attachment);
	//defect.FormType = defect.FilePath.Right(AttachmentName.GetLength() - defect.FilePath.Find('.'));
	GetDlgItem(IDC_EDIT_ATTACHFILE)->SetWindowText(strFilePath);
}

/*---------------------------------------------------------------------------
	Function Name: Cpostdeffectform::OnBnClickedPostButton
	Return Value:void
	Parameters:No parameters.
	Remarks:  ButtonClick Event for PostThreadButton to POST
---------------------------------------------------------------------------*/
void Cpostdeffectform::OnBnClickedPostButton()
{    // TODO: Add your control notification handler code here
	
	TopicDetails DetailsList;

	GetDlgItem(IDC_SELECTLANGUAGE)->GetWindowText(defectdetails.BugLanguage);
	GetDlgItem(IDC_THREADDESCRIPTION)->GetWindowText(defectdetails.BugTaskDescription);
	GetDlgItem(IDC_EDIT_ATTACHFILE)->GetWindowText(strFilePath);
	GetDlgItem(IDC_EDIT_TITLE)->GetWindowText(defectdetails.BugTaskTitle);
	GetDlgItem(IDC_SELECTASSIGNED)->GetWindowText(defectdetails.BugAssignedTo);
	CComboBox* Combodrop_down1 = (CComboBox*)GetDlgItem(IDC_SELECTTOPIC);
	int Combo_Sel1 = Combodrop_down1->GetCurSel();
	m_apiService->GetAllTopicsNameFromFormType(TopicArray);
	int strTopicID;
	strTopicID = TopicArray[Combo_Sel1].TopicID;
	CComboBox* Combodrop_downAssigned = (CComboBox*)GetDlgItem(IDC_SELECTASSIGNED);
	int ComboAssignedSelect = Combodrop_downAssigned->GetCurSel();
	m_apiService->GetAssignedToList(TopicAssignedArray);
	defectdetails.BugAssignedToValue = TopicAssignedArray[ComboAssignedSelect].EmailId;
	defectdetails.Username = CWebCloudAPITestApp::GetUsername();
	defectdetails.FormType = _T("DT");
	defectdetails.TopicID = strTopicID;
	defectdetails.FilePath = PathFindFileName(strFilePath);
	defectdetails.FileAttachment = NetworkRequest::ConvertToBase64(strFilePath);
	m_apiService->PostThread(defectdetails);
}

/*---------------------------------------------------------------------------
	Function Name:Cpostdeffectform::OnInitDialog
	Return Value: Boolean
	Parameters:No parameters.
	Remarks:  Dialog-box initialization
---------------------------------------------------------------------------*/
BOOL Cpostdeffectform::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	PostADefectForm();
	selectAssigned();
	//selectLanguage();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

/*---------------------------------------------------------------------------
	Function Name:Cpostdeffectform::PostADefectForm
	Return Value: void
	Parameters:No parameters.
	Remarks:  Function to Get All topic Names in combobox .
---------------------------------------------------------------------------*/
void Cpostdeffectform::PostADefectForm()
{

	CString addtopic;
	addtopic.Format(_T("Api/DT/GetAllTopicsNameFromFormType?strFormType=DT"));
	m_TopicCombo = (CComboBox*)GetDlgItem(IDC_SELECTTOPIC);

	try
	{
		m_apiService->GetAllTopicsNameFromFormType(TopicArray);

		for (int i = 0; i < TopicArray.GetSize(); i++) {
			m_TopicCombo->AddString(TopicArray.GetAt(i).TopicName);
		}

		CWebCloudAPITestApp::SetRequestMSg(addtopic);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}
}
/*---------------------------------------------------------------------------
	Function Name:Cpostdeffectform::selectAssigned
	Return Value: void
	Parameters:No parameters.
	Remarks:  Function to Get bugs Assigned To List in combobox .
---------------------------------------------------------------------------*/
void Cpostdeffectform::selectAssigned()
{
	CString Assigne;
	//CString strFormType = (_T("DT"));
	Assigne.Format(_T("Api/DT/GetAssignedToList?strFormType=DT"));
	m_TaskAssigned = (CComboBox*)GetDlgItem(IDC_SELECTASSIGNED);
	try
	{
		m_apiService->GetAssignedToList(TopicAssignedArray);
		for (int i = 0; i < TopicAssignedArray.GetSize(); i++) {
			m_TaskAssigned->AddString(TopicAssignedArray.GetAt(i).Name);
			
		}

		CWebCloudAPITestApp::SetRequestMSg(Assigne);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}
}

void Cpostdeffectform::selectLanguage()
{
}


/*---------------------------------------------------------------------------
	Function Name: Cpostdeffectform::OnBnClickedCloseButton
	Return Value:void
	Parameters:No parameters.
	Remarks:  ButtonClick Event for closing window
---------------------------------------------------------------------------*/
void Cpostdeffectform::OnBnClickedCloseButton()
{
	// TODO: Add your control notification handler code here
	//
	CDialog::OnCancel();
}
