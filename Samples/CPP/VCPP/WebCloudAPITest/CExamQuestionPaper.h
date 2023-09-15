#pragma once


// CExamQuestionPaper dialog

class CExamQuestionPaper : public CDialogEx
{
	DECLARE_DYNAMIC(CExamQuestionPaper)

public:
	CExamQuestionPaper(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CExamQuestionPaper();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXAMQUESTIONPAPER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
