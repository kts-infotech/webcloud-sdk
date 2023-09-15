#pragma once


// Cdeleteadmin dialog

class Cdeleteadmin : public CDialogEx
{
	DECLARE_DYNAMIC(Cdeleteadmin)

public:
	Cdeleteadmin(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cdeleteadmin();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETEADMIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
