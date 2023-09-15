/*---------------------------------------------------------------------------
    $Workfile: GetAssignedTaskList.h $

    Description: Header file for GetAssignedTaskList class.

    Copyright (C) 2022 KTS Computers
    All rights reserved.

   Author: Tom,LAKSHMI V
    Last $Modtime: 08/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETASSIGNEDTASKLIST_H
#define GETASSIGNEDTASKLIST_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetAssignedTaskList;
}

class GetAssignedTaskList : public QDialog
{
    Q_OBJECT

public:
    explicit GetAssignedTaskList(QWidget *parent = nullptr);
    ~GetAssignedTaskList();

private:
    Ui::GetAssignedTaskList *ui;
     QJsonArray m_jArray;
     QString m_Usrname;

protected:
    void showEvent(QShowEvent* event);
private slots:
    void on_comboBoxTaskID_currentIndexChanged(int index);
    void on_pushButtonClose_clicked();
};

#endif // GETASSIGNEDTASKLIST_H
