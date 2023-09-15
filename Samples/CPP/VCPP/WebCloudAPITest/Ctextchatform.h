#pragma once


// Ctextchatform dialog

class Ctextchatform : public CDialogEx
{
	DECLARE_DYNAMIC(Ctextchatform)

public:
	Ctextchatform(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Ctextchatform();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TEXTCHATFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
