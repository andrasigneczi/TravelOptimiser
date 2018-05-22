#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(findChild<QPushButton*>("SaveTrainingSet"), SIGNAL(clicked()), this, SLOT(on_SaveTrainingSet_clicked()));
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
    myWindow.hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    //myWindow.trainNeuralNetwork();
    myWindow.trainLogisticRegression();
}

void MainWindow::on_pushButton_4_clicked()
{
    myWindow.hide();
    myWindow.capture();
    myWindow.scanScreenshot_lr();
    //myWindow.scanScreenshot_lr_onevsall();
    //myWindow.scanScreenshot_svm();
    myWindow.show();
}

void MainWindow::on_pushButton_5_clicked()
{
    myWindow.deleteTrainingSet();
}

void MainWindow::on_pushButton_6_clicked()
{
    myWindow.extractTrainingSet(myWindow.getSelectedLabel());
}

void MainWindow::on_pushButton_7_clicked()
{
    myWindow.saveTrainingSet();
}
