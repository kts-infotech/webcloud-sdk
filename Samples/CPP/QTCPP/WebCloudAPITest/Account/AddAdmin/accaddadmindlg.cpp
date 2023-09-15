/*---------------------------------------------------------------------------
    Workfile:AccAddAdminDlg.cpp
    Description: . Implementation of Class GetAllBugList

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "accaddadmindlg.h"
#include "ui_accaddadmindlg.h"
#include <QJsonArray>
#include <QJsonObject>
#include <mainwindow.h>
#include "Services/accountservice.h"

AccAddAdminDlg::AccAddAdminDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccAddAdminDlg)
{
    ui->setupUi(this);
}

AccAddAdminDlg::~AccAddAdminDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name:on_accaddadmin_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Add Admin.
---------------------------------------------------------------------------*/
void AccAddAdminDlg::on_accaddadmin_clicked()
{
QString Email =ui->AccaddadminEmailLineEdit->text();
QString FirstName =ui->AccaddadminFirstNameLineEdit->text();
QString LastName =ui->AccaddadminLastFNameLineEdit->text();
QString Password =ui->AccaddadminPasswordLineEdit->text();
QString Phoneno =ui->AccaddadminPhonenoLineEdit->text();
QString Address =ui->AccaddadminAddressLineEdit->text();
try
{
    //serializiation of json.
    QString Data = "{\"Email\":\"" + Email + "\",\"FirstName\":\"" + FirstName + "\",\"LastName\":\"" + LastName + "\",\"Password\":\"" + Password + "\",\"PhoneNo\":\"" + Phoneno + "\",\"Address\":\"" + Address + "\",\"inactive\":null,\"Status\":\"" +true+ "\" }";
    AccountService* addadmin = new AccountService();

    //Calling  AccountService to make a post request.
    addadmin->AddAdmin(Data.toUtf8());

    //Displaying request data.
    QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
    MainWindow::SetRequestData(reqData);
}
catch (std::exception& es)
{
   MainWindow::SetResponseData(es.what());
}

}
/*---------------------------------------------------------------------------
    Function Name: GetAllBugList::on_pushButtonClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
