#include "newbugdata.h"
#include "ui_newbugdata.h"

NewBugData::NewBugData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewBugData)
{
    ui->setupUi(this);
}

NewBugData::~NewBugData()
{
    delete ui;
}



//setters//
void NewBugData::setEnvironment()
{
    Environment=ui->EnvLineEdit->text();
}

void NewBugData::setBugNumber()
{
    BugNumber=ui->BugNumberLineEdit->text();
}

void NewBugData::setDescription()
{
    Description=ui->DescriptionLineEdit->text();
}

void NewBugData::setSystemAffected()
{
    Description=ui->AffectedSystemLineEdit->text();
}

void NewBugData::setProductAffected()
{
    Description=ui->AffectedProdLineEdit->text();
}



//getters//

QString NewBugData::getEnvironment()
{
    return Environment;
}

QString NewBugData::getBugNumber()
{
    return BugNumber;
}

QString NewBugData::getDescription()
{
    return Description;
}

QString NewBugData::getSystemAffected()
{
    return SystemAffected;
}

QString NewBugData::getProductAffected()
{
    return Description;
}


//ui element handlers//

void NewBugData::on_CancelButton_clicked()
{
    this->close();
}

void NewBugData::on_OkButton_clicked()
{
    setEnvironment();
    setBugNumber();
    setDescription();
    setSystemAffected();
    setProductAffected();


    emit sendData(ui->EnvLineEdit->text(),
                  ui->BugNumberLineEdit->text(),
                  ui->DescriptionLineEdit->text(),
                  ui->AffectedSystemLineEdit->text(),
                  ui->AffectedProdLineEdit->text());

        ui->EnvLineEdit->clear();
        ui->BugNumberLineEdit->clear();
        ui->DescriptionLineEdit->clear();
        ui->AffectedSystemLineEdit->clear();
        ui->AffectedProdLineEdit->clear();

        //закрытие
        this->close();
}
