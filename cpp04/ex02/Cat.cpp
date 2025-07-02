#include "Cat.hpp"

Cat::Cat():brain(new Brain)
{
    std::cout << "default constractor ANIMAL: CAT" << std::endl;
}
Cat::Cat(const Cat& copy):A_Animal(copy),brain(new Brain(*(copy.brain)))
{
    std::cout << "copy constractor Cat" << std::endl;
}
Cat& Cat::operator=(const Cat& copy)
{
    if (this != &copy)
    {
        delete this->brain;
        this->brain= new Brain(*(copy.brain));
    }
    return *this;
}
void Cat::setType(std::string type)
{
    this->type = type;
}
void Cat::makeSound() const
{
    std::cout << "miawwww :)"<< std::endl;
}
Cat::~Cat()
{
    delete brain;
    std::cout << "Deconstractor ANIMAL: CAT" << std::endl;
}