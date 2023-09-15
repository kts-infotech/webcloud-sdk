// CQuestionMaster.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CQuestionMaster.h"
#include "afxdialogex.h"


// CQuestionMaster dialog

IMPLEMENT_DYNAMIC(CQuestionMaster, CDialogEx)

CQuestionMaster::CQuestionMaster(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_QUESTIONMASTER, pParent)
{

}

CQuestionMaster::~CQuestionMaster()
{
}

void CQuestionMaster::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CQuestionMaster, CDialogEx)
END_MESSAGE_MAP()


// CQuestionMaster message handlers
