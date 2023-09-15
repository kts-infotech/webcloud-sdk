/*-----------------------------------------------------------------------
   Workfile : addexternallinkdlg.cpp
   Description : Implementation of addexternallinkdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "addexternallinkdlg.h"
#include "ui_addexternallinkdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "QListWidget"
#include "QMessageBox"

AddExternalLinkDlg::AddExternalLinkDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddExternalLinkDlg)
{
    ui->setupUi(this);
    AddExLink=new cmsservice();
}

AddExternalLinkDlg::~AddExternalLinkDlg()
{
    delete ui;

}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void AddExternalLinkDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
AddOtherSettings();
}
/*--------------------------------------------------------------------------
Function Name : AddOtherSettings
Return Type : void
Remarks : Function to display title and linkname
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::AddOtherSettings()
{
      try
       {
        QJsonDocument document=AddExLink->AddSettings();
        QJsonObject obj=document.object();
         jArray = obj["linkDetailList"].toArray();
        QString strTitle(obj.value("ExternalLinkTitle").toString());
        QCheckBox checkbox;
        ui->lineEditTitle->setText(strTitle);
        ui->checkBoxExternalLink->setChecked(true);
        for(int i=0;i<jArray.count();i++)
        {
           QJsonObject jobj=jArray[i].toObject();
            QString strLinkName(jobj.value("LinkName").toString());
           ui->listWidgetSettings->addItem(strLinkName);

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
void AddExternalLinkDlg::on_pushButtonUpdateTitle_clicked()
{
    QString showLink;
     QString strDefaultTitle=ui->lineEditTitle->text();
     if(ui->checkBoxExternalLink->isChecked())
     {
         showLink="True";
     }
     else
     {
         showLink="False";
     }
      try
       {
        QJsonDocument document=AddExLink->UpdateExternalTitle(strDefaultTitle,showLink);
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
Function Name : on_pushButtonApply_clicked
Return Type : void
Remarks : Function to update the order of items
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_pushButtonApply_clicked()
{
    QJsonDocument document=AddExLink->AddSettings();
    QJsonObject obj=document.object();
    jArray = obj["linkDetailList"].toArray();
    QJsonArray reArray;
    for(int i=0;i<jArray.size();i++)
   {
         QJsonObject jobj=jArray[i].toObject();
         QString strURL(jobj.value("LinkUrl").toString());
         QString strLinkName(jobj.value("LinkName").toString());
         QString strMenuID(jobj.value("MenuID").toString());
         QString strMenuName(jobj.value("MenuName").toString());
         QString strLinkID(jobj.value("LinkID").toString());

         obj["LinkUrl"]=strURL;
         obj["LinkName"]=strLinkName;
         obj["MenuID"]=strMenuID;
         obj["MenuName"]=strMenuName;
         obj["LinkID"]=strLinkID;
         //QString search(strLinkName);
                // QList<QListWidgetItem *> list=ui->listWidgetSettings->findItems(strLinkName,Qt::MatchContains);
                // QListWidgetItem* lst = list[0];
                // qDebug() <<lst;
                // QListWidgetItem item = *lst;
                 //QString lstItem = item.text();
         ui->listWidgetSettings->setCurrentRow(i);
         //int order=ui->listWidgetSettings->currentRow();
         int order=i;
         QString Orderno=QString::number(order);
          qDebug() <<order;
       obj["OrderNo"]=Orderno;
      // obj["iOrderNo"]=order;

        reArray.push_back(obj);
    }
         QJsonDocument doc(reArray);
         MainWindow::SetRequestData(doc);
         QString data=AddExLink->ApplyOrder(doc);
         MainWindow::SetResponseData(data);
         QMessageBox::information(this,"Message","Updated Successfully");
    }
/*--------------------------------------------------------------------------
Function Name : on_pushButtonAdd_clicked
Return Type : void
Remarks : Function to insert new item
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_pushButtonAdd_clicked()
{
    QJsonDocument document=AddExLink->AddSettings();
    QJsonObject obj=document.object();
    jArray = obj["linkDetailList"].toArray();
    int counter=0;
   for(int i=0;i<jArray.size();i++)
   {
        QJsonObject jobj=jArray[i].toObject();
        counter=counter+1;
   }
QString strUrl=ui->lineEditURL->text();
QString strUrlName=ui->lineEditURLName->text();
QString LinkUrl=strUrl;
QString LinkName=strUrlName;
QString MenuID="";
QString MenuName="";
QString LinkID="";
QString strCounter=QString::number(counter);

QString OrderNo=strCounter;
int iOrderNo=counter;

try
{
 QString data="{\"MenuID\":\"" + MenuID + "\",\"MenuName\":\"" + MenuName + "\",\"LinkID\":\"" + LinkID + "\",\"LinkName\":\"" + LinkName + "\",\"LinkUrl\":\"" + LinkUrl + "\",\"OrderNo\":\""+ OrderNo +"\",\"iOrderNo\":\""+ iOrderNo +"\"}";
AddExLink->AddExternalLink(data.toUtf8());

QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
MainWindow::SetRequestData(doc);
}
catch (std::exception& es)
{
MainWindow::SetResponseData(es.what());
}
}

/*--------------------------------------------------------------------------
Function Name : on_pushButtonUpdate_clicked
Return Type : void
Remarks : Function to update item
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_pushButtonUpdate_clicked()
{

     QJsonDocument document=AddExLink->AddSettings();
     QJsonObject obj=document.object();
     jArray = obj["linkDetailList"].toArray();
     QJsonObject jobj=jArray[sel].toObject();
     QString strOrderNo(jobj.value("OrderNo").toString());
     QString strLinkID(jobj.value("LinkID").toString());

    QString LinkUrl = ui->lineEditURL->text();
    QString LinkName = ui->lineEditURLName->text();
     obj["LinkUrl"]=LinkUrl;
     obj["LinkName"]=LinkName;
     obj["OrderNo"]=strOrderNo;
     obj["LinkID"]=strLinkID;
     QJsonDocument doc(obj);
     MainWindow::SetRequestData(doc);
     QString data=AddExLink->UpdateExternalLink(doc);
     MainWindow::SetResponseData(data);
     QMessageBox::information(this,"Message","Updated Successfully");

        }

/*--------------------------------------------------------------------------
Function Name : on_pushButtonRemove_clicked
Return Type : void
Remarks : Function to remove item
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_pushButtonRemove_clicked()
{
    QJsonDocument document=AddExLink->AddSettings();
    QJsonObject obj=document.object();
    jArray = obj["linkDetailList"].toArray();
     QJsonObject jobj=jArray[sel].toObject();
    QString strLinkID(jobj.value("LinkID").toString());

    try
    {
        QJsonDocument document=AddExLink->DeleteExternalLink(strLinkID);
        MainWindow::SetRequestData(document);
        QMessageBox::information(this,"Message","Deleted Successfully");

    }
    catch (std::exception& es)
    {
      MainWindow::SetResponseData(es.what());
     }

}


void AddExternalLinkDlg::on_pushButtonClose_clicked()
{
    this->close();
}

/*--------------------------------------------------------------------------
Function Name : on_listWidgetSettings_currentRowChanged
Return Type : void
Remarks :Event handler for selection change in listwidget.
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_listWidgetSettings_currentRowChanged(int index)
{
    sel1=index;
         QJsonObject jobj=jArray[index].toObject();
            QString strUrl(jobj.value("LinkUrl").toString());
           QString strLinkName(jobj.value("LinkName").toString());

             ui->lineEditURL->setText(strUrl);
            ui->lineEditURLName->setText(strLinkName);

}


/*--------------------------------------------------------------------------
Function Name : on_pushButtonUp_clicked
Return Type : void
Remarks : Function to move the item up in listwidget
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_pushButtonUp_clicked()
{
    sel=ui->listWidgetSettings->currentRow();
    qDebug()<<sel;
    if(sel>0)
    {
        //QListWidgetItem *item=ui->listWidgetSettings->currentItem();

        QListWidgetItem *currentItem = ui->listWidgetSettings->takeItem(sel);
               ui->listWidgetSettings->insertItem(sel-1, currentItem);
               ui->listWidgetSettings->setCurrentRow(sel-1);
    }

}
/*--------------------------------------------------------------------------
Function Name : on_pushButtonDown_clicked
Return Type : void
Remarks : Function to move the item down in listwidget
--------------------------------------------------------------------------*/
void AddExternalLinkDlg::on_pushButtonDown_clicked()
{
     sel=ui->listWidgetSettings->currentRow();
    if(sel>0)
    {
        QListWidgetItem *currentItem = ui->listWidgetSettings->takeItem(sel);
        ui->listWidgetSettings->insertItem(sel+1, currentItem);
        ui->listWidgetSettings->setCurrentRow(sel+1);
    }

}



