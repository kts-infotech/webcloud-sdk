#pragma once
#include "afxdialogex.h"


// AddAdmin dialog

class AddAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(AddAdmin)

public:
	AddAdmin(CWnd* pParent = nullptr);   // standard constructor
	AppApiService* m_apiService;

	virtual ~AddAdmin();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDADMIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddAdminAccSumbitAdmin();
};
