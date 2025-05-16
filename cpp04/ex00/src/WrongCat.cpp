#include "../inc/WrongCat.hpp"

WrongCat::WrongCat():type("wrong cat")
{
    std::cout << "default constractor ANIMAL: WrongCat" << std::endl;
}
WrongCat::WrongCat(const WrongCat& copy)
{
    std::cout << "copy constractor WrongCat" << std::endl;
    this->type = copy.type;
}
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
    }
    return *this;
}
void WrongCat::setType(std::string type)
{
    this->type = type;
}
void WrongCat::makeSound() const
{
    std::cout << "miawwww :) wrong cat"<< std::endl;
}


WrongCat::~WrongCat()
{
    std::cout << "Deconstractor ANIMAL: WrongCat" << std::endl;
}