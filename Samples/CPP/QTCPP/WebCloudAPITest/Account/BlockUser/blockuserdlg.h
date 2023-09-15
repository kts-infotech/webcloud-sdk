#ifndef BLOCKUSERDLG_H
#define BLOCKUSERDLG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QJsonArray>
#include <QJsonObject>
namespace Ui {
class BlockUserDlg;
}

class BlockUserDlg : public QDialog
{
    Q_OBJECT

public:
    explicit BlockUserDlg(QWidget *parent = nullptr);
    ~BlockUserDlg();
    QStandardItemModel* blUser_Model;
    QPushButton *block;


private:
    Ui::BlockUserDlg *ui;
    QJsonArray bluser_array;
    void doSomething(int row);

    void showtable();
    void AddItemtotable();
protected:
    void showEvent(QShowEvent* event);
public slots:
    //void clicked(int row);
    void onclicked(int row);
};

#endif // BLOCKUSERDLG_H
