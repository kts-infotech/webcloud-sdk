#pragma once
#include "NetworkRequest.h"


// CEmployeeForm dialog

class CEmployeeForm : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeForm)

public:
	CEmployeeForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEmployeeForm();
	CString EmployeeID;
	CArray<CString>m_strEmployeeId;
	CArray<CString>m_strStatusId;
	CArray<CString>m_strEmployeeType;
	CArray<CString>m_strEmployeeType_new;
	CArray<CString>m_strEmployeeStatus;
	CArray<CString>m_strEmployeeStatus_new;
	AppApiService* m_HRService;

	BOOL OnInitDialog();
	JSONValue* m_Jvalue;
	CListCtrl m_listctrl;
	CArray<Employee_Info> m_InfoArray;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EMPLOYEEFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	void SHOWEMPLOYEE();
	int GetSelectedCheckboxIndex();
	void AddUpdateDeleteEmployeeAPI();
	void EMPLOYEEVIEWLIST();
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo1();
	CString Type;
	CString Status;
	int nSelectedIndex;
	afx_msg void OnBnClickedClose();
	void SetCurrentTextCombo(int ID, CString text);
	afx_msg void OnBnClickedButtonDlt();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonClearall();
	afx_msg void OnBnClickedButtonSave();
};
