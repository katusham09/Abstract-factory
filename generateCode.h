#ifndef GENERATECODE_H
#define GENERATECODE_H

#include "UnitFactory.h"
#include "classunitCPP.h"
#include "methodunitCPP.h"
#include "printoperatorunitCPP.h"
#include "CPPFactory.h"
#include "classunitCSharp.h"
#include "methodunitCSharp.h"
#include "printoperatorunitCSharp.h"
#include "CSharpFactory.h"
#include "classunitJava.h"
#include "methodunitJava.h"
#include "printoperatorunitJava.h"
#include "JavaFactory.h"


class GenerateCode {
public:
    std::string generateProgramCPP() {
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

    std::string generateProgramCSharp() {
        auto factory = std::make_shared<CSharpFactory>(); // Используем CPPFactory для создания элементов
        auto myClass = factory->createClassUnit("MyClass");

        // Добавляем методы в MyClass
        myClass->add(factory->createMethodUnit("testFunc1", "void", MethodUnitCSharp::SEALED | MethodUnitCSharp::OVERRIDE), ClassUnitCSharp::PUBLIC);
        myClass->add(factory->createMethodUnit("testFunc2", "void", MethodUnitCSharp::VIRTUAL), ClassUnitCSharp::PROTECTED);
        myClass->add(factory->createMethodUnit("testFunc3", "void", 0), ClassUnitCSharp::INTERNAL);

        // Создаем и добавляем testFunc4 с оператором printf
        auto method = std::make_shared<MethodUnitCSharp>("testFunc4", "void", MethodUnitCSharp::STATIC);
        method->add(factory->createPrintOperatorUnit(R"(Hello, world!\n)"));
        myClass->add(method, ClassUnitCSharp::PRIVATE);

        myClass->add(factory->createMethodUnit("testFunc5", "void", MethodUnitCSharp::VIRTUAL), ClassUnitCSharp::PROTECTED_INTERNAL);
        myClass->add(factory->createMethodUnit("testFunc6", "void", MethodUnitCSharp::STATIC), ClassUnitCSharp::PRIVATE_PROTECTED);

        return myClass->compile();
    }

    std::string generateProgramJava() {
        auto factory = std::make_shared<JavaFactory>(); // Используем CPPFactory для создания элементов
        auto myClass = factory->createClassUnit("MyClass");

        // Добавляем методы в MyClass
        myClass->add(factory->createMethodUnit("testFunc1", "void", MethodUnitJava::FINAL ), ClassUnitJava::PUBLIC);
        myClass->add(factory->createMethodUnit("testFunc2", "void", 0), ClassUnitJava::PROTECTED);
        myClass->add(factory->createMethodUnit("testFunc3", "void", MethodUnitJava::ABSTARCT), ClassUnitJava::PUBLIC);

        // Создаем и добавляем testFunc4 с оператором printf
        auto method = std::make_shared<MethodUnitJava>("testFunc4", "void", MethodUnitJava::STATIC);
        method->add(factory->createPrintOperatorUnit(R"(Hello, world!\n)"));
        myClass->add(method, ClassUnitJava::PRIVATE);

        return myClass->compile();
    }
};

//код который должен выводиться на Java
//public class MyClass
//{
//public final void TestFunc1() { }

//protected void TestFunc2() { }

//private static void TestFunc3()
//    {
//        System.out.println("Hello, world!\n");
//    }

//public abstract void TestFunc4() { }

//}


//код который должен выводиться на C#
//public class MyClass
//{
//public sealed override void TestFunc1() { }

//protected virtual void TestFunc2() { }

//private static void TestFunc3()
//    {
//        Console.WriteLine("Hello, world!\n");
//    }

//internal void TestFunc4() { }

//protected internal virtual void TestFunc5() { }

//private protected static void TestFunc6() { }

//}


#endif // GENERATECODE_H
