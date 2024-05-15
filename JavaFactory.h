#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "classunitJava.h"
#include "methodunitJava.h"
#include "printoperatorunitJava.h"
#include "UnitFactory.h"

class JavaFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createClassUnit() override {
        return std::make_shared<ClassUnitJava>;
    }

    std::shared_ptr<Unit> createMethodUnit() override {
        return std::make_shared<MethodUnitJava>;
    }

    std::shared_ptr<Unit> createPrintOperatorUnit() override {
        return std::make_shared<PrintOperatorUnitJava>;
    }
};
#endif
