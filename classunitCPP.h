#ifndef CLASSUNITCPP_H
#define CLASSUNITCPP_H
#include "unit.h"
#include <iostream>
#include <vector>

class ClassUnitCPP : public Unit
{
public:
    static const std::vector< std::string > ACCESS_MODIFIERS;//вектор, определяющий доступные модификаторы доступа
public:
    explicit ClassUnitCPP( const std::string& name ) : m_name( name ) { // Конструктор класса
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    // Метод для добавления элемента в класс с указанием модификатора доступа
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = PRIVATE;// По умолчанию устанавливаем модификатор доступа как private
        if( flags < ACCESS_MODIFIERS.size() ) {// Проверяем, что флаг не выходит за пределы доступных модификаторов
            accessModifier = flags;// Устанавливаем модификатор доступа по флагу
        }
        // Добавляем элемент в соответствующий список полей класса по модификатору доступа
        m_fields[ accessModifier ].push_back( unit );
    }

    // Метод компиляции класса в строку с учетом уровня вложенности
    std::string compile( unsigned int level=0) const
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";// Заголовок класса
        // Обходим список полей по каждому модификатору доступа
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            // Добавляем заголовок модификатора доступа перед соответствующими полями
            result += ACCESS_MODIFIERS[ i ] + ":\n";
            // Добавляем каждое поле из списка
            for( const auto& f : m_fields[ i ] ) {
                result += f->compile( level + 1 );// записываем поле в строку с учетом уровня вложенности
            }
            result += "\n";// Переход на новую строку для следующего модификатора доступа
        }
        result += generateShift( level ) + "};\n";// Закрываем класс
        return result;// Возвращаем результат
    }
private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};
const std::vector< std::string > ClassUnitCPP::ACCESS_MODIFIERS = { "public", "protected", "private" };

#endif // CLASSUNITC++_H
