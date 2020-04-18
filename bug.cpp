#include "bug.h"

//constructor
Bug::Bug()
{
    setStatus("Open");
}

//destructor
Bug::~Bug()
{
    delete this;
}

//setters
void Bug::setEnvironment(QString env)
{
    Environment=env;
}

void Bug::setBugNumber(QString bn)
{
    BugNumber=bn;
}

void Bug::setDescription(QString desc)
{
    Description=desc;
}

void Bug::setAffectedSystem(QString as)
{
    AffectedSystem=as;
}

void Bug::setAffectedProduct(QString ap)
{
    AffectedProduct=ap;
}

void Bug::setStatus(QString st)
{
    Status=st;
}


//getters
QString Bug::getEnvironment()
{
    return Environment;
}

QString Bug::getBugNumber()
{
    return BugNumber;
}

QString Bug::getDescription()
{
    return Description;
}

QString Bug::getAffectedSystem()
{
    return AffectedSystem;
}

QString Bug::getAffectedProduct()
{
    return AffectedProduct;
}

QString Bug::getStatus()
{
    return Status;
}
