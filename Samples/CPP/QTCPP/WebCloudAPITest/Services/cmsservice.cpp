#include "cmsservice.h"
#include "Services/networkrequest.h"
#include "mainwindow.h"
#include "qabstractitemmodel.h"
#include <QList>
cmsservice::cmsservice()
{
 strMainUrl = "http://test2.virtualtutor.co.in/";
}

QJsonDocument cmsservice::GetSeoInfoOfPage()
{
    strUrl = "api/Cms/GetSeoSettings";
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
QJsonDocument cmsservice::AddListMenu()
{
    strUrl="api/Cms/GetALLPageInfo";
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
QJsonDocument cmsservice::AddInternalLink()
{
    strUrl="api/Cms/GetInternalLinks";
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

QJsonDocument cmsservice::UpdateTitle(QString strDefaultTitle,QString showLink)
{

    strUrl="api/Cms/UpdateInternalLinkTitle?strDefaultTitle=" + strDefaultTitle + "&&ShowInternalLink=" + showLink;
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
QJsonDocument cmsservice::UpdateExternalTitle(QString strDefaultTitle,QString showLink)
{

    strUrl="api/Cms/UpdateExternalLinkTitle?strDefaultTitle=" + strDefaultTitle + "&&ShowExternalLink=" + showLink;
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
QJsonDocument cmsservice::AddExistingFooters()
{
    strUrl = "api/Cms/GetAllFooters";
QByteArray data;
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
QJsonDocument cmsservice::AddExistingHeaders()
{
    strUrl = "api/Cms/GetAllHeaders";
QByteArray data;
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
QJsonDocument cmsservice::AddFooter(QString strLinkName,QString var)
{

    strUrl=("api/Cms/AddFooter?strLinkName=" + strLinkName + "&&strMenuID=" +var);
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
QJsonDocument cmsservice::AddHeader(QString strLinkName,QString var)
{

    strUrl=("api/Cms/AddHeader?strLinkName=" + strLinkName + "&&strMenuID=" +var);
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
QJsonDocument cmsservice::DeleteFooter(QString strLinkID)
{

    strUrl="api/Cms/DeleteHeaderFooter?strLinkID="+strLinkID;
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
QJsonDocument cmsservice::ListMenuWithID()
{
    strUrl="api/Cms/GetAllPageInfo";
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
QJsonDocument cmsservice::AddSettings()
{
    strUrl="api/Cms/GetExternalLinks";
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
QJsonDocument cmsservice::AddExternalLink(QByteArray data)
{
    strUrl = "api/Cms/AddExternalLink";

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
QString cmsservice::UpdateExternalLink(QJsonDocument info)
{
    strUrl = "api/Cms/UpdateExternalLink";

    QString data;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl,info.toJson());

        data = QString(reply->readAll());
        MainWindow::SetResponseData(data);
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
    return data;
}
QJsonDocument cmsservice::DefaultSEOSettings()
{
    strUrl="api/Cms/GetDefaultSEOSettings";
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
QString cmsservice::UpdateSeoSettings(QJsonDocument info)
{
    strUrl = "api/Cms/SetSeoInfo";
//QJsonDocument doc;
    QString data;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl,info.toJson());

        //doc = QJsonDocument::fromJson(reply->readAll());
       // MainWindow::SetResponseData(doc);
        data=QString(reply->readAll());
        MainWindow::SetResponseData(data);
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
    return data;
}
QJsonDocument cmsservice::DeleteExternalLink(QString strLinkID)
{
    strUrl = "api/Cms/DeleteExternalLink?strLinkID="+strLinkID;
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
QString cmsservice::ApplyOrder(QJsonDocument info)
{
    strUrl = "api/Cms/UpdateOrderExternalLink";
    QString data;
    try
    {
        NetWorkRequest* networkRequest = new NetWorkRequest();
        QNetworkReply* reply = networkRequest->PostRequest(strUrl,info.toJson());
        data=QString(reply->readAll());
        MainWindow::SetResponseData(data);
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
    return data;
}
