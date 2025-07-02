#ifndef WCAT_HPP
#define WCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongCat();
        WrongCat(const WrongCat& copy);
        WrongCat& operator=(const WrongCat& copy);
        void setType(std::string type);
        void makeSound() const;
        
        ~WrongCat();
};
    



#endif 