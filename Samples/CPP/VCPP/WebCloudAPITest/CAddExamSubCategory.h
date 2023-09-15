#pragma once


// CAddExamSubCategory dialog

class CAddExamSubCategory : public CDialogEx
{
	DECLARE_DYNAMIC(CAddExamSubCategory)

public:
	CAddExamSubCategory(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddExamSubCategory();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDEXAMSUBCATEGORY};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
