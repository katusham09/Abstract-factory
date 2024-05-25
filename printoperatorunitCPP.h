#ifndef PRINTOPERATORUNITCPP_H
#define PRINTOPERATORUNITCPP_H
#include "unit.h"

class PrintOperatorUnitCPP : public Unit {
public:
    explicit PrintOperatorUnitCPP( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};

#endif // PRINTOPERATORUNITC++_H
