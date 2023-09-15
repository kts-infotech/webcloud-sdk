#ifndef DELETEADMINDLG_H
#define DELETEADMINDLG_H

#include <QDialog>


#include <QJsonArray>

namespace Ui {
class DeleteAdminDlg;
}

class DeleteAdminDlg : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteAdminDlg(QWidget *parent = nullptr);
    ~DeleteAdminDlg();

protected:
    void showEvent(QShowEvent* event);



private slots:


    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::DeleteAdminDlg *ui;
    QJsonArray m_jArray;
};

#endif // DELETEADMINDLG_H
