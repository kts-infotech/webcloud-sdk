#ifndef CMSSERVICE_H
#define CMSSERVICE_H
#include <QString>
#include <QJsonDocument>

class cmsservice
{
public:
    cmsservice();
     QJsonDocument AddListMenu();
     QJsonDocument AddExistingFooters();
     QJsonDocument AddExistingHeaders();
     QJsonDocument AddSettings();
     QJsonDocument AddFooter(QString strLinkName,QString var);
     QJsonDocument AddHeader(QString strLinkName,QString var);
     QJsonDocument DeleteFooter(QString strLinkID);
     QJsonDocument ListMenuWithID();
     QJsonDocument AddExternalLink(QByteArray data);
     QJsonDocument AddInternalLink();
     QJsonDocument UpdateTitle(QString strDefaultTitle,QString showLink);
     QJsonDocument UpdateExternalTitle(QString strDefaultTitle,QString showLink);
     QString UpdateExternalLink(QJsonDocument info);
     QJsonDocument GetSeoInfoOfPage();
     QJsonDocument DefaultSEOSettings();
     QString UpdateSeoSettings(QJsonDocument info);
     QJsonDocument DeleteExternalLink(QString strLinkID);
     QString ApplyOrder(QJsonDocument info);
private:
     QString strMainUrl;
     QString strUrl;
};

#endif // CMSSERVICE_H
