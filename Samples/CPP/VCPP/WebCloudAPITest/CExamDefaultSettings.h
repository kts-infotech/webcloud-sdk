#pragma once


// CExamDefaultSettings dialog

class CExamDefaultSettings : public CDialogEx
{
	DECLARE_DYNAMIC(CExamDefaultSettings)

public:
	CExamDefaultSettings(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CExamDefaultSettings();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXAMDEFAULTSETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
