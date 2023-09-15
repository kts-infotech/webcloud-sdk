#pragma once


// CCopy dialog

class CCopy : public CDialogEx
{
	DECLARE_DYNAMIC(CCopy)

public:
	CCopy(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCopy();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COPY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
