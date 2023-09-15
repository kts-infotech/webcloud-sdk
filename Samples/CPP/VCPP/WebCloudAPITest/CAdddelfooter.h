#pragma once


// CAdddelfooter dialog

class CAdddelfooter : public CDialogEx
{
	DECLARE_DYNAMIC(CAdddelfooter)

public:
	CAdddelfooter(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAdddelfooter();
	CArray<CString>list_sel;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDDELFOOTER };
#endif

	void AddListMenu();
	void AddExistingFooter();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonClose();
	CListBox ListLink;
	CListBox lbox;
	CEdit edit1;
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CArray<FooterDetails, FooterDetails> m_footerInfo;
};
