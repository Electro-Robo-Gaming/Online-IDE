#include "filedownloader.h"
#include <QFile>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>

FileDownloader::FileDownloader(QObject *parent)
    : QObject(parent), networkManager(new QNetworkAccessManager(this)) {
    connect(networkManager, &QNetworkAccessManager::finished, this, &FileDownloader::onDownloadFinished);
}

void FileDownloader::downloadFile(const QUrl &url) {
    QNetworkRequest request(url);
    networkManager->get(request);
    qDebug() << "Downloading from:" << url.toString();
}

void FileDownloader::onDownloadFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QString fileName = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "/" +
                           QFileInfo(reply->url().path()).fileName();
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(reply->readAll());
            file.close();
            qDebug() << "File downloaded to:" << fileName;
        } else {
            qDebug() << "Failed to save file:" << fileName;
        }
    } else {
        qDebug() << "Download error:" << reply->errorString();
    }
    reply->deleteLater();
}
