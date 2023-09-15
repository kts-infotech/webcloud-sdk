#pragma once



// Caddinternalink dialog

class Caddinternalink : public CDialogEx
{
	DECLARE_DYNAMIC(Caddinternalink)

public:
	Caddinternalink(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Caddinternalink();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDINTERNALLINK };
#endif

	virtual BOOL OnInitDialog();
	void DisplayMenuNames();
	void GetInternalLink();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonClose();
	CListBox ListMenu;
	CListBox LinkName;
	afx_msg void OnBnClickedButtonUpdateTitle();
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonUpdate();
	CButton ShowLink;
	CEdit Link;
	CEdit Edit1;
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CArray< LinkSettingsInfo, LinkSettingsInfo> m_linkinfo;
public:
	afx_msg void OnLbnSelchangeList3();
};
