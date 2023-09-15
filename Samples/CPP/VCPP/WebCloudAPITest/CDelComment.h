#pragma once


// CDelComment dialog

class CDelComment : public CDialogEx
{
	DECLARE_DYNAMIC(CDelComment)

public:
	CDelComment(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDelComment();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELCOMMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
