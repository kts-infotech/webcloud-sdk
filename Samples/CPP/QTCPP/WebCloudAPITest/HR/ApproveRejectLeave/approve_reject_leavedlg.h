#ifndef APPROVE_REJECT_LEAVEDLG_H
#define APPROVE_REJECT_LEAVEDLG_H
#include "Services/hrservice.h"
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QDateTime>
#include <QStandardItemModel>
#include <qtableview.h>

namespace Ui {
class Approve_Reject_LeaveDlg;
}

class Approve_Reject_LeaveDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Approve_Reject_LeaveDlg(QWidget *parent = nullptr);
    ~Approve_Reject_LeaveDlg();
    HRService *m_pHRService;
    QString StringifyJson(QJsonDocument jsonDoc);
    QString LogID;


private slots:
    void on_pushButton_2_clicked();

    void on_btnReject_clicked();

    void on_btnClose_clicked();

    void on_LeaveRequestcombo_activated(const QString &arg1);

private:
    Ui::Approve_Reject_LeaveDlg *ui;
    void LoadAllLeaveApplications();
    QJsonArray m_JsonArray;
    QDateTime GetDateFromTicks(qint64 ticks);
};

#endif // APPROVE_REJECT_LEAVEDLG_H
