#ifndef GENERATECODE_H
#define GENERATECODE_H

#include "UnitFactory.h"
#include "CPPFactory.h"
#include "CSharpFactory.h"
#include "JavaFactory.h"

class GenerateCode {
public:
    std::string generateProgram(const std::string& language) {
        std::shared_ptr<UnitFactory> factory;

        if (language == "cpp") {
            factory = std::make_shared<CPPFactory>();
        } else if (language == "csharp") {
            factory = std::make_shared<CSharpFactory>();
        } else if (language == "java") {
            factory = std::make_shared<JavaFactory>();
        } else {
            return "Unknown language";
        }

        auto myClass = factory->createClassUnit("MyClass");
        myClass->add(factory->createMethodUnit("testFunc1", "void", Unit::SEALED | Unit::OVERRIDE | Unit::FINAL), Unit::PUBLIC);
        myClass->add(factory->createMethodUnit("testFunc2", "void", Unit::STATIC), Unit::Unit::INTERNAL);
        myClass->add(factory->createMethodUnit("testFunc3", "void", Unit::VIRTUAL | Unit::CONST), Unit::PRIVATE);

        auto method = factory->createMethodUnit("testFunc4", "void", Unit::STATIC);
        method->add(factory->createPrintOperatorUnit(R"(Hello, world!\n)"),0);
        myClass->add(method, Unit::PROTECTED);
        myClass->add(factory->createMethodUnit("testFunc5", "void", Unit::VIRTUAL), Unit::PROTECTED_INTERNAL);
        myClass->add(factory->createMethodUnit("testFunc6", "void", Unit::STATIC), Unit::PRIVATE_PROTECTED);

        return myClass->compile();
    }
};

#endif // GENERATECODE_H
