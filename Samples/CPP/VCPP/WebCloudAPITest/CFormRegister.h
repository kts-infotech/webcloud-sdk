#pragma once


// CFormRegister dialog

class CFormRegister : public CDialogEx
{
	DECLARE_DYNAMIC(CFormRegister)

public:
	CFormRegister(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFormRegister();
	AppApiService* m_LicenseService;
	CArray<NewUserRegInfo>newuserreginfo;
	CArray<Activation>activation;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FORMREGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CString m_URL;
	afx_msg void OnBnClickedBuy();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedValidate();
	afx_msg void OnBnClickedRegister();
	afx_msg void OnBnClickedCancel();
	afx_msg void ValidateActivation();
	afx_msg void ActivationProduct();
	
	CComboBox m_ComboBox1;
	afx_msg void OnEnChangeEdit5();
	CString m_MachineId;
	
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit1();
};
