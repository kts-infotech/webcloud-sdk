// CSubTaskForm.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CSubTaskForm.h"
#include "afxdialogex.h"


// CSubTaskForm dialog

IMPLEMENT_DYNAMIC(CSubTaskForm, CDialogEx)

CSubTaskForm::CSubTaskForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SUBTASKFORM, pParent)
{

}

CSubTaskForm::~CSubTaskForm()
{
}

void CSubTaskForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SUBTASKLIST, m_listctrl);
}

BOOL CSubTaskForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_listctrl.InsertColumn(1, L"MsgID", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(0, L"Select", LVCFMT_CENTER, 70);
	m_listctrl.InsertColumn(1, L"SL No", LVCFMT_CENTER, 60);
	m_listctrl.InsertColumn(2, L"SubTask Name", LVCFMT_CENTER, 150);
	m_listctrl.InsertColumn(3, L"SubTask Description", LVCFMT_CENTER, 200);

	SHOWSUBTASK();
	return TRUE;

}


BEGIN_MESSAGE_MAP(CSubTaskForm, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CSubTaskForm::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CSubTaskForm::OnBnClickedButton4)
END_MESSAGE_MAP()


// CSubTaskForm message handlers
void CSubTaskForm::SHOWSUBTASK()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_CHECKBOXES);
	m_InfoArray.RemoveAll();

	m_PMService->SUBTASKVIEWLIST(m_InfoArray);

	for (unsigned int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		int nItem;
		nItem = m_listctrl.InsertItem(i, _T(""));
		CString  slno;
		slno.Format(_T("%d"), i + 1);
		m_listctrl.SetItemText(nItem, 1, slno);
		m_listctrl.SetItemText(nItem, 2, m_InfoArray[i].SubTaskTitle);
		m_listctrl.SetItemText(nItem, 3, m_InfoArray[i].SubTaskDescription);
	}
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | TVS_HASBUTTONS);
}



void CSubTaskForm::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	SubTaskDetails info;
	info.SubTaskID = _T("");
	GetDlgItem(IDC_EDIT_SUBTASKNAME)->GetWindowText(info.SubTaskTitle);
	GetDlgItem(IDC_EDIT_SUBTASKDESC)->GetWindowText(info.SubTaskDescription);
	m_PMService->AddNewSubTask(info);
	m_listctrl.DeleteAllItems();
	SHOWSUBTASK();
}


void CSubTaskForm::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
}
