#include "addexmctg.h"
#include "ui_addexmctg.h"
#include <mainwindow.h>

addexmctg::addexmctg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addexmctg)
{
    ui->setupUi(this);
}

addexmctg::~addexmctg()
{
    delete ui;
}
