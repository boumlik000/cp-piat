#include "Convert.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "default constructor" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
    std::cout << "Deconstructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    (void) obj;
    std::cout << "copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void) obj;
    std::cout << "operator overloading" << std::endl;
    return *this;
}

bool is_char(std::string obj)
{
    if (obj.length() == 1)
    {
        if (!isdigit(obj[0]) && (isalpha(obj[0])))
            return true;
    }
    else
        return false;
    return false;
}

bool is_int(std::string obj)
{
    size_t i = 0;
    if (obj[0] == '+' ||obj[0] == '-' )
        i++;
    for (; i < obj.length(); i++)
    {
        if (!isdigit(obj[i]))
            return false;
    }
    return true;
}

bool is_float(std::string obj) 
{
    bool hasdecimal = false;
    bool hasdigit = false;
    size_t i = 0;
    
    
    if (obj[0] == '+' || obj[0] == '-')
        i++;
    
    if (std::count(obj.begin(), obj.end(), 'f') != 1 || obj[obj.length() - 1] != 'f')
        return false;
    
    if (obj.length() - i <= 1)
        return false;
    
    for (; i < obj.length() - 1; i++)
    {
        if (isdigit(obj[i]))
            hasdigit = true;
        else if (obj[i] == '.')
        {
            if (hasdecimal) 
                return false;
            hasdecimal = true;
        }
        else
            return false;
    }
    if (hasdigit && hasdecimal)
        return true;
    return false;
}

bool is_double(std::string obj)
{
    size_t i = 0;
    bool hasdecimal = false;

    if (obj[0] == '+' ||obj[0] == '-' )
        i++;
    for (; i < obj.length(); i++)
    {

        if ((isdigit(obj[i]) )|| (obj[i] == '.') )
        {
            if (obj[i] == '.')
            {
                if(hasdecimal)
                    return false;
                hasdecimal = true;
            }
        }
        else
            return false;
    }
    return true;
    
}


bool ScalarConverter::Convert(std::string obj)
{
   if (is_char(obj))
    {
        std::cout << "char : '" << obj << "'" << std::endl;
        std::cout << "int : " << "impossible" << std::endl;
        std::cout << "float : " << "impossible" << std::endl;
        std::cout << "double : " << "impossible" << std::endl;
        return true;
    }
    else if (is_int(obj))
    {
        int i = atoi(obj.c_str());
        if (i < 32 || i >= 127)
            std::cout << "char : Non Displayable" << std::endl;
        else
            std::cout << "char : " << "'"  << static_cast<char>(i) << "'" << std::endl;        
        std::cout << "int : " << i << std::endl;
        std::cout << "float : " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(i) << ".0" << std::endl;
        return true;
    }
    else if (is_float(obj))
    {
        float i = atof(obj.c_str());
        std::cout << "char : " << "'"  << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int : " << static_cast<int>(i) << std::endl;
        std::cout << "float : " << i << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(i)  << std::endl;
        
        return true;
    }
    else if (is_double(obj))
    {
        double i = atof(obj.c_str());
        std::cout << "char : " << "'"  << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int : " << static_cast<int>(i) << std::endl;
        std::cout << "float : " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double : " << i << std::endl;
        return true;
    }
    else if(obj == "nan" || obj == "nanf")
    {
        std::cout << "char : impposible" << std::endl;
        std::cout << "int : impposible" << std::endl;
        std::cout << "float : " << "nan" << "f" << std::endl;
        std::cout << "double : " << "nan" << std::endl;
        return true;
    }
    else if(obj == "-inff" || obj == "-inf")
    {
        std::cout << "char : impposible" << std::endl;
        std::cout << "int : impposible" << std::endl;
        std::cout << "float : " << "-inf" << "f" << std::endl;
        std::cout << "double : " << "-inf" << std::endl;
        return true;
    }
    else if(obj == "+inff" || obj == "+inf")
    {
        std::cout << "char : impposible" << std::endl;
        std::cout << "int : impposible" << std::endl;
        std::cout << "float : " << "+inf" << "f" << std::endl;
        std::cout << "double : " << "+inf" << std::endl;
        return true;
    }
    else
    {
        std::cerr<< "this string is impossible to convert bc its not int or float or double or charr" << std::endl;
        return false;    
    }
}