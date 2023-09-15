/*---------------------------------------------------------------------------
    $Workfile: GetAllUsers.h $

    Description: Header file for GetAllUsers class.

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETALLUSERS_H
#define GETALLUSERS_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetAllUsers;
}

class GetAllUsers : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllUsers(QWidget *parent = nullptr);
    ~GetAllUsers();

private slots:
    void on_BtnAllUsersCancelComm_clicked();

    void on_ComboAllUserNamesComm_currentIndexChanged(int index);

private:
    Ui::GetAllUsers *ui;
    QJsonArray m_jArray;
protected:
    void showEvent(QShowEvent* event);
};

#endif // GETALLUSERS_H
