#pragma once


// CListLeaveApplications dialog

class CListLeaveApplications : public CDialogEx
{
	DECLARE_DYNAMIC(CListLeaveApplications)

public:
	CListLeaveApplications(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CListLeaveApplications();
	AppApiService* m_HRServices;
	BOOL OnInitDialog();
	CListCtrl m_listctrl;
	CArray<LeaveRequestDetails> m_InfoArray;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LISTALLLEAVEAPPLICATIONSFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void SHOWLEAVELIST();
	COleDateTime GetDateFromTicks(ULONGLONG date);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedClose();
};
