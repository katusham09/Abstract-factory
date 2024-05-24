#ifndef GENERATECODE_H
#define GENERATECODE_H

#include "UnitFactory.h"
#include "CPPFactory.h"
#include "CSharpFactory.h"
#include "JavaFactory.h"


class GenerateCode {
public:

    std::string generateProgram(std::shared_ptr<UnitFactory> factory) {
        auto myClass = factory->createClassUnit("MyClass");

        // Определяем специфичные методы для C++
        if (auto cppFactory = std::dynamic_pointer_cast<CPPFactory>(factory)) {
            myClass->add(cppFactory->createMethodUnit("testFunc1", "void", 0), Unit::PUBLIC);
            myClass->add(cppFactory->createMethodUnit("testFunc2", "void", Unit::STATIC), Unit::PRIVATE);
            myClass->add(cppFactory->createMethodUnit("testFunc3", "void", Unit::VIRTUAL | Unit::CONST), Unit::PUBLIC);

            auto method = cppFactory->createMethodUnit("testFunc4", "void", Unit::STATIC);
            method->add(cppFactory->createPrintOperatorUnit(R"(Hello, world!\n)"),0);
            myClass->add(method, Unit::PROTECTED);
        }

        // Определяем специфичные методы для C#
        if (auto csharpFactory = std::dynamic_pointer_cast<CSharpFactory>(factory)) {
            myClass->add(csharpFactory->createMethodUnit("testFunc1", "void", Unit::SEALED | Unit::OVERRIDE), Unit::PUBLIC);
            myClass->add(csharpFactory->createMethodUnit("testFunc2", "void", Unit::VIRTUAL), Unit::PROTECTED);
            myClass->add(csharpFactory->createMethodUnit("testFunc3", "void", 0), Unit::INTERNAL);

            auto method = csharpFactory->createMethodUnit("testFunc4", "void", Unit::STATIC);
            method->add(csharpFactory->createPrintOperatorUnit(R"(Hello, world!\n)"),0);
            myClass->add(method, Unit::PRIVATE);

            myClass->add(csharpFactory->createMethodUnit("testFunc5", "void", Unit::VIRTUAL), Unit::PROTECTED_INTERNAL);
            myClass->add(csharpFactory->createMethodUnit("testFunc6", "void", Unit::STATIC), Unit::PRIVATE_PROTECTED);
        }

        // Определяем специфичные методы для Java
        if (auto javaFactory = std::dynamic_pointer_cast<JavaFactory>(factory)) {
            myClass->add(javaFactory->createMethodUnit("testFunc1", "void", Unit::FINAL), Unit::PUBLIC);
            myClass->add(javaFactory->createMethodUnit("testFunc2", "void", 0), Unit::PROTECTED);
            myClass->add(javaFactory->createMethodUnit("testFunc3", "void", Unit::ABSTRACT), Unit::PUBLIC);

            auto method = javaFactory->createMethodUnit("testFunc4", "void", Unit::STATIC);
            method->add(javaFactory->createPrintOperatorUnit(R"(Hello, world!\n)"),0);
            myClass->add(method, Unit::PRIVATE);
        }

        return myClass->compile();
    }
};

#endif // GENERATECODE_H
