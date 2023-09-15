#ifndef ADDUSERDLG_H
#define ADDUSERDLG_H

#include <QDialog>

namespace Ui {
class AddUserDlg;
}

class AddUserDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDlg(QWidget *parent = nullptr);
    ~AddUserDlg();

private slots:
    void on_buttonBox_2_accepted();

private:
    Ui::AddUserDlg *ui;
};

#endif // ADDUSERDLG_H
