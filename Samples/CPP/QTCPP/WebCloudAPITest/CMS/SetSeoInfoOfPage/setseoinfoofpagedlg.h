#ifndef SETSEOINFOOFPAGEDLG_H
#define SETSEOINFOOFPAGEDLG_H
#include <QDialog>
#include <QJsonArray>
#include "Services/cmsservice.h"
#include <QListWidgetItem>
namespace Ui {
class SetSEOInfoOfPageDlg;
}

class SetSEOInfoOfPageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetSEOInfoOfPageDlg(QWidget *parent = nullptr);
    ~SetSEOInfoOfPageDlg();
QString StringifyJson(QJsonDocument jsonDoc);
cmsservice* SetSeo;
QString strMenuID;
//QString strMenuId;
QString selectedMenuID;
QListWidgetItem * wItem;
int Menu;
private slots:

    void on_pushButtonClose_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonReset_clicked();

    void on_pushButtonSUpdate_clicked();

    void on_pushButtonSReset_clicked();





//void on_listWidgetMenu_currentTextChanged(const QString &strMenuID);


    //void on_listWidgetMenu_currentRowChanged(int currentRow);

  //  void on_listWidgetMenu_currentTextChanged(const QString &currentText);

    void on_listWidgetMenu_currentRowChanged(int currentRow);

private:
    Ui::SetSEOInfoOfPageDlg *ui;
    QJsonArray jArray;
protected:
 void showEvent(QShowEvent* event);
 void DisplayMenu();
 void DisplayDefaultSettings();
};

#endif // SETSEOINFOOFPAGEDLG_H
