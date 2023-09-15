/*---------------------------------------------------------------------------
    $Workfile: SendEmail.h $

    Description: Header file for SendEmail class.

    Copyright (C) 2022 KTS Infotech
    All rights reserved.

    Author: Jayakrishnan P
    Last $Modtime: 15/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/
#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QDialog>

namespace Ui {
class SendEmail;
}

class SendEmail : public QDialog
{
    Q_OBJECT

public:
    explicit SendEmail(QWidget *parent = nullptr);
    ~SendEmail();

private slots:
    void on_btnSendEmailCommSend_clicked();

    void on_btnSendEmailCommAttach_clicked();

    void on_btnSendEmailCommClose_clicked();

private:
    Ui::SendEmail *ui;
    QString m_AttachmentBase64,m_AttachmentName, m_AttachmentType;
    QString EncodeToBase64(QString);
protected:
    void showEvent(QShowEvent* event);
};

#endif // SENDEMAIL_H
