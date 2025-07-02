#include "Dog.hpp"

Dog::Dog() :brain(new Brain)
{
    std::cout << "default constractor ANIMAL: DOG" << std::endl;
}

Dog::Dog(const Dog& copy): A_Animal(copy),brain(new Brain(*(copy.brain)))
{
    std::cout << "copy constractor DOG" << std::endl;
}
Dog& Dog::operator=(const Dog& copy)
{
    if (this != &copy)
    {
        delete this->brain;
        this->brain = new Brain(*(copy.brain));
    }
    return *this;
}

void Dog::setType(std::string type)
{
    this->type = type;
}
void Dog::makeSound() const
{
    std::cout << "hawhaw 3333333333333hawhaw :)"<< std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Deconstractor ANIMAL: DOG" << std::endl;
}