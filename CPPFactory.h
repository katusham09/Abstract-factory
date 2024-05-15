#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "UnitFactory.h"
#include "methodunitCPP.h"
#include "printoperatorunitCPP.h"
#include "classunitCPP.h"

class CPPFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createClassUnit() override {
        return std::make_shared<ClassUnitCPP>; // Создаем объект класса ClassUnitCPP
    }

    std::shared_ptr<Unit> createMethodUnit() override {
        return std::make_shared<MethodUnitCPP>; // Создаем объект класса MethodUnitCPP с передачей параметров
    }

    std::shared_ptr<Unit> createPrintOperatorUnit() override {
        return std::make_shared<PrintOperatorUnitCPP>; // Создаем объект класса PrintOperatorUnitCPP
    }
};


#endif
