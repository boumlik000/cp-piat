#include "./inc/Animal.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Cat.hpp"


#define ARRAY_SIZE 4

int main()
{

    Cat* cats[ARRAY_SIZE];
    Dog* dogs[ARRAY_SIZE];

    // A_Animal anim;
    // A_Animal* animals = new A_Animal();
    A_Animal animals() ;

    // A_Animal* animals[ARRAY_SIZE];
    
    // for (int i = 0; i < ARRAY_SIZE / 2; i++) {
    //     animals[i] = new Dog();
    //     animals[i]->makeSound();
    // }
    // for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
    //     animals[i] = new Cat();
    //     animals[i]->makeSound();
    // }

    // for (int i = 0; i < ARRAY_SIZE; i++) {
    //     delete animals[i];
    // }

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        cats[i] = new Cat();
        cats[i]->makeSound();
    }
    std::cout << ARRAY_SIZE << std::endl ; 
    for (size_t i = 0; i <= ARRAY_SIZE; i++)
    {
        dogs[i] = new Dog();
        dogs[i]->makeSound();
    }
    


    return 0;
}