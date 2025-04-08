#include "HumanB.hpp"

void HumanB::attack() {
    if(weapon)
        std::cout << name << " attacks with their " << weapon->get_type() << std::endl;
    
}

void HumanB::setWeapon(Weapon &w) {
    weapon = &w;
}