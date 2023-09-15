/*------------------------------------------------------------------------
  Workfile : CListAllPageInfoWithLink.cpp
   Description : Implementation of Class  CListAllPageInfoWithLink.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 6 July 2022
-------------------------------------------------------------------------*/
// CListAllPageInfoWithLink.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CListAllPageInfoWithLink.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CListAllPageInfoWithLink dialog

IMPLEMENT_DYNAMIC(CListAllPageInfoWithLink, CDialogEx)

CListAllPageInfoWithLink::CListAllPageInfoWithLink(CWnd* pParent /*=nullptr*/)
        : CDialogEx(IDD_DIALOG_LISTALLPAGEINFOWITHLINKS, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CListAllPageInfoWithLink::~CListAllPageInfoWithLink()
{
}

void CListAllPageInfoWithLink::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}


BEGIN_MESSAGE_MAP(CListAllPageInfoWithLink, CDialogEx)
        ON_BN_CLICKED(IDCLOSE, &CListAllPageInfoWithLink::OnBnClickedClose)
END_MESSAGE_MAP()


// CListAllPageInfoWithLink message handlers
/*--------------------------------------------------------------
  Function Name : OnInitDialog
  Return Type : BOOL
  Remarks : Code fofr creating table like structure
  --------------------------------------------------------------*/
BOOL CListAllPageInfoWithLink::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_listctrl.InsertColumn(1, L"Menu ID", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(2, L"Parent ID", LVCFMT_CENTER, 80);
	m_listctrl.InsertColumn(3, L"Menu Name", LVCFMT_CENTER, 120);
	m_listctrl.InsertColumn(4, L"Show Menu", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(5, L"Menu Link", LVCFMT_CENTER, 300);
	m_listctrl.InsertColumn(6, L"Alias URL Link", LVCFMT_CENTER, 210);
	m_listctrl.InsertColumn(7, L"Page Heading", LVCFMT_CENTER, 150);

	GetAllPageInfoValue();
	return TRUE;
}
void CListAllPageInfoWithLink::OnBnClickedClose()
{
        // TODO: Add your control notification handler code here
    this->OnCancel();
}

/*--------------------------------------------------------------
  Function Name : GetAllPageInfoValue
  Return Type : void
  Remarks : Function to display items in list control
  --------------------------------------------------------------*/
void CListAllPageInfoWithLink::GetAllPageInfoValue()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle());
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetAllPageInfo");
		m_apiService->GetAllDetailedInfo(m_infoArray);
		for (int i = 0; i < m_infoArray.GetSize(); i++)
		{
			infomenu = m_infoArray[i];
			int Item;
			Item = m_listctrl.InsertItem(i, _T(""));
			CString strmenu;
			strmenu.Format(_T("%d"), infomenu.MenuID);
			
			CString strParentid;
			strParentid.Format(_T("%d"), infomenu.ParentID);
			
			CString strShowmenu;
			if (infomenu.ShowMenu == 1)
			{
				strShowmenu = "true";
			}
			if (infomenu.ShowMenu == 0)
			{
				strShowmenu = "false";
			}
			m_listctrl.SetItemText(Item, 0, strmenu);
			m_listctrl.SetItemText(Item, 1, strParentid);
			m_listctrl.SetItemText(Item, 2, infomenu.MenuName);
			m_listctrl.SetItemText(Item, 3, strShowmenu);
			m_listctrl.SetItemText(Item, 4, infomenu.MenuLink);
			m_listctrl.SetItemText(Item, 5, infomenu.AliasURLLink);
			m_listctrl.SetItemText(Item, 6, infomenu.PageHeading);
		}
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}
}




