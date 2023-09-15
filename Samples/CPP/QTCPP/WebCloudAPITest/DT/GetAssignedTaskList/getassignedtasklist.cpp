/*---------------------------------------------------------------------------
    Workfile:GetAssignedTaskList.cpp
    Description: . Implementation of Class GetAssignedTaskList

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom,LAKSHMI V
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/

#include "getassignedtasklist.h"
#include "ui_getassignedtasklist.h"
#include "mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/dtservice.h"

GetAssignedTaskList::GetAssignedTaskList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAssignedTaskList)

{
    ui->setupUi(this);
}

GetAssignedTaskList::~GetAssignedTaskList()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: GetAssignedTaskList::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAssignedTaskList::showEvent(QShowEvent *event)
{

   DTService* getassignedTask = new DTService();
   try
   {
        //Get call.

         QJsonDocument document = getassignedTask->GetAssignedTaskList();
         m_jArray = document.array();

       //ComboBox with objectname comboBoxTaskID is initialized.
         for(int i = 0;i < m_jArray.count();i++){
         QJsonObject jObj = m_jArray[i].toObject();
         int TaskID=jObj.value("TaskID").toInt();
         QString tskId = QString::number(TaskID);
         ui->comboBoxTaskID->addItem(tskId);
        }
    }
   catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}
/*---------------------------------------------------------------------------
    Function Name:GetAssignedTaskList::on_comboBoxTaskID_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetAssignedTaskList::on_comboBoxTaskID_currentIndexChanged(int index)
{
    //Data is fed to labels from QJsonArray.
    if(index != -1){
        QJsonObject elementObj = m_jArray[index].toObject();
        QString TaskTitle(elementObj.value("TaskTitle").toString());
        QString TaskDescription(elementObj.value("TaskDescription").toString());
        ui->textEditTaskTitle->setText(TaskTitle);
        ui->textEditTaskDescription->setText(TaskDescription);
    }
}
/*---------------------------------------------------------------------------
    Function Name: GetAssignedTaskList::on_pushButtonClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAssignedTaskList::on_pushButtonClose_clicked()
{
    this->close();
}

