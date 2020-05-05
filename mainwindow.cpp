#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "bug.h"
#include "QMessageBox"
#include "QList"

#include "stats.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>

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

        if (Bugs.empty())
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
    int BugsInProgress=0;
    int BugsOpen=0;

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

    //count and show bugs in progress
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getStatus()=="InProgress") BugsInProgress++;
    }

    ui->BugsInProgressLabel->setText(QString::number(BugsInProgress));

    //count and show closed bugs
    for (size_t i=0; i<Bugs->size(); i++)
    {
        if (Bugs->at(i).getStatus()=="Open") BugsOpen++;
    }

    ui->OpenBugsLabel->setText(QString::number(BugsOpen));

    BugsOpenToShowStatistics=BugsOpen;
    BugsInProgressToShowStatistics=BugsInProgress;
    BugsInEnv1ToShowStatistics=BugsInEnv1;
    BugsInEnv2ToShowStatistics=BugsInEnv2;

    BugsInSystem1ToShowStatistics=BugsInSystem1;
    BugsInSystem2ToShowStatistics=BugsInSystem2;
    BugsInSystem3ToShowStatistics=BugsInSystem3;
    BugsInSystem4ToShowStatistics=BugsInSystem4;
    BugsInSystem5ToShowStatistics=BugsInSystem5;

    BugsInProduct1ToShowStatistics=BugsInProduct1;
    BugsInProduct2ToShowStatistics=BugsInProduct2;
    BugsInProduct3ToShowStatistics=BugsInProduct3;
    BugsInProduct4ToShowStatistics=BugsInProduct4;
    BugsInProduct5ToShowStatistics=BugsInProduct5;
}



void MainWindow::on_ChangeStatusPushButton_clicked()
{
    int CurrentRow=ui->tableWidget->currentRow();

    if (Bugs.empty())
    {
        QMessageBox msgBox;
        msgBox.setText("Cannot change status of an empty row");
        msgBox.exec();
    }

    else
    {
        if (ui->ChangeStatusComboBox->currentText()=="InProgress")
        {
            for (int i=0; i<6; i++)
            {
                ui->tableWidget->item(CurrentRow, i)->setBackground(QBrush(QColor(255,255,153)));
            }
        }

        else
        {
            for (int i=0; i<6; i++)
            {
                ui->tableWidget->item(CurrentRow, i)->setBackground(QBrush(QColor(51,255,51)));
            }
        }

        QString NewStatus=ui->ChangeStatusComboBox->currentText();
        Bugs.at(CurrentRow).setStatus(NewStatus);
        ui->tableWidget->item(CurrentRow, 5)->setText(Bugs.at(CurrentRow).getStatus());

        updateStatistics(&Bugs);
    }
}


void MainWindow::on_ShowStatsPushButton_clicked()
{
    updateStatistics(&Bugs);
    calculateStatistics();

    //create and show stats on envs
    QtCharts::QChartView *StatsOnEnvs=new QtCharts::QChartView();

    QtCharts::QPieSeries *series=new QtCharts::QPieSeries();
    series->append("Env1", BugsPercentageOnEnv1);
    series->append("Env2", BugsPercentageOnEnv2);

    QtCharts::QPieSlice *slice0=series->slices().at(0);
    slice0->setLabelVisible();

    QtCharts::QPieSlice *slice1=series->slices().at(1);
    slice1->setLabelVisible();

    QtCharts::QChart *chart=new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Bugs on environments");
    chart->legend()->hide();

    StatsOnEnvs->setChart(chart);
    StatsOnEnvs->setRenderHint(QPainter::Antialiasing);

    StatsOnEnvs->show();

    //create and show stats on systems
    QtCharts::QBarSet *set0=new QtCharts::QBarSet("System 1");
    QtCharts::QBarSet *set1=new QtCharts::QBarSet("System 2");
    QtCharts::QBarSet *set2=new QtCharts::QBarSet("System 3");
    QtCharts::QBarSet *set3=new QtCharts::QBarSet("System 4");
    QtCharts::QBarSet *set4=new QtCharts::QBarSet("System 5");

    *set0<<BugsInSystem1ToShowStatistics;
    *set1<<BugsInSystem2ToShowStatistics;
    *set2<<BugsInSystem3ToShowStatistics;
    *set3<<BugsInSystem4ToShowStatistics;
    *set4<<BugsInSystem5ToShowStatistics;

    QtCharts::QBarSeries *BugsInSystemsBarSeries=new QtCharts::QBarSeries;
    BugsInSystemsBarSeries->append(set0);
    BugsInSystemsBarSeries->append(set1);
    BugsInSystemsBarSeries->append(set2);
    BugsInSystemsBarSeries->append(set3);
    BugsInSystemsBarSeries->append(set4);

    QtCharts::QChart *BugsInSystemsChart=new QtCharts::QChart;
    BugsInSystemsChart->addSeries(BugsInSystemsBarSeries);
    BugsInSystemsChart->setTitle("Bugs in systems");
    BugsInSystemsChart->setAnimationOptions(QtCharts::QChart::AllAnimations);
    QStringList categories;
    categories<<"2020";
    QtCharts::QBarCategoryAxis *axis=new QtCharts::QBarCategoryAxis();
    axis->append(categories);
    BugsInSystemsChart->createDefaultAxes();
    BugsInSystemsChart->setAxisX(axis, series);
    BugsInSystemsChart->legend()->setVisible(true);
    BugsInSystemsChart->legend()->setAlignment(Qt::AlignBottom);
    QtCharts::QChartView *BugsInSystemsChartView=new QtCharts::QChartView(BugsInSystemsChart);
    BugsInSystemsChartView->show();

    //create and show stats on products

    QtCharts::QBarSet *set00=new QtCharts::QBarSet("Product 1");
    QtCharts::QBarSet *set10=new QtCharts::QBarSet("Product 2");
    QtCharts::QBarSet *set20=new QtCharts::QBarSet("Product 3");
    QtCharts::QBarSet *set30=new QtCharts::QBarSet("Product 4");
    QtCharts::QBarSet *set40=new QtCharts::QBarSet("Product 5");

    *set00<<BugsInProduct1ToShowStatistics;
    *set10<<BugsInProduct2ToShowStatistics;
    *set20<<BugsInProduct3ToShowStatistics;
    *set30<<BugsInProduct4ToShowStatistics;
    *set40<<BugsInProduct5ToShowStatistics;

    QtCharts::QBarSeries *BugsInProductsBarSeries=new QtCharts::QBarSeries;
    BugsInProductsBarSeries->append(set00);
    BugsInProductsBarSeries->append(set10);
    BugsInProductsBarSeries->append(set20);
    BugsInProductsBarSeries->append(set30);
    BugsInProductsBarSeries->append(set40);

    QtCharts::QChart *BugsInProductsChart=new QtCharts::QChart;
    BugsInProductsChart->addSeries(BugsInProductsBarSeries);
    BugsInProductsChart->setTitle("Bugs in products");
    BugsInProductsChart->setAnimationOptions(QtCharts::QChart::AllAnimations);
    QStringList categories2;
    categories2<<"2020";
    QtCharts::QBarCategoryAxis *axis2=new QtCharts::QBarCategoryAxis();
    axis->append(categories2);
    BugsInProductsChart->createDefaultAxes();
    BugsInProductsChart->setAxisX(axis2, series);
    BugsInProductsChart->legend()->setVisible(true);
    BugsInProductsChart->legend()->setAlignment(Qt::AlignBottom);
    QtCharts::QChartView *BugsInProductsChartView=new QtCharts::QChartView(BugsInProductsChart);
    BugsInProductsChartView->show();

}

void MainWindow::calculateStatistics()
    {
        BugsPercentageOnEnv1=BugsInEnv1ToShowStatistics/(BugsOpenToShowStatistics+
                                                             BugsInProgressToShowStatistics);
        BugsPercentageOnEnv2=BugsInEnv2ToShowStatistics/(BugsOpenToShowStatistics+
                                            BugsInProgressToShowStatistics);
    }
