#include "accountservice.h"
#include "Services/networkrequest.h"
#include "mainwindow.h"

AccountService::AccountService()
{

        strMainUrl = "http://test2.virtualtutor.co.in/";


}
QJsonDocument AccountService::GetUserList()
{
    strUrl = "Api/Account/GetUserList";
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
QJsonDocument AccountService::GetAdminList()
{
    strUrl = "Api/Account/GetAdminList";
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
QJsonDocument AccountService::DeleteUser(QString email)
{
    //strUrl = "Api/Account/DeleteUser?email=" + email;
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

QJsonDocument AccountService::DeleteAdmin(QString email)
 {
    strUrl = "Api/Account/DeleteAdmin?email="+email;
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
 QJsonDocument AccountService::AddAdmin(QByteArray data)
  {
      strUrl = "Api/Account/AddAdmin";
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
 QJsonDocument AccountService::AddUser(QByteArray data)
  {
      strUrl = "Api/Account/AddUser";
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
 QJsonDocument AccountService::Blockuser(QByteArray data)
  {
      strUrl = "Api/Account/BlockORUnBlockUser";
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
 QJsonDocument AccountService::InviteUser(QByteArray Data)
  {//\"UserEmail\":\"%s\", \
    // \"UserMessage\" : \"%s\//
     strUrl = "Api/Account/InviteUser";
      QJsonDocument document;
      try
      {
          NetWorkRequest* networkRequest = new NetWorkRequest();
          QNetworkReply* reply = networkRequest->PostRequest(strUrl, Data);

          document = QJsonDocument::fromJson(reply->readAll());
          MainWindow::SetResponseData(document);
      }
      catch (std::exception& es)
      {
         MainWindow::SetResponseData(es.what());
      }
      return document;
  }
 QJsonDocument AccountService::Generatetemp()
  {
      strUrl = "Api/Account/GenerateTempSiteAccessToken";
      QJsonDocument document;
      QString Data;

      try
      {
          NetWorkRequest* networkRequest = new NetWorkRequest();
          QNetworkReply* reply = networkRequest->GetRequest(strUrl);

          //document = QJsonDocument::fromJson(reply->readAll());
        //  document.Json();
          Data=QString(reply->readAll());
          MainWindow::SetResponseData(Data);

                 // MainWindow::SetResponseData(document);
      }
      catch (std::exception& es)
      {
         MainWindow::SetResponseData(es.what());
      }
      return document;
  }
