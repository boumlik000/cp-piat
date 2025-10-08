#ifndef EASY_HPP
#define EASY_HPP


#include<iostream>
#include<exception>
#include <algorithm> // ضروري لـ std::find
#include <vector> 

template<typename T>
void easyfind(T& C_type ,int i)
{
    typename T::iterator res = std::find(C_type.begin(),C_type.end(),i);
    if (res == C_type.end())
    {
        throw std::runtime_error("MAl9itoch");
    }
    else
        std::cout << "l9itooo blimara lvalue llibghiti hia : " << *res  << std::endl;
    
}


#endif // !EASY_HPP