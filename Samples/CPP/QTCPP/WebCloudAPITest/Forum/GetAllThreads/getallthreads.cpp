/*********************************************************************
   Workfile : getallthreads.cpp
   Description : Implementation of  getallthreads.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "getallthreads.h"
#include "ui_getallthreads.h"
#include "mainwindow.h"
#include <QDate>
#include <QTime>
/***************************************************************
  Function Name : GetAllThreads
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor  
 **************************************************************/
GetAllThreads::GetAllThreads(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetAllThreads)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllThreads();
}

GetAllThreads::~GetAllThreads()
{
    delete ui;
}

void GetAllThreads::on_Close_Get_All_Thread_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllThreads
  Return Type : void
  Remarks : Function to load all threads 
 **************************************************************/
void GetAllThreads::LoadAllThreads()
{

    QJsonDocument Doc=m_pForumServices->GetAllThreads();
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    ui->Select_Thread_ID->addItem(obj["ThreadID"].toString());
    }
}
/***************************************************************
  Function Name : GetDateFromTicks
  Return Type : QDateTime
  Parameters : ticks 
  Remarks : Function to get date and time from given ticks  
 **************************************************************/
QDateTime GetAllThreads::GetDateFromTicks(qint64 ticks)
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeLast=dateTimefirst.addMSecs(ticks/10000);
    return dateTimeLast;
}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion  
 **************************************************************/
QString GetAllThreads::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}

/***************************************************************
  Function Name : on_Select_Thread_ID_currentTextChanged
  Return Type : void
  Parameters : threadId 
  Remarks : Function to load all details of a thread 
 **************************************************************/
void GetAllThreads::on_Select_Thread_ID_currentTextChanged(const QString &threadId)
{
    if( ui->Select_Thread_ID->currentIndex()==-1)
        return;
    for(int i=0;i<m_JsonArray.size();i++)
    {
        QJsonObject obj=m_JsonArray[i].toObject();
        if(obj["ThreadID"].toString()==threadId)
          {
            ui->Thread_Name->setText(obj["ThreadName"].toString());
            ui->Thread_Description->setText(obj["ThreadDesc"].toString());
            QJsonObject ftrDetails=obj["ftrDetails"].toObject();
            ui->Thread_Details1->setText("BugStatus : "+ftrDetails["BugStatus"].toString());
            ui->Thread_Details2->setText("Assigned Status: "+ftrDetails["ThreadAssigned"].toString());
            QString postDate=ftrDetails["PostedDate"].toString();
            ui->Thread_Details3->setText("Posted On : "+GetDateFromTicks(postDate.toLongLong()).toString("dd.MM.yyyy,h:m:s ap"));
            ui->Thread_Details4->setText("Author ID : "+ftrDetails["AuthorID"].toString());

          }

    }
}

