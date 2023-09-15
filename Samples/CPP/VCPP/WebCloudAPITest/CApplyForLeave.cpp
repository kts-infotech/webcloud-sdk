// CApplyForLeave.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CApplyForLeave.h"
#include "afxdialogex.h"
#include <iostream>
#include <ctime>
#include <afxdtctl.h>
#include <afx.h>


// CApplyForLeave dialog

IMPLEMENT_DYNAMIC(CApplyForLeave, CDialogEx)

CApplyForLeave::CApplyForLeave(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_APPLYFORLEAVE, pParent)
{
	m_HRService = CWebCloudAPITestApp::m_pAppApiService;
}

CApplyForLeave::~CApplyForLeave()
{
}
BOOL CApplyForLeave::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Initialize the CDateTimeCtrl control
	m_DateTimeCtrl.SubclassDlgItem(IDC_DATETIMEPICKER1, this);

	// ...
	return true;
}

void CApplyForLeave::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CApplyForLeave, CDialogEx)
	ON_BN_CLICKED(IDD_DIALOG_APPLYFORLEAVE, &CApplyForLeave::OnBnClickedDialogApplyforleave)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CApplyForLeave::OnDtnDatetimechangeDatetimepicker1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CApplyForLeave::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CApplyForLeave message handlers
void CApplyForLeave::OnBnClickedDialogApplyforleave()
{
	// TODO: Add your control notification handler code here
	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER1);
	Edit_Box1->GetWindowText(strFromDate);
	CDateTimeCtrl* datePicker = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	COleDateTime date;
	datePicker->GetTime(date);
	// convert date to struct tm
	struct tm localTime;
	localTime.tm_sec = (int)date.GetSecond();
	localTime.tm_min = (int)date.GetMinute();
	localTime.tm_hour = (int)date.GetHour();
	localTime.tm_mday = (int)date.GetDay();
	localTime.tm_mon = (int)date.GetMonth() - 1;
	localTime.tm_year = (int)date.GetYear() - 1900;
	// convert local time to string form
	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%m/%d/%y %H:%M:%S", &localTime);

	// print the date and time
	std::cout << "The selected date and time is: " << timeStr << std::endl;
	CString ResultFromDate = GetTicksNow(CString(timeStr));

	CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER2);
	Edit_Box2->GetWindowText(strToDate);
	CDateTimeCtrl* datePicker1 = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
	COleDateTime date1;
	datePicker1->GetTime(date1);
	// convert date to struct tm
	struct tm localTime1;
	localTime1.tm_sec = (int)date1.GetSecond();
	localTime1.tm_min = (int)date1.GetMinute();
	localTime1.tm_hour = (int)date1.GetHour();
	localTime1.tm_mday = (int)date1.GetDay();
	localTime1.tm_mon = (int)date1.GetMonth() - 1;
	localTime1.tm_year = (int)date1.GetYear() - 1900;
	// convert local time to string form
	char timeStr1[20];
	strftime(timeStr1, sizeof(timeStr1), "%m/%d/%y %H:%M:%S", &localTime1);

	// print the date and time
	std::cout << "The selected date and time is: " << timeStr1 << std::endl;
	CString ResultToDate = GetTicksNow(CString(timeStr1));



	CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_COMBO1);
	Edit_Box3->GetWindowText(strLeaveType);


	//GetDlgItem(IDC_EDIT1)->SetWindowText(strLeaveType);
	CEdit* Edit_Box4 = (CEdit*)GetDlgItem(IDC_EDIT1);
	Edit_Box4->GetWindowText(strSubject);


	CEdit* Edit_Box5 = (CEdit*)GetDlgItem(IDC_EDIT2);
	Edit_Box5->GetWindowText(strReason);

	strLeaveRequestStatus = _T("Not Yet Reviewed");
	strRequestRemarks = _T("Not Yet Reviewed");



	try {
		WCResults response;
		LeaveRequestDetails LeaveRequestDetail;
		LeaveRequestDetail.LeaveType = strSubject;
		LeaveRequestDetail.Username = CWebCloudAPITestApp::GetUsername();
		LeaveRequestDetail.LogType = "LeaveRequest";
		LeaveRequestDetail.LogDate = GetTicksNow1();
		LeaveRequestDetail.FromDate = ResultFromDate;
		LeaveRequestDetail.ToDate = ResultToDate;
		LeaveRequestDetail.LeaveReason = strReason;
		LeaveRequestDetail.LeaveRequestStatus = strLeaveRequestStatus;
		LeaveRequestDetail.LeaveRequestRemarks = strRequestRemarks;
		m_HRService->PostLeaveRequest(response, LeaveRequestDetail);
	}
	catch (const std::exception& e)
	{
		CString err(e.what());
		CWebCloudAPITestApp::SetResponseMsg(err);
	}

}
CString CApplyForLeave::GetTicksNow(CString Date)
{
	CString strDate = Date;
	COleDateTime dateTime;
	if (dateTime.ParseDateTime(strDate)) {
		COleDateTime epoch(100, 1, 1, 00, 00, 00);
		COleDateTimeSpan span = dateTime - epoch;
		CTimeSpan cSpan(span.GetDays(), span.GetHours(), span.GetMinutes(), span.GetSeconds());
		ULONGLONG diff = cSpan.GetTotalSeconds();
		LONG missingDays = 365 * 99 + 24;
		CTimeSpan centSpan(missingDays, 0, 0, 0);
		ULONGLONG centSeconds = centSpan.GetTotalSeconds();
		ULONGLONG totSec = (diff + centSeconds) * 10000000;
		CString strDiff;
		strDiff.Format(_T("%I64u"), totSec);
		return strDiff;
	}
	else {
		return _T("Invalid date/time string");
	}
}

CString CApplyForLeave::GetTicksNow1()
{
	COleDateTime epoch(100, 1, 1, 00, 00, 00);
	COleDateTime currTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = currTime - epoch;
	CTimeSpan cSpan(span.GetDays(), span.GetHours(), span.GetMinutes(), span.GetSeconds());
	ULONGLONG diff = cSpan.GetTotalSeconds();
	LONG missingDays = 365 * 99 + 24;
	CTimeSpan centSpan(missingDays, 0, 0, 0);
	ULONGLONG centSeconds = centSpan.GetTotalSeconds();// *1000000000;//
	ULONGLONG totSec = (diff + centSeconds) * 10000000;
	CString strDiff;
	strDiff.Format(_T("%I64u"), totSec);
	return strDiff;
}

void CApplyForLeave::OnDtnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here

	*pResult = 0;
}


void CApplyForLeave::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	 // Get the current value of the combo box
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int nIndex = pComboBox->GetCurSel();
	pComboBox->GetLBText(nIndex, strLeaveType);

	// Update the edit box with the selected leave type
	if (strLeaveType != "Others(Specify)")
	{
		GetDlgItem(IDC_EDIT1)->SetWindowText(strLeaveType);
	}

	// Get the current value of the subject edit box
	CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEditBox->GetWindowText(strSubject);
	CString strSubject = GetSubjectText();
}
CString CApplyForLeave::GetSubjectText()
{
	CString strSubject;
	CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEditBox->GetWindowText(strSubject);
	return strSubject;
}
