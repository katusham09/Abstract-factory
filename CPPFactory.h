#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "UnitFactory.h"
#include "methodunitCPP.h"
#include "printoperatorunitCPP.h"
#include "classunitCPP.h"

class CPPFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override {
        return std::make_shared<ClassUnitCPP>(name); // Создаем объект класса ClassUnitCPP
    }

    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<MethodUnitCPP>(name, returnType, flags); // Создаем объект класса MethodUnitCPP с передачей параметров
    }

    std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<PrintOperatorUnitCPP>(text); // Создаем объект класса PrintOperatorUnitCPP
    }
};


#endif
