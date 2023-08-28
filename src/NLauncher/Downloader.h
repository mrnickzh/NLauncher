#pragma once
#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <deque>
#include "Utils.h"

class Downloader : public QObject {

    Q_OBJECT

public:
    Downloader();
    void setTarget(const QString&, const QString&);

private:
    QNetworkAccessManager manager;
    std::deque<QString> target;
    std::deque<QString> filename;
signals:
    void done();

public slots:
    void download();
    void downloadFinished(QNetworkReply*);
    void downloadProgress(qint64, qint64);
};