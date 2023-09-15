// CTTDataSummery.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CTTDataSummery.h"
#include "afxdialogex.h"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <atlstr.h> 


// CTTDataSummery dialog

IMPLEMENT_DYNAMIC(CTTDataSummery, CDialogEx)
CString TDHRS(int workingHoursStart, int workingHoursEnd);

// Function declarations for TDHRS_Weekly and TDHRS_Monthly
CString TDHRS_Weekly(int workingHoursStart, int workingHoursEnd);
CString TDHRS_Monthly(int workingHoursStart, int workingHoursEnd);

CString TDHRS(int workingHoursStart, int workingHoursEnd)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    // Calculate the working hours duration
    int currentHour = now_tm.tm_hour;
    int currentMinute = now_tm.tm_min;

    int workingHourStartInMinutes = workingHoursStart * 60;
    int workingHourEndInMinutes = workingHoursEnd * 60;
    int currentTimeInMinutes = currentHour * 60 + currentMinute;

    int workingMinutes;

    if (currentTimeInMinutes < workingHourStartInMinutes) {
        workingMinutes = 0; // The system hasn't started working yet.
    }
    else if (currentTimeInMinutes > workingHourEndInMinutes) {
        workingMinutes = workingHourEndInMinutes - workingHourStartInMinutes;
    }
    else {
        workingMinutes = currentTimeInMinutes - workingHourStartInMinutes;
    }

    // Convert the working minutes to hours and minutes
    int workingHours = workingMinutes / 60;
    int remainingMinutes = workingMinutes % 60;

    // Convert the working hours and remaining minutes to CStrings
    CString workingHoursString, remainingMinutesString;
    workingHoursString.Format(_T("%d"), workingHours);
    remainingMinutesString.Format(_T("%d"), remainingMinutes);

    // Construct the result using CStrings
    CString result;
    result.Format(_T("%s::%s"), workingHoursString, remainingMinutesString);

    return result;
}

CString TDHRS_Weekly(int workingHoursStart, int workingHoursEnd)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    // Calculate the week starting time (Sunday midnight)
    std::tm weekStart_tm = now_tm;
    weekStart_tm.tm_hour = 0;
    weekStart_tm.tm_min = 0;
    weekStart_tm.tm_sec = 0;
    weekStart_tm.tm_wday = 0; // 0 represents Sunday
    int daysSinceSunday = now_tm.tm_wday;
    weekStart_tm.tm_mday -= daysSinceSunday;

    // Calculate the total working hours for the week
    int currentWeekDay = now_tm.tm_wday;
    int workingDaysInCurrentWeek = currentWeekDay + 1; // +1 to include the current day
    int totalWorkingMinutes = workingDaysInCurrentWeek * (workingHoursEnd - workingHoursStart) * 60;

    // If it's not a working day yet, set total working minutes to zero
    if (currentWeekDay < 1 || currentWeekDay > 5) {
        totalWorkingMinutes = 0;
    }
    else {
        // Calculate the working minutes for the current day
        int currentTimeInMinutes = now_tm.tm_hour * 60 + now_tm.tm_min;
        int workingHourStartInMinutes = workingHoursStart * 60;

        if (currentTimeInMinutes < workingHourStartInMinutes) {
            totalWorkingMinutes -= (workingHourStartInMinutes - currentTimeInMinutes);
        }
    }

    // Convert total working minutes to hours and minutes
    int workingHours = totalWorkingMinutes / 60;
    int remainingMinutes = totalWorkingMinutes % 60;

    // Convert the working hours and remaining minutes to CStrings
    CString workingHoursString, remainingMinutesString;
    workingHoursString.Format(_T("%d"), workingHours);
    remainingMinutesString.Format(_T("%d"), remainingMinutes);

    // Construct the result using CStrings
    CString result;
    result.Format(_T("%s::%s"), workingHoursString, remainingMinutesString);



    return result;
}

CString TDHRS_Monthly(int workingHoursStart, int workingHoursEnd)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);
    // Calculate the month starting time (1st day of the month)
    std::tm monthStart_tm = now_tm;
    monthStart_tm.tm_hour = 0;
    monthStart_tm.tm_min = 0;
    monthStart_tm.tm_sec = 0;
    monthStart_tm.tm_mday = 1;

    // Calculate the total working hours for the month
    int currentDayOfMonth = now_tm.tm_mday;
    int totalWorkingDaysInCurrentMonth = currentDayOfMonth;
    int totalWorkingMinutes = totalWorkingDaysInCurrentMonth * (workingHoursEnd - workingHoursStart) * 60;

    // If it's not a working day yet, set total working minutes to zero
    if (currentDayOfMonth < 1 || currentDayOfMonth > 31) {
        totalWorkingMinutes = 0;
    }
    else {
        // Calculate the working minutes for the current day
        int currentTimeInMinutes = now_tm.tm_hour * 60 + now_tm.tm_min;
        int workingHourStartInMinutes = workingHoursStart * 60;

        if (currentTimeInMinutes < workingHourStartInMinutes) {
            totalWorkingMinutes -= (workingHourStartInMinutes - currentTimeInMinutes);
        }
    }

    // Convert total working minutes to hours and minutes
    int workingHours = totalWorkingMinutes / 60;
    int remainingMinutes = totalWorkingMinutes % 60;

    // Convert the working hours and remaining minutes to CStrings
    CString workingHoursString, remainingMinutesString;
    workingHoursString.Format(_T("%d"), workingHours);
    remainingMinutesString.Format(_T("%d"), remainingMinutes);

    // Construct the result using CStrings
    CString result;
    result.Format(_T("%s::%s"), workingHoursString, remainingMinutesString);

    return result;
}

int Final()
{
    int workingHoursStart, workingHoursEnd;

    std::cout << "Enter working hours start (in 24-hour format): ";
    std::cin >> workingHoursStart;

    std::cout << "Enter working hours end (in 24-hour format): ";
    std::cin >> workingHoursEnd;

    CString todayResult = TDHRS(workingHoursStart, workingHoursEnd);
    CString weeklyResult = TDHRS_Weekly(workingHoursStart, workingHoursEnd);
    CString monthlyResult = TDHRS_Monthly(workingHoursStart, workingHoursEnd);

    return 0;
}


CTTDataSummery::CTTDataSummery(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_TTDATASUMMERY, pParent)

    , m_WeekHours(TDHRS(8, 17))
    , m_MonthHours(TDHRS_Weekly(8, 17))
    , m_TodayHours(TDHRS_Monthly(8, 17))
   
{
}
CTTDataSummery::~CTTDataSummery()
{
}

void CTTDataSummery::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
   
    DDX_Text(pDX, IDC_EDIT1, m_TodayHours);
    DDX_Text(pDX, IDC_EDIT2, m_WeekHours);
    DDX_Text(pDX, IDC_EDIT7, m_MonthHours);
    CWebCloudAPITestApp::SetResponseMsg(L"Data Summary Tracked");
}


BEGIN_MESSAGE_MAP(CTTDataSummery, CDialogEx)

END_MESSAGE_MAP()


// CTTDataSummery message handlers





