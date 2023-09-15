/*---------------------------------------------------------------------------
    Workfile:PostADefectForm.cpp
    Description: . Implementation of Class PostADefectForm

    Copyright (C) 2022 KTS Computers
    All rights reserved.

    Author: Tom,LAKSHMI V
    Last Modtime:  08/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "postadefectform.h"
#include "ui_postadefectform.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "Services/dtservice.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include "mainwindow.h"
#include <QBuffer>

PostADefectForm::PostADefectForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostADefectForm)
{
    ui->setupUi(this);
    //Adding Values for comboBoxLanguage
    ui->comboBoxLanguage->addItem("English");
    ui->comboBoxLanguage->addItem("OtherLanguage");

}

PostADefectForm::~PostADefectForm()
{
    delete ui;
}
/*---------------------------------------------------------------------------
    Function Name:  PostADefectForm::EncodeToBase64
    Return Value: QString
    Parameters:File path(QString).
    Remarks:  This function will return a base64 encoded QString value of a file
              When it's path is given as parameter.
---------------------------------------------------------------------------*/
QString PostADefectForm::EncodeToBase64(QString path)
{
    try
    {
        QFile sourceFile(path);

        //Checks whether the file is open or not.
        if(!sourceFile.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Error","File is not Open !!");
            return "";
        }
        //Reads the file.
        QByteArray rawData = sourceFile.readAll();

        //Base64 encoding.
        QString base64Encoded = QString::fromUtf8(rawData.toBase64());
        return base64Encoded;

    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
        return "";
    }
}
/*---------------------------------------------------------------------------
    Function Name: PostADefectForm::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Dialog is initialized.
---------------------------------------------------------------------------*/
void PostADefectForm::showEvent(QShowEvent *event)
{
    DTService* PostDefect = new DTService();
    try
    {
         //Get call.
          QJsonDocument document1 =  PostDefect->GetAllTopicsInPost();
          m_jArray1 = document1.array();

        //ComboBox for GetAllTopics i.e.Objectname with comboBox is initialized.
          for(int i = 0;i < m_jArray1.count();i++){
          QJsonObject jObj = m_jArray1[i].toObject();
          TopicID=jObj.value("TopicID").toInt();
          strTopicID=QString::number(TopicID);
          QString TopicName(jObj.value("TopicName").toString());
          ui->comboBox->addItem(TopicName);
          }
          //Get call.
          QJsonDocument document2 =  PostDefect->AssignedToInPost();
          m_jArray2 = document2.array();

          //ComboBox for TaskAssignedTo i.e.Objectname with comboBoxAssignedTo is initialized.
          for(int i = 0;i < m_jArray2.count();i++){
          QJsonObject jObj = m_jArray2[i].toObject();
          QString Name(jObj.value("Name").toString());
          ui->comboBoxAssignedTo->addItem(Name);
          }
    }
    catch (std::exception& es)
     {
        MainWindow::SetResponseData(es.what());
     }
}
/*---------------------------------------------------------------------------
    Function Name:PostADefectForm::on_comboBox_currentIndexChanged
    Return Value: Void
    Parameters: New index of changed combobox selection(int).
    Remarks:  Event handler for selection change in combobox.
---------------------------------------------------------------------------*/
void PostADefectForm::on_comboBox_currentIndexChanged(int index)
{
     //Data is fed to labels from QJsonArray.
    if(index != -1){
        QJsonObject elementObj = m_jArray1[index].toObject();
        QString TopicD(elementObj.value("TopicDescription").toString());
        ui->label_TopicDescription->setText(TopicD);
    }
}
/*---------------------------------------------------------------------------
    Function Name: PostADefectForm::on_pushButton_Browse_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Browse button.
---------------------------------------------------------------------------*/
void PostADefectForm::on_pushButton_Browse_clicked()
{
    //Opening file dialog and getting the selected file's path.
    QString filePath = QFileDialog::getOpenFileName(this,"File Dialog","C://");
    QFileInfo file(filePath);

    //Encoding file to base64.
    AttachmentBase64 = EncodeToBase64(filePath);

    //Selected file's name.
    AttachmentName = file.fileName();

    //Selected fil's extension with preceding "."
    AttachmentType = "."+file.suffix();
    ui->textEditAttachFile->setText(AttachmentName);
}
/*---------------------------------------------------------------------------
    Function Name: PostADefectForm::on_pushButtonPostThread_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of PostThread button.
---------------------------------------------------------------------------*/
void PostADefectForm::on_pushButtonPostThread_clicked()
{

    QString BugTaskTitle,BugTaskDescp,BugAssigned,fileAttachment,FormType,FilePath,BugLanguage,BugAssignedToValue;
    DTService* PostThread = new DTService();
    QJsonDocument document1 = PostThread ->GetAllTopicsInPost();

    BugLanguage=ui->comboBoxLanguage->currentText();
    FilePath=ui->textEditAttachFile->toPlainText();
    BugTaskDescp=ui->textEditThrreadDescription->toPlainText();
    BugAssigned=ui->comboBoxAssignedTo->currentText();
    BugTaskTitle=ui->textEditTitle->toPlainText();

    if(BugTaskTitle == ""){
        QMessageBox::warning(this,"Title!!","Enter Title");
        return;
    }
    try
    {
        //serializiation of json.
        QString Data = "{\"BugTaskTitle\":\"" + BugTaskTitle + "\",\"BugTaskDescption\":\"" + BugTaskDescp + "\",\"fileAttachment\":\"" + AttachmentBase64 + "\",\"FilePath\":\"" + FilePath + "\",\"BugLanguage\":\"" + BugLanguage + "\",\"TopicID\":\""+ strTopicID +"\",\"BugAssignedTo\":\""+ BugAssigned +"\"}";
        DTService* post = new DTService();

        //Calling DTservice to make a post request.
        post->PostADeffectForm(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);
    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}
/*---------------------------------------------------------------------------
    Function Name: PostADefectForm::on_pushButton_Close_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void PostADefectForm::on_pushButton_Close_clicked()
{
    this->close();
}

