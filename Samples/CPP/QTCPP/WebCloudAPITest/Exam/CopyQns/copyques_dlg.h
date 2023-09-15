#ifndef COPYQUES_DLG_H
#define COPYQUES_DLG_H

#include <QDialog>

namespace Ui {
class CopyQues_Dlg;
}

class CopyQues_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit CopyQues_Dlg(QWidget *parent = nullptr);
    ~CopyQues_Dlg();

private:
    Ui::CopyQues_Dlg *ui;
};

#endif // COPYQUES_DLG_H
