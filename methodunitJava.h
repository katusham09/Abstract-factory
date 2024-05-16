#ifndef METHODUNITJAVA_H
#define METHODUNITJAVA_H

#include "unit.h"

class MethodUnitJava : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        FINAL = 1 << 1,
        ABSTARCT = 1 << 2
    };
public:
    MethodUnitJava( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body.push_back( unit );
    }

    std::string compile( unsigned int level = 0) const {
        std::string result = generateShift( level );
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & FINAL ) {
            result += "final ";
        } else if( m_flags & ABSTARCT ) {
            result += "abstact ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // METHODUNITJAVA_H
