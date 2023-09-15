/*---------------------------------------------------------------------------
    Workfile:GetBugTrackerTaskDetailsList.cpp
    Description: . Implementation of Class GetBugTrackerTaskDetailsList

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom,LAKSHMI V
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getbugtrackertaskdetailslist.h"
#include "ui_getbugtrackertaskdetailslist.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/dtservice.h"

GetBugTrackerTaskDetailsList::GetBugTrackerTaskDetailsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetBugTrackerTaskDetailsList)
{
    ui->setupUi(this);
}

GetBugTrackerTaskDetailsList::~GetBugTrackerTaskDetailsList()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: GetBugTrackerTaskDetailsList::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetBugTrackerTaskDetailsList::showEvent(QShowEvent *event)
{
    DTService* BugTracker = new DTService();
    try
    {
         //Get call.
          QJsonDocument document = BugTracker ->GetBugTrackerTaskDetailsist();
          m_jArray = document.array();

        //ComboBox 'comboBoxBugTaskTitle'is initialized.
          for(int i = 0;i < m_jArray.count();i++){
          QJsonObject jObj = m_jArray[i].toObject();
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
    Function Name:GetBugTrackerTaskDetailsList::on_comboBoxBugTaskTitle_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetBugTrackerTaskDetailsList::on_comboBoxBugTaskTitle_currentIndexChanged(int index)
{
    //Data is fed to labels from QJsonArray.
    if(index != -1){
        QJsonObject elementObj = m_jArray[index].toObject();
        QString BugStatus(elementObj.value("BugStatus").toString());
        QString BugTaskDescription(elementObj.value("BugTaskDescription").toString());
        ui->textEditBugStatus->setText(BugStatus);
        ui->textEditBugTaskDescription->setText(BugTaskDescription);
    }
}
/*---------------------------------------------------------------------------
    Function Name: GetBugTrackerTaskDetailsList::on_pushButtonClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetBugTrackerTaskDetailsList::on_pushButtonClose_clicked()
{
    this->close();
}

