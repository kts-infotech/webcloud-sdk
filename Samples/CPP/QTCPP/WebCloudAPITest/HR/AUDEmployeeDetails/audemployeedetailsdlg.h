#ifndef AUDEMPLOYEEDETAILSDLG_H
#define AUDEMPLOYEEDETAILSDLG_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <qtableview.h>
#include "Services/hrservice.h"

namespace Ui {
class AUDEmployeeDetailsDlg;
}

class AUDEmployeeDetailsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AUDEmployeeDetailsDlg(QWidget *parent = nullptr);
    ~AUDEmployeeDetailsDlg();
    QStandardItemModel* Employee_Model;
    HRService *m_pHRService;
    QString StringifyJson(QJsonDocument jsonDoc);
    QString btnSave;
    int Employeeid;

private slots:
    void on_btnEdit_clicked();

    void on_btnDelete_clicked();

    void on_btnSave_clicked();

    void on_btnClear_All_clicked();

    void on_btnClose_clicked();

private:
    Ui::AUDEmployeeDetailsDlg *ui;
    QJsonArray employee_array;
    void showtable();
    void AddItemtotable();
protected:
    void showEvent(QShowEvent* event);
};

#endif // AUDEMPLOYEEDETAILSDLG_H
