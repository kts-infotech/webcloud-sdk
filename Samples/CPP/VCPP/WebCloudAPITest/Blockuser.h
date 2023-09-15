#pragma once
#include "afxdialogex.h"

#include "NetworkRequest.h"

// Blockuser dialog

class Blockuser : public CDialogEx
{
	DECLARE_DYNAMIC(Blockuser)

public:
	Blockuser(CWnd* pParent = nullptr);   // standard constructor
	JSONValue* jval;
	CString strUrl = _T("http://test2.virtualtutor.co.in/");
    CString strSigninURL = _T("api/Account/BlockORUnBlockUser");
	AppApiService* m_apiService;
	CArray<UserIn, UserIn> m_infoArray;

    void clicked(int row);
	virtual ~Blockuser();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BLOCKUSER
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAccButtonBlockStatus();
	afx_msg void OnCbnSelchangeCombo1AccBlock();
	
};
