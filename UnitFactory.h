#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "unit.h"

class UnitFactory
{
public:
    virtual std::shared_ptr<Unit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) = 0;
};

#endif // UNITFACTORY_H
