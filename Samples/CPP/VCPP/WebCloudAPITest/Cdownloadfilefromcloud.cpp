// Cdownloadfilefromcloud.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "Cdownloadfilefromcloud.h"
#include "afxdialogex.h"


// Cdownloadfilefromcloud dialog

IMPLEMENT_DYNAMIC(Cdownloadfilefromcloud, CDialogEx)

Cdownloadfilefromcloud::Cdownloadfilefromcloud(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DOWNLOADFILEFROMCLOUD, pParent)
{

}

Cdownloadfilefromcloud::~Cdownloadfilefromcloud()
{
}

void Cdownloadfilefromcloud::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cdownloadfilefromcloud, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &Cdownloadfilefromcloud::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cdownloadfilefromcloud::OnBnClickedButton4)
END_MESSAGE_MAP()


// Cdownloadfilefromcloud message handlers


void Cdownloadfilefromcloud::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	
		// szFilters is a text string that includes two file name filters:
		// "*.my" for "MyType Files" and "*.*' for "All Files."
		TCHAR szFilters[] = _T("MyType Files (*.my)|*.my|All Files (*.*)|*.*||");

		// Create an Open dialog; the default file name extension is ".my".
		CFileDialog fileDlg(TRUE, _T("my"), _T("*.my"),
			OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

		// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
		// returns IDOK.
		if (fileDlg.DoModal() == IDOK)
		{
			CString pathName = fileDlg.GetPathName();

			// Implement opening and reading file in here.

			//Change the window's title to the opened file's title.
			CString fileName = fileDlg.GetFileTitle();

			SetWindowText(fileName);
		}
	

}


void Cdownloadfilefromcloud::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDOK);
	
}
