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
    GenerateCode generator;
    std::string code = generator.generateProgram();
    std::cout << code << std::endl; // Выводим сгенерированный код
    return 0;
}


