// CExamDefaultSettings.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CExamDefaultSettings.h"
#include "afxdialogex.h"


// CExamDefaultSettings dialog

IMPLEMENT_DYNAMIC(CExamDefaultSettings, CDialogEx)

CExamDefaultSettings::CExamDefaultSettings(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EXAMDEFAULTSETTINGS, pParent)
{

}

CExamDefaultSettings::~CExamDefaultSettings()
{
}

void CExamDefaultSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExamDefaultSettings, CDialogEx)
END_MESSAGE_MAP()


// CExamDefaultSettings message handlers
