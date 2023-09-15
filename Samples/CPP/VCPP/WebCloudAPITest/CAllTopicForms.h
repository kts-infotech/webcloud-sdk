#pragma once


// CAllTopicForms dialog

class CAllTopicForms : public CDialogEx
{
	DECLARE_DYNAMIC(CAllTopicForms)

public:
	CAllTopicForms(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAllTopicForms();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ALLTOPICFORMS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
