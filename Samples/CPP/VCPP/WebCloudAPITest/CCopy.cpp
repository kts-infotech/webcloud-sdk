// CCopy.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CCopy.h"
#include "afxdialogex.h"


// CCopy dialog

IMPLEMENT_DYNAMIC(CCopy, CDialogEx)

CCopy::CCopy(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COPY, pParent)
{

}

CCopy::~CCopy()
{
}

void CCopy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCopy, CDialogEx)
END_MESSAGE_MAP()


// CCopy message handlers
