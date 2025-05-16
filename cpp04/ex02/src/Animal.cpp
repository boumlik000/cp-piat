#include "../inc/Animal.hpp"

A_Animal::A_Animal():type("walo")
{
    std::cout << "default constractor A_ANIMAL" << std::endl;
}
A_Animal::A_Animal(const A_Animal& copy)
{
    std::cout << "copy constractor A_ANIMAL" << std::endl;
    this->type = copy.type;
}

A_Animal& A_Animal::operator=(const A_Animal& copy)
{
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

const std::string& A_Animal::getType() const
{
    return this->type;
}
void A_Animal::makeSound() const
{
    std::cout << "A_ANIMAL sound" << std::endl;
}
A_Animal::~A_Animal()
{
    std::cout << "Deconstractor ANIMAL" << std::endl;
}