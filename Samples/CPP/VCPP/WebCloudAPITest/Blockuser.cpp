/*------------------------------------------------------------------------
  Workfile : Blockuser.cpp
   Description : Implementation of Class  Blockuser.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chandradurga swaminathan
   Last Modified :20 June 2022
-------------------------------------------------------------------------*/
// Blockuser.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "afxdialogex.h"
#include "Blockuser.h"


// Blockuser dialog

IMPLEMENT_DYNAMIC(Blockuser, CDialogEx)

Blockuser::Blockuser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BLOCKUSER, pParent)
{
	jval = nullptr;
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;

}

Blockuser::~Blockuser()
{
}
/*---------------------------------------------------------------------------
	Function Name: Blockuser::DoDataExchange
	Return Value: Void
	Parameters:Pointer to CDataExchange class.
	Remarks:  Initialized ComboBox when dialog is created.
---------------------------------------------------------------------------*/

void Blockuser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO1_ACC_BLOCK);

	try
	{
		
			m_apiService->GetUserdetais(m_infoArray);
			SetWindowText(_T("ALL USER INFO"));
		


		//Initializing combobox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			Combo->AddString(m_infoArray.GetAt(i).FirstName);
		}

		//Showing Resquest data and Response data.
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);
	}
	
	
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);

	}
}


BEGIN_MESSAGE_MAP(Blockuser, CDialogEx)
	ON_BN_CLICKED(IDC_ACC_BUTTON_BLOCK_STATUS, &Blockuser::OnBnClickedAccButtonBlockStatus)
	ON_CBN_SELCHANGE(IDC_COMBO1_ACC_BLOCK, &Blockuser::OnCbnSelchangeCombo1AccBlock)
	
END_MESSAGE_MAP()


// Blockuser message handlers
/*---------------------------------------------------------------------------
	Function Name: Blockuser::OnBnClickedAccButtonBlockStatus
	Return Value: Void
	Remarks:  To block or unblock the selected user 
---------------------------------------------------------------------------*/

void Blockuser::OnBnClickedAccButtonBlockStatus()
{
	// TODO: Add your control notification handler code here
	CString btnText,btn;

	GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->GetWindowText(btnText);
	btn=btnText.MakeLower();
	

	BlockUserser blk;
		NetworkRequest::SetCloudUrl(strUrl);
		CString strSign = _T("api/Account/BlockORUnBlockUser");
		CWebCloudAPITestApp::SetStatusBarMsg(strSign);

		GetDlgItem(IDC_ACC_BLOCK_EMAIL_LABEL_VALUE)->GetWindowText(blk.Email);

		GetDlgItem(IDC_ACC_BLOCK_NAME_LABEL_VALUE)->GetWindowText(blk.FirstName);

		GetDlgItem(IDC_ACC_BLOCK_LAST_NAME_LABEL_VALUE)->GetWindowText(blk.LastName);
		GetDlgItem(IDC_ACC_BLOCK_PASSWORD_NAME_VALUE)->GetWindowText(blk.Password);

		GetDlgItem(IDC_ACC_BLOCK_PHONENO_LABEL_VALUE)->GetWindowText(blk.Phoneno);
		GetDlgItem(IDC_ACC_BLOCK_ADDRESS_LABEL_VALUE)->GetWindowText(blk.Address);
		 
		btn=m_apiService->Blockusersercive(btn);
		
			//GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->GetWindowText(Status);

			GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->SetWindowText(btn);

		
		
	
		return;

}


/*---------------------------------------------------------------------------
	Function Name: Blockuser::OnCbnSelchangeCombo1AccBlock
	Return Value: Void
	Remarks:  display selected user details from the combobox
---------------------------------------------------------------------------*/

void Blockuser::OnCbnSelchangeCombo1AccBlock()
{
	// TODO: Add your control notification handler code here

	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1_ACC_BLOCK);
	int list = comboid->GetCurSel();
	
		
			if (list != CB_ERR)
			{

				UserIn userDetail;
				userDetail = m_infoArray.GetAt(list);
			





		GetDlgItem(IDC_ACC_BLOCK_NAME_LABEL_VALUE)->SetWindowText(userDetail.FirstName);
		GetDlgItem(IDC_ACC_BLOCK_LAST_NAME_LABEL_VALUE)->SetWindowText(userDetail.LastName);
		GetDlgItem(IDC_ACC_BLOCK_PASSWORD_NAME_VALUE)->SetWindowText(userDetail.Password);

		GetDlgItem(IDC_ACC_BLOCK_EMAIL_LABEL_VALUE)->SetWindowText(userDetail.Email);

		GetDlgItem(IDC_ACC_BLOCK_PHONENO_LABEL_VALUE)->SetWindowText(userDetail.Phoneno);
		GetDlgItem(IDC_ACC_BLOCK_ADDRESS_LABEL_VALUE)->SetWindowText(userDetail.Address);
		GetDlgItem(IDC_ACC_BUTTON_BLOCK_STATUS)->SetWindowText(userDetail.Status);


	}



}


