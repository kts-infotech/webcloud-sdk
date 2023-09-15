// CAddadmin.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddadmin.h"
#include "afxdialogex.h"


// CAddadmin dialog

IMPLEMENT_DYNAMIC(CAddadmin, CDialogEx)

CAddadmin::CAddadmin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDADMIN, pParent)
{

}

CAddadmin::~CAddadmin()
{
}

void CAddadmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddadmin, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_USER, &CAddadmin::OnBnClickedAddUser)
END_MESSAGE_MAP()


// CAddadmin message handlers


void CAddadmin::OnBnClickedAddUser()
{
	// TODO: Add your control notification handler code here
}
