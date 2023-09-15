#pragma once


// Cuploadappdata dialog

class Cuploadappdata : public CDialogEx
{
	DECLARE_DYNAMIC(Cuploadappdata)

public:
	Cuploadappdata(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cuploadappdata();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPLOADAPPDATA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
