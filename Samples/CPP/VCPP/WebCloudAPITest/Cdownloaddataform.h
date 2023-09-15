#pragma once


// Cdownloaddataform dialog

class Cdownloaddataform : public CDialogEx
{
	DECLARE_DYNAMIC(Cdownloaddataform)

public:
	Cdownloaddataform(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cdownloaddataform();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DOWNLOADAPPDATAFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
