#include "appauthservice.h"
#include "networkrequest.h"
#include <QJsonObject>

AppAuthService::AppAuthService()
{

}

AppAuthService::AppAuthService(QString url, QString user, QString pass)
    :m_strAuthToken("")
{
    m_strUsername = user;
    m_strPassword=pass;
    m_strUrl=url;
}

QJsonDocument AppAuthService::ValidateUser()
{
    NetWorkRequest * netReq = new NetWorkRequest();
    try
    {
        netReq->SetTimeout(30000);
        QString apiUrl =m_strUrl+ "/api/Auth/ValidateUser?UserID=" + m_strUsername + "&Password=" + m_strPassword;
        QJsonDocument doc = QJsonDocument::fromJson(netReq->ValidateUser(apiUrl)->readAll());
        QJsonObject obj = doc.object();
        NetWorkRequest::SetAuthToken(obj["AuthenticationToken"].toString());
        NetWorkRequest::SetMainUrl(m_strUrl);
        netReq->deleteLater();
        return doc;

    }
    catch (std::exception& es)
    {
        netReq->deleteLater();
        throw es;
    }
}
