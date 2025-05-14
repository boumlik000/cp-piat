#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
    name(""),hit(10),energy(10),attack(0)
{
    std::cout << name << "Constructor called " << std::endl ;

}

ClapTrap::ClapTrap(const std::string& _name):
    name(_name),hit(10),energy(10),attack(0)
{
    std::cout << name << " Parametred Constructor called " << std::endl ;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << name << "copy Constructor called " << std::endl ;
    this->name = obj.name;
    this->energy = obj.energy;
    this->hit = obj.hit;
    this->attack = obj.attack;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        this->energy = obj.energy;
        this->hit = obj.hit;
        this->attack = obj.attack;
    }
    return *this;
}

void ClapTrap::Attack(const std::string& target)
{  
    if (energy <= 0 || hit <= 0)
        std::cout << this->name << " can't attack,or repair itself. energy points are not enough" << std::endl ;
    else
    {
        energy -= 1;
        std::cout << "clap trap " << this->name  << "attack " << target
            << " causing " << attack << " damage" << std::endl;
        std::cout << "energy remains " << this->energy << " to " << this->name << std::endl;
        std::cout << "hit remains " << this->hit << " to " << this->name << std::endl;
    }
}
void ClapTrap::TakeDamage(unsigned int amount)
{
    if(this->hit == 0)
        std::cout << this->name << "already dead :(" << std::endl ;
    else if (this->hit <= amount) 
    {
        this->hit = 0;
        std::cout << "Bekkkkkkkkkkkkhhhhhhhhhhh" 
            << this->name << "is deaaaaaaaaaad :(" << std::endl;
    }
    else
    {
        this->hit = this->hit - amount ;
        std::cout << this->name << "is damaged" << std::endl ;
        std::cout << "hit "<< this->hit << " remain" << std::endl ;
    }
}
void ClapTrap::BeRepaired(unsigned int amount)
{
    if (energy <= 0 || hit <= 0)
        std::cout << this->name << " can't attack,or repair itself. energy points are not enough" << std::endl ;
    else
    {
        this->hit = this->hit + amount;
        this->energy--;
        std::cout << "repaired" << std::endl;
        std::cout << this->name << " hit : " << this->hit << std::endl;
        std::cout << this->name << " energy left : " << this->energy << std::endl;
    }
}
ClapTrap::~ClapTrap()
{
    std::cout << "Deconstructor called " << std::endl ;
}