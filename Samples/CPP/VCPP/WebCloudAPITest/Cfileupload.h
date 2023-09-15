#pragma once


// Cfileupload dialog

class Cfileupload : public CDialogEx
{
	DECLARE_DYNAMIC(Cfileupload)

public:
	Cfileupload(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cfileupload();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILEUPLOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};
