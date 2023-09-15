#pragma once


// GetAllInternalLinks dialog

class GetAllInternalLinks : public CDialogEx
{
	DECLARE_DYNAMIC(GetAllInternalLinks)

public:
	GetAllInternalLinks(CWnd* pParent = nullptr);   // standard constructor
	virtual ~GetAllInternalLinks();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GetAllInternalLinks };
#endif

	void GetInternalLinksInfo();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose();
	
private:
	AppApiService* m_apiService;
	CArray<LinkSettingsInfo, LinkSettingsInfo> m_infoArray;
public:
	CListCtrl m_listctrl;
	CEdit m_strtitle;
	CButton showLink;
};
