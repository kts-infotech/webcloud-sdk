#pragma once


// Cdeleteuser dialog

class Cdeleteuser : public CDialogEx
{
	DECLARE_DYNAMIC(Cdeleteuser)

public:
	Cdeleteuser(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cdeleteuser();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETEUSER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
