#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal *x = new WrongAnimal();
    const WrongAnimal *y = new WrongCat();

    std::cout << "----------------\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "----------------\n";
    std::cout << x->getType() << " " << std::endl;
    std::cout << y->getType() << " " << std::endl;
    
    std::cout << "----------------\n";
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();
    
    std::cout << "----------------\n";
    x->makeSound(); 
    y->makeSound();

    delete meta;
    delete i;
    delete j;
    delete x;
    delete y;

    return 0;
}