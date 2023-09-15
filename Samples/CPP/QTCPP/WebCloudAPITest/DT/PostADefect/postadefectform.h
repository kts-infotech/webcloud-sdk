/*---------------------------------------------------------------------------
    $Workfile: PostADefectForm.h $

    Description: Header file for PostADefectForm class.

    Copyright (C) 2022 KTS Computers
    All rights reserved.

   Author: Tom,LAKSHMI V
    Last $Modtime: 08/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef POSTADEFECTFORM_H
#define POSTADEFECTFORM_H
#include "mainwindow.h"
#include <QDialog>
#include <QJsonArray>
namespace Ui {
class PostADefectForm;
}

class PostADefectForm : public QDialog
{
    Q_OBJECT
public:
    explicit PostADefectForm(QWidget *parent = nullptr);
    ~PostADefectForm();

private:
    Ui::PostADefectForm *ui;
     QJsonArray m_jArray1, m_jArray2;
    QString AttachmentBase64,AttachmentName, AttachmentType,strTopicID;
    int TopicID;
    QString EncodeToBase64(QString);
protected:
    void showEvent(QShowEvent* event);
private slots:
   void on_comboBox_currentIndexChanged(int index);
   void on_pushButton_Browse_clicked();
   void on_pushButtonPostThread_clicked();
   void on_pushButton_Close_clicked();
};

#endif // POSTADEFECTFORM_H
