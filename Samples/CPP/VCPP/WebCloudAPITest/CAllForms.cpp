// CAllForms.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAllForms.h"
#include "afxdialogex.h"


// CAllForms dialog

IMPLEMENT_DYNAMIC(CAllForms, CDialogEx)

CAllForms::CAllForms(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SELECTFORM, pParent)
{

}

CAllForms::~CAllForms()
{
}

void CAllForms::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAllForms, CDialogEx)
END_MESSAGE_MAP()


// CAllForms message handlers
