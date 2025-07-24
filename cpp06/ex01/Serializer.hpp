#ifndef SERIAL_HPP
#define SERIAL_HPP


#include <iostream>
#include "data.hpp"
#include <string>
#include <cstring>
#include <stdint.h> 


class Serializer
{   
    private:
        Serializer(/* args */);
    public:
        Serializer(const Serializer& obj);
        Serializer& operator=(const Serializer& obj);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};





#endif // !SERIAL_HPP