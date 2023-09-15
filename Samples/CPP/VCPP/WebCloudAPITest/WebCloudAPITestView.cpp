
// WebCloudAPITestView.cpp : implementation of the CWebCloudAPITestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WebCloudAPITest.h"
#endif
#include "AddAdmin.h"
#include "WebCloudAPITestDoc.h"
#include "WebCloudAPITestView.h"
#include "NetworkRequest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MainFrm.h"


// CWebCloudAPITestView

IMPLEMENT_DYNCREATE(CWebCloudAPITestView, CFormView)
CWebCloudAPITestView* CWebCloudAPITestView::m_pObjView=nullptr;
BEGIN_MESSAGE_MAP(CWebCloudAPITestView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CWebCloudAPITestView::OnBnClickedButtonLogin)
	ON_COMMAND(ID_ACCOUNT_GENERTETEMPSITEACCESSTOKEN, &CWebCloudAPITestView::OnAccountGenertetempsiteaccesstoken)
END_MESSAGE_MAP()

// CWebCloudAPITestView construction/destruction

CWebCloudAPITestView::CWebCloudAPITestView() noexcept
	: CFormView(IDD_WEBCLOUDAPITEST_FORM)
{
	// TODO: add construction code here
	m_strUsername = _T("");
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;


}

CWebCloudAPITestView::~CWebCloudAPITestView()
{
}

void CWebCloudAPITestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CWebCloudAPITestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}



void CWebCloudAPITestView::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_pObjView = this;
	CWebCloudAPITestApp::m_pAppApiService = new AppApiService(this);
#ifdef _DEBUG
	GetDlgItem(IDC_EDIT_WEB_URL)->SetWindowText(_T("http://test2.virtualtutor.co.in/"));
	GetDlgItem(IDC_EDIT_USER_ID)->SetWindowText(_T("admin"));
	GetDlgItem(IDC_EDIT_PASSWORD)->SetWindowText(_T("admin"));

#endif


}


// CWebCloudAPITestView printing

BOOL CWebCloudAPITestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWebCloudAPITestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWebCloudAPITestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWebCloudAPITestView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CWebCloudAPITestView diagnostics

#ifdef _DEBUG
void CWebCloudAPITestView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWebCloudAPITestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CWebCloudAPITestDoc* CWebCloudAPITestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebCloudAPITestDoc)));
	return (CWebCloudAPITestDoc*)m_pDocument;
}
#endif //_DEBUG


// CWebCloudAPITestView message handlers


void CWebCloudAPITestView::OnBnClickedButtonLogin()
{
	CString btnText;
	GetDlgItem(IDC_BUTTON_LOGIN)->GetWindowText(btnText);
	if (btnText == _T("Logout"))
	{
		NetworkRequest::SetAuthToken(_T(""));
		GetDlgItem(IDC_BUTTON_LOGIN)->SetWindowText(_T("Login"));
		return;
	}
#if TRUE
	CString strUserName, strPassword, strUrl, strAuthToken;
	GetDlgItem(IDC_EDIT_WEB_URL)->GetWindowText(strUrl);
	GetDlgItem(IDC_EDIT_USER_ID)->GetWindowText(strUserName);
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(strPassword);
	CWebCloudAPITestApp::m_pAppApiService->SetAPIURL(strUrl);
	AuthInfo Info;
	CWebCloudAPITestApp::m_pAppApiService->ValidateUser(strUserName, strPassword, Info);
	GetDlgItem(IDC_EDIT_AUTH_TOKEN)->SetWindowText(Info.AuthenticationToken);
	GetDlgItem(IDC_BUTTON_LOGIN)->SetWindowText(_T("Logout"));
	m_strUsername = strUserName;

#else
	CString strUserName,strPassword,strUrl,strAuthToken;
	GetDlgItem(IDC_EDIT_WEB_URL)->GetWindowText(strUrl);
	GetDlgItem(IDC_EDIT_USER_ID)->GetWindowText(strUserName);
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(strPassword);
	NetworkRequest::SetCloudUrl(strUrl);
	CString strSigninURL= _T("api/Auth/ValidateUser?UserID="+ strUserName +"&Password="+ strPassword);
	SetRequestData(strUrl+ strSigninURL);
	SetStatusBarMsg(strSigninURL);
	//strSigninURL.Format(_T("api/Auth/ValidateUser?UserID=%s&Password=%s"), strUserName, strPassword);
	try
	{
		JSONValue* jval =NetworkRequest::GetReq(strSigninURL);
		std::wstring res=jval->Stringify(true);
		CString cstrRes(res.c_str());
		SetResponseData(cstrRes);
		JSONObject root = jval->AsObject();
		CString strAuthToken (root[L"AuthenticationToken"]->AsString().c_str());
		GetDlgItem(IDC_EDIT_AUTH_TOKEN)->SetWindowText(strAuthToken);
		NetworkRequest::SetAuthToken(strAuthToken);
		GetDlgItem(IDC_BUTTON_LOGIN)->SetWindowText(_T("Logout"));
		m_strUsername = strUserName;
		
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}
#endif
	
}
void CWebCloudAPITestView::SetResponseData(CString msg)
{
	GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(msg);
}
void CWebCloudAPITestView::SetRequestData(CString msg)
{
	GetDlgItem(IDC_EDIT_REQ_DATA)->SetWindowText(msg);
}
CString CWebCloudAPITestView::GetUsername()
{
	return m_strUsername;
}
void CWebCloudAPITestView::SetStatusBarMsg(CString msg)
{
	((CStatusBar*)AfxGetApp()->m_pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR))->SetPaneText(0, msg);
}

void CWebCloudAPITestView::SetResponseDataEx(CString msg)
{
	m_pObjView->GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(msg);
}
void CWebCloudAPITestView::SetRequestDataEx(CString msg)
{
	m_pObjView->GetDlgItem(IDC_EDIT_REQ_DATA)->SetWindowText(msg);
}




void CWebCloudAPITestView::OnAccountGenertetempsiteaccesstoken()
{
	// TODO: Add your command handler code here

	m_apiService->tempaccess();
	/*CString url = _T("api/Account/GenerateTempSiteAccessToken");
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(url);
		std::wstring res = jval->AsString();
		CString strAuth(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(strAuth);
	}
	catch (const std::exception& e)
	{
		CWebCloudAPITestApp::SetResponseMsg(CString(e.what()));
	}
	*/
}

void CWebCloudAPITestView::OnResponseData(CString Data)
{
	SetResponseData(Data);
}
void CWebCloudAPITestView::OnRequestData(CString Data)
{
	SetRequestData(Data);
}
void CWebCloudAPITestView::OnStatusMessage(CString Message)
{
	SetStatusBarMsg(Message);
}
