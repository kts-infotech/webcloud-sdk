
/*---------------------------------------------------------------------------
    Workfile:BlockUserDlg.cpp
    Description: . Implementation of Class BlockUserDlg

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "blockuserdlg.h"
#include "qobjectdefs.h"
#include "ui_blockuserdlg.h"
#include <QJsonArray>
#include <QJsonObject>

#include "Services/accountservice.h"
#include <QPushButton>
#include <QSignalMapper>
#include <QStandardItemModel>
#include <mainwindow.h>
BlockUserDlg::BlockUserDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockUserDlg)
{
    ui->setupUi(this);
}

BlockUserDlg::~BlockUserDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: BlockUserDlg::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/

void BlockUserDlg::showEvent(QShowEvent *event)
{
    showtable();
    AddItemtotable();
}
/*---------------------------------------------------------------------------
    Function Name:showtable
    Return Value: Void
    Parameters:No parameters.
    Remarks:  To Show the Table View with userList.
---------------------------------------------------------------------------*/

void BlockUserDlg::showtable(){
    blUser_Model = new QStandardItemModel();
    blUser_Model->setHorizontalHeaderItem(0,new QStandardItem(tr("Email")));
    blUser_Model->setHorizontalHeaderItem(1,new QStandardItem(tr("FirstName")));
    blUser_Model->setHorizontalHeaderItem(2,new QStandardItem(tr("LastName")));
    blUser_Model->setHorizontalHeaderItem(3,new QStandardItem(tr("Phoneno")));
    blUser_Model->setHorizontalHeaderItem(4,new QStandardItem(tr("Address")));
    blUser_Model->setHorizontalHeaderItem(5,new QStandardItem(tr("Status")));
    blUser_Model->setHorizontalHeaderItem(6,new QStandardItem(tr("Button")));


    ui->BlockUserTable->setModel(blUser_Model);
}
/*---------------------------------------------------------------------------
    Function Name:AddItemtotable
    Return Value: Void
    Parameters:No parameters.
    Remarks:  To Show the Table View with userList.
---------------------------------------------------------------------------*/
void BlockUserDlg::AddItemtotable()
{

    QSignalMapper *signalMapper = new QSignalMapper(this);

    AccountService* getAllUsrsService = new AccountService();
      try
       {
        QJsonDocument document=getAllUsrsService->GetUserList();
        bluser_array = document.array();
        for(int i=0;i<bluser_array.count();i++)
        {
            QJsonObject jobj=bluser_array[i].toObject();
            QString Email(jobj.value("Email").toString());
            QString FirstName(jobj.value("FirstName").toString());
            QString LastName(jobj.value("LastName").toString());
            QString Phoneno(jobj.value("PhoneNo").toString());
            QString Address(jobj.value("Address").toString());
            QString Status(jobj.value("Status").toString());


if(LastName=="")
{
    LastName="NULL";
}
blUser_Model->setItem(i,0,new QStandardItem(Email));
blUser_Model->setItem(i,1,new QStandardItem(FirstName));
blUser_Model->setItem(i,2,new QStandardItem(LastName));
blUser_Model->setItem(i,3,new QStandardItem(Phoneno));
blUser_Model->setItem(i,4,new QStandardItem(Address));
QString status;
if (Status=="Blocked")
{
    status="UnBlock";
}
else
{
    status="Block";

}
block=new QPushButton();
block->setText(status);
blUser_Model->setItem(i,5,new QStandardItem(Status));
signalMapper->setMapping(block, i);
connect(block, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));


//blUser_Model->setItem(i,6,new QStandardItem(QPushButton());
        ui->BlockUserTable->setIndexWidget(blUser_Model->index(i,6),block);

//ui->BlockUserTable->setIndexWidget(blUser_Model->index(i,6),block);
       // connect(block, SIGNAL(mapper(int)), this, SLOT(onclicked(int)));

        }
        connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(onclicked(int)));

      }

        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
/*---------------------------------------------------------------------------
    Function Name:onclicked
    Return Value: void
    Parameters:int row.
    Remarks:  To block or unblock the user
---------------------------------------------------------------------------*/
void BlockUserDlg::onclicked(int row)
{
    int index=row;
    AccountService* blockuser = new AccountService();
      try
       {
        QJsonDocument document=blockuser->GetUserList();
        bluser_array = document.array();

    if(index!=-1){
        QJsonObject jObj = bluser_array[index].toObject();
        QString Email(jObj.value("Email").toString());
        QString FirstName(jObj.value("FirstName").toString());
        QString LastName(jObj.value("LastName").toString());
        QString Password(jObj.value("Password").toString());
        QString Phoneno(jObj.value("PhoneNo").toString());
        QString Address(jObj.value("Address").toString());
        QString Data="";
        QString btnText=block->text();
if(btnText=="Block")
{

                 Data = "{\"Email\":\"" + Email + "\",\"FirstName\":\"" + FirstName + "\",\"LastName\":\"" + LastName + "\",\"Password\":\"" + Password + "\",\"PhoneNo\":\"" + Phoneno + "\",\"Address\":\"" + Address + "\",\"IsActive\":\"" + "false"+"\",\"Status\":\"" +true+ "\" }";
   blockuser->Blockuser(Data.toUtf8());
   block->setText("UnBlock");
}

else if (btnText=="UnBlock"){

          Data = "{\"Email\":\"" + Email + "\",\"FirstName\":\"" + FirstName + "\",\"LastName\":\"" + LastName + "\",\"Password\":\"" + Password + "\",\"PhoneNo\":\"" + Phoneno + "\",\"Address\":\"" + Address + "\",\"IsActive\":true,\"Status\":\"" +"false"+ "\" }";
     blockuser->Blockuser(Data.toUtf8());
     block->setText("Block");


}
}
 }
     catch (std::exception& es) {
        MainWindow::SetResponseData(es.what());

    }
}
