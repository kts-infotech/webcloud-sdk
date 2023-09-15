#include "audemployeedetailsdlg.h"
#include "ui_audemployeedetailsdlg.h"
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

AUDEmployeeDetailsDlg::AUDEmployeeDetailsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AUDEmployeeDetailsDlg)
{
    ui->setupUi(this);
    m_pHRService=new HRService();
    QStringList ListEmployeeType={"Full Time","Intern | Trainee","Part Type"};
    ui->Employee_Typecombo->addItems(ListEmployeeType);
    QStringList ListEmployeeStatus={"Active","Left","None","On Leave"};
    ui->Employee_Statuscombo->addItems(ListEmployeeStatus);
}

void AUDEmployeeDetailsDlg::showEvent(QShowEvent *event)
{
    showtable();
    AddItemtotable();
}

void AUDEmployeeDetailsDlg::showtable()
{
    Employee_Model = new QStandardItemModel();

    Employee_Model->setHorizontalHeaderItem(0,new QStandardItem(tr("EmployeeName")));
    Employee_Model->setHorizontalHeaderItem(1,new QStandardItem(tr("EmployeeEmailOff")));
    Employee_Model->setHorizontalHeaderItem(2,new QStandardItem(tr("EmployeeEmailHom")));
    Employee_Model->setHorizontalHeaderItem(3,new QStandardItem(tr("EmployeePh")));
    ui->Employee_Listtable->setModel(Employee_Model);
}

void AUDEmployeeDetailsDlg::AddItemtotable()
{
    HRService* getAllEmployeeService = new HRService();
    try
    {
        QJsonDocument document=getAllEmployeeService->GetEmployeeList();
        employee_array = document.array();
        for(int i=0;i<employee_array.count();i++)
        {
            QJsonObject jobj=employee_array[i].toObject();
            QString EmployeeName(jobj.value("EmployeeName").toString());
            QString EmployeeEmailOff(jobj.value("EmployeeEmailOff").toString());
            QString EmployeeEmailHom(jobj.value("EmployeeEmailHom").toString());
            QString EmployeePh(jobj.value("EmployeePh").toString());

            //if(LastName=="")
            //{
            //    LastName="NULL";
            //}
            Employee_Model->setItem(i,0,new QStandardItem(EmployeeName));
            Employee_Model->setItem(i,1,new QStandardItem(EmployeeEmailOff));
            Employee_Model->setItem(i,2,new QStandardItem(EmployeeEmailHom));
            Employee_Model->setItem(i,3,new QStandardItem(EmployeePh));

        }

    }
    catch (std::exception& es)
    {
        MainWindow::SetResponseData(es.what());
    }
}

AUDEmployeeDetailsDlg::~AUDEmployeeDetailsDlg()
{
    delete ui;
}

void AUDEmployeeDetailsDlg::on_btnEdit_clicked()
{
    QPushButton *btnSave = findChild<QPushButton*>("btnSave");
    btnSave->setText("Update");

    QTableView *tableView = findChild<QTableView*>("Employee_Listtable");
    // replace with your table view object name

    QItemSelectionModel *selectionModel = tableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    int numRows = 0;
    if (selectionModel->hasSelection()) {
        numRows = tableView->model()->rowCount();
        qDebug() << "Total number of rows: " << numRows;
    }

    int rowIndex = -1;
    if (selectionModel->hasSelection()) {
        QModelIndex currentIndex = selectionModel->currentIndex();
        rowIndex = currentIndex.row();
        qDebug() << "Selected row index: " << rowIndex;
    }


    // Clearing the input fields
    ui->EmployeeName->clear();
    //ui->Employee_Typecombo->setCurrentIndex(0);
    ui->EmployeeAddr->clear();
    ui->EmployeeEmailOff->clear();
    ui->EmployeeEmailHom->clear();
    ui->EmployeePh->clear();
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->calendarWidget_2->setSelectedDate(QDate::currentDate());
    //ui->Employee_Statuscombo->setCurrentIndex(0);
    ui->EmployeeFinalSal->clear();
    ui->Employee_Remarks_2->clear();

    QJsonArray employeeArray = m_pHRService->GetEmployeeList().array();

    // Loop through the array to find the employee with the matching ID
    for (int i = 0; i < employeeArray.size(); i++)
    {
        QJsonObject currentEmployee = employeeArray[rowIndex].toObject();
        Employeeid = currentEmployee["EmployeeID"].toString().toInt();
        ui->EmployeeName->setText(currentEmployee["EmployeeName"].toString());
        qint64 type=currentEmployee["EmployeeType"].toString().toInt();
        if (type == 0)
        {
            ui->Employee_Typecombo->setCurrentIndex(0);
        }
        else if(type == 1)
        {
            ui->Employee_Typecombo->setCurrentIndex(1);
        }
        else if(type == 2)
        {
            ui->Employee_Typecombo->setCurrentIndex(2);
        }



            ui->EmployeeAddr->setText(currentEmployee["EmployeeAddr"].toString());
            ui->EmployeeEmailOff->setText(currentEmployee["EmployeeEmailOff"].toString());
            ui->EmployeeEmailHom->setText(currentEmployee["EmployeeEmailHom"].toString());
            ui->EmployeePh->setText(currentEmployee["EmployeePh"].toString());

            QDate joinDate = QDate::fromString(currentEmployee["EmployeeJoinDate"].toString(), "MM/dd/yy");
            ui->calendarWidget->setSelectedDate(joinDate);

            QDate leaveDate = QDate::fromString(currentEmployee["EmployeeLeavingDate"].toString(), "MM/dd/yy");
            ui->calendarWidget_2->setSelectedDate(leaveDate);
            ui->Employee_Statuscombo->setCurrentText(currentEmployee["EmployeeStatus"].toString());
            QString status = ui->Employee_Statuscombo->currentText();

            // Check the value of the status variable against expected values
            if(status == "Active")
            {
            // Set the ComboBox to the first index
            ui->Employee_Statuscombo->setCurrentIndex(0);
            }
            else if(status == "Left")
            {
            // Set the ComboBox to the second index
            ui->Employee_Statuscombo->setCurrentIndex(1);
            }
            else if(status == "None")
            {
            // Set the ComboBox to the third index
            ui->Employee_Statuscombo->setCurrentIndex(2);
            }
            else if(status == "On Leave")
            {
            // Set the ComboBox to the fourth index
            ui->Employee_Statuscombo->setCurrentIndex(3);
            }
            else
            {
            // Add a default behavior for unexpected values
            qDebug() << "Unknown status value: " << status;
            }


            ui->EmployeeFinalSal->setText(currentEmployee["EmployeeFinalSal"].toString());
            ui->Employee_Remarks_2->setText(currentEmployee["EmployeeRemarks"].toString());

    }
}



void AUDEmployeeDetailsDlg::on_btnDelete_clicked()
{
    QTableView *tableView = findChild<QTableView*>("Employee_Listtable");
    QItemSelectionModel *selectionModel = tableView->selectionModel();
    int rowIndex = -1;
    if (selectionModel->hasSelection()) {
            QModelIndex currentIndex = selectionModel->currentIndex();
            rowIndex = currentIndex.row();
            qDebug() << "Selected row index: " << rowIndex;
    }
    QJsonArray employeeArray = m_pHRService->GetEmployeeList().array();

    // Loop through the array to find the employee with the matching ID
    QString EmployeeEmailOff;
    for (int i = 0; i < employeeArray.size(); i++) {
            QJsonObject currentEmployee = employeeArray[rowIndex].toObject();
            EmployeeEmailOff = currentEmployee["EmployeeEmailOff"].toString();
    }

    try {
            QJsonDocument Doc=m_pHRService->DeleteEmployee(EmployeeEmailOff);
            showtable();
            AddItemtotable();
    } catch (std::exception& es) {
            MainWindow::SetResponseData(es.what());
    }
}


void AUDEmployeeDetailsDlg::on_btnSave_clicked()
{
    QPushButton *btnSave = findChild<QPushButton*>("btnSave");
    if(btnSave->text() == "Update")
    {
            QString EmployeeName = ui->EmployeeName->text();
            int EmployeeType = ui->Employee_Typecombo->currentIndex();
            QString EmployeeAddr = ui->EmployeeAddr->text();
            QString EmployeeEmailOff = ui->EmployeeEmailOff->text();
            QString EmployeeEmailHom = ui->EmployeeEmailHom->text();
            QString EmployeePh = ui->EmployeePh->text();
            QDate joiningDate = ui->calendarWidget->selectedDate();
            QDate leaveDate = ui->calendarWidget_2->selectedDate();

            QString EmployeeJoinDate = joiningDate.toString("MM/dd/yy");
            QString EmployeeLeavingDate = leaveDate.toString("MM/dd/yy");

            QString EmployeeStatus = ui->Employee_Statuscombo->currentText();
            QString EmployeeFinalSal = ui->EmployeeFinalSal->text();
            QString EmployeeRemarks = ui->Employee_Remarks_2->text();
            try {
            //serializiation of json.
            QString Data = "{\"EmployeeID\":\"" + QString::number(Employeeid) + "\",\"EmployeeName\":\"" + EmployeeName + "\",\"EmployeeType\":\"" + QString::number(EmployeeType) + "\",\"EmployeeAddr\":\"" + EmployeeAddr + "\",\"EmployeeEmailOff\":\"" + EmployeeEmailOff + "\",\"EmployeeEmailHom\":\"" + EmployeeEmailHom + "\",\"EmployeePh\":\"" + EmployeePh + "\",\"EmployeeJoinDate\":\"" + EmployeeJoinDate + "\",\"EmployeeLeavingDate\":\"" + EmployeeLeavingDate + "\",\"EmployeeStatus\":\"" + EmployeeStatus + "\",\"EmployeeFinalSal\":\"" + EmployeeFinalSal + "\",\"EmployeeRemarks\":\"" + EmployeeRemarks + "\" }";
            HRService* updateEmployee = new HRService();

            //Calling HRService to make a post request.
            updateEmployee->UpdateEmployee(Data.toUtf8());

            //Displaying request data.
            QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
            MainWindow::SetRequestData(reqData);
            AddItemtotable();

            }
            catch (std::exception& es) {
            MainWindow::SetResponseData(es.what());
            }
    }
    else if(btnSave->text() == "Save"){
            QString EmployeeName = ui->EmployeeName->text();
            int EmployeeType = ui->Employee_Typecombo->currentIndex();
            QString EmployeeAddr = ui->EmployeeAddr->text();
            QString EmployeeEmailOff = ui->EmployeeEmailOff->text();
            QString EmployeeEmailHom = ui->EmployeeEmailHom->text();
            QString EmployeePh = ui->EmployeePh->text();
            QDate joiningDate = ui->calendarWidget->selectedDate();
            QDate leaveDate = ui->calendarWidget_2->selectedDate();

            QString EmployeeJoinDate = joiningDate.toString("MM/dd/yy");
            QString EmployeeLeavingDate = leaveDate.toString("MM/dd/yy");

            QString EmployeeStatus = ui->Employee_Statuscombo->currentText();
            QString EmployeeFinalSal = ui->EmployeeFinalSal->text();
            QString EmployeeRemarks = ui->Employee_Remarks_2->text();
            try {
            //serializiation of json.
            QString Data = "{\"EmployeeID\":\"\",\"EmployeeName\":\"" + EmployeeName + "\",\"EmployeeType\":\"" + QString::number(EmployeeType) + "\",\"EmployeeAddr\":\"" + EmployeeAddr + "\",\"EmployeeEmailOff\":\"" + EmployeeEmailOff + "\",\"EmployeeEmailHom\":\"" + EmployeeEmailHom + "\",\"EmployeePh\":\"" + EmployeePh + "\",\"EmployeeJoinDate\":\"" + EmployeeJoinDate + "\",\"EmployeeLeavingDate\":\"" + EmployeeLeavingDate + "\",\"EmployeeStatus\":\"" + EmployeeStatus + "\",\"EmployeeFinalSal\":\"" + EmployeeFinalSal + "\",\"EmployeeRemarks\":\"" + EmployeeRemarks + "\" }";
            HRService* addEmployee = new HRService();

            //Calling HRService to make a post request.
            addEmployee->AddEmployee(Data.toUtf8());

            //Displaying request data.
            QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
            MainWindow::SetRequestData(reqData);
            AddItemtotable();

            }
            catch (std::exception& es) {
            MainWindow::SetResponseData(es.what());
            }
    }
}



void AUDEmployeeDetailsDlg::on_btnClear_All_clicked()
{
    ui->EmployeeName->setText("");
    ui->Employee_Typecombo->setCurrentIndex(0);
    ui->EmployeeAddr->setText("");
    ui->EmployeeEmailOff->setText("");
    ui->EmployeeEmailHom->setText("");
    ui->EmployeePh->setText("");
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->calendarWidget_2->setSelectedDate(QDate::currentDate());
    ui->Employee_Statuscombo->setCurrentIndex(0);
    ui->EmployeeFinalSal->setText("");
    ui->Employee_Remarks_2->setText("");
}


void AUDEmployeeDetailsDlg::on_btnClose_clicked()
{
    this->close();
}

