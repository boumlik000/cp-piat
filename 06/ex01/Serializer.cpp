#include "Serializer.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer(/* args */)
{
    std::cout << "Default constructor" << std::endl;
}

Serializer::Serializer(const Serializer& obj)
{
    (void)obj;
    std::cout << "copy constructor" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
    
    (void)obj;
    std::cout << "operator overloading" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Deconstructor" << std::endl;
}