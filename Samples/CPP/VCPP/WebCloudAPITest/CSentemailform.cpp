// CSentemailform.cpp : implementation file
/*---------------------------------------------------------------------------
	Workfile:CSentemailform.cpp
	Description: . Implementation of Class CSentemailform

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

	Author: Jayakrishnan P
	Last Modtime:  15/06/2022
	Last Revision:
---------------------------------------------------------------------------*/

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CSentemailform.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"



// CSentemailform dialog

IMPLEMENT_DYNAMIC(CSentemailform, CDialogEx)

CSentemailform::CSentemailform(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SENDEMAILFORM, pParent)
{
	
}

CSentemailform::~CSentemailform()
{
}

/*---------------------------------------------------------------------------
	Function Name: CSentemailform::DoDataExchange
	Return Value: Void
	Parameters:Pointer to CDataExchange class.
	Remarks:  Initialized Text Boxes when dialog is created.
---------------------------------------------------------------------------*/
void CSentemailform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//Initializing 'From' Text Box with "admin".
	GetDlgItem(IDC_EDIT_SendEmail_from)->SetWindowText(L"admin");
}


BEGIN_MESSAGE_MAP(CSentemailform, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SendEmail_add, &CSentemailform::OnBnClickedButtonEmailAttachment)
	ON_BN_CLICKED(IDC_BUTTON_SendEmail_sendMail, &CSentemailform::OnBnClickedButtonSendemailSend)
END_MESSAGE_MAP()


// CSentemailform message handlers

/*---------------------------------------------------------------------------
	Function Name: CSentemailform::OnBnClickedButtonEmailAttachment
	Return Value: Void
	Parameters:No parametrs
	Remarks:  Click event of Sent Email Form's Attach button.
---------------------------------------------------------------------------*/
void CSentemailform::OnBnClickedButtonEmailAttachment()
{
	// TODO: Add your control notification handler code here

	IFileOpenDialog* fileOpen;
	PWSTR pszFilePath;
	HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
		IID_IFileOpenDialog, reinterpret_cast<void**>(&fileOpen));

	if (SUCCEEDED(hr))
	{
		try
		{
			// Show the Open dialog box.
			hr = fileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = fileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					strFilePath = pszFilePath;
					pItem->Release();
				}
			}
		}
		catch (const std::exception& e)
		{
			CString err(e.what());
			CWebCloudAPITestApp::SetResponseMsg(err);
		}
		
	}
	AttachmentInfo attachment;

	//Converting file into base64 encoded CString
	attachment.AttachmentBase64 = NetworkRequest::ConvertToBase64(strFilePath);

	//Name of selected file with extension
	attachment.AttachmentName = PathFindFileName(strFilePath);

	//Extension of selected file with preceding '.'
	attachment.AttachmentType = attachment.AttachmentName.Right(attachment.AttachmentName.GetLength()- attachment.AttachmentName.Find('.'));

	m_attchmentList.Add(attachment);
}



/*---------------------------------------------------------------------------
	Function Name: CSentemailform::OnBnClickedButtonSendemailSend
	Return Value: Void
	Parameters:No parametrs
	Remarks:  Click event of Sent Email Form's Send button.
---------------------------------------------------------------------------*/
void CSentemailform::OnBnClickedButtonSendemailSend()
{
	// TODO: Add your control notification handler code here

	GetDlgItem(IDC_EDIT_SendEmail_to)->GetWindowText(m_mailInfo.To);
	GetDlgItem(IDC_EDIT_SendEmail_cc)->GetWindowText(m_mailInfo.CC);
	GetDlgItem(IDC_EDIT_SendEmail_bcc)->GetWindowText(m_mailInfo.BCC);
	GetDlgItem(IDC_EDIT_SendEmail_subject)->GetWindowText(m_mailInfo.Subject);
	GetDlgItem(IDC_EDIT_SendEmail_message)->GetWindowText(m_mailInfo.HtmlMailContent);

	m_mailInfo.AttachmentArray.Copy(m_attchmentList);

	//Code to check whether mandatory fields are empty or not
	int msgBxResponce = 0;
	if (m_mailInfo.To == "") {
		AfxMessageBox(L"Fill the TO Address", MB_OK);
		return;
	}

	if (m_mailInfo.Subject == "") {
		AfxMessageBox(L"Fill the subject field", MB_OK);
		return;
	}

	if (m_mailInfo.HtmlMailContent == "")
	{
		msgBxResponce = AfxMessageBox(L"Are you sure to leave message field empty?",MB_YESNO);
		if (msgBxResponce == 7)
			return;
	}

	

	try 
	{
		WCResult responce;
		CWebCloudAPITestApp::m_pAppApiService->SendEmail(responce, m_mailInfo);
		CString url = _T("Api/Comm/SendMail");
		CWebCloudAPITestApp::SetStatusBarMsg(url);
		CString rsp= _T("Description:") + responce.Desc;
		CWebCloudAPITestApp::SetResponseMsg(rsp);
	}
	catch (const std::exception &e)
	{
		CString err(e.what());
		CWebCloudAPITestApp::SetResponseMsg(err);
	}
	
}
