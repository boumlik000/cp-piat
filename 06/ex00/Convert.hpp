#ifndef CONVERT_HPP
#define CONVERT_HPP


#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NOTYPE
};

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter();
        static bool Convert(std::string obj);

};




#endif // !CONVERT_HPP