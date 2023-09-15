/*---------------------------------------------------------------------------
    Workfile:SendEmail.cpp
    Description: . Implementation of Class SendEmail

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last Modtime:  15/06/2022
    Last Revision:
---------------------------------------------------------------------------*/
#include "sendemail.h"
#include "ui_sendemail.h"
#include "Services/commservice.h"
#include <QJsonDocument>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include "mainwindow.h"
#include <QBuffer>

SendEmail::SendEmail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendEmail)
{
    ui->setupUi(this);
}

SendEmail::~SendEmail()
{
    delete ui;
}


/*---------------------------------------------------------------------------
    Function Name: SendEmail::on_btnSendEmailCommSend_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Send Mail button.
---------------------------------------------------------------------------*/
void SendEmail::on_btnSendEmailCommSend_clicked()
{
    QString strFrom, strTo, strCc, strBcc, strSubject, strMessage;

    //Getting data from text fields of email form.
    strFrom = ui->editSendEmailFromComm->text();
    strTo = ui->editSendEmailCommTo->text();
    strCc = ui->editSendEmailCommCc->text();
    strBcc = ui->editSendEmailCommBcc->text();
    strSubject = ui->editSendEmailCommSubject->text();
    strMessage = ui->editSendEmailCommMessage->text();

    //Checking mandatory fields are empty or not.
    if(strTo == ""){
        QMessageBox::warning(this,"Empty To:","Fill To field");
        return;
    }
    if(strSubject == ""){
        QMessageBox::warning(this,"Empty Subject:","Fill Subject field");
        return;
    }
    if(strMessage == ""){
        QMessageBox::StandardButton msgBoxReply = QMessageBox::question(this,"Warning","Sure to leave Message field empty?",QMessageBox::Yes | QMessageBox::No);
        if(msgBoxReply == QMessageBox::No){
            return;
        }
    }

    try
    {
        //serializiation of json.
        QString Data = "{\"To\":\"" + strTo + "\",\"CC\":\"" + strCc + "\",\"BCC\":\"" + strBcc + "\",\"Subject\":\"" + strSubject + "\",\"HtmlMailContent\":\"" + strMessage + "\",\"AdditionalParams\":null,\"AttachmentArray\":[{\"AttachmentBase64\":\"" + m_AttachmentBase64 + "\",\"AttachmentName\":\"" + m_AttachmentName + "\",\"AttachmentType\":\"" + m_AttachmentType + "\"}]}";
        CommService* sendEmailService = new CommService();

        //Calling commservice to make a post request.
        sendEmailService->SendEmail(Data.toUtf8());

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
    Function Name: SendEmail::on_btnSendEmailCommAttach_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Attach(Add) button.
---------------------------------------------------------------------------*/
void SendEmail::on_btnSendEmailCommAttach_clicked()
{
    //Opening file dialog and getting the selected file's path.
    QString filePath = QFileDialog::getOpenFileName(this,"File Dialog","C://");
    QFileInfo file(filePath);

    //Encoding file to base64.
    m_AttachmentBase64 = EncodeToBase64(filePath);

    //Selected file's name.
    m_AttachmentName = file.fileName();

    //Selected fil's extension with preceding "."
    m_AttachmentType = "."+file.suffix();
}


/*---------------------------------------------------------------------------
    Function Name: SendEmail::on_btnSendEmailCommClose_clicked
    Return Value: Void
    Parameters:No parameters.
    Remarks:  Button click event of Close button.
---------------------------------------------------------------------------*/
void SendEmail::on_btnSendEmailCommClose_clicked()
{
    this->close();
}


/*---------------------------------------------------------------------------
    Function Name: SendEmail::showEvent
    Return Value: Void
    Parameters:Pointer to QShowEvent class.
    Remarks:  Initializing dialog.
---------------------------------------------------------------------------*/
void SendEmail::showEvent(QShowEvent *event)
{
    ui->editSendEmailFromComm->setText("admin");
}


/*---------------------------------------------------------------------------
    Function Name: SendEmail::EncodeToBase64
    Return Value: QString
    Parameters:File path(QString).
    Remarks:  This function will return a base64 encoded QString value of a file
              When it's path is given as parameter.
---------------------------------------------------------------------------*/
QString SendEmail::EncodeToBase64(QString path)
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
