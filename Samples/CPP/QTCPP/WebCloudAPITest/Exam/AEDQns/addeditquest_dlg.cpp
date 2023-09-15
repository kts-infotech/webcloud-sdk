#include "addupdtques_dlg.h"
#include "ui_addupdtques_dlg.h"

addUpdtQues_Dlg::addUpdtQues_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUpdtQues_Dlg)
{
    ui->setupUi(this);
}

addUpdtQues_Dlg::~addUpdtQues_Dlg()
{
    delete ui;
}
