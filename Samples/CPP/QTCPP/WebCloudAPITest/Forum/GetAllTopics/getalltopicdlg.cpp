/*********************************************************************
   Workfile : getalltopicdlg.cpp
   Description : Implementation of  getalltopicdlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "getalltopicdlg.h"
#include "ui_getalltopicdlg.h"
#include "mainwindow.h"
/***************************************************************
  Function Name : GetAllTopicDlg
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor   
 **************************************************************/
GetAllTopicDlg::GetAllTopicDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllTopicDlg)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllTopics();
}

GetAllTopicDlg::~GetAllTopicDlg()
{
    delete ui;
}

void GetAllTopicDlg::on_Close_Get_All_Topic_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllTopics
  Return Type : void
  Remarks : Function to load all topics 
 **************************************************************/
void GetAllTopicDlg::LoadAllTopics()
{
    QJsonDocument Doc=m_pForumServices->GetAllTopics();
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    ui->Select_Topic_ID->addItem(obj["TopicID"].toString());
    }

}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion  
 **************************************************************/
QString GetAllTopicDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}
/***************************************************************
  Function Name : on_Select_Topic_ID_currentTextChanged
  Return Type : void
  Parameters : topicId 
  Remarks : Function to get all details of selected topic 
 **************************************************************/
void GetAllTopicDlg::on_Select_Topic_ID_currentTextChanged(const QString &topicId)
{
    if(ui->Select_Topic_ID->currentIndex()==-1)
        return;
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
        if(obj["TopicID"].toString()==topicId)
          {
            ui->Name_Topic->setText(obj["TopicName"].toString());
            ui->Description_Topic->setText(obj["TopicDesc"].toString());
          }
    }

}

