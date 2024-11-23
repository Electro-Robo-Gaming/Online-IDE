#include "onlineide.h"
#include "ui_onlineide.h"

#include <QWebEngineProfile>
#include <QWebEngineDownloadRequest>
#include <QFileDialog>
#include <QDebug>

OnlineIDE::OnlineIDE(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::OnlineIDE),
    webView(new QWebEngineView(this)) {
    ui->setupUi(this);

    webView->setUrl(QUrl("https://online-ide-cyan.vercel.app/"));
    setCentralWidget(webView);

    connect(webView->page()->profile(), &QWebEngineProfile::downloadRequested,
            this, &OnlineIDE::handleDownloadRequested);
}

OnlineIDE::~OnlineIDE() {
    delete ui;
}

void OnlineIDE::handleDownloadRequested(QWebEngineDownloadRequest *download) {
    QString suggestedFileName = download->url().fileName();
    QString savePath = QFileDialog::getSaveFileName(this, "Save File", suggestedFileName);

    if (savePath.isEmpty()) {
        qDebug() << "Download canceled by the user.";
        return;
    }

    download->setDownloadDirectory(QFileInfo(savePath).absolutePath());
    download->setDownloadFileName(QFileInfo(savePath).fileName());
    download->accept();

    qDebug() << "Download started for:" << download->url().toString();
    connect(download, &QWebEngineDownloadRequest::stateChanged, this, [download]() {
        if (download->state() == QWebEngineDownloadRequest::DownloadCompleted) {
            qDebug() << "Download completed.";
        } else if (download->state() == QWebEngineDownloadRequest::DownloadInterrupted) {
            qDebug() << "Download interrupted.";
        }
    });
}
