/*********************************************************************
   Workfile : forumservices.h
   Description : Headerfile for ForumServices CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef FORUMSERVICES_H
#define FORUMSERVICES_H
#include "networkrequest.h"
#include <QJsonDocument>

class ForumServices
{
public:
    NetWorkRequest *m_NetworkReq;
    ForumServices();
    QJsonDocument GetAllForums();
    QJsonDocument GetAllForumIdWithNames();
    QJsonDocument GetAllTopicsWithForumID(QString strForumId);
    QJsonDocument GetAllThreadsWithTopicID(QString strTopicID);
    QJsonDocument GetAllTopics();
    QJsonDocument GetAllThreads();
    QJsonDocument DeleteThread(QString strThreadID);
    QString DeleteForum(QString strForumID);
    QString DeleteTopic(QString strTopicID);
    QString AddForum(QJsonDocument Info);
    QString UpdateForum(QJsonDocument Info);
    QJsonDocument GetExistingGroups();
    QString  RetrieveEmail(QString strGroupId);
    QString AddTopics(QJsonDocument Info);
    QString UpdateTopic(QJsonDocument Info);
    QString AddThread(QJsonDocument trd);
    QString UpdateThread(QJsonDocument trd);
    QJsonDocument GetThreadByID(QString strThreadID);
    QJsonDocument GetMsgsByTrdID(QString strThread);
    QJsonDocument DeleteComments(QJsonDocument strMsgID);
    QJsonDocument AddComments(QJsonDocument Info);
    QJsonDocument ForceDeleteForum(QString strForumId);
    QJsonDocument ForceDeleteTopic(QString strTopicId);

};

#endif // FORUMSERVICES_H
