#include <mainwindow.h>
#include "addexmsubctg_dlg.h"
#include "Services/examservice.h"
#include "ui_addexmsubctg_dlg.h"
#include <QJsonObject>
#include <QJsonDocument>

addexmsubctg_Dlg::addexmsubctg_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addexmsubctg_Dlg)
{
    ui->setupUi(this);
}

addexmsubctg_Dlg::~addexmsubctg_Dlg()
{
    delete ui;
}

void addexmsubctg_Dlg::on_pushButton_clicked()
{
    int SubCategoryID = 0;
    int MainCategoryID = int (SubCategoryID);
    QString SubCategoryName =ui->textEdit->toPlainText();
    QString SubCategoryDesc =ui->textEdit_2->toPlainText();

    try
    {
        QString Data = "{\"SubCategoryName\":\"" + SubCategoryName + "\",\"SubCategoryDesc\":\"" + SubCategoryDesc + "\", \"MainCategoryID\":\"" + MainCategoryID + "\"}";
        ExamService* addsubexam = new ExamService();

        //Calling  AccountService to make a post request.
        addsubexam->AddExamSubCategory(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);

    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


void addexmsubctg_Dlg::on_pushButton_2_clicked()
{
    this->close();
}

