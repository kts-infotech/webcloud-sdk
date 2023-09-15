/*---------------------------------------------------------------------------
    $Workfile: GetAllOnlineNormalUsers.h $

    Description: Header file for GetAllOnlineNormalUsers class.

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef GETALLONLINENORMALUSERS_H
#define GETALLONLINENORMALUSERS_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetAllOnlineNormalUsers;
}

class GetAllOnlineNormalUsers : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllOnlineNormalUsers(QWidget *parent = nullptr);
    ~GetAllOnlineNormalUsers();

private slots:
    void on_pushButton_clicked();

    void on_listOnlnNormalComm_currentRowChanged(int currentRow);

private:
    Ui::GetAllOnlineNormalUsers *ui;
    QJsonArray m_jArray;
protected:
    void showEvent(QShowEvent* event);
};

#endif // GETALLONLINENORMALUSERS_H
