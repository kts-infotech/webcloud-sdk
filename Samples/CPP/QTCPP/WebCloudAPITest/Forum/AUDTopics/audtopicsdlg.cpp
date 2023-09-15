/*********************************************************************
   Workfile : audtopicsdlg.cpp
   Description : Implementation of  audtopicsdlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "audtopicsdlg.h"
#include "ui_audtopicsdlg.h"
#include "mainwindow.h"
#include <QListWidget>
#include  <QMessageBox>
#include <QDebug>
/***************************************************************
  Function Name : AUDTopicsDlg
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor  
 **************************************************************/
AUDTopicsDlg::AUDTopicsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AUDTopicsDlg)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllForums();
}

AUDTopicsDlg::~AUDTopicsDlg()
{
    delete ui;
}
/***************************************************************
  Function Name : on_Select_All_AUD_Topics_clicked
  Return Type : void
  Remarks : Function to select all e-mails  
 **************************************************************/
void AUDTopicsDlg::on_Select_All_AUD_Topics_clicked()
{

       for(int i = 0; i <ui->listWidget_Email->count(); ++i)
       {
           QListWidgetItem* item = ui->listWidget_Email->item(i);
           item->setCheckState(Qt::Checked);

       }
}

/***************************************************************
  Function Name : on_UNSelect_AUD_Topic_clicked
  Return Type : void
  Remarks : Function to unselect all e-mails  
 **************************************************************/
void AUDTopicsDlg::on_UNSelect_AUD_Topic_clicked()
{

    for(int i = 0; i <ui->listWidget_Email->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidget_Email->item(i);
        item->setCheckState(Qt::Unchecked);

    }
}

void AUDTopicsDlg::on_Cancel_AUD_Topic_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllForums
  Return Type : void
  Remarks : Function to load all forums  
 **************************************************************/
void AUDTopicsDlg::LoadAllForums()
{
    ui->AddNew_AUD_Topic->setVisible(false);
    ui->pushButton_Delete->setDisabled(true);
    QJsonDocument Doc=m_pForumServices->GetAllForums();
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    ui->comboBox_Forum_Name_Existing->addItem(obj["FormName"].toString(),obj);
    }

}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion 
 **************************************************************/
QString AUDTopicsDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());

}
/***************************************************************
  Function Name : on_comboBox_Forum_Name_Existing_currentTextChanged
  Return Type : void
  Parameters : obj 
  Remarks : Function to load all topics  
 **************************************************************/
void AUDTopicsDlg::on_comboBox_Forum_Name_Existing_currentTextChanged(const QString &obj)
{
    if(ui->comboBox_Forum_Name_Existing->currentIndex()==-1)
        return;
    Q_UNUSED(obj)
    ui->listWidget_Existing_Topics->clear();
    ui->lineEdit_Topic_name_Existing->clear();
    ui->textEdit_Desc_AUD_Topic->clear();
    QVariant object=ui->comboBox_Forum_Name_Existing->currentData();
    QJsonObject Jsonobj=object.toJsonObject();

    QStringList EmailList=(Jsonobj["GroupEmail"].toString()).split(",");
    ui->listWidget_Email->clear();

    for(int i=0;i<EmailList.size();i++)
    {
        QListWidgetItem * itemEmail = new QListWidgetItem(EmailList[i]);
        itemEmail->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        itemEmail->setCheckState(Qt::Unchecked);
        ui->listWidget_Email->addItem(itemEmail);
    }
    m_ForumId=Jsonobj["FormID"].toString();
    QJsonDocument Doc=m_pForumServices->GetAllTopicsWithForumID(Jsonobj["FormID"].toString());
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Qt::UserRole,obj["Value"].toInt());
    item->setText(obj["Text"].toString());
    ui->listWidget_Existing_Topics->addItem(item);
    }

}

/***************************************************************
  Function Name : on_pushButton_Delete_clicked
  Return Type : void
  Remarks :  Function to delete a topic  
 **************************************************************/
void AUDTopicsDlg::on_pushButton_Delete_clicked()
{
    if(ui->lineEdit_Topic_name_Existing->text()=="")
    {
        QMessageBox::information(nullptr,"WebColudAPITest","Please Select A Topic To Delete");
        return;
    }
    else
    {
qDebug()<<QString::number(m_TopicId);
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "WebColudAPITest", "Do You Want To Delete This Topic?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes)
      {
        QString Response=m_pForumServices->DeleteTopic(QString::number(m_TopicId) );
        MainWindow::SetResponseData(Response);
        if(Response=="This Forum Contains Topics")
        {
            QMessageBox::StandardButton reply;
              reply = QMessageBox::question(this, "WebColudAPITest", "Do you want to delete all details?",
                                            QMessageBox::Yes|QMessageBox::No);
              if (reply == QMessageBox::Yes)
              {
                  QJsonDocument Doc=m_pForumServices->ForceDeleteTopic(QString::number(m_TopicId));
                  MainWindow::SetResponseData(StringifyJson(Doc));
              }
              else
              {
                  return;
              }
        }

      }
      else
      {
        return;
      }
}


}

/***************************************************************
  Function Name : on_AddNew_AUD_Topic_clicked
  Return Type : void
  Remarks :  Clearing the dialog box values to add new topic  
 **************************************************************/
void AUDTopicsDlg::on_AddNew_AUD_Topic_clicked()
{
    ui->AddNew_AUD_Topic->setVisible(false);
    ui->lineEdit_Topic_name_Existing->clear();
    ui->textEdit_Desc_AUD_Topic->clear();
    ui->Add_AUD_Topic->setText("Add");
    for(int i = 0; i <ui->listWidget_Email->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidget_Email->item(i);
        item->setCheckState(Qt::Unchecked);

    }
}
/***************************************************************
  Function Name : on_listWidget_Existing_Topics_itemClicked
  Return Type : void
  Parameters : item 
  Remarks : Function to load all details of a topic 
 **************************************************************/

void AUDTopicsDlg::on_listWidget_Existing_Topics_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item)
    ui->AddNew_AUD_Topic->setVisible(true);
    ui->pushButton_Delete->setDisabled(false);
    ui->Add_AUD_Topic->setText("Update");
    ui->lineEdit_Topic_name_Existing->clear();
    ui->textEdit_Desc_AUD_Topic->clear();
    int TopicId= (item->data(Qt::UserRole)).toInt();
    m_TopicId=TopicId;
    QJsonDocument Doc=m_pForumServices->GetAllTopics();
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i = 0; i <ui->listWidget_Email->count(); ++i)
    {
    QListWidgetItem* item = ui->listWidget_Email->item(i);
    item->setCheckState(Qt::Unchecked);
}
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    if(obj["TopicID"].toString()==QString::number(TopicId))
     {
       ui->lineEdit_Topic_name_Existing->setText(obj["TopicName"].toString());
       ui->textEdit_Desc_AUD_Topic->setText(obj["TopicDesc"].toString());
       QStringList EmailList=(obj["GroupEmail"].toString()).split(",");
       for(int i=0;i<EmailList.size();i++)
       {

           QList<QListWidgetItem* >ListMatch=ui->listWidget_Email->findItems(EmailList[i],Qt::MatchExactly);
           if(ListMatch.size()>0)
           {
           QListWidgetItem* item = ListMatch[0];
           item->setCheckState(Qt::Checked);
           }
       }
       if(obj["AdminApproval"].toBool()==true)
       {
            ui->checkBox_Admin->setCheckState(Qt::Checked);
       }
       else
       {
            ui->checkBox_Admin->setCheckState(Qt::Unchecked);
       }

     }
    }
}
/***************************************************************
  Function Name : on_Add_AUD_Topic_clicked
  Return Type : void
  Remarks : Function to add and update topic 
 **************************************************************/
void AUDTopicsDlg::on_Add_AUD_Topic_clicked()
{
 if(ui->lineEdit_Topic_name_Existing->text()=="")
 {
     QMessageBox::information(nullptr,"WebColudAPITest","Please Enter A Topic");
     return;
 }
 else
 {
   bool AdminApproval=false;
   if(ui->checkBox_Admin->checkState()==Qt::Unchecked)
   {
       AdminApproval=false;
   }
   else if(ui->checkBox_Admin->checkState()==Qt::Checked)
   {
        AdminApproval=true;
   }
   QStringList chkdEmails;
   for(int i=0;i<ui->listWidget_Email->count();i++)
   {
       QListWidgetItem* item = ui->listWidget_Email->item(i);
       if(item->checkState()==Qt::Checked)
       {
           chkdEmails.append(item->text());
       }

   }

   if(ui->Add_AUD_Topic->text()=="Add")
   {
       QJsonObject jobject;
       jobject["TopicID"] ="";
       jobject["ForumID"] =m_ForumId;
       jobject["GroupEmail"]=chkdEmails.join(",");
       jobject["TopicName"]=ui->lineEdit_Topic_name_Existing->text();
       jobject["TopicDesc"]=ui->textEdit_Desc_AUD_Topic->toPlainText();
       jobject["AdminApproval"]=AdminApproval;
       jobject["Success"]=false;
       jobject["ErrorDesc"]="";
       QJsonDocument doc(jobject);
       MainWindow::SetRequestData(doc);
       QString Data=m_pForumServices->AddTopics(doc);
       MainWindow::SetResponseData(Data);
   }
   else    if(ui->Add_AUD_Topic->text()=="Update")
   {
       QJsonObject jobject;
       jobject["TopicID"] =m_TopicId;
       jobject["ForumID"] =m_ForumId;
       jobject["GroupEmail"]=chkdEmails.join(",");
       jobject["TopicName"]=ui->lineEdit_Topic_name_Existing->text();
       jobject["TopicDesc"]=ui->textEdit_Desc_AUD_Topic->toPlainText();
       jobject["AdminApproval"]=AdminApproval;
       jobject["Success"]=false;
       jobject["ErrorDesc"]="";
       QJsonDocument doc(jobject);
       MainWindow::SetRequestData(doc);
       QString Data=m_pForumServices->UpdateTopic(doc);
       MainWindow::SetResponseData(Data);
   }
 }
}

