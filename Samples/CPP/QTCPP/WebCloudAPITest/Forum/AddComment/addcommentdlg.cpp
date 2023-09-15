/*********************************************************************
   Workfile : addcommentdlg.cpp
   Description : Implementation of  addcommentdlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "addcommentdlg.h"
#include "ui_addcommentdlg.h"
#include "mainwindow.h"
/***************************************************************
  Function Name : AddCommentDlg
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor  
 **************************************************************/
AddCommentDlg::AddCommentDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCommentDlg)
{
    ui->setupUi(this);
    m_pMainwindow=(MainWindow *)parent;
    m_pForumServices=new ForumServices();
    LoadAllForums();
}

AddCommentDlg::~AddCommentDlg()
{
    delete ui;
}
/***************************************************************
  Function Name : on_Add_Add_Comment_clicked
  Return Type : void
  Remarks : Function to add a comment 
 **************************************************************/
void AddCommentDlg::on_Add_Add_Comment_clicked()
{
    QString PostedDate = QString::number(GetTicksNow());
    int iThreadId=ui->Select_Thread_ID->currentData().toInt();
    QJsonObject jobject;
    jobject["MsgID"] ="";
    jobject["ThreadID"] =QString::number(iThreadId);
    jobject["Message"]=ui->Add_Comments_2->toPlainText();
    jobject["Author"]=m_pMainwindow->GetUserName();
    jobject["User"]=m_pMainwindow->GetUserName();
    jobject["PostedDate"]=PostedDate;
    jobject["Status"]=false;
    jobject["DeletedBy"]=m_pMainwindow->GetUserName();
    jobject["Success"]=false;
    jobject["ErrorDesc"]="";
    QJsonDocument doc( jobject );
    MainWindow::SetRequestData(doc);
    QJsonDocument Doc=m_pForumServices->AddComments(doc);
    MainWindow::SetResponseData(StringifyJson(Doc));

}
void AddCommentDlg::on_Cancel_Add_Comments_clicked()
{
    this->close();

}
/***************************************************************
  Function Name : LoadAllForums
  Return Type : void
  Remarks : Function to load all forums 
 **************************************************************/
void AddCommentDlg::LoadAllForums()
{
    QJsonDocument Doc=m_pForumServices->GetAllForumIdWithNames();
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    ui->Select_Forum_ID->addItem(obj["Text"].toString(),obj["Value"].toInt());
    }
}
/***************************************************************
  Function Name : GetTicksNow
  Return Type : qint64
  Remarks : function to get ticks from current date and time 
 **************************************************************/
qint64 AddCommentDlg::GetTicksNow()
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeNow=QDateTime::currentDateTime();
    qint64 ticks=dateTimefirst.msecsTo(dateTimeNow);
    return (ticks*10000);

}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks :  Function for QJsonDocument to QString conversion 
 **************************************************************/
QString AddCommentDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}
/***************************************************************
  Function Name : on_Select_Forum_ID_currentTextChanged
  Return Type : void
  Parameters : forum 
  Remarks : Function to load all topics 
 **************************************************************/
void AddCommentDlg::on_Select_Forum_ID_currentTextChanged(const QString &forum)
{
    if(ui->Select_Forum_ID->currentIndex()==-1)
        return;
    ui->Select_Topic_ID->clear();
    ui->Select_Thread_ID->clear();
    ui->Add_Comments_2->clear();
    Q_UNUSED(forum)
    int value = ui->Select_Forum_ID->currentData().toInt();
    QJsonDocument Doc=m_pForumServices->GetAllTopicsWithForumID(QString::number(value));
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
     {
       QJsonObject obj=JsonArray[i].toObject();
       ui->Select_Topic_ID->addItem(obj["Text"].toString(),obj["Value"].toInt());
     }
}

/***************************************************************
  Function Name : on_Select_Topic_ID_currentTextChanged
  Return Type : void
  Parameters : topic 
  Remarks : Function to load all threads 
 **************************************************************/
void AddCommentDlg::on_Select_Topic_ID_currentTextChanged(const QString &topic)
{
    if(ui->Select_Topic_ID->currentIndex()==-1)
        return;
    ui->Select_Thread_ID->clear();
    ui->Add_Comments_2->clear();
    Q_UNUSED(topic)
    int value = ui->Select_Topic_ID->currentData().toInt();
    QJsonDocument Doc=m_pForumServices->GetAllThreadsWithTopicID(QString::number(value));
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    ui->Select_Thread_ID->addItem(obj["Text"].toString(),obj["Value"].toInt());
    }
}

/***************************************************************
  Function Name : on_Select_Thread_ID_currentTextChanged
  Return Type : void
  Parameters : arg1 
  Remarks :  
 **************************************************************/

void AddCommentDlg::on_Select_Thread_ID_currentTextChanged(const QString &arg1)
{
    if(ui->Select_Thread_ID->currentIndex()==-1)
        return;
    ui->Add_Comments_2->clear();
    Q_UNUSED(arg1)
}

