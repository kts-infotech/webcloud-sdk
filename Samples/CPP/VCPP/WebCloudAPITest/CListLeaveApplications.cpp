// CListLeaveApplications.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CListLeaveApplications.h"
#include "afxdialogex.h"


// CListLeaveApplications dialog

IMPLEMENT_DYNAMIC(CListLeaveApplications, CDialogEx)

CListLeaveApplications::CListLeaveApplications(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LISTALLLEAVEAPPLICATIONSFORM, pParent)
{
	m_HRServices = CWebCloudAPITestApp::m_pAppApiService;
}

CListLeaveApplications::~CListLeaveApplications()
{
}

void CListLeaveApplications::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}
BOOL CListLeaveApplications::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_listctrl.InsertColumn(1, L"MsgID", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(0, L"Select", LVCFMT_CENTER, 60);
	m_listctrl.InsertColumn(1, L"Sl No", LVCFMT_CENTER, 50);
	m_listctrl.InsertColumn(2, L"LogID", LVCFMT_CENTER, 50);
	m_listctrl.InsertColumn(3, L"UserName", LVCFMT_CENTER, 180);
	m_listctrl.InsertColumn(4, L"FromDate", LVCFMT_CENTER, 200);
	m_listctrl.InsertColumn(5, L"ToDate", LVCFMT_CENTER, 200);
	m_listctrl.InsertColumn(6, L"LeaveType", LVCFMT_CENTER, 130);
	m_listctrl.InsertColumn(7, L"Reason", LVCFMT_CENTER, 155);
	m_listctrl.InsertColumn(8, L"Request Status", LVCFMT_CENTER, 130);
	m_listctrl.InsertColumn(9, L"Request Remarks", LVCFMT_CENTER, 130);
	SHOWLEAVELIST();
	return TRUE;
}


BEGIN_MESSAGE_MAP(CListLeaveApplications, CDialogEx)
	ON_BN_CLICKED(IDCLOSE, &CListLeaveApplications::OnBnClickedClose)
END_MESSAGE_MAP()


// CListLeaveApplications message handlers


void CListLeaveApplications::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
}

void CListLeaveApplications::SHOWLEAVELIST()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_CHECKBOXES);
	m_InfoArray.RemoveAll();

	m_HRServices->LEAVEVIEWLIST(m_InfoArray);

	for (unsigned int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		LeaveRequestDetails leaverequestDetail;
		int nItem;
		nItem = m_listctrl.InsertItem(i, _T(""));
		CString  slno;
		slno.Format(_T("%d"), i + 1);
		m_listctrl.SetItemText(nItem, 1, slno);
		m_listctrl.SetItemText(nItem, 2, m_InfoArray[i].LogID);
		m_listctrl.SetItemText(nItem, 3, m_InfoArray[i].Username);
		//m_listctrl.SetItemText(nItem, 3, m_InfoArray[i].LogDate);

		CString a = m_InfoArray[i].FromDate;
		int digitCount = 0;
		for (int i = 0; i < a.GetLength(); i++) {
			if (isdigit(a[i])) {
				digitCount++;
			}
		}
		if (digitCount == 18) {
			ULONGLONG num = _ttoi64(a);
			COleDateTime date = GetDateFromTicks(num);
			CString strdate = date.Format(_T("%A, %B %d, %Y"));
			m_InfoArray[i].FromDate = strdate;
		}

		m_listctrl.SetItemText(nItem, 4, m_InfoArray[i].FromDate);

		CString a1 = m_InfoArray[i].ToDate;
		int digitCount1 = 0;
		for (int i = 0; i < a1.GetLength(); i++) {
			if (isdigit(a1[i])) {
				digitCount1++;
			}
		}
		if (digitCount1 == 18) {
			ULONGLONG num1 = _ttoi64(a1);
			COleDateTime date1 = GetDateFromTicks(num1);
			CString strdate1 = date1.Format(_T("%A, %B %d, %Y"));
			m_InfoArray[i].ToDate = strdate1;
		}

		m_listctrl.SetItemText(nItem, 5, m_InfoArray[i].ToDate);
		m_listctrl.SetItemText(nItem, 6, m_InfoArray[i].LeaveType);
		m_listctrl.SetItemText(nItem, 7, m_InfoArray[i].LeaveReason);
		m_listctrl.SetItemText(nItem, 8, m_InfoArray[i].LeaveRequestStatus);
		m_listctrl.SetItemText(nItem, 9, m_InfoArray[i].LeaveRequestRemarks);

	}
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | TVS_HASBUTTONS);
}
COleDateTime CListLeaveApplications::GetDateFromTicks(ULONGLONG date)
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