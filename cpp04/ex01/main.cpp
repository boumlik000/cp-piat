#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


#define SIZE 4

int main()
{
    Animal* animals[SIZE];
    
    for (int i = 0; i < SIZE / 2; i++) {
        animals[i] = new Dog();
        animals[i]->makeSound();
    }
    for (int i = SIZE / 2; i < SIZE; i++) {
        animals[i] = new Cat();
        animals[i]->makeSound();
    }

    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }


    return 0;
}