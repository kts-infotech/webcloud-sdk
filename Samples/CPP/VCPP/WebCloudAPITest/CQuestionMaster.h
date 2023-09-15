#pragma once


// CQuestionMaster dialog

class CQuestionMaster : public CDialogEx
{
	DECLARE_DYNAMIC(CQuestionMaster)

public:
	CQuestionMaster(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CQuestionMaster();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_QUESTIONMASTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
