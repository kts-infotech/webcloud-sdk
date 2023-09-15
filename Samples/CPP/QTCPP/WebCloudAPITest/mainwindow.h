#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QJsonDocument>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void SetResponseData(QJsonDocument jsonDoc);
    static void SetResponseData(QString strMessage);
    static void SetRequestData(QJsonDocument jsonDoc);
    static void SetStatusBar(QString strData);
    static QString strAuthToken;
    static QString GetUserName();

private:
    Ui::MainWindow *ui;
    static MainWindow * pMainWindow;
    bool LoginWebCloud();
    QSettings m_Settings;

    static QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void ShowUserList();
    void on_btnLogin_clicked();


    void ShowAdddelFooter();
    void ShowAdddelHeader();
    void ShowAddExternalLink();
    void ShowAddInternalLink();
    void ShowGetAllExternalLinks();
    void ShowGetAllInternalLinks();
    void ShowGetDetailedPageInfo();
    void ShowGetSEOPageInfo();
    void ShowListAllPageInfoWithLinks();
    void ShowSetSEOInfoPage();

    void ShowGetAllForums();
    void ShowGetAllThreads();
    void ShowGetAllTopics();
    void ShowDeleteAThread();
    void ShowAddUpdateDeleteForum();
    void ShowAddUpdateDeleteTopics();
    void ShowAddUpdateThread();
    void ShowDeleteAComment();
    void ShowAddAComment();

    void ShowGetAllUsers();
    void ShowGetAllAdminUsers();
    void ShowGetAllOnlineUsers();
    void ShowGetAllOnlineNormalUsers();
    void ShowGetAllOnlineSupportUsers();
    void ShowSendEmail();

    void ShowGetAllBugList();
    void ShowGetAssignedTaskList();
    void ShowGetBugTrackerDetailsList();
    void ShowGetUserInfo();
    void ShowPostADefectForm();

     void ShowAdduserlist();
     void ShowAddAdminlist();
     void ShowInviteUser();
     void ShowBlockUSer();
     void ShowDeleteUser();
     void ShowDeleteAdmin();
     void ShowGenerateTermSiteAccessToken();

     void ShowAddExamCategory();
     void ShowAddExamSubCategory();
     void ShowListExamCategory();
     void ShowListExamSubCategory();
     void ShowUpdateExamSettings();
     void ShowListExamQuestions();
     void ShowImportData();
     void ShowCopyQues();
     void ShowAddEditQues();

     void ShowAdd_Update_DeleteEmploy_Details();
     void ShowInvite_Employee();
     void ShowApply_For_Leave();
     void ShowApprove_Reject_Leave();
     void ShowList_All_Leave_Application();
};
#endif // MAINWINDOW_H
