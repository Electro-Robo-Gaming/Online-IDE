#include <QApplication>
#include <QIcon>
#include "onlineide.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon("G:/Online_IDE/onlineide.ico"));

    OnlineIDE w;
    w.show();
    return app.exec();
}
