// CProjectForm.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CProjectForm.h"
#include "afxdialogex.h"


// CProjectForm dialog

IMPLEMENT_DYNAMIC(CProjectForm, CDialogEx)

CProjectForm::CProjectForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PROJECTFORM, pParent)
{

}

CProjectForm::~CProjectForm()
{
}

void CProjectForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProjectForm, CDialogEx)
END_MESSAGE_MAP()


// CProjectForm message handlers
