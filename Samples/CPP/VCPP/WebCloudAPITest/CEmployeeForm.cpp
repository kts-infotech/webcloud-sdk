// CEmployeeForm.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "CEmployeeForm.h"
#include "afxdialogex.h"
#include "NetworkRequest.h"
#include <iostream>


// CEmployeeForm dialog

IMPLEMENT_DYNAMIC(CEmployeeForm, CDialogEx)

CEmployeeForm::CEmployeeForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EMPLOYEEFORM, pParent)
{
	m_HRService = CWebCloudAPITestApp::m_pAppApiService;
}

CEmployeeForm::~CEmployeeForm()
{
}

void CEmployeeForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}

BOOL CEmployeeForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_listctrl.InsertColumn(1, L"MsgID", LVCFMT_CENTER, 100);
	m_listctrl.InsertColumn(0, L"Select", LVCFMT_CENTER, 70);
	m_listctrl.InsertColumn(1, L"Sl No", LVCFMT_CENTER, 60);
	m_listctrl.InsertColumn(2, L"Employee Name", LVCFMT_CENTER, 180);
	m_listctrl.InsertColumn(3, L"EMail-ID Office", LVCFMT_CENTER, 230);
	m_listctrl.InsertColumn(4, L"EMail-ID Personal", LVCFMT_CENTER, 230);
	m_listctrl.InsertColumn(5, L"Phone Number", LVCFMT_CENTER, 150);

	SHOWEMPLOYEE();
	CComboBox* typecombo = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	typecombo->AddString(L"Full Time");
	typecombo->AddString(L"Part Type");
	typecombo->AddString(L"Intern | Trainee");
	typecombo->SetCurSel(0);
	typecombo->GetLBText(0, Type);
	GetDlgItem(IDC_COMBO2)->GetWindowText(Type);

	CComboBox* typestatus = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	typestatus->AddString(L"None");
	typestatus->AddString(L"Active");
	typestatus->AddString(L"On Leave");
	typestatus->AddString(L"Left");
	typestatus->SetCurSel(0);
	typestatus->GetLBText(0, Status);
	GetDlgItem(IDC_COMBO1)->GetWindowText(Status);
	return TRUE;

}


BEGIN_MESSAGE_MAP(CEmployeeForm, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CEmployeeForm::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CEmployeeForm::OnCbnSelchangeCombo1)
	//ON_BN_CLICKED(IDCLEARALL, &CEmployeeForm::OnBnClickedClearall)
	ON_BN_CLICKED(IDCLOSE, &CEmployeeForm::OnBnClickedClose)
	ON_BN_CLICKED(IDC_BUTTON_DLT, &CEmployeeForm::OnBnClickedButtonDlt)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CEmployeeForm::OnBnClickedButtonEdit)
	ON_BN_CLICKED(ID_BUTTON_CLEARALL, &CEmployeeForm::OnBnClickedButtonClearall)
	ON_BN_CLICKED(ID_BUTTON_SAVE, &CEmployeeForm::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CEmployeeForm message handlers
void CEmployeeForm::SHOWEMPLOYEE()
{
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_CHECKBOXES);
	m_InfoArray.RemoveAll();

	m_HRService->EMPLOYEEVIEWLIST(m_InfoArray);

	for (unsigned int i = 0; i < m_InfoArray.GetSize(); i++)
	{
		int nItem;
		nItem = m_listctrl.InsertItem(i, _T(""));
		CString  slno;
		slno.Format(_T("%d"), i + 1);
		m_listctrl.SetItemText(nItem, 1, slno);
		m_listctrl.SetItemText(nItem, 2, m_InfoArray[i].EmployeeName);
		m_listctrl.SetItemText(nItem, 3, m_InfoArray[i].EmployeeEmailOff);
		m_listctrl.SetItemText(nItem, 4, m_InfoArray[i].EmployeeEmailHom);
		m_listctrl.SetItemText(nItem, 5, m_InfoArray[i].EmployeePh);

	}
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | TVS_HASBUTTONS);
}





void CEmployeeForm::OnBnClickedCancel3()
{
	// TODO: Add your control notification handler code here

}


void CEmployeeForm::OnBnClickedCancel4()
{
	// TODO: Add your control notification handler code here
}


void CEmployeeForm::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
void CEmployeeForm::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	CComboBox* typecombo = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	int cursel = typecombo->GetCurSel();
	Type.Format(_T("%d"), cursel);
	typecombo->SetWindowText(Type);
}


void CEmployeeForm::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	CComboBox* statuscombo = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	int cursel1 = statuscombo->GetCurSel();
	statuscombo->GetLBText(cursel1, Status);
	GetDlgItem(IDC_COMBO1)->GetWindowText(Status);
}






void CEmployeeForm::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}






int CEmployeeForm::GetSelectedCheckboxIndex()
{
	int nSelectedIndex = -1;

	// iterate through each item in the ListControl
	int nItemCount = m_listctrl.GetItemCount();
	for (int nIndex = 0; nIndex < nItemCount; nIndex++) {
		// check if the checkbox in the first column is checked
		if (m_listctrl.GetCheck(nIndex)) {
			nSelectedIndex = nIndex;
			break; // exit the loop as soon as a checked checkbox is found
		}
	}

	return nSelectedIndex;
}




void CEmployeeForm::AddUpdateDeleteEmployeeAPI()
{
	// TODO: Add your implementation code here.
	CString getAllEmployee = _T("api/HR/GetAllEmployeeDetails");
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(getAllEmployee);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(getAllEmployee);
		JSONArray root = jval->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();

			m_strEmployeeId.Add(jobj[L"EmployeeID"]->AsString().c_str());
			m_strEmployeeType.Add(jobj[L"EmployeeType"]->AsString().c_str());
			if (m_strEmployeeType[i] == _T("False"))
				m_strEmployeeType_new.Add(_T("Part Type"));
			else if (m_strEmployeeType[i] == _T("True"))
				m_strEmployeeType_new.Add(_T("Intern | Trainee"));
			else if (m_strEmployeeType[i] == _T("Full Time"))
				m_strEmployeeType_new.Add(_T("Full Time"));

			m_strEmployeeStatus.Add(jobj[L"EmployeeStatus"]->AsString().c_str());
			if (m_strEmployeeStatus[i] == _T("Active"))
				m_strEmployeeStatus_new.Add(_T("Active"));
			else if (m_strEmployeeStatus[i] == _T("Left"))
				m_strEmployeeStatus_new.Add(_T("Left"));
			else if (m_strEmployeeStatus[i] == _T("None"))
				m_strEmployeeStatus_new.Add(_T("None"));
			else if (m_strEmployeeStatus[i] == _T("On Leave"))
				m_strEmployeeStatus_new.Add(_T("On Leave"));
		}

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);
	}

}


void CEmployeeForm::SetCurrentTextCombo(int ID, CString text)
{
	CComboBox* comboBox = (CComboBox*)GetDlgItem(ID);
	comboBox->SetCurSel(comboBox->FindStringExact(0, text));
}





void CEmployeeForm::OnBnClickedButtonDlt()
{
	// TODO: Add your control notification handler code here
#if TRUE
	CArray<CString>EmployeeID;
	CArray<CString>EmployeeEmailOff;
	int nCount = m_listctrl.GetItemCount();
	if (nCount == -1)
	{
		// No item selected
		AfxMessageBox(_T("Please select an item to delete."), MB_ICONWARNING);
		return;
	}
	else
	{
		for (int i = 0; i < nCount; i++)
		{
			if (m_listctrl.GetCheck(i))
			{
				EmployeeID.Add(m_listctrl.GetItemText(i, 1));


			}
		}
		for (int i = 0; i < nCount; i++)
		{
			if (m_listctrl.GetCheck(i))
			{
				EmployeeEmailOff.Add(m_listctrl.GetItemText(i, 3));

			}
		}

		m_HRService->DeleteEmployee(EmployeeEmailOff[0]);
		m_listctrl.DeleteAllItems();
		SHOWEMPLOYEE();
	}



#else
	CString DeleteEmployee;
	CString ResponseMessage;
	DeleteEmployee.Format(_T("api/HR/DeleteEmployee?EmployeeId=%s"), EmployeeID);
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(DeleteEmployee);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		CWebCloudAPITestApp::SetResponseMsg(cstrRes);
		CWebCloudAPITestApp::SetStatusBarMsg(DeleteEmployee);
		CString strCompare = Jvalue->AsString().c_str();
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		CWebCloudAPITestApp::SetResponseMsg(errorStr);

	}
	return ResponseMessage;
#endif
}




void CEmployeeForm::OnBnClickedButtonEdit()
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(ID_BUTTON_SAVE, _T("Update"));
	int nCount = m_listctrl.GetItemCount();


	int nSelectedIndex = GetSelectedCheckboxIndex();

	if (nSelectedIndex != -1) {
		// do something with the selected checkbox's index value
	}
	else {
		AfxMessageBox(_T("Please select an item to edit."), MB_ICONWARNING);
	}


#if TRUE

	if (m_InfoArray[nSelectedIndex].EmployeeType == _T("0"))
		SetCurrentTextCombo(IDC_COMBO2, _T("Full Time"));
	else if (m_InfoArray[nSelectedIndex].EmployeeType == _T("1"))
		SetCurrentTextCombo(IDC_COMBO2, _T("Intern | Trainee"));
	else if (m_InfoArray[nSelectedIndex].EmployeeType == _T("2"))
		SetCurrentTextCombo(IDC_COMBO2, _T("Part Type"));

	if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("Active"))
		SetCurrentTextCombo(IDC_COMBO1, _T("Active"));
	else if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("Left"))
		SetCurrentTextCombo(IDC_COMBO1, _T("Left"));
	else if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("None"))
		SetCurrentTextCombo(IDC_COMBO1, _T("None"));
	else if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("On Leave"))
		SetCurrentTextCombo(IDC_COMBO1, _T("On Leave"));


#else
	if (m_InfoArray[nSelectedIndex].EmployeeType == _T("0"))
		SetCurrentTextCombo(IDC_COMBO2, _T("Full Time "));
	else if (m_InfoArray[nSelectedIndex].EmployeeType == _T("1"))
		SetCurrentTextCombo(IDC_COMBO2, _T("Intern | Trainee"));
	else if (m_InfoArray[nSelectedIndex].EmployeeType == _T("2"))
		SetCurrentTextCombo(IDC_COMBO2, _T("Part Type"));

	if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("Active"))
		SetCurrentTextCombo(IDC_COMBO1, _T("Active"));
	else if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("Left"))
		SetCurrentTextCombo(IDC_COMBO1, _T("Left"));
	else if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("None"))
		SetCurrentTextCombo(IDC_COMBO1, _T("None"));
	else if (m_InfoArray[nSelectedIndex].EmployeeStatus == _T("On Leave"))
		SetCurrentTextCombo(IDC_COMBO1, _T("On Leave"));
#endif

	//SetDlgItemText(IDSAVE, _T("Update"));
	if (nSelectedIndex != LB_ERR)
	{
#if TRUE
		CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT1);
		Edit_Box1->SetWindowText(_T(""));

		CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT5);
		Edit_Box2->SetWindowText(_T(""));
		CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT2);
		Edit_Box3->SetWindowText(_T(""));
		CEdit* Edit_Box4 = (CEdit*)GetDlgItem(IDC_EDIT4);
		Edit_Box4->SetWindowText(_T(""));
		CEdit* Edit_Box5 = (CEdit*)GetDlgItem(IDC_EDIT7);
		Edit_Box5->SetWindowText(_T(""));
		//CEdit* Edit_Box6 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER1);
		//Edit_Box6->SetWindowText(_T(""));
		//CEdit* Edit_Box7 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER2);
		//Edit_Box7->SetWindowText(_T(""));

		CEdit* Edit_Box8 = (CEdit*)GetDlgItem(IDC_EDIT3);
		Edit_Box8->SetWindowText(_T(""));
		CEdit* Edit_Box9 = (CEdit*)GetDlgItem(IDC_EDIT8);
		Edit_Box9->SetWindowText(_T(""));


		Edit_Box1->SetWindowText(m_InfoArray[nSelectedIndex].EmployeeName);
		Edit_Box2->SetWindowText(m_InfoArray[nSelectedIndex].EmployeeAddr);
		Edit_Box3->SetWindowText(m_InfoArray[nSelectedIndex].EmployeeEmailOff);
		Edit_Box4->SetWindowText(m_InfoArray[nSelectedIndex].EmployeeEmailHom);
		Edit_Box5->SetWindowText(m_InfoArray[nSelectedIndex].EmployeePh);

		CString strJoinDate = m_InfoArray[nSelectedIndex].EmployeeJoinDate;
		COleDateTime oleJoinDate;
		oleJoinDate.ParseDateTime(strJoinDate);
		CTime joinDate(oleJoinDate.GetYear(), oleJoinDate.GetMonth(), oleJoinDate.GetDay(), 0, 0, 0); // hour, minute, second set to 0
		CDateTimeCtrl* pDateTimeCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
		pDateTimeCtrl->SetTime(&joinDate);

		CString strLeaveDate = m_InfoArray[nSelectedIndex].EmployeeLeavingDate;
		COleDateTime oleLeaveDate;
		oleLeaveDate.ParseDateTime(strLeaveDate);
		CTime leaveDate(oleLeaveDate.GetYear(), oleLeaveDate.GetMonth(), oleLeaveDate.GetDay(), 0, 0, 0); // hour, minute, second set to 0
		CDateTimeCtrl* pDateTimeCtrl1 = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
		pDateTimeCtrl1->SetTime(&leaveDate);

		Edit_Box8->SetWindowText(m_InfoArray[nSelectedIndex].EmployeeFinalSal);
		Edit_Box9->SetWindowText(m_InfoArray[nSelectedIndex].EmployeeRemarks);


#else
		CString getAllEmployee = _T("api/HR/GetAllEmployeeDetails");
		try
		{
			JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllEmployee);
			std::wstring res = Jvalue->Stringify(true);
			CString cstrRes(res.c_str());
			CWebCloudAPITestApp::SetResponseMsg(cstrRes);
			CWebCloudAPITestApp::SetStatusBarMsg(getAllEmployee);
			JSONArray root = Jvalue->AsArray();

			CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT1);
			Edit_Box1->SetWindowText(_T(""));
			CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT5);
			Edit_Box2->SetWindowText(_T(""));
			CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT2);
			Edit_Box3->SetWindowText(_T(""));
			CEdit* Edit_Box4 = (CEdit*)GetDlgItem(IDC_EDIT4);
			Edit_Box4->SetWindowText(_T(""));
			CEdit* Edit_Box5 = (CEdit*)GetDlgItem(IDC_EDIT7);
			Edit_Box5->SetWindowText(_T(""));
			CEdit* Edit_Box6 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER1);
			Edit_Box6->SetWindowText(_T(""));
			CEdit* Edit_Box7 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER2);
			Edit_Box7->SetWindowText(_T(""));
			CEdit* Edit_Box9 = (CEdit*)GetDlgItem(IDC_EDIT8);
			Edit_Box9->SetWindowText(_T(""));

			JSONObject Jobj = root[nCount]->AsObject();
			CString strEmployeeName(Jobj[L"EmployeeName"]->AsString().c_str());
			Edit_Box1->SetWindowText(strEmployeeName);
			CString strEmployeeAddress(Jobj[L"EmployeeAddress"]->AsString().c_str());
			Edit_Box2->SetWindowText(strEmployeeAddress);
			CString strEmailOff(Jobj[L"EmailOffice"]->AsString().c_str());
			Edit_Box3->SetWindowText(strEmailOff);
			CString strEmailHom(Jobj[L"EmailHome"]->AsString().c_str());
			Edit_Box4->SetWindowText(strEmailHom);
			CString strPh(Jobj[L"EmployeePh"]->AsString().c_str());
			Edit_Box5->SetWindowText(strPh);
			CString strJoinDate(Jobj[L"EmployeeJoiningDate"]->AsString().c_str());
			Edit_Box6->SetWindowText(strJoinDate);
			CString strLeavingDate(Jobj[L"EmployeeLeavingDate"]->AsString().c_str());
			Edit_Box7->SetWindowText(strLeavingDate);
			CString strRemarks(Jobj[L"EmployeeRemarks"]->AsString().c_str());
			Edit_Box9->SetWindowText(strRemarks);
		}
		catch (const std::exception& e)
		{
			CString errorStr(e.what());
			CWebCloudAPITestApp::SetResponseMsg(errorStr);
		}
#endif

	}
}


void CEmployeeForm::OnBnClickedButtonClearall()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_COMBO2)->SetWindowText(_T("Full Time"));
	GetDlgItem(IDC_EDIT5)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT7)->SetWindowText(_T(""));
	SYSTEMTIME st;              // Declare a variable to hold the current system time and date
	GetLocalTime(&st);         // Get the current system time and date
	CDateTimeCtrl* pDateTimeCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	CDateTimeCtrl* pDateTimeCtrl1 = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
	pDateTimeCtrl->SetTime(&st);
	pDateTimeCtrl1->SetTime(&st);
	GetDlgItem(IDC_COMBO1)->SetWindowText(_T("Active"));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT8)->SetWindowText(_T(""));
}


void CEmployeeForm::OnBnClickedButtonSave()
{
	// TODO: Add your control notification handler code here
	CString strButtonText1;
	GetDlgItem(ID_BUTTON_SAVE)->GetWindowText(strButtonText1);
	if (strButtonText1 == _T("Save"))
	{
		try
		{
			Employee_Details info;
			info.EmployeeID = _T("");
			GetDlgItem(IDC_EDIT1)->GetWindowText(info.EmployeeName);
			OnCbnSelchangeCombo2();
			info.EmployeeType = Type;
			//GetDlgItem(IDC_COMBO2)->GetWindowText(info.EmployeeType);
			GetDlgItem(IDC_EDIT5)->GetWindowText(info.EmployeeAddr);
			GetDlgItem(IDC_EDIT2)->GetWindowText(info.EmployeeEmailOff);
			GetDlgItem(IDC_EDIT4)->GetWindowText(info.EmployeeEmailHom);
			GetDlgItem(IDC_EDIT7)->GetWindowText(info.EmployeePh);
			GetDlgItem(IDC_DATETIMEPICKER1)->GetWindowText(info.EmployeeJoinDate);
			GetDlgItem(IDC_DATETIMEPICKER2)->GetWindowText(info.EmployeeLeavingDate);
			GetDlgItem(IDC_COMBO1)->GetWindowText(info.EmployeeStatus);
			GetDlgItem(IDC_EDIT3)->GetWindowText(info.EmployeeFinalSal);
			GetDlgItem(IDC_EDIT8)->GetWindowText(info.EmployeeRemarks);
			m_HRService->AddNewEmployee(info);
			m_listctrl.DeleteAllItems();
			SHOWEMPLOYEE();
		}
		catch (const std::exception& e)
		{
			CString errorStr1(e.what());
			AfxMessageBox(errorStr1);
		}
	}


	CString  strName, strAdrr, strEmailOff, strEmailHom, strPh, strJoinDate, strLeaveDate, Combo_Sel_Status, Combo_Sel_Status_New, strFinalSal, strRemarks, Combo_Sel_type, Combo_Sel_type_new;

	CEdit* Edit_Box1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	Edit_Box1->GetWindowText(strName);

	CComboBox* combo_Box_drop = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int isel = combo_Box_drop->GetCurSel();
	combo_Box_drop->GetWindowText(Combo_Sel_type);

	CEdit* Edit_Box2 = (CEdit*)GetDlgItem(IDC_EDIT5);
	Edit_Box2->GetWindowText(strAdrr);

	CEdit* Edit_Box3 = (CEdit*)GetDlgItem(IDC_EDIT2);
	Edit_Box3->GetWindowText(strEmailOff);

	CEdit* Edit_Box4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	Edit_Box3->GetWindowText(strEmailHom);

	CEdit* Edit_Box5 = (CEdit*)GetDlgItem(IDC_EDIT7);
	Edit_Box5->GetWindowText(strPh);

	CEdit* Edit_Box6 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER1);
	Edit_Box6->GetWindowText(strJoinDate);

	CEdit* Edit_Box7 = (CEdit*)GetDlgItem(IDC_DATETIMEPICKER2);
	Edit_Box7->GetWindowText(strLeaveDate);

	CComboBox* combo_Box_drop1 = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int isel1 = combo_Box_drop1->GetCurSel();
	combo_Box_drop1->GetWindowText(Combo_Sel_Status);

	CEdit* Edit_Box8 = (CEdit*)GetDlgItem(IDC_EDIT3);
	Edit_Box8->GetWindowText(strFinalSal);

	CEdit* Edit_Box9 = (CEdit*)GetDlgItem(IDC_EDIT8);
	Edit_Box9->GetWindowText(strRemarks);



	if (Combo_Sel_type == _T(""))
	{
		//AfxMessageBox(_T("Please Enter Data "));
		return;
	}




	CString strButtonText;



	if (strName != _T(""))
	{
		GetDlgItem(ID_BUTTON_SAVE)->GetWindowText(strButtonText);
		if (strButtonText == _T("Update"))
		{
			int nSelectedIndex = GetSelectedCheckboxIndex();
#if TRUE
			Employee_Details Info;
			Info.EmployeeID = m_InfoArray[nSelectedIndex].EmployeeID;
			Info.EmployeeName = strName;
			Info.EmployeeType = Combo_Sel_type;
			if (Info.EmployeeType == _T("Full Time"))
				Info.EmployeeType = "0";
			else if (Info.EmployeeType == _T("Intern | Trainee"))
				Info.EmployeeType = "1";
			else if (Info.EmployeeType == _T("Part Type"))
				Info.EmployeeType = "2";


			Info.EmployeeAddr = strAdrr;
			Info.EmployeeEmailOff = strEmailOff;
			Info.EmployeeEmailHom = strEmailHom;
			Info.EmployeePh = strPh;
			Info.EmployeeJoinDate = strJoinDate;
			Info.EmployeeLeavingDate = strLeaveDate;
			Info.EmployeeStatus = Combo_Sel_Status;
			Info.EmployeeFinalSal = strFinalSal;
			Info.EmployeeRemarks = strRemarks;
			m_HRService->UpdateEmployee(Info);
			m_listctrl.DeleteAllItems();
			SHOWEMPLOYEE();
			SetDlgItemText(ID_BUTTON_SAVE, _T("Save"));

#else

			CString EmployeeID = m_strEmployeeId[nSelectedIndex];
			Info.EmployeeName = strName;
			Info.EmployeeType = Combo_Sel_type_new;
			Info.EmployeeEmailOff = strEmailOff;
			Info.EmployeeEmailHom = strEmailHom;
			Info.EmployeePh = strPh;
			Info.EmployeeJoinDate = strJoinDate;
			Info.EmployeeLeavingDate = strLeaveDate;
			Info.EmployeeStatus = Combo_Sel_Status_New;
			Info.EmployeeFinalSal = strFinalSal;
			Info.EmployeeRemarks = strRemarks;
			CString UpadteEmployee = _T("api/HR/UpadteEmployee");
			CString dataUpdate;
			JSONObject obj;
			obj[L"EmployeeID"] = new JSONValue(Info.EmployeeID);
			obj[L"EmployeeName"] = new JSONValue(Info.EmployeeName);
			obj[L"EmployeeType"] = new JSONValue(Info.EmployeeType);
			obj[L"EmployeeAddr"] = new JSONValue(Info.EmployeeAddr);
			obj[L"EmployeeEmailOff"] = new JSONValue(Info.EmployeeEmailOff);
			obj[L"EmployeeEmailHom"] = new JSONValue(Info.EmployeeEmailHom);
			obj[L"EmployeePh"] = new JSONValue(Info.EmployeePh);
			obj[L"EmployeeJoinDate"] = new JSONValue(Info.EmployeeJoinDate);
			obj[L"EmployeeLeavingDate"] = new JSONValue(Info.EmployeeLeavingDate);
			obj[L"EmployeeStatus"] = new JSONValue(Info.EmployeeStatus);
			obj[L"EmployeeFinalSal"] = new JSONValue(Info.EmployeeFinalSal);
			obj[L"EmployeeRemarks"] = new JSONValue(Info.EmployeeRemarks);

			JSONValue* val = new JSONValue(obj);
			std::wstring res = val->Stringify(false);
			dataUpdate = CString(res.c_str());


			try
			{
				CWebCloudAPITestApp::SetRequestMSg(dataUpdate);
				JSONValue* jval = NetworkRequest::PostReq(UpadteEmployee, dataUpdate);
				std::wstring res = jval->Stringify(true);
				CString cstrRes(res.c_str());
				CWebCloudAPITestApp::SetResponseMsg(cstrRes);
				AfxMessageBox(cstrRes);
			}
			catch (const std::exception& e)
			{
				CString errorStr(e.what());
				AfxMessageBox(errorStr);
			}

#endif

		}
	}
}
