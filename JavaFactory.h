#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "classunitJava.h"
#include "methodunitJava.h"
#include "printoperatorunitJava.h"
#include "UnitFactory.h"

class JavaFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override {
        return std::make_shared<ClassUnitJava>(name);
    }

    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<MethodUnitJava>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<PrintOperatorUnitJava>(text);
    }
};

#endif
