#ifndef GETDETAILEDPAGEINFODLG_H
#define GETDETAILEDPAGEINFODLG_H
#include <QDialog>
#include <QJsonArray>


namespace Ui {
class GetDetailedPageInfoDlg;
}

class GetDetailedPageInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GetDetailedPageInfoDlg(QWidget *parent = nullptr);
    ~GetDetailedPageInfoDlg();

private slots:
    void on_pushButtonClose_clicked();
    void AddMenuWithID();

    //void on_listWidgetMenu_itemChanged(int index);

    void on_listWidgetMenu_currentRowChanged(int index);

private:
    Ui::GetDetailedPageInfoDlg *ui;
    QJsonArray jArray;
protected:
 void showEvent(QShowEvent* event);
};

#endif // GETDETAILEDPAGEINFODLG_H
