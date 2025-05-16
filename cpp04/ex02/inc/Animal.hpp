#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class A_Animal
{
    protected:
        std::string type;
    public:
        A_Animal();
        A_Animal(const std::string& ty) : type(ty) {}
        A_Animal(const A_Animal& copy);
        A_Animal& operator=(const A_Animal& copy);
        virtual void makeSound() const = 0;
        const std::string& getType() const; 
        virtual ~A_Animal();
};




#endif // !ANMAL_HPP