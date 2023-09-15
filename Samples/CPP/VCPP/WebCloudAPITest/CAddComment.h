#pragma once


// CAddComment dialog

class CAddComment : public CDialogEx
{
	DECLARE_DYNAMIC(CAddComment)

public:
	CAddComment(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddComment();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDCOMMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
