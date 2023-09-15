#ifndef ADDEXMSUBCTG_DLG_H
#define ADDEXMSUBCTG_DLG_H

#include <QDialog>

namespace Ui {
class addexmsubctg_Dlg;
}

class addexmsubctg_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit addexmsubctg_Dlg(QWidget *parent = nullptr);
    ~addexmsubctg_Dlg();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::addexmsubctg_Dlg *ui;
};

#endif // ADDEXMSUBCTG_DLG_H
