#ifndef GETALLEXTERNALLINKSDLG_H
#define GETALLEXTERNALLINKSDLG_H
#include <QJsonArray>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class GetAllExternalLinksDlg;
}

class GetAllExternalLinksDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllExternalLinksDlg(QWidget *parent = nullptr);
    ~GetAllExternalLinksDlg();
QStandardItemModel* Model;
private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::GetAllExternalLinksDlg *ui;
    QJsonArray jArray;

protected:
 void showEvent(QShowEvent* event);
 void CreateTableView();
 void DisplayAllItems();
};

#endif // GETALLEXTERNALLINKSDLG_H
