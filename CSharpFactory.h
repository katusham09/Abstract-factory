#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "classunitCSharp.h"
#include "methodunitCSharp.h"
#include "printoperatorunitCSharp.h"
#include "UnitFactory.h"

class CSharpFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createClassUnit(const std::string& name) override {
        return std::make_shared<ClassUnitCSharp>(name);
    }

    std::shared_ptr<Unit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<MethodUnitCSharp>(name, returnType, flags);
    }

    std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<PrintOperatorUnitCSharp>(text);
    }
};
#endif
