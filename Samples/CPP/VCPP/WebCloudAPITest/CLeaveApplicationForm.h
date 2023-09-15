#pragma once
#include <cstring>

// CLeaveApplicationForm dialog

class CLeaveApplicationForm : public CDialogEx
{
	DECLARE_DYNAMIC(CLeaveApplicationForm)

public:
	CLeaveApplicationForm(CWnd* pParent = nullptr);   // standard constructor
	JSONValue* jval;
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strSigninURL = _T("Api/HR/GetAllLeaveApplicationsList");
	AppApiService* m_apiService;
	CArray<LeaveRequestDetails, LeaveRequestDetails> m_infoArray;
	CString LogId;
	CArray<LeaveRequestDetails> m_InfoArray;
	virtual ~CLeaveApplicationForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LEAVEAPPLICATIONFROM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedApprove();
	afx_msg void OnBnClickedReject();
	COleDateTime GetDateFromTicks(ULONGLONG date);
	afx_msg void OnBnClickedCancel();
};
