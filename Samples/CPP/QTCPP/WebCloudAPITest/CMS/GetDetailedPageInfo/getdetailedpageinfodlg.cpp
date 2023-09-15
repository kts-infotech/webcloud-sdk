/*-----------------------------------------------------------------------
   Workfile : getdetailedpageinfodlg.cpp
   Description : Implementation of getdetailedpageinfodlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "getdetailedpageinfodlg.h"
#include "ui_getdetailedpageinfodlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"


GetDetailedPageInfoDlg::GetDetailedPageInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetDetailedPageInfoDlg)
{
    ui->setupUi(this);
}

GetDetailedPageInfoDlg::~GetDetailedPageInfoDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetDetailedPageInfoDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
AddMenuWithID();
}
void GetDetailedPageInfoDlg::on_pushButtonClose_clicked()
{
    this->close();
}
/*---------------------------------------------------------------------------
    Function Name: AddMenuWithID
    Return Value: Void
    Remarks:  Function to display menuname with id
---------------------------------------------------------------------------*/
void GetDetailedPageInfoDlg::AddMenuWithID()
{
    cmsservice* Menu=new cmsservice();
      try
       {
        QJsonDocument document=Menu->ListMenuWithID();
        jArray = document.array();
        for(int i=0;i<jArray.count();i++)
        {
            QJsonObject jobj=jArray[i].toObject();
            QString strMenuName(jobj.value("MenuName").toString());
            int strMenu(jobj.value("MenuID").toInt());
            QString strMenuID=QString::number(strMenu);
            ui->listWidgetMenu->addItem(strMenuName + "(" + strMenuID + ")");

        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}

/*---------------------------------------------------------------------------
    Function Name:on_listWidgetMenu_currentRowChanged
    Return Value: Void
    Parameters: New index of changed listwidget selection(int).
    Remarks:  Event handler for selection change in listwidget.
---------------------------------------------------------------------------*/
void GetDetailedPageInfoDlg::on_listWidgetMenu_currentRowChanged(int index)
{
    if(index != -1)
    {
         //QJsonDocument document=Menu->ListMenuWithID();
        QJsonObject elementobj=jArray[index].toObject();
        int strMenu(elementobj.value("MenuID").toInt());
        QString strMenuId=QString::number(strMenu);
        QString strMenuName(elementobj.value("MenuName").toString());
        QString strMenuLink(elementobj.value("MenuLink").toString());
        int strParentID(elementobj.value("ParentID").toInt());
        QString strParent=QString::number(strParentID);
         QString strPage(elementobj.value("PageHeading").toString());
        bool strShowmenu(elementobj.value("ShowMenu").toBool());
        QString strShow=QString::number(strShowmenu);
        if(strShowmenu==0)
        {
            strShow="False";
        }
        else
        {
            strShow="True";
        }
        bool strSuccess(elementobj.value("Success").toBool());
        QString Success=QString::number(strSuccess);
        if(strSuccess==0)
        {
            Success="False";
        }
        else
        {
            Success="True";
        }
         QString strError(elementobj.value("ErrorDesc").toString());

         ui->listWidgetDetails->clear();
        // QJsonObject jobj;
        ui->listWidgetDetails->addItem("MenuID : " + strMenuId);
        ui->listWidgetDetails->addItem("Menu Name : " + strMenuName);
        ui->listWidgetDetails->addItem("Menu Link : " + strMenuLink);
        ui->listWidgetDetails->addItem("Parent ID : " + strParent);
        ui->listWidgetDetails->addItem("Page Heading : " + strPage);
        ui->listWidgetDetails->addItem("Show Menu : " + strShow);
        ui->listWidgetDetails->addItem("Success : " + Success);
        ui->listWidgetDetails->addItem("Error Desc : " + strError);
        ui->listWidgetDesc->clear();
        ui->listWidgetDesc->addItem(strPage);


    }
}

