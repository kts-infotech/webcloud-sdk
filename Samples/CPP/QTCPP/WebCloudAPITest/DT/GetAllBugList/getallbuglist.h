/*---------------------------------------------------------------------------
    $Workfile: GetAllBugList.h $

    Description: Header file for GetAllBugList class.

    Copyright (C) 2022 KTS Computers
    All rights reserved.

   Author: Tom,LAKSHMI V
    Last $Modtime: 08/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/

#ifndef GETALLBUGLIST_H
#define GETALLBUGLIST_H

#include <QDialog>
#include <QJsonArray>
namespace Ui {
class GetAllBugList;
}

class GetAllBugList : public QDialog
{
    Q_OBJECT

public:
    explicit GetAllBugList(QWidget *parent = nullptr);
    ~GetAllBugList();

private:
    Ui::GetAllBugList *ui;
    QJsonArray m_jArray;
protected:
   void showEvent(QShowEvent* event);
private slots:
   void on_comboBoxTaskTitle_currentIndexChanged(int index);
   void on_pushButtonClose_clicked();
};

#endif // GETALLBUGLIST_H
