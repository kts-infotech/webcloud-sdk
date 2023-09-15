#pragma once


// CAddExamCategory dialog

class CAddExamCategory : public CDialogEx
{
	DECLARE_DYNAMIC(CAddExamCategory)

public:
	CAddExamCategory(CWnd* pParent = nullptr);  // standard constructor
	AppApiService* m_apiService;

	virtual ~CAddExamCategory();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDEXAMCATEGORY};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedAdd();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedClose();
};
