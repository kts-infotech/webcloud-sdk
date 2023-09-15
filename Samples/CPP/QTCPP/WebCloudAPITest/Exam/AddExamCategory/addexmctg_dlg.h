#ifndef ADDEXMCTG_DLG_H
#define ADDEXMCTG_DLG_H

#include <QDialog>

namespace Ui {
class addexmctg_Dlg;
}

class addexmctg_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit addexmctg_Dlg(QWidget *parent = nullptr);
    ~addexmctg_Dlg();

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::addexmctg_Dlg *ui;
};

#endif // ADDEXMCTG_DLG_H
