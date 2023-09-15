#pragma once


// CAddThread dialog

class CAddThread : public CDialogEx
{
	DECLARE_DYNAMIC(CAddThread)

public:
	CAddThread(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddThread();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDTHREAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
