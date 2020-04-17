#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "newbugdata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void recieveData(QString str1,QString str2,QString str3, QString str4, QString str5);
    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    NewBugData *BugData;
    QString Environment, BugNumber, Description, SystemAffected, ProductAffected;

};
#endif // MAINWINDOW_H
