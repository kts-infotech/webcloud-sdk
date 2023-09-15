#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Account/UserList/userlistdlg.h"
#include "Account/InviteUser/inviteuserdlg.h"
#include "Services/appauthservice.h"
#include <QMessageBox>
#include <QByteArray>
#include <QJsonObject>

#include "Exam/AddExamCategory/addexmctg_dlg.h"
#include "Exam/AddExamSubCategory/addexmsubctg_dlg.h"
#include "Exam/ListAllExamCategories/listexmctg_dlg.h"
#include "Exam/ListAllExamSubCategories/listexmsubctg_dlg.h"
#include "Exam/UpdateExamDefaultSettings/exmdeftstg_dlg.h"
#include "Exam/ListAllQnsInSubCategory/listexmques_dlg.h"
#include "Exam/ImportData/importdata_dlg.h"
#include "Exam/CopyQns/copyques_dlg.h"
#include "Exam/AEDQns/add_editques_dlg.h"

#include "CMS/AddDeleteFooter/adddelfooterdlg.h"
#include "CMS/AddDeleteHeader/adddelheaderdlg.h"
#include "CMS/AddExternalLink/addexternallinkdlg.h"
#include "CMS/AddInternalLink/addinternallinkdlg.h"
#include "CMS/GetAllExternalLinks/getallexternallinksdlg.h"
#include "CMS/GetAllInternalLinks/getallinternallinksdlg.h"
#include "CMS/GetDetailedPageInfo/getdetailedpageinfodlg.h"
#include "CMS/GetSeoInfoOfPage/getseoinfoofpagedlg.h"
#include "CMS/ListAllPageInfoWithLinks/listallpageinfowithlinksdlg.h"
#include "CMS/SetSeoInfoOfPage/setseoinfoofpagedlg.h"

#include "Forum/GetAllForums/getallforums.h"
#include "Forum/GetAllThreads/getallthreads.h"
#include "Forum/GetAllTopics/getalltopicdlg.h"
#include "Forum/DeleteThread/deletethreaddlg.h"
#include "Forum/AUDForum/audforumdlg.h"
#include "Forum/AUDTopics/audtopicsdlg.h"
#include "Forum/AUThread/authreaddlg.h"
#include "Forum/DeleteComment/deletecommentdlg.h"
#include "Forum/AddComment/addcommentdlg.h"

#include "Comm/GetAllUsers/getallusers.h"
#include "Comm/GetAllOnlineUsers/getallonlineusers.h"
#include "Comm/GetAllAdminUsers/getalladminusers.h"
#include "Comm/GetAllOnlineNormalUsers/getallonlinenormalusers.h"
#include "Comm/GetAllOnlineSupportUsers/getallonlinesupportusers.h"
#include "Comm/SendEmail/sendemail.h"

#include "DT/GetAllBugList/getallbuglist.h"
#include "DT/GetAssignedTaskList/getassignedtasklist.h"
#include "DT/GetBugTrackerTaskDetailList/getbugtrackertaskdetailslist.h"
#include "DT/GetUserTaskInfo/getusertaskinfo.h"
#include "DT/PostADefect/postadefectform.h"

#include "Account/AddUser/adduserdlg.h"
#include "Account/AddAdmin/accaddadmindlg.h"
#include "Account/BlockUser/blockuserdlg.h"
#include "Account/DeleteAdmin/deleteadmindlg.h"
#include "Account/DeleteUser/deleteuserdlg.h"
#include <Services/accountservice.h>


#include "HR/AUDEmployeeDetails/audemployeedetailsdlg.h"
#include "HR/InviteEmployee/invite_employeedlg.h"
#include "HR/ApplyForLeave/apply_for_leavedlg.h"
#include "HR/ApproveRejectLeave/approve_reject_leavedlg.h"
#include "HR/ListAllLeaveAppli/list_all_leave_applicationdlg.h"


MainWindow * MainWindow::pMainWindow=nullptr;
QString MainWindow::strAuthToken="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_Settings("KTS InfoTech", "WebCloudApiTest")
{
    ui->setupUi(this);
    pMainWindow=this;
    ui->lineEditWebUrl->setText(m_Settings.value("WebUrl").toString());
    ui->lineEditUserId->setText(m_Settings.value("Username").toString());
    ui->lineEditPassword->setText(m_Settings.value("Password").toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetResponseData(QJsonDocument jsonDoc)
{
    QString strData=StringifyJson(jsonDoc);
    pMainWindow->ui->plainTextEditRespData->setPlainText(strData);
}

void MainWindow::SetResponseData(QString strMessage)
{
    pMainWindow->ui->plainTextEditRespData->setPlainText(strMessage);
}

void MainWindow::SetRequestData(QJsonDocument jsonDoc)
{
    QString strData=StringifyJson(jsonDoc);
    pMainWindow->ui->plainTextEditReqData->setPlainText(strData);
}

void MainWindow::SetStatusBar(QString strData)
{
    pMainWindow->ui->statusbar->showMessage(strData);
}



QString MainWindow::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}

void MainWindow::ShowUserList()
{
 UserListDlg * dlg = new UserListDlg();
 dlg->show();
}


void MainWindow::on_btnLogin_clicked()
{
    if(ui->btnLogin->text()=="Login")
    {
        m_Settings.setValue("WebUrl",ui->lineEditWebUrl->text());
        m_Settings.setValue("Username",ui->lineEditUserId->text());
        m_Settings.setValue("Password",ui->lineEditPassword->text());
        if(LoginWebCloud())
        {
            ui->btnLogin->setText("Logout");
        }
    }
    else
    {
        ui->btnLogin->setText("Login");
    }
}

void MainWindow::ShowAdddelFooter()
{
AdddelFooterDlg * ftrdlg=new AdddelFooterDlg();
ftrdlg->show();
}

void MainWindow::ShowAdddelHeader()
{
AdddelHeaderDlg * hdrdlg=new AdddelHeaderDlg();
hdrdlg->show();
}

void MainWindow::ShowAddExternalLink()
{
AddExternalLinkDlg * exdlg=new AddExternalLinkDlg();
exdlg->show();
}

void MainWindow::ShowAddInternalLink()
{
AddInternalLinkDlg * indlg=new AddInternalLinkDlg();
indlg->show();
}

void MainWindow::ShowGetAllExternalLinks()
{
GetAllExternalLinksDlg *allexdlg=new GetAllExternalLinksDlg();
allexdlg->show();
}

void MainWindow::ShowGetAllInternalLinks()
{
GetAllInternalLinksDlg *allindlg=new GetAllInternalLinksDlg();
allindlg->show();
}

void MainWindow::ShowGetDetailedPageInfo()
{
GetDetailedPageInfoDlg *pageinfo=new GetDetailedPageInfoDlg();
pageinfo->show();
}

void MainWindow::ShowGetSEOPageInfo()
{
GetSeoInfoOfPageDlg *getseo=new GetSeoInfoOfPageDlg();
getseo->show();
}

void MainWindow::ShowListAllPageInfoWithLinks()
{
ListAllPageInfoWithLinksDlg *allpage=new ListAllPageInfoWithLinksDlg();
allpage->show();
}

void MainWindow::ShowSetSEOInfoPage()
{
SetSEOInfoOfPageDlg *setseo=new SetSEOInfoOfPageDlg();
setseo->show();
}

void MainWindow::ShowGetAllForums()
{
GetAllForums *dlg =new GetAllForums();
dlg->show();
}

void MainWindow::ShowGetAllThreads()
{
GetAllThreads *dlg =new GetAllThreads();
dlg->show();
}

void MainWindow::ShowGetAllTopics()
{
GetAllTopicDlg *dlg=new GetAllTopicDlg();
dlg->show();

}

void MainWindow::ShowDeleteAThread()
{
DeleteThreadDlg *dlg=new DeleteThreadDlg();
dlg->show();
}

void MainWindow::ShowAddUpdateDeleteForum()
{
    AUDForumDlg *dlg=new AUDForumDlg();
    dlg->show();
}

void MainWindow::ShowAddUpdateDeleteTopics()
{
    AUDTopicsDlg *dlg=new AUDTopicsDlg();
    dlg->show();
}

void MainWindow::ShowAddUpdateThread()
{
    AUThreadDlg *dlg=new AUThreadDlg();
    dlg->show();
}

void MainWindow::ShowDeleteAComment()
{
    DeleteCommentDlg *dlg=new DeleteCommentDlg();
    dlg->show();
}

void MainWindow::ShowAddAComment()
{
    AddCommentDlg *dlg=new AddCommentDlg(this);
    dlg->show();
}

void MainWindow::ShowGetAllUsers()
{
    GetAllUsers* getAllUsers = new GetAllUsers();
    getAllUsers->show();
}

void MainWindow::ShowGetAllAdminUsers()
{
    GetAllAdminUsers* getAllAdminUsers = new GetAllAdminUsers();
    getAllAdminUsers->show();
}

void MainWindow::ShowGetAllOnlineUsers()
{
    GetAllOnlineUsers* getAllOnlineUsers = new GetAllOnlineUsers();
    getAllOnlineUsers->show();
}

void MainWindow::ShowGetAllOnlineNormalUsers()
{
    GetAllOnlineNormalUsers* getAllOnlineNormalUsers = new GetAllOnlineNormalUsers();
    getAllOnlineNormalUsers->show();
}

void MainWindow::ShowGetAllOnlineSupportUsers()
{
    GetAllOnlineSupportUsers* getAllOnlineSupportUsers = new GetAllOnlineSupportUsers();
    getAllOnlineSupportUsers->show();
}

void MainWindow::ShowSendEmail()
{
    SendEmail* sendEmail = new SendEmail();
    sendEmail->show();
}

void MainWindow::ShowGetAllBugList()
{
 GetAllBugList* getallbuglist=new GetAllBugList();
 getallbuglist-> show();
}

void MainWindow::ShowGetAssignedTaskList()
{
GetAssignedTaskList* getassignedTaskList= new GetAssignedTaskList();
getassignedTaskList->show();
}

void MainWindow::ShowGetBugTrackerDetailsList()
{
GetBugTrackerTaskDetailsList * getbugtracker=new GetBugTrackerTaskDetailsList();
getbugtracker->show();
}

void MainWindow::ShowGetUserInfo()
{
GetUserTaskInfo *getuserTaskInfo= new GetUserTaskInfo();
getuserTaskInfo->show();
}

void MainWindow::ShowPostADefectForm()
{
PostADefectForm *postdefect= new PostADefectForm();
postdefect->show();
}

void MainWindow::ShowAdduserlist()
{
AddUserDlg * adduser=  new AddUserDlg();
adduser->show();
}

void MainWindow::ShowAddAdminlist()
{
AccAddAdminDlg * addadmin=new AccAddAdminDlg();
addadmin->show();
}

void MainWindow::ShowInviteUser()
{
InviteUserDlg * invite =new InviteUserDlg();
invite->show();

}

void MainWindow::ShowBlockUSer()
{
BlockUserDlg * block =new BlockUserDlg();
block->show();
}

void MainWindow::ShowDeleteUser()
{
    DeleteUserDlg * deleUser =new DeleteUserDlg();
    deleUser->show();
}

void MainWindow::ShowDeleteAdmin()
{
DeleteAdminDlg * deleadmin =new DeleteAdminDlg();
deleadmin->show();
}

QString MainWindow::GetUserName()
{
QString usrName=pMainWindow->ui->lineEditUserId->text();
return usrName;
}
void MainWindow::ShowGenerateTermSiteAccessToken()
{
    AccountService* tempaccess = new AccountService();
    tempaccess->Generatetemp();
}

void MainWindow::ShowAddExamCategory()
{
   addexmctg_Dlg * dlg = new addexmctg_Dlg();
   dlg->show();
}

void MainWindow::ShowAddExamSubCategory()
{
    addexmsubctg_Dlg * dlg = new addexmsubctg_Dlg();
    dlg->show();
}

void MainWindow::ShowListExamCategory()
{
     listexmctg_Dlg  * dlg = new listexmctg_Dlg();
     dlg->show();
}

void MainWindow::ShowListExamSubCategory()
{
   listexmsubctg_Dlg * dlg = new listexmsubctg_Dlg();
   dlg->show();
}

void MainWindow::ShowUpdateExamSettings()
{
   exmdeftstg_Dlg * dlg = new exmdeftstg_Dlg();
   dlg->show();
}

void MainWindow::ShowListExamQuestions()
{
   listexmQues_Dlg * dlg = new listexmQues_Dlg();
   dlg->show();
}

void MainWindow::ShowImportData()
{
   importdata_Dlg * dlg = new importdata_Dlg();
   dlg->show();
}

void MainWindow::ShowCopyQues()
{
    CopyQues_Dlg * dlg = new CopyQues_Dlg();
    dlg->show();
}

void MainWindow::ShowAddEditQues()
{
    add_editQues_Dlg * dlg = new add_editQues_Dlg();
    dlg->show();
}

void MainWindow::ShowAdd_Update_DeleteEmploy_Details()
{
    AUDEmployeeDetailsDlg * dlg = new AUDEmployeeDetailsDlg();
    dlg->show();
}

void MainWindow::ShowInvite_Employee()
{
    Invite_EmployeeDlg * dlg = new Invite_EmployeeDlg();
    dlg->show();
}

void MainWindow::ShowApply_For_Leave()
{
    Apply_For_LeaveDlg * dlg = new Apply_For_LeaveDlg();
    dlg->show();
}

void MainWindow::ShowApprove_Reject_Leave()
{
    Approve_Reject_LeaveDlg * dlg = new Approve_Reject_LeaveDlg();
    dlg->show();
}

void MainWindow::ShowList_All_Leave_Application()
{
    List_All_Leave_ApplicationDlg * dlg = new List_All_Leave_ApplicationDlg();
    dlg->show();
}

bool MainWindow::LoginWebCloud()
{
    AppAuthService * pAuth = new AppAuthService(ui->lineEditWebUrl->text(),
                                                ui->lineEditUserId->text(),
                                                ui->lineEditPassword->text());
    try
    {
        QJsonDocument doc = pAuth->ValidateUser();
        SetResponseData(doc);
        QJsonObject obj = doc.object();
        strAuthToken = obj["AuthenticationToken"].toString();
        ui->lineEditAuthToken->setText(strAuthToken);
        return true;
    }
    catch (std::exception& es)
    {
       SetResponseData(es.what());
       return false;
    }
}
