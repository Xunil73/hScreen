#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint); // einzige Möglichkeit um die Statusbar des Programms zu entfernen
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
