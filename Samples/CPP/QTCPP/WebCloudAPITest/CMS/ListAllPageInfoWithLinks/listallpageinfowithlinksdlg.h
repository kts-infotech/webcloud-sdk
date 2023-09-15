#ifndef LISTALLPAGEINFOWITHLINKSDLG_H
#define LISTALLPAGEINFOWITHLINKSDLG_H
#include "qtableview.h"
#include <QStandardItemModel>
#include <QDialog>
#include <QJsonArray>

namespace Ui {
class ListAllPageInfoWithLinksDlg;
}

class ListAllPageInfoWithLinksDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ListAllPageInfoWithLinksDlg(QWidget *parent = nullptr);
    ~ListAllPageInfoWithLinksDlg();
    QStandardItemModel* m_pModel;
 //QList<QString> Menuid;
private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::ListAllPageInfoWithLinksDlg *ui;
    void CreateTableView();
    void AddToTable(QApplication *info);
    QJsonArray jArray;
    void DisplayAllItem();
    void AddToTable();
    QTableView* m_listItems=new QTableView();
protected:
 void showEvent(QShowEvent* event);
  //  QStandardItemModel m_pModel;
};

#endif // LISTALLPAGEINFOWITHLINKSDLG_H
