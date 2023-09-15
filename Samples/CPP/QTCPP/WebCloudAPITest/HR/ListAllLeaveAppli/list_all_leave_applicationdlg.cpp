#include "list_all_leave_applicationdlg.h"
#include "ui_list_all_leave_applicationdlg.h"
#include <Services/hrservice.h>
#include <mainwindow.h>
#include <QListWidget>
#include  <QMessageBox>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QStringListModel>
#include <QTableWidgetItem>
#include <qstringview.h>
#include <QStandardItemModel>

List_All_Leave_ApplicationDlg::List_All_Leave_ApplicationDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List_All_Leave_ApplicationDlg)
{
    ui->setupUi(this);
    m_pHRService=new HRService();
}

List_All_Leave_ApplicationDlg::~List_All_Leave_ApplicationDlg()
{
    delete ui;
}

void List_All_Leave_ApplicationDlg::showEvent(QShowEvent *event)
{
    showtable();
    AddItemtotable();
}

void List_All_Leave_ApplicationDlg::showtable()
{
    Leave_Model = new QStandardItemModel();
    ui->ListTable->setColumnWidth(0, 20);
    Leave_Model->setHorizontalHeaderItem(0,new QStandardItem(tr("LogID")));
    Leave_Model->setHorizontalHeaderItem(1,new QStandardItem(tr("UserName")));
    Leave_Model->setHorizontalHeaderItem(2,new QStandardItem(tr("FromDate")));
    Leave_Model->setHorizontalHeaderItem(3,new QStandardItem(tr("ToDate")));
    Leave_Model->setHorizontalHeaderItem(4,new QStandardItem(tr("LeaveType")));
    Leave_Model->setHorizontalHeaderItem(5,new QStandardItem(tr("Reason")));
    Leave_Model->setHorizontalHeaderItem(6,new QStandardItem(tr("Request Status")));
    Leave_Model->setHorizontalHeaderItem(7,new QStandardItem(tr("Request Remarks")));
    ui->ListTable->setModel(Leave_Model);
}

void List_All_Leave_ApplicationDlg::AddItemtotable()
{
    HRService* getAllEmployeeService = new HRService();
    try
    {
        QJsonDocument document=getAllEmployeeService->GetAllLeaveApplications();
        employee_array = document.array();
        for(int i=0;i<employee_array.count();i++)
        {
            QJsonObject jobj=employee_array[i].toObject();
            QString LogID(jobj.value("LogID").toString());
            QString Username(jobj.value("Username").toString());


            QString fromDate=jobj["FromDate"].toString();
            QString FromDate = GetDateFromTicks(fromDate.toLongLong()).toString("MM/dd/yyyy");

            QString toDate=jobj["ToDate"].toString();
            QString ToDate = GetDateFromTicks(toDate.toLongLong()).toString("MM/dd/yyyy");

            //QString ToDate(jobj.value("ToDate").toString());
            QString LeaveType(jobj.value("LeaveType").toString());
            QString LeaveReason(jobj.value("LeaveReason").toString());
            QString LeaveRequestStatus(jobj.value("LeaveRequestStatus").toString());
            QString LeaveRequestRemarks(jobj.value("LeaveRequestRemarks").toString());

            //if(LastName=="")
            //{
            //    LastName="NULL";
            //}
            Leave_Model->setItem(i,0,new QStandardItem(LogID));
            Leave_Model->setItem(i,1,new QStandardItem(Username));
            Leave_Model->setItem(i,2,new QStandardItem(FromDate));
            Leave_Model->setItem(i,3,new QStandardItem(ToDate));
            Leave_Model->setItem(i,4,new QStandardItem(LeaveType));
            Leave_Model->setItem(i,5,new QStandardItem(LeaveReason));
            Leave_Model->setItem(i,6,new QStandardItem(LeaveRequestStatus));
            Leave_Model->setItem(i,7,new QStandardItem(LeaveRequestStatus));

        }

    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
}

QDateTime List_All_Leave_ApplicationDlg::GetDateFromTicks(qint64 ticks)
{
    QDate date(1,1,1);
    QTime time(0,0,0);
    QDateTime dateTimefirst(date,time);//QDateTime::fromString("M1d1y0000:00:00","'M'M'd'd'y'yyhh:mm:ss");
    QDateTime dateTimeLast=dateTimefirst.addMSecs(ticks/10000);
    return dateTimeLast;
}

void List_All_Leave_ApplicationDlg::on_pushButton_clicked()
{
    this->close();
}

