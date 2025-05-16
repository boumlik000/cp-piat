#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    protected:
        std::string type;
    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& copy);
        void setType(std::string type);
        void makeSound() const;
        
        ~Cat();
};
    



#endif // !ANMAL_HPP