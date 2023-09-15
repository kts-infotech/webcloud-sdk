#pragma once


// CAddadmin dialog

class CAddadmin : public CDialogEx
{
	DECLARE_DYNAMIC(CAddadmin)

public:
	CAddadmin(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddadmin();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDADMIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddUser();
};
