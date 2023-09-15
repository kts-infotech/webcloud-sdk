#pragma once


// CSinglePageSettings dialog

class CSinglePageSettings : public CDialogEx
{
	DECLARE_DYNAMIC(CSinglePageSettings)

public:
	CSinglePageSettings(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSinglePageSettings();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SINGLEPAGESETTINGS };
#endif
	virtual BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void SetSEOPageInfo();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSupdate();
	afx_msg void OnBnClickedButtonSreset();
	
	CButton checkboxDefault;
	CStatic m_Title;
	CListBox ListMenu;
	afx_msg void OnLbnSelchangeList1();
	CButton socialSharing;
	CButton enableWhatsapp;
	
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CArray<SeoPageDetails, SeoPageDetails> m_seodetails;

};
