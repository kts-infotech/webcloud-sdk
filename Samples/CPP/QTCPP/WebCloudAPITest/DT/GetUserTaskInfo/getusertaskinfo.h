/*---------------------------------------------------------------------------
    $Workfile: GetUserTaskInfo.h $

    Description: Header file for GetUserTaskInfo class.

    Copyright (C) 2022 KTS Computers
    All rights reserved.

   Author: Tom,LAKSHMI V
    Last $Modtime: 08/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETUSERTASKINFO_H
#define GETUSERTASKINFO_H
#include<QJsonArray>
#include <QDialog>

namespace Ui {
class GetUserTaskInfo;
}

class GetUserTaskInfo : public QDialog
{
    Q_OBJECT

public:
    explicit GetUserTaskInfo(QWidget *parent = nullptr);
    ~GetUserTaskInfo();

private:
    Ui::GetUserTaskInfo *ui;
    QJsonArray m_jArray;

private slots:
   void on_pushButtonGetInfo_clicked();
   void on_comboBoxBugTaskTitle_currentIndexChanged(int index);
   void on_pushButtonClose_clicked();
};

#endif // GETUSERTASKINFO_H
