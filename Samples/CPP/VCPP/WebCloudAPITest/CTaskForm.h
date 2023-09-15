#pragma once
#include"NetworkRequest.h"


// CTaskForm dialog

class CTaskForm : public CDialogEx
{
	DECLARE_DYNAMIC(CTaskForm)

public:
	CTaskForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTaskForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TASKFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();
	JSONValue* m_Jvalue;

	AppApiService* m_PMService;
	CListCtrl m_listctrl;
	CArray<Task_Info> m_InfoArray;
	DECLARE_MESSAGE_MAP()
public:
	void SHOWTASK();
	afx_msg void OnBnClickedButtonSave2();
	afx_msg void OnBnClickedButtonCancel();
};
