/*------------------------------------------------------------------------
  Workfile : CSetseopageinfo.cpp
   Description : Implementation of Class  CSetseopageinfo.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 26 June 2022
-------------------------------------------------------------------------*/
// CSetseopageinfo.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CSetseopageinfo.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CSetseopageinfo dialog

IMPLEMENT_DYNAMIC(CSetseopageinfo, CDialogEx)

CSetseopageinfo::CSetseopageinfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETSEOPAGEINFO, pParent)
{

}

CSetseopageinfo::~CSetseopageinfo()
{
}

void CSetseopageinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
	//DDX_Control(pDX, IDC_LIST2, listBoxMenu);
}


BEGIN_MESSAGE_MAP(CSetseopageinfo, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CSetseopageinfo::OnTcnSelchangeTab1)
	//ON_BN_CLICKED(IDCLOSE, &CSetseopageinfo::OnBnClickedClose)
	ON_BN_CLICKED(IDC_BUTTONCLOSE, &CSetseopageinfo::OnBnClickedButtonclose)
END_MESSAGE_MAP()


/*--------------------------------------------------------------
  Function Name : OnInitDialog
  Return Type : void
  Remarks : Code for Tab Control
  --------------------------------------------------------------*/
BOOL CSetseopageinfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTabCtrl* pTabCtrl1 = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	m_tab1.Create(IDD_DEFAULT, pTabCtrl1);
	CTabCtrl* pTabCtrl2 = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	m_tab2.Create(IDD_SINGLEPAGESETTINGS, pTabCtrl2);

	TCITEM item1,item2;
	item1.mask = TCIF_TEXT | TCIF_PARAM;
	item1.lParam = (LPARAM)&m_tab1;
	item1.pszText = _T("Default Settings");
	pTabCtrl1->InsertItem(0, &item1);

	item2.mask = TCIF_TEXT | TCIF_PARAM;
	item2.lParam = (LPARAM)&m_tab2;
	item2.pszText = _T("Single Page Settings");
	pTabCtrl2->InsertItem(1, &item2);

	CRect rcItem1;
	pTabCtrl1->GetItemRect(0, &rcItem1);
	m_tab1.SetWindowPos(NULL, rcItem1.left, rcItem1.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CRect rcItem2;
	pTabCtrl2->GetItemRect(0, &rcItem2);
	m_tab2.SetWindowPos(NULL, rcItem2.left, rcItem2.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
	m_tab1.ShowWindow(SW_SHOW);
	m_tab2.ShowWindow(SW_HIDE);
	//SetSEOPageInfo();
	
	return TRUE;
}

/*--------------------------------------------------------------
  Function Name : OnTcnSelchangeTab1
  Return Type : void
  Remarks : Function for selection change event of Tab Control.
  --------------------------------------------------------------*/
void CSetseopageinfo::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	int iSel = m_tabctrl.GetCurSel();

	if (iSel == 0)
	{
		m_tab1.ShowWindow(SW_SHOW);
		m_tab2.ShowWindow(SW_HIDE);
	}
	else if(iSel == 1)
	{
		m_tab2.ShowWindow(SW_SHOW);
		m_tab1.ShowWindow(SW_HIDE);
	}
}


void CSetseopageinfo::OnBnClickedButtonclose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
