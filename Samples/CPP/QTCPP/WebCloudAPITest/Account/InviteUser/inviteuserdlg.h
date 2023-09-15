#ifndef INVITEUSERDLG_H
#define INVITEUSERDLG_H

#include <QDialog>

namespace Ui {
class InviteUserDlg;
}

class InviteUserDlg : public QDialog
{
    Q_OBJECT

public:
    explicit InviteUserDlg(QWidget *parent = nullptr);
    ~InviteUserDlg();

private slots:
    //void on_pushButton_2_clicked();

    void on_Inviteuserclosetn_clicked();

private:
    Ui::InviteUserDlg *ui;
};

#endif // INVITEUSERDLG_H
