// CAddTopic.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddTopic.h"
#include "afxdialogex.h"


// CAddTopic dialog

IMPLEMENT_DYNAMIC(CAddTopic, CDialogEx)

CAddTopic::CAddTopic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDTOPIC, pParent)
{

}

CAddTopic::~CAddTopic()
{
}

void CAddTopic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddTopic, CDialogEx)
END_MESSAGE_MAP()


// CAddTopic message handlers
