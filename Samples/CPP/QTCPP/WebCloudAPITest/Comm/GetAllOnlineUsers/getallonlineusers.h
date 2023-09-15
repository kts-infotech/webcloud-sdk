/*---------------------------------------------------------------------------
    $Workfile: GetAllOnlineUsers.h $

    Description: Header file for GetAllOnlineUsers class.

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETALLONLINEUSERS_H
#define GETALLONLINEUSERS_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetAllOnlineUsers;
}

class GetAllOnlineUsers : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllOnlineUsers(QWidget *parent = nullptr);
    ~GetAllOnlineUsers();

private slots:
    void on_pushButton_clicked();

    void on_listOnlineUsersComm_currentRowChanged(int currentRow);

private:
    Ui::GetAllOnlineUsers *ui;
    QJsonArray m_jArray;
protected:
    void showEvent(QShowEvent* event);

};

#endif // GETALLONLINEUSERS_H
