/*---------------------------------------------------------------------------
    Workfile:InviteUserDlg.cpp
    Description: . Implementation of Class InviteUserDlg

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/

#include "inviteuserdlg.h"
#include "ui_inviteuserdlg.h"

#include <Services/accountservice.h>

#include <mainwindow.h>

InviteUserDlg::InviteUserDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InviteUserDlg)
{
    ui->setupUi(this);
}

InviteUserDlg::~InviteUserDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name:on_pushButton_2_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Invite User
---------------------------------------------------------------------------*/




void InviteUserDlg::on_Inviteuserclosetn_clicked()
{
    QString Email =ui->InviteUser_Email->text();
    QString Msg =ui->Invite_user_msg->text();
    try
    {
        //serializiation of json.
        QString Data = "{\"UserCategory\":\"1000\",\"UserEmail\":\"" + Email + "\",\"UserMessage\":\"" + Msg +"\" }";
        AccountService* Inviteusr = new AccountService();

        //Calling  AccountService to make a post request.
        Inviteusr->InviteUser(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);

    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}

