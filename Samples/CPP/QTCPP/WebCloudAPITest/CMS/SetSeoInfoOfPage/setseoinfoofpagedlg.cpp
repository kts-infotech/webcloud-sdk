/*-----------------------------------------------------------------------
   Workfile : setseoinfoofpagedlg.cpp
   Description : Implementation of setseoinfoofpagedlg.cpp

   Copyright (C) 2022 KTS InfoTech
   All rights reserved

   Author : Chikku Clare Joseph
   Last Modified : 23 June 2022
------------------------------------------------------------------------*/
#include "setseoinfoofpagedlg.h"
#include "ui_setseoinfoofpagedlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include "Services/cmsservice.h"
#include <QMessageBox>
SetSEOInfoOfPageDlg::SetSEOInfoOfPageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSEOInfoOfPageDlg)
{
    ui->setupUi(this);
    SetSeo=new cmsservice();
}

SetSEOInfoOfPageDlg::~SetSEOInfoOfPageDlg()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name: showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::showEvent(QShowEvent *event)
{
Q_UNUSED(event);
DisplayMenu();
DisplayDefaultSettings();
}
/*---------------------------------------------------------------------------
    Function Name: DisplayMenu
    Return Value: Void
    Remarks:  Function to display menuname
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::DisplayMenu()
{
      try
       {
        QJsonDocument document=SetSeo->ListMenuWithID();
        jArray = document.array();
        for(int i=0;i<jArray.count();i++)
        {
            QJsonObject jobj=jArray[i].toObject();
            QString strMenuName(jobj.value("MenuName").toString());
            int strMenu(jobj.value("MenuID").toInt());
            strMenuID=QString::number(strMenu);

          wItem=new QListWidgetItem();
            wItem->setData(Qt::UserRole,strMenuID);
            wItem->setText(strMenuName);
            ui->listWidgetMenu->addItem(wItem);
            //ui->listWidgetMenu->addItem(strMenuName + "(" + strMenuID + ")");
        // selectedMenuID=wItem->data(Qt::UserRole).toString();
        }

      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }
}
/*---------------------------------------------------------------------------
    Function Name: DisplayDefaultSettings
    Return Value: Void
    Remarks:  Function to display items
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::DisplayDefaultSettings()
{

      try
       {
        QJsonDocument document=SetSeo->DefaultSEOSettings();
        QJsonObject obj=document.object();
        QString strPageTitle(obj.value("DefaultPageTitle").toString());
        QString strMetaDesc(obj.value("DefaultMetaDescription").toString());
        QString strMetaKeywords(obj.value("DefaultMetaKeywords").toString());

        ui->textEditTitle->setText(strPageTitle);
        ui->textEditDescription->setText(strMetaDesc);
        ui->textEditKeywords->setText(strMetaKeywords);
        ui->checkBoxAlias->setChecked(true);


      }
        catch (std::exception& es)
        {
          MainWindow::SetResponseData(es.what());
         }

}

void SetSEOInfoOfPageDlg::on_pushButtonClose_clicked()
{
  this->close();
}

/*---------------------------------------------------------------------------
    Function Name: on_pushButtonUpdate_clicked
    Return Value: Void
    Remarks:  Function to update default settings
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::on_pushButtonUpdate_clicked()
{
    QString IsAliasEnabled;
     if(ui->checkBoxAlias->isChecked())
     {
         IsAliasEnabled="True";
     }
     else
     {
         IsAliasEnabled="False";
     }
     QJsonObject obj;
     obj["DefaultPageTitle"]=ui->textEditTitle->toPlainText();
     obj["DefaultMetaDescription"]=ui->textEditDescription->toPlainText();
     obj["DefaultMetaKeywords"]=ui->textEditKeywords->toPlainText();
     obj["IsAliasingEnabled"]=IsAliasEnabled;
     QJsonDocument doc(obj);
    // qDebug()<<doc;
     MainWindow::SetRequestData(doc);

        QString data=SetSeo->UpdateSeoSettings(doc);
        MainWindow::SetResponseData(data);
       QMessageBox::information(this,"Message","Updated Successfully");
      }
/*---------------------------------------------------------------------------
    Function Name: on_pushButtonReset_clicked
    Return Value: Void
    Remarks:  Function to clear default page items
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::on_pushButtonReset_clicked()
{
ui->textEditTitle->clear();
ui->textEditDescription->clear();
ui->textEditKeywords->clear();
ui->checkBoxAlias->setChecked(false);
}

/*---------------------------------------------------------------------------
    Function Name: on_pushButtonSUpdate_clicked
    Return Value: Void
    Remarks:  Function to update single page settings
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::on_pushButtonSUpdate_clicked()
{

   QJsonObject jobj;
    bool UseDefaultSeo=false;


     if(ui->checkBoxDefaultSEO->checkState()==Qt::Checked)
     {
         UseDefaultSeo=true;
     }
     else if(ui->checkBoxDefaultSEO->checkState()==Qt::Unchecked)
     {
         UseDefaultSeo=false;
     }
     bool EnableSharing=false;
      if(ui->checkBoxEnableSocial->checkState()==Qt::Checked)
      {
          EnableSharing=true;
      }
      else if(ui->checkBoxEnableSocial->checkState()==Qt::Unchecked)
      {
          EnableSharing=false;
      }
      bool EnablewhatsappSharing=false;
       if(ui->checkBoxWhatsapp->checkState()==Qt::Checked)
       {
           EnablewhatsappSharing=true;
       }
       else if(ui->checkBoxWhatsapp->checkState()==Qt::Unchecked)
       {
           EnablewhatsappSharing=false;
       }
       bool EnableFB=false;
        if(ui->checkBoxFB->checkState()==Qt::Checked)
        {
            EnableFB=true;
        }
        else if(ui->checkBoxFB->checkState()==Qt::Unchecked)
        {
            EnableFB=false;
        }
        bool EnableFinTip=false;
         if(ui->checkBoxFinTip->checkState()==Qt::Checked)
         {
             EnableFinTip=true;
         }
         else if(ui->checkBoxFinTip->checkState()==Qt::Unchecked)
         {
             EnableFinTip=false;
         }
         bool EnableLinkedin=false;
          if(ui->checkBoxLinkedIn->checkState()==Qt::Checked)
          {
              EnableLinkedin=true;
          }
          else if(ui->checkBoxLinkedIn->checkState()==Qt::Unchecked)
          {
              EnableLinkedin=false;
          }
          bool EnableTwitter=false;
           if(ui->checkBoxTwitter->checkState()==Qt::Checked)
           {
               EnableTwitter=true;
           }
           else if(ui->checkBoxTwitter->checkState()==Qt::Unchecked)
           {
               EnableTwitter=false;
           }

     jobj["MenuID"]=Menu;
     jobj["DefaultPageTitle"]=ui->textEditSTitle->toPlainText();
     jobj["DefaultMetaDescription"]=ui->textEditSDesc->toPlainText();
     jobj["DefaultMetaKeywords"]=ui->textEditSKeywords->toPlainText();
     jobj["UseDefaultSeoDetails"]=UseDefaultSeo;
     jobj["EnableSocialSharing"]=EnableSharing;
     jobj["EnableWhatsAppSharing"]=EnablewhatsappSharing;
     jobj["EnableFbSharing"]=EnableFB;
     jobj["EnableFTOSharing"]=EnableFinTip;
     jobj["EnableGooglePlusSharing"]=EnableLinkedin;
     jobj["EnableTwitterSharing"]=EnableTwitter;
     QJsonDocument doc(jobj);
     MainWindow::SetRequestData(doc);
     QString data=SetSeo->UpdateSeoSettings(doc);
     MainWindow::SetResponseData(data);

     QMessageBox::information(this,"Message",data);
}

/*---------------------------------------------------------------------------
    Function Name: on_pushButtonSReset_clicked
    Return Value: Void
    Remarks:  Function to clear single page settings items
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::on_pushButtonSReset_clicked()
{
    ui->checkBoxDefaultSEO->setChecked(false);
    ui->textEditSTitle->clear();
    ui->textEditSDesc->clear();
    ui->textEditSKeywords->clear();
    ui->checkBoxEnableSocial->setChecked(false);
    ui->checkBoxWhatsapp->setChecked(false);
    ui->checkBoxFB->setChecked(false);
    ui->checkBoxFinTip->setChecked(false);
    ui->checkBoxLinkedIn->setChecked(false);
    ui->checkBoxTwitter->setChecked(false);

}
/*---------------------------------------------------------------------------
    Function Name:on_listWidgetMenu_currentRowChanged
    Return Value: Void
    Remarks:  Event handler for selection change in list widget.
---------------------------------------------------------------------------*/
void SetSEOInfoOfPageDlg::on_listWidgetMenu_currentRowChanged(int currentRow)
{
    const QString& s = ui->listWidgetMenu->currentItem()->text();

          ui->labelSelect->setText(s);


                  QJsonDocument document=SetSeo->GetSeoInfoOfPage();

                    QJsonArray jArray = document.array();
                    for(int i=0;i<jArray.count();i++)
                        {

                       QJsonObject elementobj=jArray[i].toObject();
                       QJsonObject obj=elementobj["SocialSharingSettings"].toObject();

                       int strMenuid(elementobj.value("MenuID").toInt());
                        qDebug()<<"strMenuid:"<<strMenuid;
                         QListWidgetItem *item=ui->listWidgetMenu->currentItem();
                      QString Menuid=item->data(Qt::UserRole).toString();
                      Menu=Menuid.toInt();
                    qDebug()<<"Menu:"<<Menu;
                 if(Menu==strMenuid)
                   {

                       QString strTitle(elementobj.value("DefaultPageTitle").toString());
                        QString strDesc(elementobj.value("DefaultMetaDescription").toString());
                        QString strKeywords(elementobj.value("DefaultMetaKeywords").toString());
                        bool strDefSettings(elementobj.value("UseDefaultSeoDetails").toBool());
                        if(strDefSettings==1)
                        {
                            ui->checkBoxDefaultSEO->setCheckState(Qt::Checked);
                        }
                        else if(strDefSettings==0)
                        {
                            ui->checkBoxDefaultSEO->setCheckState(Qt::Unchecked);
                        }
                         bool strEnableSocial(obj.value("EnableSocialSharing").toBool());
                         if(strEnableSocial==1)
                        {
                             ui->checkBoxEnableSocial->setCheckState(Qt::Checked);
                        }
                       else if(strEnableSocial==0)
                        {
                           ui->checkBoxEnableSocial->setCheckState(Qt::Unchecked);
                       }
                         bool strEnableFb(obj.value("EnableFbSharing").toBool());

                         if(strEnableFb==1)
                        {
                             ui->checkBoxFB->setCheckState(Qt::Checked);
                        }
                       else if(strEnableFb==0)
                        {
                           ui->checkBoxFB->setCheckState(Qt::Unchecked);
                       }
                         bool strEnableWhatsapp(obj.value("EnableWhatsAppSharing").toBool());

                         if(strEnableWhatsapp==1)
                        {
                             ui->checkBoxWhatsapp->setCheckState(Qt::Checked);
                        }
                         else if(strEnableWhatsapp==0)
                        {
                           ui->checkBoxWhatsapp->setCheckState(Qt::Unchecked);
                       }
                         bool strEnableFTO(obj.value("EnableFTOSharing").toBool());

                         if(strEnableFTO==1)
                        {
                             ui->checkBoxFinTip->setCheckState(Qt::Checked);
                        }
                       else if(strEnableFTO==0)
                        {
                           ui->checkBoxFinTip->setCheckState(Qt::Unchecked);
                       }
                         bool strEnableGooglePlus(obj.value("EnableGooglePlusSharing").toBool());

                         if(strEnableGooglePlus==1)
                        {
                             ui->checkBoxLinkedIn->setCheckState(Qt::Checked);
                        }
                       else if(strEnableGooglePlus==0)
                        {
                           ui->checkBoxLinkedIn->setCheckState(Qt::Unchecked);
                       }
                         bool strEnableTwitter(obj.value("EnableTwitterSharing").toBool());

                         if(strEnableTwitter==1)
                        {
                             ui->checkBoxTwitter->setCheckState(Qt::Checked);
                        }
                       else if(strEnableTwitter==0)
                        {
                           ui->checkBoxTwitter->setCheckState(Qt::Unchecked);
                       }
                        ui->textEditSTitle->clear();
                        ui->textEditSDesc->clear();
                        ui->textEditSKeywords->clear();
                        ui->textEditSTitle->setText(strTitle);
                        ui->textEditSDesc->setText(strDesc);
                        ui->textEditSKeywords->setText(strKeywords);
                   }
}
}

