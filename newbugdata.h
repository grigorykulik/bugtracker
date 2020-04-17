#ifndef NEWBUGDATA_H
#define NEWBUGDATA_H

#include <QWidget>

namespace Ui {
class NewBugData;
}

class NewBugData : public QWidget
{
    Q_OBJECT

public:
    explicit NewBugData(QWidget *parent = nullptr);
    ~NewBugData();

    void setEnvironment();
    void setBugNumber();
    void setDescription();
    void setSystemAffected();
    void setProductAffected();

    QString getEnvironment();
    QString getBugNumber();
    QString getDescription();
    QString getSystemAffected();
    QString getProductAffected();

signals:
    void sendData(QString line1, QString line2, QString line3, QString line4, QString line5);

private slots:
    void on_CancelButton_clicked();
    void on_OkButton_clicked();

private:
    Ui::NewBugData *ui;
    QString Environment, BugNumber, Description, SystemAffected, ProductAffected;
};

#endif // NEWBUGDATA_H
