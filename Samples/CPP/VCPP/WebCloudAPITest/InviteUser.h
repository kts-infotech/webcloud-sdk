#pragma once
#include "afxdialogex.h"

#include "NetworkRequest.h"

// InviteUser dialog

class InviteUser : public CDialogEx
{
	DECLARE_DYNAMIC(InviteUser)

public:
	InviteUser(CWnd* pParent = nullptr);   // standard constructor
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strSigninURL;
	CString url;
	AppApiService* m_apiService;
	virtual ~InviteUser();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INVITE_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
