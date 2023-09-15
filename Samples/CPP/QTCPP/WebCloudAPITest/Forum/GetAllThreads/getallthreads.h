/*********************************************************************
   Workfile : getallthreads.h
   Description : Headerfile for GetAllThreads CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef GETALLTHREADS_H
#define GETALLTHREADS_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDateTime>


namespace Ui {
class GetAllThreads;
}

class GetAllThreads : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllThreads(QWidget *parent = nullptr);
    ~GetAllThreads();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void on_Close_Get_All_Thread_clicked();

    void on_Select_Thread_ID_currentTextChanged(const QString &arg1);

private:
    Ui::GetAllThreads *ui;
    void LoadAllThreads();
    QJsonArray m_JsonArray;
    QDateTime GetDateFromTicks(qint64 ticks);
};

#endif // GETALLTHREADS_H
