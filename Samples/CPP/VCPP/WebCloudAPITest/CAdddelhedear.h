#pragma once


// CAdddelhedear dialog

class CAdddelhedear : public CDialogEx
{
	DECLARE_DYNAMIC(CAdddelhedear)

public:
	CAdddelhedear(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAdddelhedear();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDDELHEADER };
#endif
	void AddListMenu();
	void AddExistingHeader();
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnClickedButtonRemove();
	afx_msg void OnBnClickedButtonClose();
	CListBox ListMenu;
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CArray<HeaderDetails, HeaderDetails> m_headerInfo;
};
