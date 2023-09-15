#ifndef ADD_EDITQUES_DLG_H
#define ADD_EDITQUES_DLG_H

#include <QDialog>

namespace Ui {
class add_editQues_Dlg;
}

class add_editQues_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit add_editQues_Dlg(QWidget *parent = nullptr);
    ~add_editQues_Dlg();

private:
    Ui::add_editQues_Dlg *ui;
};

#endif // ADD_EDITQUES_DLG_H
