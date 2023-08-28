#include "Downloader.h"

Downloader::Downloader() : manager(this) {
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
};


void Downloader::setTarget(const QString& t, const QString& f) {
    target.push_back(t);
    filename.push_back(f);
};

void Downloader::downloadFinished(QNetworkReply* data) {
    QFile localFile(filename[0]);
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    //qDebug() << sdata;
    localFile.close();
    qDebug() << target[0];
    target.pop_front();
    filename.pop_front();
    emit done();
    download();
};

void Downloader::download() {
    if (!target.empty() && !filename.empty()) {
        QUrl url = QUrl::fromEncoded(this->target[0].toLocal8Bit());
        QNetworkRequest request(url);
        connect(manager.get(request), SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
    }
};

void Downloader::downloadProgress(qint64 recieved, qint64 total) {
    qDebug() << recieved << total;
};