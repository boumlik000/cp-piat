#include "../inc/Animal.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Dog k;
    std::cout << sizeof(*j) << std::endl;
    std::cout << sizeof(k) << std::endl;
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
    return 0;
}