/*********************************************************************
   Workfile : audforumdlg.cpp
   Description : Implementation of  audforumdlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "audforumdlg.h"
#include "ui_audforumdlg.h"
#include "mainwindow.h"
#include <QListWidget>
#include  <QMessageBox>
#include <QDebug>
/***************************************************************
  Function Name : AUDForumDlg
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor 
 **************************************************************/
AUDForumDlg::AUDForumDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AUDForumDlg)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllForums();
    QStringList ListForumType={"Discussion Forum","Bug Tracking System","Blog"};
    ui->comboBox_Forum_Type->addItems(ListForumType);

}

AUDForumDlg::~AUDForumDlg()
{
    delete ui;
}
/***************************************************************
  Function Name : on_pushButton_Retrive_Email_AUD_clicked
  Return Type : void
  Remarks :  Button click function to retrieve e-mail   
 **************************************************************/
void AUDForumDlg::on_pushButton_Retrive_Email_AUD_clicked()
{

    QString value = ui->comboBox_Select_Group_AUD->currentData().toString();
    QString Response=m_pForumServices->RetrieveEmail(value);
    ui->textEdit_Participant_Email->setText(Response);
}

/***************************************************************
  Function Name : on_Add_AUD_Forum_clicked
  Return Type : void
  Remarks : Function to add and update  forums 
 **************************************************************/
void AUDForumDlg::on_Add_AUD_Forum_clicked()
{
QString strforumType,ForumType;
bool Private=false;
bool AllowAdmins=false;
ForumType=ui->comboBox_Forum_Type->currentText();
if(ForumType=="")
    {
    QMessageBox::information(nullptr,"WebColudAPITest","Please Select A Forum Type");
    return;
    }
else
    {
    if(ForumType=="Discussion Forum")
      {
        strforumType="False";
      }
    else if(ForumType=="Bug Tracking System")
      {
        strforumType="True";
      }
    else if(ForumType=="Blog")
      {
        strforumType="Blog";
      }

     if(ui->checkBox_Private_Forum->checkState()==Qt::Unchecked)
     {
          Private=false;
     }
     else if(ui->checkBox_Private_Forum->checkState()==Qt::Checked)
     {
        Private=true;
     }

    }
    if(ui->checkBox_Allow_New_Thrad->checkState()==Qt::Checked)
    {
        AllowAdmins=true;
    }
    else if(ui->checkBox_Allow_New_Thrad->checkState()==Qt::Unchecked)
    {
        AllowAdmins=false;
    }

    if(ui->lineEdit_Forum_name->text()=="")
    {
        QMessageBox::information(nullptr,"WebColudAPITest","Please Enter A Forum");
        return;
    }
    if(ui->Add_AUD_Forum->text()=="Add")
    {
        QJsonObject jobject;
        jobject["FormID"] ="";
        jobject["FormName"] =ui->lineEdit_Forum_name->text();
        jobject["FormDesc"]=ui->textEdit_Desc_AUD_Forum->toPlainText();
        jobject["GroupEmail"]=ui->textEdit_Participant_Email->toPlainText();
        jobject["ForumType"]=ui->comboBox_Forum_Type->currentText();
        jobject["IsPrivate"]=Private;
        jobject["IsThreadAdminOnly"]=AllowAdmins;
        jobject["Success"]=false;
        jobject["ErrorDesc"]="";
        QJsonDocument doc(jobject);
        MainWindow::SetRequestData(doc);
        QString Data=m_pForumServices->AddForum(doc);
        MainWindow::SetResponseData(Data);

    }
    else if(ui->Add_AUD_Forum->text()=="Update")
    {
        QJsonObject jobject;
        jobject["FormID"] =m_FormId;
        jobject["FormName"] =ui->lineEdit_Forum_name->text();
        jobject["FormDesc"]=ui->textEdit_Desc_AUD_Forum->toPlainText();
        jobject["GroupEmail"]=ui->textEdit_Participant_Email->toPlainText();
        jobject["ForumType"]=ui->comboBox_Forum_Type->currentText();
        jobject["IsPrivate"]=Private;
        jobject["IsThreadAdminOnly"]=AllowAdmins;
        jobject["Success"]=false;
        jobject["ErrorDesc"]="";
        QJsonDocument doc(jobject);
        MainWindow::SetRequestData(doc);
        QString Data=m_pForumServices->UpdateForum(doc);
        MainWindow::SetResponseData(Data);

    }
}

/***************************************************************
  Function Name : on_Delete_AUD_Forum_clicked
  Return Type : void
  Remarks : Function to delete a forum  
 **************************************************************/
void AUDForumDlg::on_Delete_AUD_Forum_clicked()
{
if(ui->lineEdit_Forum_name->text()=="")
    QMessageBox::information(nullptr,"WebColudAPITest","Please Select A Forum To Delete");
else
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "WebColudAPITest", "Do You Want To Delete This Forum?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes)
      {
        QString Response=m_pForumServices->DeleteForum(m_FormId);
        MainWindow::SetResponseData(Response);
        if(Response=="This Forum Contains Topics")
        {
            QMessageBox::StandardButton reply;
              reply = QMessageBox::question(this, "WebColudAPITest", "Do you want to delete all details?",
                                            QMessageBox::Yes|QMessageBox::No);
              if (reply == QMessageBox::Yes)
              {
                  QJsonDocument Doc=m_pForumServices->ForceDeleteForum(m_FormId);
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
void AUDForumDlg::on_Cancel_AUD_Forum_clicked()
{
    this->close();
}
/***************************************************************
  Function Name : LoadAllForums
  Return Type : void
  Remarks : Loading all forums into combobox for selection  
 **************************************************************/
void AUDForumDlg::LoadAllForums()
{
    ui->Delete_AUD_Forum->setDisabled(true);
    QJsonDocument Doc=m_pForumServices->GetAllForums();
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Qt::UserRole,obj);
    item->setText(obj["FormName"].toString());
    ui->listWidget_Existing_forums->addItem(item);
    ui->pushButton_AddNew->setVisible(false);
    }
    QJsonDocument doc=m_pForumServices->GetExistingGroups();
    MainWindow::SetResponseData(StringifyJson(doc));
    QJsonArray jsonArray=doc.array();
    for(int i=0;i<jsonArray.size();i++)
    {
    QJsonObject obj=jsonArray[i].toObject();
    ui->comboBox_Select_Group_AUD->addItem(obj["CategoryName"].toString(),obj["CategoryID"].toString());
    }

}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion 
 **************************************************************/
QString AUDForumDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());

}
/***************************************************************
  Function Name : on_listWidget_Existing_forums_itemClicked
  Return Type : void
  Parameters : item 
  Remarks : Function to load all forum details  
 **************************************************************/
void AUDForumDlg::on_listWidget_Existing_forums_itemClicked(QListWidgetItem *item)
{
  ui->pushButton_AddNew->setVisible(true);
  ui->Delete_AUD_Forum->setDisabled(false);
  ui->Add_AUD_Forum->setText("Update");
  QVariant object= item->data(Qt::UserRole);
  QJsonObject obj=object.toJsonObject();
  m_FormId=obj["FormID"].toString();
  if(obj["ForumType"].toString()=="False")
      ui->comboBox_Forum_Type->setCurrentText("Discussion Forum");
  else if(obj["ForumType"].toString()=="True")
      ui->comboBox_Forum_Type->setCurrentText("Bug Tracking System");
  else if(obj["ForumType"].toString()=="Blog")
      ui->comboBox_Forum_Type->setCurrentText("Blog");
  ui->lineEdit_Forum_name->setText(obj["FormName"].toString());
  if(obj["IsPrivate"]==true)
      ui->checkBox_Private_Forum->setCheckState(Qt::Checked);
  else
      ui->checkBox_Private_Forum->setCheckState(Qt::Unchecked);
  if(obj["IsThreadAdminOnly"]==true)
      ui->checkBox_Allow_New_Thrad->setCheckState(Qt::Checked);
  else
      ui->checkBox_Allow_New_Thrad->setCheckState(Qt::Unchecked);
  ui->textEdit_Desc_AUD_Forum->setText(obj["FormDesc"].toString());
  ui->textEdit_Participant_Email->setText(obj["GroupEmail"].toString());

}
/***************************************************************
  Function Name : on_pushButton_AddNew_clicked
  Return Type : void
  Remarks : Clearing the dialog box values to add new forum 
 **************************************************************/
void AUDForumDlg::on_pushButton_AddNew_clicked()
{

ui->textEdit_Participant_Email->clear();
ui->textEdit_Desc_AUD_Forum->clear();
ui->lineEdit_Forum_name->clear();
ui->pushButton_AddNew->setText("Add");

}

