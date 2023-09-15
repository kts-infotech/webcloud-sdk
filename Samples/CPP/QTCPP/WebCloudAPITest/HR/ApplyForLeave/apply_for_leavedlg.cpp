#include "apply_for_leavedlg.h"
#include "ui_apply_for_leavedlg.h"
#include <Services/hrservice.h>
#include "mainwindow.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

Apply_For_LeaveDlg::Apply_For_LeaveDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Apply_For_LeaveDlg)
{
    ui->setupUi(this);
    m_pHrService=new HRService();
    QStringList ListLeaveType={"Sick Leave","Casual Leave","Vacation Leave","Others(Specify)"};
    ui->Typecombo->addItems(ListLeaveType);
}

Apply_For_LeaveDlg::~Apply_For_LeaveDlg()
{
    delete ui;
}

void Apply_For_LeaveDlg::on_btnRequestLeave_clicked()
{
    QString LeaveType = ui->Subject->text();
    QString UserName = MainWindow::GetUserName();
    QString LogType = "LeaveRequest";
    qint64 LogDate = GetTicksNow();

    qint64 fromDateTicks = GetTicksNow1();

    qint64 toDateTicks = GetTicksNow2();

    QString LeaveReason = ui->Reason->text();
    QString LeaveRequestStatus = "Not Yet Reviewed";
    QString LeaveRequestRemarks = "Not Yet Reviewed";
    try {
        QString Data = "{\"LogID\":\"\",\"LeaveType\":\"" + LeaveType + "\",\"UserName\":\"" + UserName + "\",\"LogType\":\"" + LogType + "\",\"LogDate\":\"" + QString::number(LogDate) + "\",\"FromDate\":\"" + QString::number(fromDateTicks) + "\",\"ToDate\":\"" + QString::number(toDateTicks) + "\",\"LeaveReason\":\"" + LeaveReason + "\",\"LeaveRequestStatus\":\"" + LeaveRequestStatus + "\",\"LeaveRequestRemarks\":\"" + LeaveRequestRemarks + "\",\"ErrorInfo\":\"\"}";

        HRService* postLeaveRequest = new HRService();

        //Calling HRService to make a post request.
        postLeaveRequest->PostLeaveRequest(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);

    }
    catch (...) {
        // Handle the exception appropriately
    }
}


void Apply_For_LeaveDlg::on_btnCancel_clicked()
{
    this->close();
}

qint64 Apply_For_LeaveDlg::GetTicksNow()
{
    QDate date(1,1,1);
    qDebug() << "get date ini:" << date;
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeNow=QDateTime::currentDateTime();
    qint64 ticks=dateTimefirst.msecsTo(dateTimeNow);
    return (ticks*10000);

}

qint64 Apply_For_LeaveDlg::GetTicksNow1()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    QTime currentTime = QTime::currentTime();
    QDateTime dateTimeNow(selectedDate, currentTime);
    QDate date(1,1,1);
    qDebug() << "get date ini:" << date;
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    qint64 ticks = dateTimefirst.msecsTo(dateTimeNow);
    return (ticks*10000);
}

qint64 Apply_For_LeaveDlg::GetTicksNow2()
{
    QDate selectedDate = ui->calendarWidget_2->selectedDate();
    QTime currentTime = QTime::currentTime();
    QDateTime dateTimeNow(selectedDate, currentTime);
    QDate date(1,1,1);
    qDebug() << "get date ini:" << date;
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    qint64 ticks = dateTimefirst.msecsTo(dateTimeNow);
    return (ticks*10000);
}


void Apply_For_LeaveDlg::on_Typecombo_activated(int index)
{
    if (ui->Typecombo->currentText() != "Others(Specify)"){
        ui->Subject->setText(ui->Typecombo->currentText());
    }
    else if(ui->Typecombo->currentText() != "")
    {
        ui->Subject->setText("");
    }
}

