/*------------------------------------------------------------------------
  Workfile : CAdddelfooter.cpp
   Description : Implementation of Class  CAdddelfooter.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Chikku Clare Joseph
   Last Modified : 7 July 2022
-------------------------------------------------------------------------*/
// CAdddelfooter.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAdddelfooter.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// CAdddelfooter dialog

IMPLEMENT_DYNAMIC(CAdddelfooter, CDialogEx)

CAdddelfooter::CAdddelfooter(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDDELFOOTER, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CAdddelfooter::~CAdddelfooter()
{
}

void CAdddelfooter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListLink);
	DDX_Control(pDX, IDC_LIST2, lbox);
	DDX_Control(pDX, IDC_EDIT1, edit1);
}


BEGIN_MESSAGE_MAP(CAdddelfooter, CDialogEx)
	
	
	ON_BN_CLICKED(IDC_BUTTON1, &CAdddelfooter::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON3, &CAdddelfooter::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON5, &CAdddelfooter::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CAdddelfooter message handlers
BOOL CAdddelfooter::OnInitDialog()
{
	CString data;
	CDialogEx::OnInitDialog();
	AddListMenu();
	AddExistingFooter();
	return TRUE;
}

  /*--------------------------------------------------------------
  Function Name : AddListMenu
  Return Type : void
  Remarks : Function to display menuname
  --------------------------------------------------------------*/
void CAdddelfooter::AddListMenu()
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
  Function Name : AddExistingFooter
  Return Type : void
  Remarks : Function to display linkname
  --------------------------------------------------------------*/
void CAdddelfooter::AddExistingFooter()
{
	CListBox* ListFooters = (CListBox*)GetDlgItem(IDC_LIST1);

	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL, strLinkName;
		strSigninURL = ("api/Cms/GetAllFooters");
		m_apiService->GetAllFooters(m_footerInfo);


		for (int i = 0; i < m_footerInfo.GetSize(); i++)
		{
			ListFooters->AddString(m_footerInfo.GetAt(i).LinkName);
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
  Function Name : OnBnClickedButtonInsert
  Return Type : void
  Remarks : Function to insert new item
  --------------------------------------------------------------*/
void CAdddelfooter::OnBnClickedButtonInsert()
{
	
	CString strLinkName;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strLinkName);
	CString url, strMenuID;
	CListBox* lbox = (CListBox*)GetDlgItem(IDC_LIST2);
	int list_sel = lbox->GetCurSel();
	CString MenuID;
	MenuID.Format(_T("%d"), list_sel + 1);
	url.Format(_T("api/Cms/AddFooter?strLinkName=" + strLinkName + "&&strMenuID=" + MenuID));
	FooterDetails footer;
	footer.MenuID = MenuID;
	footer.LinkName = strLinkName;
	m_apiService->InvokeAddFooter(strLinkName, MenuID);
	}
	

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonRemove
  Return Type : void
  Remarks : Function to remove an item
  --------------------------------------------------------------*/
void CAdddelfooter::OnBnClickedButtonRemove()
{
	
	CListBox* ListLink = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = ListLink->GetCurSel();
	m_apiService->GetAllFooters(m_footerInfo);
	FooterDetails ftrinfo;
	for (int i = 0; i < m_footerInfo.GetSize(); i++)
	{
		ftrinfo = m_footerInfo[i];
	}
	m_apiService->DeleteHeaderFooter(ftrinfo.LinkID);

}

void CAdddelfooter::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
