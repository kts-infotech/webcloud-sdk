#ifndef LISTEXMCTG_DLG_H
#define LISTEXMCTG_DLG_H

#include <QDialog>

namespace Ui {
class listexmctg_Dlg;
}

class listexmctg_Dlg : public QDialog
{
    Q_OBJECT

public:
    explicit listexmctg_Dlg(QWidget *parent = nullptr);
    ~listexmctg_Dlg();

private slots:
    void on_pushButton_clicked();

    void on_treeView_expanded(const QModelIndex &index);

private:
    Ui::listexmctg_Dlg *ui;
};

#endif // LISTEXMCTG_DLG_H
