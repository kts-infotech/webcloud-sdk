#include "listexmques_dlg.h"
#include "ui_listexmques_dlg.h"

listexmQues_Dlg::listexmQues_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listexmQues_Dlg)
{
    ui->setupUi(this);
}

listexmQues_Dlg::~listexmQues_Dlg()
{
    delete ui;
}
