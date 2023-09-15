#pragma once


// CAddFourms dialog

class CAddFourms : public CDialogEx
{
	DECLARE_DYNAMIC(CAddFourms)

public:
	CAddFourms(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddFourms();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDFOURMS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
