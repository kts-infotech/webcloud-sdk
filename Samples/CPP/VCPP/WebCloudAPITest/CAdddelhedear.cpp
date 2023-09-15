/*------------------------------------------------------------------------
  Workfile : CAdddelhedear.cpp
   Description : Implementation of Class  CAdddelhedear.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 26 June 2022
-------------------------------------------------------------------------*/

// CAdddelhedear.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAdddelhedear.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// CAdddelhedear dialog

IMPLEMENT_DYNAMIC(CAdddelhedear, CDialogEx)

CAdddelhedear::CAdddelhedear(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDDELHEADER, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CAdddelhedear::~CAdddelhedear()
{
}

void CAdddelhedear::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, ListMenu);
}


BEGIN_MESSAGE_MAP(CAdddelhedear, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdddelhedear::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON3, &CAdddelhedear::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON5, &CAdddelhedear::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CAdddelhedear message handlers
BOOL CAdddelhedear::OnInitDialog()
{
	CString data;
	CDialogEx::OnInitDialog();
	AddListMenu();
	AddExistingHeader();
	return TRUE;
}
/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonInsert
  Return Type : void
  Remarks : Function to insert new item
  --------------------------------------------------------------*/
void CAdddelhedear::OnBnClickedButtonInsert()
{
	CString strLinkName;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strLinkName);
	CString url, strMenuID;
	CListBox* lbox = (CListBox*)GetDlgItem(IDC_LIST2);
	int list_sel = lbox->GetCurSel();
	CString MenuID;
	MenuID.Format(_T("%d"), list_sel + 1);
	url.Format(_T("api/Cms/AddHeader?strLinkName=" + strLinkName + "&&strMenuID=" + MenuID));
	HeaderDetails header;
	header.MenuID = MenuID;
	header.LinkName = strLinkName;
	m_apiService->InvokeAddHeader(strLinkName, MenuID);
}
	
/*--------------------------------------------------------------
  Function Name : AddListMenu
  Return Type : void
  Remarks : Function to display menuname
  --------------------------------------------------------------*/
void CAdddelhedear::AddListMenu()
{
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST2);
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL == _T("api/Cms/GetAllPageInfo");
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
	

/*--------------------------------------------------------------
  Function Name : AddExistingHeader
  Return Type : void
  Remarks : Function to display linkname
  --------------------------------------------------------------*/
void CAdddelhedear::AddExistingHeader()
{
	CListBox* ListFooters = (CListBox*)GetDlgItem(IDC_LIST1);

	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL, strLinkName;
		strSigninURL = ("api/Cms/GetAllHeaders");
		m_apiService->GetAllHeaders(m_headerInfo);


		for (int i = 0; i < m_headerInfo.GetSize(); i++)
		{
			ListFooters->AddString(m_headerInfo.GetAt(i).LinkName);
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
  Function Name : OnBnClickedButtonRemove
  Return Type : void
  Remarks : Function to remove an item
  --------------------------------------------------------------*/
void CAdddelhedear::OnBnClickedButtonRemove()
{
	CListBox* ListLink = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = ListLink->GetCurSel();
	m_apiService->GetAllHeaders(m_headerInfo);
	HeaderDetails headerinfo;
	for (int i = 0; i < m_headerInfo.GetSize(); i++)
	{
		headerinfo = m_headerInfo[i];
	}
	m_apiService->DeleteHeaderFooter(headerinfo.LinkID);
}


void CAdddelhedear::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
