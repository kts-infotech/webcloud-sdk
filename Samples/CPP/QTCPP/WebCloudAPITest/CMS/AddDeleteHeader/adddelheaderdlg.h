#ifndef ADDDELHEADERDLG_H
#define ADDDELHEADERDLG_H
#include <QDialog>
#include <QJsonArray>
#include "Services/cmsservice.h"

namespace Ui {
class AdddelHeaderDlg;
}

class AdddelHeaderDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AdddelHeaderDlg(QWidget *parent = nullptr);
    ~AdddelHeaderDlg();
 QString strLinkID;
 cmsservice* AddDelHdr;
private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonInsert_clicked();

    void on_pushButtonRemove_clicked();
    void AddMenu();
    void AddExistingHeaders();

    void on_listWidgetMenu_currentRowChanged(int currentRow);

    void on_listWidgetHeader_currentRowChanged(int currentRow);

private:
     QJsonArray jArray;
    Ui::AdddelHeaderDlg *ui;
protected:
     void showEvent(QShowEvent* event);

     int strMenu=-1;
     int sel=-1;
};

#endif // ADDDELHEADERDLG_H
