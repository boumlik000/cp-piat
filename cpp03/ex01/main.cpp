#include "ScavTrap.hpp"

int main()
{
    
    ClapTrap p1("hassan");
    ScavTrap p2("boumlik");
    p2.Attack("boumlik");
    p2.BeRepaired(2);
    p2.TakeDamage(15);
    p2.guardGate();
    p2.BeRepaired(2);
    return 0;
}
