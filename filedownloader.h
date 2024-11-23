#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class FileDownloader : public QObject {
    Q_OBJECT

public:
    explicit FileDownloader(QObject *parent = nullptr);
    void downloadFile(const QUrl &url);

private slots:
    void onDownloadFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif
