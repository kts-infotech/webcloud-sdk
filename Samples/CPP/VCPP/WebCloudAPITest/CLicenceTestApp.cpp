#include "pch.h"
#include "WebCloudAPITest.h"
#include "CLicenceTestApp.h"
#include "afxdialogex.h"
#include <ctime>
#include <chrono>
#include <string>
#include <afxwin.h> 



// CLicenceTestApp dialog

IMPLEMENT_DYNAMIC(CLicenceTestApp, CDialogEx)

CLicenceTestApp::CLicenceTestApp(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_LICENCESTESTAPP, pParent)
{

}

CLicenceTestApp::~CLicenceTestApp()
{
}

void CLicenceTestApp::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLicenceTestApp, CDialogEx)

END_MESSAGE_MAP()


// CLicenceTestApp message handlers


BOOL CLicenceTestApp::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Your existing code for target date and time calculation
    int targetYear = 2023;
    int targetMonth = 8;
    int targetDay = 11;

    CTime currentTime = CTime::GetCurrentTime();
    CTime targetTime(targetYear, targetMonth, targetDay, 0, 0, 0);
    CTimeSpan timeDifference = targetTime - currentTime;
    int daysRemaining = timeDifference.GetDays();

    // Get a pointer to the button with ID "IDOK"
    CWnd* pButton = GetDlgItem(IDOK);

    if (pButton) {
        CTime lastDayOfMonth(targetYear, targetMonth + 1, 1, 0, 0, 0);
        lastDayOfMonth -= CTimeSpan(1, 0, 0, 0);
        int daysDifference = (lastDayOfMonth - currentTime).GetDays();

        // Enable or disable the button based on the conditions
        if (daysDifference > 30 || daysDifference < 0)
        {
            pButton->EnableWindow(FALSE); // Disable the button
            CWebCloudAPITestApp::SetResponseMsg(L"Button Inactive");

        }
        else
        {
            pButton->EnableWindow(TRUE);  // Enable the button
            CWebCloudAPITestApp::SetResponseMsg(L"Button Activated");

        }
    }
 

    return TRUE;  // return TRUE unless you set the focus to a control
}