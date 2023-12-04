#include "Figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    return f.outp(os);
}

std::istream& operator>>(std::istream& is, Figure& f) {
    return f.inp(is);
}


Figure::operator double() const{
    return (static_cast <double> (this->getSquare()));
}

bool Figure::operator==(const Figure& f)
{
    if (f.getN() == this->getN() && f.getSquare() == this->getSquare()) {
        return true;
    }
    return false;
}

double Figure::inputNumber(std::istream& input) {
    double res;
    std::string inStr, resStr;
    const std::regex patternDigit("[^\\+\\-0-9\\.]");
    const std::regex patternDouble("(\\+|\\-)?\\d+\\.?\\d*");

    fseek(stdin, 0, SEEK_END);  // выделяем весь поток
    fflush(stdin);              // очистка потока

    while (true) {
        try {
            // Получаем данные
            getline(input, inStr);

            // Применяем регулярное выражение и 
            // убираем все кроме перечисленно в регулярке
            resStr = regex_replace(inStr, patternDigit, "");

            // если длина очищенной строки меньше первоначальной
            // то кидаем ислючение, так как пользователь пытался ввести 
            // чтото лишнее и некорректное
            if (inStr.size() != resStr.size()) {
                throw "Введены некорректные символы.";
            }

            // Похожа ли введеная строка на число с точкой
            if (!regex_match(resStr, patternDouble)) {
                throw "Это точно не число";
            }

            // преобразуем строку в число
            res = stod(resStr);
            return res;
        }
        catch (const char* ex) {
            std::cout << "ОШИБКА ВВОДА >> " << ex << std::endl;
        }
    }
}
