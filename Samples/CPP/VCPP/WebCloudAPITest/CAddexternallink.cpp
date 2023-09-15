/*------------------------------------------------------------------------
  Workfile : CAddexternallink.cpp
   Description : Implementation of Class  CAddexternallink.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 9 July 2022
-------------------------------------------------------------------------*/
// CAddexternallink.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddexternallink.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// CAddexternallink dialog

IMPLEMENT_DYNAMIC(CAddexternallink, CDialogEx)

CAddexternallink::CAddexternallink(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDEXTERNALLINK, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CAddexternallink::~CAddexternallink()
{
}

void CAddexternallink::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Link);
	DDX_Control(pDX, IDC_EDIT2, strLinkURL1);
	DDX_Control(pDX, IDC_EDIT7, strLinkName1);
	DDX_Control(pDX, IDC_CHECK1, CheckAlias);
}


BEGIN_MESSAGE_MAP(CAddexternallink, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddexternallink::OnBnClickedButtonUpdateTitle)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddexternallink::OnBnClickedButtonOrder)
	ON_BN_CLICKED(IDC_BUTTON6, &CAddexternallink::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON7, &CAddexternallink::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON8, &CAddexternallink::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON9, &CAddexternallink::OnBnClickedButtonClose)
	ON_LBN_SELCHANGE(IDC_LIST1, &CAddexternallink::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddexternallink::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddexternallink::OnBnClickedButtonDown)
END_MESSAGE_MAP()


// CAddexternallink message handlers
BOOL CAddexternallink::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetExternalLink();
	return TRUE;
}
/*--------------------------------------------------------------
  Function Name : GetExternalLink
  Return Type : void
  Remarks : Function to display title and linkname
  --------------------------------------------------------------*/
void CAddexternallink::GetExternalLink()
{
	JSONValue* jval = NULL;
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetExternalLinks");
	m_apiService->GetExternalLinkInfo(m_linkinfo);
	LinkSettingsInfo linksetinfo;
	CListBox* LinkName1 = (CListBox*)GetDlgItem(IDC_LIST1);
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		linksetinfo = m_linkinfo[i];
		CEdit* Link = (CEdit*)GetDlgItem(IDC_EDIT1);
		GetDlgItem(IDC_EDIT1)->SetWindowText(linksetinfo.ExternalLinkTitle);
		CButton* CheckAlias = (CButton*)GetDlgItem(IDC_CHECK1);
		CheckAlias->SetCheck(true);
		LinkName1->AddString(m_linkinfo.GetAt(i).linkinfo.LinkName);
	}
}

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonUpdateTitle
  Return Type : void
  Remarks : Function to update the title
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonUpdateTitle()
{
	// TODO: Add your control notification handler code here
	LinkSettingsInfo linkInfo;
	CString strSigninURL, strLinkID, strDefaultTitle;
	bool ShowInternalLink = false;
	CEdit* Link = (CEdit*)GetDlgItem(IDC_EDIT1);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strDefaultTitle);
	CButton* CheckAlias = (CButton*)GetDlgItem(IDC_CHECK1);
	CString checkconvert;
	int check1 = CheckAlias->GetCheck();
	linkInfo.ExternalLinkTitle = strDefaultTitle;
	linkInfo.ShowExternalLinks= check1;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		m_linkinfo[i] = linkInfo;
	}
	m_apiService->UpdateExternalLinkTitle(m_linkinfo);
}

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonOrder
  Return Type : void
  Remarks : Function to update the order of items 
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonOrder()
{
	JSONValue* jval = NULL;
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetExternalLinks");
	m_apiService->GetExternalLinkInfo(m_linkinfo);
	LinkSettingsInfo linksetinfo;
	CListBox* LinkName1 = (CListBox*)GetDlgItem(IDC_LIST1);
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		int Order = LinkName1->FindString(0, m_linkinfo[i].linkinfo.LinkName);
		CString strOrder;
		strOrder.Format(_T("%d"), Order);

		linksetinfo.linkinfo.MenuID = m_linkinfo[i].linkinfo.MenuID;
		linksetinfo.linkinfo.MenuName = m_linkinfo[i].linkinfo.MenuName;
		linksetinfo.linkinfo.LinkID = m_linkinfo[i].linkinfo.LinkID;
		linksetinfo.linkinfo.LinkName = m_linkinfo[i].linkinfo.LinkName;
		linksetinfo.linkinfo.LinkUrl = m_linkinfo[i].linkinfo.LinkUrl;
		linksetinfo.linkinfo.OrderNo = strOrder;
		linksetinfo.linkinfo.iOrderNo = Order;
		m_linkinfo[i] = linksetinfo;
	}
		m_apiService->UpdateOrderExternalLink(m_linkinfo);
}
	
/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonAdd
  Return Type : void
  Remarks : Function to insert new items
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonAdd()
{
	m_apiService->GetExternalLinkInfo(m_linkinfo);
	int counter = 0;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		counter = counter + 1;
	}
	CString strURL, strURLName, data;
	CEdit* strLinkURL = (CEdit*)GetDlgItem(IDC_EDIT2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(strURL);
	CEdit* strLinkName = (CEdit*)GetDlgItem(IDC_EDIT7);
	GetDlgItem(IDC_EDIT7)->GetWindowText(strURLName);
	LinkDetails link;
	link.LinkUrl = strURL;
	link.LinkName = strURLName;
	CString url = _T("api/Cms/AddExternalLink");
	CListBox* LinkName1 = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = LinkName1->GetCurSel();
	link.MenuID = _T("");
	link.MenuName = _T("");
	link.LinkID = _T("");
	CString strCounter;
	strCounter.Format(_T("%d"), counter);
	link.OrderNo = strCounter;
	link.iOrderNo = counter;
	m_apiService->AddExternalLink(link);
}
	
/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonUpdate
  Return Type : void
  Remarks : Function to update
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonUpdate()
{
	CListBox* ListLink = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = ListLink->GetCurSel();
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetExternalLinks");
	m_apiService->GetExternalLinkInfo(m_linkinfo);
	LinkSettingsInfo linksetinfo;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		linksetinfo = m_linkinfo[list_sel];
	}
	CString strURL, strURLName;
	CEdit* strLinkURL = (CEdit*)GetDlgItem(IDC_EDIT2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(strURL);
	CEdit* strLinkName = (CEdit*)GetDlgItem(IDC_EDIT7);
	GetDlgItem(IDC_EDIT7)->GetWindowText(strURLName);
	if (strURL == _T("") || strURLName == _T(""))
	{
		AfxMessageBox(_T("Please select a Link Name"));
		return;
	}
	LinkDetails linkinf;

	linkinf.LinkUrl = strURL;
	linkinf.LinkName = strURLName;
	linkinf.OrderNo = linksetinfo.linkinfo.OrderNo;
	linkinf.LinkID = linksetinfo.linkinfo.LinkID;
	CString url = _T("api/Cms/UpdateExternalLink");
	m_apiService->UpdateExternalLink(linkinf);
}
	
	
/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonRemove
  Return Type : void
  Remarks : Function to remove an item
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonRemove()
{
	CListBox* LinkName1 = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = LinkName1->GetCurSel();
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetExternalLinks");
	m_apiService->GetExternalLinkInfo(m_linkinfo);
	LinkSettingsInfo linksetinfo;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		linksetinfo = m_linkinfo[list_sel];
	}
	CString strURL;
	CEdit* strLinkURL = (CEdit*)GetDlgItem(IDC_EDIT2);
	strLinkURL->GetWindowText(strURL);
	int ans = 0;
	if (strURL == _T(""))
	{
		AfxMessageBox(_T("Please select any Link Name"));
		return;
	}
	else
	{
		ans = AfxMessageBox(_T("Are you sure you want to delete this Link Name"), MB_OKCANCEL);
		if (ans == IDCANCEL)
		{
			return;
		}
		LinkDetails link;
		link.LinkID = linksetinfo.linkinfo.LinkID;
		m_apiService->DeleteExternalLink(link);
	}
}

void CAddexternallink::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
/*--------------------------------------------------------------
  Function Name : OnLbnSelchangeList1
  Return Type : void
  Remarks : Function for selection change event of listbox.
  --------------------------------------------------------------*/
void CAddexternallink::OnLbnSelchangeList1()
{
	CListBox* LinkName1 = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = LinkName1->GetCurSel();

	if (list_sel != LB_ERR)
	{
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetExternalLinks");
		m_apiService->GetExternalLinkInfo(m_linkinfo);
		LinkSettingsInfo linksetinfo;
		for (int i = 0; i < m_linkinfo.GetSize(); i++)
		{
			linksetinfo = m_linkinfo[list_sel];
		}
		GetDlgItem(IDC_EDIT2)->SetWindowText(linksetinfo.linkinfo.LinkUrl);
		GetDlgItem(IDC_EDIT7)->SetWindowText(linksetinfo.linkinfo.LinkName);

	}
}
	
/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonUp
  Return Type : void
  Remarks : Function for moving items up in the list box.
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonUp()
{
	CString linkname;
	CListBox* Link = (CListBox*)GetDlgItem(IDC_LIST1);
	int isel = Link->GetCurSel();
	if (isel > 0)
	{
		CString strCurrent;
		Link->GetText(isel, strCurrent);
		Link->DeleteString(isel);
		Link->InsertString(isel - 1, strCurrent);
		Link->SetCurSel(isel - 1);
	}
}
/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonDown
  Return Type : void
  Remarks : Function for moving items down in the list box.
  --------------------------------------------------------------*/
void CAddexternallink::OnBnClickedButtonDown()
{
	// TODO: Add your control notification handler code here
	CListBox* Link = (CListBox*)GetDlgItem(IDC_LIST1);
	int isel = Link->GetCurSel();
	if (isel >= 0)
	{
		CString strCurrent;
		Link->GetText(isel, strCurrent);
		Link->DeleteString(isel);
		Link->InsertString(isel + 1, strCurrent);
		Link->SetCurSel(isel + 1);
	}

}




