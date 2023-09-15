/*---------------------------------------------------------------------------
    Workfile:GetAllBugList.cpp
    Description: . Implementation of Class GetAllBugList

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom,LAKSHMI V
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "getallbuglist.h"
#include "ui_getallbuglist.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/dtservice.h"

GetAllBugList::GetAllBugList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllBugList)
{
    ui->setupUi(this);
}
GetAllBugList::~GetAllBugList()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: GetAllBugList::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllBugList::showEvent(QShowEvent *event)
{
    DTService* AllBugList = new DTService();
    try
    {
         //Get call.
          QJsonDocument document = AllBugList->GetAllBugList();
          m_jArray = document.array();

        //ComboBox with objectname comboBoxTaskTitle is initialized.
          for(int i = 0;i < m_jArray.count();i++){
          QJsonObject jObj = m_jArray[i].toObject();
          QString strBugTaskTitle(jObj.value("BugTaskTitle").toString());
          ui->comboBoxTaskTitle->addItem(strBugTaskTitle);
         }
     }
    catch (std::exception& es)
     {
        MainWindow::SetResponseData(es.what());
     }
}
/*---------------------------------------------------------------------------
    Function Name:GetAllBugList::on_comboBoxTaskTitle_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetAllBugList::on_comboBoxTaskTitle_currentIndexChanged(int index)
{
    //Data is fed to labels from QJsonArray.
    if(index != -1){
        QJsonObject elementObj = m_jArray[index].toObject();
        QString BugStatus;
        if(elementObj.value("BugStatus")!=NULL)
        {
           BugStatus=elementObj.value("BugStatus").toString();
        }
        QString BugTaskDescription(elementObj.value("BugTaskDescription").toString());
        ui->label_BugStatus->setText(BugStatus);
        ui->textEditBugDescription->setText(BugTaskDescription);
    }
}
/*---------------------------------------------------------------------------
    Function Name: GetAllBugList::on_pushButtonClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void GetAllBugList::on_pushButtonClose_clicked()
{
    this->close();
}

