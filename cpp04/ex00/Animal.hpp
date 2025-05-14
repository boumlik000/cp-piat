#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(/* args */);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        void makeSound() const;
        const std::string& getType() const; 
        ~Animal();
};




#endif // !ANMAL_HPP