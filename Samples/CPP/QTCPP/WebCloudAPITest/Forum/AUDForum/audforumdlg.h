/*********************************************************************
   Workfile : audforumdlg.h
   Description : Headerfile for AUDForumDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef AUDFORUMDLG_H
#define AUDFORUMDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class AUDForumDlg;
}
class AUDForumDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AUDForumDlg(QWidget *parent = nullptr);
    ~AUDForumDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void on_pushButton_Retrive_Email_AUD_clicked();

    void on_Add_AUD_Forum_clicked();

    void on_Delete_AUD_Forum_clicked();

    void on_Cancel_AUD_Forum_clicked();

    void on_listWidget_Existing_forums_itemClicked(QListWidgetItem *item);

    void on_pushButton_AddNew_clicked();

private:
    Ui::AUDForumDlg *ui;
    void LoadAllForums();
    QString m_FormId;
};

#endif // AUDFORUMDLG_H
