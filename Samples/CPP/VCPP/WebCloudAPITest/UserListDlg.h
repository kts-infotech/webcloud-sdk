#pragma once
#include "NetworkRequest.h"


// UserListDlg dialog

class UserListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserListDlg)

public:
	UserListDlg(CWnd* pParent = nullptr);   // standard constructor
	JSONValue* jval;
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
	CString strSigninURL = _T("api/Account/GetUserList");
	AppApiService* m_apiService;

	CArray<UserIn, UserIn> m_infoArray;

	//int list;
//UserListDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserListDlg();
	

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMThemeChangedScrollbar2(NMHDR* pNMHDR, LRESULT* pResult);
	//afx_msg void OnLbnSelchangeList2();
	virtual BOOL OnInitDialog();
	void GetAllUserLIist();


	afx_msg void OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
	void OnCbnSelchangeUlCombo();
	//afx_msg void OnLbnSelchangeList4();



};
