/*---------------------------------------------------------------------------
    Workfile:GetAllUsers.cpp
    Description: . Implementation of Class GetAllUsers

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getallusers.h"
#include "ui_getallusers.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/commservice.h"

GetAllUsers::GetAllUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllUsers)
{
    ui->setupUi(this);
}

GetAllUsers::~GetAllUsers()
{
    delete ui;
}


/*---------------------------------------------------------------------------
    Function Name: GetAllUsers::on_BtnAllUsersCancelComm_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAllUsers::on_BtnAllUsersCancelComm_clicked()
{
    this->close();
}


/*---------------------------------------------------------------------------
    Function Name: GetAllUsers::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllUsers::showEvent(QShowEvent *event)
{
    CommService* getAllUsrsService = new CommService();
    try
    {
        //Get call
        QJsonDocument document = getAllUsrsService->GetAllUsers();

        m_jArray = document.array();

        //ComboBox is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("Name").toString());
            ui->ComboAllUserNamesComm->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


/*---------------------------------------------------------------------------
    Function Name:GetAllUsers::on_ComboAllUserNamesComm_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetAllUsers::on_ComboAllUserNamesComm_currentIndexChanged(int index)
{
    //Data is fed to labels from QJsonArray.
    if(index != -1){
        QJsonObject elementObj = m_jArray[index].toObject();
        QString categryName(elementObj.value("CategryName").toString());
        QString emailId(elementObj.value("EmailID").toString());
        QString phoneNumber(elementObj.value("PhoneNo").toString());
        QString address(elementObj.value("Address").toString());

        ui->lblAllUsersCtgryNameComm->setText(categryName);
        ui->lblAllUsersEmailComm->setText(emailId);
        ui->lblAllUsersPhoneComm->setText(phoneNumber);
        ui->lblAllUsersAddressComm->setText(address);
    }
}

