#ifndef BUG_H
#define BUG_H
#include <QString>

class Bug
{
public:
    Bug();
    ~Bug();

    void setEnvironment(QString env);
    void setBugNumber(QString bn);
    void setDescription(QString desc);
    void setAffectedSystem(QString as);
    void setAffectedProduct(QString ap);
    void setStatus(QString st);

    QString getEnvironment();
    QString getBugNumber();
    QString getDescription();
    QString getAffectedSystem();
    QString getAffectedProduct();
    QString getStatus();

private:
    QString Environment;
    QString BugNumber;
    QString Description;
    QString AffectedSystem;
    QString AffectedProduct;
    QString Status;
};

#endif // BUG_H
