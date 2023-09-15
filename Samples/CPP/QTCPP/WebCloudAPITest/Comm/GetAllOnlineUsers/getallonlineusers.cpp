/*---------------------------------------------------------------------------
    Workfile:GetAllOnlineUsers.cpp
    Description: . Implementation of Class GetAllOnlineUsers

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getallonlineusers.h"
#include "ui_getallonlineusers.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/commservice.h"
#include "mainwindow.h"

GetAllOnlineUsers::GetAllOnlineUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllOnlineUsers)
{
    ui->setupUi(this);
}

GetAllOnlineUsers::~GetAllOnlineUsers()
{
    delete ui;
}


/*---------------------------------------------------------------------------
    Function Name: GetAllOnlineUsers::on_pushButton_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAllOnlineUsers::on_pushButton_clicked()
{
    this->close();
}


/*---------------------------------------------------------------------------
    Function Name: GetAllOnlineUsers::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllOnlineUsers::showEvent(QShowEvent *event)
{
    CommService* getAllOnlineUsrsService = new CommService();
    try
    {
        //Get call.
        QJsonDocument document = getAllOnlineUsrsService->GetAllOnlineUsers();

        m_jArray = document.array();

        //List Widget is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("Name").toString());
            ui->listOnlineUsersComm->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


/*---------------------------------------------------------------------------
    Function Name:GetAllOnlineUsers::on_listOnlineUsersComm_currentRowChanged
    Return Value: Void
    Parameters: New index of changed list widget row(int).
    Remarks:  Event handler for row change in list widget.
---------------------------------------------------------------------------*/
void GetAllOnlineUsers::on_listOnlineUsersComm_currentRowChanged(int currentRow)
{
    //Data is fed to labels from QJsonArray.
    if(currentRow != -1){
        QJsonObject elementObj = m_jArray[currentRow].toObject();
        QString connectionId(elementObj.value("ConnectionId").toString());
        QString userType(elementObj.value("UserType").toString());
        QString name(elementObj.value("Name").toString());
        QString phoneNumber(elementObj.value("PhoneNo").toString());
        QString address(elementObj.value("Address").toString());

        ui->lblOnlineUsersContnIdComm->setText(connectionId);
        ui->lblOnlineUsersUsrTypeComm->setText(userType);
        ui->lblOnlineUsersNameComm->setText(name);
        ui->lblOnlineUsersPhNoComm->setText(phoneNumber);
        ui->lblOnlineUsersAddressComm->setText(address);
    }
}

