#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black; "
                        "color: white;");
    this->setWindowIcon(QIcon("images/figment_logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
