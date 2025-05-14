#ifndef CLAPTRAPP_HPP
#define CLAPTRAPP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        size_t hit;
        size_t energy;
        size_t attack;
    public:
        ClapTrap();
        ClapTrap(const std::string& _name);
        ClapTrap(const ClapTrap& obj);
        ClapTrap& operator=(const ClapTrap& obj);


        ClapTrap& print(ClapTrap& target);
        void Attack(const std::string& target);
        void TakeDamage(unsigned int amount);
        void BeRepaired(unsigned int amount);
        
        
        ~ClapTrap();
};

#endif