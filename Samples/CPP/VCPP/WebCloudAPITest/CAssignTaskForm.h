#pragma once


// CAssignTaskForm dialog

class CAssignTaskForm : public CDialogEx
{
	DECLARE_DYNAMIC(CAssignTaskForm)

public:
	CAssignTaskForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAssignTaskForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ASSIGNTASKFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
