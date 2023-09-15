#ifndef APPLY_FOR_LEAVEDLG_H
#define APPLY_FOR_LEAVEDLG_H
#include "Services/hrservice.h"
#include <QDialog>
#include<QJsonArray>
#include<QJsonObject>

namespace Ui {
class Apply_For_LeaveDlg;
}

class Apply_For_LeaveDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Apply_For_LeaveDlg(QWidget *parent = nullptr);
    ~Apply_For_LeaveDlg();
    HRService *m_pHrService;
    QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void on_btnRequestLeave_clicked();

    void on_btnCancel_clicked();

    void on_Typecombo_activated(int index);

private:
    Ui::Apply_For_LeaveDlg *ui;
    qint64 GetTicksNow();
    qint64 GetTicksNow1();
    qint64 GetTicksNow2();
};

#endif // APPLY_FOR_LEAVEDLG_H
