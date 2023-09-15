#ifndef HRSERVICE_H
#define HRSERVICE_H
#include <QString>
#include "networkrequest.h"
#include <QJsonDocument>

class HRService
{
public:
    HRService();
    NetWorkRequest *m_NetworkReq;
    QJsonDocument GetEmployeeList();
    QJsonDocument InviteEmployee(QByteArray Data);
    QJsonDocument AddEmployee(QByteArray Data);
    QJsonDocument UpdateEmployee(QByteArray Data);
    QJsonDocument DeleteEmployee(QString EmployeeID);
    QJsonDocument PostLeaveRequest(QByteArray Data);
    QJsonDocument GetAllLeaveApplications();
    QJsonDocument PostLeaveStatus(QByteArray Data);

private:
    QString strMainUrl;
    QString strUrl;
};
#endif // HRSERVICE_H
