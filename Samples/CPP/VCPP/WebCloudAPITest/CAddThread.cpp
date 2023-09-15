// CAddThread.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddThread.h"
#include "afxdialogex.h"


// CAddThread dialog

IMPLEMENT_DYNAMIC(CAddThread, CDialogEx)

CAddThread::CAddThread(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDTHREAD, pParent)
{

}

CAddThread::~CAddThread()
{
}

void CAddThread::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddThread, CDialogEx)
END_MESSAGE_MAP()


// CAddThread message handlers
