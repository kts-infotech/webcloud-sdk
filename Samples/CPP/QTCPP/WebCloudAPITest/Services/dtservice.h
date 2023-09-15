/*---------------------------------------------------------------------------
    $Workfile: DTService.h $

    Description: Header file for DTService class.

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom, Arun K, LAKSHMI V
    Last $Modtime: 08/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef DTSERVICE_H
#define DTSERVICE_H
#include <QString>
#include <QJsonDocument>
#include"mainwindow.h"

class DTService
{   QString m_strUsername,strUrl,user,strUrl2;
public:
    DTService();
     QJsonDocument GetAssignedTaskList();
     QJsonDocument GetBugTrackerTaskDetailsist();
     QJsonDocument GetUserTaskInfo();
     QJsonDocument GetAllBugList();
     QJsonDocument PostADeffectForm(QByteArray data);
     QJsonDocument GetAllTopicsInPost();
     QJsonDocument AssignedToInPost();
 private:
    QString strMainUrl;
};

#endif // DTSERVICE_H
