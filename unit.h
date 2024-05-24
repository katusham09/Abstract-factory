#ifndef UNIT_H
#define UNIT_H

#include <QMainWindow>

class Unit
{
public:
    using Flags = unsigned int;

    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        SEALED = 1 << 3,
        OVERRIDE = 1 << 4,
        FINAL = 1 << 5,
        ABSTRACT = 1 << 6
    };
public:
    virtual ~Unit() = default;

    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }
//  Виртуальная функция-член предназначена для добавления вложенных элементов (передача происходит через умный указатель)
//  умный указатель std::shared_ptr).Также эта функция принимает параметр Flags. По умолчанию add() выбрасывает исключение.

    virtual std::string compile( unsigned int level = 0 ) const = 0;
//    Функция генерирует код, соответствующий содержимому элемента. Результат возвращается в виде строки std::string.
//    В качестве аргумента функция принимает параметр level, указывающий на уровень вложенности узла дерева. Это требуется для корректной
//    расстановки отступов в начале строк генерируемого кода.
protected:
    virtual std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
//    Вспомогательная функция-член всего лишь возвращает строку, состоящую из нужного числа пробелов. Результат зависит от уровня вложенности.
};
#endif
