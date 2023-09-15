#include "copyques_dlg.h"
#include "ui_copyques_dlg.h"

CopyQues_Dlg::CopyQues_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CopyQues_Dlg)
{
    ui->setupUi(this);
}

CopyQues_Dlg::~CopyQues_Dlg()
{
    delete ui;
}
