#pragma once


// CDeleteThread dialog

class CDeleteThread : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteThread)

public:
	CDeleteThread(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDeleteThread();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETETHREAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
