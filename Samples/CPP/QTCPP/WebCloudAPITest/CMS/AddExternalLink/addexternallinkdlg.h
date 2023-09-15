#ifndef ADDEXTERNALLINKDLG_H
#define ADDEXTERNALLINKDLG_H
#include "qlayoutitem.h"
#include <QDialog>
#include <QJsonArray>
#include <QMessageBox>
#include "Services/cmsservice.h"
#include "qlistwidget.h"
#include <QListWidgetItem>
namespace Ui {
class AddExternalLinkDlg;
}

class AddExternalLinkDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddExternalLinkDlg(QWidget *parent = nullptr);
    ~AddExternalLinkDlg();
cmsservice* AddExLink;
QString StringifyJson(QJsonDocument jsonDoc);
private slots:
    void on_pushButtonUpdateTitle_clicked();

    void on_pushButtonApply_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonRemove_clicked();

    void on_pushButtonClose_clicked();

    void on_listWidgetSettings_currentRowChanged(int index);

    void on_pushButtonUp_clicked();

    void on_pushButtonDown_clicked();



  // void on_listWidgetSettings_currentTextChanged(const QString &currentText);

   // void on_listWidgetSettings_itemPressed(QListWidgetItem *item);

private:
    Ui::AddExternalLinkDlg *ui;
    QJsonArray jArray;
int sel,sel1;
protected:
    void showEvent(QShowEvent* event);
    void AddOtherSettings();
};

#endif // ADDEXTERNALLINKDLG_H
