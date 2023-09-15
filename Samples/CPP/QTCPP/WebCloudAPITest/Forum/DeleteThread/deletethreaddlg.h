/*********************************************************************
   Workfile : deletethreaddlg.h
   Description : Headerfile for DeleteThreadDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef DELETETHREADDLG_H
#define DELETETHREADDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDateTime>

namespace Ui {
class DeleteThreadDlg;
}

class DeleteThreadDlg : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteThreadDlg(QWidget *parent = nullptr);
    ~DeleteThreadDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);

private slots:
    void on_Delete_Delete_Thread_clicked();

    void on_Close_Delete_This_Thread_clicked();

    void on_Select_Delete_Thread_ID_currentTextChanged(const QString &arg1);

private:
    Ui::DeleteThreadDlg *ui;
    void LoadAllThreads();
    QJsonArray m_JsonArray;
    QString m_ThreadId;
    QDateTime GetDateFromTicks(qint64 ticks);
};

#endif // DELETETHREADDLG_H
