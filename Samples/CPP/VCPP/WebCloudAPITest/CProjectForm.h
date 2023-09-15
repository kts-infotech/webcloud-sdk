#pragma once


// CProjectForm dialog

class CProjectForm : public CDialogEx
{
	DECLARE_DYNAMIC(CProjectForm)

public:
	CProjectForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CProjectForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PROJECTFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
