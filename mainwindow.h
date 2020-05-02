#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QMainWindow>
#include <QString>
#include "bug.h"
#include <deque>
#include "stats.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::vector<Bug> Bugs;

    qreal BugsOpenToShowStatistics;
    qreal BugsInProgressToShowStatistics;
    qreal BugsInEnv1ToShowStatistics;
    qreal BugsInEnv2ToShowStatistics;

public slots:
    void on_addButton_clicked();

private slots:
    void on_removeButton_clicked();
    void updateStatistics(std::vector<Bug> *list);
    void addBug(Bug bug);
    void removeBug(std::vector<Bug> *Bug, int Row);
    void on_ChangeStatusPushButton_clicked();
    void on_ShowStatsPushButton_clicked();
    void calculateStatistics();

private:
    Ui::MainWindow *ui;
    QtCharts::QChartView stats;
    double BugsPercentageOnEnv1;
    double BugsPercentageOnEnv2;
};
#endif // MAINWINDOW_H
