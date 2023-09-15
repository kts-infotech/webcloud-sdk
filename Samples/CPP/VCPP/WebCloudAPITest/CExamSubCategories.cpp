// CExamSubCategories.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CExamSubCategories.h"
#include "afxdialogex.h"


// CExamSubCategories dialog

IMPLEMENT_DYNAMIC(CExamSubCategories, CDialogEx)

CExamSubCategories::CExamSubCategories(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGEXAMSUBCATEGORYLIST, pParent)
{

}

CExamSubCategories::~CExamSubCategories()
{
}

void CExamSubCategories::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExamSubCategories, CDialogEx)
END_MESSAGE_MAP()


// CExamSubCategories message handlers
