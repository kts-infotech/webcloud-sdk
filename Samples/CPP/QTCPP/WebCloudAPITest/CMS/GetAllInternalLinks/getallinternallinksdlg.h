#ifndef GETALLINTERNALLINKSDLG_H
#define GETALLINTERNALLINKSDLG_H
#include <QStandardItemModel>
#include <QDialog>
#include <QJsonArray>
namespace Ui {
class GetAllInternalLinksDlg;
}

class GetAllInternalLinksDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllInternalLinksDlg(QWidget *parent = nullptr);
    ~GetAllInternalLinksDlg();
QStandardItemModel* Model;
private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::GetAllInternalLinksDlg *ui;
    QJsonArray jArray;

protected:
 void showEvent(QShowEvent* event);
 void CreateTableView();
 void DisplayAllItems();
};

#endif // GETALLINTERNALLINKSDLG_H
