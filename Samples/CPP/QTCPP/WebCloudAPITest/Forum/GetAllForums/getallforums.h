/*********************************************************************
   Workfile : getallforums.h
   Description : Headerfile for GetAllForums CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef GETALLFORUMS_H
#define GETALLFORUMS_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>


namespace Ui {
class GetAllForums;
}

class GetAllForums : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllForums(QWidget *parent = nullptr);
    ~GetAllForums();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);

private slots:
    void on_Close_Get_All_Forum_clicked();

    void on_Select_Forum_ID_currentTextChanged(const QString &arg1);

private:
    Ui::GetAllForums *ui;
    void LoadAllForums();
    QJsonArray m_JsonArray;

};

#endif // GETALLFORUMS_H
