/*********************************************************************
   Workfile : deletecommentdlg.h
   Description : Headerfile for DeleteCommentDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef DELETECOMMENTDLG_H
#define DELETECOMMENTDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class DeleteCommentDlg;
}

class DeleteCommentDlg : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteCommentDlg(QWidget *parent = nullptr);
    ~DeleteCommentDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);
    QStandardItemModel* m_pCommentListTable;
private slots:
    void on_UnSelect_All_Delete_Comment_clicked();

    void on_Select_All_Delete_Comment_clicked();

    void on_Delete_Selected_Delete_Comment_2_clicked();

    void on_Cancel_Delete_Comment_2_clicked();

    void on_Select_Forum_ID_currentTextChanged(const QString &arg1);

    void on_Select_Topic_ID_currentTextChanged(const QString &arg1);

    void on_Select_Thread_ID_currentTextChanged(const QString &arg1);

private:
    Ui::DeleteCommentDlg *ui;
    void LoadAllForums();
    QJsonArray m_JsonArray;
    QDateTime GetDateFromTicks(qint64 ticks);
    void CommentList();
};

#endif // DELETECOMMENTDLG_H
