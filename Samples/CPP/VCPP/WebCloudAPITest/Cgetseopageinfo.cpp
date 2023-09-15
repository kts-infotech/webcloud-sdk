/*------------------------------------------------------------------------
  Workfile : Cgetseopageinfo.cpp
   Description : Implementation of Class  Cgetseopageinfo.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 6 July 2022
-------------------------------------------------------------------------*/
// Cgetseopageinfo.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "Cgetseopageinfo.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// Cgetseopageinfo dialog

IMPLEMENT_DYNAMIC(Cgetseopageinfo, CDialogEx)

Cgetseopageinfo::Cgetseopageinfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GETSEOPAGEINFO, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

Cgetseopageinfo::~Cgetseopageinfo()
{
}
BOOL Cgetseopageinfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetSEOPageInfo();
	return TRUE;
}
void Cgetseopageinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, comboid);
	DDX_Control(pDX, IDC_LIST1, ListItem);
}


BEGIN_MESSAGE_MAP(Cgetseopageinfo, CDialogEx)

	ON_CBN_SELCHANGE(IDC_COMBO1, &Cgetseopageinfo::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

/*--------------------------------------------------------------
  Function Name : GetSEOPageInfo
  Return Type : void
  Remarks : Function to display menuid
  --------------------------------------------------------------*/
void Cgetseopageinfo::GetSEOPageInfo()
{
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);
	SeoPageDetails pageinfo;
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = ("api/Cms/GetSeoSettings");
		m_apiService->GetSeoSettings(m_seodetails);
		CString strMenuID;
		for (int i = 0; i < m_seodetails.GetSize(); i++)
		{
			pageinfo = m_seodetails[i];
			strMenuID.Format(L"%d", pageinfo.MenuID);
			comboid->AddString(strMenuID);
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
  Function Name : OnCbnSelchangeCombo1
  Return Type : void
  Remarks : Function for selecton change event of combobox.
  --------------------------------------------------------------*/
void Cgetseopageinfo::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int ComboSelItem = comboid->GetCurSel();
	if (ComboSelItem != CB_ERR)
	{
		SeoPageDetails pageinfo;
		pageinfo = m_seodetails.GetAt(ComboSelItem);
		ListItem.ResetContent();
		CString strMenuID;
		strMenuID.Format(L"%d", pageinfo.MenuID);
		ListItem.AddString(_T("Menu ID : ") + strMenuID);
		ListItem.AddString(_T("Default Page Title : ") + pageinfo.DefaultPageTitle);
		ListItem.AddString(_T("Default Meta Description : ") + pageinfo.DefaultMetaDescription);
		ListItem.AddString(_T("Default Meta Keywords : ") + pageinfo.DefaultMetaKeywords);
		CString isAliasing;
		if (pageinfo.IsAliasingEnabled == 1)
		{
			isAliasing = "true";
		}
		if (pageinfo.IsAliasingEnabled == 0)
		{
			isAliasing = "false";
		}
		ListItem.AddString(_T("Is Aliasing Enabled : ") + isAliasing);
	}
}
	




