/*-----------------------------------------------------------------------
   Workfile : adddelheaderdlg.cpp
   Description : Implementation of adddelheaderdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "adddelheaderdlg.h"
#include "ui_adddelheaderdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include "QListView"
#include <QMessageBox>
AdddelHeaderDlg::AdddelHeaderDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdddelHeaderDlg)
{
    ui->setupUi(this);
    AddDelHdr=new cmsservice();
}

AdddelHeaderDlg::~AdddelHeaderDlg()
{
    delete ui;
}

void AdddelHeaderDlg::on_pushButtonClose_clicked()
{
    this->close();
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void AdddelHeaderDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
AddMenu();
AddExistingHeaders();
}
/*--------------------------------------------------------------------------
Function Name : AddMenu
Return Type : void
Remarks : Function to display menuname
--------------------------------------------------------------------------*/
void AdddelHeaderDlg::AddMenu()
{
      try
       {
        QJsonDocument document=AddDelHdr->AddListMenu();
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
Function Name : AddExistingHeaders
Return Type : void
Remarks : Function to display linkname
--------------------------------------------------------------------------*/
void AdddelHeaderDlg::AddExistingHeaders()
{
      try
       {
        QJsonDocument document=AddDelHdr->AddExistingHeaders();
         QJsonObject obj=document.object();
        jArray = obj["HeaderList"].toArray();
        for(int i=0;i<jArray.count();i++)
        {
            QJsonObject jobj=jArray[i].toObject();
            QString strLinkName(jobj.value("LinkName").toString());
            ui->listWidgetHeader->addItem(strLinkName);

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
void AdddelHeaderDlg::on_pushButtonInsert_clicked()
{
   QString strLinkName = ui->lineEditLink->text();
   QString var=QString::number(strMenu);

    try
     {

       QJsonDocument document=AddDelHdr->AddHeader(strLinkName,var);
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
void AdddelHeaderDlg::on_pushButtonRemove_clicked()
{
      QJsonDocument document=AddDelHdr->AddExistingHeaders();
       QJsonObject obj=document.object();
      jArray = obj["HeaderList"].toArray();

          QJsonObject jobj=jArray[sel].toObject();
          QString strLinkID(jobj.value("LinkID").toString());
    try
    {
        QJsonDocument document=AddDelHdr->DeleteFooter(strLinkID);

         QJsonObject obj=document.object();
        MainWindow::SetRequestData(document);
        QMessageBox::information(this,"Message","Deleted Successfully");
    }
    catch (std::exception& es)
    {
      MainWindow::SetResponseData(es.what());
     }

}


void AdddelHeaderDlg::on_listWidgetMenu_currentRowChanged(int currentRow)
{
    strMenu=currentRow;
}


void AdddelHeaderDlg::on_listWidgetHeader_currentRowChanged(int currentRow)
{
    sel=currentRow;
}

