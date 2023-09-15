// CAddExamCategory.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CAddExamCategory.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

// CAddExamCategory dialog

IMPLEMENT_DYNAMIC(CAddExamCategory, CDialogEx)

CAddExamCategory::CAddExamCategory(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDEXAMCATEGORY, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CAddExamCategory::~CAddExamCategory()
{
}

void CAddExamCategory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddExamCategory, CDialogEx)
	ON_BN_CLICKED(IDADD, &CAddExamCategory::OnBnClickedAdd)
	ON_BN_CLICKED(IDCLOSE, &CAddExamCategory::OnBnClickedClose)
END_MESSAGE_MAP()


// CAddExamCategory message handlers

void CAddExamCategory::OnBnClickedAdd()
{
	ExamMainCategory add;

	GetDlgItem(IDC_EDIT1)->GetWindowText(add.MainCategoryName);
	GetDlgItem(IDC_EDIT2)->GetWindowText(add.MainCategoryDesc);

	m_apiService->AddExamMainCategory(add);
}

void CAddExamCategory::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
