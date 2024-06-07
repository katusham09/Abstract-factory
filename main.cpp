#include "UnitFactory.h"
#include "generateCode.h"
#include <QApplication>
#include "iostream"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    std::cout << "Enter language (cpp, csharp, java): ";
    std::string language;
    std::cin >> language;

    GenerateCode generator;
    std::cout << generator.generateProgram(language) << std::endl;


    return a.exec();
}
