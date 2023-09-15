#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include <QObject>
#include <QEventLoop>


class NetWorkRequest : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkRequest(QObject *parent = nullptr);
    QNetworkReply * ValidateUser(QString strUrl);
    //QNetworkReply *  PostRequest(QString strUrl);
    void SetTimeout(int iMaxWaitTime);
    QNetworkReply * GetRequest(QString strUrl);

    QNetworkReply *PostRequest(QString strUrl, QByteArray data);
    static void SetAuthToken(QString strToken);
    static void SetMainUrl(QString strMainUrl);
    //QNetworkReply *PostRequest(QString strUrl, QString strHeader, QByteArray data);

private slots:
    void ReplyReciever(QNetworkReply * reply);
private:
    QNetworkAccessManager * m_Manager;
    QEventLoop * m_EvLoop;
    bool m_bErrorStatus;
    QString m_strErrorInfo;
    QNetworkReply * m_Reply;
    static QString m_strMainUrl,m_strAuthToken;

signals:

};

#endif // NETWORKREQUEST_H
