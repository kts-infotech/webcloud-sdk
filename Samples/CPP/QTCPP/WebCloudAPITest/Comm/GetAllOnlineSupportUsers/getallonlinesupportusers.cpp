/*---------------------------------------------------------------------------
    Workfile:GetAllOnlineSupportUsers.cpp
    Description: . Implementation of Class GetAllOnlineSupportUsers

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getallonlinesupportusers.h"
#include "ui_getallonlinesupportusers.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/commservice.h"
#include "mainwindow.h"

GetAllOnlineSupportUsers::GetAllOnlineSupportUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllOnlineSupportUsers)
{
    ui->setupUi(this);
}

GetAllOnlineSupportUsers::~GetAllOnlineSupportUsers()
{
    delete ui;
}


/*---------------------------------------------------------------------------
    Function Name: GetAllOnlineSupportUsers::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllOnlineSupportUsers::showEvent(QShowEvent *event)
{
    CommService* getAllOnlineSupportUsrsService = new CommService();
    try
    {
        //Get call.
        QJsonDocument document = getAllOnlineSupportUsrsService->GetAllOnlineSupportUsers();

        m_jArray = document.array();

        //List Widget is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("Name").toString());
            ui->listOnSupportComm->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


/*---------------------------------------------------------------------------
    Function Name: GetAllOnlineSupportUsers::on_btnOnSupportClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAllOnlineSupportUsers::on_btnOnSupportClose_clicked()
{
    this->close();
}


/*---------------------------------------------------------------------------
    Function Name:GetAllOnlineSupportUsers::on_listOnSupportComm_currentRowChanged
    Return Value: Void
    Parameters: New index of changed list widget row(int).
    Remarks:  Event handler for row change in list widget.
---------------------------------------------------------------------------*/
void GetAllOnlineSupportUsers::on_listOnSupportComm_currentRowChanged(int currentRow)
{
    //Data is fed to labels from QJsonArray.
    if(currentRow != -1){
        QJsonObject elementObj = m_jArray[currentRow].toObject();
        QString connectionId(elementObj.value("ConnectionId").toString());
        QString userType(elementObj.value("UserType").toString());
        QString name(elementObj.value("Name").toString());
        QString phoneNumber(elementObj.value("PhoneNo").toString());
        QString address(elementObj.value("Address").toString());

        ui->lblOnSupportCntnIdComm->setText(connectionId);
        ui->lblOnSupportUsrTypeComm->setText(userType);
        ui->lblOnSupportNameComm->setText(name);
        ui->lblOnSupportPhComm->setText(phoneNumber);
        ui->lblOnSupportAddressComm->setText(address);
    }
}

