/*-----------------------------------------------------------------------
   Workfile : addinternallinkdlg.cpp
   Description : Implementation of addinternallinkdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "addinternallinkdlg.h"
#include "ui_addinternallinkdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include "QListWidget"
#include "QMessageBox"
#include "QList"

AddInternalLinkDlg::AddInternalLinkDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInternalLinkDlg)
{
    ui->setupUi(this);
    AddInLink=new cmsservice();
}

AddInternalLinkDlg::~AddInternalLinkDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void AddInternalLinkDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
AddMenu();
AddExistingLinks();
}
/*--------------------------------------------------------------------------
Function Name : AddMenu
Return Type : void
Remarks : Function to add menuname
--------------------------------------------------------------------------*/
void AddInternalLinkDlg::AddMenu()
{
      try
       {
        QJsonDocument document=AddInLink->AddListMenu();
        //QJsonDocument document1=Footer->AddExistingFooters(QByteArray);

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
Function Name : AddExistingLinks
Return Type : void
Remarks : Function to add linkname
--------------------------------------------------------------------------*/
void AddInternalLinkDlg::AddExistingLinks()
{
      try
       {
        QJsonDocument document=AddInLink->AddInternalLink();
        QJsonObject obj=document.object();
         jArray = obj["linkDetailList"].toArray();
        QString strTitle(obj.value("InternalLinkTitle").toString());
        QCheckBox checkbox;
        ui->lineEditTitle->setText(strTitle);
        ui->checkBoxInternalLink->setChecked(true);
        for(int i=0;i<jArray.count();i++)
        {
           QJsonObject jobj=jArray[i].toObject();
            QString strLinkName(jobj.value("LinkName").toString());
           ui->listWidgetLinks->addItem(strLinkName);

        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
/*--------------------------------------------------------------------------
Function Name : on_pushButtonUpdateTitle_clicked
Return Type : void
Remarks : Function to update title
--------------------------------------------------------------------------*/
void AddInternalLinkDlg::on_pushButtonUpdateTitle_clicked()
{
    QString showLink;
     QString strDefaultTitle=ui->lineEditTitle->text();
     if(ui->checkBoxInternalLink->isChecked())
     {
         showLink="True";
     }
     else
     {
         showLink="False";
     }
      try
       {
        QJsonDocument document=AddInLink->UpdateTitle(strDefaultTitle,showLink);
        QJsonObject obj=document.object();
        MainWindow::SetRequestData(document);
        QMessageBox::information(this,"Message","Updated Successfully");
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
void AddInternalLinkDlg::on_pushButtonInsert_clicked()
{
 QString strLink=ui->lineEditLinkText->text();
 ui->listWidgetLinks->addItem(strLink);
 QMessageBox::information(this,"Message","Inserted Successfully");
}
/*--------------------------------------------------------------------------
Function Name : on_pushButtonRemove_clicked
Return Type : void
Remarks : Function to remove item
--------------------------------------------------------------------------*/
void AddInternalLinkDlg::on_pushButtonRemove_clicked()
{

 QString strLink=ui->lineEditLinkText->text();
 ui->listWidgetLinks->takeItem(ui->listWidgetLinks->currentRow());
 QMessageBox::information(this,"Message","Deleted Successfully");

}


void AddInternalLinkDlg::on_pushButtonUpdate_clicked()
{
    QString item;
    QListWidget listWidgetLinks;
 QString strLink=ui->lineEditLinkText->text();

}


void AddInternalLinkDlg::on_pushButtonClose_clicked()
{
    this->close();
}

