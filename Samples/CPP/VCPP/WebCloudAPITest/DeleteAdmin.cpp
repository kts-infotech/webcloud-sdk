/*------------------------------------------------------------------------
  Workfile : DeleteAdmin.cpp
   Description : Implementation of Class  DeleteAdmin.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chandradurga swaminathan
   Last Modified :20 June 2022

-------------------------------------------------------------------------*/
// DeleteAdmin.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "afxdialogex.h"
#include "DeleteAdmin.h"


// DeleteAdmin dialog

IMPLEMENT_DYNAMIC(DeleteAdmin, CDialogEx)

DeleteAdmin::DeleteAdmin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETE_ADMIN, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

DeleteAdmin::~DeleteAdmin()
{
}
/*---------------------------------------------------------------------------
	Function Name: DeleteAdmin::DoDataExchange
	Return Value: Void
	Parameters:Pointer to CDataExchange class.
	Remarks:  Initialized ComboBox when dialog is created.
---------------------------------------------------------------------------*/

void DeleteAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	NetworkRequest::SetCloudUrl(strUrl);
	CString strSigninURL = _T("api/Account/GetAdminList");
	
	CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO1);

	try
	{
		//Get request.
		if (strSigninURL == _T("api/Account/GetAdminList"))
		{
			m_apiService->GetAdmindetais(m_infoArray);
			SetWindowText(_T("ALL USER INFO"));
		}
		//Initializing combobox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			Combo->AddString(m_infoArray.GetAt(i).Email);
		}

		//void AppApiService::GetAdmindetais(CArray<UserIn, UserIn>&InfoArray)

		//Initializing combobox.
		/*for (int i = 0; i < m_infoArray.GetSize(); i++) {
			comboid->AddString(m_infoArray.GetAt(i).Email);
		}*/

		//Showing Resquest data and Response data.
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}

}


BEGIN_MESSAGE_MAP(DeleteAdmin, CDialogEx)
	ON_BN_CLICKED(IDOK2, &DeleteAdmin::OnBnClickedOk2)
END_MESSAGE_MAP()


// DeleteAdmin message handlers

/*---------------------------------------------------------------------------
	Function Name: DeleteAdmin::OnBnClickedOk2
	Return Value: Void
	Remarks:   Function to insert new user details.
---------------------------------------------------------------------------*/



void DeleteAdmin::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
	NetworkRequest::SetCloudUrl(strUrl);
	CString strSigninURL = _T("api/Account/GetAdminList");
	// TODO: Add your control notification handler code here
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int list = comboid->GetCurSel();
	//int list = comboid->GetCurSel();
	if (list != CB_ERR)
	{

		UserIn userDetail;
		userDetail = m_infoArray.GetAt(list);
		Deleteuser user;
		//user.Email=
		m_apiService->Deleteuserdetail(list);




	}
	/*if (list != CB_ERR)
	{
		JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

		JSONArray arr = jval->AsArray();

		JSONObject obj = arr[list]->AsObject();



		CString Emai(obj[L"Email"]->AsString().c_str());
		CString email = Emai;
		url.Format(_T("api/Account/DeleteAdmin?email=%s"), email);

		try
		{
			JSONValue* jval = NetworkRequest::GetReqEx(url);

			std::wstring res = jval->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			AfxMessageBox(errorStr);
		}
	}*/

}
