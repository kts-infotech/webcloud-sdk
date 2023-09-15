#pragma once


// CImportData dialog

class CImportData : public CDialogEx
{
	DECLARE_DYNAMIC(CImportData)

public:
	CImportData(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CImportData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IMPORTDATA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
