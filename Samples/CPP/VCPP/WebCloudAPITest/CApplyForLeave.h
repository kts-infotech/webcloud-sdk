#pragma once


// CApplyForLeave dialog

class CApplyForLeave : public CDialogEx
{
	DECLARE_DYNAMIC(CApplyForLeave)

public:
	CApplyForLeave(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CApplyForLeave();
	CDateTimeCtrl m_datePicker;
	JSONValue* m_Jvalue;
	AppApiService* m_HRService;
	CArray<LeaveRequestDetails>LeaveRequestDetail;
	CString strFromDate, strToDate, strLeaveType, strSubject, strReason, strRequestRemarks, strLeaveRequestStatus, strLogDate, logID;
	CDateTimeCtrl m_DateTimeCtrl;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_APPLYFORLEAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDialogApplyforleave();
	CString GetTicksNow(CString Date);
	CString GetTicksNow1();
	BOOL OnInitDialog();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCbnSelchangeCombo1();
	CString GetSubjectText();
};
