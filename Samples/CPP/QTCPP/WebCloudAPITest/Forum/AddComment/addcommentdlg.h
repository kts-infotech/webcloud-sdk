/*********************************************************************
   Workfile : addcommentdlg.h
   Description : Headerfile for AddCommentDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef ADDCOMMENTDLG_H
#define ADDCOMMENTDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDialog>

namespace Ui {
class AddCommentDlg;
}

class MainWindow;

class AddCommentDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddCommentDlg(QWidget *parent = nullptr);
    MainWindow * m_pMainwindow;  //ptr to mainwindow
    ~AddCommentDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void on_Add_Add_Comment_clicked();

    void on_Cancel_Add_Comments_clicked();

    void on_Select_Forum_ID_currentTextChanged(const QString &arg1);

    void on_Select_Topic_ID_currentTextChanged(const QString &arg1);

    void on_Select_Thread_ID_currentTextChanged(const QString &arg1);

private:
    Ui::AddCommentDlg *ui;
    void LoadAllForums();
    qint64 GetTicksNow();
 };

#endif // ADDCOMMENTDLG_H
