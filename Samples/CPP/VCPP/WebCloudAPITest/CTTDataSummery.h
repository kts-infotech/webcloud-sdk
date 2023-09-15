#pragma once


// CTTDataSummery dialog

class CTTDataSummery : public CDialogEx
{
	DECLARE_DYNAMIC(CTTDataSummery)

public:
	CTTDataSummery(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTTDataSummery();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TTDATASUMMERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_TodayHours;
	CString m_WeekHours;
	CString m_MonthHours;
};
