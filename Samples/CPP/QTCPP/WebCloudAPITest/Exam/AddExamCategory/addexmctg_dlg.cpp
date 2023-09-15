#include "addexmctg_dlg.h"
#include <Services/examservice.h>
#include "ui_addexmctg_dlg.h"
#include <mainwindow.h>
#include <QJsonObject>
#include <QJsonDocument>

addexmctg_Dlg::addexmctg_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addexmctg_Dlg)
{
    ui->setupUi(this);
}

addexmctg_Dlg::~addexmctg_Dlg()
{
    delete ui;
}

void addexmctg_Dlg::on_pushButton_2_clicked()
{
    int MainCategoryID = 0;
    QString MainCategoryName =ui->textEdit->toPlainText();
    QString MainCategoryDesc =ui->textEdit_2->toPlainText();

    try
    {
        QString Data = "{\"MainCategoryName\":\"" + MainCategoryName + "\",\"MainCategoryDesc\":\"" + MainCategoryDesc + "\", \"MainCategoryID\":\"" + MainCategoryID + "\" }";
        ExamService* addexam = new ExamService();

        //Calling  AccountService to make a post request.
        addexam->AddExamMainCategory(Data.toUtf8());

        //Displaying request data.
        QJsonDocument reqData = QJsonDocument::fromJson(Data.toUtf8());
        MainWindow::SetRequestData(reqData);

    }
    catch (std::exception& es)
    {
       MainWindow::SetResponseData(es.what());
    }
}


void addexmctg_Dlg::on_pushButton_clicked()
{
    this->close();
}

