#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "bug.h"
#include "QMessageBox"
#include "QList"

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
//handle add button
void MainWindow::on_addButton_clicked()
{

//get the current number of rows in the table
    int currentRowCount;
    currentRowCount=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRowCount);

//create a bug and fill its fields with values
    Bug *bug=new Bug();

    bug->setEnvironment(ui->EnvironmentComboBox->currentText());
    bug->setBugNumber(ui->BugNumberLineEdit->text());
    bug->setDescription(ui->DescriptionLineEdit->text());
    bug->setAffectedSystem(ui->AffectedSystemComboBox->currentText());
    bug->setAffectedProduct(ui->AffectedProductComboBox->currentText());

    ui->tableWidget->setItem(currentRowCount-1, 0, new QTableWidgetItem(bug->getEnvironment()));
    ui->tableWidget->setItem(currentRowCount-1, 1, new QTableWidgetItem(bug->getBugNumber()));
    ui->tableWidget->setItem(currentRowCount-1, 2, new QTableWidgetItem(bug->getDescription()));
    ui->tableWidget->setItem(currentRowCount-1, 3, new QTableWidgetItem(bug->getAffectedSystem()));
    ui->tableWidget->setItem(currentRowCount-1, 4, new QTableWidgetItem(bug->getAffectedProduct()));
    ui->tableWidget->setItem(currentRowCount-1, 5, new QTableWidgetItem(bug->getStatus()));

    addBug(*bug);

//paint the added row red
    for (int i=0; i<6; i++)
    {
        ui->tableWidget->item(currentRowCount-1, i)->setBackground(QBrush(QColor(250,0,0)));
    }  
}

//handle remove button
void MainWindow::on_removeButton_clicked()
{
        int RowToBeRemoved=ui->tableWidget->currentRow();

        if (ui->tableWidget->rowCount()==1)
        {
            QMessageBox msgBox;
            msgBox.setText("Nothing to remove");
            msgBox.exec();
        }

        else
        {
            ui->tableWidget->removeRow(RowToBeRemoved);
            removeBug(&Bugs, RowToBeRemoved);
        }
}

//add a bug to the list
void MainWindow::addBug(Bug bug)
{
    Bugs.push_back(bug);
    updateStatistics(&Bugs);
}

//remove a bug from the list
void MainWindow::removeBug(std::vector<Bug> *Bugs, int Row)
{
    std::vector<Bug>::iterator pos;
    pos=Bugs->begin()+Row;
    Bugs->erase(pos);
    Bugs->shrink_to_fit();
    updateStatistics(Bugs);
}


//update statistics
void MainWindow::updateStatistics(std::vector<Bug> *Bugs)
{
    int BugsInEnv1=0;
    int BugsInEnv2=0;
    int BugsInSystem1=0;
    int BugsInSystem2=0;
    int BugsInSystem3=0;
    int BugsInSystem4=0;
    int BugsInSystem5=0;
    int BugsInProduct1=0;
    int BugsInProduct2=0;
    int BugsInProduct3=0;
    int BugsInProduct4=0;
    int BugsInProduct5=0;

    //show the total number of bugs
    ui->BugsTotalLabel->setText(QString::number(Bugs->size()));

    //count and show bugs on env 1
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getEnvironment()=="ENV 1") BugsInEnv1++;
    }

    ui->BugsInEnv1Label->setText(QString::number(BugsInEnv1));

//count and show bugs on env 2
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getEnvironment()=="ENV 2") BugsInEnv2++;
    }

    ui->BugsInEnv2Label->setText(QString::number(BugsInEnv2));

//count and show bugs on system 1
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedSystem()=="SYSTEM 1") BugsInSystem1++;
    }

    ui->BugsInSystem1Label->setText(QString::number(BugsInSystem1));

//count and show bugs on system 2
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedSystem()=="SYSTEM 2") BugsInSystem2++;
    }

    ui->BugsInSystem2Label->setText(QString::number(BugsInSystem2));

//count and show bugs on system 3
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedSystem()=="SYSTEM 3") BugsInSystem3++;
    }

    ui->BugsInSystem3Label->setText(QString::number(BugsInSystem3));

//count and show bugs on system 4
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedSystem()=="SYSTEM 4") BugsInSystem4++;
    }

    ui->BugsInSystem4Label->setText(QString::number(BugsInSystem4));

//count and show bugs on system 5
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedSystem()=="SYSTEM 5") BugsInSystem5++;
    }

    ui->BugsInSystem5Label->setText(QString::number(BugsInSystem5));

//count and show bugs in prouct 1
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedProduct()=="PRODUCT 1") BugsInProduct1++;
    }

    ui->BugsInProduct1Label->setText(QString::number(BugsInProduct1));

//count and show bugs in prouct 2
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedProduct()=="PRODUCT 2") BugsInProduct2++;
    }

    ui->BugsInProduct2Label->setText(QString::number(BugsInProduct2));

//count and show bugs in prouct 3
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedProduct()=="PRODUCT 3") BugsInProduct3++;
    }

    ui->BugsInProduct3Label->setText(QString::number(BugsInProduct3));


    //count and show bugs in prouct 4
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedProduct()=="PRODUCT 4") BugsInProduct4++;
    }

    ui->BugsInProduct4Label->setText(QString::number(BugsInProduct4));


    //count and show bugs in prouct 5
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getAffectedProduct()=="PRODUCT 5") BugsInProduct5++;
    }

    ui->BugsInProduct5Label->setText(QString::number(BugsInProduct5));

}


