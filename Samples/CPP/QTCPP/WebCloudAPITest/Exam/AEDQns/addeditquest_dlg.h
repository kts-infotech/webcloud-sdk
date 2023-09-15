#ifndef ADDEDITQUEST_DLG_H
#define ADDEDITQUEST_DLG_H

#include <QDialog>

namespace Ui {
class addUpdtQues_Dlg;
}

class addUpdtQues_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit addUpdtQues_Dlg(QWidget *parent = nullptr);
    ~addUpdtQues_Dlg();

private:
    Ui::addUpdtQues_Dlg *ui;
};

#endif // ADDEDITQUEST_DLG_H
