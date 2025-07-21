#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
    std::cout << "ScalarConverter Default constructor" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    (void)obj;
    std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    std::cout << "ScalarConverter operator constructor" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter Deconstructor" << std::endl;
}

int to_int(std::string input)
{
    std::istringstream iss(input);
    int res ;
    iss >> res;
    return res;
}

char to_char(std::string input)
{
    std::istringstream iss(input);
    char res ;
    iss >> res;
    return res;
}

float to_float(std::string input)
{
    std::istringstream iss(input);
    float res ;
    iss >> res;
    return res;
}

double to_double(std::string input)
{
    std::istringstream iss(input);
    double res ;
    iss >> res;
    return res;
}

void charr(std::string& input)
{
    std::cout << "charr " << std::endl;
}



void ScalarConverter::convert(std::string& literal )
{

    std::cout << "ur input : " << literal << std::endl;
    std::cout << "char : " << charr(literal) << std::endl;
    std::cout << "int : " << innt(literal) << std::endl;
    std::cout << "float : " << flooat(literal) << std::endl;
    std::cout << "double : " << doouble(literal) << std::endl;

}