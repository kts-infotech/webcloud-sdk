// CAddComment.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddComment.h"
#include "afxdialogex.h"


// CAddComment dialog

IMPLEMENT_DYNAMIC(CAddComment, CDialogEx)

CAddComment::CAddComment(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDCOMMENT, pParent)
{

}

CAddComment::~CAddComment()
{
}

void CAddComment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddComment, CDialogEx)
END_MESSAGE_MAP()


// CAddComment message handlers
