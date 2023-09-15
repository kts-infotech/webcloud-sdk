/*********************************************************************
   Workfile : deletethreaddlg.cpp
   Description : Implementation of  deletethreaddlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "deletethreaddlg.h"
#include "ui_deletethreaddlg.h"
#include "mainwindow.h"
#include <QMessageBox>
/***************************************************************
  Function Name : DeleteThreadDlg
  Return Type : int
  Parameters : parent 
  Remarks :  Initializing values in constructor   
 **************************************************************/
DeleteThreadDlg::DeleteThreadDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteThreadDlg)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllThreads();
}

DeleteThreadDlg::~DeleteThreadDlg()
{
    delete ui;
}
/***************************************************************
  Function Name : on_Delete_Delete_Thread_clicked
  Return Type : void
  Remarks : Function to delete a selected thread  
 **************************************************************/
void DeleteThreadDlg::on_Delete_Delete_Thread_clicked()
{
if(ui->Select_Delete_Thread_ID->currentText()=="")
     QMessageBox::information(nullptr,"WebColudAPITest","Please Select A Thread To Delete");
else
     QJsonDocument Doc=m_pForumServices->DeleteThread(m_ThreadId);

}

void DeleteThreadDlg::on_Close_Delete_This_Thread_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllThreads
  Return Type : void
  Remarks : Function to load all threads  
 **************************************************************/
void DeleteThreadDlg::LoadAllThreads()
{
    QJsonDocument Doc=m_pForumServices->GetAllThreads();
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    ui->Select_Delete_Thread_ID->addItem(obj["ThreadID"].toString());
    }
}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks :  Function for QJsonDocument to QString conversion 
 **************************************************************/
QString DeleteThreadDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}
/***************************************************************
  Function Name : GetDateFromTicks
  Return Type : QDateTime
  Parameters : ticks 
  Remarks :  Function to get date and time from ticks
 **************************************************************/
QDateTime  DeleteThreadDlg::GetDateFromTicks(qint64 ticks)
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeLast=dateTimefirst.addMSecs(ticks/10000);
    return dateTimeLast;
}
/***************************************************************
  Function Name : on_Select_Delete_Thread_ID_currentTextChanged
  Return Type : void
  Parameters : threadId 
  Remarks : Function to load all details of a thread  
 **************************************************************/
void DeleteThreadDlg::on_Select_Delete_Thread_ID_currentTextChanged(const QString &threadId)
{
    if(ui->Select_Delete_Thread_ID->currentIndex()==-1)
        return;
    m_ThreadId=threadId;
    for(int i=0;i<m_JsonArray.size();i++)
    {
        QJsonObject obj=m_JsonArray[i].toObject();
        if(obj["ThreadID"].toString()==threadId)
          {
            ui->Select_Thread_Name_Delete->setText(obj["ThreadName"].toString());
            ui->Thread_Delete_Description->setText(obj["ThreadDesc"].toString());
            QJsonObject ftrDetails=obj["ftrDetails"].toObject();
            ui->Thread_Delete1->setText("BugStatus : "+ftrDetails["BugStatus"].toString());
            ui->Thread_Delete2->setText("Assigned Status: "+ftrDetails["ThreadAssigned"].toString());
            QString postDate=ftrDetails["PostedDate"].toString();
            ui->Thread_Delete3->setText("Posted On : "+GetDateFromTicks(postDate.toLongLong()).toString("dd.MM.yyyy,h:m:s ap"));
            ui->Thread_Delete4->setText("Author ID : "+ftrDetails["AuthorID"].toString());

          }

    }
}

