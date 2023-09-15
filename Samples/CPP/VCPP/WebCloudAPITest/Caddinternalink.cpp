/*------------------------------------------------------------------------
  Workfile : Caddinternalink.cpp
   Description : Implementation of Class  Caddinternalink.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 11 July 2022
-------------------------------------------------------------------------*/
// Caddinternalink.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "Caddinternalink.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// Caddinternalink dialog

IMPLEMENT_DYNAMIC(Caddinternalink, CDialogEx)

Caddinternalink::Caddinternalink(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDINTERNALLINK, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

Caddinternalink::~Caddinternalink()
{
}

void Caddinternalink::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListMenu);
	DDX_Control(pDX, IDC_LIST3, LinkName);
	DDX_Control(pDX, IDC_CHECK1, ShowLink);
	DDX_Control(pDX, IDC_EDIT1, Link);
	DDX_Control(pDX, IDC_EDIT2, Edit1);
}


BEGIN_MESSAGE_MAP(Caddinternalink, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON10, &Caddinternalink::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON1, &Caddinternalink::OnBnClickedButtonUpdateTitle)
	ON_BN_CLICKED(IDC_BUTTON3, &Caddinternalink::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON5, &Caddinternalink::OnBnClickedButtonRemove)
	ON_BN_CLICKED(IDC_BUTTON9, &Caddinternalink::OnBnClickedButtonUpdate)
	
	ON_LBN_SELCHANGE(IDC_LIST3, &Caddinternalink::OnLbnSelchangeList3)
END_MESSAGE_MAP()


// Caddinternalink message handlers
BOOL Caddinternalink::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DisplayMenuNames();
	GetInternalLink();
	return TRUE;
}

/*--------------------------------------------------------------
  Function Name : DisplayMenuNames
  Return Type : void
  Remarks : Function to display menu names in the list box.
  --------------------------------------------------------------*/
void Caddinternalink::DisplayMenuNames()
{
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST1);
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
  Function Name : GetInternalLink
  Return Type : void
  Remarks : Function to display title and linkname.
  --------------------------------------------------------------*/
void Caddinternalink::GetInternalLink()
{
	JSONValue* jval = NULL;
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetInternalLinks");
	m_apiService->GetInternalLinkInfo(m_linkinfo);
	LinkSettingsInfo linksetinfo;
	CListBox* LinkName = (CListBox*)GetDlgItem(IDC_LIST3);
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		linksetinfo = m_linkinfo[i];
		CEdit* Link = (CEdit*)GetDlgItem(IDC_EDIT1);
		GetDlgItem(IDC_EDIT1)->SetWindowText(linksetinfo.InternalLinkTitle);
		ShowLink.SetCheck(true);
		LinkName->AddString(m_linkinfo.GetAt(i).linkinfo.LinkName);
	}
}

void Caddinternalink::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonUpdateTitle
  Return Type : void
  Remarks : Function to update the title displayed in the listbox.
  --------------------------------------------------------------*/
void Caddinternalink::OnBnClickedButtonUpdateTitle()
{
	// TODO: Add your control notification handler code here
	LinkSettingsInfo linkInfo;
	CString strSigninURL, strLinkID, strDefaultTitle;
	bool ShowInternalLink = false;
	CEdit* Link = (CEdit*)GetDlgItem(IDC_EDIT1);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strDefaultTitle);
	CButton* ShowLink = (CButton*)GetDlgItem(IDC_CHECK1);
	CString checkconvert;
	int check1 = ShowLink->GetCheck();
	linkInfo.InternalLinkTitle = strDefaultTitle;
	linkInfo.ShowInternalLink = check1;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		m_linkinfo[i] = linkInfo;
	}
	m_apiService->UpdateInternalLinkTitle(m_linkinfo);
	
}

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonInsert
  Return Type : void
  Remarks : Function to insert the item.
  --------------------------------------------------------------*/
void Caddinternalink::OnBnClickedButtonInsert()
{
	m_apiService->GetInternalLinkInfo(m_linkinfo);
	int counter = 0;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		counter = counter + 1;
	}
	CString strLinkName, data;
	CEdit* Edit1 = (CEdit*)GetDlgItem(IDC_EDIT2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(strLinkName);
	LinkDetails link;
	link.LinkName = strLinkName;
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = ListMenu->GetCurSel();
	link.MenuID = _T("");
	CString strMenuName;
	ListMenu->GetText(ListMenu->GetCurSel(), strMenuName);
	
	if (strMenuName == _T(""))
	{
		AfxMessageBox(_T("Please select MenuName from list"));
		return;
	}
	else
	{
		link.MenuName = strMenuName;
	}
	link.LinkID = _T("");
	CString strCounter;
	strCounter.Format(_T("%d"), counter);
	link.OrderNo = strCounter;
	link.iOrderNo = counter;
	if (strLinkName == _T(""))
	{
		AfxMessageBox(_T("Please Enter Title"));
		return;
	}
	else
	{
		LinkName.AddString(strLinkName);
		AfxMessageBox(L"Inserted Successfully");
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	}
}

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonRemove
  Return Type : void
  Remarks : Function to delete the item.
  --------------------------------------------------------------*/
void Caddinternalink::OnBnClickedButtonRemove()
{
	// TODO: Add your control notification handler code here
	int ans = 0;
	CListBox* LinkName = (CListBox*)GetDlgItem(IDC_LIST3);
	int list_sel = LinkName->GetCurSel();
	ans = AfxMessageBox(_T("Are you sure you want to delete this Title"), MB_OKCANCEL);
	if (ans == IDCANCEL)
	{
		return;
	}
	else
	{
		CEdit* Edit1 = (CEdit*)GetDlgItem(IDC_EDIT2);
		LinkName->DeleteString(list_sel);
	}
}

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonUpdate
  Return Type : void
  Remarks : Function to update the item.
  --------------------------------------------------------------*/
void Caddinternalink::OnBnClickedButtonUpdate()
{
	// TODO: Add your control notification handler code here
	CListBox* LinkName = (CListBox*)GetDlgItem(IDC_LIST3);
	int list_sel = LinkName->GetCurSel();
	CString strSigninURL;
	strSigninURL = _T("api/Cms/GetInternalLinks");
	m_apiService->GetInternalLinkInfo(m_linkinfo);
	LinkSettingsInfo linksetinfo;
	for (int i = 0; i < m_linkinfo.GetSize(); i++)
	{
		linksetinfo = m_linkinfo[list_sel];
	}
	CString strLinkName;
	CEdit* Edit1 = (CEdit*)GetDlgItem(IDC_EDIT2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(strLinkName);
	if (strLinkName == _T(""))
	{
		AfxMessageBox(_T("Please select a Link Name"));
		return;
	}
	LinkDetails linkinf;

	linkinf.LinkUrl = linksetinfo.linkinfo.LinkUrl;
	linkinf.LinkName = strLinkName;
	linkinf.OrderNo = linksetinfo.linkinfo.OrderNo;
	linkinf.LinkID = linksetinfo.linkinfo.LinkID;
	CString url = _T("api/Cms/UpdateInternalLink");
	m_apiService->UpdateInternalLink(linkinf);
}

/*--------------------------------------------------------------
  Function Name : OnLbnSelchangeList3
  Return Type : void
  Remarks : Function for selection change event of listbox.
  --------------------------------------------------------------*/
void Caddinternalink::OnLbnSelchangeList3()
{
	// TODO: Add your control notification handler code here
	CListBox* LinkName = (CListBox*)GetDlgItem(IDC_LIST3);
	int list_sel = LinkName->GetCurSel();

	if (list_sel != LB_ERR)
	{
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetInternalLinks");
		m_apiService->GetInternalLinkInfo(m_linkinfo);
		LinkSettingsInfo linksetinfo;
		for (int i = 0; i < m_linkinfo.GetSize(); i++)
		{
			linksetinfo = m_linkinfo[list_sel];
		}
		GetDlgItem(IDC_EDIT2)->SetWindowText(linksetinfo.linkinfo.LinkName);
		

	}
}
