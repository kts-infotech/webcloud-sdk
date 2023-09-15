/*---------------------------------------------------------------------------
    Workfile:GetUserTaskInfo.cpp
    Description: . Implementation of Class GetUserTaskInfo

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom,LAKSHMI V
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getusertaskinfo.h"
#include "ui_getusertaskinfo.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/dtservice.h"

GetUserTaskInfo::GetUserTaskInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetUserTaskInfo)
{
    ui->setupUi(this);
}

GetUserTaskInfo::~GetUserTaskInfo()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: GetUserTaskInfo::on_pushButtonGetInfo_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of GetInfo button.
---------------------------------------------------------------------------*/
void GetUserTaskInfo::on_pushButtonGetInfo_clicked()
{
    DTService* userinfo = new DTService();
    try
    {
          //Get call.
          QJsonDocument document = userinfo ->GetUserTaskInfo();
          QJsonObject obj=document.object();
          QJsonObject Usr= obj.value("UserInfo").toObject();
          QString usrname;
          if(Usr.value(usrname)!=NULL){
          usrname=(Usr.value("usrname").toString());
          ui->label_UserGroup->setText("Usergroup");
          }
          else{
              ui->label_UserGroup->setText("No groups");
          }
          bool Admin=obj.value("IsAdmin").toBool();
          QString StrAdmin;
          if(!Admin){
              ui->label_UserType->setText("Normal User");
          }
          else{
              ui->label_UserType->setText("Admin User");
          }
          QString ErrorReason;
          if(obj.value(ErrorReason)!=NULL)
          {
            ErrorReason=obj.value("ErrorReason").toString();
          }

          QJsonArray Jarry = obj[L"BugTaskDetailsList"].toArray();
          //ComboBox 'comboBoxBugTaskTitle' is initialized.
          for(int i = 0;i < Jarry.count();i++){
          QJsonObject jObj = Jarry[i].toObject();
          QString strBugTaskTitle(jObj.value("BugTaskTitle").toString());
          ui->comboBoxBugTaskTitle->addItem(strBugTaskTitle);
        }
     }
    catch (std::exception& es)
     {
        MainWindow::SetResponseData(es.what());
     }
}
/*---------------------------------------------------------------------------
    Function Name:GetUserTaskInfo::on_comboBoxBugTaskTitle_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetUserTaskInfo::on_comboBoxBugTaskTitle_currentIndexChanged(int index)
{
    //Data is fed to labels from QJsonArray.
    if(index != -1){
        DTService* userinfo = new DTService();
        QJsonDocument document = userinfo ->GetUserTaskInfo();
        QJsonObject obj=document.object();
        QJsonArray Jarry = obj[L"BugTaskDetailsList"].toArray();
        QJsonObject elementObj =Jarry[index].toObject();
        QString BugStatus(elementObj.value("BugStatus").toString());
        QString BugTaskDescription(elementObj.value("BugTaskDescription").toString());
        ui->label_BugStatus->setText(BugStatus);
        ui->textEditBugDescription->setText(BugTaskDescription);
    }
}
/*---------------------------------------------------------------------------
    Function Name: GetUserTaskInfo::on_pushButtonClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetUserTaskInfo::on_pushButtonClose_clicked()
{
    this->close();
}

