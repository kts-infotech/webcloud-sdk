/*---------------------------------------------------------------------------
    Workfile:CommService.cpp
    Description: . Implementation of Class CommService

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "commservice.h"
#include "Services/networkrequest.h"
#include "mainwindow.h"

CommService::CommService()
{
    strMainUrl = "http://test2.virtualtutor.co.in/";
}

//Unwanted function GetReq(QString strUrl)
QJsonDocument CommService::GetReq(QString strUrl)
{
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        NetWorkRequest::SetMainUrl(strMainUrl);
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


/*---------------------------------------------------------------------------
    Function Name:CommService::GetAllUsers
    Return Value: QJsonDocument
    Parameters: Null.
    Remarks: Function in service to call API to get all active site users list.
---------------------------------------------------------------------------*/
QJsonDocument CommService::GetAllUsers()
{
    strUrl = "Api/Comm/GetAllActiveSiteUsersList";
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


/*---------------------------------------------------------------------------
    Function Name:CommService::GetAllAdminUsers
    Return Value: QJsonDocument
    Parameters: Null.
    Remarks: Function in service to call API to get all admin users list.
---------------------------------------------------------------------------*/
QJsonDocument CommService::GetAllAdminUsers()
{
    strUrl = "Api/Comm/GetAllSiteAdminUsersList";
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


/*---------------------------------------------------------------------------
    Function Name:CommService::GetAllOnlineUsers
    Return Value: QJsonDocument
    Parameters: Null.
    Remarks: Function in service to call API to get all online users list.
---------------------------------------------------------------------------*/
QJsonDocument CommService::GetAllOnlineUsers()
{
    strUrl = "Api/Comm/GetAllOnlineUsersList";
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


/*---------------------------------------------------------------------------
    Function Name:CommService::GetAllOnlineNormalUsers
    Return Value: QJsonDocument
    Parameters: Null.
    Remarks: Function in service to call API to get all online normal users list.
---------------------------------------------------------------------------*/
QJsonDocument CommService::GetAllOnlineNormalUsers()
{
    strUrl = "Api/Comm/GetAllOnlineNormalUsersList";
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


/*---------------------------------------------------------------------------
    Function Name:CommService::GetAllOnlineSupportUsers
    Return Value: QJsonDocument
    Parameters: Null.
    Remarks: Function in service to call API to get all online support users list.
---------------------------------------------------------------------------*/
QJsonDocument CommService::GetAllOnlineSupportUsers()
{
    strUrl = "Api/Comm/GetAllOnlineSupportUsersList";
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


/*---------------------------------------------------------------------------
    Function Name:CommService::SendEmail
    Return Value: QJsonDocument
    Parameters: QByteArray data -- Email data.
    Remarks: Function in service to call API for posting an email.
---------------------------------------------------------------------------*/
QJsonDocument CommService::SendEmail(QByteArray data)
{
    strUrl = "Api/Comm/SendMail";
    QJsonDocument document;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl,data);

        document = QJsonDocument::fromJson(reply->readAll());
        MainWindow::SetResponseData(document);
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
    return document;
}
