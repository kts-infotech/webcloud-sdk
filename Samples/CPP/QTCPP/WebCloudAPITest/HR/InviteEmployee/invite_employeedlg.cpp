#include "invite_employeedlg.h"
#include "ui_invite_employeedlg.h"
#include <QListWidget>
#include  <QMessageBox>
#include <QDebug>

#include <Services/hrservice.h>

#include <mainwindow.h>

Invite_EmployeeDlg::Invite_EmployeeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invite_EmployeeDlg)
{
    ui->setupUi(this);
    QStringList ListEmployeeCategory={"Default","Special","Gold Certified Affiliate","KTS Testing Category"};
    ui->InviteEmployeeCategorycombo->addItems(ListEmployeeCategory);
    QStringList ListEmployeeType={"Full Time","Part Type","Intern | Trainee"};
    ui->InviteEmployeeTypecombo->addItems(ListEmployeeType);
}

Invite_EmployeeDlg::~Invite_EmployeeDlg()
{
    delete ui;
}

void Invite_EmployeeDlg::on_btnInvite_Employee_clicked()
{
    int UserCategory = ui->InviteEmployeeCategorycombo->currentIndex() + 1002;
    int EmployeeType = ui->InviteEmployeeTypecombo->currentIndex() + 1;
    QString UserEmailAddress = ui->InviteEmployee_Email->toPlainText();
    QString UserMessage = ui->InviteEmployee_msg->toPlainText();

    try {
        //serializiation of json.
        QString Data = "{\"UserCategory\":\"" + QString::number(UserCategory) + "\",\"EmployeeType\":\"" + QString::number(EmployeeType) + "\",\"UserEmailAddress\":\"" + UserEmailAddress + "\",\"UserMessage\":\"" + UserMessage + "\" }";
        HRService* inviteemployee = new HRService();

        //Calling AccountService to make a post request.
        inviteemployee->InviteEmployee(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);

    }
    catch (std::exception& es) {
        MainWindow::SetResponseData(es.what());
    }
}



void Invite_EmployeeDlg::on_pushButton_2_clicked()
{
    this->close();
}

