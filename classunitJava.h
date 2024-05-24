#ifndef CLASSUNITJAVA_H
#define CLASSUNITJAVA_H
#include "unit.h"

class ClassUnitJava : public Unit
{
public:
    static const std::vector< std::string > ACCESS_MODIFIERS;//вектор, определяющий доступные модификаторы доступа
public:
    explicit ClassUnitJava( const std::string& name ) : m_name( name ) {// Конструктор класса
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
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n";// Заголовок класса
        // Метод компиляции класса в строку с учетом уровня вложенности
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }
            for(const auto& f : m_fields[i]) {
                result += ACCESS_MODIFIERS[i];// Добавляем модификатор доступа
                result += f->compile(level + 1);// записываем поле в строку с учетом уровня вложенности
            }
            result += "\n";// Переход на новую строку для следующего модификатора доступа
        }
        result += generateShift(level) + "};\n";// Закрываем класс
        return result;// Возвращаем сгенерированный код класса
    }
private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};
const std::vector< std::string > ClassUnitJava::ACCESS_MODIFIERS = { "public", "protected", "private" };

#endif // CLASSUNITJAVA_H
