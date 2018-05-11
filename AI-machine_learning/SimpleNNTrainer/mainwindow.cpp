#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    myWindow.capture();
    myWindow.show();
}

void MainWindow::on_pushButton_2_clicked()
{
    myWindow.saveTiles();
}

void MainWindow::on_pushButton_3_clicked()
{
    myWindow.trainNeuralNetwork();
}

void MainWindow::on_pushButton_4_clicked()
{
    myWindow.capture();
    myWindow.scanScreenshot_lr();
    myWindow.show();
}

void MainWindow::on_pushButton_5_clicked()
{
    myWindow.deleteTrainingSet();
}

void MainWindow::on_pushButton_6_clicked()
{
    myWindow.extractTrainingSet();
}
