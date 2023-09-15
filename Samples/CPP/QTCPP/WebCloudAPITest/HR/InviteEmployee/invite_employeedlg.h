#ifndef INVITE_EMPLOYEEDLG_H
#define INVITE_EMPLOYEEDLG_H

#include <QDialog>

namespace Ui {
class Invite_EmployeeDlg;
}

class Invite_EmployeeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit Invite_EmployeeDlg(QWidget *parent = nullptr);
    ~Invite_EmployeeDlg();

private slots:
    void on_btnInvite_Employee_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Invite_EmployeeDlg *ui;
};

#endif // INVITE_EMPLOYEEDLG_H
