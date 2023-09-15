#pragma once
#include "afxdialogex.h"
#include "NetworkRequest.h"

// CInviteEmployeeForm dialog

class CInviteEmployeeForm : public CDialogEx
{
	DECLARE_DYNAMIC(CInviteEmployeeForm)

public:
	CInviteEmployeeForm(CWnd* pParent = nullptr);   // standard constructor
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strSigninURL;
	CString url;
	AppApiService* m_apiService;
	virtual ~CInviteEmployeeForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INVITEEMPLOYEEFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInviteEmployee();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	CString EmployeeType;
	CString UserCategory;
	CString strIndex, Type;
};
