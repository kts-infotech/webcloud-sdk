#pragma once


// CAllForms dialog

class CAllForms : public CDialogEx
{
	DECLARE_DYNAMIC(CAllForms)

public:
	CAllForms(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAllForms();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECTFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
