#include "mynmapview.h"

MyNmapView::MyNmapView(QObject *parent) {
}

void MyNmapView::run() {
    QProcess process;
    QString program = "nmap";
    QStringList arguments;
    arguments << "-v" << "-sn" << "192.168.178.0/24";
    process.start(program, arguments);
    process.waitForFinished(-1);
    QString outpt = process.readAllStandardOutput();

    qDebug() << outpt;
    emit nmapReady(outpt);
}
