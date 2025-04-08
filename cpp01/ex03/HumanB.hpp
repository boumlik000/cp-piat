#ifndef HUMANB_HPP
#define HUMANB_HPP

// #include <iostream>
#include "Weapon.hpp"
class HumanB
{

    std::string name;
    Weapon *weapon;
    public:
        HumanB(std::string nameh): name(nameh),weapon(NULL){}
        void attack() ;
        void setWeapon(Weapon &w);
};


#endif // DEBUG