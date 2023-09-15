#pragma once


// GetAllExternalLinks dialog

class GetAllExternalLinks : public CDialogEx
{
	DECLARE_DYNAMIC(GetAllExternalLinks)

public:
	GetAllExternalLinks(CWnd* pParent = nullptr);   // standard constructor
	virtual ~GetAllExternalLinks();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETALLLINKS };
#endif
	void GetExternalLinksInfo();
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedClose();
	CListCtrl m_listctrl;
private:
	AppApiService* m_apiService;
	CArray<LinkSettingsInfo, LinkSettingsInfo> m_infoArray;
public:
	CEdit m_strtitle;
	CButton showLink;
};
