#pragma once
#include "CDefault.h"
#include "CSinglePageSettings.h"
// CSetseopageinfo dialog

class CSetseopageinfo : public CDialogEx
{
	DECLARE_DYNAMIC(CSetseopageinfo)

public:
	CSetseopageinfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSetseopageinfo();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETSEOPAGEINFO };
#endif
	//void SetSEOPageInfo();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	//afx_msg void OnLbnSelchangeList2();
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CListBox ListMenu;
	CTabCtrl m_tabctrl;
	CDefault m_tab1;
	CSinglePageSettings m_tab2;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedClose();
	CListBox listBoxMenu;
	afx_msg void OnBnClickedButtonclose();
};
