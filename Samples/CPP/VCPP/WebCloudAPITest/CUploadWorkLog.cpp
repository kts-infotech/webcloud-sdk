// CUploadWorkLog.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CUploadWorkLog.h"
#include "afxdialogex.h"
#include <Ctime>
#include<string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <GdiPlus.h>
#pragma comment(lib, "GdiPlus.lib")

using namespace Gdiplus;


// CUploadWorkLog dialog

IMPLEMENT_DYNAMIC(CUploadWorkLog, CDialogEx)
HWND hButton, hStatic;
HBITMAP hScreenshot = NULL;





CString CaptureTime()
{
    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the time to a string format
    char timeStr[100];
    struct tm timeStruct;
    localtime_s(&timeStruct, &currentTime); // Use localtime_s
    std::strftime(timeStr, sizeof(timeStr), "CaptureTime::%I:%M:%S %p", &timeStruct);

    // Convert the char array to a CString
    CString result(timeStr);

    return result;
}
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
    UINT num = 0;           // number of image encoders
    UINT size = 0;          // size of the image encoder array in bytes

    ImageCodecInfo* pImageCodecInfo = NULL;

    GetImageEncodersSize(&num, &size);
    if (size == 0)
        return -1;  // Failure

    pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == NULL)
        return -1;  // Failure

    GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT j = 0; j < num; ++j) {
        if (_wcsicmp(pImageCodecInfo[j].MimeType, format) == 0) {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j;  // Success
        }
    }

    free(pImageCodecInfo);
    return -1;  // Failure
}
void TakeAndSaveScreenshot(const wchar_t* filePath)
{
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // Set the desired screenshot dimensions
    int captureWidth = 640;
    int captureHeight = 480;

    // Create a bitmap to capture the scaled screen
    HDC screenDC = GetDC(NULL);
    HDC memDC = CreateCompatibleDC(screenDC);
    HBITMAP screenshotBitmap = CreateCompatibleBitmap(screenDC, captureWidth, captureHeight);
    SelectObject(memDC, screenshotBitmap);

    int captureX = 640; // X coordinate of the capture area
    int captureY = 480; // Y coordinate of the capture area
    BitBlt(memDC, 0, 0, captureWidth, captureHeight, screenDC, captureX, captureY, SRCCOPY);

    // Save the screenshot
    Bitmap* screenshot = new Bitmap(screenshotBitmap, NULL);
    CLSID pngClsid;
    GetEncoderClsid(L"image/png", &pngClsid);
    screenshot->Save(filePath, &pngClsid, NULL);

    // Clean up
    delete screenshot;
    DeleteObject(screenshotBitmap);
    DeleteDC(memDC);
    ReleaseDC(NULL, screenDC);

    // Shutdown GDI+
    GdiplusShutdown(gdiplusToken);
}

void CUploadWorkLog::OnBnClickedTakeScreenshot()
{
    {
        CString captureTime = CaptureTime();  // Get the formatted time string

        // Assign the formatted time string to m_MessageText
        m_MessageText = captureTime;

        // Update the message box with the new text
        UpdateData(FALSE); // This updates the UI with the new value

        const wchar_t* filePath = L"C:\\Users\\Public\\DesktopScreenShot.png";
       
        TakeAndSaveScreenshot(filePath);

        CImage image;
        if (image.Load(filePath) == S_OK)
        {
            CWnd* pPictureBox = GetDlgItem(IDC_SHOW);
            if (pPictureBox)
            {
                CRect rect;
                pPictureBox->GetClientRect(&rect);

                CDC* pDC = pPictureBox->GetDC();
                if (pDC)
                {
                    image.Draw(pDC->m_hDC, rect);
                    pPictureBox->ReleaseDC(pDC);
                }

            }
        }
    }
    CWebCloudAPITestApp::SetResponseMsg(L"ScreenShot Captured");

}











CUploadWorkLog::CUploadWorkLog(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_UPLOADWORKLOG, pParent)

    , m_MessageText(_T(""))

{

}


CUploadWorkLog::~CUploadWorkLog()
{

}

void CUploadWorkLog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);


    DDX_Text(pDX, IDC_SEOSETTINGS, m_MessageText);
   
}


BEGIN_MESSAGE_MAP(CUploadWorkLog, CDialogEx)

    ON_BN_CLICKED(IDC_BUTTON1, &CUploadWorkLog::OnBnClickedUpload)
    ON_BN_CLICKED(IDC_BUTTON2, &CUploadWorkLog::OnBnClickedClose)

    ON_BN_CLICKED(IDC_BUTTON3, &CUploadWorkLog::OnBnClickedTakeScreenshot)
END_MESSAGE_MAP()


// CUploadWorkLog message handlers

void CUploadWorkLog::OnBnClickedUpload()
{
    // TODO: Add your control notification handler code here
}


void CUploadWorkLog::OnBnClickedClose()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}







void CUploadWorkLog::OnEnChangeEdit5()
{

}










