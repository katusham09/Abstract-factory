#include "unit.h"
#include "classunitCPP.h"
#include "UnitFactory.h"
#include "CPPFactory.h"
#include "generateCode.h"
#include "printoperatorunitCPP.h"
#include "methodunitCPP.h"
#include <QApplication>
#include "iostream"
#include "string.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
//    GenerateCode generator;
//    std::string code = generator.generateProgramCPP();
//    std::cout << code << std::endl; // Выводим сгенерированный код

//    std::string code = generator.generateProgramCSharp();
//    std::cout << code << std::endl; // Выводим сгенерированный код

//    std::string code = generator.generateProgramJava();
//    std::cout << code << std::endl; // Выводим сгенерированный код

//    CPPFactory factory;
//    std::string code = generator.generateProgram(factory);
    CPPFactory factory; // Создаем экземпляр фабрики
    std::shared_ptr<UnitFactory> factoryPtr = std::make_shared<CPPFactory>(factory); // Оборачиваем фабрику в shared_ptr

    GenerateCode generator; // Создаем экземпляр генератора
    std::string code = generator.generateProgram(factoryPtr);
    std::cout << code << std::endl;

    return 0;
}


