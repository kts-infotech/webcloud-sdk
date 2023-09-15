#pragma once
#include "afxdialogex.h"
#include "NetworkRequest.h"


// DeleteAdmin dialog

class DeleteAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteAdmin)

public:
	DeleteAdmin(CWnd* pParent = nullptr);   // standard constructor
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strSigninURL;
	CString url;
	int list;
	AppApiService* m_apiService;
	CArray<UserIn, UserIn> m_infoArray;
	virtual ~DeleteAdmin();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_ADMIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk2();
};
