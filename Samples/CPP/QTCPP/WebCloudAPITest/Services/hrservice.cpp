#include "hrservice.h"
#include "Services/networkrequest.h"
#include "mainwindow.h"
#include <QMessageBox>

HRService::HRService()
{
    strMainUrl = "http://test2.virtualtutor.co.in/";
    m_NetworkReq=new NetWorkRequest();
}

QJsonDocument HRService::InviteEmployee(QByteArray Data)
{
    strUrl = "api/HR/InviteEmployee";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl, Data);

        auto document = QString(reply->readAll());
        MainWindow::SetResponseData(document);
        QMessageBox::information(nullptr,"WebColudAPITest",document);
    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
        QMessageBox::critical(nullptr, "Error", "Invitation Failed.");
    }
    return document;
}

QJsonDocument HRService::GetEmployeeList()
{
    strUrl = "api/HR/GetAllEmployeeDetails";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->GetRequest(strUrl);

        document = QJsonDocument::fromJson(reply->readAll());
        MainWindow::SetResponseData(document);
    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
    return document;
}

QJsonDocument HRService::AddEmployee(QByteArray Data)
{
    strUrl = "api/HR/UploadNewEmployeeDetails";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl, Data);

        auto document = QString(reply->readAll());
        MainWindow::SetResponseData(document);
        QMessageBox::information(nullptr,"WebColudAPITest",document);
    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
    return document;
}

QJsonDocument HRService::UpdateEmployee(QByteArray Data)
{
    strUrl = "api/HR/UpadteEmployee";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl, Data);

        auto document = QString(reply->readAll());
        MainWindow::SetResponseData(document);
        QMessageBox::information(nullptr,"WebColudAPITest",document);
    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
    return document;
}

QJsonDocument HRService::DeleteEmployee(QString EmployeeID)
{

    QJsonDocument document;
    try {
        QString strUrl = "api/HR/DeleteEmployee?EmployeeId="+EmployeeID;
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->GetRequest(strUrl);
        auto Doc=QString(reply->readAll());
        MainWindow::SetResponseData(Doc);
        QMessageBox::information(nullptr,"WebColudAPITest",Doc);
    } catch (std::exception& es) {
        MainWindow::SetResponseData(es.what());
    }
    return document;
}

QJsonDocument HRService::PostLeaveRequest(QByteArray Data)
{
    strUrl = "api/HR/PostALeaveRequest";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl, Data);

        auto document = QString(reply->readAll());
        MainWindow::SetResponseData(document);
        QMessageBox::information(nullptr,"WebColudAPITest",document);
    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
    return document;
}

QJsonDocument HRService::GetAllLeaveApplications()
{
    QJsonDocument Doc;
    try
    {
        QString Paramters = "Api/HR/GetAllLeaveApplicationsList";
        QNetworkReply* Result= m_NetworkReq->GetRequest(Paramters);
        Doc=QJsonDocument::fromJson(Result->readAll());
        MainWindow::SetResponseData(Doc);

    }
    catch (std::exception& e)
    {
        MainWindow::SetResponseData(e.what());
    }
    return Doc;
}

QJsonDocument HRService::PostLeaveStatus(QByteArray Data)
{
    strUrl = "api/HR/PostALeaveStatus";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl, Data);

        auto document = QString(reply->readAll());
        MainWindow::SetResponseData(document);
        QMessageBox::information(nullptr,"WebColudAPITest",document);
    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
    return document;
}

