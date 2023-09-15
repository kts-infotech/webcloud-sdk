#pragma once
#include "afxdialogex.h"

#include "NetworkRequest.h"

// DeleteUser dialog

class DeleteUser : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteUser)

public:
	DeleteUser(CWnd* pParent = nullptr);   // standard constructor
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strSigninURL;
	CString url;
	int list;
	AppApiService* m_apiService;
	CArray<UserIn, UserIn> m_infoArray;

	virtual ~DeleteUser();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDelete();

	afx_msg void OnBnClickedDelete1();
};
