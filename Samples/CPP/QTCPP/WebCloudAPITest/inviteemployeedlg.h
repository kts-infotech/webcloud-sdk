#ifndef INVITEEMPLOYEEDLG_H
#define INVITEEMPLOYEEDLG_H

#include <QDialog>

namespace Ui {
class InviteEmployeeDlg;
}

class InviteEmployeeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit InviteEmployeeDlg(QWidget *parent = nullptr);
    ~InviteEmployeeDlg();

private:
    Ui::InviteEmployeeDlg *ui;
};

#endif // INVITEEMPLOYEEDLG_H
