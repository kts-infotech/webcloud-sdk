#ifndef IMPORTDATA_DLG_H
#define IMPORTDATA_DLG_H

#include <QDialog>

namespace Ui {
class importdata_Dlg;
}

class importdata_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit importdata_Dlg(QWidget *parent = nullptr);
    ~importdata_Dlg();

private:
    Ui::importdata_Dlg *ui;
};

#endif // IMPORTDATA_DLG_H
