#include "approve_reject_leavedlg.h"
#include "ui_approve_reject_leavedlg.h"
#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QStringListModel>
#include <QTableWidgetItem>
#include <qstringview.h>
#include <QStandardItemModel>
#include <QDate>
#include <QTime>

Approve_Reject_LeaveDlg::Approve_Reject_LeaveDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Approve_Reject_LeaveDlg)
{
    ui->setupUi(this);
    m_pHRService=new HRService();
    LoadAllLeaveApplications();
}

void Approve_Reject_LeaveDlg::LoadAllLeaveApplications()
{

    QJsonDocument Doc=m_pHRService->GetAllLeaveApplications();
    MainWindow::SetResponseData(StringifyJson(Doc));
    m_JsonArray=Doc.array();
    for(int i=0;i<m_JsonArray.size();i++)
    {
        QJsonObject obj=m_JsonArray[i].toObject();
        ui->LeaveRequestcombo->addItem(obj["Username"].toString());
    }
}

QString Approve_Reject_LeaveDlg::StringifyJson(QJsonDocument jsonDoc)
{
    QByteArray data = jsonDoc.toJson();
    return QString::fromStdString(data.toStdString());
}

Approve_Reject_LeaveDlg::~Approve_Reject_LeaveDlg()
{
    delete ui;

}

void Approve_Reject_LeaveDlg::on_pushButton_2_clicked()
{
    QString id = LogID;
    QString remark = ui->remarks->toPlainText();
    QString Status = "Approved";

    try {
        //serializiation of json.
        QString Data = "{\"LogID\":\"" + id + "\",\"LeaveRequestRemarks\":\"" + remark + "\",\"LeaveRequestStatus\":\"" + Status + "\" }";
        HRService* updateStatus = new HRService();

        //Calling HRService to make a post request.
        updateStatus->PostLeaveStatus(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);
    }
    catch (std::exception& es) {
        MainWindow::SetResponseData(es.what());
    }

}


void Approve_Reject_LeaveDlg::on_btnReject_clicked()
{
    QString id = LogID;
    QString remark = ui->remarks->toPlainText();
    //qDebug() << "sdfd" << remark;
    QString Status = "Rejected";

    try {
        //serializiation of json.
        QString Data = "{\"LogID\":\"" + id + "\",\"LeaveRequestRemarks\":\"" + remark + "\",\"LeaveRequestStatus\":\"" + Status + "\" }";
        HRService* updateStatus = new HRService();

        //Calling HRService to make a post request.
        updateStatus->PostLeaveStatus(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);
    }
    catch (std::exception& es) {
        MainWindow::SetResponseData(es.what());
    }
}


void Approve_Reject_LeaveDlg::on_btnClose_clicked()
{
    this->close();
}


void Approve_Reject_LeaveDlg::on_LeaveRequestcombo_activated(const QString &Username)
{

    int index = ui->LeaveRequestcombo->currentIndex() + 1;
    HRService* getAllEmployeeService = new HRService();
    QJsonArray employee_array;
    try {
        QJsonDocument document=getAllEmployeeService->GetAllLeaveApplications();
        employee_array = document.array();
        for(int i=0;i<index;i++)
        {
            QJsonObject jobj=employee_array[i].toObject();
            LogID = jobj.value("LogID").toString();
        }
    } catch (...) {

    }



    if( ui->LeaveRequestcombo->currentIndex()==-1)
        return;
    for(int i=0;i<m_JsonArray.size();i++)
    {
        QJsonObject obj=m_JsonArray[i].toObject();
        if(obj["LogID"].toString()==LogID)
        {
            ui->remarks->setText(obj["LeaveRequestRemarks"].toString());

            QString fromDate=obj["FromDate"].toString();
            ui->from->setText(""+GetDateFromTicks(fromDate.toLongLong()).toString("dd.MM.yyyy"));

            QString toDate=obj["ToDate"].toString();
            ui->to->setText(""+GetDateFromTicks(toDate.toLongLong()).toString("dd.MM.yyyy"));

            ui->status->setText(obj["LeaveRequestStatus"].toString());
            ui->type_of_leave->setText(obj["LeaveType"].toString());
            ui->reason->setText(obj["LeaveReason"].toString());
        }
    }
}

QDateTime Approve_Reject_LeaveDlg::GetDateFromTicks(qint64 ticks)
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeLast=dateTimefirst.addMSecs(ticks/10000);
    return dateTimeLast;
}

