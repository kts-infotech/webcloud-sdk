/*---------------------------------------------------------------------------
    $Workfile: GetBugTrackerTaskDetailsList.h $

    Description: Header file for GetBugTrackerTaskDetailsList class.

    Copyright (C) 2022 KTS Computers
    All rights reserved.

   Author: Tom,LAKSHMI V
    Last $Modtime: 08/06/2022  $
    Last $Revision:  $
    $History: $
---------------------------------------------------------------------------*/

#ifndef GETBUGTRACKERTASKDETAILSLIST_H
#define GETBUGTRACKERTASKDETAILSLIST_H

#include <QDialog>
#include <QJsonArray>
namespace Ui {
class GetBugTrackerTaskDetailsList;
}

class GetBugTrackerTaskDetailsList : public QDialog
{
    Q_OBJECT

public:
    explicit GetBugTrackerTaskDetailsList(QWidget *parent = nullptr);
    ~GetBugTrackerTaskDetailsList();

private:
    Ui::GetBugTrackerTaskDetailsList *ui;
    QJsonArray m_jArray;
protected:
   void showEvent(QShowEvent* event);
private slots:
   void on_comboBoxBugTaskTitle_currentIndexChanged(int index);
   void on_pushButtonClose_clicked();
};

#endif // GETBUGTRACKERTASKDETAILSLIST_H
