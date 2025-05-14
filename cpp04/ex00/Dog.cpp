#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "default constractor ANIMAL: DOG" << std::endl;
}

Dog::Dog(const Dog& copy)
{
    std::cout << "copy constractor DOG" << std::endl;
    this->type = copy.type;
}
Dog& Dog::operator=(const Dog& copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
    }
    return *this;
}

void Dog::setType(std::string type)
{
    this->type = type;
}
void Dog::makeSound() const
{
    std::cout << "hawhaw 3333333333333hawhaw :)";
}



Dog::~Dog()
{
    std::cout << "Deconstractor ANIMAL: DOG" << std::endl;
}