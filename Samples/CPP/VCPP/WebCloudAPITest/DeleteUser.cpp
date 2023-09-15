/*------------------------------------------------------------------------
  Workfile : DeleteUser.cpp
   Description : Implementation of Class  DeleteUser.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author :Chandradurga swaminathan
   Last Modified : 20 June 2022

-------------------------------------------------------------------------*/
// DeleteUser.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "afxdialogex.h"
#include "DeleteUser.h"


// DeleteUser dialog

IMPLEMENT_DYNAMIC(DeleteUser, CDialogEx)

DeleteUser::DeleteUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETE, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;

}

DeleteUser::~DeleteUser()
{
}
/*---------------------------------------------------------------------------
	Function Name: DeleteUser::DoDataExchange
	Return Value: Void
	Parameters:Pointer to CDataExchange class.
	Remarks:  Initialized ComboBox when dialog is created.
---------------------------------------------------------------------------*/

void DeleteUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	NetworkRequest::SetCloudUrl(strUrl);
	CString strSigninURL = _T("api/Account/GetUserList");
	CComboBox* Combo = (CComboBox*)GetDlgItem(IDC_COMBO1_DELETEUSER);


	
	try
	{
		//Get request.
		if (strSigninURL == _T("api/Account/GetUserList"))
		{
			m_apiService->GetUserdetais(m_infoArray);
			SetWindowText(_T("Delete User"));
		}


		//Initializing combobox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			Combo->AddString(m_infoArray.GetAt(i).Email);
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


BEGIN_MESSAGE_MAP(DeleteUser, CDialogEx)
	ON_BN_CLICKED(ID_DELETE, &DeleteUser::OnBnClickedDelete1)
END_MESSAGE_MAP()
/*---------------------------------------------------------------------------
	Function Name: DeleteUser::OnBnClickedAddUserSumbitbutton
	Return Value: Void
	Remarks:   Function to insert new user details.
---------------------------------------------------------------------------*/


// DeleteUser message handlers
void DeleteUser::OnBnClickedDelete()
{
	// TODO: Add your control notification handler code here

	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1_DELETEUSER);
	int list = comboid->GetCurSel();
	if (list != CB_ERR)
	{

		UserIn userDetail;
		userDetail = m_infoArray.GetAt(list);
		Deleteuser user;
		//user.Email=
		m_apiService->Deleteuserdetail(list);




		}





	/*NetworkRequest::SetCloudUrl(strUrl);
	CString strSigninURL = _T("api/Account/GetUserList");
	// TODO: Add your control notification handler code here
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1_DELETEUSER);
	int list = comboid->GetCurSel();
	if (list != CB_ERR)
	{
		JSONValue* jval = NetworkRequest::GetReqEx(strSigninURL);

		JSONArray arr = jval->AsArray();

		JSONObject obj = arr[list]->AsObject();



		CString Emai(obj[L"Email"]->AsString().c_str());
		CString email = Emai;
		url.Format(_T("api/Account/DeleteUser?email=%s"), email);

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

void DeleteUser::OnBnClickedDelete1()
{
	// TODO: Add your control notification handler code here
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1_DELETEUSER);
	int list = comboid->GetCurSel();
	if (list != CB_ERR)
	{

		UserIn userDetail;
		userDetail = m_infoArray.GetAt(list);
		Deleteuser user;
		//user.Email=
		m_apiService->Deleteuserdetail(list);




	}
}
