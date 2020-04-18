#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "bug.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ui handlers
void MainWindow::on_addButton_clicked()
{
    int currentRowCount;
    currentRowCount=ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(currentRowCount);

    Bug *bug=new Bug();

    bug->setEnvironment(ui->EnvironmentLineEdit->text());
    bug->setBugNumber(ui->BugNumberLineEdit->text());
    bug->setDescription(ui->DescriptionLineEdit->text());
    bug->setAffectedSystem(ui->AffectedSystemLineEdit->text());
    bug->setAffectedProduct(ui->AffectedProductLineEdit->text());

    ui->tableWidget->setItem(currentRowCount-1, 0, new QTableWidgetItem(bug->getEnvironment()));
    ui->tableWidget->setItem(currentRowCount-1, 1, new QTableWidgetItem(bug->getBugNumber()));
    ui->tableWidget->setItem(currentRowCount-1, 2, new QTableWidgetItem(bug->getDescription()));
    ui->tableWidget->setItem(currentRowCount-1, 3, new QTableWidgetItem(bug->getAffectedSystem()));
    ui->tableWidget->setItem(currentRowCount-1, 4, new QTableWidgetItem(bug->getAffectedProduct()));
    ui->tableWidget->setItem(currentRowCount-1, 5, new QTableWidgetItem(bug->getStatus()));

    for (int i=0; i<6; i++)
    {
        ui->tableWidget->item(currentRowCount-1, i)->setBackground(QBrush(QColor(250,0,0)));
    }


}

void MainWindow::on_removeButton_clicked()
{
        int RowToBeRemoved=ui->tableWidget->currentRow();

        if (ui->tableWidget->rowCount()==1)
        {
            QMessageBox msgBox;
            msgBox.setText("Nothing to remove");
            msgBox.exec();
        }

        else ui->tableWidget->removeRow(RowToBeRemoved);
}
