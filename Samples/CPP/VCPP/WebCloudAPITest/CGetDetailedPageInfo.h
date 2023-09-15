#pragma once
#include "NetworkRequest.h"
#include "Services/AppCmsService.h"



// CGetDetailedPageInfo dialog

class CGetDetailedPageInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CGetDetailedPageInfo)

public:
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CGetDetailedPageInfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CGetDetailedPageInfo();
	//JSONValue* jval;
	
	CString strSigninURL;
	
	CArray<int>m_Menuid;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GETDETAILEDPAGEINFO };
#endif

	
	void DetailedPageInfo();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose();
	afx_msg void OnLbnSelchangeListmenuwithid();
	CListBox ListItem;
	CListBox ListDesc;
private:
	AppApiService* m_apiService;
	CArray<MenuInfo, MenuInfo> m_infoArray;
	CListBox ListMenu;
	//CArray<MenuInfo, MenuInfo> m_allinfo;
};
 