/*-----------------------------------------------------------------------
   Workfile : listallpageinfowithlinksdlg.cpp
   Description : Implementation of listallpageinfowithlinksdlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "listallpageinfowithlinksdlg.h"
#include "qlayoutitem.h"
#include "qlistwidget.h"
#include "ui_listallpageinfowithlinksdlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"

ListAllPageInfoWithLinksDlg::ListAllPageInfoWithLinksDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListAllPageInfoWithLinksDlg)
{
    ui->setupUi(this);

}

ListAllPageInfoWithLinksDlg::~ListAllPageInfoWithLinksDlg()
{
    delete ui;
}

void ListAllPageInfoWithLinksDlg::on_pushButtonClose_clicked()
{
    this->close();
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void ListAllPageInfoWithLinksDlg::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
CreateTableView();
DisplayAllItem();

}
/*---------------------------------------------------------------------------
    Function Name: CreateTableView
    Return Value: Void
    Remarks:  Create GridView
---------------------------------------------------------------------------*/
void ListAllPageInfoWithLinksDlg::CreateTableView()
{
    m_pModel = new QStandardItemModel();
    m_pModel->setHorizontalHeaderItem(0,new QStandardItem(tr("Menu ID")));
    m_pModel->setHorizontalHeaderItem(1,new QStandardItem(tr("Parent ID")));
    m_pModel->setHorizontalHeaderItem(2,new QStandardItem(tr("Menu Name")));
    m_pModel->setHorizontalHeaderItem(3,new QStandardItem(tr("Show Menu")));
    m_pModel->setHorizontalHeaderItem(4,new QStandardItem(tr("Menu Link")));
    m_pModel->setHorizontalHeaderItem(5,new QStandardItem(tr("Alias URL Link")));
    m_pModel->setHorizontalHeaderItem(6,new QStandardItem(tr("Page Heading")));
    ui->tableView->setModel(m_pModel);
}
/*---------------------------------------------------------------------------
    Function Name: DisplayAllItem
    Return Value: Void
    Remarks:  Function to display all items
---------------------------------------------------------------------------*/
void ListAllPageInfoWithLinksDlg::DisplayAllItem()
{
    cmsservice* Menu=new cmsservice();
   //QTableView* m_listItems=new QTableView();
      try
       {
        QJsonDocument document=Menu->ListMenuWithID();
        jArray = document.array();
        for(int i=0;i<jArray.count();i++)
        {
            QJsonObject jobj=jArray[i].toObject();
            int strMenu(jobj.value("MenuID").toInt());
            QString strMenuId=QString::number(strMenu);
            int strParentID(jobj.value("ParentID").toInt());
            QString strParent=QString::number(strParentID);
            QString strMenuName(jobj.value("MenuName").toString());
            bool strShowmenu(jobj.value("ShowMenu").toBool());
            QString strShow=QString::number(strShowmenu);
            if(strShowmenu==0)
            {
                strShow="False";
            }
            else
            {
                strShow="True";
            }
            QString strMenuLink(jobj.value("MenuLink").toString());
            QString strAlias(jobj.value("AliasURLLink").toString());
            QString strPageHeading(jobj.value("PageHeading").toString());

m_pModel->setItem(i,0,new QStandardItem(strMenuId));
m_pModel->setItem(i,1,new QStandardItem(strParent));
m_pModel->setItem(i,2,new QStandardItem(strMenuName));
m_pModel->setItem(i,3,new QStandardItem(strShow));
m_pModel->setItem(i,4,new QStandardItem(strMenuLink));
m_pModel->setItem(i,5,new QStandardItem(strAlias));
m_pModel->setItem(i,6,new QStandardItem(strPageHeading));


        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}
