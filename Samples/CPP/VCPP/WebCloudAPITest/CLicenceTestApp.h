#pragma once


// CLicenceTestApp dialog

class CLicenceTestApp : public CDialogEx
{
	DECLARE_DYNAMIC(CLicenceTestApp)

public:
	CLicenceTestApp(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CLicenceTestApp();
	AppApiService* m_LicenseService;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LICENCESTESTAPP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	BOOL OnInitDialog();


	DECLARE_MESSAGE_MAP()



};
