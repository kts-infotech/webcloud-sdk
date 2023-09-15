#include "networkrequest.h"
#include "mainwindow.h"
#include <stdexcept>
#include <QApplication>

QString NetWorkRequest::m_strMainUrl="";
QString NetWorkRequest::m_strAuthToken="";

NetWorkRequest::NetWorkRequest(QObject *parent) : QObject(parent)
{
    m_Manager=new QNetworkAccessManager(this);
    m_EvLoop = new QEventLoop(this);
    m_bErrorStatus=false;
    m_Manager->setTransferTimeout(30000);
    connect(m_Manager,&QNetworkAccessManager::finished,this,&NetWorkRequest::ReplyReciever);

}

QNetworkReply *   NetWorkRequest::ValidateUser(QString strUrl)
{

    QNetworkRequest request;
    request.setUrl(QUrl(strUrl));
    MainWindow::SetStatusBar(strUrl);
    m_Manager->get(request);
    m_EvLoop->exec();
    if(m_bErrorStatus)
    {
        throw std::runtime_error(m_strErrorInfo.toLatin1());
    }
    else
    {
        return m_Reply;
    }
}

QNetworkReply *  NetWorkRequest::GetRequest(QString strUrl)
{

    QNetworkRequest request;
    request.setUrl(QUrl(m_strMainUrl+"/"+strUrl));
    MainWindow::SetStatusBar(strUrl);
    QString strBearHeader = "Bearer "+m_strAuthToken;
    request.setRawHeader(QByteArray("Authorization"),strBearHeader.toUtf8());
    m_Manager->get(request);
    m_EvLoop->exec();
    if(m_bErrorStatus)
    {
        throw std::runtime_error(m_strErrorInfo.toLatin1());
    }
    else
    {
        return m_Reply;
    }
}

QNetworkReply *  NetWorkRequest::PostRequest(QString strUrl,QByteArray data)
{
    QNetworkRequest request;
    request.setUrl(QUrl(m_strMainUrl+"/"+strUrl));
    MainWindow::SetStatusBar(strUrl);
    QString strBearHeader = "Bearer "+m_strAuthToken;
    request.setRawHeader(QByteArray("Authorization"),strBearHeader.toUtf8());
    request.setRawHeader("Content-Type","application/json");
    m_Manager->post(request,data);
    m_EvLoop->exec();
    if(m_bErrorStatus)
    {
        throw std::runtime_error(m_strErrorInfo.toLatin1());
    }
    else
    {
        return m_Reply;
    }
}

void NetWorkRequest::SetAuthToken(QString strToken)
{
    m_strAuthToken=strToken;
}

void NetWorkRequest::SetMainUrl(QString strMainUrl)
{
    m_strMainUrl=strMainUrl;
}


//QNetworkReply *  NetWorkRequest::PostRequest(QString strUrl,QString strHeader,QByteArray data)
//{
//    QNetworkRequest request;
//    request.setUrl(QUrl(strUrl));
//    MainWindow::SetStatusBar(strUrl);
//    QString strBearHeader = "Bearer "+strHeader;
//    request.setRawHeader(QByteArray("Authorization"),strBearHeader.toUtf8());
//    request.setRawHeader("Content-Type","application/json");
//    m_Manager->post(request,data);
//    m_EvLoop->exec();
//    if(m_bErrorStatus)
//    {
//        throw std::runtime_error(m_strErrorInfo.toLatin1());
//    }
//    else
//    {
//        return m_Reply;
//    }
//}

void NetWorkRequest::SetTimeout(int iMaxWaitTime)
{
    m_Manager->setTransferTimeout(iMaxWaitTime);
}

void NetWorkRequest::ReplyReciever(QNetworkReply *reply)
{
    if (reply->error())
    {
        m_bErrorStatus=true;
        m_EvLoop->quit();
        m_strErrorInfo=reply->errorString();
    }
    else
    {
        m_bErrorStatus=false;
        m_EvLoop->quit();
        m_Reply=reply;
    }
    reply->deleteLater();
}
