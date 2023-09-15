#ifndef ADDDELFOOTERDLG_H
#define ADDDELFOOTERDLG_H
#include <QDialog>
#include <QJsonArray>
#include <QItemSelectionModel>
#include "Services/cmsservice.h"
namespace Ui {
class AdddelFooterDlg;
}

class AdddelFooterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AdddelFooterDlg(QWidget *parent = nullptr);
    ~AdddelFooterDlg();
 QString strLinkID;
 cmsservice* AddDel;
//QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    //void on_pushButtonClose_clicked();

    void on_pushButtonInsert_clicked();

    void on_pushButtonRemove_clicked();
    void AddMenu();
    void AddExistingFooters();



    void on_listWidgetMenu_currentRowChanged(int index);

    void on_listWidgetFooters_currentRowChanged(int index);

private:
    Ui::AdddelFooterDlg *ui;
    QJsonArray jArray;
   int strMenu=-1,sel=-1;

 // int var1=strMenu;

protected:
 void showEvent(QShowEvent* event);
};

#endif // ADDDELFOOTERDLG_H
