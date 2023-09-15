#include "inviteemployeedlg.h"
#include "ui_inviteemployeedlg.h"

InviteEmployeeDlg::InviteEmployeeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InviteEmployeeDlg)
{
    ui->setupUi(this);
}

InviteEmployeeDlg::~InviteEmployeeDlg()
{
    delete ui;
}
