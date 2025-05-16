#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(/* args */);
        Animal(const std::string& ty) : type(ty) {}
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        virtual void makeSound() const;
        const std::string& getType() const; 
        virtual ~Animal();
};




#endif // !ANMAL_HPP