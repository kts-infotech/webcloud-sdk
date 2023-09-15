#pragma once


// Cdownloadfilefromcloud dialog

class Cdownloadfilefromcloud : public CDialogEx
{
	DECLARE_DYNAMIC(Cdownloadfilefromcloud)

public:
	Cdownloadfilefromcloud(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Cdownloadfilefromcloud();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DOWNLOADFILEFROMCLOUD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();



};
