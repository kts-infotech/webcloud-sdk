
// WebCloudAPITest.h : main header file for the WebCloudAPITest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CWebCloudAPITestApp:
// See WebCloudAPITest.cpp for the implementation of this class
//

class CWebCloudAPITestApp : public CWinApp
{
public:
	static AppApiService* m_pAppApiService;

	CWebCloudAPITestApp() noexcept;
	static void SetResponseMsg(CString msg);
	static void SetRequestMSg(CString msg);
	static void SetStatusBarMsg(CString msg);
	static CString GetUsername();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnAccountUserlist();
	afx_msg void OnAccountAdduser();
	afx_msg void OnAccountInviteuser();
	afx_msg void OnAccountDeleteuser();
	afx_msg void OnAccountBlockuser();
	afx_msg void OnAccountAddadmin();
	afx_msg void OnAccountDeleteadmin();
	afx_msg void OnAccountGenertetempsiteaccesstoken();
	afx_msg void OnCmsAdddelfooter();
	afx_msg void OnCmsAdddelheader();
	afx_msg void OnCmsAddexternallinks();
	afx_msg void OnCmsAddinternallinks();
	afx_msg void OnCmsGetall();
	afx_msg void OnCmsGetallinternallinks();
	afx_msg void OnCmsSetseoinfoofpage();
	afx_msg void OnCmsGetseoinfoofpage();
	afx_msg void OnCmsGetdetailedpageinfo();
	afx_msg void OnListAllPageInfo();
	afx_msg void OnDtGetAssignedTaskList();
	afx_msg void OnDtGetUserTaskInfo();
	afx_msg void OnDtGetAllBugList();
	afx_msg void OnDtPostADefectForm();
	afx_msg void OnDtGetBugTrackerDetailsList();
	afx_msg void OnCommGetallusers();
	afx_msg void OnCommGetalladminusers();
	afx_msg void OnCommGetallonlineusers();
	afx_msg void OnCommGetallonlineSupportUsers();
	afx_msg void OnCommSendemail();
	afx_msg void OnCommLaunchtextchatdemo();
	afx_msg void OnCommLaunchvoicechatdemo();
//	afx_msg void OnFormGetallform();
	afx_msg void OnDialogGetAllForum();
	afx_msg void OnDialogGetAllTopic();
	afx_msg void OnFormGetAllThreads();
	afx_msg void OnFormAddUpdateDeleteForums();
	afx_msg void OnFormAddUpdateDeleteTopics();
	afx_msg void OnFormAddUpdateThread();
	afx_msg void OnFormDeleteAComment();
	afx_msg void OnFormAddAComment();
	afx_msg void OnForumDeleteAThread();
	
	afx_msg void OnCommGetallonlinenormalusers();

	//afx_msg void OnExamAddexamcategory();
	//afx_msg void OnExamAddexamsubcategory();
	//afx_msg void OnExamListallexamcategories();
	//afx_msg void OnExamListallsubcategoeris();
	//afx_msg void OnExamListallquestionsinsubcategory();
	//afx_msg void OnExamUpdateexamdefaultsettings();
	//afx_msg void OnExamImportdata();
	//afx_msg void OnExamCopyquestions();
	//afx_msg void OnExamAdd();

	afx_msg void OnPmAdd();
	afx_msg void OnPmAdd32837();
	afx_msg void OnPmAdd32838();
	afx_msg void OnPmAssingntask();
	afx_msg void OnHrAdd();
	afx_msg void OnHrInviteemployee();
	afx_msg void OnHrApplyforleave();
	afx_msg void OnHrApprove();
	afx_msg void OnLicenceRegisterlicenceuser();
	afx_msg void OnLicenceGetlicenceinfo();
	afx_msg void OnLicenceLicensetestapp();
	afx_msg void OnTtGettimetrackersettings();
	afx_msg void OnTtUploadworklog();
	afx_msg void OnTtTimetrackerdatasummeryinfo();

	afx_msg void OnCbUploadfile();
	afx_msg void OnCbDownloadfile();
	afx_msg void OnCbLista();
	afx_msg void OnCbCreate();
	afx_msg void OnCbUploadappdata();
	afx_msg void OnCbDownloadappdata();
	afx_msg void OnHrListallleaveapplication();
};


extern CWebCloudAPITestApp theApp;
