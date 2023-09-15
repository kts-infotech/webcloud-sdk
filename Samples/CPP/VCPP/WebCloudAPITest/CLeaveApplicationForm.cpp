// CLeaveApplicationForm.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CLeaveApplicationForm.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"

#pragma comment(lib, "Winhttp.lib")
// CLeaveApplicationForm dialog

IMPLEMENT_DYNAMIC(CLeaveApplicationForm, CDialogEx)

CLeaveApplicationForm::CLeaveApplicationForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LEAVEAPPLICATIONFROM, pParent)
{
	m_apiService = CWebCloudAPITestApp::m_pAppApiService;
}

CLeaveApplicationForm::~CLeaveApplicationForm()
{
}

void CLeaveApplicationForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BOOL CLeaveApplicationForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);

	try
	{
		//Get request.
		if (strSigninURL == _T("Api/HR/GetAllLeaveApplicationsList"))
		{
			m_apiService->GetAllLeaveApplicationsList(m_infoArray);
		}


		//Initializing combobox.
		for (int i = 0; i < m_infoArray.GetSize(); i++) {
			comboid->AddString(m_infoArray.GetAt(i).Username);
		}

		//Showing Resquest data and Response data.
		CWebCloudAPITestApp::SetRequestMSg(strSigninURL);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		GetDlgItem(IDC_EDIT_RES_DATA)->SetWindowText(errorStr);
	}

	return true;
}

BEGIN_MESSAGE_MAP(CLeaveApplicationForm, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLeaveApplicationForm::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(ID_APPROVE, &CLeaveApplicationForm::OnBnClickedApprove)
	ON_BN_CLICKED(ID_REJECT, &CLeaveApplicationForm::OnBnClickedReject)
	ON_BN_CLICKED(IDCANCEL, &CLeaveApplicationForm::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLeaveApplicationForm message handlers
void CLeaveApplicationForm::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int list = comboid->GetCurSel();
	if (list != CB_ERR)
	{

		LeaveRequestDetails leaverequestDetail;
		LeaveReqStatus LeaveRequestStatus;
		leaverequestDetail = m_infoArray.GetAt(list);
		//LogId = leaverequestDetail.LogID;
		CString a = leaverequestDetail.FromDate;
		ULONGLONG num = _ttoi64(a);
		COleDateTime date = GetDateFromTicks(num);
		CString strdate = date.Format(_T("%A, %B %d, %Y"));
		leaverequestDetail.FromDate = strdate;
		GetDlgItem(IDC_FROM)->SetWindowText(leaverequestDetail.FromDate);

		CString b = leaverequestDetail.ToDate;
		ULONGLONG num1 = _ttoi64(b);
		COleDateTime date1 = GetDateFromTicks(num1);
		CString strdate1 = date.Format(_T("%A, %B %d, %Y"));
		leaverequestDetail.ToDate = strdate1;

		GetDlgItem(IDC_TO)->SetWindowText(leaverequestDetail.ToDate);
		GetDlgItem(IDC_TYPE)->SetWindowText(leaverequestDetail.LeaveType);
		GetDlgItem(IDC_REASON)->SetWindowText(leaverequestDetail.LeaveReason);
		GetDlgItem(IDC_STATUS)->SetWindowText(leaverequestDetail.LeaveRequestStatus);
		GetDlgItem(IDC_EDIT_REMARKS)->SetWindowText(leaverequestDetail.LeaveRequestRemarks);

	}



}


void CLeaveApplicationForm::OnBnClickedApprove()
{
	// TODO: Add your control notification handler code here

	// Assuming you have a CComboBox variable named m_comboBox
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);

	//CComboBox* Combodrop_down = (CComboBox*)GetDlgItem(IDC_COMBO_SELECT_FORUM_ID);
	int Combo_Sel = comboid->GetCurSel();
	m_InfoArray.RemoveAll();

	m_apiService->GETLOGID(m_InfoArray, Combo_Sel);

	LeaveRequestDetails leaveRequestDetail;
	CString LogId;
	//leaveRequestDetail.LogID = m_InfoArray[nSelectedIndex].LogID;
	CString remarks;
	CString status = _T("Approved");
	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_REMARKS);
	Edit_Box1->GetWindowText(remarks);
	try {
		WCResults response;
		LeaveReqStatus LeaveRequestStatus;
		LeaveRequestStatus.LogID = m_InfoArray[0].LogID;
		LeaveRequestStatus.LeaveRequestStatus = status;
		LeaveRequestStatus.LeaveRequestRemarks = remarks;
		m_apiService->PostLeaveStatus(response, LeaveRequestStatus);

	}
	catch (const std::exception& e)
	{
		CString err(e.what());
		CWebCloudAPITestApp::SetResponseMsg(err);
	}
	OnBnClickedCancel();
}



void CLeaveApplicationForm::OnBnClickedReject()
{
	// TODO: Add your control notification handler code here
	// Assuming you have a CComboBox variable named m_comboBox
	CComboBox* comboid = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int Combo_Sel = comboid->GetCurSel();
	m_InfoArray.RemoveAll();

	m_apiService->GETLOGID(m_InfoArray, Combo_Sel);

	LeaveRequestDetails leaveRequestDetail;
	CString LogId;
	CString remarks;
	CString status = _T("Rejected");
	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT_REMARKS);
	Edit_Box1->GetWindowText(remarks);
	try {
		WCResults response;
		LeaveReqStatus LeaveRequestStatus;
		LeaveRequestStatus.LogID = m_InfoArray[0].LogID;
		LeaveRequestStatus.LeaveRequestStatus = status;
		LeaveRequestStatus.LeaveRequestRemarks = remarks;
		m_apiService->PostLeaveStatus(response, LeaveRequestStatus);

	}
	catch (const std::exception& e)
	{
		CString err(e.what());
		CWebCloudAPITestApp::SetResponseMsg(err);
	}
	OnBnClickedCancel();
}

COleDateTime CLeaveApplicationForm::GetDateFromTicks(ULONGLONG date)
{
	COleDateTime epoch(100, 1, 1, 00, 00, 00);
	LONG missingDays = 365 * 99 + 24;
	CTimeSpan centSpan(missingDays, 0, 0, 0);
	CTimeSpan cSpan(date / 10000000);
	CTimeSpan tot = cSpan - centSpan;
	COleDateTimeSpan timSpn((LONG)tot.GetDays(), (int)tot.GetHours(), (int)tot.GetMinutes(), (int)tot.GetSeconds());
	COleDateTime resDate = epoch + timSpn;
	return resDate;
}



void CLeaveApplicationForm::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}