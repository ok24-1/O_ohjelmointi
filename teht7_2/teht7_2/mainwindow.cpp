#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        activeDisplay = ui->display1;
        operation = "a";
        result = 0;
        connect(ui->b1,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b2,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b3,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b4,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b5,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b6,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b7,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b8,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b9,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->b0,&QPushButton::clicked,this,&MainWindow::clickHandler);
        connect(ui->bClear,&QPushButton::clicked,this,&MainWindow::clearAndEnterHandler);
        connect(ui->bEnter,&QPushButton::clicked,this,&MainWindow::clearAndEnterHandler);
        connect(ui->bPlus,&QPushButton::clicked,this,&MainWindow::operationHandler);
        connect(ui->bMinus,&QPushButton::clicked,this,&MainWindow::operationHandler);
        connect(ui->bDivided,&QPushButton::clicked,this,&MainWindow::operationHandler);
        connect(ui->bTimes,&QPushButton::clicked,this,&MainWindow::operationHandler);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::clickHandler() {

    QString c = activeDisplay->text();
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString bName = button->objectName();
    qDebug() << "Pressed " << bName;

    QString bNumber = bName.remove('b');

        for (int i = 0; i < 10; i++){
            if (bNumber == QString::number(i)){
                c += QString::number(i);
                activeDisplay->setText(c);
                break;
            }
        }
}



void MainWindow::clearAndEnterHandler()
{

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString bName = button->objectName();
    qDebug() << "Pressed " << bName;

    if (bName == "bClear"){
        ui->display1->clear();
        ui->display2->clear();
        ui->display3->clear();
        qDebug() << "Cleared everything";
        activeDisplay = ui->display1;
        operation = "a";
    }

    if (bName == "bEnter"){
        if (activeDisplay == ui->display1){
            activeDisplay = ui->display2;
        }
        if (activeDisplay == ui->display2){
            float a = ui->display1->text().toFloat();
            float b = ui->display2->text().toFloat();

            if (operation == "+"){
                float sum = a + b;
                QString AplusB = QString::number(sum);
                ui->display3->setText(AplusB);
            }
            else if (operation == "-"){
                float sum = a - b;
                QString AplusB = QString::number(sum);
                ui->display3->setText(AplusB);
            }
            else if (operation == "/"){
                float sum = a / b;
                QString AplusB = QString::number(sum);
                ui->display3->setText(AplusB);
            }
            else if (operation == "*"){
                float sum = a * b;
                QString AplusB = QString::number(sum);
                ui->display3->setText(AplusB);
            }
            else {
                ui->display3->setText("Missing operand");
            }
        }
    }
}

void MainWindow::operationHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString bName = button->objectName();
    qDebug() << "Pressed " << bName;

    if (bName == "bPlus"){
        operation = "+";
        activeDisplay = ui->display2;
        qDebug() << "using" << operation;
    }
    if (bName == "bMinus"){
        operation = "-";
        activeDisplay = ui->display2;
        qDebug() << "using" << operation;
    }
    if (bName == "bTimes"){
        operation = "*";
        activeDisplay = ui->display2;
        qDebug() << "using" << operation;
    }
    if (bName == "bDivided"){
        operation = "/";
        activeDisplay = ui->display2;
        qDebug() << "using" << operation;
    }
}
