// CTaskForm.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CTaskForm.h"
#include "afxdialogex.h"


// CTaskForm dialog

IMPLEMENT_DYNAMIC(CTaskForm, CDialogEx)

CTaskForm::CTaskForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TASKFORM, pParent)
{

}

CTaskForm::~CTaskForm()
{
}

void CTaskForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TASKLIST, m_listctrl);
}

BOOL CTaskForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_listctrl.InsertColumn(1, L"MsgID", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(0, L"Select", LVCFMT_CENTER, 70);
	m_listctrl.InsertColumn(1, L"SL No", LVCFMT_CENTER, 60);
	m_listctrl.InsertColumn(2, L"Task Name", LVCFMT_CENTER, 150);
	m_listctrl.InsertColumn(3, L"Task Description", LVCFMT_CENTER, 200);

	SHOWTASK();
	return TRUE;

}
BEGIN_MESSAGE_MAP(CTaskForm, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SAVE2, &CTaskForm::OnBnClickedButtonSave2)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CTaskForm::OnBnClickedButtonCancel)
END_MESSAGE_MAP()


// CTaskForm message handlers
void CTaskForm::SHOWTASK()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_CHECKBOXES);
	m_InfoArray.RemoveAll();

	m_PMService->TASKVIEWLIST(m_InfoArray);

	for (unsigned int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		int nItem;
		nItem = m_listctrl.InsertItem(i, _T(""));
		CString  slno;
		slno.Format(_T("%d"), i + 1);
		m_listctrl.SetItemText(nItem, 1, slno);
		m_listctrl.SetItemText(nItem, 2, m_InfoArray[i].TaskTitle);
		m_listctrl.SetItemText(nItem, 3, m_InfoArray[i].TaskDescription);
	}
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | TVS_HASBUTTONS);
}


void CTaskForm::OnBnClickedButtonSave2()
{
	// TODO: Add your control notification handler code here
	Task_Details info;
	info.TaskID = _T("");
	GetDlgItem(IDC_EDIT_TASKNAME)->GetWindowText(info.TaskTitle);
	GetDlgItem(IDC_EDIT_TASKDESC)->GetWindowText(info.TaskDescription);
	m_PMService->AddNewTask(info);
	m_listctrl.DeleteAllItems();
	SHOWTASK();
}


void CTaskForm::OnBnClickedButtonCancel()
{
	// TODO: Add your control notification handler code here
	
}
