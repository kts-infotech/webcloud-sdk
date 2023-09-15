#include "listexmctg_dlg.h"
#include "ui_listexmctg_dlg.h"
#include <mainwindow.h>
#include <Services/examservice.h>

listexmctg_Dlg::listexmctg_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listexmctg_Dlg)
{
    ui->setupUi(this);
}

listexmctg_Dlg::~listexmctg_Dlg()
{
    delete ui;
}

void listexmctg_Dlg::on_pushButton_clicked()
{
    this->close();
}


void listexmctg_Dlg::on_treeView_expanded(const QModelIndex &index)
{

}

