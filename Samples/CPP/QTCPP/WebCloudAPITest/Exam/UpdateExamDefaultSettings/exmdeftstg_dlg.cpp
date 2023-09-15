#include "exmdeftstg_dlg.h"
#include "ui_exmdeftstg_dlg.h"

exmdeftstg_Dlg::exmdeftstg_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exmdeftstg_Dlg)
{
    ui->setupUi(this);
}

exmdeftstg_Dlg::~exmdeftstg_Dlg()
{
    delete ui;
}
