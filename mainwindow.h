#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    double BugsPercentageOnEnv1;
    double BugsPercentageOnEnv2;

    int BugsOpenToShowStatistics;
    int BugsInProgressToShowStatistics;
    int BugsInEnv1ToShowStatistics;
    int BugsInEnv2ToShowStatistics;

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
    QWidget stats;

};
#endif // MAINWINDOW_H
