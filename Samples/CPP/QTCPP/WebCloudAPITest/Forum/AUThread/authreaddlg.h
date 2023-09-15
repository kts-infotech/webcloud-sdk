/*********************************************************************
   Workfile : authreaddlg.h
   Description : Headerfile for AUThreadDlg CLASS
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#ifndef AUTHREADDLG_H
#define AUTHREADDLG_H
#include "Services/forumservices.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class AUThreadDlg;
}

class AUThreadDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AUThreadDlg(QWidget *parent = nullptr);
    ~AUThreadDlg();
    ForumServices *m_pForumServices;
    QString StringifyJson(QJsonDocument jsonDoc);

private slots:
    void on_Upload_Image_pushButton_clicked();

    void on_Add_AU_clicked();

    void on_Cancel_AU_clicked();

    void on_pushButton_AddNew_clicked();

    void on_comboBox_Existing_Forum_currentTextChanged(const QString &arg1);

    void on_Existing_Topic_Name_currentTextChanged(const QString &arg1);

    void on_listWidget_Existing_Threads_itemClicked(QListWidgetItem *item);

    void on_Upload_Image_Check_Box_stateChanged(int arg1);

private:
    Ui::AUThreadDlg *ui;
    void LoadAllForums();
    QImage m_Imageupload;
    //QVariant m_ImgExisting;
    QJsonValue m_ImgExisting;
    QString m_ForumId,m_TopicId,m_ThreadId,m_ImageName,m_ImageNameExisting;
    qint64 GetTicksNow();
    QString GetBase64BitImage();
};

#endif // AUTHREADDLG_H
