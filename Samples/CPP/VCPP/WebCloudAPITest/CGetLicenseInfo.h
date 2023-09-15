#pragma once


// CGetLicenseInfo dialog

class CGetLicenseInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CGetLicenseInfo)

public:
	CGetLicenseInfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetLicenseInfo();
	AppApiService* m_LicenseService;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETLICENSEINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeDetails();
	afx_msg void OnCbnSelchangeCombo1();

	afx_msg void OnEnChangeEdit1();
	CString m_MACAddress;
	CString m_Details;
	CString selectPrdt;
	
};
