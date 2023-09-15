/*---------------------------------------------------------------------------
    Workfile:GetAllAdminUsers.cpp
    Description: . Implementation of Class GetAllAdminUsers

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getalladminusers.h"
#include "ui_getalladminusers.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/commservice.h"

GetAllAdminUsers::GetAllAdminUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllAdminUsers)
{
    ui->setupUi(this);
}

GetAllAdminUsers::~GetAllAdminUsers()
{
    delete ui;
}


/*---------------------------------------------------------------------------
    Function Name: GetAllAdminUsers::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllAdminUsers::showEvent(QShowEvent *event)
{
    CommService* getAllAdminUsrsService = new CommService();
    try
    {
        //Get call
        QJsonDocument document = getAllAdminUsrsService->GetAllAdminUsers();

        m_jArray = document.array();

        //ComboBox is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("Name").toString());
            ui->comboAllAdminNameComm->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


/*---------------------------------------------------------------------------
    Function Name: GetAllAdminUsers::on_btnAllAdminCancelComm_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAllAdminUsers::on_btnAllAdminCancelComm_clicked()
{
    this->close();
}


/*---------------------------------------------------------------------------
    Function Name:GetAllAdminUsers::on_comboAllAdminNameComm_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetAllAdminUsers::on_comboAllAdminNameComm_currentIndexChanged(int index)
{
    //Data is fed to labels from QJsonArray.
    if(index != -1){
        QJsonObject elementObj = m_jArray[index].toObject();
        QString categryName(elementObj.value("CategryName").toString());
        QString emailId(elementObj.value("EmailID").toString());
        QString phoneNumber(elementObj.value("PhoneNo").toString());
        QString address(elementObj.value("Address").toString());

        ui->lblAllAdminCtgryNameComm->setText(categryName);
        ui->lblAllAdminEmailComm->setText(emailId);
        ui->lblAllAdminPhComm->setText(phoneNumber);
        ui->lblAllAdminAddressComm->setText(address);
    }
}

