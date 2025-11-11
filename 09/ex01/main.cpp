#include "RPN.hpp"
#include <sstream>
// #include <vector>

enum Type{
    NAN,
    NUMBER,
    OPERATOR_PLUS,
    OPERATOR_MINES,
    OPERATOR_MULTIPLICATION,
    OPERATOR_DEVISION
};

Type check_arg(std::string token)
{
    if (token.length() != 1)
    {
        std::cerr << "Error: invalid token length" << std::endl;
        return NAN;
    }
    
    char c = token[0];
    
    if (c == '+')
        return OPERATOR_PLUS;
    else if (c == '-')
        return OPERATOR_MINES;
    else if (c == '*')
        return OPERATOR_MULTIPLICATION;
    else if (c == '/')
        return OPERATOR_DEVISION;
    else if (isdigit(c))
        return NUMBER;
    else
    {
        std::cerr << token << " bad input" << std::endl;
        return NAN;
    }
}

Type parsing(std::string input, std::stack<float>& stak)
{
    std::istringstream iss(input);
    std::string token;
    Type t = NAN;
    
    while (iss >> token)
    {
        t = check_arg(token);
        
        if (t == NAN)
        {
            std::cerr << "Error in token: " << token << std::endl;
            return t;
        }
        else if (t == NUMBER)
        {
            int n = atoi(token.c_str());
            stak.push(n);
        }
        else if (t == OPERATOR_PLUS || t == OPERATOR_MINES || 
                 t == OPERATOR_MULTIPLICATION || t == OPERATOR_DEVISION)
        {
            if (stak.size() < 2)
            {
                std::cerr << "Error: not enough operands" << std::endl;
                return NAN;
            }
            
            float a = stak.top(); stak.pop();
            float b = stak.top(); stak.pop();
            float result = 0;
            
            if (t == OPERATOR_PLUS)
                result = b + a;
            else if (t == OPERATOR_MINES)
                result = b - a;
            else if (t == OPERATOR_MULTIPLICATION)
                result = b * a;
            else if (t == OPERATOR_DEVISION)
            {
                if (a == 0)
                    return NAN;
                result = b / a;
            }
            
            stak.push(result);
        }
    }
    
    return t;
}

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " \"expression\"" << std::endl;
        return 1;
    }
    
    std::stack<float> stak;
    Type t = parsing(av[1], stak);
    
    if (t == NAN)
    {
        std::cerr << "Error in parsing" << std::endl;
        return 1;
    }
    else if (t == NUMBER)
    {
        std::cerr << "Error: last argument must be an operator" << std::endl;
        return 1;
    }
    
    if (stak.size() != 1)
    {
        std::cerr << "Error: invalid expression" << std::endl;
        return 1;
    }
    
    std::cout << "Result: " << stak.top() << std::endl;
    
    return 0;
}