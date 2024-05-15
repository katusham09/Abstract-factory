#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "unit.h"

class UnitFactory
{
public:
    virtual std::shared_ptr<Unit> createClassUnit() = 0;
    virtual std::shared_ptr<Unit> createMethodUnit() = 0;
    virtual std::shared_ptr<Unit> createPrintOperatorUnit() = 0;
};

#endif // UNITFACTORY_H
