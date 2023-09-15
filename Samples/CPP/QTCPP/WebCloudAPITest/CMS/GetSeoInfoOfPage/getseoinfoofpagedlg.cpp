/*-----------------------------------------------------------------------
   Workfile : getseoinfoofpagedlg.cpp
   Description : Implementation of getseoinfoofpagedlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "getseoinfoofpagedlg.h"
#include "ui_getseoinfoofpagedlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include "QListWidget"

GetSeoInfoOfPageDlg::GetSeoInfoOfPageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetSeoInfoOfPageDlg)
{
    ui->setupUi(this);
}

GetSeoInfoOfPageDlg::~GetSeoInfoOfPageDlg()
{
    delete ui;
}

void GetSeoInfoOfPageDlg::on_pushButtonClose_clicked()
{
    this->close();
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void GetSeoInfoOfPageDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
cmsservice* getseo=new cmsservice();
try
{
    QJsonDocument document=getseo->GetSeoInfoOfPage();
    jArray = document.array();
    for(int i=0;i<jArray.count();i++)
    {
        QJsonObject jobj=jArray[i].toObject();
        int strMenu(jobj.value("MenuID").toInt());
        QString strMenuID=QString::number(strMenu);

        ui->comboBoxMenuID->addItem(strMenuID);

    }
}
catch (std::exception& es)
{
   MainWindow::SetResponseData(es.what());
}
}
/*---------------------------------------------------------------------------
    Function Name:on_comboBoxMenuID_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void GetSeoInfoOfPageDlg::on_comboBoxMenuID_currentIndexChanged(int index)
{

    if(index != -1)
    {
        QJsonObject elementobj=jArray[index].toObject();
        int strMenu(elementobj.value("MenuID").toInt());
        QString strTitle(elementobj.value("DefaultPageTitle").toString());
        QString strDesc(elementobj.value("DefaultMetaDescription").toString());
        QString strKeywords(elementobj.value("DefaultMetaKeywords").toString());
       bool strAlias(elementobj.value("IsAliasingEnabled").toBool());
        ui->listItem->clear();
        QJsonObject jobj;
       QString strMenuID=QString::number(strMenu);
        ui->listItem->addItem("MenuID : " + strMenuID);
        ui->listItem->addItem("Default Page Title : " + strTitle);
        ui->listItem->addItem("Default Meta Description : " + strDesc);
        ui->listItem->addItem("Default Meta Keywords : " + strKeywords);
        QString strAliasing=QString::number(strAlias);
        if(strAlias==0)
        {
            strAliasing="False";
        }
        else
        {
            strAliasing="True";
        }
        ui->listItem->addItem("Is Aliasing Enabled : " + strAliasing);

    }
}


