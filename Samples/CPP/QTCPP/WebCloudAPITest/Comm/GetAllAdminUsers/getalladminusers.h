/*---------------------------------------------------------------------------
    $Workfile: GetAllAdminUsers.h $

    Description: Header file for GetAllAdminUsers class.

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETALLADMINUSERS_H
#define GETALLADMINUSERS_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetAllAdminUsers;
}

class GetAllAdminUsers : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllAdminUsers(QWidget *parent = nullptr);
    ~GetAllAdminUsers();

private:
    Ui::GetAllAdminUsers *ui;
    QJsonArray m_jArray;
protected:
    void showEvent(QShowEvent* event);
private slots:
    void on_btnAllAdminCancelComm_clicked();
    void on_comboAllAdminNameComm_currentIndexChanged(int index);
};

#endif // GETALLADMINUSERS_H
