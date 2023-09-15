#pragma once


// Cgetseopageinfo dialog

class Cgetseopageinfo : public CDialogEx
{
	DECLARE_DYNAMIC(Cgetseopageinfo)

public:
	Cgetseopageinfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cgetseopageinfo();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETSEOPAGEINFO };
#endif

	void GetSEOPageInfo();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	CComboBox comboid;
	
	afx_msg void OnCbnSelchangeCombo1();

	CListBox ListItem;
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CArray<SeoPageDetails, SeoPageDetails> m_seodetails;
};
