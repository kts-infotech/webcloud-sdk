#ifndef DELETEUSERDLG_H
#define DELETEUSERDLG_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class DeleteUserDlg;
}

class DeleteUserDlg : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteUserDlg(QWidget *parent = nullptr);
    ~DeleteUserDlg();

private slots:
    void on_Deleteuser_clicked_clicked();

private:
    Ui::DeleteUserDlg *ui;
    QJsonArray m_jArray;
protected:
    void showEvent(QShowEvent* event);

};

#endif // DELETEUSERDLG_H
