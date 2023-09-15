/*-----------------------------------------------------------------------
   Workfile : adddelfooterdlg.cpp
   Description : Implementation of  adddelfooterdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "adddelfooterdlg.h"
#include "ui_adddelfooterdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include "QListWidget"
#include <QMessageBox>
AdddelFooterDlg::AdddelFooterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdddelFooterDlg)
{
    ui->setupUi(this);
    AddDel=new cmsservice();
}

AdddelFooterDlg::~AdddelFooterDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void AdddelFooterDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
AddMenu();
AddExistingFooters();
}
/*--------------------------------------------------------------------------
Function Name : AddMenu
Return Type : void
Remarks : Function to display menuname
--------------------------------------------------------------------------*/

void AdddelFooterDlg::AddMenu()
{
      try
       {
        QJsonDocument document=AddDel->AddListMenu();

        jArray = document.array();
        for(int i=0;i<jArray.count();i++)
        {
            QJsonObject jobj=jArray[i].toObject();
            QString strMenuName(jobj.value("MenuName").toString());
            ui->listWidgetMenu->addItem(strMenuName);

        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
/*--------------------------------------------------------------------------
Function Name : AddExistingFooters
Return Type : void
Remarks : Function to display linkname
--------------------------------------------------------------------------*/
void AdddelFooterDlg::AddExistingFooters()
{
      try
       {
        QJsonDocument document=AddDel->AddExistingFooters();
         QJsonObject obj=document.object();
        jArray = obj["FooterList"].toArray();
        for(int i=0;i<jArray.count();i++)
        {
            QJsonObject jobj=jArray[i].toObject();
            QString strLinkName(jobj.value("LinkName").toString());
            ui->listWidgetFooters->addItem(strLinkName);

        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
/*--------------------------------------------------------------------------
Function Name : on_pushButtonInsert_clicked
Return Type : void
Remarks : Function to insert item
--------------------------------------------------------------------------*/
void AdddelFooterDlg::on_pushButtonInsert_clicked()
{

   QString strLinkName = ui->lineEditLink->text();
   QString var=QString::number(strMenu);
    try
     {

       QJsonDocument document=AddDel->AddFooter(strLinkName,var);
       QJsonObject obj=document.object();
       MainWindow::SetRequestData(document);
       QMessageBox::information(this,"Message","Inserted Successfully");
     }


  catch (std::exception& es)
  {
    MainWindow::SetResponseData(es.what());
   }

}

/*--------------------------------------------------------------------------
Function Name : on_pushButtonRemove_clicked
Return Type : void
Remarks : Function to remove item
--------------------------------------------------------------------------*/
void AdddelFooterDlg::on_pushButtonRemove_clicked()
{
      QJsonDocument document=AddDel->AddExistingFooters();
       QJsonObject obj=document.object();
      jArray = obj["FooterList"].toArray();
          QJsonObject jobj=jArray[sel].toObject();
           QString strLinkID(jobj.value("LinkID").toString());

    try
    {
        QJsonDocument document=AddDel->DeleteFooter(strLinkID);
        MainWindow::SetRequestData(document);
        QMessageBox::information(this,"Message","Deleted Successfully");

    }
    catch (std::exception& es)
    {
      MainWindow::SetResponseData(es.what());
     }

}
void AdddelFooterDlg::on_listWidgetMenu_currentRowChanged(int index)
{
     strMenu=index;
}


void AdddelFooterDlg::on_listWidgetFooters_currentRowChanged(int index)
{
    sel=index;
}

