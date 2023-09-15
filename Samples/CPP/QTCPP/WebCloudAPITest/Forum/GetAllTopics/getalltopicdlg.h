/*********************************************************************
   Workfile : getalltopicdlg.h
   Description : Headerfile for GetAllTopicDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef GETALLTOPICDLG_H
#define GETALLTOPICDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
namespace Ui {
class GetAllTopicDlg;
}

class GetAllTopicDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllTopicDlg(QWidget *parent = nullptr);
    ~GetAllTopicDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void on_Close_Get_All_Topic_clicked();

    void on_Select_Topic_ID_currentTextChanged(const QString &arg1);

private:
    Ui::GetAllTopicDlg *ui;
    void LoadAllTopics();
    QJsonArray m_JsonArray;
};

#endif // GETALLTOPICDLG_H
