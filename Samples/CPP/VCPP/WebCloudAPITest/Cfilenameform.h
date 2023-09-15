#pragma once


// Cfilenameform dialog

class Cfilenameform : public CDialogEx
{
	DECLARE_DYNAMIC(Cfilenameform)

public:
	Cfilenameform(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cfilenameform();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILENAMEFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
