#include "UnitFactory.h"
#include "generateCode.h"
#include <QApplication>
#include "iostream"


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::shared_ptr<UnitFactory> factoryPtr = std::make_shared<CPPFactory>();
//    std::shared_ptr<UnitFactory> factoryPtr = std::make_shared<CSharpFactory>();

//    std::shared_ptr<UnitFactory> factoryPtr = std::make_shared<JavaFactory>();

    GenerateCode generator;
    std::cout << generator.generateProgram(factoryPtr) << std::endl;

    return 0;
}


