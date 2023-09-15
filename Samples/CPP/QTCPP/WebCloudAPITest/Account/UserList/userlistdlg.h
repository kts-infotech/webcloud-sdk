#ifndef USERLISTDLG_H
#define USERLISTDLG_H

#include <QDialog>
#include <QJsonArray>
#include <QStandardItemModel>
#include "qtableview.h"

namespace Ui {
class UserListDlg;
}

class UserListDlg : public QDialog
{
    Q_OBJECT

public:
    explicit UserListDlg(QWidget *parent = nullptr);
    //(QObject *parent = 0);

    ~UserListDlg();
    QStandardItemModel* User_Model;

private:
    Ui::UserListDlg *ui;
    QJsonArray user_array;

    void showtable();
    void AddItemtotable();
protected:
    void showEvent(QShowEvent* event);


};

#endif // USERLISTDLG_H
