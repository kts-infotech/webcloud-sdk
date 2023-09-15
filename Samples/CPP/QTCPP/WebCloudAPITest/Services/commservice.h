/*---------------------------------------------------------------------------
    $Workfile: CommService.h $

    Description: Header file for CommService class.

    Copyright (C) 2022 KTS InfoTech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef COMMSERVICE_H
#define COMMSERVICE_H
#include <QString>
#include <QJsonDocument>


class CommService
{
public:
    CommService();
    QJsonDocument GetAllUsers();
    QJsonDocument GetAllAdminUsers();
    QJsonDocument GetAllOnlineUsers();
    QJsonDocument GetAllOnlineNormalUsers();
    QJsonDocument GetAllOnlineSupportUsers();
    QJsonDocument SendEmail(QByteArray);
    QJsonDocument GetReq(QString url); //Unwanted
private:
    QString strMainUrl;
    QString strUrl;
};

#endif // COMMSERVICE_H
