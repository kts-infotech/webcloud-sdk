/*------------------------------------------------------------------------
  Workfile : GetAllExternalLinks.cpp
   Description : Implementation of Class  GetAllExternalLinks.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 6 July 2022
-------------------------------------------------------------------------*/
// GetAllExternalLinks.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "GetAllExternalLinks.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// GetAllExternalLinks dialog

IMPLEMENT_DYNAMIC(GetAllExternalLinks, CDialogEx)

GetAllExternalLinks::GetAllExternalLinks(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GETALLLINKS, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

GetAllExternalLinks::~GetAllExternalLinks()
{
}

void GetAllExternalLinks::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_EDIT1, m_strtitle);
	DDX_Control(pDX, IDC_SHOW, showLink);
}


BEGIN_MESSAGE_MAP(GetAllExternalLinks, CDialogEx)
	ON_BN_CLICKED(IDCLOSE, &GetAllExternalLinks::OnBnClickedClose)
END_MESSAGE_MAP()


// GetAllExternalLinks message handlers
/*--------------------------------------------------------------
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Code fofr creating table like structure
  --------------------------------------------------------------*/
BOOL GetAllExternalLinks::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_listctrl.InsertColumn(1, L"Link ID", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(2, L"Link URL", LVCFMT_CENTER, 170);
	m_listctrl.InsertColumn(3, L"Link Name", LVCFMT_CENTER, 130);
	m_listctrl.InsertColumn(4, L"Order No", LVCFMT_CENTER, 100);

	GetExternalLinksInfo();
	return TRUE;
}

/*--------------------------------------------------------------
  Function Name : GetExternalLinksInfo
  Return Type : void
  Remarks : Function to display item in list control
  --------------------------------------------------------------*/
void GetAllExternalLinks::GetExternalLinksInfo()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle());
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetExternalLinks");
		m_apiService->GetExternalLinkInfo(m_infoArray);
		LinkSettingsInfo linksetinfo;
		for (int i = 0; i < m_infoArray.GetSize(); i++)
		{
			linksetinfo = m_infoArray[i];
			CEdit* m_strtitle = (CEdit*)GetDlgItem(IDC_EDIT1);
			GetDlgItem(IDC_EDIT1)->SetWindowText(linksetinfo.ExternalLinkTitle);
			showLink.SetCheck(true);
			int Item;
			Item = m_listctrl.InsertItem(i, _T(""));

			m_listctrl.SetItemText(Item, 0, linksetinfo.linkinfo.LinkID);
			m_listctrl.SetItemText(Item, 1, linksetinfo.linkinfo.LinkUrl);
			m_listctrl.SetItemText(Item, 2, linksetinfo.linkinfo.LinkName);
			m_listctrl.SetItemText(Item, 3, linksetinfo.linkinfo.OrderNo);
		}
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
}

void GetAllExternalLinks::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
