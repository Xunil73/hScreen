#include "mynmapview.h"

MyNmapView::MyNmapView(QObject *parent) {
}

void MyNmapView::run() {
    QProcess process;
    process.start("nmap -v -sn 19.168.178.0/24");
    process.waitForFinished(-1);
    QString outpt = process.readAllStandardOutput();

    emit nmapReady(outpt);
}
