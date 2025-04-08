#include "HumanA.hpp"

HumanA::HumanA(std::string nameh, Weapon& weaponh): name(nameh), weapon(weaponh){  }

void HumanA::attack() 
{
    std::cout << name << " attacks with their " << weapon.get_type() << std::endl;
}