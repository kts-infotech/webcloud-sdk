#pragma once


// CHrSendEmail dialog

class CHrSendEmail : public CDialogEx
{
	DECLARE_DYNAMIC(CHrSendEmail)

public:
	CHrSendEmail(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHrSendEmail();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HRSENDEMAIL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
