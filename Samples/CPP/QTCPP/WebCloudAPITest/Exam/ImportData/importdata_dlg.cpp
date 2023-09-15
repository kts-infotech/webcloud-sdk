#include "importdata_dlg.h"
#include "ui_importdata_dlg.h"

importdata_Dlg::importdata_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importdata_Dlg)
{
    ui->setupUi(this);
}

importdata_Dlg::~importdata_Dlg()
{
    delete ui;
}
