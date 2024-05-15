#ifndef GENERATECODE_H
#define GENERATECODE_H

#include "UnitFactory.h"
#include "classunitCPP.h"
#include "methodunitCPP.h"
#include "CPPFactory.h"
#include "printoperatorunitCPP.h"

class GenerateCode {
public:
    std::string generateProgram() {
        auto factory = std::make_shared<CPPFactory>(); // Используем CPPFactory для создания элементов
        auto myClass = factory->createClassUnit("MyClass");

        // Добавляем методы в MyClass
        myClass->add(factory->createMethodUnit("testFunc1", "void", 0), ClassUnitCPP::PUBLIC);
        myClass->add(factory->createMethodUnit("testFunc2", "void", MethodUnitCPP::STATIC), ClassUnitCPP::PRIVATE);
        myClass->add(factory->createMethodUnit("testFunc3", "void", MethodUnitCPP::VIRTUAL | MethodUnitCPP::CONST), ClassUnitCPP::PUBLIC);

        // Создаем и добавляем testFunc4 с оператором printf
        auto method = std::make_shared<MethodUnitCPP>("testFunc4", "void", MethodUnitCPP::STATIC);
        method->add(factory->createPrintOperatorUnit(R"(Hello, world!\n)"));
        myClass->add(method, ClassUnitCPP::PROTECTED);

        return myClass->compile();
    }
};


//код который должен выводиться на C#
//public class MyClass
//{
//public virtual void TestFunc1() { }

//protected static void TestFunc2() { }

//private void TestFunc3()
//    {
//        Console.WriteLine("Hello, world!\n");
//    }

//    internal void TestFunc4() { }

//protected internal void TestFunc5() { }

//private protected void TestFunc6() { }

//public abstract void AbstractMethod();

//public sealed void OverrideMethod() { }
//}


#endif // GENERATECODE_H
