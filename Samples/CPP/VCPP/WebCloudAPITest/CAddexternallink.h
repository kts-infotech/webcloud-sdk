#pragma once


// CAddexternallink dialog

class CAddexternallink : public CDialogEx
{
	DECLARE_DYNAMIC(CAddexternallink)

public:
	CAddexternallink(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddexternallink();
	CArray<CString>m_strLinkID;
	CString strMenuID, strURL, strLinkName, strMenuName, strLinkID;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDEXTERNALLINK };
#endif

	virtual BOOL OnInitDialog();
	void GetExternalLink();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CEdit Link;
	afx_msg void OnBnClickedButtonUpdateTitle();
	afx_msg void OnBnClickedButtonOrder();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnLbnSelchangeList1();
	CEdit strLinkURL1;
	CEdit strLinkName1;
	CButton CheckAlias;
	CArray<CString> list_sel;

	afx_msg void OnBnClickedButtonUp();
	afx_msg void OnBnClickedButtonDown();
	
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CArray< LinkSettingsInfo, LinkSettingsInfo> m_linkinfo;
	CArray<LinkDetails, LinkDetails> m_link;
};
