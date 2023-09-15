#ifndef LISTEXMSUBCTG_DLG_H
#define LISTEXMSUBCTG_DLG_H

#include <QDialog>

namespace Ui {
class listexmsubctg_Dlg;
}

class listexmsubctg_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit listexmsubctg_Dlg(QWidget *parent = nullptr);
    ~listexmsubctg_Dlg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listexmsubctg_Dlg *ui;
};

#endif // LISTEXMSUBCTG_DLG_H
