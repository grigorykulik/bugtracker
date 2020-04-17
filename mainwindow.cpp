#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BugData = new NewBugData();
    connect(ui->addButton, SIGNAL(clicked()), BugData, SLOT(show()));
    connect(BugData, SIGNAL(sendData(QString, QString, QString, QString, QString)),
            this, SLOT(recieveData(QString, QString, QString, QString, QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieveData(QString str1, QString str2,QString str3, QString str4, QString str5)
{
    int currentRowCount=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRowCount);
    ui->tableWidget->setItem(currentRowCount-1, 0, new QTableWidgetItem(str1));
    ui->tableWidget->setItem(currentRowCount-1, 1, new QTableWidgetItem(str2));
    ui->tableWidget->setItem(currentRowCount-1, 2, new QTableWidgetItem(str3));
    ui->tableWidget->setItem(currentRowCount-1, 3, new QTableWidgetItem(str4));
    ui->tableWidget->setItem(currentRowCount-1, 4, new QTableWidgetItem(str5));
}

//ui handlers
void MainWindow::on_addButton_clicked()
{
    int currentRowCount;

    currentRowCount=ui->tableWidget->rowCount();
    BugData->getEnvironment();
    currentRowCount--;
  //  ui->tableWidget->setItem(currentRowCount, 0, new QTableWidgetItem(Environment));
}
