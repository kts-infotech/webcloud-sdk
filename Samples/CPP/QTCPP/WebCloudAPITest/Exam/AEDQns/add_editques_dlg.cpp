#include "add_editques_dlg.h"
#include "ui_add_editques_dlg.h"

add_editQues_Dlg::add_editQues_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_editQues_Dlg)
{
    ui->setupUi(this);
}

add_editQues_Dlg::~add_editQues_Dlg()
{
    delete ui;
}
