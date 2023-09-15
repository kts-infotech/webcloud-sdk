// CGetTTSettings.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CGetTTSettings.h"
#include "afxdialogex.h"
#include <iostream>
#include <windows.h>
#include <ctime> 
#include <chrono> 
#include <ctime>
#include <iomanip>

// CGetTTSettings dialog

IMPLEMENT_DYNAMIC(CGetTTSettings, CDialogEx)

ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t>>> GetTimeZoneName() {
    // Get the current dynamic time zone information
    DYNAMIC_TIME_ZONE_INFORMATION timeZoneInfo;
    DWORD result = GetDynamicTimeZoneInformation(&timeZoneInfo);

    if (result == TIME_ZONE_ID_INVALID) {
        // Return an empty string or an appropriate error message
        return L"Failed to get time zone information.";
    }

    // Return the time zone name
    return timeZoneInfo.TimeZoneKeyName;
}

int main() {
    // Call the function to get the time zone name
    ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t>>> timeZoneName = GetTimeZoneName();

    // Display the time zone name
    std::wcout << L"Time Zone Name: " << timeZoneName << std::endl;

    return 0;
}
CString GetScreenResolution() {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    CString resolution;
    resolution.Format(_T("%dx%d"), screenWidth, screenHeight);

    return resolution;
}

CGetTTSettings::CGetTTSettings(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_GETTTSETTINGS, pParent)
    , m_TimeZone(GetTimeZoneName())
    , m_IdleTime(_T("5"))
    , m_TimeZoneCode(_T("190"))
    , m_ActivityCaptureInterval(_T("10"))
    , m_ScreenCaptureResolution(GetScreenResolution())
    
{

}

CGetTTSettings::~CGetTTSettings()
{
}


void CGetTTSettings::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, m_TimeZone);
    DDX_Text(pDX, IDC_EDIT2, m_IdleTime);
    DDX_Text(pDX, IDC_EDIT3, m_TimeZoneCode);
    DDX_Text(pDX, IDC_EDIT5, m_ActivityCaptureInterval);
    DDX_Text(pDX, IDC_EDIT8, m_ScreenCaptureResolution);

    // Construct the response message
    CString responseMsg;
    responseMsg.Format(_T("TimeZone: %s :: IdleTime: %s :: TimeZoneCode: %s :: ActivityCaptureInterval: %s :: ScreenCaptureResolution: %s"),
        m_TimeZone, m_IdleTime, m_TimeZoneCode, m_ActivityCaptureInterval, m_ScreenCaptureResolution);

    // Set the response message
    CWebCloudAPITestApp::SetResponseMsg(responseMsg);
}



BEGIN_MESSAGE_MAP(CGetTTSettings, CDialogEx)

END_MESSAGE_MAP()


// CGetTTSettings message handlers




