#ifndef LIST_ALL_LEAVE_APPLICATIONDLG_H
#define LIST_ALL_LEAVE_APPLICATIONDLG_H

#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <qtableview.h>
#include "Services/hrservice.h"
#include <QDateTime>

namespace Ui {
class List_All_Leave_ApplicationDlg;
}

class List_All_Leave_ApplicationDlg : public QDialog
{
    Q_OBJECT

public:
    explicit List_All_Leave_ApplicationDlg(QWidget *parent = nullptr);
    ~List_All_Leave_ApplicationDlg();
    QStandardItemModel* Leave_Model;
    HRService *m_pHRService;
    QString StringifyJson(QJsonDocument jsonDoc);

private:
    Ui::List_All_Leave_ApplicationDlg *ui;
    QJsonArray employee_array;
    void showtable();
    void AddItemtotable();
    QDateTime GetDateFromTicks(qint64 ticks);
protected:
    void showEvent(QShowEvent* event);
private slots:
    void on_pushButton_clicked();
};

#endif // LIST_ALL_LEAVE_APPLICATIONDLG_H
