#ifndef SERIALIAZER
#define SERIALIAZER

#include <iostream>
// #include <cstdint>
#include <stdint.h>

struct Data
{
    int a;
    std::string s;
};


class Serializer
{
private:
    /* data */
public:
    Serializer(/* args */);
    Serializer(const Serializer& obj);
    Serializer& operator=(const Serializer& obj);
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};







#endif // !Serializer