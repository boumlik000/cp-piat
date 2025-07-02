#ifndef WANIMAL_HPP
#define WANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        const std::string& getType() const;
        void makeSound() const;
        ~WrongAnimal();
};
    



#endif // !WANIMAL_HPP