#include "unit.h"
#include "classunitCPP.h"
#include "printoperatorunitCPP.h"
#include "methodunitCPP.h"
#include <QApplication>
#include "iostream"
#include "string.h"

std::string generateProgram()
{
    ClassUnitCPP myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnitCPP >( "testFunc1", "void", 0 ), ClassUnitCPP::PUBLIC);
    myClass.add(
        std::make_shared< MethodUnitCPP >( "testFunc2", "void", MethodUnitCPP::STATIC ), ClassUnitCPP::PRIVATE);
    myClass.add(
        std::make_shared< MethodUnitCPP >( "testFunc3", "void", MethodUnitCPP::VIRTUAL | MethodUnitCPP::CONST ), ClassUnitCPP::PUBLIC);
    auto method = std::make_shared< MethodUnitCPP >( "testFunc4", "void", MethodUnitCPP::STATIC );
    method->add( std::make_shared< PrintOperatorUnitCPP >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnitCPP::PROTECTED );
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << generateProgram() << std::endl;
    return 0;
}


