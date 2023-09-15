#ifndef APPAUTHSERVICE_H
#define APPAUTHSERVICE_H
#include<QString>
#include <QJsonDocument>

class AppAuthService
{

    QString m_strUsername,m_strPassword,m_strUrl,m_strAuthToken;
public:
    AppAuthService();
    AppAuthService(QString url,QString user,QString pass);
    QJsonDocument ValidateUser();
};

#endif // APPAUTHSERVICE_H
