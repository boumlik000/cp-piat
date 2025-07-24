#include "Serializer.hpp"

Serializer::Serializer(/* args */)
{
    std::cout << "default constructor Serializer" << std::endl;
}

Serializer::Serializer(const Serializer& obj)
{
    (void)obj;
    std::cout << "copy constructor Serializer" << std::endl;
    
}

Serializer& Serializer::operator=(const Serializer& obj)
{
    (void)obj;
    std::cout << "operator Serializer" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Deconstructor Serializer" << std::endl;
}


uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}