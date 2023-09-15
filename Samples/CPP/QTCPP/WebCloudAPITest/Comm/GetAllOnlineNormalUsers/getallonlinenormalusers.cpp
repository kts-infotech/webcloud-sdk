/*---------------------------------------------------------------------------
    Workfile:GetAllOnlineNormalUsers.cpp
    Description: . Implementation of Class GetAllOnlineNormalUsers

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getallonlinenormalusers.h"
#include "ui_getallonlinenormalusers.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/commservice.h"
#include "mainwindow.h"

GetAllOnlineNormalUsers::GetAllOnlineNormalUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllOnlineNormalUsers)
{
    ui->setupUi(this);
}

GetAllOnlineNormalUsers::~GetAllOnlineNormalUsers()
{
    delete ui;
}


/*---------------------------------------------------------------------------
    Function Name:GetAllOnlineNormalUsers::on_pushButton_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAllOnlineNormalUsers::on_pushButton_clicked()
{
    this->close();
}


/*---------------------------------------------------------------------------
    Function Name: GetAllOnlineNormalUsers::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllOnlineNormalUsers::showEvent(QShowEvent *event)
{
    CommService* getAllOnlineNormalUsrsService = new CommService();
    try
    {
        //Get call.
        QJsonDocument document = getAllOnlineNormalUsrsService->GetAllOnlineNormalUsers();

        m_jArray = document.array();

        //List widget is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("Name").toString());
            ui->listOnlnNormalComm->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


/*---------------------------------------------------------------------------
    Function Name:GetAllOnlineNormalUsers::on_listOnlnNormalComm_currentRowChanged
    Return Value: Void
    Parameters: New index of changed list widget row(int).
    Remarks:  Event handler for row change in list widget.
---------------------------------------------------------------------------*/
void GetAllOnlineNormalUsers::on_listOnlnNormalComm_currentRowChanged(int currentRow)
{
    //Data is fed to labels from QJsonArray.
    if(currentRow != -1){
        QJsonObject elementObj = m_jArray[currentRow].toObject();
        QString connectionId(elementObj.value("ConnectionId").toString());
        QString userType(elementObj.value("UserType").toString());
        QString name(elementObj.value("Name").toString());
        QString phoneNumber(elementObj.value("PhoneNo").toString());
        QString address(elementObj.value("Address").toString());

        ui->lblOnlnNormalCntnIdComm->setText(connectionId);
        ui->lblOnlnNormalUsrTypeComm->setText(userType);
        ui->lblOnlnNormalNameComm->setText(name);
        ui->lblOnlnNormalPhComm->setText(phoneNumber);
        ui->lblOnlnNormalAddressComm->setText(address);
    }
}

