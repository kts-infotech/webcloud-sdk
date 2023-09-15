#ifndef ACCADDADMINDLG_H
#define ACCADDADMINDLG_H

#include <QDialog>

namespace Ui {
class AccAddAdminDlg;
}

class AccAddAdminDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AccAddAdminDlg(QWidget *parent = nullptr);
    ~AccAddAdminDlg();

private slots:
    void on_accaddadmin_clicked();

private:
    Ui::AccAddAdminDlg *ui;
};

#endif // ACCADDADMINDLG_H
