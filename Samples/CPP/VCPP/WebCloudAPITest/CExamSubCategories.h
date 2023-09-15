#pragma once


// CExamSubCategories dialog

class CExamSubCategories : public CDialogEx
{
	DECLARE_DYNAMIC(CExamSubCategories)

public:
	CExamSubCategories(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CExamSubCategories();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGEXAMSUBCATEGORYLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
