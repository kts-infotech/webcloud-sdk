#ifndef ADDINTERNALLINKDLG_H
#define ADDINTERNALLINKDLG_H
#include "qlayoutitem.h"
#include <QDialog>
#include <QJsonArray>
#include <QMessageBox>
#include "Services/cmsservice.h"
namespace Ui {
class AddInternalLinkDlg;
}

class AddInternalLinkDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddInternalLinkDlg(QWidget *parent = nullptr);
    ~AddInternalLinkDlg();
cmsservice* AddInLink;
private slots:
    void on_pushButtonUpdateTitle_clicked();

    void on_pushButtonInsert_clicked();

    void on_pushButtonRemove_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonClose_clicked();
void AddMenu();
void AddExistingLinks();
private:
    Ui::AddInternalLinkDlg *ui;
     QJsonArray jArray;

protected:
     void showEvent(QShowEvent* event);
};

#endif // ADDINTERNALLINKDLG_H
