/*********************************************************************
   Workfile : deletecommentdlg.cpp
   Description : Implementation of  deletecommentdlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "deletecommentdlg.h"
#include "ui_deletecommentdlg.h"
#include "mainwindow.h"
#include <QMessageBox>
/***************************************************************
  Function Name : DeleteCommentDlg
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor  
 **************************************************************/
DeleteCommentDlg::DeleteCommentDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteCommentDlg)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllForums();
    CommentList();
}

DeleteCommentDlg::~DeleteCommentDlg()
{
    delete ui;
}
/***************************************************************
  Function Name : on_UnSelect_All_Delete_Comment_clicked
  Return Type : void
  Remarks : Function to select all comments  
 **************************************************************/
void DeleteCommentDlg::on_UnSelect_All_Delete_Comment_clicked()
{

    for (int row = 0; row < m_pCommentListTable->rowCount(); ++row)

    {
        QStandardItem* item0 = m_pCommentListTable->item(row,0);
        item0->setCheckState(Qt::Unchecked);
    }
}
/***************************************************************
  Function Name : on_Select_All_Delete_Comment_clicked
  Return Type : void
  Remarks : Function to unselect all comments  
 **************************************************************/
void DeleteCommentDlg::on_Select_All_Delete_Comment_clicked()
{
    for (int row = 0; row < m_pCommentListTable->rowCount(); ++row)

    {
        QStandardItem* item0 = m_pCommentListTable->item(row,0);
        item0->setCheckState(Qt::Checked);
    }
}
/***************************************************************
  Function Name : on_Delete_Selected_Delete_Comment_2_clicked
  Return Type : void
  Remarks : Function to delete a selected message  
 **************************************************************/
void DeleteCommentDlg::on_Delete_Selected_Delete_Comment_2_clicked()
{
    if(ui->Select_Thread_ID->currentText()=="")
         QMessageBox::information(nullptr,"WebColudAPITest","Please Select A Message To Delete");
    else if(ui->Select_Thread_ID->currentText()=="No data available")
         QMessageBox::information(nullptr,"WebColudAPITest","No Messages To Delete");
    else
    {
    QJsonArray msgId ;
    for (int row = 0; row < m_pCommentListTable->rowCount(); ++row)

    {
        QStandardItem* item0 = m_pCommentListTable->item(row,0);
        if(item0->checkState())
        {
            QStandardItem* item1 = m_pCommentListTable->item(row,1);
            msgId.append(item1->data(Qt::DisplayRole).toString());
        }

    }
    QJsonDocument Doc(msgId);
    MainWindow::SetRequestData(Doc);
    QJsonDocument doc=m_pForumServices->DeleteComments(Doc);
    MainWindow::SetResponseData(StringifyJson(doc));
    }
}


void DeleteCommentDlg::on_Cancel_Delete_Comment_2_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllForums
  Return Type : void
  Remarks : Function to load all forums  
 **************************************************************/
void DeleteCommentDlg::LoadAllForums()
{
QJsonDocument Doc=m_pForumServices->GetAllForumIdWithNames();
MainWindow::SetResponseData(StringifyJson(Doc));
m_JsonArray=Doc.array();
for(int i=0;i<m_JsonArray.size();i++)
{
QJsonObject obj=m_JsonArray[i].toObject();
ui->Select_Forum_ID->addItem(obj["Text"].toString(),obj["Value"].toInt());
}
}
/***************************************************************
  Function Name : GetDateFromTicks
  Return Type : QDateTime
  Parameters : ticks 
  Remarks : Function to retrieve the date and time from given ticks 
 **************************************************************/
QDateTime DeleteCommentDlg::GetDateFromTicks(qint64 ticks)
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeLast=dateTimefirst.addMSecs(ticks/10000);
    return dateTimeLast;
}
/***************************************************************
  Function Name : CommentList
  Return Type : void
  Remarks : Function to load all messages 
 **************************************************************/
void DeleteCommentDlg::CommentList()
{
m_pCommentListTable=new QStandardItemModel;
m_pCommentListTable->setHorizontalHeaderItem(0,new QStandardItem(tr("Select")));
m_pCommentListTable->setHorizontalHeaderItem(1,new QStandardItem(tr("MsgID")));
m_pCommentListTable->setHorizontalHeaderItem(2,new QStandardItem(tr("Message")));
m_pCommentListTable->setHorizontalHeaderItem(3,new QStandardItem(tr("Author")));
m_pCommentListTable->setHorizontalHeaderItem(4,new QStandardItem(tr("Posted Date")));
m_pCommentListTable->setHorizontalHeaderItem(5,new QStandardItem(tr("Approval")));
ui->tableView->setModel(m_pCommentListTable);
ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion 
 **************************************************************/
QString DeleteCommentDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}

/***************************************************************
  Function Name : on_Select_Forum_ID_currentTextChanged
  Return Type : void
  Parameters : forumId 
  Remarks : Function to load all topics for a specific forum  
 **************************************************************/
void DeleteCommentDlg::on_Select_Forum_ID_currentTextChanged(const QString &forumId)
{
    if(ui->Select_Forum_ID->currentIndex()==-1)
        return;
    ui->Select_Topic_ID->clear();
    Q_UNUSED(forumId)
    int value = ui->Select_Forum_ID->currentData().toInt();
    QJsonDocument Doc=m_pForumServices->GetAllTopicsWithForumID(QString::number(value));
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    ui->Select_Topic_ID->addItem(obj["Text"].toString(),obj["Value"].toInt());
    }
}
/***************************************************************
  Function Name : on_Select_Topic_ID_currentTextChanged
  Return Type : void
  Parameters : topicId 
  Remarks : Function to load all threads for a specific topic  
 **************************************************************/

void DeleteCommentDlg::on_Select_Topic_ID_currentTextChanged(const QString &topicId)
{

    if(ui->Select_Topic_ID->currentIndex()==-1)
        return;
    ui->Select_Thread_ID->clear();
    Q_UNUSED(topicId)
    int value = ui->Select_Topic_ID->currentData().toInt();
    QJsonDocument Doc=m_pForumServices->GetAllThreadsWithTopicID(QString::number(value));;
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    ui->Select_Thread_ID->addItem(obj["Text"].toString(),obj["Value"].toInt());
    }
}
/***************************************************************
  Function Name : on_Select_Thread_ID_currentTextChanged
  Return Type : void
  Parameters : threadId 
  Remarks : Function to load all messages corresponding to thread selection  
 **************************************************************/

void DeleteCommentDlg::on_Select_Thread_ID_currentTextChanged(const QString &threadId)
{
    Q_UNUSED(threadId)
    if(ui->Select_Topic_ID->currentIndex()==-1)
        return;
    m_pCommentListTable->removeRows( 0, m_pCommentListTable->rowCount() );
    int value = ui->Select_Thread_ID->currentData().toInt();
    QJsonDocument Doc=m_pForumServices->GetMsgsByTrdID(QString::number(value));;
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
    QJsonObject obj=m_JsonArray[i].toObject();
    QString strMsgID(obj.value("MsgID").toString());
    QString strMessage(obj.value("Message").toString());
    QString strAuthor(obj.value("Author").toString());
    QString strPostedDate(obj.value("PostedDate").toString());
    bool Approval(obj.value("Approval").toBool());
    QString strDate=(GetDateFromTicks(strPostedDate.toLongLong())).toString("dd.MM.yyyy,h:m:s ap");
    QString strApprov;
    if(Approval==0)
        strApprov="false";
    else if(Approval==1)
        strApprov="true";
    QStandardItem* item0 = new QStandardItem(true);
    item0->setCheckable(true);
    item0->setCheckState(Qt::Unchecked);

    m_pCommentListTable->setItem(i,0,item0);
    m_pCommentListTable->setItem(i,1,new QStandardItem(strMsgID));
    m_pCommentListTable->setItem(i,2,new QStandardItem(strMessage));
    m_pCommentListTable->setItem(i,3,new QStandardItem(strAuthor));
    m_pCommentListTable->setItem(i,4,new QStandardItem(strDate));
    m_pCommentListTable->setItem(i,5,new QStandardItem(strApprov));
    }

}

