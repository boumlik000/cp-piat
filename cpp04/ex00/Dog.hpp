#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
    protected:
        std::string type;
    public:
        Dog(/* args */);
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        void setType(std::string type);
        void makeSound() const;

        ~Dog();
};




#endif // !ANMAL_HPP