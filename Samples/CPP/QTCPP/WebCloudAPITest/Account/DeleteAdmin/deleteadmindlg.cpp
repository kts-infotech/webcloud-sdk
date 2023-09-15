/*---------------------------------------------------------------------------
    Workfile:DeleteAdminDlg.cpp
    Description: . Implementation of Class DeleteAdminDlg

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/

#include "deleteadmindlg.h"
#include "ui_deleteadmindlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/accountservice.h"

DeleteAdminDlg::DeleteAdminDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteAdminDlg)
{
    ui->setupUi(this);
}

DeleteAdminDlg::~DeleteAdminDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: DeleteAdminDlg::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void DeleteAdminDlg::showEvent(QShowEvent *event)
{
    AccountService* getadmindel = new AccountService();
    try
    {
        //Get call
        QJsonDocument document = getadmindel->GetAdminList();

        m_jArray = document.array();

        //ComboBox is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("FirstName").toString());
            ui->AccDeleteAdmincomboBox->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}
/*---------------------------------------------------------------------------
    Function Name:on_comboBox_currentIndexChanged(int index)
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void DeleteAdminDlg::on_comboBox_currentIndexChanged(int index)
{
  }
/*---------------------------------------------------------------------------
    Function Name:on_pushButton_clicked
    Return Value: Void
    Remarks:  Delete the admin
---------------------------------------------------------------------------*/

void DeleteAdminDlg::on_pushButton_clicked()
{  try
    {
    AccountService *deleteadmin = new AccountService();

    QJsonDocument document = deleteadmin->GetAdminList();

    m_jArray = document.array();

int index=ui->AccDeleteAdmincomboBox->currentIndex();
if(index != -1){
    QJsonObject elementObj = m_jArray[index].toObject();
    QString Email(elementObj.value("Email").toString());



   deleteadmin->DeleteAdmin(Email);

    }
    }


    catch (std::exception& es)
    {
      MainWindow::SetResponseData(es.what());
     }
}

