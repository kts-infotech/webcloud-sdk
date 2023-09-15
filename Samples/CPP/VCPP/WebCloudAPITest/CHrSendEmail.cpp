// CHrSendEmail.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CHrSendEmail.h"
#include "afxdialogex.h"


// CHrSendEmail dialog

IMPLEMENT_DYNAMIC(CHrSendEmail, CDialogEx)

CHrSendEmail::CHrSendEmail(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HRSENDEMAIL, pParent)
{

}

CHrSendEmail::~CHrSendEmail()
{
}

void CHrSendEmail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHrSendEmail, CDialogEx)
END_MESSAGE_MAP()


// CHrSendEmail message handlers
