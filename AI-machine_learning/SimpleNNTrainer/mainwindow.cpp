#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QScrollArea>
#include "screencopy.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myWindow = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    if( myWindow != nullptr ) {
        delete myWindow;
    }
}

void MainWindow::on_pushButton_clicked()
{
    //QList<QScreen*> screens = QApplication::screens();
    QScreen* screen = qApp->primaryScreen();
    QRect g = screen->geometry();

    if( myWindow == nullptr ) {
        screenshot = screen->grabWindow(0, g.x(), g.y(), g.width(), g.height());
        screenshot.save("test.png");
        myWindow = new ScreenCopy(screenshot);
        myWindow->move(100,0);
        //myWindow->resize(g.width(),g.height());
        myWindow->resize(1200,780);
        //myWindow->setWindowTitle(QApplication::translate("Hello", "hello"));
        //QScrollArea* sc = new QScrollArea(myWindow);
        //sc->setGeometry(g);
    } else {
        screenshot = screen->grabWindow(0,myWindow->x(),myWindow->y(),myWindow->width(),myWindow->height());
    }
    myWindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    if( myWindow != nullptr ) {
        ((ScreenCopy*)myWindow)->saveTiles();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if( myWindow != nullptr ) {
        ((ScreenCopy*)myWindow)->trainNeuralNetwork();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if( myWindow != nullptr ) {
        ((ScreenCopy*)myWindow)->scanScreenshot();
    }
}
