#include "examservice.h"
#include "Services/networkrequest.h"
#include "mainwindow.h"
ExamService::ExamService()
{

}

QJsonDocument ExamService:: AddExamMainCategory(QByteArray data)
{
    strUrl = "api/Exam/AddExamMainCategory";
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

QJsonDocument ExamService:: AddExamSubCategory(QByteArray data)
{
    strUrl = "api/Exam/AddExamSubCategory";
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


