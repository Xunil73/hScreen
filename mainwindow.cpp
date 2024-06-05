#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint); // einzige Möglichkeit um die Statusbar des Programms zu entfernen
    ui->setupUi(this);
    MyNmapView *mynmapview = new MyNmapView(this);
    connect(mynmapview, &MyNmapView::nmapReady, this, &MainWindow::displayNmap);
    connect(mynmapview, &MyNmapView::finished, mynmapview, &QObject::deleteLater);
    mynmapview->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayNmap(const QString& str) {
    //ui->textBrowser->setTextColor(Qt::darkRed);
    ui->textBrowser->setPlainText(str);
}
