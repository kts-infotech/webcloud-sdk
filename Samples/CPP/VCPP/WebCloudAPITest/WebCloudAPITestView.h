
// WebCloudAPITestView.h : interface of the CWebCloudAPITestView class
//

#pragma once


class CWebCloudAPITestView : public CFormView,  public ApiEvents
{
	CString m_strUsername;
protected: // create from serialization only
	CWebCloudAPITestView() noexcept;
	DECLARE_DYNCREATE(CWebCloudAPITestView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WEBCLOUDAPITEST_FORM };
#endif

// Attributes
public:
	CWebCloudAPITestDoc* GetDocument() const;
	static CWebCloudAPITestView* m_pObjView;
	AppApiService* m_apiService;


// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	static void SetStatusBarMsg(CString msg);
	void OnResponseData(CString Data);
	void OnRequestData(CString Data);
	void OnStatusMessage(CString Message);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CWebCloudAPITestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLogin();
	void SetResponseData(CString msg);
	void SetRequestData(CString msg);
	CString GetUsername();
	static void SetResponseDataEx(CString msg);
	static void SetRequestDataEx(CString msg);
	afx_msg void OnAccountGenertetempsiteaccesstoken();
};

#ifndef _DEBUG  // debug version in WebCloudAPITestView.cpp
inline CWebCloudAPITestDoc* CWebCloudAPITestView::GetDocument() const
   { return reinterpret_cast<CWebCloudAPITestDoc*>(m_pDocument); }
#endif

