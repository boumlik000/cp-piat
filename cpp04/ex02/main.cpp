#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define SIZE 2

int main()
{

    Cat* cats[SIZE];
    Dog* dogs[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        cats[i] = new Cat();
        cats[i]->makeSound();
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        dogs[i] = new Dog();
        dogs[i]->makeSound();
    }
    
    for (int i = 0; i < SIZE; i++) {
        delete cats[i];
        delete dogs[i];
    }

    return 0;
}