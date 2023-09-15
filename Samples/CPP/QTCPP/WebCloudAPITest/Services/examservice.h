#ifndef EXAMSERVICE_H
#define EXAMSERVICE_H

#include <QString>
#include <QJsonDocument>

class ExamService
{
public:
    ExamService();
    QJsonDocument AddExamMainCategory(QByteArray data);
    QJsonDocument AddExamSubCategory(QByteArray data);

private:
    QString strUrl;
};

#endif // EXAMSERVICE_H
