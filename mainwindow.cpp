#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint); // einzige Möglichkeit um die Statusbar des Programms zu entfernen
    ui->setupUi(this);
    NmapThread *nmapThread = new NmapThread(this);
    connect(nmapThread, &NmapThread::nmapReady, this, &MainWindow::displayNmap);
    connect(nmapThread, &NmapThread::finished, nmapThread, &QObject::deleteLater);
    nmapThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayNmap(const QString& str) {
    //ui->textBrowser->setTextColor(Qt::darkRed);
    ui->textBrowser->setPlainText(str);
}
