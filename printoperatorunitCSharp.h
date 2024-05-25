#ifndef PRINTOPERATORUNITCSHARP_H
#define PRINTOPERATORUNITCSHARP_H
#include"unit.h"

class PrintOperatorUnitCSharp : public Unit {
public:
    explicit PrintOperatorUnitCSharp( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};
#endif // PRINTOPERATORUNITCSHARP_H
