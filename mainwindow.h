#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "bug.h"
#include <deque>

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

public slots:
    void on_addButton_clicked();

private slots:
    void on_removeButton_clicked();
    void updateStatistics(std::vector<Bug> *list);
    void addBug(Bug bug);
    void removeBug(std::vector<Bug> *Bug, int Row);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
