#pragma once
#include"NetworkRequest.h"

// CSubTaskForm dialog

class CSubTaskForm : public CDialogEx
{
	DECLARE_DYNAMIC(CSubTaskForm)

public:
	CSubTaskForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSubTaskForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SUBTASKFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();
	JSONValue* m_Jvalue;
	CListCtrl m_listctrl;
	AppApiService* m_PMService;
	
	CArray<SubTask_Info> m_InfoArray;
	DECLARE_MESSAGE_MAP()
public:
	void SHOWSUBTASK();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};
