#ifndef ARR_HPP
#define ARR_HPP

#include <iostream>



template<typename T>
class Array
{
    T *arr;
    unsigned int size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& obj);
        Array& operator=(const Array& obj);
        int size();
        ~Array();
};

template<typename T>
Array<T>::Array() : arr(NULL) , size(0)
{
    std::cout << "Default constructor" << std::endl; 
}

template<typename T>
Array<T>::Array(unsigned int n) : size(n)
{
    if (n == 0 )
    {
        arr = NULL;
    }
    else
        arr = new T[n];
    
    std::cout << "parametred constructor" << std::endl; 
}
template<typename T>
Array<T>::Array(const Array& obj)
{
    std::cout << "copy constructor" << std::endl; 
    this->size = obj.size;
    if (size == 0)
    {
        arr = NULL;
    }
    else
    {
        this->arr= new T[this->size];
        for (unsigned int i = 0; i < this->size; i++)
        {
            this->arr[i] = obj.arr[i];
        }

    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{

    if (this != &obj)
    {

        delete[] this->arr;
        this->size = obj.size;
        if (size == 0)
        {
            arr = NULL;
        }
        else
        {
            this->arr= new T[this->size];
            for (unsigned int i = 0; i < this->size; i++)
            {
                this->arr[i] = obj.arr[i];
            }
        }
    }
    return *this;
}


template<typename T>
Array<T>::~Array()
{
    std::cout << " Deconstructor" << std::endl; 
    delete[] this->_array;
}


#endif // !ARR_HPP