// CDeleteThread.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CDeleteThread.h"
#include "afxdialogex.h"


// CDeleteThread dialog

IMPLEMENT_DYNAMIC(CDeleteThread, CDialogEx)

CDeleteThread::CDeleteThread(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETETHREAD, pParent)
{

}

CDeleteThread::~CDeleteThread()
{
}

void CDeleteThread::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteThread, CDialogEx)
END_MESSAGE_MAP()


// CDeleteThread message handlers
