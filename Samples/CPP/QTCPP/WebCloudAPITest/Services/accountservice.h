#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H

#include <QString>
#include <QJsonDocument>

class AccountService
{
public:
    AccountService();
     QJsonDocument GetUserList();
     QJsonDocument AddAdmin(QByteArray data);
     QJsonDocument AddUser(QByteArray data);

     QJsonDocument GetAdminList();

     QJsonDocument DeleteUser(QString email);
     QJsonDocument DeleteAdmin(QString email);
     QJsonDocument InviteUser(QByteArray Data);

     QJsonDocument Generatetemp();
     QJsonDocument Blockuser(QByteArray data);
private:
    QString strMainUrl;
    QString strUrl;
};

#endif // ACCOUNTSERVICE_H
