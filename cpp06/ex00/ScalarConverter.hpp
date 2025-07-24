#ifndef SCARL_HPP
#define SCARL_HPP

#include <iostream>
#include <sstream>
#include <limits.h>
#include <iomanip> 

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
        ~ScalarConverter();
        static void convert(std::string& literal);
};






#endif