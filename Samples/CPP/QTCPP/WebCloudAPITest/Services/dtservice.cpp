/*---------------------------------------------------------------------------
    Workfile:DTService.cpp
    Description: . Implementation of Class DTService

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom, Arun K, LAKSHMI V
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "dtservice.h"
#include "Services/networkrequest.h"
#include "mainwindow.h"
#include"appauthservice.h"
DTService::DTService()
{

}
QJsonDocument DTService::GetAssignedTaskList()
{
    QString strUsrName= MainWindow::GetUserName();
    strUrl="Api/DT/GetAssignedBugList?strUserName="+ strUsrName;
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

QJsonDocument DTService::GetBugTrackerTaskDetailsist()
{
    QString strUsrName= MainWindow::GetUserName();
    strUrl="Api/DT/GetBugTrackerTaskDetailsList?strUserName="+ strUsrName;
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

QJsonDocument DTService::GetUserTaskInfo()
{
    QString strUsrName=MainWindow::GetUserName();
    strUrl="Api/DT/GetWebCloudUserTaskDetails?strUserName="+ strUsrName;
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

QJsonDocument DTService::GetAllBugList()
{
    strUrl="Api/DT/GetAllBugDetailsList";
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

QJsonDocument DTService::PostADeffectForm(QByteArray data)
{
    strUrl = "api/DT/PostADefect";
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

QJsonDocument DTService::GetAllTopicsInPost()
{

    strUrl="Api/DT/GetAllTopicsNameFromFormType?strFormType=DT";

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

QJsonDocument DTService::AssignedToInPost()
{
   strUrl2="Api/DT/GetAssignedToList?strFormType=DT";
   QJsonDocument document;
   try
   {
       NetWorkRequest* networkRequest = new NetWorkRequest();
       QNetworkReply* reply = networkRequest->GetRequest(strUrl2);
        document = QJsonDocument::fromJson(reply->readAll());
        MainWindow::SetResponseData(document);
   }
   catch (std::exception& es)
   {
      MainWindow::SetResponseData(es.what());
   }
   return document;
}
