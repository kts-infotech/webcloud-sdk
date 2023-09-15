#ifndef LISTEXMQUES_DLG_H
#define LISTEXMQUES_DLG_H

#include <QDialog>

namespace Ui {
class listexmQues_Dlg;
}

class listexmQues_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit listexmQues_Dlg(QWidget *parent = nullptr);
    ~listexmQues_Dlg();

private:
    Ui::listexmQues_Dlg *ui;
};

#endif // LISTEXMQUES_DLG_H
