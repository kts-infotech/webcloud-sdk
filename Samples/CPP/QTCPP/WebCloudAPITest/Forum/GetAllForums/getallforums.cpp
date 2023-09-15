/*********************************************************************
   Workfile : getallforums.cpp
   Description : Implementation of  getallforums.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "getallforums.h"
#include "ui_getallforums.h"
#include "mainwindow.h"
/***************************************************************
  Function Name : GetAllForums
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor    
 **************************************************************/
GetAllForums::GetAllForums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllForums)
{
    ui->setupUi(this);

    m_pForumServices=new ForumServices();
    LoadAllForums();
}

GetAllForums::~GetAllForums()
{
    delete ui;
}



void GetAllForums::on_Close_Get_All_Forum_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllForums
  Return Type : void
  Remarks :  Function to load all forums 
 **************************************************************/
void GetAllForums::LoadAllForums()
{
    QJsonDocument Doc=m_pForumServices->GetAllForums();
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    ui->Select_Forum_ID->addItem(obj["FormID"].toString());
    }
}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion 
 **************************************************************/
QString GetAllForums::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}
/***************************************************************
  Function Name : on_Select_Forum_ID_currentTextChanged
  Return Type : void
  Parameters : forumId 
  Remarks : Loading all details of selected forum  
 **************************************************************/
void GetAllForums::on_Select_Forum_ID_currentTextChanged(const QString &forumId)
{
    if( ui->Select_Forum_ID->currentIndex()==-1)
    return;
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
        if(obj["FormID"].toString()==forumId)
          {
            ui->Name_Forum->setText(obj["FormName"].toString());
            ui->Description_Forum->setText(obj["FormDesc"].toString());
          }
    }
}

