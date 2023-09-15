#pragma once


// Cinviteuser dialog

class Cinviteuser : public CDialogEx
{
	DECLARE_DYNAMIC(Cinviteuser)

public:
	Cinviteuser(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cinviteuser();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INVITEUSER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
