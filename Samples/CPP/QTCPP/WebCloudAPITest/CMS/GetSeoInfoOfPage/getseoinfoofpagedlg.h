#ifndef GETSEOINFOOFPAGEDLG_H
#define GETSEOINFOOFPAGEDLG_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class GetSeoInfoOfPageDlg;
}

class GetSeoInfoOfPageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit GetSeoInfoOfPageDlg(QWidget *parent = nullptr);
    ~GetSeoInfoOfPageDlg();

private slots:
    void on_pushButtonClose_clicked();

    void on_comboBoxMenuID_currentIndexChanged(int index);

private:
    Ui::GetSeoInfoOfPageDlg *ui;
     QJsonArray jArray;
protected:
      void showEvent(QShowEvent* event);
};

#endif // GETSEOINFOOFPAGEDLG_H
