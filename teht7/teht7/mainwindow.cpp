#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addButton,&QPushButton::clicked,this,&MainWindow::clickToAdd);
    connect(ui->resetButton,&QPushButton::clicked,this,&MainWindow::clickToReset);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickToAdd()
{
    int c = ui->display->text().toInt();
    c++;
    qDebug() << "Clicked add";
    ui->display->setText(QString::number(c));
}
void MainWindow::clickToReset()
{
    qDebug() << "Clicked clear";
    ui->display->clear();
}
