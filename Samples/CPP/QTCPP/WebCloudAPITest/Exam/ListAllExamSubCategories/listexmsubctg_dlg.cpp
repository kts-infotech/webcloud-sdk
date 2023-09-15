#include "listexmsubctg_dlg.h"
#include "ui_listexmsubctg_dlg.h"

listexmsubctg_Dlg::listexmsubctg_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listexmsubctg_Dlg)
{
    ui->setupUi(this);
}

listexmsubctg_Dlg::~listexmsubctg_Dlg()
{
    delete ui;
}

void listexmsubctg_Dlg::on_pushButton_clicked()
{
    this->close();
}


