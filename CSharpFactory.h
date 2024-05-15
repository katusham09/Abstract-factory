#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "classunitCSharp.h"
#include "methodunitCSharp.h"
#include "printoperatorunitCSharp.h"
#include "UnitFactory.h"

class CSharpFactory : public UnitFactory {
public:
    std::shared_ptr<Unit> createClassUnit() override {
        return std::make_shared<ClassUnitCSharp>;
    }

    std::shared_ptr<Unit> createMethodUnit() override {
        return std::make_shared<MethodUnitCSharp>;
    }

    std::shared_ptr<Unit> createPrintOperatorUnit() override {
        return std::make_shared<PrintOperatorUnitCSharp>;
    }
};
#endif
