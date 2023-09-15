#pragma once


// CAddTopic dialog

class CAddTopic : public CDialogEx
{
	DECLARE_DYNAMIC(CAddTopic)

public:
	CAddTopic(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddTopic();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDTOPIC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
