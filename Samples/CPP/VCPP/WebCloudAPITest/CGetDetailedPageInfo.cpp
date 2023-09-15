/*------------------------------------------------------------------------
  Workfile : CGetDetailedPageInfo.cpp
   Description : Implementation of Class  CGetDetailedPageInfo.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 26 June 2022
-------------------------------------------------------------------------*/
// CGetDetailedPageInfo.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CGetDetailedPageInfo.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// CGetDetailedPageInfo dialog

IMPLEMENT_DYNAMIC(CGetDetailedPageInfo, CDialogEx)

CGetDetailedPageInfo::CGetDetailedPageInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GETDETAILEDPAGEINFO, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CGetDetailedPageInfo::~CGetDetailedPageInfo()
{
}

BOOL CGetDetailedPageInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString strMenuID;
	DetailedPageInfo();
	return TRUE;
}
void CGetDetailedPageInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTMENUWITHID, ListMenu);
	DDX_Control(pDX, IDC_LIST4, ListItem);
	DDX_Control(pDX, IDC_LIST5, ListDesc);
}


BEGIN_MESSAGE_MAP(CGetDetailedPageInfo, CDialogEx)
	ON_BN_CLICKED(IDCLOSE, &CGetDetailedPageInfo::OnBnClickedClose)
	ON_LBN_SELCHANGE(IDC_LISTMENUWITHID, &CGetDetailedPageInfo::OnLbnSelchangeListmenuwithid)
END_MESSAGE_MAP()


// CGetDetailedPageInfo message handlers


void CGetDetailedPageInfo::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}

/*--------------------------------------------------------------
  Function Name : DetailedPageInfo
  Return Type : void
  Remarks : Function to display MenuName with MenuID in the listbox.
  --------------------------------------------------------------*/
void CGetDetailedPageInfo::DetailedPageInfo()
{
      CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LISTMENUWITHID);
	try
	{
		//Get request.
		JSONValue* jval = NULL;
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
  Function Name : OnLbnSelchangeListmenuwithid
  Return Type : void
  Remarks : Function for selection change event of list box.
  --------------------------------------------------------------*/
void CGetDetailedPageInfo::OnLbnSelchangeListmenuwithid()
{
	// TODO: Add your control notification handler code here
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LISTMENUWITHID);
	int MenuListSelItem = ListMenu->GetCurSel();
	if (MenuListSelItem != LB_ERR)
	{
		MenuInfo infomenu;
		infomenu = m_infoArray.GetAt(MenuListSelItem);
		ListItem.ResetContent();
		CString strmenu;
		strmenu.Format(_T("%d"), infomenu.MenuID);
		ListItem.AddString(_T("Menu ID : ") + strmenu);
		ListItem.AddString(_T("Menu Name : ") + infomenu.MenuName);
		ListItem.AddString(_T("Menu Link : ") + infomenu.MenuLink);
		CString strParentid;
		strParentid.Format(_T("%d"), infomenu.ParentID);
		ListItem.AddString(_T("Parent ID : ") + strParentid);
		CString strShowmenu;
		if (infomenu.ShowMenu == 1)
		{
			strShowmenu = "true";
		}
		if(infomenu.ShowMenu == 0)
		{
			strShowmenu = "false";
		}
		ListItem.AddString(_T("Show Menu : ") + strShowmenu);
		CString strSuccess;
		if (infomenu.Success == 1)
		{
			strSuccess = "true";
		}
		if (infomenu.Success == 0)
		{
			strSuccess = "false";
		}
		ListItem.AddString(_T("Success : ") + strSuccess);
		ListItem.AddString(_T("Error Description : ") + infomenu.ErrorDec);


		ListDesc.ResetContent();
		ListDesc.AddString(infomenu.PageHeading);

	}
}



