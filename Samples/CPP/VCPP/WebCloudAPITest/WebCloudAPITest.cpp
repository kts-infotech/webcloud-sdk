
// WebCloudAPITest.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "WebCloudAPITest.h"
#include "MainFrm.h"
#include "UserListDlg.h"
#include "AddUser.h"
#include "InviteUser.h"
#include "WebCloudAPITestDoc.h"
#include "WebCloudAPITestView.h"
#include "DeleteUser.h"
#include "Blockuser.h"
#include "AddAdmin.h"
#include "DeleteAdmin.h"
#include "CAdddelfooter.h"
#include "CAdddelhedear.h"
#include "CAddexternallink.h"
#include "Caddinternalink.h"
#include "GetAllExternalLinks.h"
#include "GetAllInternalLinks.h"
#include "CSetseopageinfo.h"
#include "Cgetseopageinfo.h"
#include "CGetDetailedPageInfo.h"
#include "CListAllPageInfoWithLink.h"
#include "CDtgetassigntasklist.h"
#include "Cusertaskdetails.h"
#include "Cgetallbuglist.h"
#include "Cpostdeffectform.h"
#include "CGetBugTrackerDetailsList.h"
#include "CProjectForm.h"
#include "CTaskForm.h"
#include "CSubTaskForm.h"
#include "CAssignTaskForm.h"
#include "CFormRegister.h"
#include "CGetLicenseInfo.h"
#include "CLicenceTestApp.h"
#include "CGetTTSettings.h"
#include "CUploadWorkLog.h"
#include "CTTDataSummery.h"
#include "CEmployeeForm.h"
#include "CInviteEmployeeForm.h"
#include "CApplyForLeave.h"
#include "CLeaveApplicationForm.h"
#include "Cfileupload.h"
#include "Cdownloaddataform.h"
#include "Cuploadappdata.h"
#include "Cdownloadfilefromcloud.h"
#include "Cuploadappdata.h"
#include "Cfileupload.h"
#include "CListLeaveApplications.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Calluserinfo.h"
#include "CAllonlineuser.h"
#include "CSentemailform.h"
#include "Ctextchatform.h"
#include "Cvoicechatform.h"
#include "CGetAllForum.h"
#include "CGetAllTopic.h"
#include "CGetAllThread.h"
#include "CAddUpdateDeleteForums.h"
#include "CAddUpdateDeleteTopics.h"
#include "CAddUpdateThread.h"
#include "CDeleteAComment.h"
#include "CAddAComment.h"
#include "CDeleteAThread.h"
#include "CAddExamCategory.h"
#include "CAddExamSubCategory.h"
#include "CAddExamCategory.h"
#include "CExamCategoriesList.h"
#include "CExamSubCategories.h"
#include "CExamQuestionPaper.h"
#include "CExamDefaultSettings.h"
#include "CImportData.h"
#include "CCopy.h"
#include "CQuestionMaster.h"
#include "CGetLicenseInfo.h"

// CWebCloudAPITestApp

AppApiService* CWebCloudAPITestApp::m_pAppApiService=NULL;

BEGIN_MESSAGE_MAP(CWebCloudAPITestApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CWebCloudAPITestApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_ACCOUNT_USERLIST, &CWebCloudAPITestApp::OnAccountUserlist)
	ON_COMMAND(ID_ACCOUNT_ADDUSER, &CWebCloudAPITestApp::OnAccountAdduser)
	ON_COMMAND(ID_ACCOUNT_INVITEUSER, &CWebCloudAPITestApp::OnAccountInviteuser)
	ON_COMMAND(ID_ACCOUNT_DELETEUSER, &CWebCloudAPITestApp::OnAccountDeleteuser)
	ON_COMMAND(ID_ACCOUNT_BLOCKUSER, &CWebCloudAPITestApp::OnAccountBlockuser)
	ON_COMMAND(ID_ACCOUNT_ADDADMIN, &CWebCloudAPITestApp::OnAccountAddadmin)
	ON_COMMAND(ID_ACCOUNT_DELETEADMIN, &CWebCloudAPITestApp::OnAccountDeleteadmin)
	ON_COMMAND(ID_ACCOUNT_GENERTETEMPSITEACCESSTOKEN, &CWebCloudAPITestApp::OnAccountGenertetempsiteaccesstoken)
	ON_COMMAND(ID_CMS_ADD32789, &CWebCloudAPITestApp::OnCmsAdddelfooter)
	ON_COMMAND(ID_CMS_ADD, &CWebCloudAPITestApp::OnCmsAdddelheader)
	ON_COMMAND(ID_CMS_ADDEXTERNALLINKS, &CWebCloudAPITestApp::OnCmsAddexternallinks)
	ON_COMMAND(ID_CMS_ADDINTERNALLINKS, &CWebCloudAPITestApp::OnCmsAddinternallinks)
	ON_COMMAND(ID_CMS_GETALL, &CWebCloudAPITestApp::OnCmsGetall)
	ON_COMMAND(ID_CMS_GETALLIN, &CWebCloudAPITestApp::OnCmsGetallinternallinks)
	ON_COMMAND(ID_CMS_SETSEOINFOOFPAGE, &CWebCloudAPITestApp::OnCmsSetseoinfoofpage)
	ON_COMMAND(ID_CMS_GETSEOINFOOFPAGE, &CWebCloudAPITestApp::OnCmsGetseoinfoofpage)
	ON_COMMAND(ID_CMS_GETDETAILEDPAGEINFO, &CWebCloudAPITestApp::OnCmsGetdetailedpageinfo)
	ON_COMMAND(ID_Menu, &CWebCloudAPITestApp::OnListAllPageInfo)
	ON_COMMAND(ID_DT_GETASSIGNEDTASKLIST, &CWebCloudAPITestApp::OnDtGetAssignedTaskList)
	ON_COMMAND(ID_DT_GETUSERTASKINFO, &CWebCloudAPITestApp::OnDtGetUserTaskInfo)
	ON_COMMAND(ID_DT_GET, &CWebCloudAPITestApp::OnDtGetAllBugList)
	ON_COMMAND(ID_DT_, &CWebCloudAPITestApp::OnDtPostADefectForm)
	ON_COMMAND(ID_DT_GETBUGTRACKERTASKD, &CWebCloudAPITestApp::OnDtGetBugTrackerDetailsList)
	ON_COMMAND(ID_COMM_GETALLUSERS, &CWebCloudAPITestApp::OnCommGetallusers)
	ON_COMMAND(ID_COMM_GETALLADMINUSERS, &CWebCloudAPITestApp::OnCommGetalladminusers)
	ON_COMMAND(ID_COMM_GETALLONLINEUSERS, &CWebCloudAPITestApp::OnCommGetallonlineusers)
	ON_COMMAND(ID_COMM_GETALLONLINE, &CWebCloudAPITestApp::OnCommGetallonlineSupportUsers)
	ON_COMMAND(ID_COMM_SENDEMAIL, &CWebCloudAPITestApp::OnCommSendemail)
	ON_COMMAND(ID_COMM_LAUNCHTEXTCHATDEMO, &CWebCloudAPITestApp::OnCommLaunchtextchatdemo)
	ON_COMMAND(ID_COMM_LAUNCHVOICECHATDEMO, &CWebCloudAPITestApp::OnCommLaunchvoicechatdemo)
	//ON_COMMAND(ID_FORM_GETALLFORM, &CWebCloudAPITestApp::OnFormGetallform)
	ON_COMMAND(IDD_DIALOG_GET_ALL_FORUM, &CWebCloudAPITestApp::OnDialogGetAllForum)
	ON_COMMAND(IDD_DIALOG_GET_ALL_TOPIC, &CWebCloudAPITestApp::OnDialogGetAllTopic)
	ON_COMMAND(ID_FORM_GET_ALL_THREADS, &CWebCloudAPITestApp::OnFormGetAllThreads)
	ON_COMMAND(ID_FORM_ADD_UPDATE_DELETE_FORUMS, &CWebCloudAPITestApp::OnFormAddUpdateDeleteForums)
	ON_COMMAND(ID_FORM_ADD_UPDATE_DELETE_TOPICS, &CWebCloudAPITestApp::OnFormAddUpdateDeleteTopics)
	ON_COMMAND(ID_FORM_ADD_UPDATE_THREAD, &CWebCloudAPITestApp::OnFormAddUpdateThread)
	ON_COMMAND(ID_FORM_DELETE_A_COMMENT, &CWebCloudAPITestApp::OnFormDeleteAComment)
	ON_COMMAND(ID_FORM_ADD_A_COMMENT, &CWebCloudAPITestApp::OnFormAddAComment)
	ON_COMMAND(ID_FORUM_DELETE_A_THREAD, &CWebCloudAPITestApp::OnForumDeleteAThread)
	ON_COMMAND(ID_COMM_GETALLONLINENORMALUSERS, &CWebCloudAPITestApp::OnCommGetallonlinenormalusers)
	ON_COMMAND(ID_EXAM_ADDEXAMCATEGORY, &CWebCloudAPITestApp::OnExamAddexamcategory)
	ON_COMMAND(ID_EXAM_ADDEXAMSUBCATEGORY, &CWebCloudAPITestApp::OnExamAddexamsubcategory)
	ON_COMMAND(ID_EXAM_LISTALLEXAMCATEGORIES, &CWebCloudAPITestApp::OnExamListallexamcategories)
	ON_COMMAND(ID_EXAM_LISTALLSUBCATEGOERIS, &CWebCloudAPITestApp::OnExamListallsubcategoeris)
	ON_COMMAND(ID_EXAM_LISTALLQUESTIONSINSUBCATEGORY, &CWebCloudAPITestApp::OnExamListallquestionsinsubcategory)
	ON_COMMAND(ID_EXAM_UPDATEEXAMDEFAULTSETTINGS, &CWebCloudAPITestApp::OnExamUpdateexamdefaultsettings)
	ON_COMMAND(ID_EXAM_IMPORTDATA, &CWebCloudAPITestApp::OnExamImportdata)
	ON_COMMAND(ID_EXAM_COPYQUESTIONS, &CWebCloudAPITestApp::OnExamCopyquestions)
	ON_COMMAND(ID_EXAM_ADD, &CWebCloudAPITestApp::OnExamAdd)
	ON_COMMAND(ID_PM_ADD, &CWebCloudAPITestApp::OnPmAdd)
	ON_COMMAND(ID_PM_ADD32837, &CWebCloudAPITestApp::OnPmAdd32837)
	ON_COMMAND(ID_PM_ADD32838, &CWebCloudAPITestApp::OnPmAdd32838)
	ON_COMMAND(ID_PM_ASSINGNTASK, &CWebCloudAPITestApp::OnPmAssingntask)
	ON_COMMAND(ID_LICENCE_REGISTERLICENCEUSER, &CWebCloudAPITestApp::OnLicenceRegisterlicenceuser)
	ON_COMMAND(ID_LICENCE_GETLICENCEINFO, &CWebCloudAPITestApp::OnLicenceGetlicenceinfo)
	ON_COMMAND(ID_LICENCE_LICENSETESTAPP, &CWebCloudAPITestApp::OnLicenceLicensetestapp)
	ON_COMMAND(ID_TT_GETTIMETRACKERSETTINGS, &CWebCloudAPITestApp::OnTtGettimetrackersettings)
	ON_COMMAND(ID_TT_UPLOADWORKLOG, &CWebCloudAPITestApp::OnTtUploadworklog)
	ON_COMMAND(ID_TT_TIMETRACKERDATASUMMERYINFO, &CWebCloudAPITestApp::OnTtTimetrackerdatasummeryinfo)
	ON_COMMAND(ID_HR_ADD, &CWebCloudAPITestApp::OnHrAdd)
	ON_COMMAND(ID_HR_INVITEEMPLOYEE, &CWebCloudAPITestApp::OnHrInviteemployee)
	ON_COMMAND(ID_HR_APPLYFORLEAVE, &CWebCloudAPITestApp::OnHrApplyforleave)
	ON_COMMAND(ID_HR_APPROVE, &CWebCloudAPITestApp::OnHrApprove)
	ON_COMMAND(ID_CB_UPLOADFILE, &CWebCloudAPITestApp::OnCbUploadfile)
	ON_COMMAND(ID_CB_DOWNLOADFILE, &CWebCloudAPITestApp::OnCbDownloadfile)
	ON_COMMAND(ID_CB_LISTA, &CWebCloudAPITestApp::OnCbLista)
	ON_COMMAND(ID_CB_CREATE, &CWebCloudAPITestApp::OnCbCreate)
	ON_COMMAND(ID_CB_UPLOADAPPDATA, &CWebCloudAPITestApp::OnCbUploadappdata)
	ON_COMMAND(ID_CB_DOWNLOADAPPDATA, &CWebCloudAPITestApp::OnCbDownloadappdata)
	ON_COMMAND(ID_HR_LISTALLLEAVEAPPLICATION, &CWebCloudAPITestApp::OnHrListallleaveapplication)
END_MESSAGE_MAP()


// CWebCloudAPITestApp construction

CWebCloudAPITestApp::CWebCloudAPITestApp() noexcept
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("WebCloudAPITest.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CWebCloudAPITestApp object

CWebCloudAPITestApp theApp;


// CWebCloudAPITestApp initialization

BOOL CWebCloudAPITestApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CWebCloudAPITestDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CWebCloudAPITestView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_MAXIMIZE);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}

int CWebCloudAPITestApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CWebCloudAPITestApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CWebCloudAPITestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CWebCloudAPITestApp message handlers





void CWebCloudAPITestApp::OnAccountUserlist()
{
	UserListDlg lt;
	lt.DoModal();
	// TODO: Add your command handler code here
}


void CWebCloudAPITestApp::OnAccountAdduser()
{
	// TODO: Add your command handler code here
	AddUser adUser;
	adUser.DoModal();
}


void CWebCloudAPITestApp::OnAccountInviteuser()
{
	// TODO: Add your command handler code here
	InviteUser inviteuser;
	inviteuser.DoModal();
}


void CWebCloudAPITestApp::OnAccountDeleteuser()
{
	// TODO: Add your command handler code
	DeleteUser deluser;
	deluser.DoModal();

}


void CWebCloudAPITestApp::OnAccountBlockuser()
{
	// TODO: Add your command handler code here
	Blockuser blkuser;
	blkuser.DoModal();
}


void CWebCloudAPITestApp::OnAccountAddadmin()
{
	// TODO: Add your command handler code here
	AddAdmin adAdmin;
	adAdmin.DoModal();
}


void CWebCloudAPITestApp::OnAccountDeleteadmin()
{
	// TODO: Add your command handler code here

	DeleteAdmin delAdmin;
	delAdmin.DoModal();
}


void CWebCloudAPITestApp::OnAccountGenertetempsiteaccesstoken()
{
	// TODO: Add your command handler code here
}
 
//Exam Menu Event-Handler
void CWebCloudAPITestApp::OnExamAddexamcategory()
{
	CAddExamCategory ExmCtg;
	ExmCtg.DoModal();
}

void CWebCloudAPITestApp::OnExamAddexamsubcategory()
{
	CAddExamSubCategory ExmSubCtg;
	ExmSubCtg.DoModal();
}

void CWebCloudAPITestApp::OnExamListallexamcategories()
{
	CExamCategoriesList ListallCtg;
	ListallCtg.DoModal();
}

void CWebCloudAPITestApp::OnExamListallsubcategoeris()
{
	CExamSubCategories ListallSubCtg;
	ListallSubCtg.DoModal();
}

void CWebCloudAPITestApp::OnExamListallquestionsinsubcategory()
{
	CExamQuestionPaper ListallQSubCtg;
	ListallQSubCtg.DoModal();
}

void CWebCloudAPITestApp::OnExamUpdateexamdefaultsettings()
{ 
	CExamDefaultSettings ExmDfStg;
	ExmDfStg.DoModal();
}

void CWebCloudAPITestApp::OnExamImportdata()
{
	CImportData ImportDt;
	ImportDt.DoModal();
}

void CWebCloudAPITestApp::OnExamCopyquestions()
{
	CCopy CpyExmQ;
	CpyExmQ.DoModal();
}

void CWebCloudAPITestApp::OnExamAdd()
{
	CQuestionMaster EditExmQ;
	EditExmQ.DoModal();

}

void CWebCloudAPITestApp::OnCmsAdddelfooter()
{
	// TODO: Add your command handler code here
	CAdddelfooter ftr;
	ftr.DoModal();
}


void CWebCloudAPITestApp::OnCmsAdddelheader()
{
	// TODO: Add your command handler code here
	CAdddelhedear hdr;
	hdr.DoModal();
}


void CWebCloudAPITestApp::OnCmsAddexternallinks()
{
	// TODO: Add your command handler code here
	CAddexternallink elink;
	elink.DoModal();

}



void CWebCloudAPITestApp::OnCmsAddinternallinks()
{
	// TODO: Add your command handler code here
	Caddinternalink ilink;
	ilink.DoModal();
}


void CWebCloudAPITestApp::OnCmsGetall()
{
	// TODO: Add your command handler code here
	GetAllExternalLinks allelinks;
	allelinks.DoModal();
}


void CWebCloudAPITestApp::OnCmsGetallinternallinks()
{
	// TODO: Add your command handler code here
	GetAllInternalLinks allilinks;
	allilinks.DoModal();
}


void CWebCloudAPITestApp::OnCmsSetseoinfoofpage()
{
	// TODO: Add your command handler code here
	CSetseopageinfo sseo;
	sseo.DoModal();

}


void CWebCloudAPITestApp::OnCmsGetseoinfoofpage()
{
	// TODO: Add your command handler code here
	Cgetseopageinfo gseo;
	gseo.DoModal();
}


void CWebCloudAPITestApp::OnCmsGetdetailedpageinfo()
{
	// TODO: Add your command handler code here
	CGetDetailedPageInfo pageinfo;
	pageinfo.DoModal();
}


void CWebCloudAPITestApp::OnListAllPageInfo()
{
	// TODO: Add your command handler code here
	CListAllPageInfoWithLink listall;
	listall.DoModal();
}


void CWebCloudAPITestApp::OnDtGetAssignedTaskList()
{
	// TODO: Add your command handler code here
	CDtgetassigntasklist getassigntasklist;
	getassigntasklist.DoModal();
}


void CWebCloudAPITestApp::OnDtGetUserTaskInfo()
{
	// TODO: Add your command handler code here
	Cusertaskdetails usertaskdetails;
	usertaskdetails.DoModal();
	
}


void CWebCloudAPITestApp::OnDtGetAllBugList()
{
	// TODO: Add your command handler code here
	Cgetallbuglist getallbuglist;
	getallbuglist.DoModal();
}


void CWebCloudAPITestApp::OnDtPostADefectForm()
{
	// TODO: Add your command handler code here
	Cpostdeffectform postdefectform;
	postdefectform.DoModal();
}


void CWebCloudAPITestApp::OnDtGetBugTrackerDetailsList()
{
	// TODO: Add your command handler code here
	CGetBugTrackerDetailsList GetBugTrackerDetailsList;
	GetBugTrackerDetailsList.DoModal();
}


void CWebCloudAPITestApp::OnCommGetallusers()
{
	// TODO: Add your command handler code here
	Calluserinfo allUserInfo;
	allUserInfo.strSigninURL = _T("Api/Comm/GetAllActiveSiteUsersList");
	allUserInfo.DoModal();
}


void CWebCloudAPITestApp::OnCommGetalladminusers()
{
	// TODO: Add your command handler code here
	Calluserinfo allAdminUserInfo;
	allAdminUserInfo.strSigninURL = _T("Api/Comm/GetAllSiteAdminUsersList");
	allAdminUserInfo.DoModal();
}


void CWebCloudAPITestApp::OnCommGetallonlineusers()
{
	// TODO: Add your command handler code here
	CAllonlineuser allOnlineUserInfo;
	allOnlineUserInfo.strSigninURL = _T("Api/Comm/GetAllOnlineUsersList");
	allOnlineUserInfo.DoModal();
}


void CWebCloudAPITestApp::OnCommGetallonlineSupportUsers()
{
	// TODO: Add your command handler code here
	CAllonlineuser allOnlineSupportUserInfo;
	allOnlineSupportUserInfo.strSigninURL = _T("Api/Comm/GetAllOnlineSupportUsersList");
	allOnlineSupportUserInfo.DoModal();
}


void CWebCloudAPITestApp::OnCommSendemail()
{
	// TODO: Add your command handler code here
	CSentemailform sendEmail;
	sendEmail.DoModal();
}


void CWebCloudAPITestApp::OnCommLaunchtextchatdemo()
{
	// TODO: Add your command handler code here
	Ctextchatform textChat;
	textChat.DoModal();
}


void CWebCloudAPITestApp::OnCommLaunchvoicechatdemo()
{
	// TODO: Add your command handler code here
	CVoiceChatForm voiceChat;
	voiceChat.DoModal();
}




void CWebCloudAPITestApp::OnDialogGetAllForum()
{
	// TODO: Add your command handler code here
	CGetAllForum getAllForum;
	getAllForum.DoModal();
}


void CWebCloudAPITestApp::OnDialogGetAllTopic()
{
	// TODO: Add your command handler code here
	CGetAllTopic getAllTopic;
	getAllTopic.DoModal();
}


void CWebCloudAPITestApp::OnFormGetAllThreads()
{
	// TODO: Add your command handler code here
	CGetAllThread getAllThread;
	getAllThread.DoModal();
}


void CWebCloudAPITestApp::OnFormAddUpdateDeleteForums()
{
	// TODO: Add your command handler code here
	CAddUpdateDeleteForums obj;
	obj.DoModal();

}


void CWebCloudAPITestApp::OnFormAddUpdateDeleteTopics()
{
	// TODO: Add your command handler code here
	CAddUpdateDeleteTopics obj;
	obj.DoModal();
}


void CWebCloudAPITestApp::OnFormAddUpdateThread()
{
	// TODO: Add your command handler code here
	CAddUpdateThread obj;
	obj.DoModal();
}


void CWebCloudAPITestApp::OnFormDeleteAComment()
{
	// TODO: Add your command handler code here
	CDeleteAComment obj;
	obj.DoModal();
}


void CWebCloudAPITestApp::OnFormAddAComment()
{
	// TODO: Add your command handler code here
	CAddAComment obj;
	obj.DoModal();
}


void CWebCloudAPITestApp::OnForumDeleteAThread()
{
	// TODO: Add your command handler code here
	CDeleteAThread obj;
	obj.DoModal();
}


void CWebCloudAPITestApp::SetResponseMsg(CString msg)
{
	// TODO: Add your implementation code here.
	CWebCloudAPITestView::m_pObjView->CWebCloudAPITestView::SetResponseData(msg);
}

void CWebCloudAPITestApp::SetRequestMSg(CString msg)
{
	CWebCloudAPITestView::m_pObjView->CWebCloudAPITestView::SetRequestData(msg);
}

void CWebCloudAPITestApp::SetStatusBarMsg(CString msg)
{
	CWebCloudAPITestView::m_pObjView->CWebCloudAPITestView::SetStatusBarMsg(msg);
}

CString CWebCloudAPITestApp::GetUsername()
{
	return CWebCloudAPITestView::m_pObjView->GetUsername();
}

//Menu item click event handler for 'Comm' menu..Others are above
void CWebCloudAPITestApp::OnCommGetallonlinenormalusers()
{
	// TODO: Add your command handler code here
	CAllonlineuser allOnlineNormalUserInfo;
	allOnlineNormalUserInfo.strSigninURL = _T("Api/Comm/GetAllOnlineNormalUsersList");
	allOnlineNormalUserInfo.DoModal();
}



void CWebCloudAPITestApp::OnPmAdd()
{
	// TODO: Add your command handler code here
	CProjectForm obj;
	obj.DoModal();
}


void CWebCloudAPITestApp::OnPmAdd32837()
{
	// TODO: Add your command handler code here
	CTaskForm taskform;
	taskform.DoModal();
}


void CWebCloudAPITestApp::OnPmAdd32838()
{
	// TODO: Add your command handler code here
	CSubTaskForm subtaskform;
	subtaskform.DoModal();
}


void CWebCloudAPITestApp::OnPmAssingntask()
{
	// TODO: Add your command handler code here
	CAssignTaskForm assigntask;
	assigntask.DoModal();
}


void CWebCloudAPITestApp::OnHrAdd()
{
	// TODO: Add your command handler code here
	CEmployeeForm employeeform;
	employeeform.DoModal();
	
}


void CWebCloudAPITestApp::OnHrInviteemployee()
{
	// TODO: Add your command handler code here
	CInviteEmployeeForm inviteemployeeform;
	inviteemployeeform.DoModal();
}


void CWebCloudAPITestApp::OnHrApplyforleave()
{
	// TODO: Add your command handler code here
	CApplyForLeave applyforleave;
	applyforleave.DoModal();
}


void CWebCloudAPITestApp::OnHrApprove()
{
	// TODO: Add your command handler code here
	CLeaveApplicationForm leaveapplicationform;
	leaveapplicationform.DoModal();
}

void CWebCloudAPITestApp::OnLicenceRegisterlicenceuser()
{
	CFormRegister formregister;
	formregister.DoModal();
}

void CWebCloudAPITestApp::OnLicenceGetlicenceinfo()
{
	CGetLicenseInfo getlicenseinfo;
	getlicenseinfo.DoModal();
}

void CWebCloudAPITestApp::OnLicenceLicensetestapp()
{
	CLicenceTestApp licencetestapp;
	licencetestapp.DoModal();
}

void CWebCloudAPITestApp::OnTtGettimetrackersettings()
{
	CGetTTSettings getttsettings;
	getttsettings.DoModal();
}

void CWebCloudAPITestApp::OnTtUploadworklog()
{
	CUploadWorkLog uploadworklog;
	uploadworklog.DoModal();
}

void CWebCloudAPITestApp::OnTtTimetrackerdatasummeryinfo()
{
	CTTDataSummery ttdatasummery;
	ttdatasummery.DoModal();
}


void CWebCloudAPITestApp::OnCbUploadfile()
{
	// TODO: Add your command handler code here
	Cfileupload fileupload;
	fileupload.DoModal();
	
}


void CWebCloudAPITestApp::OnCbDownloadfile()
{
	// TODO: Add your command handler code here
	Cdownloadfilefromcloud download;
	download.DoModal();
}


void CWebCloudAPITestApp::OnCbLista()
{
	// TODO: Add your command handler code here
}


void CWebCloudAPITestApp::OnCbCreate()
{
	// TODO: Add your command handler code here
}


void CWebCloudAPITestApp::OnCbUploadappdata()
{
	// TODO: Add your command handler code here
}


void CWebCloudAPITestApp::OnCbDownloadappdata()
{
	// TODO: Add your command handler code here
	Cdownloaddataform dwnload;
	dwnload.DoModal();
}

void CWebCloudAPITestApp::OnHrListallleaveapplication()
{
	// TODO: Add your command handler code here
	CListLeaveApplications listleaveapplications;
	listleaveapplications.DoModal();
}
