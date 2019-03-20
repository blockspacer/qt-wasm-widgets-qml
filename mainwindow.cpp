#include "mainwindow.h"
#include "qmlcontainer.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(openNewWindow()));

    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openNewWindow()
{
   mMyNewWindow = new QMLContainer(this); // Be sure to destroy your window somewhere
   mMyNewWindow->show();
   // ...
}
