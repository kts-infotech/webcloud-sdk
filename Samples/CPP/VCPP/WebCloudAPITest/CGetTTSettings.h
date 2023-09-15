#pragma once


// CGetTTSettings dialog

class CGetTTSettings : public CDialogEx
{
	DECLARE_DYNAMIC(CGetTTSettings)

public:
	CGetTTSettings(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetTTSettings();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETTTSETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_TimeZone;
	CString m_IdleTime;
	CString m_TimeZoneCode;
	CString m_ActivityCaptureInterval;
	CString m_ScreenCaptureResolution;
};
