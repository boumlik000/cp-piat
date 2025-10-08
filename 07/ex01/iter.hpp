#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void print_ee(T& element)
{
    std::cout << element << "eee" << std::endl;
}

void doubleElement(int& x) 
{
    x *= 2;
    std::cout << x << std::endl;
}



template <typename T>
void Iter(T arr[],int lenght, void(*fc)(T&))
{
    for (int i = 0; i < lenght; i++)
    {
        fc(arr[i]);
    }
    
}



#endif