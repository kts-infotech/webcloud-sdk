/*------------------------------------------------------------------------
  Workfile : GetAllInternalLinks.cpp
   Description : Implementation of Class  GetAllInternalLinks.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 6 July 2022
-------------------------------------------------------------------------*/
// GetAllInternalLinks.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "GetAllInternalLinks.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// GetAllInternalLinks dialog

IMPLEMENT_DYNAMIC(GetAllInternalLinks, CDialogEx)

GetAllInternalLinks::GetAllInternalLinks(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GetAllInternalLinks, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

GetAllInternalLinks::~GetAllInternalLinks()
{
}

void GetAllInternalLinks::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_EDIT1, m_strtitle);
	DDX_Control(pDX, IDC_CHECK1, showLink);
}


BEGIN_MESSAGE_MAP(GetAllInternalLinks, CDialogEx)
	ON_BN_CLICKED(IDCLOSE, &GetAllInternalLinks::OnBnClickedClose)
	
END_MESSAGE_MAP()


// GetAllInternalLinks message handlers
/*--------------------------------------------------------------
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Code fofr creating table like structure
  --------------------------------------------------------------*/
BOOL GetAllInternalLinks::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_listctrl.InsertColumn(1, L"MenuID", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(2, L"MenuID", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(3, L"MenuName", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(4, L"LinkName", LVCFMT_CENTER, 100);

	GetInternalLinksInfo();
	return TRUE;
}

/*--------------------------------------------------------------
  Function Name : GetInternalLinksInfo
  Return Type : void
  Remarks : Function to display items in list control
  --------------------------------------------------------------*/
void GetAllInternalLinks::GetInternalLinksInfo()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle());
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetInternalLinks");
		m_apiService->GetInternalLinkInfo(m_infoArray);
		LinkSettingsInfo linksetinfo;
		for (int i = 0; i < m_infoArray.GetSize(); i++)
		{
			linksetinfo = m_infoArray[i];
			CEdit* m_strtitle = (CEdit*)GetDlgItem(IDC_EDIT1);
			GetDlgItem(IDC_EDIT1)->SetWindowText(linksetinfo.InternalLinkTitle);
			showLink.SetCheck(true);
			int nItem;
			nItem = m_listctrl.InsertItem(i, _T(""));

			m_listctrl.SetItemText(nItem, 0, linksetinfo.linkinfo.LinkID);
			m_listctrl.SetItemText(nItem, 1, linksetinfo.linkinfo.MenuID);
			m_listctrl.SetItemText(nItem, 2, linksetinfo.linkinfo.MenuName);
			m_listctrl.SetItemText(nItem, 3, linksetinfo.linkinfo.LinkName);
		}
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}

}
void GetAllInternalLinks::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}


