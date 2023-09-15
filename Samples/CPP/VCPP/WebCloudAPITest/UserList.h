#pragma once


// UserList dialog

class UserList : public CDialogEx
{
	DECLARE_DYNAMIC(UserList)

public:
	UserList(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUserList();
};
