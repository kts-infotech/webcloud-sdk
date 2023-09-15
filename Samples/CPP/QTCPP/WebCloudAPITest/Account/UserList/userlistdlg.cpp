/*---------------------------------------------------------------------------
    Workfile:UserListDlg.cpp
    Description: . Implementation of Class UserListDlg

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/

#include "userlistdlg.h"
#include "ui_userlistdlg.h"
#include "mainwindow.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QStringListModel>
#include <QTableWidgetItem>
#include <qstringview.h>
#include "Services/accountservice.h"
#include <QStandardItemModel>
UserListDlg::UserListDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserListDlg)
{
    ui->setupUi(this);
}

UserListDlg::~UserListDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: UserListDlg::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void UserListDlg::showEvent(QShowEvent *event)
{
    showtable();
    AddItemtotable();
}

/*---------------------------------------------------------------------------
    Function Name:UserListDlg::showtable
    Return Value: Void
    Parameters:No parameters.
    Remarks: To show the list of user in table view.
---------------------------------------------------------------------------*/
void UserListDlg::showtable(){
    User_Model = new QStandardItemModel();
    User_Model->setHorizontalHeaderItem(0,new QStandardItem(tr("Email")));
    User_Model->setHorizontalHeaderItem(1,new QStandardItem(tr("FirstName")));
    User_Model->setHorizontalHeaderItem(2,new QStandardItem(tr("LastName")));
    User_Model->setHorizontalHeaderItem(3,new QStandardItem(tr("Phoneno")));
    User_Model->setHorizontalHeaderItem(4,new QStandardItem(tr("Address")));
    ui->UserListTable->setModel(User_Model);
}
/*---------------------------------------------------------------------------
    Function Name:UserListDlg::AddItemtotable
    Return Value: Void
    Parameters:No parameters.
    Remarks: Add the User Details to standardItemModel.
---------------------------------------------------------------------------*/
void UserListDlg::AddItemtotable()
{
    AccountService* getAllUsrsService = new AccountService();
      try
       {
        QJsonDocument document=getAllUsrsService->GetUserList();
        user_array = document.array();
        for(int i=0;i<user_array.count();i++)
        {
            QJsonObject jobj=user_array[i].toObject();
            QString Email(jobj.value("Email").toString());
            QString FirstName(jobj.value("FirstName").toString());
            QString LastName(jobj.value("LastName").toString());
            QString Phoneno(jobj.value("PhoneNo").toString());
            QString Address(jobj.value("Address").toString());

if(LastName=="")
{
    LastName="NULL";
}
User_Model->setItem(i,0,new QStandardItem(Email));
User_Model->setItem(i,1,new QStandardItem(FirstName));
User_Model->setItem(i,2,new QStandardItem(LastName));
User_Model->setItem(i,3,new QStandardItem(Phoneno));
User_Model->setItem(i,4,new QStandardItem(Address));

        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
