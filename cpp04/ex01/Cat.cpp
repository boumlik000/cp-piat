#include "Cat.hpp"

Cat::Cat():Animal() ,brain(new Brain)
{
    this->type = "Cat";
    std::cout << "default constractor ANIMAL: CAT" << std::endl;
}
Cat::Cat(const Cat& copy): Animal() ,brain(new Brain(*(copy.brain)))
{
    std::cout << "copy constractor Cat" << std::endl;
    this->type = copy.type;
}
Cat& Cat::operator=(const Cat& copy)
{
    if (this != &copy)
    {
        this->type = copy.type;
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