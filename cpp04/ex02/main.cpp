#include "./inc/Animal.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Cat.hpp"


#define ARRAY_SIZE 4

int main()
{

    Cat* cats[ARRAY_SIZE];
    Dog* dogs[ARRAY_SIZE];

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        cats[i] = new Cat();
        cats[i]->makeSound();
    }
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        dogs[i] = new Dog();
        dogs[i]->makeSound();
    }
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete cats[i];
        delete dogs[i];
    }
    // delete[] cats;
    // delete[] dogs;


    return 0;
}