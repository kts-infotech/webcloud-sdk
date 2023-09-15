#ifndef ADDEXMCTG_H
#define ADDEXMCTG_H

#include <QDialog>

namespace Ui {
class addexmctg;
}

class addexmctg : public QDialog
{
    Q_OBJECT

public:
    explicit addexmctg(QWidget *parent = nullptr);
    ~addexmctg();

private:
    Ui::addexmctg *ui;
};

#endif // ADDEXMCTG_H
