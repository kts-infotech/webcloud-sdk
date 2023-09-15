// CGetLicenseInfo.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "afxdialogex.h"
#include <winhttp.h>
#include "tchar.h"
#include "CGetLicenseInfo.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <algorithm> 
#pragma once

#include "NetworkRequest.h" 





// CGetLicenseInfo dialog

IMPLEMENT_DYNAMIC(CGetLicenseInfo, CDialogEx)

CString GetEntryTime() {
	static CString formattedTime;

	if (formattedTime.IsEmpty()) {
		// Set the desired date and time components
		int year = 2023;
		int month = 6;
		int day = 4;

		// Formatting the date and time as a string
		formattedTime.Format(_T("%02d-%02d-%d"), day, month, year);

		// Displaying the current date and time (Optional)
		std::wcout << year << "-" << month << "-" << day << std::endl;
	}

	return formattedTime;
}
CString GetMACaddresss()
{
	CString r;
	IP_ADAPTER_INFO info[16];
	ULONG size = sizeof(info);

	// Call GetAdaptersInfo to retrieve adapter information
	DWORD status = GetAdaptersInfo(info, &size);

	// Iterate over the adapters and print their MAC addresses
	if (status == ERROR_SUCCESS) {
		IP_ADAPTER_INFO* pAdapterInfo = info;
		while (pAdapterInfo) {
			r.Format(_T(" %02X%02X%02X%02X%02X%02X"), pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2],
				pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
			pAdapterInfo = pAdapterInfo->Next;
		}
	}
	return r;
}
CString Noofdays()
{
	// Set the target date (2023-06-04)
	int targetYear = 2023;
	int targetMonth = 6;
	int targetDay = 4;

	// Get the current date
	time_t now = time(nullptr);
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);

	// Set the target date
	struct tm targetTimeinfo = { 0 };
	targetTimeinfo.tm_year = targetYear - 1900;
	targetTimeinfo.tm_mon = targetMonth - 1;
	targetTimeinfo.tm_mday = targetDay;

	// Calculate the time difference in seconds
	std::chrono::seconds diff = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::from_time_t(mktime(&timeinfo)) - std::chrono::system_clock::from_time_t(mktime(&targetTimeinfo)));

	// Calculate the number of days
	int daysDifference = diff.count() / (60 * 60 * 24);

	// Cap the daysDifference at 30 days
	const int maxDays = 30;
	if (daysDifference > maxDays) {
		daysDifference = maxDays;
	}

	// Convert the daysDifference integer to a CString
	CString cstrDaysDifference;
	cstrDaysDifference.Format(_T("%d"), daysDifference);

	return cstrDaysDifference;
}
CString GetDaysRemaining(int year, int month, int day)
{

	time_t now = time(nullptr);
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);
    
	

	// Set the target date
	std::tm targetTime_t = { 0, 0, 0, day, month - 1, year - 1900 };

	// Convert to system time
	std::time_t target = std::mktime(&targetTime_t);

	// Calculate the time difference in seconds
	std::chrono::seconds diff = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::from_time_t(target) - std::chrono::system_clock::from_time_t(now));

	// Calculate the number of remaining days
	int daysRemaining = diff.count() / (60 * 60 * 24);

	// Convert the daysRemaining integer to a string
	std::string daysRemainingStr = std::to_string(daysRemaining);

	// Convert the std::string to a CString
	CString cstrDaysRemaining(daysRemainingStr.c_str());

	return cstrDaysRemaining;
}

CGetLicenseInfo::CGetLicenseInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GETLICENSEINFO, pParent)
	, m_MACAddress(GetMACaddresss())
	, m_Details(_T(""))
{

}

CGetLicenseInfo::~CGetLicenseInfo()
{

}

void CGetLicenseInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_MACAddress);
	DDX_Text(pDX, IDC_EDIT2, m_Details);
}


BEGIN_MESSAGE_MAP(CGetLicenseInfo, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CGetLicenseInfo::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CGetLicenseInfo::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CGetLicenseInfo::OnEnChangeDetails)
	ON_EN_CHANGE(IDC_EDIT1, &CGetLicenseInfo::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CGetLicenseInfo message handlers

void CGetLicenseInfo::OnEnChangeDetails()
{
    // Retrieve the selected product from the combo box
    CString selectPrdt;
    CComboBox* combo_Box_drop = (CComboBox*)GetDlgItem(IDC_COMBO1);
    combo_Box_drop->GetWindowText(selectPrdt);

    // Get a pointer to the edit control
    CEdit* pEditControl = (CEdit*)GetDlgItem(IDC_EDIT2);

    // Get the current text in the edit control
    CString currentText;
    pEditControl->GetWindowText(currentText);

    // Check if the text actually changed
  
    CString NewText;
  
    if (selectPrdt == "Desktop Streamer")
    {
        // Construct the new text based on the selected product
        NewUserRegInfo info; // Declare and initialize the 'info' object
        
       
        NewText += _T("LicenseStatus		: ") + info.LicenseStatus + _T("\r\n");
        NewText += _T("Machine Name		: ") + info.MachineName + _T("\r\n");
        NewText += _T("Product Name		: ") + info.ProductName + _T("\r\n");
        NewText += _T("Product ID		: ") + info.ProductID + _T("\r\n");
        NewText += _T("EmailID			: ") + info.EmailID + _T("\r\n");
        NewText += _T("Is Unlimited License		: ") + (info.IsUnlimitedLicense)+_T(" False") + _T("\r\n");
        NewText += _T("License Name		: ") + info.LicenseName + _T(" DesktopStreamer | One Month | Unlimited") + _T("\r\n");
        NewText += _T("No Of Days		: ") + info.NoOfDays +  Noofdays() +_T("\r\n");
        NewText += _T("Date of Entry		: ") + info.DateofEntry + GetEntryTime() + _T("\r\n");
        NewText += _T("regKey			: ") + info.RegKey + _T("\r\n");
        NewText += _T("Email Status		: ") + info.EmailStatus  + _T("\r\n");
        NewText += _T("Person Name		: ") + info.PersonName  + _T("\r\n");
        NewText += _T("LicensePassword		: ") + info.LicensePassword  + _T("\r\n");
        NewText += _T("Hardware ID		: ") + info.HardwareID + GetMACaddresss() + _T("\r\n");
        NewText += _T("License ID		: ") + info.LicenseID  + _T("\r\n");
        NewText += _T("Remaining Days		: ") + info.RemainingDays + GetDaysRemaining(2023, 6, 4) + _T("\r\n");
        NewText += _T("Allowed Features		: ") + info.AllowedFeatures  +_T(" ALL") + _T("\r\n");
        NewText += _T("Disabled Features		: ") + info.DisabledFeatures +_T(" None") + _T("\r\n");
        NewText += _T("Initial License		: ") + info.InitialLicense +_T(" True") + _T("\r\n");
        NewText += _T("Product Subscription Id	: ") + info.ProductSubID +_T(" DKST1") + _T("\r\n");
    }
    else if (selectPrdt == "WebCloud")
    {
        NewText = _T("Product not Found");
    }
 

    // Set the new text only if it has changed
    if (NewText != currentText)
    {
        pEditControl->SetWindowText(NewText);
    }
}
void CGetLicenseInfo::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString Macid = GetMACaddresss();
	CComboBox* combo_Box_drop = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int selectedIndex = combo_Box_drop->GetCurSel();
	if (selectedIndex==0)
	{
		CString selectPrdt = L"DKST1";
		
	}
	else
	{
		CString selectPrdt = L"WC45E";
	}
	
	m_LicenseService->GetLicenseInfo(selectPrdt, Macid);
	OnEnChangeDetails();
	CWebCloudAPITestApp::SetResponseMsg(Macid);

}


void CGetLicenseInfo::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}






void CGetLicenseInfo::OnEnChangeEdit1()
{
	
}
