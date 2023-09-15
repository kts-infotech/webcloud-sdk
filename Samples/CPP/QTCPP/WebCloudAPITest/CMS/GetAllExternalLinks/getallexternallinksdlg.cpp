/*-----------------------------------------------------------------------
   Workfile : getallexternallinksdlg.cpp
   Description : Implementation of getallexternallinksdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "getallexternallinksdlg.h"
#include "ui_getallexternallinksdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include "QListWidget"
#include <QMessageBox>

GetAllExternalLinksDlg::GetAllExternalLinksDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllExternalLinksDlg)
{
    ui->setupUi(this);
}

GetAllExternalLinksDlg::~GetAllExternalLinksDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllExternalLinksDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
CreateTableView();
DisplayAllItems();
}
/*---------------------------------------------------------------------------
    Function Name: CreateTableView
    Return Value: Void
    Remarks:  Create GridView
---------------------------------------------------------------------------*/
void GetAllExternalLinksDlg::CreateTableView()
{
    Model = new QStandardItemModel();
    Model->setHorizontalHeaderItem(0,new QStandardItem(tr("Link ID")));
    Model->setHorizontalHeaderItem(1,new QStandardItem(tr("Link URL")));
    Model->setHorizontalHeaderItem(2,new QStandardItem(tr("Link Name")));
    Model->setHorizontalHeaderItem(3,new QStandardItem(tr("Order No")));

    ui->tableView->setModel(Model);
}
/*---------------------------------------------------------------------------
    Function Name: DisplayAllItems
    Return Value: Void
    Remarks:  Function to display all items
---------------------------------------------------------------------------*/
void GetAllExternalLinksDlg::DisplayAllItems()
{
    cmsservice* exlink=new cmsservice();
      try
       {
        QJsonDocument document=exlink->AddSettings();
        QJsonObject obj=document.object();
         jArray = obj["linkDetailList"].toArray();
        QString strTitle(obj.value("ExternalLinkTitle").toString());
        QCheckBox checkbox;
        ui->labelText->setText(strTitle);
        ui->checkBoxExternalLinks->setChecked(true);
        for(int i=0;i<jArray.count();i++)
        {
           QJsonObject jobj=jArray[i].toObject();
           QString strLinkID(jobj.value("LinkID").toString());
           QString strLinkUrl(jobj.value("LinkUrl").toString());
           QString strLinkName(jobj.value("LinkName").toString());
           QString strOrderNo(jobj.value("OrderNo").toString());
           //ui->listWidgetSettings->addItem(strLinkName);
           Model->setItem(i,0,new QStandardItem(strLinkID));
           Model->setItem(i,1,new QStandardItem(strLinkUrl));
           Model->setItem(i,2,new QStandardItem(strLinkName));
           Model->setItem(i,3,new QStandardItem(strOrderNo));
        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
void GetAllExternalLinksDlg::on_pushButtonClose_clicked()
{
    this->close();
}

