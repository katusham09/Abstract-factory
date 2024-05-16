#ifndef PRINTOPERATORUNITJAVA_H
#define PRINTOPERATORUNITJAVA_H
#include"unit.h"

class PrintOperatorUnitJava : public Unit {
public:
    explicit PrintOperatorUnitJava ( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};
#endif // PRINTOPERATORUNITJAVA_H
