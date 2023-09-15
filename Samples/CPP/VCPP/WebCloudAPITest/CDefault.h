#pragma once


// CDefault dialog

class CDefault : public CDialogEx
{
	DECLARE_DYNAMIC(CDefault)

public:
	CDefault(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDefault();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEFAULT };
#endif
	virtual BOOL OnInitDialog();
	void SetSEOPageInfo();
	void DefaultSEOSettings();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonReset();
	CListBox ListMenu;
private:
	AppApiService* m_apiService;
	CArray<SeoPageDetails, SeoPageDetails> m_seoArray;
	CArray<MenuInfo, MenuInfo> m_infoArray;
public:
	CButton CheckAlias;
};
