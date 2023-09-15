/*********************************************************************
   Workfile : audtopicsdlg.h
   Description : Headerfile for AUDTopicsDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef AUDTOPICSDLG_H
#define AUDTOPICSDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class AUDTopicsDlg;
}

class AUDTopicsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AUDTopicsDlg(QWidget *parent = nullptr);
    ~AUDTopicsDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);

private slots:
    void on_Select_All_AUD_Topics_clicked();

    void on_UNSelect_AUD_Topic_clicked();

    void on_Cancel_AUD_Topic_clicked();

    void on_comboBox_Forum_Name_Existing_currentTextChanged(const QString &arg1);

    void on_pushButton_Delete_clicked();

    void on_AddNew_AUD_Topic_clicked();

    void on_listWidget_Existing_Topics_itemClicked(QListWidgetItem *item);

    void on_Add_AUD_Topic_clicked();

private:
    Ui::AUDTopicsDlg *ui;
    void LoadAllForums();
    int m_TopicId;
    QString m_ForumId;
};

#endif // AUDTOPICSDLG_H
