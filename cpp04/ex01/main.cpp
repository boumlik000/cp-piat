#include "./inc/Animal.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Cat.hpp"


#define ARRAY_SIZE 4

int main()
{
    Animal* animals[ARRAY_SIZE];
    
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        animals[i] = new Dog();
        animals[i]->makeSound();
    }
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        animals[i] = new Cat();
        animals[i]->makeSound();
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete animals[i];
    }


    return 0;
}