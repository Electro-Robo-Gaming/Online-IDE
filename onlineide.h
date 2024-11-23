#ifndef ONLINEIDE_H
#define ONLINEIDE_H

#include <QMainWindow>

#include <QWebEngineView>
#include <QWebEngineDownloadRequest>

QT_BEGIN_NAMESPACE

namespace Ui {

class OnlineIDE;
}
QT_END_NAMESPACE

class OnlineIDE : public QMainWindow
{
    Q_OBJECT

public:
    explicit OnlineIDE(QWidget *parent = nullptr);
    ~OnlineIDE();

private slots:
    void handleDownloadRequested(QWebEngineDownloadRequest *download);


private:
    Ui::OnlineIDE *ui;
    QWebEngineView *webView;
};
#endif
