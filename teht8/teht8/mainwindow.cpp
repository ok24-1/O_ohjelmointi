#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameTime = 0;
    curPlayer = 1;
    gameState = false;
    ui->progressBar1->setValue(100);
    ui->progressBar2->setValue(100);
    gameTimer = new QTimer(this);
    connect(gameTimer,&QTimer::timeout,this,&MainWindow::timeOutHandeler);
    connect(ui->bTime120,&QPushButton::clicked,this,&MainWindow::seTime);
    connect(ui->bTime300,&QPushButton::clicked,this,&MainWindow::seTime);
    connect(ui->bStart,&QPushButton::clicked,this,&MainWindow::stateHandeler);
    connect(ui->bStop,&QPushButton::clicked,this,&MainWindow::stateHandeler);
    connect(ui->bPass1,&QPushButton::clicked,this,&MainWindow::turnHandeler);
    connect(ui->bPass2,&QPushButton::clicked,this,&MainWindow::turnHandeler);
    connect(gameTimer,&QTimer::timeout,this,&MainWindow::barHandeler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::seTime()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString bName = button->objectName();

    if (bName == "bTime120" && gameState == false){
        gameTime = 120;
        ui->gameStatus->setText("Timer set for 120s. Ready to play!");
        qDebug() << "gameTime = " << gameTime;
        p1Time = gameTime, p2Time = gameTime;
        ui->progressBar1->setRange(0,gameTime);
        ui->progressBar2->setRange(0,gameTime);
        ui->progressBar1->setValue(gameTime);
        ui->progressBar2->setValue(gameTime);
    }
    else if (bName == "bTime300" && gameState == false){
        gameTime = 300;
        ui->gameStatus->setText("Timer set for 5m. Ready to play!");
        qDebug() << "gameTime = " << gameTime;
        p1Time = gameTime, p2Time = gameTime;
        ui->progressBar1->setRange(0,gameTime);
        ui->progressBar2->setRange(0,gameTime);
        ui->progressBar1->setValue(gameTime);
        ui->progressBar2->setValue(gameTime);
    }
}

void MainWindow::timeOutHandeler()
{
    if (curPlayer == 1){
        p1Time--;
        ui->gameStatus->setText("Player 1 turn");
    }
    else if (curPlayer == 2){
        p2Time--;
        ui->gameStatus->setText("Player 2 turn");
    }
    if (p1Time == 0 && gameState == true) {
        gameState = false;
        ui->gameStatus->setText("Player 2 wins!");
        gameTimer->stop();
        gameTime = 0;
    }
    else if (p2Time == 0 && gameState == true) {
        gameState = false;
        ui->gameStatus->setText("Player 1 wins!");
        gameTimer->stop();
        gameTime = 0;
    }

}

void MainWindow::stateHandeler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString bName = button->objectName();

    if (bName == "bStart" && gameTime != 0 && gameState == false){
        gameState = true;
        qDebug() << "Game started";
        gameTimer->start(1000);
        curPlayer = 1;
        ui->gameStatus->setText("Player 1 turn");
    }
    else if (bName == "bStop" && gameState == true){
        gameState = false;
        qDebug() << "Game aborted";
        ui->gameStatus->setText("Game aborted.");
        gameTimer->stop();
        gameTime = 0;
    }
    else if (gameTime == 0 && gameState == false) {
        ui->gameStatus->setText("Please select game lenght");
    }
 }

void MainWindow::turnHandeler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString bName = button->objectName();

    if (bName == "bPass1"){
        curPlayer = 2;
        qDebug() << "Turn passed to player 2";
    }
    if (bName == "bPass2"){
        curPlayer = 1;
        qDebug() << "Turn passed to player 1";
    }
}

void MainWindow::barHandeler()
{
    ui->progressBar1->setValue(p1Time);
    ui->progressBar2->setValue(p2Time);
}


