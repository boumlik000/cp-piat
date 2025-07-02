#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constuctor Brain" << std::endl;
}


Brain::Brain(const Brain& copy)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain& Brain::operator=(const  Brain& obj)
{
    if (this != &obj)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = obj.ideas[i];
        }  
    }
    return *this ;
    
}

Brain::~Brain()
{
    std::cout << "Deconstuctor Brain" << std::endl;
    
}