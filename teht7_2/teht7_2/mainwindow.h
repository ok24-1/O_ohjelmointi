#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlineedit.h"
#include "QPushButton"
#include <QMainWindow>

using namespace std;

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

private:
    Ui::MainWindow *ui;
    QLineEdit *activeDisplay;
    string operation;
    float result;
private slots:
    void clickHandler();
    void clearAndEnterHandler();
    void operationHandler();
};
#endif // MAINWINDOW_H
