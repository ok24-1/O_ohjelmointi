#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void seTime();
    void timeOutHandeler();
    void stateHandeler();
    void turnHandeler();
    void barHandeler();

private:
    Ui::MainWindow *ui;
    short gameTime;
    short p1Time;
    short p2Time;
    short curPlayer;
    bool gameState;
    QTimer * gameTimer;
};
#endif // MAINWINDOW_H
