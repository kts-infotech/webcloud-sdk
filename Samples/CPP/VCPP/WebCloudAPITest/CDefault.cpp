/*------------------------------------------------------------------------
  Workfile : CDefault.cpp
   Description : Implementation of Class  CDefault.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 6 July 2022
-------------------------------------------------------------------------*/
// CDefault.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CDefault.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CDefault dialog

IMPLEMENT_DYNAMIC(CDefault, CDialogEx)

CDefault::CDefault(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEFAULT, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CDefault::~CDefault()
{
}

void CDefault::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, ListMenu);
	DDX_Control(pDX, IDC_CHECK1, CheckAlias);
}


BEGIN_MESSAGE_MAP(CDefault, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CDefault::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CDefault::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// CDefault message handlers
BOOL CDefault::OnInitDialog()
{
	DefaultSEOSettings();
	SetSEOPageInfo();
	return TRUE;
}

/*--------------------------------------------------------------
  Function Name : DefaultSEOSettings
  Return Type : void
  Remarks : Function to display default settings
  --------------------------------------------------------------*/
void CDefault::DefaultSEOSettings()
{

	//Get request.
	try
	{
		SeoPageDetails pageInfo;
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetDefaultSEOSettings");
		m_apiService->GetDefaultSeoSettings(m_seoArray);
		for (int i = 0; i < m_seoArray.GetSize(); i++)
		{
			pageInfo = m_seoArray[i];
			GetDlgItem(IDC_EDIT1)->SetWindowText(pageInfo.DefaultPageTitle);
			GetDlgItem(IDC_EDIT2)->SetWindowText(pageInfo.DefaultMetaDescription);
			GetDlgItem(IDC_EDIT3)->SetWindowText(pageInfo.DefaultMetaKeywords);
			CButton* CheckAlias = (CButton*)GetDlgItem(IDC_CHECK1);
			if (pageInfo.IsAliasingEnabled == 1)
			{
				CheckAlias->SetCheck(1);
			}
			else
			{
				CheckAlias->SetCheck(0);
			}
		}
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
}

/*--------------------------------------------------------------
Function Name : OnBnClickedButtonUpdate
Return Type : void
Remarks : Function to update default values
--------------------------------------------------------------*/
void CDefault::OnBnClickedButtonUpdate()
{
	CString strTitle, strDesc, strKeyword;
	CEdit* Title = (CEdit*)GetDlgItem(IDC_EDIT1);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strTitle);
	CEdit* Description = (CEdit*)GetDlgItem(IDC_EDIT2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(strDesc);
	CEdit* Keywords = (CEdit*)GetDlgItem(IDC_EDIT3);
	GetDlgItem(IDC_EDIT3)->GetWindowText(strKeyword);
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST2);
	int list_sel = ListMenu->GetCurSel();

	SeoPageDetails seopage;
	seopage.DefaultPageTitle = strTitle;
	seopage.DefaultMetaDescription = strDesc;
	seopage.DefaultMetaKeywords = strKeyword;
	CString url = _T("api/Cms/SetSeoInfo");
	m_apiService->SetSeoSettings(m_seoArray);
	// TODO: Add your control notification handler code here
	/*CString strTitle, strDesc, strKeyword;
		CEdit* Title = (CEdit*)GetDlgItem(IDC_EDIT1);
		GetDlgItem(IDC_EDIT1)->GetWindowText(strTitle);
		CEdit* Description = (CEdit*)GetDlgItem(IDC_EDIT2);
		GetDlgItem(IDC_EDIT2)->GetWindowText(strDesc);
		CEdit* Keywords = (CEdit*)GetDlgItem(IDC_EDIT3);
		GetDlgItem(IDC_EDIT3)->GetWindowText(strKeyword);
		CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST2);
		int list_sel = ListMenu->GetCurSel();
	
		CString DefaultPageTitle = strTitle;
		CString DefaultMetaDescription = strDesc;
		CString DefaultMetaKeywords = strKeyword;
	
		CString url = _T("api/Cms/SetSeoInfo");
		CString data;
		JSONObject obj;
		obj[L"DefaultPageTitle"] = new JSONValue(std::wstring(DefaultPageTitle));
		obj[L"DefaultMetaDescription"] = new JSONValue(std::wstring(DefaultMetaDescription));
		obj[L"DefaultMetaKeywords"] = new JSONValue(std::wstring(DefaultMetaKeywords));
		
		JSONValue* val = new JSONValue(obj);
		std::wstring res = val->Stringify(false);
		data = CString(res.c_str());
	
			try
			{
				CWebCloudAPITestApp::SetRequestMSg(data);
				JSONValue* Defaultjval = NetworkRequest::PostReq(url, data);
				std::wstring res = Defaultjval->Stringify(true);
				CString cstrRes(res.c_str());
				CWebCloudAPITestApp::SetResponseMsg(cstrRes);
				AfxMessageBox(cstrRes);
			}
			catch (const std::exception& e)
			{
				CString errorStr(e.what());
				AfxMessageBox(errorStr);
			}*/
}

/*--------------------------------------------------------------
Function Name : OnBnClickedButtonReset
Return Type : void
Remarks : Function to clear the values
--------------------------------------------------------------*/
void CDefault::OnBnClickedButtonReset()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	CButton* CheckAlias = (CButton*)GetDlgItem(IDC_CHECK1);
	CheckAlias->SetCheck(false);
}

/*--------------------------------------------------------------
  Function Name : SetSEOPageInfo
  Return Type : void
  Remarks : Function for adding MenuName to the listbox.
  --------------------------------------------------------------*/
void CDefault::SetSEOPageInfo()
{
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST4);
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetAllPageInfo");
		m_apiService->GetAllDetailedInfo(m_infoArray);


		for (int i = 0; i < m_infoArray.GetSize(); i++)
		{
			ListMenu->AddString(m_infoArray.GetAt(i).MenuName);
		}
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
}
	