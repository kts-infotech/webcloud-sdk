
/*---------------------------------------------------------------------------
    Workfile:AddUserDlg.cpp
    Description: . Implementation of Class AddUserDlg

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "adduserdlg.h"
#include "ui_adduserdlg.h"

#include <Services/accountservice.h>

#include <mainwindow.h>

AddUserDlg::AddUserDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserDlg)
{
    ui->setupUi(this);
}

AddUserDlg::~AddUserDlg()
{
    delete ui;
}
//AccaddUserEmailLineEdit
/*---------------------------------------------------------------------------
    Function Name:on_buttonBox_2_accepted
    Return Value: Void
    Parameters:No parameters.
    Remarks:  To Add user.
---------------------------------------------------------------------------*/
void AddUserDlg::on_buttonBox_2_accepted()
{
    QString Email =ui->AccaddUserEmailLineEdit->text();
    QString FirstName =ui->AccaddUserFirstNameLineEdit->text();
    QString LastName =ui->AccaddUserLastFNameLineEdit->text();
    QString Password =ui->AccaddUserPasswordLineEdit->text();
    QString Phoneno =ui->AccaddUserPhonenoLineEdit->text();
    QString Address =ui->AccaddUserAddressLineEdit->text();
    try
    {
        //serializiation of json.
        QString Data = "{\"Email\":\"" + Email + "\",\"FirstName\":\"" + FirstName + "\",\"LastName\":\"" + LastName + "\",\"Password\":\"" + Password + "\",\"PhoneNo\":\"" + Phoneno + "\",\"Address\":\"" + Address + "\",\"inactive\":null,\"Status\":\"" +true+ "\" }";
        AccountService* adduser = new AccountService();

        //Calling  AccountService to make a post request.
        adduser->AddUser(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}

