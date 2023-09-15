#pragma once
#include "NetworkRequest.h"
#include "AppAuthService.h"
#include "AppAccountService.h"
#include "AppCBService.h"
#include "AppCmsService.h"
#include "AppCommService.h"
#include "AppDTService.h"
#include "AppEComService.h"
#include "AppExamService.h"
#include "AppForumService.h"
#include "AppHRService.h"
#include "AppLicenseService.h"
#include "AppPMSeervice.h"
#include "AppSettingsService.h"
#include "AppTTService.h"

class ApiEvents
{
public:
	virtual void OnResponseData(CString Data)=0;
	virtual void OnRequestData(CString Data)=0;
	virtual void OnStatusMessage(CString Message)=0;
};
class AppApiService : public ApiEvents
{
	CString			m_strBaseAPIURL;
	NetworkRequest m_NetworkRequest;
	ApiEvents* m_pApiEvents;
public:
	AppApiService(ApiEvents* pApiEvents);
	void SetAPIURL(CString strURL);
	virtual void OnResponseData(CString Data);
	virtual void OnRequestData(CString Data);
	virtual void OnStatusMessage(CString Message);
	//Authentication API Routines
	void ValidateUser(CString UserID, CString Password, AuthInfo& Info);

	//CMS API Routines
    void GetAllDetailedInfo(CArray<MenuInfo, MenuInfo>& AllInfo);
	void GetSeoSettings(CArray<SeoPageDetails,SeoPageDetails>& Info);
	void GetDefaultSeoSettings(CArray<SeoPageDetails, SeoPageDetails>& info);
	void GetInternalLinkInfo(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo);
	void GetExternalLinkInfo(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo);
	void GetAllFooters(CArray< FooterDetails, FooterDetails>& FtrInfo);
	void InvokeAddFooter(CString strMenuID, CString strLinkName);
	void DeleteHeaderFooter(CString strLinkID);
	void GetAllHeaders(CArray< HeaderDetails, HeaderDetails>& headerinfo);
	void InvokeAddHeader(CString strMenuID, CString strLinkName);
	void SetSeoSettings(CArray<SeoPageDetails, SeoPageDetails>& seoinfo);
	void UpdateInternalLinkTitle(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo);
	void UpdateExternalLinkTitle(CArray< LinkSettingsInfo, LinkSettingsInfo>& LinkInfo);
	void AddExternalLink(LinkDetails linkinfo);
	void UpdateExternalLink(LinkDetails linkinfo);
	void DeleteExternalLink(LinkDetails linkinfo);
	void UpdateOrderExternalLink(CArray<LinkSettingsInfo, LinkSettingsInfo>& linkin);
	void UpdateInternalLink(LinkDetails linkinfo);

	//DT API Routines
	void GetBugTrackerTaskDetailsList(CString strUsername, CArray<BugTaskDetails, BugTaskDetails>& TaskDetailsList);
	void AssignedTaskList(CString strUsername, CArray<TaskDetails, TaskDetails>& AssignedTaskDetailsList);
	void AllbugLists(CArray<BugTaskDetails, BugTaskDetails>& Allbugs);
	void UserTaskDetails(CString strUsername, UserBugTaskDetailsResponse& userResponse, CArray<BugTaskDetails, BugTaskDetails>& Allbugs);
	void PostThread(DefectDetails& defectDetails);
	void GetAllTopicsNameFromFormType(CArray<TopicDetails, TopicDetails>& Details);
	void GetAssignedToList(CArray<TaskAssignedTo, TaskAssignedTo>& Assigned);
	//etc etc..

	//Communication routines
	void GetAllSiteUserInfo(CArray<UserInfo, UserInfo>& InfoArray);
	void GetAllSiteAdminUserInfo(CArray<UserInfo, UserInfo>& InfoArray);
	void GetAllOnlineUserInfo(CArray<UserInfo, UserInfo>& InfoArray);
	void GetAllOnlineNormalUserInfo(CArray<UserInfo, UserInfo>& InfoArray);
	void GetAllOnlineSupportUserInfo(CArray<UserInfo, UserInfo>& InfoArray);
	void SendEmail(WCResult& responce, MailInfo& mailInfo);

	//FORUM API Routines
	void GetAllForums(CArray<FormDetailsInfo>& InfoArray);
	void GetAllForumIdWithNames(CArray<ItemInfo>&InfoArray);
	void GetAllTopicsWithForumID(CString strForumId, CArray<ItemInfo>& InfoArray);
	void GetAllThreadsWithTopicID(CString strTopicID, CArray<ItemInfo>& InfoArray);
	void GetAllTopics(CArray<Topics>& InfoArray);
	void GetAllThreads(CArray<ThreadDetailsInfo>& InfoArray);
	void DeleteThread(CString strThreadID,CString &ResponseMessage);
	void DeleteForum(CString strForumID, CString& ResponseMessage);
	void DeleteTopic(int strTopicID,CString& ResponseMessage);
	CString AddForum(FormDetailsInfo Info);
	CString UpdateForum(FormDetailsInfo Info);
	void GetExistingGroups(CArray<UserCategotyInfo>& InfoArray);
	CString  RetrieveEmail(CString strGroupId, CString& ResponseMessage);
	CString AddTopics(Topics Info);
	CString UpdateTopic(Topics Info);
	CString AddThread(ThreadDetailsInfo trd);
	CString UpdateThread(ThreadDetailsInfo trd);
	void GetThreadByID(CString strThreadID, CArray<ThreadDetailsInfo>& InfoArray);
	void GetMsgsByTrdID(CString strThread,CArray< CommentsInfo>&InfoArray);
	void DeleteComments(CArray<CString>&strMsgID, CArray<CString>& ResponseMessage);
	CString AddComments(CommentsInfo Info);
	CString ForceDeleteForum(CString strForumId);
	CString ForceDeleteTopic(int strTopicId);

	//Account API  Routines
	void GetUserdetais(CArray<UserIn, UserIn>& InfoArray);
	CString Addadmindetail(Addadmin addadmin);
	CString AppApiService::Adduserdetail(Adduser adduser);
	CString AppApiService::Deleteuserdetail(int list);
	void GetAdmindetais(CArray<UserIn, UserIn>& InfoArray);
	CString Deleteadmindetail(int list);
	CString Inviteusersercive(InviteUserapi invite);
	CString Blockusersercive(CString buttontxt);
	void tempaccess();

	

	//Exam API Routines
 	CString AddExamMainCategory(ExamMainCategory examMainCategory);
	//PM API Routines
	CString AddNewTask(Task_Details info);
	void TASKVIEWLIST(CArray<Task_Info>& InfoArray);
	CString AddNewSubTask(SubTaskDetails info);
	void SUBTASKVIEWLIST(CArray<SubTask_Info>& InfoArray);

	//HR API Routines
	CString AddNewEmployee(Employee_Details info);
	void EMPLOYEEVIEWLIST(CArray<Employee_Info>& InfoArray);
	CString InviteEmployee(InviteEmployeeInfo invite);
	CString DeleteEmployee(CString EmployeeID);
	CString UpdateEmployee(Employee_Details Info);
	CString PostLeaveRequest(WCResults& response, LeaveRequestDetails& LeaveRequestDetail);
	CString PostLeaveStatus(WCResults& response, LeaveReqStatus& LeaveRequestStatus);
	void GetAllLeaveApplicationsList(CArray<LeaveRequestDetails, LeaveRequestDetails>& InfoArray);
	void LEAVEVIEWLIST(CArray<LeaveRequestDetails>& InfoArray);
	void GETLOGID(CArray<LeaveRequestDetails>& InfoArray, int index);

	//License API Routines
	CString RegisterNewLicense(NewUserRegInfo Info);
	CString RequestOneTimeReg(NewUserRegInfo Info);
	CString RequestSubscription(NewUserRegInfo Info);
	CString ActivationProduct(Activation Info);
	CString GetLicenseInfo(CString selectPrdt, CString Macid);
	CString GetLicenseInfo(CString NewText);
};

