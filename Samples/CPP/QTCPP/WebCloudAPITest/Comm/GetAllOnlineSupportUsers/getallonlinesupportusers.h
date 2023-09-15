/*---------------------------------------------------------------------------
    $Workfile: GetAllOnlineSupportUsers.h $

    Description: Header file for GetAllOnlineSupportUsers class.

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETALLONLINESUPPORTUSERS_H
#define GETALLONLINESUPPORTUSERS_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetAllOnlineSupportUsers;
}

class GetAllOnlineSupportUsers : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllOnlineSupportUsers(QWidget *parent = nullptr);
    ~GetAllOnlineSupportUsers();

private:
    Ui::GetAllOnlineSupportUsers *ui;
    QJsonArray m_jArray;
protected:
    void showEvent(QShowEvent* event);
private slots:
    void on_btnOnSupportClose_clicked();
    void on_listOnSupportComm_currentRowChanged(int currentRow);
};

#endif // GETALLONLINESUPPORTUSERS_H
