/*********************************************************************
   Workfile : authreaddlg.cpp
   Description : Implementation of  authreaddlg.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "authreaddlg.h"
#include "ui_authreaddlg.h"
#include "mainwindow.h"
#include <QListWidget>
#include <QMessageBox>
#include <QDebug>
#include <QBuffer>
#include <QFileDialog>
/***************************************************************
  Function Name : AUThreadDlg
  Return Type : int
  Parameters : parent 
  Remarks : Initializing values in constructor  
 **************************************************************/

AUThreadDlg::AUThreadDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AUThreadDlg)
{
    ui->setupUi(this);
    m_pForumServices=new ForumServices();
    LoadAllForums();
}

AUThreadDlg::~AUThreadDlg()
{
    delete ui;
}

/***************************************************************
  Function Name : on_Upload_Image_pushButton_clicked
  Return Type : void
  Remarks : Function to upload an image 
 **************************************************************/

void AUThreadDlg::on_Upload_Image_pushButton_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
   ui->Upload_Image_lineEdit->setText(fileName);
   m_ImageName=fileName;
   if(fileName=="")
        {
       return;
       m_ImageName="";
        }
   if(m_Imageupload.load(fileName))
   {
       ui->label_Picture->setPixmap(QPixmap::fromImage(m_Imageupload));
       ui->label_Picture->setScaledContents(true);
   }

}
/***************************************************************
  Function Name : on_Add_AU_clicked
  Return Type : void
  Remarks : Function to add and update thread 
 **************************************************************/

void AUThreadDlg::on_Add_AU_clicked()
{
if(ui->comboBox_Existing_Forum->currentText()=="" ||ui->Existing_Topic_Name->currentText()=="")
{
    QMessageBox::information(nullptr,"WebColudAPITest","Please Select A Forum And Topic");
    return;
}
if(ui->Thread_Name_AU->text()=="")
{
   QMessageBox::information(nullptr,"WebColudAPITest","Please Enter Thread Name");
   return ;
}
else
{
    if(ui->Add_AU->text()=="Add")
    {
        QJsonObject ftrDetails;
        ftrDetails["BugStatus"] ="None";
        ftrDetails["ThreadAssigned"] ="";
        ftrDetails["PostedDate"] =GetTicksNow();
        ftrDetails["AuthorID"] ="";
        ftrDetails["ThreadImagePth"] =QJsonValue(QJsonValue::Null);
        int TopicId=ui->Existing_Topic_Name->currentData().toInt();
        int ForumId=ui->comboBox_Existing_Forum->currentData().toInt();
        QJsonObject ItemInfo;
        ItemInfo["Text"] = ui->comboBox_Existing_Forum->currentText();
        ItemInfo["Value"] =ForumId;
        QJsonObject ItemInfo1;
        ItemInfo1["Text"] = ui->Existing_Topic_Name->currentText();
        ItemInfo1["Value"] =TopicId;
        QJsonObject ThreadDetailsInfo;
        ThreadDetailsInfo["ftrDetails"]=ftrDetails;
        ThreadDetailsInfo["ForumInfo"]=ItemInfo;
        ThreadDetailsInfo["TopicInfo"]=ItemInfo1;
        ThreadDetailsInfo["ThreadID"]="";
        ThreadDetailsInfo["ThreadName"]=ui->Thread_Name_AU->text() ;
        ThreadDetailsInfo["UserName"]= MainWindow::GetUserName() ;
        ThreadDetailsInfo["ThreadDesc"]=ui->Thread_Description_AU->toPlainText();
        ThreadDetailsInfo["ThreadImage"]=GetBase64BitImage();
        ThreadDetailsInfo["ImageName"]=m_ImageName;
        ThreadDetailsInfo["Success"]=false;
        ThreadDetailsInfo["ErrorDesc"]="";
        QJsonDocument doc( ThreadDetailsInfo );
        MainWindow::SetRequestData(doc);
        QString data=m_pForumServices->AddThread(doc);
        MainWindow::SetResponseData(data);
    }
    else if(ui->Add_AU->text()=="Update")
    {
        QJsonObject ftrDetails;
        ftrDetails["BugStatus"] ="None";
        ftrDetails["ThreadAssigned"] ="";
        ftrDetails["PostedDate"] ="";
        ftrDetails["AuthorID"] ="";
        ftrDetails["ThreadImagePth"] =QJsonValue(QJsonValue::Null);
        int TopicId=ui->Existing_Topic_Name->currentData().toInt();
        int ForumId=ui->comboBox_Existing_Forum->currentData().toInt();
        QJsonObject ItemInfo;
        ItemInfo["Text"] = ui->comboBox_Existing_Forum->currentText();
        ItemInfo["Value"] =ForumId;
        QJsonObject ItemInfo1;
        ItemInfo1["Text"] = ui->Existing_Topic_Name->currentText();
        ItemInfo1["Value"] =TopicId;
        QJsonObject ThreadDetailsInfo;
        ThreadDetailsInfo["ftrDetails"]=ftrDetails;
        ThreadDetailsInfo["ForumInfo"]=ItemInfo;
        ThreadDetailsInfo["TopicInfo"]=ItemInfo1;
        ThreadDetailsInfo["ThreadID"]=m_ThreadId;
        ThreadDetailsInfo["ThreadName"]=ui->Thread_Name_AU->text() ;
        ThreadDetailsInfo["UserName"]= MainWindow::GetUserName() ;
        ThreadDetailsInfo["ThreadDesc"]=ui->Thread_Description_AU->toPlainText();
        if((ui->Upload_Image_Check_Box->isChecked()) && (ui->Upload_Image_lineEdit->text())!="")
        {
            ThreadDetailsInfo["ThreadImage"]=GetBase64BitImage();
            ThreadDetailsInfo["ImageName"]=m_ImageName;
        }
        else
        {

            ThreadDetailsInfo["ThreadImage"]="";
            ThreadDetailsInfo["ImageName"]="";

        }

        ThreadDetailsInfo["Success"]=false;
        ThreadDetailsInfo["ErrorDesc"]="";
        QJsonDocument doc( ThreadDetailsInfo );
        MainWindow::SetRequestData(doc);
        QString data=m_pForumServices->UpdateThread(doc);
        MainWindow::SetResponseData(data);
    }
}

}
/***************************************************************
  Function Name : GetBase64BitImage
  Return Type : QString
  Remarks : Function to convert image to base64 format 
 **************************************************************/
QString AUThreadDlg::GetBase64BitImage()
{
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    m_Imageupload.save(&buffer,"PNG");
    QString const encoded = buffer.data().toBase64();
    return encoded;
}

void AUThreadDlg::on_Cancel_AU_clicked()
{
    this->close();
}

/***************************************************************
  Function Name : on_pushButton_AddNew_clicked
  Return Type : void
  Remarks : Clearing the dialog box values to add new thread 
 **************************************************************/
void AUThreadDlg::on_pushButton_AddNew_clicked()
{
    ui->pushButton_AddNew->setVisible(false);
    ui->Thread_Name_AU->clear();
    ui->Thread_Description_AU->clear();
    ui->Add_AU->setText("Add");
    ui->Upload_Image_lineEdit->clear();
    ui->Upload_Image_Check_Box->setText("Upload Image");
    ui->Upload_Image_Check_Box->setCheckState(Qt::Unchecked);
    ui->label_Picture->clear();
    ui->Upload_Image_lineEdit->clear();
}
/***************************************************************
  Function Name : LoadAllForums
  Return Type : void
  Remarks : Function to load all forums 
 **************************************************************/
void AUThreadDlg::LoadAllForums()
{
    ui->pushButton_AddNew->setVisible(false);
    QJsonDocument Doc=m_pForumServices->GetAllForums();
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
    {
    QJsonObject obj=JsonArray[i].toObject();
    ui->comboBox_Existing_Forum->addItem(obj["FormName"].toString(),obj["FormID"].toString());
    }
}
/***************************************************************
  Function Name : StringifyJson
  Return Type : QString
  Parameters : jsonDoc 
  Remarks : Function for QJsonDocument to QString conversion 
 **************************************************************/
QString AUThreadDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}
/***************************************************************
  Function Name : on_comboBox_Existing_Forum_currentTextChanged
  Return Type : void
  Parameters : forumName 
  Remarks : Function to load all topics of selected forum 
 **************************************************************/
void AUThreadDlg::on_comboBox_Existing_Forum_currentTextChanged(const QString &forumName)
{
    Q_UNUSED(forumName)
    if(ui->comboBox_Existing_Forum->currentIndex()==-1)
        return;
    ui->listWidget_Existing_Threads->clear();
    ui->Thread_Name_AU->clear();
    ui->Existing_Topic_Name->clear();
    ui->Thread_Description_AU->clear();
    ui->Upload_Image_Check_Box->setCheckState(Qt::Unchecked);
    ui->Upload_Image_lineEdit->clear();
    QString value = ui->comboBox_Existing_Forum->currentData().toString();
    m_ForumId=value;
    QJsonDocument Doc=m_pForumServices->GetAllTopicsWithForumID(value);
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonArray JsonArray=Doc.array();
    for(int i=0;i<JsonArray.size();i++)
     {
       QJsonObject obj=JsonArray[i].toObject();
       ui->Existing_Topic_Name->addItem(obj["Text"].toString(),obj["Value"].toInt());
     }
}

/***************************************************************
  Function Name : on_Existing_Topic_Name_currentTextChanged
  Return Type : void
  Parameters : TopicName 
  Remarks :  Function to load all threads of selected topic
 **************************************************************/
void AUThreadDlg::on_Existing_Topic_Name_currentTextChanged(const QString &TopicName)
{
     Q_UNUSED(TopicName)
     if(ui->Existing_Topic_Name->currentIndex()==-1)
            return;
     ui->listWidget_Existing_Threads->clear();
     ui->Thread_Name_AU->clear();
     ui->Thread_Description_AU->clear();
     ui->Upload_Image_Check_Box->setCheckState(Qt::Unchecked);
     ui->Upload_Image_lineEdit->clear();
     int value = ui->Existing_Topic_Name->currentData().toInt();
     m_TopicId=QString::number(value);
     QJsonDocument Doc=m_pForumServices->GetAllThreadsWithTopicID(m_TopicId);
     MainWindow::SetResponseData(StringifyJson(Doc));
     QJsonArray JsonArray=Doc.array();
 for(int i=0;i<JsonArray.size();i++)
  {
    QJsonObject obj=JsonArray[i].toObject();
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Qt::UserRole,obj);
    item->setText(obj["Text"].toString());
    ui->listWidget_Existing_Threads->addItem(item);
 }

}
/***************************************************************
  Function Name : on_listWidget_Existing_Threads_itemClicked
  Return Type : void
  Parameters : item 
  Remarks : Function to load all details of seleted thread 
 **************************************************************/
void AUThreadDlg::on_listWidget_Existing_Threads_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item)
    ui->Upload_Image_Check_Box->setText("Update Image");
    ui->pushButton_AddNew->setVisible(true);
    ui->Add_AU->setText("Update");
    ui->Upload_Image_Check_Box->setCheckState(Qt::Unchecked);
    ui->Upload_Image_lineEdit->clear();
    QVariant object= item->data(Qt::UserRole);
    QJsonObject obj=object.toJsonObject();
    m_ThreadId=QString::number(obj["Value"].toInt());
    QJsonDocument Doc=m_pForumServices->GetThreadByID(m_ThreadId);
    MainWindow::SetResponseData(StringifyJson(Doc));
    QJsonObject Jsonobj=Doc.object();

    m_ImgExisting = Jsonobj["ThreadImage"];
    QString ImgDisp = Jsonobj["ThreadImage"].toString();
    QByteArray byte = QByteArray::fromBase64(ImgDisp.toLatin1());
    QImage img(QImage::fromData(byte));

    //m_Imageupload.loadFromData(byte);
    //ui->label_Picture->setPixmap(QPixmap::fromImage(m_Imageupload));

    ui->label_Picture->setPixmap(QPixmap::fromImage(img));
    ui->label_Picture->setScaledContents(true);
    m_ImageNameExisting=Jsonobj["ImageName"].toString();
    ui->Thread_Name_AU->setText(Jsonobj["ThreadName"].toString());
    ui->Thread_Description_AU->setText(Jsonobj["ThreadDesc"].toString());
}
/***************************************************************
  Function Name : GetTicksNow
  Return Type : qint64
  Remarks : Function to get ticks of current date and time 
 **************************************************************/
qint64 AUThreadDlg::GetTicksNow()
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeNow=QDateTime::currentDateTime();
    qint64 ticks=dateTimefirst.msecsTo(dateTimeNow);
    return (ticks*10000);

}
/***************************************************************
  Function Name : on_Upload_Image_Check_Box_stateChanged
  Return Type : void
  Parameters : state 
  Remarks : Function to enable imageupload button 
 **************************************************************/
void AUThreadDlg::on_Upload_Image_Check_Box_stateChanged(int state)
{
    ui->Upload_Image_pushButton->setEnabled(state);
}

