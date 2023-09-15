// CInviteEmployeeForm.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CInviteEmployeeForm.h"
#include "afxdialogex.h"


// CInviteEmployeeForm dialog

IMPLEMENT_DYNAMIC(CInviteEmployeeForm, CDialogEx)

CInviteEmployeeForm::CInviteEmployeeForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INVITEEMPLOYEEFORM, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CInviteEmployeeForm::~CInviteEmployeeForm()
{
}

void CInviteEmployeeForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInviteEmployeeForm, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO3, &CInviteEmployeeForm::OnCbnSelchangeCombo3)
    ON_CBN_SELCHANGE(IDC_COMBO2, &CInviteEmployeeForm::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_INVITE_EMPLOYEE, &CInviteEmployeeForm::OnBnClickedInviteEmployee)
END_MESSAGE_MAP()


// CInviteEmployeeForm message handlers
void CInviteEmployeeForm::OnCbnSelchangeCombo3()
{
    // TODO: Add your control notification handler code here
    CComboBox* usercategory = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO3));
    int cursel = usercategory->GetCurSel();
    cursel = cursel + 1002;
    strIndex.Format(_T("%d"), cursel);
    usercategory->SetWindowText(strIndex);
}


void CInviteEmployeeForm::OnCbnSelchangeCombo2()
{
    // TODO: Add your control notification handler code here
    CComboBox* employeetype = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
    int cursel = employeetype->GetCurSel();
    cursel = cursel + 1;
    Type.Format(_T("%d"), cursel);
    employeetype->SetWindowText(Type);
}




void CInviteEmployeeForm::OnBnClickedInviteEmployee()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	NetworkRequest::SetCloudUrl(strUrl);
	InviteEmployeeInfo invite;
	OnCbnSelchangeCombo3();
	//GetDlgItem(IDC_COMBO3)->GetWindowText(invite.UserCategory);
    invite.UserCategory = strIndex;
	OnCbnSelchangeCombo2();
	//GetDlgItem(IDC_COMBO2)->GetWindowText(invite.EmployeeType);
    invite.EmployeeType = Type;
	GetDlgItem(IDC_EDIT_USREMAIL)->GetWindowText(invite.UserEmailAddress);
	GetDlgItem(IDC_EDIT_USRMSG)->GetWindowText(invite.UserMessage);
	m_apiService->InviteEmployee(invite);
}
