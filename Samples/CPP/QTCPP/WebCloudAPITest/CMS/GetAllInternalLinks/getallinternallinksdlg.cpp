/*-----------------------------------------------------------------------
   Workfile : getallinternallinksdlg.cpp
   Description : Implementation of getallinternallinksdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "getallinternallinksdlg.h"
#include "ui_getallinternallinksdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include "QListWidget"
#include <QMessageBox>
GetAllInternalLinksDlg::GetAllInternalLinksDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllInternalLinksDlg)
{
    ui->setupUi(this);
}

GetAllInternalLinksDlg::~GetAllInternalLinksDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetAllInternalLinksDlg::showEvent(QShowEvent *event)
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
void GetAllInternalLinksDlg::CreateTableView()
{
    Model = new QStandardItemModel();
    Model->setHorizontalHeaderItem(0,new QStandardItem(tr("Link ID")));
    Model->setHorizontalHeaderItem(1,new QStandardItem(tr("Menu ID")));
    Model->setHorizontalHeaderItem(2,new QStandardItem(tr("Menu Name")));
    Model->setHorizontalHeaderItem(3,new QStandardItem(tr("Link Name")));

    ui->tableView->setModel(Model);
}
/*---------------------------------------------------------------------------
    Function Name: DisplayAllItems
    Return Value: Void
    Remarks:  Function to display all items
---------------------------------------------------------------------------*/
void GetAllInternalLinksDlg::DisplayAllItems()
{
    cmsservice* inlink=new cmsservice();
      try
       {
        QJsonDocument document=inlink->AddInternalLink();
        QJsonObject obj=document.object();
         jArray = obj["linkDetailList"].toArray();
        QString strTitle(obj.value("InternalLinkTitle").toString());
        QCheckBox checkbox;
        ui->labelTitle->setText(strTitle);
        ui->checkBoxShowInternalLinks->setChecked(true);
        //QJsonDocument document1=Footer->AddExistingFooters(QByteArray);

        //jArray = document.array();
        for(int i=0;i<jArray.count();i++)
        {
           QJsonObject jobj=jArray[i].toObject();
            QString strLinkID(jobj.value("LinkID").toString());
            QString strMenuID(jobj.value("MenuID").toString());
            QString strMenuName(jobj.value("MenuName").toString());
            QString strLinkName(jobj.value("LinkName").toString());
            Model->setItem(i,0,new QStandardItem(strLinkID));
            Model->setItem(i,1,new QStandardItem(strMenuID));
            Model->setItem(i,2,new QStandardItem(strMenuName));
            Model->setItem(i,3,new QStandardItem(strLinkName));

        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }
}
void GetAllInternalLinksDlg::on_pushButtonClose_clicked()
{
    this->close();
}

