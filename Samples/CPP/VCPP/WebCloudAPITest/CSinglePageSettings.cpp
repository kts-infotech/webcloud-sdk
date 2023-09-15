/*------------------------------------------------------------------------
  Workfile : CSinglePageSettings.cpp
   Description : Implementation of Class  CSinglePageSettings.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 6 July 2022
-------------------------------------------------------------------------*/
// CSinglePageSettings.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CSinglePageSettings.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"


// CSinglePageSettings dialog

IMPLEMENT_DYNAMIC(CSinglePageSettings, CDialogEx)

CSinglePageSettings::CSinglePageSettings(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SINGLEPAGESETTINGS, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CSinglePageSettings::~CSinglePageSettings()
{
}
BOOL CSinglePageSettings::OnInitDialog()
{
	SetSEOPageInfo();
	return TRUE;
}
void CSinglePageSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECKDEFAULT, checkboxDefault);
	DDX_Control(pDX, IDC_LIST1, ListMenu);
	DDX_Control(pDX, IDC_CHECK2, socialSharing);
	DDX_Control(pDX, IDC_CHECK7, enableWhatsapp);
}


BEGIN_MESSAGE_MAP(CSinglePageSettings, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SUPDATE, &CSinglePageSettings::OnBnClickedButtonSupdate)
	ON_BN_CLICKED(IDC_BUTTON_SRESET, &CSinglePageSettings::OnBnClickedButtonSreset)
	ON_LBN_SELCHANGE(IDC_LIST1, &CSinglePageSettings::OnLbnSelchangeList1)
END_MESSAGE_MAP()

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonSupdate
  Return Type : void
  Remarks : Function to update the values
  --------------------------------------------------------------*/
void CSinglePageSettings::OnBnClickedButtonSupdate()
{
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST1);
	int list_sel = ListMenu->GetCurSel();
	CString strSigninURL;
	strSigninURL == _T("api/Cms/GetAllPageInfo");
	m_apiService->GetAllDetailedInfo(m_infoArray);
	int strMenuID;
	SeoPageDetails info;
	strMenuID = m_infoArray[list_sel].MenuID;

	bool EnableSocialSharing = false, UseDefaultSeoDetails = false, EnableWhatsAppSharing = false, EnableFbSharing = false, EnableFTOSharing = false, EnableGooglePlusSharing = false, EnableTwitterSharing = false;
	CString strTitle, strDesc, strKeyword;
	CEdit* Title = (CEdit*)GetDlgItem(IDC_EDIT1);
	GetDlgItem(IDC_EDIT1)->GetWindowText(strTitle);
	CEdit* Description = (CEdit*)GetDlgItem(IDC_EDIT2);
	GetDlgItem(IDC_EDIT2)->GetWindowText(strDesc);
	CEdit* Keywords = (CEdit*)GetDlgItem(IDC_EDIT3);
	GetDlgItem(IDC_EDIT3)->GetWindowText(strKeyword);

	CButton* socialSharing = (CButton*)GetDlgItem(IDC_CHECK2);
	int check_box1 = socialSharing->GetCheck();
	if (check_box1 == BST_UNCHECKED)
		EnableSocialSharing = false;
	else if (check_box1 == BST_CHECKED)
		EnableSocialSharing = true;

	CButton* checkboxDefault = (CButton*)GetDlgItem(IDC_CHECKDEFAULT);
	int check_box2 = checkboxDefault->GetCheck();
	if (check_box2 == BST_UNCHECKED)
		UseDefaultSeoDetails = false;
	else if (check_box2 == BST_CHECKED)
		UseDefaultSeoDetails = true;

	CButton* enableWhatsapp = (CButton*)GetDlgItem(IDC_CHECK7);
	int check_box3 = enableWhatsapp->GetCheck();
	if (check_box3 == BST_UNCHECKED)
		EnableWhatsAppSharing = false;
	else if (check_box3 == BST_CHECKED)
		EnableWhatsAppSharing = true;

	CButton* enableFB = (CButton*)GetDlgItem(IDC_CHECK3);
	int check_box4 = enableFB->GetCheck();
	if (check_box4 == BST_UNCHECKED)
		EnableFbSharing = false;
	else if (check_box4 == BST_CHECKED)
		EnableFbSharing = true;

	CButton* enableFTO = (CButton*)GetDlgItem(IDC_CHECK4);
	int check_box5 = enableFTO->GetCheck();
	if (check_box5 == BST_UNCHECKED)
		EnableFTOSharing = false;
	else if (check_box5 == BST_CHECKED)
		EnableFTOSharing = true;

	CButton* enableGoogle = (CButton*)GetDlgItem(IDC_CHECK5);
	int check_box6 = enableGoogle->GetCheck();
	if (check_box6 == BST_UNCHECKED)
		EnableGooglePlusSharing = false;
	else if (check_box6 == BST_CHECKED)
		EnableGooglePlusSharing = true;

	CButton* enableTwitter = (CButton*)GetDlgItem(IDC_CHECK6);
	int check_box7 = enableTwitter->GetCheck();
	if (check_box7 == BST_UNCHECKED)
		EnableTwitterSharing = false;
	else if (check_box7 == BST_CHECKED)
		EnableTwitterSharing = true;
	
    info.MenuID = strMenuID;
	info.DefaultPageTitle = strTitle;
	info.DefaultMetaDescription = strDesc;
	info.DefaultMetaKeywords = strKeyword;
	info.SocialSharingSettings.EnableSocialSharing = EnableSocialSharing;
	info.UseDefaultSeoDetails = UseDefaultSeoDetails;
	info.SocialSharingSettings.EnableWhatsAppSharing = EnableWhatsAppSharing;
	info.SocialSharingSettings.EnableFbSharing = EnableFbSharing;
	info.SocialSharingSettings.EnableFTOSharing = EnableFTOSharing;
	info.SocialSharingSettings.EnableGooglePlusSharing = EnableGooglePlusSharing;
	info.SocialSharingSettings.EnableTwitterSharing = EnableTwitterSharing;
	for (int i = 0; i < m_seodetails.GetSize(); i++)
	{
	m_seodetails[i] = info;
	}
	m_apiService->SetSeoSettings(m_seodetails);
}
	

/*--------------------------------------------------------------
  Function Name : OnBnClickedButtonSreset
  Return Type : void
  Remarks : Function to reset the values
  --------------------------------------------------------------*/
void CSinglePageSettings::OnBnClickedButtonSreset()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	CButton* CheckAlias = (CButton*)GetDlgItem(IDC_CHECK2);
	CButton* enableWhatsapp = (CButton*)GetDlgItem(IDC_CHECK7);
	CButton* enableFB = (CButton*)GetDlgItem(IDC_CHECK3);
	CButton* enableFTO = (CButton*)GetDlgItem(IDC_CHECK4);
	CButton* enableGoogle = (CButton*)GetDlgItem(IDC_CHECK5);
	CButton* enableTwitter = (CButton*)GetDlgItem(IDC_CHECK6);
	CheckAlias->SetCheck(false);
	enableWhatsapp->SetCheck(false);
	enableFB->SetCheck(false);
	enableFTO->SetCheck(false);
	enableGoogle->SetCheck(false);
	enableTwitter->SetCheck(false);
}

/*--------------------------------------------------------------
  Function Name : SetSEOPageInfo
  Return Type : void
  Remarks : Function for adding MenuName to the listbox.
  --------------------------------------------------------------*/
void CSinglePageSettings::SetSEOPageInfo()
{
	CListBox* ListMenu = (CListBox*)GetDlgItem(IDC_LIST1);
	try
	{
		//Get request.
		JSONValue* jval = NULL;
		CString strSigninURL;
		strSigninURL = _T("api/Cms/GetAllPageInfo");
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
  Function Name : OnLbnSelchangeList1
  Return Type : void
  Remarks : Function for selection change event of List Box.
  --------------------------------------------------------------*/
void CSinglePageSettings::OnLbnSelchangeList1()
{
	CListBox* listBoxMenu = (CListBox*)GetDlgItem(IDC_LIST1);
	int MenuListSelItem = listBoxMenu->GetCurSel();
	if (MenuListSelItem != LB_ERR)
	{
		MenuInfo infomenu;
		infomenu = m_infoArray.GetAt(MenuListSelItem);
		CEdit* title = (CEdit*)GetDlgItem(IDC_EDIT4);
		GetDlgItem(IDC_EDIT4)->SetWindowText(infomenu.MenuName);

		SeoPageDetails pageinfo;
		try
		{
			//Get request.
			JSONValue* jval = NULL;
			CString strSigninURL;
			strSigninURL = ("api/Cms/GetSeoSettings");
			m_apiService->GetSeoSettings(m_seodetails);
			for (int i = 0; i < m_seodetails.GetSize(); i++)
			{
				pageinfo = m_seodetails[i];
				
				if (infomenu.MenuID == pageinfo.MenuID)
				{
					CEdit* Pagetitle = (CEdit*)GetDlgItem(IDC_EDIT1);
					GetDlgItem(IDC_EDIT1)->SetWindowText(pageinfo.DefaultPageTitle);
					CEdit* PageDesc = (CEdit*)GetDlgItem(IDC_EDIT2);
					GetDlgItem(IDC_EDIT2)->SetWindowText(pageinfo.DefaultMetaDescription);
					CEdit* PageKeywords = (CEdit*)GetDlgItem(IDC_EDIT3);
					GetDlgItem(IDC_EDIT3)->SetWindowText(pageinfo.DefaultMetaKeywords);
					CButton* checkboxDefault = (CButton*)GetDlgItem(IDC_CHECKDEFAULT);
					if (pageinfo.UseDefaultSeoDetails == true)
					{
						checkboxDefault->SetCheck(BST_CHECKED);
					}
					else
					{
						checkboxDefault->SetCheck(BST_UNCHECKED);
					}

					CButton* socialSharing = (CButton*)GetDlgItem(IDC_CHECK2);
					if (pageinfo.SocialSharingSettings.EnableSocialSharing == true)
					{
						socialSharing->SetCheck(BST_CHECKED);
					}
					else
					{
						socialSharing->SetCheck(BST_UNCHECKED);
					}

					CButton* enableWhatsapp = (CButton*)GetDlgItem(IDC_CHECK7);
					if (pageinfo.SocialSharingSettings.EnableWhatsAppSharing == true)
					{
						enableWhatsapp->SetCheck(BST_CHECKED);
					}
					else
					{
						enableWhatsapp->SetCheck(BST_UNCHECKED);
					}

					CButton* enableFB = (CButton*)GetDlgItem(IDC_CHECK3);
					if (pageinfo.SocialSharingSettings.EnableFbSharing == true)
					{
						enableFB->SetCheck(BST_CHECKED);
					}
					else
					{
						enableFB->SetCheck(BST_UNCHECKED);
					}

					CButton* enableFTO = (CButton*)GetDlgItem(IDC_CHECK4);
					if (pageinfo.SocialSharingSettings.EnableFTOSharing == true)
					{
						enableFTO->SetCheck(BST_CHECKED);
					}
					else
					{
						enableFTO->SetCheck(BST_UNCHECKED);
					}

					CButton* enableGoogle = (CButton*)GetDlgItem(IDC_CHECK5);
					if (pageinfo.SocialSharingSettings.EnableGooglePlusSharing == true)
					{
						enableGoogle->SetCheck(BST_CHECKED);
					}
					else
					{
						enableGoogle->SetCheck(BST_UNCHECKED);
					}

					CButton* enableTwitter = (CButton*)GetDlgItem(IDC_CHECK6);
					if (pageinfo.SocialSharingSettings.EnableTwitterSharing == true)
					{
						enableTwitter->SetCheck(BST_CHECKED);
					}
					else
					{
						enableTwitter->SetCheck(BST_UNCHECKED);
					}
				}
			}
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}
	}

}
	
	


