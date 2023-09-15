#ifndef EXMDEFTSTG_DLG_H
#define EXMDEFTSTG_DLG_H

#include <QDialog>

namespace Ui {
class exmdeftstg_Dlg;
}

class exmdeftstg_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit exmdeftstg_Dlg(QWidget *parent = nullptr);
    ~exmdeftstg_Dlg();

private:
    Ui::exmdeftstg_Dlg *ui;
};

#endif // EXMDEFTSTG_DLG_H
