/*---------------------------------------------------------------------------
    Workfile:DeleteUserDlg.cpp
    Description: . Implementation of Class DeleteUserDlg

    Copyright (C) 2002 KTS Computers
    All rights reserved.

    Author: Tom,Chandradurga S
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/

#include "deleteuserdlg.h"
#include "qjsonobject.h"
#include "ui_deleteuserdlg.h"

#include <Services/accountservice.h>

#include <mainwindow.h>

DeleteUserDlg::DeleteUserDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteUserDlg)
{
    ui->setupUi(this);
}
/*---------------------------------------------------------------------------
    Function Name: DeleteUserDlg::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void DeleteUserDlg::showEvent(QShowEvent *event)
{
    AccountService* getadmindel = new AccountService();
    try
    {
        //Get call
        QJsonDocument document = getadmindel->GetUserList();

        m_jArray = document.array();

        //ComboBox is initialized.
        for(int i = 0;i < m_jArray.count();i++){
            QJsonObject jObj = m_jArray[i].toObject();
            QString strJson(jObj.value("FirstName").toString());
            ui->Deleteuser_comboBox->addItem(strJson);
        }
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}

DeleteUserDlg::~DeleteUserDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name:on_accaddadmin_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/

void DeleteUserDlg::on_Deleteuser_clicked_clicked()
{
    try
       {
       AccountService *deleteadmin = new AccountService();

       QJsonDocument document = deleteadmin->GetAdminList();

       m_jArray = document.array();

   int index=ui->Deleteuser_comboBox->currentIndex();
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


