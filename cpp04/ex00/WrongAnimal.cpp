#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("wrong animal")
{
    std::cout<< "Default constructor WRONG ANIMAL" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& ty): type(ty)
{
    std::cout<< "Constructor WRONG ANIMAL" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout<< "Copy constructor WRONG ANIMAL" << std::endl;
    this->type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout<< "Operator assignement WRONG ANIMAL" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
    }
    return *this;    
}

const std::string& WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong ANIMAL sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<< "Deconstructor WRONG ANIMAL" << std::endl;
}