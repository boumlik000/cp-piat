#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "default constractor ANIMAL" << std::endl;
}
Animal::Animal(const Animal& copy)
{
    std::cout << "copy constractor ANIMAL" << std::endl;
    this->type = copy.type;
}

Animal& Animal::operator=(const Animal& copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
    }
    return *this;
}

const std::string& Animal::getType() const
{
    return this->type;
}
Animal::~Animal()
{
    std::cout << "Deconstractor ANIMAL" << std::endl;
}